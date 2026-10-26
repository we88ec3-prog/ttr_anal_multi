
undefined4 * FUN_0046f740(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0091791c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x10) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[6] = 0xf;
      param_2[5] = 0;
      *(undefined1 *)(param_2 + 1) = 0;
      FUN_00403040(in_ECX + 1,0,0xffffffff);
      local_8 = 2;
      param_2[0xd] = 0xf;
      param_2[0xc] = 0;
      *(undefined1 *)(param_2 + 8) = 0;
      FUN_00403040(in_ECX + 8,0,0xffffffff);
      param_2[0xf] = in_ECX[0xf];
    }
    param_2 = param_2 + 0x10;
  }
  ExceptionList = local_10;
  return param_2;
}

