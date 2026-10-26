
void FUN_00753c60(byte param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911da8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIEventI2S1::vftable;
  local_8 = 0;
  FUN_00757640(in_ECX + 7);
  *in_ECX = FoxUI::FXUIEvent::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

