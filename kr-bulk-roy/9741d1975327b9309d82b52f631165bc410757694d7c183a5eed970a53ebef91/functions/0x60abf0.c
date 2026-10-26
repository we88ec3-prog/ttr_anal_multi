
void FUN_0060abf0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fa8c;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  uVar1 = DAT_00f94390 & 1;
  *(undefined4 *)(unaff_EDI + 0x110) = param_1;
  if (uVar1 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar3 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iVar3 = FUN_005090e0();
  }
  *(int *)(unaff_EDI + 0x114) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)(unaff_EDI + 0x114) = 0;
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_20 = *(undefined4 *)(unaff_EDI + 0x110);
  FUN_008438c0(&local_20);
  if ((local_1c != DAT_00f8d91c) && (*(int *)(local_1c + 0x10) != 0)) {
    FUN_00757800(*(int *)(local_1c + 0x10));
    FUN_007597b0(0);
    (**(code **)(**(int **)(unaff_EDI + 0x104) + 200))();
  }
  ExceptionList = local_14;
  return;
}

