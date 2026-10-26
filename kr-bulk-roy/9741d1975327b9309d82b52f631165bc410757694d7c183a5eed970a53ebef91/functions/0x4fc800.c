
void FUN_004fc800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CShopMgr>::vftable;
  DAT_00fe1db4 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

