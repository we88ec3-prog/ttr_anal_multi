
void FUN_0068c5b0(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ca4c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar2 = param_1;
  if ((*(byte *)(param_1 + 0x28) & 0x10) == 0) {
    if (*(int *)(param_1 + 0x60) == 0) goto LAB_0068c620;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_0068c620:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00f93930;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  FUN_004f6a30(uVar1);
  iVar2 = *(int *)(param_1 + 0xf4);
  if (*(char *)(iVar2 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar2 + 0x168) = 0;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined4 *)(iVar2 + 0x164) = 0;
  *(undefined4 *)(iVar2 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  FUN_0075cd30(*(undefined4 *)(param_1 + 0xf8));
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  *(undefined1 *)(param_1 + 0x110) = param_2;
  (**(code **)(**(int **)(param_1 + 0xfc) + 0xa0))(1);
  (**(code **)(**(int **)(param_1 + 0x100) + 0xa0))(0);
  ExceptionList = pvStack_1c;
  return;
}

