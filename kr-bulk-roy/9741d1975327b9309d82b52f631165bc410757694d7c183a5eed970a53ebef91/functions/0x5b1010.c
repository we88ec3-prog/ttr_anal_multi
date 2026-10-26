
void FUN_005b1010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

