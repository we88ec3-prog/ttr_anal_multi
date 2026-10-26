
void FUN_00435c40(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0xf8) + 0xcc);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) {
    FUN_00435a00(unaff_ESI,*(undefined4 *)(iVar1 + 0x20));
    FUN_00435a90(unaff_ESI);
    return;
  }
  FUN_00435a00(unaff_ESI,0xffffffff);
  FUN_00435a90(unaff_ESI);
  return;
}

