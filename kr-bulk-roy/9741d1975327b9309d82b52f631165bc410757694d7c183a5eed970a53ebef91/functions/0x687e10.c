
void FUN_00687e10(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x148) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0x148) + 0xd8))(0x3f800000);
                    /* WARNING: Could not recover jumptable at 0x00687e59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x148) + 200))();
  return;
}

