
void FUN_006bc7f0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0xbc) + 0xcc);
  if (iVar1 == 0) {
    FUN_006bc2b0();
    FUN_006bc330(unaff_ESI);
    return;
  }
  if (*(int *)(iVar1 + 0xdc) == 0) {
    FUN_006bc2b0();
    FUN_006bc330(unaff_ESI);
    return;
  }
  FUN_006bc2b0();
  FUN_006bc330(unaff_ESI);
  return;
}

