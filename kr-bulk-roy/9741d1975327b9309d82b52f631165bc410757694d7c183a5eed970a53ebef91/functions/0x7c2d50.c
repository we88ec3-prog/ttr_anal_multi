
void FUN_007c2d50(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar4 = puVar3[10];
    puVar5 = *(undefined4 **)(iVar4 + 0x1c);
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)(1);
      *(undefined4 *)(iVar4 + 0x1c) = 0;
    }
    puVar5 = (undefined4 *)puVar3[10];
    if (puVar5 != (undefined4 *)0x0) {
      if (0xf < (uint)puVar5[5]) {
        FUN_0089120c(*puVar5);
      }
      puVar5[5] = 0xf;
      puVar5[4] = 0;
      *(undefined1 *)puVar5 = 0;
      FUN_0089120c(puVar5);
      puVar3[10] = 0;
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x2d);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x2d);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

