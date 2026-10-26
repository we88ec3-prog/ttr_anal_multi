
void FUN_0045b330(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0xd8))(0x3f800000);
                    /* WARNING: Could not recover jumptable at 0x0045b379. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  return;
}

