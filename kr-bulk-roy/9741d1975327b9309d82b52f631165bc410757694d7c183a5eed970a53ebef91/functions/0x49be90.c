
undefined2 * FUN_0049be90(int param_1,undefined2 *param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00920071;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x1c) {
    local_8 = 1;
    if (param_2 != (undefined2 *)0x0) {
      *(undefined4 *)(param_2 + 10) = 7;
      *(undefined4 *)(param_2 + 8) = 0;
      *param_2 = 0;
      FUN_00402800(in_ECX);
    }
    param_2 = param_2 + 0xe;
  }
  ExceptionList = local_10;
  return param_2;
}

