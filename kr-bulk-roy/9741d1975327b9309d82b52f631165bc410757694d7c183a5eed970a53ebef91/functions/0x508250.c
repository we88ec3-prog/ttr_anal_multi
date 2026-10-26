
void FUN_00508250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CScenarioDescData::vftable;
  in_ECX[1] = CScenarioDescData::vftable;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CScenarioDescData>::vftable;
  DAT_00fe18f8 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

