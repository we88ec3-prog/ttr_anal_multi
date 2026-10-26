
undefined * Catch_All_0040254a(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_0044b7d0(iVar1 + 1);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_0040256d;
}

