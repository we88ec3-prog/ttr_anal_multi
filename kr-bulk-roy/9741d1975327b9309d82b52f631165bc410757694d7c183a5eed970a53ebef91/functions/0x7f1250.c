
void FUN_007f1250(void)

{
  int in_ECX;
  undefined4 ****ppppuVar1;
  undefined4 ***local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928496;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00543500(local_30,in_ECX + 0x40,in_ECX + 0x5c,local_14);
  local_8 = 0;
  ppppuVar1 = (undefined4 ****)local_30[0];
  if (local_1c < 0x10) {
    ppppuVar1 = local_30;
  }
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  FUN_007ce0a0(&DAT_00fe3250,ppppuVar1);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

