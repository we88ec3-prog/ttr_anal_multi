
void FUN_00508480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CScenarioDescData>::vftable;
  DAT_00fe18f8 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

