
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006f21e0(int param_1,HWND param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  HIMC pHVar3;
  DWORD DVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  undefined1 *puVar10;
  undefined4 auStackY_40 [3];
  undefined1 auStackY_34 [4];
  int iStackY_30;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pcVar9 = ImmGetCompositionStringW_exref;
  if (((param_3 & 8) != 0) &&
     (pHVar3 = ImmGetContext(param_2), pcVar9 = ImmGetCompositionStringW_exref, pHVar3 != (HIMC)0x0)
     ) {
    iStackY_30 = 0x6f2218;
    DVar4 = ImmGetCompositionStringW(pHVar3,8,(LPVOID)0x0,0);
    iStackY_30 = 0x6f222b;
    ImmGetCompositionStringW(pHVar3,8,&stack0xffffffe4,DVar4);
    iStackY_30 = 0x6f2269;
    FUN_006f31c0();
    ImmReleaseContext(param_2,pHVar3);
  }
  if (((param_3 & 0x800) != 0) && (pHVar3 = ImmGetContext(param_2), pHVar3 != (HIMC)0x0)) {
    iStackY_30 = 0x6f22a8;
    DVar4 = (*pcVar9)();
    iStackY_30 = 0x6f22bf;
    ImmGetCompositionStringW(pHVar3,0x800,&stack0xffffffe4,DVar4);
    iStackY_30 = 0x6f22ff;
    FUN_006f31c0();
    ImmReleaseContext(param_2,pHVar3);
    pcVar9 = ImmGetCompositionStringW_exref;
  }
  if ((param_3 & 0x80) != 0) {
    iStackY_30 = 0x6f2322;
    uVar5 = (*pcVar9)();
    *(undefined4 *)(param_1 + 100) = uVar5;
  }
  if (((param_3 & 0x10) != 0) && (pHVar3 = ImmGetContext(param_2), pHVar3 != (HIMC)0x0)) {
    iStackY_30 = 0x6f2348;
    iVar6 = (*pcVar9)();
    iStackY_30 = 0x6f234f;
    iVar1 = -iVar6;
    *(int *)((int)&iStackY_30 + iVar1) = iVar6;
    *(undefined1 **)(auStackY_34 + iVar1) = &stack0xffffffd4 + iVar1;
    *(undefined4 *)((int)auStackY_40 + iVar1 + 8) = 0x10;
    *(HIMC *)((int)auStackY_40 + iVar1 + 4) = pHVar3;
    puVar10 = (undefined1 *)((int)auStackY_40 + iVar1);
    *(undefined4 *)((int)auStackY_40 + iVar1) = 0x6f235b;
    (*pcVar9)();
    iVar7 = 0;
    if (0 < iVar6) {
      do {
        if (((&stack0xffffffd4)[iVar7 + iVar1] == '\x01') ||
           ((&stack0xffffffd4)[iVar7 + iVar1] == '\x03')) break;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
    iVar8 = iVar7;
    if (iVar7 < iVar6) {
      do {
        if ((&stack0xffffffd4)[iVar8 + iVar1] != (&stack0xffffffd4)[iVar7 + iVar1]) break;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
    *(int *)(param_1 + 0x6c) = iVar8;
    *(int *)(param_1 + 0x68) = iVar7;
    *(HIMC *)(puVar10 + -4) = pHVar3;
    *(HWND *)(puVar10 + -8) = param_2;
    *(undefined4 *)(puVar10 + -0xc) = 0x6f23a1;
    ImmReleaseContext(*(HWND *)(puVar10 + -8),*(HIMC *)(puVar10 + -4));
  }
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

