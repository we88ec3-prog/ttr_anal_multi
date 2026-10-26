
void FUN_00482470(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x118) + 0xd8))(0x3f800000);
  (**(code **)(**(int **)(unaff_EDI + 0x118) + 0x94))(1);
                    /* WARNING: Could not recover jumptable at 0x004824b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x118) + 200))();
  return;
}

