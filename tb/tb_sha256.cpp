#include <iostream>
#include <iomanip>
#include <cstdint>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsha256_core.h" // The Verilator-generated header

// Helper function to advance the clock and dump VCD waveforms
void tick(int &time_cnt, Vsha256_core* dut, VerilatedVcdC* tfp) {
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(time_cnt * 10);
    time_cnt++;

    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(time_cnt * 10);
    time_cnt++;
}

int main(int argc, char** argv) {
    // Initialize Verilator arguments
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // Instantiate the DUT (Design Under Test)
    Vsha256_core* dut = new Vsha256_core;

    // Setup VCD tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("sha256_trace.vcd");

    int time_cnt = 0;

    // ---------------------------------------------------------
    // 1. Reset and Initialization
    // ---------------------------------------------------------
    std::cout << "[TB] Asserting Reset..." << std::endl;
    dut->clk = 0;
    dut->rst_n = 0;
    dut->init = 0;
    dut->next_block = 0;
    
    // Apply reset for a few cycles
    for(int i=0; i<5; i++) tick(time_cnt, dut, tfp);
    
    dut->rst_n = 1;
    tick(time_cnt, dut, tfp);

    // Pulse 'init' to load the SHA-256 magic constants
    std::cout << "[TB] Initializing Core..." << std::endl;
    dut->init = 1;
    tick(time_cnt, dut, tfp);
    dut->init = 0;
    tick(time_cnt, dut, tfp);

    // ---------------------------------------------------------
    // 2. Prepare the Input Block (Testing string: "abc")
    // ---------------------------------------------------------
    // "abc" in ASCII is 0x61, 0x62, 0x63 (24 bits total).
    // Padded block: 0x61626380 followed by zeros, ending with length in bits (24).
    //
    // Note on Verilator Wide Signals: A logic [511:0] becomes a uint32_t[16] array.
    // Index [0] is the LSB (bits 31:0), Index [15] is the MSB (bits 511:480).
    
    // Clear the array first
    for(int i=0; i<16; i++) {
        dut->block_in[i] = 0;
    }
    
    // Set the padded string at the MSB (W[0] in our SV code)
    dut->block_in[15] = 0x61626380; 
    
    // Set the length at the LSB (W[15] in our SV code)
    dut->block_in[0]  = 0x00000018; 

    // Wait for the core to be ready
    while(!dut->ready) {
        tick(time_cnt, dut, tfp);
    }

    // ---------------------------------------------------------
    // 3. Drive the Stimulus
    // ---------------------------------------------------------
    std::cout << "[TB] Sending Block..." << std::endl;
    dut->next_block = 1;
    tick(time_cnt, dut, tfp);
    dut->next_block = 0;

    // ---------------------------------------------------------
    // 4. Wait for processing to complete
    // ---------------------------------------------------------
    std::cout << "[TB] Calculating..." << std::endl;
    while(!dut->hash_valid) {
        tick(time_cnt, dut, tfp);
    }

    // Capture the hash on the exact cycle hash_valid goes high
    uint32_t actual_hash[8];
    for(int i=0; i<8; i++) {
        actual_hash[i] = dut->hash_out[i];
    }

    // ---------------------------------------------------------
    // 5. Verify the Result
    // ---------------------------------------------------------
    // Expected Hash for "abc": ba7816bf 8f01cfea 414140de 5dae2223 b00361a3 96177a9c b410ff61 f20015ad
    uint32_t expected_hash[8] = {
        0xf20015ad, // LSB: H[7] (bits 31:0)
        0xb410ff61, //      H[6]
        0x96177a9c, //      H[5]
        0xb00361a3, //      H[4]
        0x5dae2223, //      H[3]
        0x414140de, //      H[2]
        0x8f01cfea, //      H[1]
        0xba7816bf  // MSB: H[0] (bits 255:224)
    };

    bool pass = true;
    std::cout << std::endl << "--- RESULTS ---" << std::endl;
    std::cout << std::hex << std::setfill('0');
    
    std::cout << "EXPECTED: ";
    for(int i=7; i>=0; i--) std::cout << std::setw(8) << expected_hash[i] << " ";
    std::cout << std::endl;

    std::cout << "ACTUAL:   ";
    for(int i=7; i>=0; i--) std::cout << std::setw(8) << actual_hash[i] << " ";
    std::cout << std::endl;

    for(int i=0; i<8; i++) {
        if(actual_hash[i] != expected_hash[i]) pass = false;
    }

    if (pass) {
        std::cout << "\n[SUCCESS] Hash matches expected NIST vector!" << std::endl;
    } else {
        std::cout << "\n[FAIL] Hash does not match!" << std::endl;
    }

    // Run a few extra cycles so the trace doesn't cut off abruptly
    for(int i=0; i<5; i++) tick(time_cnt, dut, tfp);

    // Cleanup
    tfp->close();
    delete dut;
    delete tfp;
    
    return 0;
}