
void FUN_00510d20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CBuffExplainTable>::vftable;
  DAT_00fc0c6c = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

