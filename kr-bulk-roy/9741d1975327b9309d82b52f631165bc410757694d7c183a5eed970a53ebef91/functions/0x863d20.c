
void FUN_00863d20(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 4);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      uVar4 = puVar3[10];
      if (((uVar4 == 0) ||
          (uVar6 = uVar4 & 0xffff,
          (uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x9c) <= uVar6)) ||
         (*(uint *)(*(int *)(param_1 + 0x20) + uVar6 * 4) != uVar4 >> 0x10)) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = (undefined4 *)(uVar6 * 0x9c + *(int *)(param_1 + 0x10));
      }
      (**(code **)*puVar7)(*(undefined4 *)(param_1 + 0x40));
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        puVar7 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar7 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x2d);
          puVar3 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar7 + 0x2d);
            puVar3 = puVar7;
            puVar7 = (undefined4 *)*puVar7;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar7 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x2d);
            puVar5 = (undefined4 *)puVar3[1];
            puVar7 = puVar3;
          }
        }
      }
    }
  }
  return;
}

