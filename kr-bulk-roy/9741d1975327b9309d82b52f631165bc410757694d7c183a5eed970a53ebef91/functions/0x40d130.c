
void FUN_0040d130(void)

{
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00945a6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005ceab0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0040d8e0(in_ECX[0xe0]);
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = 0xffffffff;
  }
  (**(code **)(*in_ECX + 0x19c))();
  ExceptionList = local_10;
  return;
}

