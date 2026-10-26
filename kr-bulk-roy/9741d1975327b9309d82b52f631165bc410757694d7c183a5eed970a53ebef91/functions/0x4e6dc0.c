
void FUN_004e6dc0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009301e6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_00498f60(uVar1);
  local_8 = 0;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  FUN_004d6b30(uVar2);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

