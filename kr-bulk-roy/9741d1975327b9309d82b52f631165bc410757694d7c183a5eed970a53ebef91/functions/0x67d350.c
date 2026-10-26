
void FUN_0067d350(void)

{
  int unaff_EDI;
  
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x198) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0x198) + 0xd8))(0x3f800000);
                    /* WARNING: Could not recover jumptable at 0x0067d399. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x198) + 200))();
  return;
}

