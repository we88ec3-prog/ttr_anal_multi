
void FUN_00418bd0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092ab80;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar1;
  FUN_004041f0(*in_ECX,0,0xffffffff);
  if (local_20 < (int)in_ECX[1]) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_8._0_1_ = 1;
    FUN_00402340(in_ECX[1] - local_20,in_ECX[2]);
    FUN_004041f0(local_30,0,0xffffffff);
    FUN_004026e0(local_4c,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0],uVar1);
    }
  }
  FUN_004041f0(local_30,0,0xffffffff);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

