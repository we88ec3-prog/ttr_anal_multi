
void FUN_005c6fd0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  int iVar6;
  int *piVar7;
  
  if (*(char *)(in_EAX + 0x304) != '\0') {
    if (*(int **)(in_EAX + 0x274) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x274) + 8))();
      *(undefined4 *)(in_EAX + 0x274) = 0;
    }
    *(undefined4 *)(in_EAX + 0x2c4) = 0;
    *(undefined4 *)(in_EAX + 0x2c8) = 0;
    *(undefined1 *)(in_EAX + 0x304) = 0;
  }
  if (*(char *)(in_EAX + 0x3a4) != '\0') {
    if (*(int **)(in_EAX + 0x314) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x314) + 8))();
      *(undefined4 *)(in_EAX + 0x314) = 0;
    }
    *(undefined4 *)(in_EAX + 0x364) = 0;
    *(undefined4 *)(in_EAX + 0x368) = 0;
    *(undefined1 *)(in_EAX + 0x3a4) = 0;
  }
  if (*(char *)(in_EAX + 0x444) != '\0') {
    if (*(int **)(in_EAX + 0x3b4) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x3b4) + 8))();
      *(undefined4 *)(in_EAX + 0x3b4) = 0;
    }
    *(undefined4 *)(in_EAX + 0x404) = 0;
    *(undefined4 *)(in_EAX + 0x408) = 0;
    *(undefined1 *)(in_EAX + 0x444) = 0;
  }
  (**(code **)(**(int **)(in_EAX + 0x268) + 0x2c))();
  (**(code **)(**(int **)(in_EAX + 0x14) + 0x20))();
  piVar7 = (int *)(in_EAX + 0x128);
  iVar6 = 4;
  do {
    (**(code **)(*piVar7 + 0x2c))();
    piVar7 = piVar7 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar2 = *(undefined4 **)(in_EAX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[10] + 0x2c))();
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}

