// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsha256_core__Syms.h"


void Vsha256_core___024root__trace_chg_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsha256_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_chg_0\n"); );
    // Init
    Vsha256_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsha256_core___024root*>(voidSelf);
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsha256_core___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsha256_core___024root__trace_chg_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->sha256_core__DOT__state),2);
        bufp->chgCData(oldp+1,(vlSelf->sha256_core__DOT__round_ctr),6);
        bufp->chgBit(oldp+2,(vlSelf->sha256_core__DOT__round_ctr_en));
        bufp->chgIData(oldp+3,(vlSelf->sha256_core__DOT__k_val),32);
        bufp->chgIData(oldp+4,(vlSelf->sha256_core__DOT__H[0]),32);
        bufp->chgIData(oldp+5,(vlSelf->sha256_core__DOT__H[1]),32);
        bufp->chgIData(oldp+6,(vlSelf->sha256_core__DOT__H[2]),32);
        bufp->chgIData(oldp+7,(vlSelf->sha256_core__DOT__H[3]),32);
        bufp->chgIData(oldp+8,(vlSelf->sha256_core__DOT__H[4]),32);
        bufp->chgIData(oldp+9,(vlSelf->sha256_core__DOT__H[5]),32);
        bufp->chgIData(oldp+10,(vlSelf->sha256_core__DOT__H[6]),32);
        bufp->chgIData(oldp+11,(vlSelf->sha256_core__DOT__H[7]),32);
        bufp->chgIData(oldp+12,(vlSelf->sha256_core__DOT__a),32);
        bufp->chgIData(oldp+13,(vlSelf->sha256_core__DOT__b),32);
        bufp->chgIData(oldp+14,(vlSelf->sha256_core__DOT__c),32);
        bufp->chgIData(oldp+15,(vlSelf->sha256_core__DOT__d),32);
        bufp->chgIData(oldp+16,(vlSelf->sha256_core__DOT__e),32);
        bufp->chgIData(oldp+17,(vlSelf->sha256_core__DOT__f),32);
        bufp->chgIData(oldp+18,(vlSelf->sha256_core__DOT__g),32);
        bufp->chgIData(oldp+19,(vlSelf->sha256_core__DOT__h),32);
        bufp->chgIData(oldp+20,((vlSelf->sha256_core__DOT__temp1 
                                 + vlSelf->sha256_core__DOT__temp2)),32);
        bufp->chgIData(oldp+21,((vlSelf->sha256_core__DOT__d 
                                 + vlSelf->sha256_core__DOT__temp1)),32);
        bufp->chgIData(oldp+22,(vlSelf->sha256_core__DOT__w[0]),32);
        bufp->chgIData(oldp+23,(vlSelf->sha256_core__DOT__w[1]),32);
        bufp->chgIData(oldp+24,(vlSelf->sha256_core__DOT__w[2]),32);
        bufp->chgIData(oldp+25,(vlSelf->sha256_core__DOT__w[3]),32);
        bufp->chgIData(oldp+26,(vlSelf->sha256_core__DOT__w[4]),32);
        bufp->chgIData(oldp+27,(vlSelf->sha256_core__DOT__w[5]),32);
        bufp->chgIData(oldp+28,(vlSelf->sha256_core__DOT__w[6]),32);
        bufp->chgIData(oldp+29,(vlSelf->sha256_core__DOT__w[7]),32);
        bufp->chgIData(oldp+30,(vlSelf->sha256_core__DOT__w[8]),32);
        bufp->chgIData(oldp+31,(vlSelf->sha256_core__DOT__w[9]),32);
        bufp->chgIData(oldp+32,(vlSelf->sha256_core__DOT__w[10]),32);
        bufp->chgIData(oldp+33,(vlSelf->sha256_core__DOT__w[11]),32);
        bufp->chgIData(oldp+34,(vlSelf->sha256_core__DOT__w[12]),32);
        bufp->chgIData(oldp+35,(vlSelf->sha256_core__DOT__w[13]),32);
        bufp->chgIData(oldp+36,(vlSelf->sha256_core__DOT__w[14]),32);
        bufp->chgIData(oldp+37,(vlSelf->sha256_core__DOT__w[15]),32);
        bufp->chgIData(oldp+38,(vlSelf->sha256_core__DOT__w_next),32);
        bufp->chgIData(oldp+39,(vlSelf->sha256_core__DOT__temp1),32);
        bufp->chgIData(oldp+40,(vlSelf->sha256_core__DOT__temp2),32);
        bufp->chgIData(oldp+41,(vlSelf->sha256_core__DOT__w_val),32);
        bufp->chgIData(oldp+42,(vlSelf->sha256_core__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+43,(vlSelf->sha256_core__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+44,(vlSelf->sha256_core__DOT__unnamedblk3__DOT__i),32);
        bufp->chgIData(oldp+45,(vlSelf->sha256_core__DOT__unnamedblk4__DOT__i),32);
    }
    bufp->chgBit(oldp+46,(vlSelf->clk));
    bufp->chgBit(oldp+47,(vlSelf->rst_n));
    bufp->chgBit(oldp+48,(vlSelf->init));
    bufp->chgBit(oldp+49,(vlSelf->next_block));
    bufp->chgWData(oldp+50,(vlSelf->block_in),512);
    bufp->chgBit(oldp+66,(vlSelf->ready));
    bufp->chgBit(oldp+67,(vlSelf->hash_valid));
    bufp->chgWData(oldp+68,(vlSelf->hash_out),256);
    bufp->chgCData(oldp+76,(vlSelf->sha256_core__DOT__next_state),2);
    bufp->chgBit(oldp+77,(vlSelf->sha256_core__DOT__round_ctr_rst));
}

void Vsha256_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_cleanup\n"); );
    // Init
    Vsha256_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsha256_core___024root*>(voidSelf);
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
