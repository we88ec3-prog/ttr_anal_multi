
undefined4 * FUN_005110a0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00912e8c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0xd) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[1] = in_ECX[1];
      param_2[7] = 7;
      param_2[6] = 0;
      *(undefined2 *)(param_2 + 2) = 0;
      FUN_004026e0(in_ECX + 2,0,0xffffffff);
      local_8 = 2;
      FUN_00510fd0(param_2 + 9,in_ECX + 9);
    }
    param_2 = param_2 + 0xd;
  }
  ExceptionList = local_10;
  return param_2;
}

