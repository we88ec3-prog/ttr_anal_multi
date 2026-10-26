
undefined1 * FUN_0043feb0(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00910e01;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    local_8 = 1;
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = *param_1;
      *(undefined4 *)(param_3 + 0x18) = 7;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined2 *)(param_3 + 4) = 0;
      FUN_004026e0(param_1 + 4,0,0xffffffff);
    }
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}

