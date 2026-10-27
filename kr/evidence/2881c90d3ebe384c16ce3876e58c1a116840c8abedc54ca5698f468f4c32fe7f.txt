
void FUN_006bc7b0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x90) + 0xcc);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) {
    FUN_006bc1a0(unaff_ESI,*(undefined4 *)(iVar1 + 0x20),0);
    FUN_006bc330(unaff_ESI);
    return;
  }
  FUN_006bc1a0(unaff_ESI,0xffffffff,0);
  FUN_006bc330(unaff_ESI);
  return;
}

