
void FUN_005f7ca0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(in_ECX + 0x100) + 0x94))
            ((DAT_00fab104 & 0x20) != 0 || DAT_00fab128 != '\0');
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  ExceptionList = local_10;
  return;
}

