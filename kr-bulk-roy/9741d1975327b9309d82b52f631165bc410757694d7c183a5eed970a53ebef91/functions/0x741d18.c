
undefined * Catch_All_00741d18(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + 0xc) = iVar1;
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_0044b7d0(iVar1 + 1);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  return &DAT_00741d3b;
}

