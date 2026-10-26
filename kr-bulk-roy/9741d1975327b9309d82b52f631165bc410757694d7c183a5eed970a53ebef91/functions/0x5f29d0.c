
void FUN_005f29d0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ab80;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar2;
  FUN_005e2160(local_30);
  local_38 = 7;
  local_3c = 0;
  local_4c = (uint)local_4c._2_2_ << 0x10;
  FUN_004026e0(local_30,0,0xffffffff);
  iVar1 = *(int *)(in_ECX + 0x194);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_007578f0(uVar2);
  FUN_00759ed0(iVar1 + 0xe8,&local_4c,0x7b,0x7d);
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x194) + 0x154) = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

