
void FUN_005cabd0(void)

{
  HIMC pHVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  pHVar1 = ImmGetContext(*(HWND *)(in_ECX + 0x18));
  if (pHVar1 != (HIMC)0x0) {
    ImmNotifyIME(pHVar1,0x15,4,0);
    ImmNotifyIME(pHVar1,0x11,0,0);
    ImmReleaseContext(*(HWND *)(in_ECX + 0x18),pHVar1);
  }
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005cac1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))();
    return;
  }
  return;
}

