
void FUN_006d61a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CPostEffectMgr>::vftable;
  DAT_00fe2770 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

