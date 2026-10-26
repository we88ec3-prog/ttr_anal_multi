
void FUN_00508b10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CSquareUserData>::vftable;
  DAT_00fe1aa0 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

