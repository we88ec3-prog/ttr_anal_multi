
void FUN_0040c560(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 0xd8))(0x3f800000);
                    /* WARNING: Could not recover jumptable at 0x0040c5a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 200))();
  return;
}

