
void FUN_00454260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CInfiniteDungeonDescData>::vftable;
  DAT_00fc0c68 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

