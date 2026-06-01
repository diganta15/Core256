// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsha256_core.h for the primary calling header

#include "Vsha256_core__pch.h"
#include "Vsha256_core___024root.h"

VL_INLINE_OPT void Vsha256_core___024root___ico_sequent__TOP__0(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->sha256_core__DOT__round_ctr_rst = 0U;
    vlSelf->sha256_core__DOT__next_state = vlSelf->sha256_core__DOT__state;
    if ((0U == (IData)(vlSelf->sha256_core__DOT__state))) {
        if (vlSelf->next_block) {
            vlSelf->sha256_core__DOT__round_ctr_rst = 1U;
            vlSelf->sha256_core__DOT__next_state = 1U;
        }
    } else {
        if ((1U != (IData)(vlSelf->sha256_core__DOT__state))) {
            if ((2U == (IData)(vlSelf->sha256_core__DOT__state))) {
                if (vlSelf->next_block) {
                    vlSelf->sha256_core__DOT__round_ctr_rst = 1U;
                }
            }
        }
        if ((1U == (IData)(vlSelf->sha256_core__DOT__state))) {
            if ((0x3fU == (IData)(vlSelf->sha256_core__DOT__round_ctr))) {
                vlSelf->sha256_core__DOT__next_state = 2U;
            }
        } else {
            vlSelf->sha256_core__DOT__next_state = 
                ((2U == (IData)(vlSelf->sha256_core__DOT__state))
                  ? ((IData)(vlSelf->next_block) ? 1U
                      : 0U) : 0U);
        }
    }
}

