
void FUN_0064ff10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIArchive::vftable;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

