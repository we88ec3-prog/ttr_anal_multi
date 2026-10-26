
undefined1 * FUN_007c5670(undefined1 *param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916db9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  local_8 = 0;
  FUN_00401ed0(in_ECX + 4,0,0xffffffff);
  if (*(char *)(in_ECX + 0xf4) == '\0') {
    FUN_00401fc0("Avatar/",7);
    FUN_00401ed0(in_ECX + 0x20,0,0xffffffff);
  }
  ExceptionList = local_10;
  return param_1;
}

