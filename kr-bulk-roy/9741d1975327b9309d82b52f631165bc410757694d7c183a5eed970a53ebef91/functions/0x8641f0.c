
void FUN_008641f0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 4);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      uVar4 = puVar3[10];
      if (((uVar4 == 0) ||
          (uVar7 = uVar4 & 0xffff,
          (uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x11c) <= uVar7)) ||
         (*(uint *)(*(int *)(param_1 + 0x20) + uVar7 * 4) != uVar4 >> 0x10)) {
        iVar8 = 0;
      }
      else {
        iVar8 = uVar7 * 0x11c + *(int *)(param_1 + 0x10);
      }
      FUN_008433e0(iVar8,*(undefined4 *)(param_1 + 0x40));
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
    FUN_008433e0(param_1 + 0x44,*(undefined4 *)(param_1 + 0x40));
  }
  return;
}

