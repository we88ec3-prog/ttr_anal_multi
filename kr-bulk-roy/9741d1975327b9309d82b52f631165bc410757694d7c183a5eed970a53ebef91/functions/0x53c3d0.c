
void FUN_0053c3d0(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090afbf;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CUnionPartyMgr::vftable;
  local_8 = 1;
  FUN_0044e720(in_ECX + 0x17ab,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[0x17ac],(undefined4 *)in_ECX[0x17ac]);
  FUN_0089120c(in_ECX[0x17ac]);
  *in_ECX = CPacketProcessor::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

