
undefined4 * FUN_00743f60(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c96e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x2f4,in_ECX[-1],FUN_00778500);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1,uVar1);
    }
    ExceptionList = local_10;
    return in_ECX + -1;
  }
  *in_ECX = FoxUI::FXUIBackground9::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x93,0x10,9,FUN_005f5d10);
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(in_ECX + 3,0x40,9,FUN_00776700);
  *in_ECX = FoxUI::FXUIArchive::vftable;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return in_ECX;
}

