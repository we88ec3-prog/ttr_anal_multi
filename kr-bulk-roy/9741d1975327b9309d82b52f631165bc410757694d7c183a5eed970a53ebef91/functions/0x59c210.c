
void FUN_0059c210(void)

{
  int *piVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094751e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcce20);
  }
  local_8 = 0xffffffff;
  if (((DAT_00fab104 & 0x20) != 0) || (DAT_00fab128 != '\0')) {
    piVar1 = *(int **)(unaff_ESI + 0x18c);
    if (((uint)piVar1[10] >> 8 & 1) == 0) {
      FUN_00596e00(unaff_ESI,piVar1);
    }
    else if (((uint)piVar1[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar1 + 0xd4))();
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

