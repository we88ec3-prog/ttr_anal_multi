
void FUN_00422930(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

