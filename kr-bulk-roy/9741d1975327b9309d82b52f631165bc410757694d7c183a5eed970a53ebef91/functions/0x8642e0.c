
void FUN_008642e0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    uVar4 = puVar3[10];
    if (((uVar4 == 0) ||
        (uVar8 = uVar4 & 0xffff,
        (uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x11c) <= uVar8)) ||
       (*(uint *)(*(int *)(param_1 + 0x20) + uVar8 * 4) != uVar4 >> 0x10)) {
      iVar9 = 0;
    }
    else {
      iVar9 = uVar8 * 0x11c + *(int *)(param_1 + 0x10);
    }
    piVar5 = *(int **)(iVar9 + 0x110);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))(piVar5);
      *(undefined4 *)(iVar9 + 0x110) = 0;
    }
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
        puVar7 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  }
  piVar5 = *(int **)(param_1 + 0x154);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  return;
}

