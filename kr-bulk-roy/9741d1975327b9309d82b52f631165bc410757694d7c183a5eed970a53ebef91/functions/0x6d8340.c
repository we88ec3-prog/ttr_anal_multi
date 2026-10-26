
void FUN_006d8340(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 ***pppuVar3;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009215f6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  local_14 = uVar1;
  FUN_00402160(param_3,param_4);
  pppuVar3 = (undefined4 ***)local_30[0];
  if (local_1c < 8) {
    pppuVar3 = local_30;
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 1;
    FUN_00734ef0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  uVar2 = (**(code **)(*DAT_00fb7b78 + 0x44))(*(undefined4 *)(in_ECX + 0xc),pppuVar3,param_2);
  *param_1 = uVar2;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

