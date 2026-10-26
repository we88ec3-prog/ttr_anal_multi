
undefined4 * FUN_004fced0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0091067c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0xf) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[1] = in_ECX[1];
      param_2[2] = in_ECX[2];
      param_2[3] = in_ECX[3];
      param_2[9] = 7;
      param_2[8] = 0;
      *(undefined2 *)(param_2 + 4) = 0;
      FUN_004026e0(in_ECX + 4,0,0xffffffff);
      local_8 = 2;
      FUN_004fcd00(param_2 + 0xb,in_ECX + 0xb);
    }
    param_2 = param_2 + 0xf;
  }
  ExceptionList = local_10;
  return param_2;
}

