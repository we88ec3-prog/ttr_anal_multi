
void FUN_00624da0(void)

{
  int *piVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090aaf6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb92f1 == '\0') {
    piVar1 = *(int **)(unaff_ESI + 0xf8);
  }
  else {
    piVar1 = *(int **)(unaff_ESI + 0xf4);
  }
  (**(code **)(*piVar1 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb92fd == '\0') {
    piVar1 = *(int **)(unaff_ESI + 0x100);
  }
  else {
    piVar1 = *(int **)(unaff_ESI + 0xfc);
  }
  (**(code **)(*piVar1 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 2;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(unaff_ESI + 0x10c + (uint)(DAT_00fb9341 == '\0') * 4) + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 3;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(unaff_ESI + 0xec) + 0xa0))(DAT_00fb9111 != '\0');
  (**(code **)(**(int **)(unaff_ESI + 0xec) + 200))();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 4;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(unaff_ESI + 0x114 + (uint)(DAT_00fb934d == '\0') * 4) + 0xa0))(1);
  ExceptionList = local_10;
  return;
}

