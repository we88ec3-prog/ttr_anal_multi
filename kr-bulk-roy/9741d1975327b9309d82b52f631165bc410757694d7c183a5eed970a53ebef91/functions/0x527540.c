
void FUN_00527540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CNPCTable>::vftable;
  DAT_00fe1bd0 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

