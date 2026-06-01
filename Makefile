SRC_DIR = src
TB_DIR  = tb
OBJ_DIR = obj_dir

DUT = $(SRC_DIR)/sha256_core.sv
TB  = $(TB_DIR)/tb_sha256.cpp
TOP = sha256_core

VERILATOR = verilator
VFLAGS    = -Wall --trace -cc $(DUT) --exe $(TB) -Mdir $(OBJ_DIR)

.PHONY: all build sim clean

all: sim

build: $(DUT) $(TB)
	@echo "====================================="
	@echo " [1/2] Verilating and Compiling...   "
	@echo "====================================="
	$(VERILATOR) $(VFLAGS)
	make -j -C $(OBJ_DIR) -f V$(TOP).mk V$(TOP)

sim: build
	@echo "====================================="
	@echo " [2/2] Running Simulation...         "
	@echo "====================================="
	./$(OBJ_DIR)/V$(TOP)

clean:
	@echo "Cleaning up $(OBJ_DIR) and waveforms..."
	rm -rf $(OBJ_DIR)
	rm -f *.vcd