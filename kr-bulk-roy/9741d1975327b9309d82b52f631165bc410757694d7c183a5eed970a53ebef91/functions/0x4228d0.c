
void FUN_004228d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CDailyDungeonDescData>::vftable;
  DAT_00fb7348 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

