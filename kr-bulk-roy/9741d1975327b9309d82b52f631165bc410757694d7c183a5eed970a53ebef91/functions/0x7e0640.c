
undefined4 * FUN_007e0640(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009075f1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 6) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[1] = in_ECX[1];
      FUN_007e8a90(param_2 + 2,in_ECX + 2);
    }
    param_2 = param_2 + 6;
  }
  ExceptionList = local_10;
  return param_2;
}

