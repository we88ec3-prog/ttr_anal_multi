
byte FUN_0051bf00(int param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910333;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  param_1 = *(undefined4 *)(param_1 + 0x20);
  FUN_008438c0(&param_1);
  if ((in_ECX != DAT_00f8d9b0) && (*(int *)(in_ECX + 0x10) != 0)) {
    ExceptionList = local_10;
    return *(byte *)(*(int *)(in_ECX + 0x10) + 0xec) & 1;
  }
  ExceptionList = local_10;
  return 0;
}

