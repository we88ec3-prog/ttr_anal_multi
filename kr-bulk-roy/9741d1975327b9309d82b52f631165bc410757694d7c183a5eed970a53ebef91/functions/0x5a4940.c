
void FUN_005a4940(void)

{
  int *piVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b65e;
  local_10 = ExceptionList;
  if (*(char *)(unaff_ESI + 0x134) == '\0') {
    return;
  }
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb11e8 == 1) {
    piVar1 = *(int **)(unaff_ESI + 0x140);
  }
  else {
    if (DAT_00fb11e8 != 2) goto LAB_005a49c2;
    piVar1 = *(int **)(unaff_ESI + 0x148);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xd0))();
  }
LAB_005a49c2:
  *(undefined1 *)(unaff_ESI + 0x134) = 0;
  ExceptionList = local_10;
  return;
}

