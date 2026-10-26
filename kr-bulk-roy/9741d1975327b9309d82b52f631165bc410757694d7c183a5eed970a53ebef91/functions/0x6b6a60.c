
void FUN_006b6a60(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  float fVar12;
  float local_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935838;
  local_14 = ExceptionList;
  uVar10 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar10);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar2 = *(int *)(DAT_00fab130 + 0x5f18);
  iVar11 = *(int *)(DAT_00fab130 + 0x5f20);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90(uVar10);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar8 = DAT_00fab228;
  if (DAT_00fab228 != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90(uVar10);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    puVar7 = DAT_00fab14c;
    local_c = 0xffffffff;
    puVar3 = (undefined4 *)*DAT_00fab14c;
    local_28 = (float)iVar11 / (float)iVar2;
    while (puVar3 != puVar7) {
      iVar11 = puVar3[4];
      if ((iVar11 != 0) &&
         (((iVar4 = *(int *)(iVar8 + 0x10), iVar4 == 0 || (iVar4 != *(int *)(iVar11 + 0x10))) &&
          (*(short *)(iVar8 + 0x14) != *(short *)(iVar11 + 0x14))))) {
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 3;
          FUN_004dec90(uVar10);
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        iVar11 = FUN_004dfb60();
        if ((iVar11 != 0) && (*(int *)(iVar11 + 0x3c8) != 0)) {
          local_28 = local_28 -
                     (1.0 - (float)*(int *)(iVar11 + 0x3c8) / (float)*(int *)(iVar11 + 0x3bc)) /
                     (float)iVar2;
        }
      }
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar5 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar5 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x15);
            puVar3 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar9 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
          while ((puVar3 = puVar9, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar9 = (undefined4 *)puVar3[1];
            puVar5 = puVar3;
          }
        }
      }
    }
    fVar12 = 0.0;
    if ((local_28 < 0.0) || (fVar12 = 1.0, 1.0 < local_28)) {
      local_28 = fVar12;
    }
    if (*(int *)(*(int *)(param_1 + 0x84) + 0xcc) != 0) {
      FUN_00757710();
    }
    pcVar6 = *(code **)(**(int **)(param_1 + 0x84) + 0x128);
    (*(int **)(param_1 + 0x84))[0x34] = (int)local_28;
    (*pcVar6)();
    (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  }
  ExceptionList = local_14;
  return;
}

