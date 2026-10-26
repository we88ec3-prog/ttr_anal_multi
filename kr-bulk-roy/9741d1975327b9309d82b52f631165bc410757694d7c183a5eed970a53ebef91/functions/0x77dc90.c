
void FUN_0077dc90(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0x210);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((undefined4 *)puVar3[10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar3[10])(1);
      puVar3[10] = 0;
    }
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
  FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 0x210) + 4));
  *(int *)(*(int *)(param_1 + 0x210) + 4) = *(int *)(param_1 + 0x210);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(param_1 + 0x210);
  *(int *)(*(int *)(param_1 + 0x210) + 8) = *(int *)(param_1 + 0x210);
  *(undefined4 *)(param_1 + 0x214) = 0;
  return;
}

