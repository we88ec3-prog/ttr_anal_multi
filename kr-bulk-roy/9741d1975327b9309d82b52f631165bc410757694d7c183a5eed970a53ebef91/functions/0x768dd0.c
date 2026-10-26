
void FUN_00768dd0(void)

{
  int *in_ECX;
  
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x00768df3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x1b0))();
  return;
}

