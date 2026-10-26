
void FUN_005ceab0(void)

{
  int in_ECX;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094382e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005ccd30(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  FUN_005cd210();
  FUN_005cd520(in_ECX);
  FUN_005cd3c0(in_ECX);
  FUN_005ce430(in_ECX);
  FUN_005ce6f0(in_ECX);
  *(undefined4 *)(*(int *)(in_ECX + 0x348) + 0xdc) = 1;
  FUN_0068b260(*(undefined4 *)(in_ECX + 0x348));
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_c = 0;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_c = 0xffffffff;
  }
  (**(code **)(**(int **)(in_ECX + 0x104) + 0x90))
            ((DAT_00fab104 & 0x20) != 0 || DAT_00fab128 != '\0');
  ExceptionList = pvStack_18;
  return;
}

