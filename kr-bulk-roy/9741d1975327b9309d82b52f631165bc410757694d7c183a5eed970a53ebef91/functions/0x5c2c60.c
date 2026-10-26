
void FUN_005c2c60(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009472de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005b87b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb7258 == 0) {
    if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x2f8) + 0xd4))();
    }
  }
  else if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) == 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0xd0))();
  }
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
  }
  ExceptionList = local_10;
  return;
}

