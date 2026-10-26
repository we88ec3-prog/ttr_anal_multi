
undefined4 * FUN_007b2f00(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00914fac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x10) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[1] = in_ECX[1];
      param_2[2] = in_ECX[2];
      param_2[3] = in_ECX[3];
      param_2[4] = in_ECX[4];
      param_2[10] = 0xf;
      param_2[9] = 0;
      *(undefined1 *)(param_2 + 5) = 0;
      FUN_00403040(in_ECX + 5,0,0xffffffff);
      local_8 = 2;
      FUN_0062d9b0(in_ECX + 0xc);
    }
    param_2 = param_2 + 0x10;
  }
  ExceptionList = local_10;
  return param_2;
}

