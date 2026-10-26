
void FUN_00507c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSingleton<CGameServerState>::vftable;
  DAT_00fe1b54 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

