
undefined1 * FUN_0082b9e0(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090e7b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x24) {
    local_8 = 1;
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = *in_ECX;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(in_ECX + 4);
      *(undefined4 *)(param_2 + 0x1c) = 7;
      *(undefined4 *)(param_2 + 0x18) = 0;
      *(undefined2 *)(param_2 + 8) = 0;
      FUN_004026e0(in_ECX + 8,0,0xffffffff);
    }
    param_2 = param_2 + 0x24;
  }
  ExceptionList = local_10;
  return param_2;
}

