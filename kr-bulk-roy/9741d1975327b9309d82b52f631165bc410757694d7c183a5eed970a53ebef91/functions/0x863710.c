
void FUN_00863710(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  do {
    if (puVar3 == puVar2) {
      return;
    }
    uVar4 = puVar3[10];
    if (uVar4 == 0) {
LAB_00863770:
      piVar9 = (int *)0x0;
    }
    else {
      uVar8 = uVar4 & 0xffff;
      if (((uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x34) <= uVar8) ||
         (*(uint *)(*(int *)(param_1 + 0x20) + uVar8 * 4) != uVar4 >> 0x10)) goto LAB_00863770;
      piVar9 = (int *)(*(int *)(param_1 + 0x10) + uVar8 * 0x34);
    }
    if ((piVar9[7] == 0) && (piVar5 = (int *)*piVar9, piVar5 != (int *)0x0)) {
      (**(code **)(*piVar5 + 8))(piVar5);
      *piVar9 = 0;
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
  } while( true );
}

