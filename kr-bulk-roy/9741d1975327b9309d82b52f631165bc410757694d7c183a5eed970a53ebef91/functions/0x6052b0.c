
void FUN_006052b0(void)

{
  undefined4 uVar1;
  int unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00943318;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar1 = DAT_00f93930;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_004f6a30(uVar1);
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  if ((DAT_00fc1cbc & 1) == 0) {
    DAT_00fc1cbc = DAT_00fc1cbc | 1;
    local_c = 2;
    FUN_004fdac0();
    _atexit(FUN_00bce150);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00fc7ef8;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  FUN_004f6a30(uVar1);
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  ExceptionList = local_14;
  return;
}

