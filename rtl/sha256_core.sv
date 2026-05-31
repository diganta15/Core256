`timescale 1ns/1ps

// SHA-256 core — corrected
//
// Key fix: the sliding-window shift approach is replaced with modular
// in-place indexing.  The array w[0:15] is indexed by (round_ctr % 16)
// every round.  After each round the consumed slot is overwritten in-place
// with the next scheduled word W[t+16].  No shifting ever occurs.
//
// Why the shift approach fails:
//   The expansion formula W[t] = SIG1(W[t-2]) + W[t-7] + SIG0(W[t-15]) + W[t-16]
//   uses four relative offsets (-2, -7, -15, -16).  In a shift register those
//   offsets map to fixed positions w[14], w[9], w[1], w[0].  But after each
//   shift those positions refer to different absolute words, so the formula
//   reads stale or already-overwritten values from round 16 onwards.
//
// The in-place modular approach:
//   At round t (0..63):
//     idx       = t % 16
//     w_val     = w[idx]                               -- consumed by compression
//     w_next    = SIG1(w[(idx+14)%16])                 -- same as W[t-2]
//               + w[(idx+9)%16]                        -- same as W[t-7]
//               + SIG0(w[(idx+1)%16])                  -- same as W[t-15]
//               + w[idx]                               -- same as W[t-16]
//     w[idx]   <= w_next                               -- slot free for W[t+16]
//   All four source slots are guaranteed untouched because we only ever
//   overwrite w[idx] = w[t%16], and the offsets +14, +9, +1 are all
//   different from 0 mod 16 for any t.
//
// Other fixes retained from the previous revision:
//   * init guarded to IDLE state only
//   * hash_valid held stable until next operation (not a 1-cycle pulse)
//   * hash_out registered so it presents post-accumulation values

module sha256_core (
    input  logic         clk,
    input  logic         rst_n,

    input  logic         init,        // Initialise H[] to IV (only honoured in IDLE)
    input  logic         next_block,  // Load block_in and begin hashing
    input  logic [511:0] block_in,    // 512-bit message block (big-endian words)

    output logic         ready,       // Core is idle and ready for a block
    output logic         hash_valid,  // hash_out contains a completed digest
    output logic [255:0] hash_out     // Registered digest; stable while hash_valid
);

// ---------------------------------------------------------------------------
// State machine
// ---------------------------------------------------------------------------

typedef enum logic [1:0] { IDLE, CALC, DONE } state_t;
state_t state, next_state;

logic [5:0] round_ctr;
logic       round_ctr_en, round_ctr_rst;

// ---------------------------------------------------------------------------
// SHA-256 round constants
// ---------------------------------------------------------------------------

logic [31:0] k_val;
always_comb begin
    case (round_ctr)
        6'd00: k_val=32'h428a2f98; 6'd01: k_val=32'h71374491;
        6'd02: k_val=32'hb5c0fbcf; 6'd03: k_val=32'he9b5dba5;
        6'd04: k_val=32'h3956c25b; 6'd05: k_val=32'h59f111f1;
        6'd06: k_val=32'h923f82a4; 6'd07: k_val=32'hab1c5ed5;
        6'd08: k_val=32'hd807aa98; 6'd09: k_val=32'h12835b01;
        6'd10: k_val=32'h243185be; 6'd11: k_val=32'h550c7dc3;
        6'd12: k_val=32'h72be5d74; 6'd13: k_val=32'h80deb1fe;
        6'd14: k_val=32'h9bdc06a7; 6'd15: k_val=32'hc19bf174;
        6'd16: k_val=32'he49b69c1; 6'd17: k_val=32'hefbe4786;
        6'd18: k_val=32'h0fc19dc6; 6'd19: k_val=32'h240ca1cc;
        6'd20: k_val=32'h2de92c6f; 6'd21: k_val=32'h4a7484aa;
        6'd22: k_val=32'h5cb0a9dc; 6'd23: k_val=32'h76f988da;
        6'd24: k_val=32'h983e5152; 6'd25: k_val=32'ha831c66d;
        6'd26: k_val=32'hb00327c8; 6'd27: k_val=32'hbf597fc7;
        6'd28: k_val=32'hc6e00bf3; 6'd29: k_val=32'hd5a79147;
        6'd30: k_val=32'h06ca6351; 6'd31: k_val=32'h14292967;
        6'd32: k_val=32'h27b70a85; 6'd33: k_val=32'h2e1b2138;
        6'd34: k_val=32'h4d2c6dfc; 6'd35: k_val=32'h53380d13;
        6'd36: k_val=32'h650a7354; 6'd37: k_val=32'h766a0abb;
        6'd38: k_val=32'h81c2c92e; 6'd39: k_val=32'h92722c85;
        6'd40: k_val=32'ha2bfe8a1; 6'd41: k_val=32'ha81a664b;
        6'd42: k_val=32'hc24b8b70; 6'd43: k_val=32'hc76c51a3;
        6'd44: k_val=32'hd192e819; 6'd45: k_val=32'hd6990624;
        6'd46: k_val=32'hf40e3585; 6'd47: k_val=32'h106aa070;
        6'd48: k_val=32'h19a4c116; 6'd49: k_val=32'h1e376c08;
        6'd50: k_val=32'h2748774c; 6'd51: k_val=32'h34b0bcb5;
        6'd52: k_val=32'h391c0cb3; 6'd53: k_val=32'h4ed8aa4a;
        6'd54: k_val=32'h5b9cca4f; 6'd55: k_val=32'h682e6ff3;
        6'd56: k_val=32'h748f82ee; 6'd57: k_val=32'h78a5636f;
        6'd58: k_val=32'h84c87814; 6'd59: k_val=32'h8cc70208;
        6'd60: k_val=32'h90befffa; 6'd61: k_val=32'ha4506ceb;
        6'd62: k_val=32'hbef9a3f7; 6'd63: k_val=32'hc67178f2;
        default: k_val=32'h0;
    endcase
end

// ---------------------------------------------------------------------------
// Hash state registers H[0..7] and SHA-256 IV
// ---------------------------------------------------------------------------

localparam [31:0] H0_INIT=32'h6a09e667, H1_INIT=32'hbb67ae85,
                  H2_INIT=32'h3c6ef372, H3_INIT=32'ha54ff53a,
                  H4_INIT=32'h510e527f, H5_INIT=32'h9b05688c,
                  H6_INIT=32'h1f83d9ab, H7_INIT=32'h5be0cd19;

logic [31:0] H [0:7];

// ---------------------------------------------------------------------------
// Working variables
// ---------------------------------------------------------------------------

logic [31:0] a, b, c, d, e, f, g, h;
logic [31:0] a_next, b_next, c_next, d_next, e_next, f_next, g_next, h_next;

// ---------------------------------------------------------------------------
// Message schedule: 16-word in-place modular buffer
// ---------------------------------------------------------------------------

logic [31:0] w [0:15];

// ---------------------------------------------------------------------------
// SHA-256 helper functions
// ---------------------------------------------------------------------------

function automatic logic [31:0] ROTR (input logic [31:0] x, input integer n);
    return (x >> n) | (x << (32 - n));
endfunction
function automatic logic [31:0] CH  (input logic [31:0] x, y, z);
    return (x & y) ^ (~x & z);
endfunction
function automatic logic [31:0] MAJ (input logic [31:0] x, y, z);
    return (x & y) ^ (x & z) ^ (y & z);
endfunction
function automatic logic [31:0] EP0 (input logic [31:0] x);
    return ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22);
endfunction
function automatic logic [31:0] EP1 (input logic [31:0] x);
    return ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25);
endfunction
function automatic logic [31:0] SIG0 (input logic [31:0] x);
    return ROTR(x,7) ^ ROTR(x,18) ^ (x >> 3);
endfunction
function automatic logic [31:0] SIG1 (input logic [31:0] x);
    return ROTR(x,17) ^ ROTR(x,19) ^ (x >> 10);
endfunction

// ---------------------------------------------------------------------------
// Combinational data path
// ---------------------------------------------------------------------------

logic [3:0] idx;       // = round_ctr % 16
logic [31:0] w_val;    // message word for this round  = w[t % 16]
logic [31:0] w_next;   // new schedule word to store in w[t % 16]
logic [31:0] temp1, temp2;

assign idx    = round_ctr[3:0];   // round_ctr is 0..63, low 4 bits == mod 16

// w_val and all four w_next source words are read from the CURRENT w[]
// contents, before the clock edge that writes w_next back.
assign w_val  = w[idx];

// W[t+16] = SIG1(W[t-2])  + W[t-7]         + SIG0(W[t-15])        + W[t-16]
//         = SIG1(w[t+14])  + w[t+9]          + SIG0(w[t+1])          + w[t]
//              (mod-16 offsets from idx)
assign w_next = SIG1(w[(idx+14) & 4'hF])
              + w[(idx+9)  & 4'hF]
              + SIG0(w[(idx+1)  & 4'hF])
              + w[idx];

// Compression round
assign temp1  = h + EP1(e) + CH(e,f,g) + k_val + w_val;
assign temp2  = EP0(a) + MAJ(a,b,c);

assign h_next = g;
assign g_next = f;
assign f_next = e;
assign e_next = d + temp1;
assign d_next = c;
assign c_next = b;
assign b_next = a;
assign a_next = temp1 + temp2;

// ---------------------------------------------------------------------------
// Sequential logic
// ---------------------------------------------------------------------------

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        state      <= IDLE;
        round_ctr  <= 6'd0;
        hash_valid <= 1'b0;
        hash_out   <= 256'h0;
        for (int i=0;i<8;i++)  H[i] <= 32'h0;
        for (int i=0;i<16;i++) w[i] <= 32'h0;
        a<=0; b<=0; c<=0; d<=0; e<=0; f<=0; g<=0; h<=0;
    end
    else begin
        // -- State register --------------------------------------------------
        state <= next_state;

        // -- Round counter ---------------------------------------------------
        if      (round_ctr_rst) round_ctr <= 6'd0;
        else if (round_ctr_en)  round_ctr <= round_ctr + 6'd1;

        // -- init: load IV into H (only safe in IDLE) ------------------------
        if (init && state == IDLE) begin
            H[0]<=H0_INIT; H[1]<=H1_INIT; H[2]<=H2_INIT; H[3]<=H3_INIT;
            H[4]<=H4_INIT; H[5]<=H5_INIT; H[6]<=H6_INIT; H[7]<=H7_INIT;
        end

        // -- Block load (IDLE -> CALC) ----------------------------------------
        if (state == IDLE && next_block) begin
            a<=H[0]; b<=H[1]; c<=H[2]; d<=H[3];
            e<=H[4]; f<=H[5]; g<=H[6]; h<=H[7];
            for (int i=0;i<16;i++)
                w[i] <= block_in[511-(i*32) -: 32];
        end

        // -- Compression rounds ----------------------------------------------
        else if (state == CALC) begin
            a<=a_next; b<=b_next; c<=c_next; d<=d_next;
            e<=e_next; f<=f_next; g<=g_next; h<=h_next;
            // Overwrite consumed slot in-place: no shifting required
            w[idx] <= w_next;
        end

        // -- Accumulate into hash state at end of block ----------------------
        else if (state == DONE) begin
            H[0]<=H[0]+a; H[1]<=H[1]+b; H[2]<=H[2]+c; H[3]<=H[3]+d;
            H[4]<=H[4]+e; H[5]<=H[5]+f; H[6]<=H[6]+g; H[7]<=H[7]+h;
        end

        // -- hash_valid and registered hash_out ------------------------------
        // Capture the final digest on the cycle AFTER DONE finishes so that
        // hash_out holds the post-accumulation values when hash_valid rises.
        if (state == DONE && next_state == IDLE) begin
            hash_out   <= { H[0]+a, H[1]+b, H[2]+c, H[3]+d,
                            H[4]+e, H[5]+f, H[6]+g, H[7]+h };
            hash_valid <= 1'b1;
        end
        else if (state == DONE && next_state == CALC) begin
            // Back-to-back block: chaining continues, digest not yet final
            hash_valid <= 1'b0;
        end
        else if (state == IDLE && (init || next_block)) begin
            hash_valid <= 1'b0;
        end
    end
end

// ---------------------------------------------------------------------------
// FSM combinational logic
// ---------------------------------------------------------------------------

always_comb begin
    next_state    = state;
    ready         = 1'b0;
    round_ctr_en  = 1'b0;
    round_ctr_rst = 1'b0;

    case (state)
        IDLE: begin
            ready = 1'b1;
            if (next_block) begin
                next_state    = CALC;
                round_ctr_rst = 1'b1;
            end
        end
        CALC: begin
            round_ctr_en = 1'b1;
            if (round_ctr == 6'd63)
                next_state = DONE;
        end
        DONE: begin
            if (next_block) begin
                next_state    = CALC;
                round_ctr_rst = 1'b1;
            end
            else next_state = IDLE;
        end
        default: next_state = IDLE;
    endcase
end

endmodule