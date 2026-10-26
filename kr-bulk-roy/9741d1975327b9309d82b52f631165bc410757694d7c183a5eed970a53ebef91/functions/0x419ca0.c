
undefined4 * FUN_00419ca0(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091be48;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x248,in_ECX[-1],FUN_00691ac0);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1);
    }
    ExceptionList = local_10;
    return in_ECX + -1;
  }
  in_ECX[0xf] = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  local_8 = 0;
  FUN_0077b5f0(in_ECX + 0x57);
  local_8 = 0xffffffff;
  FUN_00754980(uVar1);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return in_ECX;
}

