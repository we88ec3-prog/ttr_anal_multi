
undefined4 * FUN_005284c0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090b10c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 9) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      FUN_004fcd00(param_2 + 1,in_ECX + 1);
      local_8 = 2;
      FUN_007e8a90(param_2 + 5,in_ECX + 5);
    }
    param_2 = param_2 + 9;
  }
  ExceptionList = local_10;
  return param_2;
}

