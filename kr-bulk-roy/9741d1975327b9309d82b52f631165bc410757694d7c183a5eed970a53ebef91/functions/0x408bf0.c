
undefined4 FUN_00408bf0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xb8) == *(int *)(unaff_ESI + 0xbc)) {
                    /* WARNING: Could not recover jumptable at 0x00408c09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(unaff_ESI + 0xa4) + 0x28))();
    return uVar1;
  }
  uVar1 = *(undefined4 *)(*(int *)(unaff_ESI + 0xbc) + -4);
  (**(code **)(**(int **)(unaff_ESI + 0xa4) + 0x2c))(uVar1);
  if (*(int *)(unaff_ESI + 0xb8) != *(int *)(unaff_ESI + 0xbc)) {
    *(int *)(unaff_ESI + 0xbc) = *(int *)(unaff_ESI + 0xbc) + -4;
  }
  return uVar1;
}

