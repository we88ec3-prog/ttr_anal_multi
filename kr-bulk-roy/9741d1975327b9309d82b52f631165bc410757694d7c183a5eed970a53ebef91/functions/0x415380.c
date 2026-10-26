
void FUN_00415380(uint param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar5 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091362c;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)(param_1 + 0x3c4);
  piVar2 = (int *)(param_1 + 0x3c0);
  param_1 = 0;
  if (*piVar1 - *piVar2 >> 2 != 0) {
    do {
      iVar4 = *(int *)(iVar5 + 0x3c0);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 0;
        FUN_0051c120(uVar6);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      puVar8 = *(undefined4 **)(DAT_00f8d91c + 4);
      cVar3 = *(char *)((int)puVar8 + 0x15);
      while (cVar3 == '\0') {
        if ((int)puVar8[3] < **(int **)(iVar4 + param_1 * 4)) {
          puVar8 = (undefined4 *)puVar8[2];
        }
        else {
          puVar8 = (undefined4 *)*puVar8;
        }
        cVar3 = *(char *)((int)puVar8 + 0x15);
      }
      uVar7 = FUN_0057ef20();
      FUN_0057e850(iVar5 + 0x4a0,uVar7);
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(iVar5 + 0x3c4) - *(int *)(iVar5 + 0x3c0) >> 2));
  }
  param_1 = 0;
  if (*(int *)(iVar5 + 0x3c4) - *(int *)(iVar5 + 0x3c0) >> 2 != 0) {
    do {
      iVar4 = *(int *)(iVar5 + 0x3c0);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 1;
        FUN_0051c120(uVar6);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      puVar8 = *(undefined4 **)(DAT_00f8d91c + 4);
      cVar3 = *(char *)((int)puVar8 + 0x15);
      while (cVar3 == '\0') {
        if ((int)puVar8[3] < **(int **)(iVar4 + param_1 * 4)) {
          puVar8 = (undefined4 *)puVar8[2];
        }
        else {
          puVar8 = (undefined4 *)*puVar8;
        }
        cVar3 = *(char *)((int)puVar8 + 0x15);
      }
      uVar7 = FUN_0057ef20();
      FUN_0057e850(iVar5 + 0x4a0,uVar7);
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(iVar5 + 0x3c4) - *(int *)(iVar5 + 0x3c0) >> 2));
  }
  ExceptionList = local_10;
  return;
}

