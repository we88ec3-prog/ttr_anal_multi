
void FUN_00470a40(void)

{
  int iVar1;
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0xfc) + 0xcc);
  if (iVar1 != 0) {
    FUN_006438f0(iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x00470ab2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  return;
}

