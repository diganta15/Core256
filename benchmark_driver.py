import serial
import struct
import time
import hashlib

# --- CONFIGURATION ---
SERIAL_PORT = 'COM10' 
BAUD_RATE = 115200
PAYLOAD_SIZE_KB = 10  # Adjust this to test larger amounts of data (e.g., 50 or 100)

def pad_message(message: bytes) -> bytes:
    """Applies standard SHA-256 padding to a byte array."""
    original_bit_len = len(message) * 8
    message += b'\x80' 
    while (len(message) * 8) % 512 != 448:
        message += b'\x00'
    message += struct.pack('>Q', original_bit_len)
    return message

def run_benchmark(size_kb: int):
    print(f"--- NanoHash-256 Hardware Benchmark ---")
    
    # 1. Generate Dummy Payload
    print(f"Generating {size_kb} KB of test data...")
    message_str = "A" * (size_kb * 1024)
    raw_bytes = message_str.encode('utf-8')
    
    # 2. CPU Gold Standard Hash
    start_cpu = time.perf_counter()
    expected_hash = hashlib.sha256(raw_bytes).hexdigest()
    cpu_time = time.perf_counter() - start_cpu
    
    # 3. Format for FPGA
    padded_data = pad_message(raw_bytes)
    chunks = [padded_data[i:i+64] for i in range(0, len(padded_data), 64)]
    total_bytes_sent = len(padded_data)
    print(f"Formatted into {len(chunks)} blocks ({total_bytes_sent} total padded bytes).")

    try:
        with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2) as ser:
            time.sleep(1) 
            ser.reset_input_buffer() 
            ser.reset_output_buffer()
            
            print("\n======================================================")
            print(" PORT OPEN. HARDWARE SYNC REQUIRED:")
            print("   1. Press the RESET button (S1) on your Tang Nano.")
            print("   2. Press the INIT button (S2) on your Tang Nano.")
            print("======================================================")
            input(" Press [ENTER] when ready to start the benchmark timer...")
            print("\nBenchmarking in progress... please wait.")
            
            final_hash = b''
            
            # --- START HARDWARE TIMER ---
            start_hw = time.perf_counter()
            
            for i, chunk in enumerate(chunks):
                ser.write(chunk)
                result = ser.read(32)
                
                if len(result) == 32:
                    final_hash = result
                else:
                    print(f"\n[FAIL] Error: FPGA timeout on block {i+1}.")
                    return
            
            # --- END HARDWARE TIMER ---
            hw_time = time.perf_counter() - start_hw
            
            hardware_hash_hex = final_hash.hex()
            
            # 4. Results & Analysis
            print("\n==================================")
            print("          RESULTS                 ")
            print("==================================")
            print(f"Expected Hash : {expected_hash}")
            print(f"Hardware Hash : {hardware_hash_hex}")
            
            if expected_hash == hardware_hash_hex:
                print("Status        : PASS ✅ (100% Match)")
            else:
                print("Status        : FAIL ❌ (Mismatch)")
                
            print("\n--- Performance Metrics ---")
            print(f"Payload Size  : {size_kb} KB")
            
            # Hardware speed
            hw_kb_per_sec = (total_bytes_sent / 1024) / hw_time
            print(f"Hardware Time : {hw_time:.4f} seconds")
            print(f"System Speed  : {hw_kb_per_sec:.2f} KB/s")
            
    except serial.SerialException as e:
        print(f"Could not open serial port: {e}")

if __name__ == "__main__":
    # Run the benchmark with a 10 KB payload
    run_benchmark(PAYLOAD_SIZE_KB)