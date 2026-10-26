
undefined2 * FUN_0056c570(undefined2 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00921ec6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x22) = 0;
  *(undefined4 *)(param_1 + 0xe) = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0x1e) = 0;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00734ef0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_14);
  *(undefined4 *)(param_1 + 0x20) = *puVar2;
  ExceptionList = local_10;
  return param_1;
}

