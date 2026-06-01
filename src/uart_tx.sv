`timescale 1ns/1ps

module uart_tx #(
    parameter CLK_FREQ = 27_000_000,
    parameter BAUD_RATE = 115200
)(
    input  logic clk, rst_n, start,
    input  logic [7:0] data_in,
    output logic tx, ready
);
    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;
    
    typedef enum logic [1:0] {IDLE, START, DATA, STOP} state_t;
    state_t state;
    logic [$clog2(CLKS_PER_BIT)-1:0] clk_cnt;
    logic [2:0] bit_cnt;
    logic [7:0] tx_data;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE; tx <= 1; ready <= 1; clk_cnt <= 0;
        end else begin
            case (state)
                IDLE: begin
                    tx <= 1; ready <= 1;
                    if (start) begin
                        ready <= 0; tx_data <= data_in; state <= START; clk_cnt <= 0;
                    end
                end
                START: begin
                    tx <= 0;
                    if (clk_cnt == CLKS_PER_BIT-1) begin
                        clk_cnt <= 0; state <= DATA; bit_cnt <= 0;
                    end else clk_cnt <= clk_cnt + 1;
                end
                DATA: begin
                    tx <= tx_data[bit_cnt];
                    if (clk_cnt == CLKS_PER_BIT-1) begin
                        clk_cnt <= 0;
                        if (bit_cnt == 7) state <= STOP;
                        else bit_cnt <= bit_cnt + 1;
                    end else clk_cnt <= clk_cnt + 1;
                end
                STOP: begin
                    tx <= 1;
                    if (clk_cnt == CLKS_PER_BIT-1) state <= IDLE;
                    else clk_cnt <= clk_cnt + 1;
                end
            endcase
        end
    end
endmodule