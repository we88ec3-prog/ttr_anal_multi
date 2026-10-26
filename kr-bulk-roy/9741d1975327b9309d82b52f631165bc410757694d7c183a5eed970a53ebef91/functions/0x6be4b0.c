
void FUN_006be4b0(uint param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar4 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bf1c;
  local_10 = ExceptionList;
  iVar6 = *(int *)(param_1 + 0x248);
  if (iVar6 == -1) {
    iVar6 = *(int *)(param_1 + 0x250);
    if (*(char *)(iVar6 + 0xa4) == '\0') {
      return;
    }
    if (*(int *)(iVar6 + 0x94) == 0) {
      return;
    }
    ExceptionList = &local_10;
    iVar5 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))();
    if (iVar5 != 0xbf6b) {
      ExceptionList = local_10;
      return;
    }
    iVar6 = *(int *)(iVar6 + 0x94);
    iVar5 = *(int *)(iVar6 + 0x10);
    if (iVar5 == 0) {
      ExceptionList = local_10;
      return;
    }
    piVar2 = *(int **)(iVar5 + 8);
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
    *(undefined4 *)(iVar6 + 0x10) = 0;
    ExceptionList = local_10;
    return;
  }
  iVar5 = *(int *)(param_1 + 0x254);
  if (iVar5 == 0) {
    ExceptionList = &local_10;
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = iVar5;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_8 = 0xffffffff;
    uVar3 = *(undefined4 *)(uVar4 + 0x248);
    iVar6 = FUN_005c7190();
    if (iVar6 != 0) {
      local_14 = uVar3;
      FUN_0082ef00(&local_14);
      if (local_18 == *(int *)(iVar6 + 0xc)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(local_18 + 0x10);
      }
      goto LAB_006be640;
    }
  }
  else if (iVar5 == 1) {
    ExceptionList = &local_10;
    iVar6 = FUN_00404ba0();
    param_1 = (uint)*(ushort *)(uVar4 + 0x248);
    iVar6 = *(int *)(iVar6 + 0x6928);
    FUN_004dae30(&param_1);
    if (local_18 == *(int *)(iVar6 + 4)) {
      iVar6 = iVar6 + 0x30;
    }
    else {
      iVar6 = local_18 + 0x10;
    }
    if (iVar6 != 0) {
      FUN_00403470();
      iVar6 = FUN_005c6d70();
LAB_006be640:
      if (iVar6 != 0) goto LAB_006be67e;
    }
  }
  else {
    ExceptionList = &local_10;
    if (iVar5 == 2) {
      FUN_00403470(iVar6,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      iVar6 = FUN_005c7150(iVar6);
      goto LAB_006be640;
    }
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
LAB_006be67e:
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

