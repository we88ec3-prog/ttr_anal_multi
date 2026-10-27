
void FUN_005084c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSquareChannelState::vftable;
  in_ECX[1] = CSquareChannelState::vftable;
  if (in_ECX[2] != 0) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[1] = IDataTable::vftable;
  *in_ECX = CSingleton<CSquareChannelState>::vftable;
  DAT_00fe1a88 = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

