
undefined4 * FUN_006c8bc0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090f541;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 10) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[6] = 7;
      param_2[5] = 0;
      *(undefined2 *)(param_2 + 1) = 0;
      FUN_004026e0(in_ECX + 1,0,0xffffffff);
      *(undefined1 *)(param_2 + 8) = *(undefined1 *)(in_ECX + 8);
      param_2[9] = in_ECX[9];
    }
    param_2 = param_2 + 10;
  }
  ExceptionList = local_10;
  return param_2;
}

