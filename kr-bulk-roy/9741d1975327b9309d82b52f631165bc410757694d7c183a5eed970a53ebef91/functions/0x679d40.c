
void FUN_00679d40(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x120) + 0xd8))(0x3f800000);
  (**(code **)(**(int **)(unaff_EDI + 0x120) + 0x94))(1);
                    /* WARNING: Could not recover jumptable at 0x00679d89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x120) + 200))();
  return;
}

