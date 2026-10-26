
undefined4 FUN_00780150(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  
  if (param_1[0xb] != 0) {
    puVar2 = (undefined4 *)param_1[0xe];
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar4 = (int *)puVar3[4];
      iVar8 = (**(code **)(*piVar4 + 4))();
      piVar5 = (int *)param_1[0x12];
      piVar9 = (int *)param_1[0x11];
      if (piVar9 == piVar5) {
LAB_0078019f:
        (**(code **)(*piVar4 + 0x18))(param_1,param_2);
      }
      else {
        do {
          if (*piVar9 == *(int *)(iVar8 + 4)) break;
          piVar9 = piVar9 + 1;
        } while (piVar9 != piVar5);
        if (piVar9 == piVar5) goto LAB_0078019f;
      }
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar6 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar6 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x15);
            puVar3 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar7 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x18))();
  return 1;
}

