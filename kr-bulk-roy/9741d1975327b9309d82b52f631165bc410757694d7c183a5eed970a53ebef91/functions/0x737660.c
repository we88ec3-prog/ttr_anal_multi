
void FUN_00737660(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar2 = (undefined4 *)param_1[4];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar4 = puVar3[4];
    piVar5 = *(int **)(iVar4 + 0x30);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
      *(undefined4 *)(iVar4 + 0x30) = 0;
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
  *param_1 = 0;
  return;
}

