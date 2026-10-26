
void FUN_00863870(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  void **ppvVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00908d2d;
  uVar10 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 1;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar8 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar8, puVar3 != puVar2) {
    uVar4 = puVar3[10];
    if (((uVar4 == 0) ||
        (uVar11 = uVar4 & 0xffff,
        (uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x34) <= uVar11)) ||
       (*(uint *)(*(int *)(param_1 + 0x20) + uVar11 * 4) != uVar4 >> 0x10)) {
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = (int *)(uVar11 * 0x34 + *(int *)(param_1 + 0x10));
    }
    if ((piVar12[7] == 0) && (piVar5 = (int *)*piVar12, piVar5 != (int *)0x0)) {
      (**(code **)(*piVar5 + 8))(piVar5,uVar10);
      *piVar12 = 0;
    }
    ppvVar8 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar6 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar6 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x2d);
        puVar3 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x2d);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar9 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar9, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar9 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = local_8 & 0xffffff00;
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  piVar12 = *(int **)(param_1 + 0x10);
  if (piVar12 != (int *)0x0) {
    piVar5 = *(int **)(param_1 + 0x14);
    for (; piVar12 != piVar5; piVar12 = piVar12 + 0xd) {
      piVar7 = (int *)*piVar12;
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 8))(piVar7);
        *piVar12 = 0;
      }
    }
    FUN_0089120c(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  local_8 = 2;
  FUN_0057ffd0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

