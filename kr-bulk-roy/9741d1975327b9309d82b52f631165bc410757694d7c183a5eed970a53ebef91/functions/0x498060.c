
void FUN_00498060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CClient>::vftable;
  DAT_00fb1318 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