void Vsha256_core___024root___eval_ico(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsha256_core___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vsha256_core___024root___eval_triggers__ico(Vsha256_core___024root* vlSelf);

bool Vsha256_core___024root___eval_phase__ico(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsha256_core___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsha256_core___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsha256_core___024root___eval_act(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_act\n"); );
}

extern const VlUnpacked<IData/*31:0*/, 64> Vsha256_core__ConstPool__TABLE_hfa1e13c0_0;

VL_INLINE_OPT void Vsha256_core___024root___nba_sequent__TOP__0(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vdly__sha256_core__DOT__round_ctr;
    __Vdly__sha256_core__DOT__round_ctr = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__H__v0;
    __Vdlyvset__sha256_core__DOT__H__v0 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__a;
    __Vdly__sha256_core__DOT__a = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v0;
    __Vdlyvval__sha256_core__DOT__w__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v0;
    __Vdlyvset__sha256_core__DOT__w__v0 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__b;
    __Vdly__sha256_core__DOT__b = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v1;
    __Vdlyvval__sha256_core__DOT__w__v1 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v1;
    __Vdlyvset__sha256_core__DOT__w__v1 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__c;
    __Vdly__sha256_core__DOT__c = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v2;
    __Vdlyvval__sha256_core__DOT__w__v2 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v2;
    __Vdlyvset__sha256_core__DOT__w__v2 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__d;
    __Vdly__sha256_core__DOT__d = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v3;
    __Vdlyvval__sha256_core__DOT__w__v3 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v3;
    __Vdlyvset__sha256_core__DOT__w__v3 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__e;
    __Vdly__sha256_core__DOT__e = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v4;
    __Vdlyvval__sha256_core__DOT__w__v4 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v4;
    __Vdlyvset__sha256_core__DOT__w__v4 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__f;
    __Vdly__sha256_core__DOT__f = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v5;
    __Vdlyvval__sha256_core__DOT__w__v5 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v5;
    __Vdlyvset__sha256_core__DOT__w__v5 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__g;
    __Vdly__sha256_core__DOT__g = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v6;
    __Vdlyvval__sha256_core__DOT__w__v6 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v6;
    __Vdlyvset__sha256_core__DOT__w__v6 = 0;
    IData/*31:0*/ __Vdly__sha256_core__DOT__h;
    __Vdly__sha256_core__DOT__h = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v7;
    __Vdlyvval__sha256_core__DOT__w__v7 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v7;
    __Vdlyvset__sha256_core__DOT__w__v7 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v8;
    __Vdlyvval__sha256_core__DOT__w__v8 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v9;
    __Vdlyvval__sha256_core__DOT__w__v9 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v10;
    __Vdlyvval__sha256_core__DOT__w__v10 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v11;
    __Vdlyvval__sha256_core__DOT__w__v11 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v12;
    __Vdlyvval__sha256_core__DOT__w__v12 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v13;
    __Vdlyvval__sha256_core__DOT__w__v13 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v14;
    __Vdlyvval__sha256_core__DOT__w__v14 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v15;
    __Vdlyvval__sha256_core__DOT__w__v15 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v16;
    __Vdlyvval__sha256_core__DOT__w__v16 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v16;
    __Vdlyvset__sha256_core__DOT__w__v16 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v17;
    __Vdlyvval__sha256_core__DOT__w__v17 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v18;
    __Vdlyvval__sha256_core__DOT__w__v18 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v19;
    __Vdlyvval__sha256_core__DOT__w__v19 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v20;
    __Vdlyvval__sha256_core__DOT__w__v20 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v21;
    __Vdlyvval__sha256_core__DOT__w__v21 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v22;
    __Vdlyvval__sha256_core__DOT__w__v22 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v23;
    __Vdlyvval__sha256_core__DOT__w__v23 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v24;
    __Vdlyvval__sha256_core__DOT__w__v24 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v25;
    __Vdlyvval__sha256_core__DOT__w__v25 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v26;
    __Vdlyvval__sha256_core__DOT__w__v26 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v27;
    __Vdlyvval__sha256_core__DOT__w__v27 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v28;
    __Vdlyvval__sha256_core__DOT__w__v28 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v29;
    __Vdlyvval__sha256_core__DOT__w__v29 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v30;
    __Vdlyvval__sha256_core__DOT__w__v30 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__w__v31;
    __Vdlyvval__sha256_core__DOT__w__v31 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v8;
    __Vdlyvval__sha256_core__DOT__H__v8 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__H__v8;
    __Vdlyvset__sha256_core__DOT__H__v8 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v9;
    __Vdlyvval__sha256_core__DOT__H__v9 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v10;
    __Vdlyvval__sha256_core__DOT__H__v10 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v11;
    __Vdlyvval__sha256_core__DOT__H__v11 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v12;
    __Vdlyvval__sha256_core__DOT__H__v12 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v13;
    __Vdlyvval__sha256_core__DOT__H__v13 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v14;
    __Vdlyvval__sha256_core__DOT__H__v14 = 0;
    IData/*31:0*/ __Vdlyvval__sha256_core__DOT__H__v15;
    __Vdlyvval__sha256_core__DOT__H__v15 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__H__v16;
    __Vdlyvset__sha256_core__DOT__H__v16 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__H__v17;
    __Vdlyvset__sha256_core__DOT__H__v17 = 0;
    CData/*0:0*/ __Vdlyvset__sha256_core__DOT__w__v32;
    __Vdlyvset__sha256_core__DOT__w__v32 = 0;
    // Body
    __Vdly__sha256_core__DOT__d = vlSelf->sha256_core__DOT__d;
    __Vdlyvset__sha256_core__DOT__H__v0 = 0U;
    __Vdlyvset__sha256_core__DOT__H__v8 = 0U;
    __Vdlyvset__sha256_core__DOT__H__v16 = 0U;
    __Vdlyvset__sha256_core__DOT__H__v17 = 0U;
    __Vdly__sha256_core__DOT__c = vlSelf->sha256_core__DOT__c;
    __Vdly__sha256_core__DOT__b = vlSelf->sha256_core__DOT__b;
    __Vdly__sha256_core__DOT__a = vlSelf->sha256_core__DOT__a;
    __Vdly__sha256_core__DOT__h = vlSelf->sha256_core__DOT__h;
    __Vdly__sha256_core__DOT__g = vlSelf->sha256_core__DOT__g;
    __Vdly__sha256_core__DOT__f = vlSelf->sha256_core__DOT__f;
    __Vdly__sha256_core__DOT__e = vlSelf->sha256_core__DOT__e;
    __Vdly__sha256_core__DOT__round_ctr = vlSelf->sha256_core__DOT__round_ctr;
    __Vdlyvset__sha256_core__DOT__w__v0 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v1 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v2 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v3 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v4 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v5 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v6 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v7 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v16 = 0U;
    __Vdlyvset__sha256_core__DOT__w__v32 = 0U;
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->sha256_core__DOT__unnamedblk1__DOT__i = 8U;
        vlSelf->sha256_core__DOT__unnamedblk2__DOT__i = 0x10U;
    }
    if (vlSelf->rst_n) {
        if (vlSelf->sha256_core__DOT__round_ctr_rst) {
            __Vdly__sha256_core__DOT__round_ctr = 0U;
        } else if (vlSelf->sha256_core__DOT__round_ctr_en) {
            __Vdly__sha256_core__DOT__round_ctr = (0x3fU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->sha256_core__DOT__round_ctr)));
        }
        if (vlSelf->init) {
            __Vdlyvset__sha256_core__DOT__H__v0 = 1U;
        }
        vlSelf->hash_valid = (2U == (IData)(vlSelf->sha256_core__DOT__state));
        if (((0U == (IData)(vlSelf->sha256_core__DOT__state)) 
             & (IData)(vlSelf->next_block))) {
            vlSelf->sha256_core__DOT__unnamedblk3__DOT__i = 0x10U;
            __Vdly__sha256_core__DOT__a = vlSelf->sha256_core__DOT__H
                [0U];
            __Vdlyvval__sha256_core__DOT__w__v0 = vlSelf->block_in[0xfU];
            __Vdlyvset__sha256_core__DOT__w__v0 = 1U;
            __Vdly__sha256_core__DOT__b = vlSelf->sha256_core__DOT__H
                [1U];
            __Vdlyvval__sha256_core__DOT__w__v1 = vlSelf->block_in[0xeU];
            __Vdlyvset__sha256_core__DOT__w__v1 = 1U;
            __Vdly__sha256_core__DOT__c = vlSelf->sha256_core__DOT__H
                [2U];
            __Vdlyvval__sha256_core__DOT__w__v2 = vlSelf->block_in[0xdU];
            __Vdlyvset__sha256_core__DOT__w__v2 = 1U;
            __Vdly__sha256_core__DOT__d = vlSelf->sha256_core__DOT__H
                [3U];
            __Vdlyvval__sha256_core__DOT__w__v3 = vlSelf->block_in[0xcU];
            __Vdlyvset__sha256_core__DOT__w__v3 = 1U;
            __Vdly__sha256_core__DOT__e = vlSelf->sha256_core__DOT__H
                [4U];
            __Vdlyvval__sha256_core__DOT__w__v4 = vlSelf->block_in[0xbU];
            __Vdlyvset__sha256_core__DOT__w__v4 = 1U;
            __Vdly__sha256_core__DOT__f = vlSelf->sha256_core__DOT__H
                [5U];
            __Vdlyvval__sha256_core__DOT__w__v5 = vlSelf->block_in[0xaU];
            __Vdlyvset__sha256_core__DOT__w__v5 = 1U;
            __Vdly__sha256_core__DOT__g = vlSelf->sha256_core__DOT__H
                [6U];
            __Vdlyvval__sha256_core__DOT__w__v6 = vlSelf->block_in[9U];
            __Vdlyvset__sha256_core__DOT__w__v6 = 1U;
            __Vdly__sha256_core__DOT__h = vlSelf->sha256_core__DOT__H
                [7U];
            __Vdlyvval__sha256_core__DOT__w__v7 = vlSelf->block_in[8U];
            __Vdlyvset__sha256_core__DOT__w__v7 = 1U;
            __Vdlyvval__sha256_core__DOT__w__v8 = vlSelf->block_in[7U];
            __Vdlyvval__sha256_core__DOT__w__v9 = vlSelf->block_in[6U];
            __Vdlyvval__sha256_core__DOT__w__v10 = 
                vlSelf->block_in[5U];
            __Vdlyvval__sha256_core__DOT__w__v11 = 
                vlSelf->block_in[4U];
            __Vdlyvval__sha256_core__DOT__w__v12 = 
                vlSelf->block_in[3U];
            __Vdlyvval__sha256_core__DOT__w__v13 = 
                vlSelf->block_in[2U];
            __Vdlyvval__sha256_core__DOT__w__v14 = 
                vlSelf->block_in[1U];
            __Vdlyvval__sha256_core__DOT__w__v15 = 
                vlSelf->block_in[0U];
        } else if ((1U == (IData)(vlSelf->sha256_core__DOT__state))) {
            if ((0x10U <= (IData)(vlSelf->sha256_core__DOT__round_ctr))) {
                vlSelf->sha256_core__DOT__unnamedblk4__DOT__i = 0xfU;
                __Vdlyvval__sha256_core__DOT__w__v16 
                    = vlSelf->sha256_core__DOT__w[1U];
                __Vdlyvset__sha256_core__DOT__w__v16 = 1U;
                __Vdlyvval__sha256_core__DOT__w__v17 
                    = vlSelf->sha256_core__DOT__w[2U];
                __Vdlyvval__sha256_core__DOT__w__v18 
                    = vlSelf->sha256_core__DOT__w[3U];
                __Vdlyvval__sha256_core__DOT__w__v19 
                    = vlSelf->sha256_core__DOT__w[4U];
                __Vdlyvval__sha256_core__DOT__w__v20 
                    = vlSelf->sha256_core__DOT__w[5U];
                __Vdlyvval__sha256_core__DOT__w__v21 
                    = vlSelf->sha256_core__DOT__w[6U];
                __Vdlyvval__sha256_core__DOT__w__v22 
                    = vlSelf->sha256_core__DOT__w[7U];
                __Vdlyvval__sha256_core__DOT__w__v23 
                    = vlSelf->sha256_core__DOT__w[8U];
                __Vdlyvval__sha256_core__DOT__w__v24 
                    = vlSelf->sha256_core__DOT__w[9U];
                __Vdlyvval__sha256_core__DOT__w__v25 
                    = vlSelf->sha256_core__DOT__w[0xaU];
                __Vdlyvval__sha256_core__DOT__w__v26 
                    = vlSelf->sha256_core__DOT__w[0xbU];
                __Vdlyvval__sha256_core__DOT__w__v27 
                    = vlSelf->sha256_core__DOT__w[0xcU];
                __Vdlyvval__sha256_core__DOT__w__v28 
                    = vlSelf->sha256_core__DOT__w[0xdU];
                __Vdlyvval__sha256_core__DOT__w__v29 
                    = vlSelf->sha256_core__DOT__w[0xeU];
                __Vdlyvval__sha256_core__DOT__w__v30 
                    = vlSelf->sha256_core__DOT__w[0xfU];
                __Vdlyvval__sha256_core__DOT__w__v31 
                    = vlSelf->sha256_core__DOT__w_val;
            }
            __Vdly__sha256_core__DOT__a = (vlSelf->sha256_core__DOT__temp1 
                                           + vlSelf->sha256_core__DOT__temp2);
            __Vdly__sha256_core__DOT__b = vlSelf->sha256_core__DOT__b_next;
            __Vdly__sha256_core__DOT__c = vlSelf->sha256_core__DOT__c_next;
            __Vdly__sha256_core__DOT__d = vlSelf->sha256_core__DOT__d_next;
            __Vdly__sha256_core__DOT__e = vlSelf->sha256_core__DOT__e_next;
            __Vdly__sha256_core__DOT__f = vlSelf->sha256_core__DOT__f_next;
            __Vdly__sha256_core__DOT__g = vlSelf->sha256_core__DOT__g_next;
            __Vdly__sha256_core__DOT__h = vlSelf->sha256_core__DOT__h_next;
        } else if ((2U == (IData)(vlSelf->sha256_core__DOT__state))) {
            __Vdlyvval__sha256_core__DOT__H__v8 = (
                                                   vlSelf->sha256_core__DOT__H
                                                   [0U] 
                                                   + vlSelf->sha256_core__DOT__a);
            __Vdlyvset__sha256_core__DOT__H__v8 = 1U;
            __Vdlyvval__sha256_core__DOT__H__v9 = (
                                                   vlSelf->sha256_core__DOT__H
                                                   [1U] 
                                                   + vlSelf->sha256_core__DOT__b);
            __Vdlyvval__sha256_core__DOT__H__v10 = 
                (vlSelf->sha256_core__DOT__H[2U] + vlSelf->sha256_core__DOT__c);
            __Vdlyvval__sha256_core__DOT__H__v11 = 
                (vlSelf->sha256_core__DOT__H[3U] + vlSelf->sha256_core__DOT__d);
            __Vdlyvval__sha256_core__DOT__H__v12 = 
                (vlSelf->sha256_core__DOT__H[4U] + vlSelf->sha256_core__DOT__e);
            __Vdlyvval__sha256_core__DOT__H__v13 = 
                (vlSelf->sha256_core__DOT__H[5U] + vlSelf->sha256_core__DOT__f);
            __Vdlyvval__sha256_core__DOT__H__v14 = 
                (vlSelf->sha256_core__DOT__H[6U] + vlSelf->sha256_core__DOT__g);
            __Vdlyvval__sha256_core__DOT__H__v15 = 
                (vlSelf->sha256_core__DOT__H[7U] + vlSelf->sha256_core__DOT__h);
        }
    } else {
        __Vdlyvset__sha256_core__DOT__H__v16 = 1U;
        __Vdly__sha256_core__DOT__round_ctr = 0U;
        vlSelf->hash_valid = 0U;
        __Vdlyvset__sha256_core__DOT__H__v17 = 1U;
        __Vdly__sha256_core__DOT__a = 0U;
        __Vdly__sha256_core__DOT__b = 0U;
        __Vdly__sha256_core__DOT__c = 0U;
        __Vdly__sha256_core__DOT__d = 0U;
        __Vdly__sha256_core__DOT__e = 0U;
        __Vdly__sha256_core__DOT__f = 0U;
        __Vdly__sha256_core__DOT__g = 0U;
        __Vdly__sha256_core__DOT__h = 0U;
        __Vdlyvset__sha256_core__DOT__w__v32 = 1U;
    }
    vlSelf->sha256_core__DOT__d = __Vdly__sha256_core__DOT__d;
    vlSelf->sha256_core__DOT__a = __Vdly__sha256_core__DOT__a;
    vlSelf->sha256_core__DOT__b = __Vdly__sha256_core__DOT__b;
    vlSelf->sha256_core__DOT__c = __Vdly__sha256_core__DOT__c;
    vlSelf->sha256_core__DOT__h = __Vdly__sha256_core__DOT__h;
    vlSelf->sha256_core__DOT__e = __Vdly__sha256_core__DOT__e;
    vlSelf->sha256_core__DOT__f = __Vdly__sha256_core__DOT__f;
    vlSelf->sha256_core__DOT__g = __Vdly__sha256_core__DOT__g;
    vlSelf->sha256_core__DOT__round_ctr = __Vdly__sha256_core__DOT__round_ctr;
    if (__Vdlyvset__sha256_core__DOT__H__v0) {
        vlSelf->sha256_core__DOT__H[0U] = 0x6a09e667U;
        vlSelf->sha256_core__DOT__H[1U] = 0xbb67ae85U;
        vlSelf->sha256_core__DOT__H[2U] = 0x3c6ef372U;
        vlSelf->sha256_core__DOT__H[3U] = 0xa54ff53aU;
        vlSelf->sha256_core__DOT__H[4U] = 0x510e527fU;
        vlSelf->sha256_core__DOT__H[5U] = 0x9b05688cU;
        vlSelf->sha256_core__DOT__H[6U] = 0x1f83d9abU;
        vlSelf->sha256_core__DOT__H[7U] = 0x5be0cd19U;
    }
    if (__Vdlyvset__sha256_core__DOT__H__v8) {
        vlSelf->sha256_core__DOT__H[0U] = __Vdlyvval__sha256_core__DOT__H__v8;
        vlSelf->sha256_core__DOT__H[1U] = __Vdlyvval__sha256_core__DOT__H__v9;
        vlSelf->sha256_core__DOT__H[2U] = __Vdlyvval__sha256_core__DOT__H__v10;
        vlSelf->sha256_core__DOT__H[3U] = __Vdlyvval__sha256_core__DOT__H__v11;
        vlSelf->sha256_core__DOT__H[4U] = __Vdlyvval__sha256_core__DOT__H__v12;
        vlSelf->sha256_core__DOT__H[5U] = __Vdlyvval__sha256_core__DOT__H__v13;
        vlSelf->sha256_core__DOT__H[6U] = __Vdlyvval__sha256_core__DOT__H__v14;
        vlSelf->sha256_core__DOT__H[7U] = __Vdlyvval__sha256_core__DOT__H__v15;
    }
    if (__Vdlyvset__sha256_core__DOT__H__v16) {
        vlSelf->sha256_core__DOT__H[0U] = 0U;
    }
    if (__Vdlyvset__sha256_core__DOT__H__v17) {
        vlSelf->sha256_core__DOT__H[1U] = 0U;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v0) {
        vlSelf->sha256_core__DOT__w[0U] = __Vdlyvval__sha256_core__DOT__w__v0;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v1) {
        vlSelf->sha256_core__DOT__w[1U] = __Vdlyvval__sha256_core__DOT__w__v1;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v2) {
        vlSelf->sha256_core__DOT__w[2U] = __Vdlyvval__sha256_core__DOT__w__v2;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v3) {
        vlSelf->sha256_core__DOT__w[3U] = __Vdlyvval__sha256_core__DOT__w__v3;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v4) {
        vlSelf->sha256_core__DOT__w[4U] = __Vdlyvval__sha256_core__DOT__w__v4;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v5) {
        vlSelf->sha256_core__DOT__w[5U] = __Vdlyvval__sha256_core__DOT__w__v5;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v6) {
        vlSelf->sha256_core__DOT__w[6U] = __Vdlyvval__sha256_core__DOT__w__v6;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v7) {
        vlSelf->sha256_core__DOT__w[7U] = __Vdlyvval__sha256_core__DOT__w__v7;
        vlSelf->sha256_core__DOT__w[8U] = __Vdlyvval__sha256_core__DOT__w__v8;
        vlSelf->sha256_core__DOT__w[9U] = __Vdlyvval__sha256_core__DOT__w__v9;
        vlSelf->sha256_core__DOT__w[0xaU] = __Vdlyvval__sha256_core__DOT__w__v10;
        vlSelf->sha256_core__DOT__w[0xbU] = __Vdlyvval__sha256_core__DOT__w__v11;
        vlSelf->sha256_core__DOT__w[0xcU] = __Vdlyvval__sha256_core__DOT__w__v12;
        vlSelf->sha256_core__DOT__w[0xdU] = __Vdlyvval__sha256_core__DOT__w__v13;
        vlSelf->sha256_core__DOT__w[0xeU] = __Vdlyvval__sha256_core__DOT__w__v14;
        vlSelf->sha256_core__DOT__w[0xfU] = __Vdlyvval__sha256_core__DOT__w__v15;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v16) {
        vlSelf->sha256_core__DOT__w[0U] = __Vdlyvval__sha256_core__DOT__w__v16;
        vlSelf->sha256_core__DOT__w[1U] = __Vdlyvval__sha256_core__DOT__w__v17;
        vlSelf->sha256_core__DOT__w[2U] = __Vdlyvval__sha256_core__DOT__w__v18;
        vlSelf->sha256_core__DOT__w[3U] = __Vdlyvval__sha256_core__DOT__w__v19;
        vlSelf->sha256_core__DOT__w[4U] = __Vdlyvval__sha256_core__DOT__w__v20;
        vlSelf->sha256_core__DOT__w[5U] = __Vdlyvval__sha256_core__DOT__w__v21;
        vlSelf->sha256_core__DOT__w[6U] = __Vdlyvval__sha256_core__DOT__w__v22;
        vlSelf->sha256_core__DOT__w[7U] = __Vdlyvval__sha256_core__DOT__w__v23;
        vlSelf->sha256_core__DOT__w[8U] = __Vdlyvval__sha256_core__DOT__w__v24;
        vlSelf->sha256_core__DOT__w[9U] = __Vdlyvval__sha256_core__DOT__w__v25;
        vlSelf->sha256_core__DOT__w[0xaU] = __Vdlyvval__sha256_core__DOT__w__v26;
        vlSelf->sha256_core__DOT__w[0xbU] = __Vdlyvval__sha256_core__DOT__w__v27;
        vlSelf->sha256_core__DOT__w[0xcU] = __Vdlyvval__sha256_core__DOT__w__v28;
        vlSelf->sha256_core__DOT__w[0xdU] = __Vdlyvval__sha256_core__DOT__w__v29;
        vlSelf->sha256_core__DOT__w[0xeU] = __Vdlyvval__sha256_core__DOT__w__v30;
        vlSelf->sha256_core__DOT__w[0xfU] = __Vdlyvval__sha256_core__DOT__w__v31;
    }
    if (__Vdlyvset__sha256_core__DOT__w__v32) {
        vlSelf->sha256_core__DOT__H[2U] = 0U;
        vlSelf->sha256_core__DOT__H[3U] = 0U;
        vlSelf->sha256_core__DOT__H[4U] = 0U;
        vlSelf->sha256_core__DOT__H[5U] = 0U;
        vlSelf->sha256_core__DOT__H[6U] = 0U;
        vlSelf->sha256_core__DOT__H[7U] = 0U;
        vlSelf->sha256_core__DOT__w[0U] = 0U;
        vlSelf->sha256_core__DOT__w[1U] = 0U;
        vlSelf->sha256_core__DOT__w[2U] = 0U;
        vlSelf->sha256_core__DOT__w[3U] = 0U;
        vlSelf->sha256_core__DOT__w[4U] = 0U;
        vlSelf->sha256_core__DOT__w[5U] = 0U;
        vlSelf->sha256_core__DOT__w[6U] = 0U;
        vlSelf->sha256_core__DOT__w[7U] = 0U;
        vlSelf->sha256_core__DOT__w[8U] = 0U;
        vlSelf->sha256_core__DOT__w[9U] = 0U;
        vlSelf->sha256_core__DOT__w[0xaU] = 0U;
        vlSelf->sha256_core__DOT__w[0xbU] = 0U;
        vlSelf->sha256_core__DOT__w[0xcU] = 0U;
        vlSelf->sha256_core__DOT__w[0xdU] = 0U;
        vlSelf->sha256_core__DOT__w[0xeU] = 0U;
        vlSelf->sha256_core__DOT__w[0xfU] = 0U;
    }
    vlSelf->sha256_core__DOT__b_next = vlSelf->sha256_core__DOT__a;
    vlSelf->sha256_core__DOT__c_next = vlSelf->sha256_core__DOT__b;
    vlSelf->sha256_core__DOT__d_next = vlSelf->sha256_core__DOT__c;
    vlSelf->sha256_core__DOT__temp2 = (([&]() {
                vlSelf->__Vfunc_sha256_core__DOT__EP0__11__x 
                    = vlSelf->sha256_core__DOT__a;
                vlSelf->__Vfunc_sha256_core__DOT__EP0__11__Vfuncout 
                    = ((([&]() {
                                vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__x 
                                    = vlSelf->__Vfunc_sha256_core__DOT__EP0__11__x;
                                vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__x, 2U) 
                                       | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__x, 0x1eU));
                            }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__Vfuncout) 
                        ^ ([&]() {
                                vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__x 
                                    = vlSelf->__Vfunc_sha256_core__DOT__EP0__11__x;
                                vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__Vfuncout 
                                    = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__x, 0xdU) 
                                       | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__x, 0x13U));
                            }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__Vfuncout)) 
                       ^ ([&]() {
                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__x 
                                = vlSelf->__Vfunc_sha256_core__DOT__EP0__11__x;
                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__Vfuncout 
                                = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__x, 0x16U) 
                                   | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__x, 0xaU));
                        }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__Vfuncout));
            }(), vlSelf->__Vfunc_sha256_core__DOT__EP0__11__Vfuncout) 
                                       + ([&]() {
                vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__z 
                    = vlSelf->sha256_core__DOT__c;
                vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__y 
                    = vlSelf->sha256_core__DOT__b;
                vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__x 
                    = vlSelf->sha256_core__DOT__a;
                vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__Vfuncout 
                    = (((vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__x 
                         & vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__y) 
                        ^ (vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__x 
                           & vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__z)) 
                       ^ (vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__y 
                          & vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__z));
            }(), vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__Vfuncout));
    vlSelf->sha256_core__DOT__state = ((IData)(vlSelf->rst_n)
                                        ? (IData)(vlSelf->sha256_core__DOT__next_state)
                                        : 0U);
    vlSelf->sha256_core__DOT__f_next = vlSelf->sha256_core__DOT__e;
    vlSelf->sha256_core__DOT__g_next = vlSelf->sha256_core__DOT__f;
    vlSelf->sha256_core__DOT__h_next = vlSelf->sha256_core__DOT__g;
    __Vtableidx1 = vlSelf->sha256_core__DOT__round_ctr;
    vlSelf->sha256_core__DOT__k_val = Vsha256_core__ConstPool__TABLE_hfa1e13c0_0
        [__Vtableidx1];
    vlSelf->hash_out[0U] = vlSelf->sha256_core__DOT__H
        [7U];
    vlSelf->hash_out[1U] = vlSelf->sha256_core__DOT__H
        [6U];
    vlSelf->hash_out[2U] = vlSelf->sha256_core__DOT__H
        [5U];
    vlSelf->hash_out[3U] = vlSelf->sha256_core__DOT__H
        [4U];
    vlSelf->hash_out[4U] = vlSelf->sha256_core__DOT__H
        [3U];
    vlSelf->hash_out[5U] = vlSelf->sha256_core__DOT__H
        [2U];
    vlSelf->hash_out[6U] = (IData)((((QData)((IData)(
                                                     vlSelf->sha256_core__DOT__H
                                                     [0U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->sha256_core__DOT__H
                                                                 [1U]))));
    vlSelf->hash_out[7U] = (IData)(((((QData)((IData)(
                                                      vlSelf->sha256_core__DOT__H
                                                      [0U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->sha256_core__DOT__H
                                                                  [1U]))) 
                                    >> 0x20U));
    vlSelf->sha256_core__DOT__w_next = (((([&]() {
                        vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__x 
                            = vlSelf->sha256_core__DOT__w
                            [0xeU];
                        vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__Vfuncout 
                            = ((([&]() {
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__x 
                                            = vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__x;
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__x, 0x11U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__x, 0xfU));
                                    }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__Vfuncout) 
                                ^ ([&]() {
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__x 
                                            = vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__x;
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__x, 0x13U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__x, 0xdU));
                                    }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__Vfuncout)) 
                               ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__x, 0xaU));
                    }(), vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__Vfuncout) 
                                          + vlSelf->sha256_core__DOT__w
                                          [9U]) + ([&]() {
                    vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__x 
                        = vlSelf->sha256_core__DOT__w
                        [1U];
                    vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__Vfuncout 
                        = ((([&]() {
                                    vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__x 
                                        = vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__x;
                                    vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__Vfuncout 
                                        = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__x, 7U) 
                                           | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__x, 0x19U));
                                }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__Vfuncout) 
                            ^ ([&]() {
                                    vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__x 
                                        = vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__x;
                                    vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__Vfuncout 
                                        = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__x, 0x12U) 
                                           | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__x, 0xeU));
                                }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__Vfuncout)) 
                           ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__x, 3U));
                }(), vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__Vfuncout)) 
                                        + vlSelf->sha256_core__DOT__w
                                        [0U]);
    vlSelf->sha256_core__DOT__w_val = ((0x10U > (IData)(vlSelf->sha256_core__DOT__round_ctr))
                                        ? vlSelf->sha256_core__DOT__w
                                       [(0xfU & (IData)(vlSelf->sha256_core__DOT__round_ctr))]
                                        : vlSelf->sha256_core__DOT__w_next);
    vlSelf->ready = 0U;
    vlSelf->sha256_core__DOT__round_ctr_en = 0U;
    if ((0U != (IData)(vlSelf->sha256_core__DOT__state))) {
        if ((1U == (IData)(vlSelf->sha256_core__DOT__state))) {
            vlSelf->sha256_core__DOT__round_ctr_en = 1U;
        }
    }
    vlSelf->sha256_core__DOT__round_ctr_rst = 0U;
    vlSelf->sha256_core__DOT__next_state = vlSelf->sha256_core__DOT__state;
    if ((0U == (IData)(vlSelf->sha256_core__DOT__state))) {
        vlSelf->ready = 1U;
        if (vlSelf->next_block) {
            vlSelf->sha256_core__DOT__round_ctr_rst = 1U;
            vlSelf->sha256_core__DOT__next_state = 1U;
        }
    } else {
        if ((1U != (IData)(vlSelf->sha256_core__DOT__state))) {
            if ((2U == (IData)(vlSelf->sha256_core__DOT__state))) {
                if (vlSelf->next_block) {
                    vlSelf->sha256_core__DOT__round_ctr_rst = 1U;
                }
            }
        }
        if ((1U == (IData)(vlSelf->sha256_core__DOT__state))) {
            if ((0x3fU == (IData)(vlSelf->sha256_core__DOT__round_ctr))) {
                vlSelf->sha256_core__DOT__next_state = 2U;
            }
        } else {
            vlSelf->sha256_core__DOT__next_state = 
                ((2U == (IData)(vlSelf->sha256_core__DOT__state))
                  ? ((IData)(vlSelf->next_block) ? 1U
                      : 0U) : 0U);
        }
    }
    vlSelf->sha256_core__DOT__temp1 = ((((vlSelf->sha256_core__DOT__h 
                                          + ([&]() {
                            vlSelf->__Vfunc_sha256_core__DOT__EP1__6__x 
                                = vlSelf->sha256_core__DOT__e;
                            vlSelf->__Vfunc_sha256_core__DOT__EP1__6__Vfuncout 
                                = ((([&]() {
                                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__x 
                                                = vlSelf->__Vfunc_sha256_core__DOT__EP1__6__x;
                                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__x, 6U) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__x, 0x1aU));
                                        }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__Vfuncout) 
                                    ^ ([&]() {
                                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__x 
                                                = vlSelf->__Vfunc_sha256_core__DOT__EP1__6__x;
                                            vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__Vfuncout 
                                                = (
                                                   VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__x, 0xbU) 
                                                   | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__x, 0x15U));
                                        }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__Vfuncout)) 
                                   ^ ([&]() {
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__x 
                                            = vlSelf->__Vfunc_sha256_core__DOT__EP1__6__x;
                                        vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__Vfuncout 
                                            = (VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__x, 0x19U) 
                                               | VL_SHIFTL_III(32,32,32, vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__x, 7U));
                                    }(), vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__Vfuncout));
                        }(), vlSelf->__Vfunc_sha256_core__DOT__EP1__6__Vfuncout)) 
                                         + ([&]() {
                        vlSelf->__Vfunc_sha256_core__DOT__CH__10__z 
                            = vlSelf->sha256_core__DOT__g;
                        vlSelf->__Vfunc_sha256_core__DOT__CH__10__y 
                            = vlSelf->sha256_core__DOT__f;
                        vlSelf->__Vfunc_sha256_core__DOT__CH__10__x 
                            = vlSelf->sha256_core__DOT__e;
                        vlSelf->__Vfunc_sha256_core__DOT__CH__10__Vfuncout 
                            = ((vlSelf->__Vfunc_sha256_core__DOT__CH__10__x 
                                & vlSelf->__Vfunc_sha256_core__DOT__CH__10__y) 
                               ^ ((~ vlSelf->__Vfunc_sha256_core__DOT__CH__10__x) 
                                  & vlSelf->__Vfunc_sha256_core__DOT__CH__10__z));
                    }(), vlSelf->__Vfunc_sha256_core__DOT__CH__10__Vfuncout)) 
                                        + vlSelf->sha256_core__DOT__k_val) 
                                       + vlSelf->sha256_core__DOT__w_val);
    vlSelf->sha256_core__DOT__e_next = (vlSelf->sha256_core__DOT__d 
                                        + vlSelf->sha256_core__DOT__temp1);
}

void Vsha256_core___024root___eval_nba(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsha256_core___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vsha256_core___024root___eval_triggers__act(Vsha256_core___024root* vlSelf);

bool Vsha256_core___024root___eval_phase__act(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsha256_core___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsha256_core___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsha256_core___024root___eval_phase__nba(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsha256_core___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__ico(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__nba(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__act(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vsha256_core___024root___eval(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsha256_core___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("src/sha256_core.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsha256_core___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsha256_core___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("src/sha256_core.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsha256_core___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("src/sha256_core.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsha256_core___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsha256_core___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsha256_core___024root___eval_debug_assertions(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->init & 0xfeU))) {
        Verilated::overWidthError("init");}
    if (VL_UNLIKELY((vlSelf->next_block & 0xfeU))) {
        Verilated::overWidthError("next_block");}
}
#endif  // VL_DEBUG
