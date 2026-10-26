
void FUN_005074b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CGameServerState::vftable;
  in_ECX[1] = CGameServerState::vftable;
  FUN_004c4240();
  FUN_0089120c(in_ECX[2]);
  in_ECX[2] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CGameServerState>::vftable;
  DAT_00fe1b54 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

