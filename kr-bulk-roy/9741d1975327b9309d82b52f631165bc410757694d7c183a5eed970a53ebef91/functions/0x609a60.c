
void FUN_00609a60(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x160) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0x160) + 0xd8))(0x3f800000);
                    /* WARNING: Could not recover jumptable at 0x00609aa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x160) + 200))();
  return;
}

