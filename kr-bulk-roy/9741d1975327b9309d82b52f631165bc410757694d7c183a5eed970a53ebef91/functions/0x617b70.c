
void FUN_00617b70(int param_1,uint param_2)

{
  char cVar1;
  undefined4 *puVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint unaff_EBX;
  uint uVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  undefined4 uStack_a0;
  uint uStack_9c;
  int *local_68;
  undefined1 *local_64;
  uint local_60;
  undefined4 *local_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_2c;
  undefined4 uStack_24;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00943188;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar4 = DAT_00f94390 & 1;
  *(undefined1 *)(param_1 + 0x10c) = (undefined1)param_2;
  if (uVar4 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_64 = (undefined1 *)(param_2 & 0xff);
  uVar4 = DAT_00fab278 & 1;
  *(undefined4 *)(param_1 + 0x110) = 0;
  if (uVar4 == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_c = 1;
    FUN_00817da0();
    _atexit((_func_4879 *)&LAB_00bcced0);
  }
  local_c = 0xffffffff;
  local_60 = param_2 & 0xff;
  uVar4 = (uint)local_68 >> 8;
  local_68 = (int *)((uint)local_68 & 0xffffff00);
  FUN_008195e0();
  puVar11 = local_5c;
  puVar12 = local_64;
  if (local_5c != DAT_00fab280) {
    FUN_008196d0();
    puVar2 = (undefined4 *)puVar11[5];
    puVar5 = local_5c;
    puVar12 = local_64;
    if (puVar2 == local_5c) {
      if (puVar11[6] == 0) goto LAB_00617d54;
      puVar5 = (undefined4 *)*puVar2;
    }
    if (puVar5[4] != 0) {
      local_5c = (undefined4 *)(uint)*(ushort *)(puVar5[4] + 0x18);
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      puVar12 = local_64;
      if ((((-1 < (int)local_64) && ((int)local_64 < 10)) &&
          (iVar6 = (int)local_64 * 0x210 + DAT_00f94304, *(int *)(iVar6 + 0x5c) != 0)) &&
         ((iVar6 != 0 && (iVar6 != -0x1d4)))) {
        local_5c = (undefined4 *)((uint)local_5c & 0xffff);
        FUN_00826280();
        if ((local_60 != *(uint *)(iVar6 + 0x1d8)) &&
           ((*(int *)(local_60 + 0x10) != 0 && (*(short *)(*(int *)(local_60 + 0x10) + 4) != 0)))) {
          *(undefined4 *)(param_1 + 0x110) = 1;
        }
      }
    }
  }
LAB_00617d54:
  iVar6 = FUN_00617880();
  pcVar3 = *(code **)(**(int **)(param_1 + 0xf4) + 0x90);
  if (iVar6 == 0) {
    (*pcVar3)();
    (**(code **)(**(int **)(param_1 + 0xf8) + 0x90))();
  }
  else {
    (*pcVar3)();
    (**(code **)(**(int **)(param_1 + 0xf8) + 0x90))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  if ((((-1 < (int)puVar12) && ((int)puVar12 < 10)) &&
      (iVar6 = (int)puVar12 * 0x210 + DAT_00f94304, *(int *)(iVar6 + 0x5c) != 0)) &&
     ((iVar6 != 0 && ((undefined1 *)(iVar6 + 500) != (undefined1 *)0x0)))) {
    (**(code **)(**(int **)(param_1 + 0x108) + 0x94))();
    if (*(int *)(*(int *)(param_1 + 0x104) + 0xcc) != 0) {
      FUN_00408920();
    }
    uVar10 = 0;
    if (unaff_EBX != 0) {
      do {
        iVar7 = *(int *)(*(int *)(param_1 + 0x104) + 0xcc);
        if (((iVar7 == 0) || ((int)uVar10 < 0)) ||
           (*(int *)(iVar7 + 0xac) - *(int *)(iVar7 + 0xa8) >> 2 <= (int)uVar10)) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(*(int *)(iVar7 + 0xa8) + uVar10 * 4);
        }
        if (iVar7 != 0) {
          uStack_9c = 0x617eb3;
          FUN_00616f40();
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < unaff_EBX);
    }
    FUN_00749920();
    (**(code **)(**(int **)(param_1 + 0x104) + 200))();
    local_68 = (int *)CONCAT31((int3)uVar4,*(undefined1 *)(iVar6 + 500));
    (**(code **)(**(int **)(param_1 + 0xec) + 0x19c))();
    (**(code **)(**(int **)(param_1 + 0xec) + 200))();
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x90))();
    if (*(int *)(param_1 + 0x110) == 0) {
      uVar4 = DAT_00f94394 & 1;
      *(undefined2 *)(*(int *)(param_1 + 0xf0) + 0x248) = 0;
      if (uVar4 == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        uStack_24 = 4;
        FUN_005c3de0();
        uStack_9c = 0x617f84;
        _atexit((_func_4879 *)&LAB_00bccc30);
        uStack_24 = 0xffffffff;
      }
      FUN_00745060();
    }
    else {
      uStack_9c = param_2;
      uStack_a0 = 0x617f4c;
      (**(code **)(**(int **)(param_1 + 0xf0) + 0x19c))();
    }
    (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  local_64 = (undefined1 *)&uStack_a0;
  FUN_00412df0();
  local_14 = (void *)0x6;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_14._0_1_ = 7;
    local_14._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_14 = (void *)CONCAT31(local_14._1_3_,6);
  }
  local_64 = (undefined1 *)0x2c6;
  FUN_005740f0(&local_64);
  if (local_68 != DAT_00fe5ac8) {
    piVar8 = local_68 + 4;
    if (7 < (uint)local_68[9]) {
      piVar8 = (int *)*piVar8;
    }
    local_14 = (void *)0xffffffff;
    FUN_004796c0(piVar8);
    iVar6 = *(int *)(param_1 + 0x100);
    puVar11 = (undefined4 *)(iVar6 + 0xe8);
    local_14 = (void *)0x8;
    *(undefined4 *)(iVar6 + 0xf8) = 0;
    if (7 < *(uint *)(iVar6 + 0xfc)) {
      puVar11 = (undefined4 *)*puVar11;
    }
    *(undefined2 *)puVar11 = 0;
    piVar8 = *(int **)(iVar6 + 0x104);
    piVar9 = (int *)*piVar8;
    *piVar8 = (int)piVar8;
    *(int *)(*(int *)(iVar6 + 0x104) + 4) = *(int *)(iVar6 + 0x104);
    *(undefined4 *)(iVar6 + 0x108) = 0;
    if (piVar9 != *(int **)(iVar6 + 0x104)) {
      do {
        piVar9 = (int *)*piVar9;
        FUN_0089120c();
      } while (piVar9 != (int *)*(int *)(iVar6 + 0x104));
    }
    piVar8 = *(int **)(*(int *)(iVar6 + 0x114) + 4);
    cVar1 = *(char *)((int)piVar8 + 0x21);
    while (cVar1 == '\0') {
      FUN_008575b0();
      piVar8 = (int *)*piVar8;
      FUN_0089120c();
      cVar1 = *(char *)((int)piVar8 + 0x21);
    }
    *(int *)(*(int *)(iVar6 + 0x114) + 4) = *(int *)(iVar6 + 0x114);
    *(undefined4 *)*(undefined4 *)(iVar6 + 0x114) = *(undefined4 *)(iVar6 + 0x114);
    *(int *)(*(int *)(iVar6 + 0x114) + 8) = *(int *)(iVar6 + 0x114);
    *(undefined4 *)(iVar6 + 0x118) = 0;
    FUN_00759ed0();
    local_14 = (void *)0xffffffff;
    if (7 < uStack_2c) {
      FUN_0089120c();
    }
    (**(code **)(**(int **)(param_1 + 0x100) + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_14 = (void *)0x9;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_14 = (void *)0xffffffff;
    }
    local_64 = (undefined1 *)0x2c7;
    FUN_005740f0();
    if (piVar8 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_004cf650();
    iVar6 = *(int *)(param_1 + 0xfc);
    puVar11 = (undefined4 *)(iVar6 + 0xe8);
    local_14 = (void *)0xa;
    *(undefined4 *)(iVar6 + 0xf8) = 0;
    if (7 < *(uint *)(iVar6 + 0xfc)) {
      puVar11 = (undefined4 *)*puVar11;
    }
    *(undefined2 *)puVar11 = 0;
    piVar8 = *(int **)(iVar6 + 0x104);
    piVar9 = (int *)*piVar8;
    *piVar8 = (int)piVar8;
    *(int *)(*(int *)(iVar6 + 0x104) + 4) = *(int *)(iVar6 + 0x104);
    *(undefined4 *)(iVar6 + 0x108) = 0;
    if (piVar9 != *(int **)(iVar6 + 0x104)) {
      do {
        piVar9 = (int *)*piVar9;
        FUN_0089120c();
      } while (piVar9 != (int *)*(int *)(iVar6 + 0x104));
    }
    piVar8 = *(int **)(*(int *)(iVar6 + 0x114) + 4);
    cVar1 = *(char *)((int)piVar8 + 0x21);
    while (cVar1 == '\0') {
      FUN_008575b0();
      piVar8 = (int *)*piVar8;
      FUN_0089120c();
      cVar1 = *(char *)((int)piVar8 + 0x21);
    }
    *(int *)(*(int *)(iVar6 + 0x114) + 4) = *(int *)(iVar6 + 0x114);
    *(undefined4 *)*(undefined4 *)(iVar6 + 0x114) = *(undefined4 *)(iVar6 + 0x114);
    *(int *)(*(int *)(iVar6 + 0x114) + 8) = *(int *)(iVar6 + 0x114);
    *(undefined4 *)(iVar6 + 0x118) = 0;
    FUN_00759ed0();
    local_14 = (void *)0xffffffff;
    if (7 < uStack_4c) {
      FUN_0089120c();
    }
    local_60 = local_60 & 0xffff0000;
    uStack_4c = 7;
    uStack_50 = 0;
    (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
    ExceptionList = pvStack_1c;
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

