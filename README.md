# Core256: Hardware Cryptographic Coprocessor

> A lightweight, fully synthesizable SHA-256 hardware accelerator written in SystemVerilog for the Gowin Tang Nano 9K FPGA.

This project demonstrates hardware-software co-design by using a Python host driver to stream pre-padded data blocks over UART to the FPGA, calculating the hash entirely in silicon, and returning the 256-bit digest.

---

## Features

- **Area-Optimized Core** — 64-cycle iterative SHA-256 architecture fitting comfortably within a Tang Nano 9K.
- **Full SoC Integration** — Includes custom UART RX/TX modules and a master state machine for continuous block streaming.
- **Hardware/Software Handshake** — Robust Python host driver with buffer-clearing and synchronization to prevent USB-to-UART glitches.
- **Benchmarking Suite** — Included Python profiling script to test maximum hardware/I/O throughput.

---

## Repository Structure

```text
NanoHash-256/
├── src/                        # RTL source files
│   ├── sha256_core.sv          # The core mathematical hash engine
│   ├── sha256_soc.sv           # Top-level wrapper tying UART and Core together
│   ├── uart_rx.sv              # Serial receiver (115200 baud)
│   └── uart_tx.sv              # Serial transmitter (115200 baud)
├── tb/                         # Testbench
│   └── tb_sha256.cpp           # Cycle-accurate Verilator C++ testbench
├── impl/                       # Gowin EDA implementation output
├── obj_dir/                    # Verilator build artifacts
├── benchmark_driver.py         # High-speed payload generator and throughput tester
├── host_driver.py              # Standard Python driver for hashing strings
├── core256.gprj                # Gowin EDA project file
├── core256.gprj.user           # Gowin EDA user project settings
├── sha256_trace.vcd            # Waveform dump from simulation
├── Makefile                    # Build automation for Verilator simulation
└── README.md
```

---

## Hardware & Software Requirements

| Requirement | Details |
|---|---|
| **Hardware** | Gowin Tang Nano 9K (uses the onboard BL702 chip for both programming and UART communication) |
| **Software IDE** | Gowin EDA (Education or Standard edition) |
| **Python** | Python 3.x with the `pyserial` library |

Install the Python dependency with:

```bash
pip install pyserial
```

---

## Quick Start Guide

### 1. Synthesize and Flash the FPGA

1. Open **Gowin EDA** and create a new project for the Tang Nano 9K (`GW1NR-LV9`).
2. Add all `.sv` files from the `src/` folder to the **Design** tab.
3. Add `tang_nano_9k.cst` to the **Physical Constraints** tab.
4. **Critical:** Go to `Project → Configuration → Synthesize → General` and change the Verilog Language standard from **Verilog 2001** to **SystemVerilog 2017**.
5. Run **Synthesis** and **Place & Route**.
6. Open the **Gowin Programmer**, flash the bitstream to SRAM or Flash, then close the programmer.

---

### 2. Configure the Python Driver

Open `host_driver.py` and set the `SERIAL_PORT` variable to match your system:

| OS | Port Format | Example |
|---|---|---|
| Windows | `'COMx'` | `'COM3'` (check Device Manager) |
| Linux / WSL | `'/dev/ttyUSBx'` or `'/dev/ttySx'` | `'/dev/ttyUSB0'` |

---

### 3. Run the Hardware Hash

> **Note:** Opening a USB serial port sends a hardware glitch (DTR/RTS toggle) to the FPGA, so a manual handshake is required.

1. Run the Python script:
   ```bash
   python host_driver.py
   ```
2. Wait for the terminal to display:
   ```
   PORT OPEN AND STABLE. HARDWARE SYNC REQUIRED.
   ```
3. On your Tang Nano 9K, press **Button 1 (S1)** to clear the reset/glitch state.
4. Press **Button 2 (S2)** to initialize the SHA-256 mathematical constants.
5. Press **Enter** on your PC keyboard to stream the data.

You should see the intermediate block states and the final matched hash.

---

## Performance Benchmarking

Run the included benchmark script to test maximum UART SoC throughput:

```bash
python benchmark_driver.py
```

This generates a dummy payload (default 10 KB), calculates the expected hash via the host CPU, then streams the data to the FPGA while measuring round-trip time.

### Results

| Metric | Value |
|---|---|
| UART Baud Rate | 115,200 baud |
| Practical I/O Throughput | ~6.6 KB/s |
| SHA-256 Core Compute Speed | ~26 MB/s |
| FPGA Time Spent Waiting on I/O | ~99% |

**Current Bottleneck:** The system is entirely I/O bound. The SystemVerilog core computes far faster than UART can feed it data.

**Future Upgrade Path:** To unlock the core's true speed, bypass the onboard UART and connect a high-speed USB-to-SPI bridge (such as an **FT232H** module) to the FPGA's GPIO pins.