
void FUN_00454200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CInfiniteDungeonDescData::vftable;
  in_ECX[1] = CInfiniteDungeonDescData::vftable;
  if (in_ECX[0x13] != 0) {
    FUN_0089120c(in_ECX[0x13]);
  }
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CInfiniteDungeonDescData>::vftable;
  DAT_00fc0c68 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

