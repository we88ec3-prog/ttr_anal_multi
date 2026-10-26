
void FUN_004347b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CEternalTowerDescData::vftable;
  in_ECX[1] = CEternalTowerDescData::vftable;
  if (in_ECX[0x17] != 0) {
    FUN_0089120c(in_ECX[0x17]);
  }
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CEternalTowerDescData>::vftable;
  DAT_00fb7618 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

