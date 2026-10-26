
void FUN_0073cd90(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00911ec5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CFontDriver_FreeType::vftable;
  local_8 = 1;
  FUN_0073f6f0(in_ECX + 0xe);
  FUN_0073ea80(in_ECX + 4);
  FUN_008bdb30(in_ECX[3],uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_0073d0e0(in_ECX + 3);
  *in_ECX = CFontDriver::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

