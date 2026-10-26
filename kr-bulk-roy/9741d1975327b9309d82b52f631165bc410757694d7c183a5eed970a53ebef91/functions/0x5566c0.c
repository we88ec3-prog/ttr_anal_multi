
undefined1 * FUN_005566c0(int param_1,int param_2,undefined1 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0091def1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    local_8 = 1;
    if (param_3 != (undefined1 *)0x0) {
      *(undefined4 *)(param_3 + 0x14) = 0xf;
      *(undefined4 *)(param_3 + 0x10) = 0;
      *param_3 = 0;
      FUN_00403040(param_1,0,0xffffffff);
    }
    param_3 = param_3 + 0x1c;
  }
  ExceptionList = local_10;
  return param_3;
}

