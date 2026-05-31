// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsha256_core__Syms.h"


VL_ATTR_COLD void Vsha256_core___024root__trace_init_sub__TOP__0(Vsha256_core___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"init",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"next_block",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+51,0,"block_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+67,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"hash_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+69,0,"hash_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("sha256_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"init",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"next_block",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+51,0,"block_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+67,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"hash_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+69,0,"hash_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+1,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+77,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"round_ctr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+3,0,"round_ctr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"round_ctr_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"k_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("H", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+79,0,"H0_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"H1_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"H2_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"H3_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"H4_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"H5_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"H6_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"H7_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"a_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"b_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"c_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"d_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"e_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"f_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"g_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"h_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("w", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+23+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+39,0,"w_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"w_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+43,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+44,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+45,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsha256_core___024root__trace_init_top(Vsha256_core___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_init_top\n"); );
    // Body
    Vsha256_core___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsha256_core___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsha256_core___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsha256_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsha256_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsha256_core___024root__trace_register(Vsha256_core___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsha256_core___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsha256_core___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsha256_core___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsha256_core___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsha256_core___024root__trace_const_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsha256_core___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_const_0\n"); );
    // Init
    Vsha256_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsha256_core___024root*>(voidSelf);
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsha256_core___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsha256_core___024root__trace_const_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+79,(0x6a09e667U),32);
    bufp->fullIData(oldp+80,(0xbb67ae85U),32);
    bufp->fullIData(oldp+81,(0x3c6ef372U),32);
    bufp->fullIData(oldp+82,(0xa54ff53aU),32);
    bufp->fullIData(oldp+83,(0x510e527fU),32);
    bufp->fullIData(oldp+84,(0x9b05688cU),32);
    bufp->fullIData(oldp+85,(0x1f83d9abU),32);
    bufp->fullIData(oldp+86,(0x5be0cd19U),32);
}

VL_ATTR_COLD void Vsha256_core___024root__trace_full_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsha256_core___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_full_0\n"); );
    // Init
    Vsha256_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsha256_core___024root*>(voidSelf);
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsha256_core___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsha256_core___024root__trace_full_0_sub_0(Vsha256_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->sha256_core__DOT__state),2);
    bufp->fullCData(oldp+2,(vlSelf->sha256_core__DOT__round_ctr),6);
    bufp->fullBit(oldp+3,(vlSelf->sha256_core__DOT__round_ctr_en));
    bufp->fullIData(oldp+4,(vlSelf->sha256_core__DOT__k_val),32);
    bufp->fullIData(oldp+5,(vlSelf->sha256_core__DOT__H[0]),32);
    bufp->fullIData(oldp+6,(vlSelf->sha256_core__DOT__H[1]),32);
    bufp->fullIData(oldp+7,(vlSelf->sha256_core__DOT__H[2]),32);
    bufp->fullIData(oldp+8,(vlSelf->sha256_core__DOT__H[3]),32);
    bufp->fullIData(oldp+9,(vlSelf->sha256_core__DOT__H[4]),32);
    bufp->fullIData(oldp+10,(vlSelf->sha256_core__DOT__H[5]),32);
    bufp->fullIData(oldp+11,(vlSelf->sha256_core__DOT__H[6]),32);
    bufp->fullIData(oldp+12,(vlSelf->sha256_core__DOT__H[7]),32);
    bufp->fullIData(oldp+13,(vlSelf->sha256_core__DOT__a),32);
    bufp->fullIData(oldp+14,(vlSelf->sha256_core__DOT__b),32);
    bufp->fullIData(oldp+15,(vlSelf->sha256_core__DOT__c),32);
    bufp->fullIData(oldp+16,(vlSelf->sha256_core__DOT__d),32);
    bufp->fullIData(oldp+17,(vlSelf->sha256_core__DOT__e),32);
    bufp->fullIData(oldp+18,(vlSelf->sha256_core__DOT__f),32);
    bufp->fullIData(oldp+19,(vlSelf->sha256_core__DOT__g),32);
    bufp->fullIData(oldp+20,(vlSelf->sha256_core__DOT__h),32);
    bufp->fullIData(oldp+21,((vlSelf->sha256_core__DOT__temp1 
                              + vlSelf->sha256_core__DOT__temp2)),32);
    bufp->fullIData(oldp+22,((vlSelf->sha256_core__DOT__d 
                              + vlSelf->sha256_core__DOT__temp1)),32);
    bufp->fullIData(oldp+23,(vlSelf->sha256_core__DOT__w[0]),32);
    bufp->fullIData(oldp+24,(vlSelf->sha256_core__DOT__w[1]),32);
    bufp->fullIData(oldp+25,(vlSelf->sha256_core__DOT__w[2]),32);
    bufp->fullIData(oldp+26,(vlSelf->sha256_core__DOT__w[3]),32);
    bufp->fullIData(oldp+27,(vlSelf->sha256_core__DOT__w[4]),32);
    bufp->fullIData(oldp+28,(vlSelf->sha256_core__DOT__w[5]),32);
    bufp->fullIData(oldp+29,(vlSelf->sha256_core__DOT__w[6]),32);
    bufp->fullIData(oldp+30,(vlSelf->sha256_core__DOT__w[7]),32);
    bufp->fullIData(oldp+31,(vlSelf->sha256_core__DOT__w[8]),32);
    bufp->fullIData(oldp+32,(vlSelf->sha256_core__DOT__w[9]),32);
    bufp->fullIData(oldp+33,(vlSelf->sha256_core__DOT__w[10]),32);
    bufp->fullIData(oldp+34,(vlSelf->sha256_core__DOT__w[11]),32);
    bufp->fullIData(oldp+35,(vlSelf->sha256_core__DOT__w[12]),32);
    bufp->fullIData(oldp+36,(vlSelf->sha256_core__DOT__w[13]),32);
    bufp->fullIData(oldp+37,(vlSelf->sha256_core__DOT__w[14]),32);
    bufp->fullIData(oldp+38,(vlSelf->sha256_core__DOT__w[15]),32);
    bufp->fullIData(oldp+39,(vlSelf->sha256_core__DOT__w_next),32);
    bufp->fullIData(oldp+40,(vlSelf->sha256_core__DOT__temp1),32);
    bufp->fullIData(oldp+41,(vlSelf->sha256_core__DOT__temp2),32);
    bufp->fullIData(oldp+42,(vlSelf->sha256_core__DOT__w_val),32);
    bufp->fullIData(oldp+43,(vlSelf->sha256_core__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+44,(vlSelf->sha256_core__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+45,(vlSelf->sha256_core__DOT__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+46,(vlSelf->sha256_core__DOT__unnamedblk4__DOT__i),32);
    bufp->fullBit(oldp+47,(vlSelf->clk));
    bufp->fullBit(oldp+48,(vlSelf->rst_n));
    bufp->fullBit(oldp+49,(vlSelf->init));
    bufp->fullBit(oldp+50,(vlSelf->next_block));
    bufp->fullWData(oldp+51,(vlSelf->block_in),512);
    bufp->fullBit(oldp+67,(vlSelf->ready));
    bufp->fullBit(oldp+68,(vlSelf->hash_valid));
    bufp->fullWData(oldp+69,(vlSelf->hash_out),256);
    bufp->fullCData(oldp+77,(vlSelf->sha256_core__DOT__next_state),2);
    bufp->fullBit(oldp+78,(vlSelf->sha256_core__DOT__round_ctr_rst));
}
