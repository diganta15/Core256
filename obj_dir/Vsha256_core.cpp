// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsha256_core__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsha256_core::Vsha256_core(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsha256_core__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , init{vlSymsp->TOP.init}
    , next_block{vlSymsp->TOP.next_block}
    , ready{vlSymsp->TOP.ready}
    , hash_valid{vlSymsp->TOP.hash_valid}
    , block_in{vlSymsp->TOP.block_in}
    , hash_out{vlSymsp->TOP.hash_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsha256_core::Vsha256_core(const char* _vcname__)
    : Vsha256_core(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsha256_core::~Vsha256_core() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsha256_core___024root___eval_debug_assertions(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG
void Vsha256_core___024root___eval_static(Vsha256_core___024root* vlSelf);
void Vsha256_core___024root___eval_initial(Vsha256_core___024root* vlSelf);
void Vsha256_core___024root___eval_settle(Vsha256_core___024root* vlSelf);
void Vsha256_core___024root___eval(Vsha256_core___024root* vlSelf);

void Vsha256_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsha256_core::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsha256_core___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsha256_core___024root___eval_static(&(vlSymsp->TOP));
        Vsha256_core___024root___eval_initial(&(vlSymsp->TOP));
        Vsha256_core___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsha256_core___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsha256_core::eventsPending() { return false; }

uint64_t Vsha256_core::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsha256_core::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsha256_core___024root___eval_final(Vsha256_core___024root* vlSelf);

VL_ATTR_COLD void Vsha256_core::final() {
    Vsha256_core___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsha256_core::hierName() const { return vlSymsp->name(); }
const char* Vsha256_core::modelName() const { return "Vsha256_core"; }
unsigned Vsha256_core::threads() const { return 1; }
void Vsha256_core::prepareClone() const { contextp()->prepareClone(); }
void Vsha256_core::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsha256_core::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsha256_core___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsha256_core___024root__trace_init_top(Vsha256_core___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsha256_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsha256_core___024root*>(voidSelf);
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsha256_core___024root__trace_decl_types(tracep);
    Vsha256_core___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsha256_core___024root__trace_register(Vsha256_core___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsha256_core::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsha256_core::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsha256_core___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
