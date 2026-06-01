import serial
import struct
import time

# --- CONFIGURATION ---
SERIAL_PORT = 'COM10' 
BAUD_RATE = 115200

def pad_message(message: bytes) -> bytes:
    original_bit_len = len(message) * 8
    message += b'\x80' 
    while (len(message) * 8) % 512 != 448:
        message += b'\x00'
    message += struct.pack('>Q', original_bit_len)
    return message

def hardware_hash(message_str: str):
    print(f"Hashing: '{message_str}'")
    padded_data = pad_message(message_str.encode('utf-8'))
    chunks = [padded_data[i:i+64] for i in range(0, len(padded_data), 64)]
    print(f"Formatted into {len(chunks)} block(s) for hardware processing.\n")

    try:
        # 1. Open the port (This causes the electrical glitch)
        with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2) as ser:
            time.sleep(1) 
            
            # 2. Clear any garbage data out of the PC's buffers
            ser.reset_input_buffer() 
            ser.reset_output_buffer()
            
            # 3. Force the user to synchronize the hardware
            print("======================================================")
            print(" PORT IS OPEN AND STABLE. HARDWARE SYNC REQUIRED:")
            print("   1. Press the RESET button (S1) on your Tang Nano.")
            print("   2. Press the INIT button (S2) on your Tang Nano.")
            print("======================================================")
            input(" Press [ENTER] on your keyboard when done to send data...")
            print("")
            
            final_hash = b''
            for i, chunk in enumerate(chunks):
                print(f"Sending Block {i+1}...")
                ser.write(chunk)
                result = ser.read(32)
                
                if len(result) == 32:
                    final_hash = result
                    print(f" -> Intermediate State: {result.hex()}")
                else:
                    print(f"Error: FPGA timeout or incomplete hash. Got {len(result)} bytes.")
                    return
            
            print("\n==================================")
            print(f"FINAL HARDWARE HASH: {final_hash.hex()}")
            print("==================================")
            
    except serial.SerialException as e:
        print(f"Could not open serial port: {e}")

if __name__ == "__main__":
    test_string = "abc"
    hardware_hash(test_string)