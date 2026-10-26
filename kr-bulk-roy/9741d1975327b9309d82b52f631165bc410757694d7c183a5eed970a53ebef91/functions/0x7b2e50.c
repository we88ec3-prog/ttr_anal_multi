
undefined4 * FUN_007b2e50(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00914fe1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 8) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      param_2[6] = 0xf;
      param_2[5] = 0;
      *(undefined1 *)(param_2 + 1) = 0;
      FUN_00403040(in_ECX + 1,0,0xffffffff);
    }
    param_2 = param_2 + 8;
  }
  ExceptionList = local_10;
  return param_2;
}

