
void FUN_006b4f80(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c14a;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar9 = (int *)(param_1 + 0x19c);
  do {
    if ((int)*(char *)(param_1 + 0x1d8 + local_14) - 1U < 9) {
      if (((*(char *)(*piVar9 + 0xa4) != '\0') &&
          (piVar2 = *(int **)(*piVar9 + 0x94), piVar2 != (int *)0x0)) &&
         (iVar7 = (**(code **)(*piVar2 + 4))(), iVar7 == 0xbf6b)) {
        FUN_0077b200();
      }
    }
    else {
      iVar7 = *piVar9;
      if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int **)(iVar7 + 0x94) != (int *)0x0)) &&
         (iVar8 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(uVar6), iVar8 == 0xbf6b)) {
        iVar7 = *(int *)(iVar7 + 0x94);
        iVar8 = *(int *)(iVar7 + 0x10);
        if (iVar8 != 0) {
          piVar2 = *(int **)(iVar8 + 8);
          if (piVar2 != (int *)0x0) {
            piVar1 = piVar2 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar2 + 0x28))();
            }
          }
          *(undefined4 *)(iVar7 + 0x10) = 0;
        }
      }
    }
    (**(code **)(*(int *)*piVar9 + 200))();
    local_14 = local_14 + 1;
    piVar9 = piVar9 + 1;
  } while (local_14 < 3);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_14 = 0x232;
  FUN_005740f0(&local_14);
  iVar7 = param_1;
  if (local_18 == DAT_00fe5ac8) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  param_1 = 0x233;
  FUN_005740f0(&param_1);
  if (local_18 == DAT_00fe5ac8) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  param_1 = 0x234;
  FUN_005740f0(&param_1);
  if (local_18 != DAT_00fe5ac8) {
    FUN_00757710();
    piVar9 = *(int **)(iVar7 + 0x18c);
    puVar3 = (undefined4 *)piVar9[0x19];
    for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
      iVar7 = puVar4[2];
      if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
      }
    }
    (**(code **)(*piVar9 + 0x128))();
    ExceptionList = local_10;
    return;
  }
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}

