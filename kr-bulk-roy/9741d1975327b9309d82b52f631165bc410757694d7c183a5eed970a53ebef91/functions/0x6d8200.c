
undefined4 FUN_006d8200(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092165e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 0;
    FUN_00734ef0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  local_8 = 0xffffffff;
  (**(code **)(*DAT_00fb7b78 + 0x4c))(param_1,*(undefined4 *)(in_ECX + 0xc),param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}

