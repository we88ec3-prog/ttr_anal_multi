
void FUN_00528cc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<COptionGrantTable>::vftable;
  DAT_00fc0e34 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

