
void FUN_007db270(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092075e;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 0xd0) != 0) {
    *(undefined4 *)(in_ECX + 0xcc) = param_2;
    return;
  }
  ExceptionList = &local_10;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 0;
    FUN_007b5430(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  local_8 = 0xffffffff;
  FUN_007b67e0(&DAT_00fd9420);
  ExceptionList = local_10;
  return;
}

