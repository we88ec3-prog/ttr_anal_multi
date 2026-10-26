
void FUN_0058e110(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  FUN_0058f430(*(undefined4 *)(*(int *)(param_1 + 0x48) + 4));
  *(int *)(*(int *)(param_1 + 0x48) + 4) = *(int *)(param_1 + 0x48);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(int *)(*(int *)(param_1 + 0x48) + 8) = *(int *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_0058cb60(puVar3[10]);
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
  FUN_0058e790(param_1);
  piVar6 = (int *)(param_1 + 0x28);
  if (7 < *(uint *)(param_1 + 0x3c)) {
    piVar6 = (int *)*piVar6;
  }
  FUN_0058de20(piVar6);
  return;
}

