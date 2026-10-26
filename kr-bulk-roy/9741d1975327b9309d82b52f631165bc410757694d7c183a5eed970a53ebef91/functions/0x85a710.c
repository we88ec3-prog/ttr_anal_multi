
void FUN_0085a710(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x114))(*(int **)(in_ECX + 4));
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((puVar3[0xb] == 0) && (piVar4 = (int *)puVar3[4], piVar4 != (int *)0x0)) {
      (**(code **)(*piVar4 + 8))(piVar4);
      puVar3[4] = 0;
    }
    if (*(char *)((int)puVar3 + 0x45) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x45) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x45);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x45);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x45);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x45);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x44);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    piVar4 = (int *)puVar3[4];
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      puVar3[4] = 0;
    }
    if (*(char *)((int)puVar3 + 0x41) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x41) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x41);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x41);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x41);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x41);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  return;
}

