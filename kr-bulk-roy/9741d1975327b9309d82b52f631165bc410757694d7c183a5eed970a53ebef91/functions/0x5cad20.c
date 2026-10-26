
void FUN_005cad20(int *param_1)

{
  char cVar1;
  int iVar2;
  HIMC pHVar3;
  int in_ECX;
  bool bVar4;
  
  if (*(int **)(in_ECX + 0x28) == param_1) {
    return;
  }
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))();
  }
  if ((param_1 == (int *)0x0) ||
     ((iVar2 = (**(code **)(*param_1 + 8))(), iVar2 != 500 &&
      (iVar2 = (**(code **)(*param_1 + 8))(), iVar2 != 600)))) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    bVar4 = false;
  }
  else {
    *(int **)(in_ECX + 0x14) = param_1;
    cVar1 = (**(code **)(*param_1 + 0x188))();
    bVar4 = cVar1 == '\0';
  }
  pHVar3 = ImmGetContext(*(HWND *)(in_ECX + 0x18));
  if (pHVar3 != (HIMC)0x0) {
    ImmNotifyIME(pHVar3,0x15,4,0);
    ImmNotifyIME(pHVar3,0x11,0,0);
    ImmReleaseContext(*(HWND *)(in_ECX + 0x18),pHVar3);
  }
  if (bVar4) {
    if (pHVar3 == (HIMC)0x0) {
      if (*(HIMC *)(in_ECX + 0x34) == (HIMC)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_006edc70(&DAT_00c1ffdc);
      }
      ImmAssociateContext(*(HWND *)(in_ECX + 0x18),*(HIMC *)(in_ECX + 0x34));
      *(undefined4 *)(in_ECX + 0x34) = 0;
    }
  }
  else if (*(int *)(in_ECX + 0x34) == 0) {
    pHVar3 = ImmAssociateContext(*(HWND *)(in_ECX + 0x18),(HIMC)0x0);
    *(HIMC *)(in_ECX + 0x34) = pHVar3;
    if (pHVar3 == (HIMC)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_006edc70(&DAT_00c1ffe0);
    }
  }
  else if (pHVar3 != (HIMC)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_006edc70(&DAT_00c1ffe4);
  }
  *(int **)(in_ECX + 0x28) = param_1;
  return;
}

