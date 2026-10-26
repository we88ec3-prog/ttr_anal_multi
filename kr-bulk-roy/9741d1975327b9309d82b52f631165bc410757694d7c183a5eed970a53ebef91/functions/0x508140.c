
void FUN_00508140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CMissionDescData>::vftable;
  DAT_00fe1aa4 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

