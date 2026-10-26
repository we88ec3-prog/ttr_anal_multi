
void FUN_00422870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CDailyDungeonDescData::vftable;
  in_ECX[1] = CDailyDungeonDescData::vftable;
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CDailyDungeonDescData>::vftable;
  DAT_00fb7348 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

