
void FUN_004e3160(int param_1)

{
  undefined4 uVar1;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_00930356;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 4) == 1) {
    uVar1 = FUN_00409560(param_1,local_14);
    FUN_004dca20(uVar1,param_1);
  }
  else {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    FUN_00402160(L"Error: CustomItem Version does not match.",0x29);
    local_8 = 0;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    FUN_004d6b30(local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

