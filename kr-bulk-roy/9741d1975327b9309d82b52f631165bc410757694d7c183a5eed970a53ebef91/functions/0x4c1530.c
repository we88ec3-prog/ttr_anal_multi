
void FUN_004c1530(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b550;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)in_ECX[0x2f60],(undefined4 *)in_ECX[0x2f60]);
  FUN_0089120c(in_ECX[0x2f60],uVar1);
  *in_ECX = CPacketProcessor::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

