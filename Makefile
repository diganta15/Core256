
RTL_DIR = rtl
TB_DIR  = tb
OBJ_DIR = obj_dir

# Source files
DUT = $(RTL_DIR)/sha256_core.sv
TB  = $(TB_DIR)/tb_sha256.cpp

# Top module name
TOP = sha256_core

# Verilator tool and flags
# -Wall:   Enable all warnings
# --trace: Enable VCD waveform generation
# -cc:     Compile to C++
# --exe:   Link the C++ testbench
# -Mdir:   Specify output directory for generated files
VERILATOR = verilator
VFLAGS    = -Wall --trace -cc $(DUT) --exe $(TB) -Mdir $(OBJ_DIR)

# Phony targets (not actual files)
.PHONY: all build sim clean

# Default target: Run everything
all: sim

# Step 1 & 2: Run Verilator and compile the generated C++ code
build: $(DUT) $(TB)

	@echo " [1/2] Verilating and Compiling...   "

	$(VERILATOR) $(VFLAGS)
	make -j -C $(OBJ_DIR) -f V$(TOP).mk V$(TOP)

# Step 3: Execute the generated binary
sim: build

	@echo " [2/2] Running Simulation...         "

	./$(OBJ_DIR)/V$(TOP)

# Step 4: Clean up build artifacts and waveforms
clean:
	@echo "Cleaning up $(OBJ_DIR) and waveforms..."
	rm -rf $(OBJ_DIR)
	rm -f *.vcd