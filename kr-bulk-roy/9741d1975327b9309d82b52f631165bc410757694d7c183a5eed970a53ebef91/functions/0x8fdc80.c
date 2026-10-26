
void FUN_008fdc80(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x38))(0x100,0x100);
  if (iVar1 != 0) {
    FUN_00571b20(0);
                    /* WARNING: Could not recover jumptable at 0x008fdcac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x3c))();
    return;
  }
  return;
}

