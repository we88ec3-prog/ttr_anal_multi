
void FUN_00508180(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CRaidDescData::vftable;
  in_ECX[1] = CRaidDescData::vftable;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CRaidDescData>::vftable;
  DAT_00fe1b58 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

