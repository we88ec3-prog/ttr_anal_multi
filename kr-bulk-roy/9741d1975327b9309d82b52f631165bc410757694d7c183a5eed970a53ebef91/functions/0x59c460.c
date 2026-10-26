
void FUN_0059c460(void)

{
  int *piVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fc0bd8 != 0) {
    piVar1 = *(int **)(unaff_ESI + 0x1b4);
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

