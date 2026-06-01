`timescale 1ns/1ps

module uart_rx #(
    parameter CLK_FREQ = 27_000_000,
    parameter BAUD_RATE = 115200
)(
    input  logic clk, rst_n, rx,
    output logic [7:0] data_out,
    output logic data_valid
);
    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;
    
    typedef enum logic [1:0] {IDLE, START, DATA, STOP} state_t;
    state_t state;
    logic [$clog2(CLKS_PER_BIT)-1:0] clk_cnt;
    logic [2:0] bit_cnt;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE; data_valid <= 0; clk_cnt <= 0; bit_cnt <= 0;
        end else begin
            data_valid <= 0;
            case (state)
                IDLE: begin
                    clk_cnt <= 0;
                    if (rx == 0) state <= START;
                end
                START: begin
                    if (clk_cnt == CLKS_PER_BIT/2) begin
                        if (rx == 0) begin clk_cnt <= 0; state <= DATA; end 
                        else state <= IDLE;
                    end else clk_cnt <= clk_cnt + 1;
                end
                DATA: begin
                    if (clk_cnt == CLKS_PER_BIT-1) begin
                        clk_cnt <= 0; data_out[bit_cnt] <= rx;
                        if (bit_cnt == 7) begin bit_cnt <= 0; state <= STOP; end 
                        else bit_cnt <= bit_cnt + 1;
                    end else clk_cnt <= clk_cnt + 1;
                end
                STOP: begin
                    if (clk_cnt == CLKS_PER_BIT/2) begin
                        data_valid <= 1; state <= IDLE;
                    end else clk_cnt <= clk_cnt + 1;
                end
            endcase
        end
    end
endmodule