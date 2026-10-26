
void FUN_007d4f50(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))();
                    /* WARNING: Could not recover jumptable at 0x007d4f62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 4))();
  return;
}

