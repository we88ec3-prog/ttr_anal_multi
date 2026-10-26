
void FUN_005a49e0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e2ac;
  local_10 = ExceptionList;
  if (*(char *)(unaff_ESI + 0x134) != '\0') {
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
    piVar2 = *(int **)(unaff_ESI + 0x140);
  }
  else {
    if (DAT_00fb11e8 != 2) goto LAB_005a4a6d;
    piVar2 = *(int **)(unaff_ESI + 0x148);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xd4))();
  }
LAB_005a4a6d:
  if (*(int *)(unaff_ESI + 0x144) != 0) {
    FUN_00641d90(*(int *)(unaff_ESI + 0x144));
    (**(code **)(**(int **)(unaff_ESI + 0x144) + 0xd4))();
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (DAT_00f95be0 == *(int *)(unaff_ESI + 0x144)) {
      iVar1 = FUN_00404aa0();
      *(undefined4 *)(iVar1 + 0x13dc) = 0;
      *(undefined1 *)(iVar1 + 0x13d9) = 1;
    }
  }
  *(undefined1 *)(unaff_ESI + 0x134) = 1;
  ExceptionList = local_10;
  return;
}

