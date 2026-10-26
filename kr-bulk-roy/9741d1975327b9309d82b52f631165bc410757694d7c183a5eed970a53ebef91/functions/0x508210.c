
void FUN_00508210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CRaidDescData>::vftable;
  DAT_00fe1b58 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

