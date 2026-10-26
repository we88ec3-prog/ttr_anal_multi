
undefined4 * FUN_00450280(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917808;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0xa8,in_ECX[-1],FUN_00489220);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1);
    }
    ExceptionList = local_10;
    return in_ECX + -1;
  }
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 0;
  FUN_00744370(uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return in_ECX;
}

