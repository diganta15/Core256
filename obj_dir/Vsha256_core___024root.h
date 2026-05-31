// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsha256_core.h for the primary calling header

#ifndef VERILATED_VSHA256_CORE___024ROOT_H_
#define VERILATED_VSHA256_CORE___024ROOT_H_  // guard

#include "verilated.h"


class Vsha256_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsha256_core___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(init,0,0);
        VL_IN8(next_block,0,0);
        VL_OUT8(ready,0,0);
        VL_OUT8(hash_valid,0,0);
        CData/*1:0*/ sha256_core__DOT__state;
        CData/*1:0*/ sha256_core__DOT__next_state;
        CData/*5:0*/ sha256_core__DOT__round_ctr;
        CData/*0:0*/ sha256_core__DOT__round_ctr_en;
        CData/*0:0*/ sha256_core__DOT__round_ctr_rst;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_INW(block_in,511,0,16);
        VL_OUTW(hash_out,255,0,8);
        IData/*31:0*/ sha256_core__DOT__k_val;
        IData/*31:0*/ sha256_core__DOT__a;
        IData/*31:0*/ sha256_core__DOT__b;
        IData/*31:0*/ sha256_core__DOT__c;
        IData/*31:0*/ sha256_core__DOT__d;
        IData/*31:0*/ sha256_core__DOT__e;
        IData/*31:0*/ sha256_core__DOT__f;
        IData/*31:0*/ sha256_core__DOT__g;
        IData/*31:0*/ sha256_core__DOT__h;
        IData/*31:0*/ sha256_core__DOT__b_next;
        IData/*31:0*/ sha256_core__DOT__c_next;
        IData/*31:0*/ sha256_core__DOT__d_next;
        IData/*31:0*/ sha256_core__DOT__e_next;
        IData/*31:0*/ sha256_core__DOT__f_next;
        IData/*31:0*/ sha256_core__DOT__g_next;
        IData/*31:0*/ sha256_core__DOT__h_next;
        IData/*31:0*/ sha256_core__DOT__w_next;
        IData/*31:0*/ sha256_core__DOT__temp1;
        IData/*31:0*/ sha256_core__DOT__temp2;
        IData/*31:0*/ sha256_core__DOT__w_val;
        IData/*31:0*/ sha256_core__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ sha256_core__DOT__unnamedblk4__DOT__i;
        IData/*31:0*/ sha256_core__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ sha256_core__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__SIG1__0__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__SIG1__0__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__1__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__1__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__2__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__2__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__SIG0__3__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__SIG0__3__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__4__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__4__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__5__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__5__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__EP1__6__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__EP1__6__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__7__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__7__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__8__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__8__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__9__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__9__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__CH__10__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__CH__10__x;
    };
    struct {
        IData/*31:0*/ __Vfunc_sha256_core__DOT__CH__10__y;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__CH__10__z;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__EP0__11__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__EP0__11__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__12__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__12__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__13__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__13__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__14__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__ROTR__14__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__MAJ__15__Vfuncout;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__MAJ__15__x;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__MAJ__15__y;
        IData/*31:0*/ __Vfunc_sha256_core__DOT__MAJ__15__z;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 8> sha256_core__DOT__H;
        VlUnpacked<IData/*31:0*/, 16> sha256_core__DOT__w;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsha256_core__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsha256_core___024root(Vsha256_core__Syms* symsp, const char* v__name);
    ~Vsha256_core___024root();
    VL_UNCOPYABLE(Vsha256_core___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
