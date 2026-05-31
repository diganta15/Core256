// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsha256_core.h for the primary calling header

#include "Vsha256_core__pch.h"
#include "Vsha256_core__Syms.h"
#include "Vsha256_core___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__stl(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsha256_core___024root___eval_triggers__stl(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsha256_core___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
