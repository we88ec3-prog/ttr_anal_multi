
void FUN_00418d10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CCashShopService::vftable;
  if (in_ECX[0x30] != 0) {
    FUN_0089120c(in_ECX[0x30]);
  }
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

