
void FUN_00638930(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f6df;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CTalkBoxNpc::vftable;
  local_8 = 1;
  FUN_0085e680(*(undefined4 *)in_ECX[0x33],(undefined4 *)in_ECX[0x33]);
  FUN_0089120c(in_ECX[0x33],uVar1);
  local_8 = 2;
  FUN_005540c0(*(undefined4 *)in_ECX[0x2d],(undefined4 *)in_ECX[0x2d]);
  FUN_0089120c(in_ECX[0x2d]);
  ExceptionList = local_10;
  return;
}

