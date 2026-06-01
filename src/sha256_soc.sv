`timescale 1ns/1ps

module sha256_soc #(
    parameter CLK_FREQ  = 27_000_000, 
    parameter BAUD_RATE = 115200
)(
    input  logic clk,
    input  logic rst_n,       
    input  logic init_btn,    
    input  logic uart_rx_pin,
    output logic uart_tx_pin
);

    logic [7:0]  rx_data, tx_data;
    logic        rx_valid, tx_start, tx_ready;
    logic        sha_init, sha_next, sha_ready, sha_valid;
    logic [511:0] sha_block_in;
    logic [255:0] sha_hash_out;

    uart_rx #(.CLK_FREQ(CLK_FREQ), .BAUD_RATE(BAUD_RATE)) u_rx (
        .clk(clk), .rst_n(rst_n), .rx(uart_rx_pin),
        .data_out(rx_data), .data_valid(rx_valid)
    );

    uart_tx #(.CLK_FREQ(CLK_FREQ), .BAUD_RATE(BAUD_RATE)) u_tx (
        .clk(clk), .rst_n(rst_n), .data_in(tx_data), .start(tx_start),
        .tx(uart_tx_pin), .ready(tx_ready)
    );

    sha256_core u_sha256 (
        .clk(clk), .rst_n(rst_n),
        .init(sha_init), .next_block(sha_next), .block_in(sha_block_in),
        .ready(sha_ready), .hash_valid(sha_valid), .hash_out(sha_hash_out)
    );

    logic [1:0] init_sync;
    always_ff @(posedge clk) init_sync <= {init_sync[0], ~init_btn};
    assign sha_init = (init_sync == 2'b01);

    typedef enum logic [2:0] {
        S_IDLE,
        S_RX_BLOCK,
        S_CALC,
        S_TX_HASH,
        S_TX_WAIT
    } state_t;

    state_t state;
    logic [6:0] byte_cnt;
    logic [511:0] rx_shift_reg;
    logic [255:0] tx_shift_reg;

    assign sha_block_in = rx_shift_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= S_IDLE; byte_cnt <= 0; sha_next <= 0; tx_start <= 0;
            rx_shift_reg <= '0; tx_shift_reg <= '0;
        end else begin
            sha_next <= 0; tx_start <= 0;

            case (state)
                S_IDLE: begin
                    byte_cnt <= 0;
                    if (rx_valid) begin
                        rx_shift_reg <= {rx_shift_reg[503:0], rx_data};
                        byte_cnt <= 1;
                        state <= S_RX_BLOCK;
                    end
                end
                S_RX_BLOCK: begin
                    if (rx_valid) begin
                        rx_shift_reg <= {rx_shift_reg[503:0], rx_data};
                        byte_cnt <= byte_cnt + 1;
                        if (byte_cnt == 63) state <= S_CALC;
                    end
                end
                S_CALC: begin
                    if (sha_ready) begin
                        sha_next <= 1'b1;
                        state <= S_TX_HASH;
                    end
                end
                S_TX_HASH: begin
                    if (sha_valid) begin
                        tx_shift_reg <= sha_hash_out;
                        byte_cnt <= 0;
                    end 
                    else if (byte_cnt < 32 && tx_ready && !tx_start) begin
                        tx_data <= tx_shift_reg[255:248];
                        tx_shift_reg <= {tx_shift_reg[247:0], 8'h00};
                        tx_start <= 1'b1;
                        byte_cnt <= byte_cnt + 1;
                        state <= S_TX_WAIT; 
                    end 
                    else if (byte_cnt == 32 && tx_ready) begin
                        state <= S_IDLE;
                    end
                end
                S_TX_WAIT: begin
                    if (!tx_ready) state <= S_TX_HASH;
                end
            endcase
        end
    end
endmodule
