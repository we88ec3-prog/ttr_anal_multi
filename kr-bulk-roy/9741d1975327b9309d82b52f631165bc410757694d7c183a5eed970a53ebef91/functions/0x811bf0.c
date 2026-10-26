
undefined1 * FUN_00811bf0(int param_1,undefined1 *param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00920579;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x3c) {
    local_8 = 1;
    if (param_2 != (undefined1 *)0x0) {
      *(undefined4 *)(param_2 + 0x14) = 0xf;
      *(undefined4 *)(param_2 + 0x10) = 0;
      *param_2 = 0;
      FUN_00403040(in_ECX,0,0xffffffff);
      local_8 = 2;
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
      *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(in_ECX + 0x20);
      *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
      FUN_00555af0(param_2 + 0x28,in_ECX + 0x28);
      param_2[0x38] = *(undefined1 *)(in_ECX + 0x38);
    }
    param_2 = param_2 + 0x3c;
  }
  ExceptionList = local_10;
  return param_2;
}

