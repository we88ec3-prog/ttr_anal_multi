
undefined4 * FUN_005c7f20(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090f8a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[6] = 7;
      param_3[5] = 0;
      *(undefined2 *)(param_3 + 1) = 0;
      FUN_004026e0(param_1 + 1,0,0xffffffff);
    }
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}

