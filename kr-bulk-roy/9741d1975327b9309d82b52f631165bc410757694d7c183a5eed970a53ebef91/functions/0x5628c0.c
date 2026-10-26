
void FUN_005628c0(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922f26;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_0046e270(param_1,uVar1);
  local_8 = 0;
  if (7 < (uint)puVar2[5]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  if ((DAT_00fc1c80 & 1) == 0) {
    DAT_00fc1c80 = DAT_00fc1c80 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0056b690();
    _atexit((_func_4879 *)&LAB_00bce500);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  FUN_0056b7f0(&DAT_00fc1c84,puVar2);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

