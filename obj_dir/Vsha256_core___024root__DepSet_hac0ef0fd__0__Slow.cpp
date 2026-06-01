// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsha256_core.h for the primary calling header

#include "Vsha256_core__pch.h"
#include "Vsha256_core___024root.h"

VL_ATTR_COLD void Vsha256_core___024root___eval_static(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsha256_core___024root___eval_initial(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vsha256_core___024root___eval_final(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__stl(Vsha256_core___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsha256_core___024root___eval_phase__stl(Vsha256_core___024root* vlSelf);

VL_ATTR_COLD void Vsha256_core___024root___eval_settle(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsha256_core___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("src/sha256_core.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsha256_core___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__stl(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<IData/*31:0*/, 64> Vsha256_core__ConstPool__TABLE_hfa1e13c0_0;

VL_ATTR_COLD void Vsha256_core___024root___stl_sequent__TOP__0(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->ready = 0U;
    vlSelf->sha256_core__DOT__round_ctr_en = 0U;
    if ((0U != (IData)(vlSelf->sha256_core__DOT__state))) {
        if ((1U == (IData)(vlSelf->sha256_core__DOT__state))) {
            vlSelf->sha256_core__DOT__round_ctr_en = 1U;
        }
    }
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
    vlSelf->sha256_core__DOT__f_next = vlSelf->sha256_core__DOT__e;
    vlSelf->sha256_core__DOT__g_next = vlSelf->sha256_core__DOT__f;
    vlSelf->sha256_core__DOT__h_next = vlSelf->sha256_core__DOT__g;
    vlSelf->sha256_core__DOT__b_next = vlSelf->sha256_core__DOT__a;
    vlSelf->sha256_core__DOT__c_next = vlSelf->sha256_core__DOT__b;
    vlSelf->sha256_core__DOT__d_next = vlSelf->sha256_core__DOT__c;
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
    __Vtableidx1 = vlSelf->sha256_core__DOT__round_ctr;
    vlSelf->sha256_core__DOT__k_val = Vsha256_core__ConstPool__TABLE_hfa1e13c0_0
        [__Vtableidx1];
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

VL_ATTR_COLD void Vsha256_core___024root___eval_stl(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsha256_core___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vsha256_core___024root___eval_triggers__stl(Vsha256_core___024root* vlSelf);

VL_ATTR_COLD bool Vsha256_core___024root___eval_phase__stl(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsha256_core___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsha256_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__ico(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__act(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsha256_core___024root___dump_triggers__nba(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsha256_core___024root___ctor_var_reset(Vsha256_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsha256_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsha256_core___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->init = VL_RAND_RESET_I(1);
    vlSelf->next_block = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, vlSelf->block_in);
    vlSelf->ready = VL_RAND_RESET_I(1);
    vlSelf->hash_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, vlSelf->hash_out);
    vlSelf->sha256_core__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->sha256_core__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->sha256_core__DOT__round_ctr = VL_RAND_RESET_I(6);
    vlSelf->sha256_core__DOT__round_ctr_en = VL_RAND_RESET_I(1);
    vlSelf->sha256_core__DOT__round_ctr_rst = VL_RAND_RESET_I(1);
    vlSelf->sha256_core__DOT__k_val = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->sha256_core__DOT__H[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sha256_core__DOT__a = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__b = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__c = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__d = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__e = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__f = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__g = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__h = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__b_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__c_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__d_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__e_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__f_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__g_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__h_next = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->sha256_core__DOT__w[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sha256_core__DOT__w_next = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__temp1 = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__temp2 = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__w_val = VL_RAND_RESET_I(32);
    vlSelf->sha256_core__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->sha256_core__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->sha256_core__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->sha256_core__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__SIG1__0__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__1__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__2__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__SIG0__3__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__4__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__5__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__EP1__6__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__EP1__6__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__7__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__8__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__9__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__CH__10__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__CH__10__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__CH__10__y = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__CH__10__z = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__EP0__11__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__EP0__11__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__12__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__13__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__ROTR__14__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__x = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__y = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sha256_core__DOT__MAJ__15__z = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
