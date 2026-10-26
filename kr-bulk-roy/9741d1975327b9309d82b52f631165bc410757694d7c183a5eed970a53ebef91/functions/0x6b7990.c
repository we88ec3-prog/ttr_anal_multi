
void FUN_006b7990(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00938a0e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  puVar3 = *(undefined4 **)(DAT_00fab130 + 0x5efc);
  local_2c = *(int *)(DAT_00fab130 + 0x5f00) - (int)puVar3 >> 2;
  if (local_2c != 0) {
    uVar1 = *(int *)(DAT_00fab130 + 0x5eec) - *(int *)(DAT_00fab130 + 0x5ee8) >> 2;
    do {
      uVar5 = 0;
      if (uVar1 != 0) {
        piVar4 = *(int **)(DAT_00fab130 + 0x5ee8);
        do {
          if (*piVar4 == *(int *)*puVar3) break;
          uVar5 = uVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar5 < uVar1);
      }
      puVar3 = puVar3 + 1;
      local_2c = local_2c + -1;
    } while (local_2c != 0);
  }
  iVar2 = *(int *)(param_1 + 0x84);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar2 = *(int *)(param_1 + 0x88);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar2 = *(int *)(param_1 + 0x8c);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  (**(code **)(**(int **)(param_1 + 0x88) + 200))();
  (**(code **)(**(int **)(param_1 + 0x8c) + 200))();
  iVar2 = *(int *)(param_1 + 0x90);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar2 = *(int *)(param_1 + 0x94);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar2 = *(int *)(param_1 + 0x98);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x90) + 200))();
  (**(code **)(**(int **)(param_1 + 0x94) + 200))();
  (**(code **)(**(int **)(param_1 + 0x98) + 200))();
  ExceptionList = local_14;
  return;
}

