
void FUN_00596c90(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar8 = param_1 + 0xc0;
  param_1 = 3;
  do {
    puVar2 = *(undefined4 **)(iVar8 + 4);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      if (((uint)((int *)puVar3[3])[10] >> 8 & 1) != 0) {
        (**(code **)(*(int *)puVar3[3] + 0xd4))();
      }
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x21);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar7 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar7 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    piVar5 = *(int **)(*(int *)(iVar8 + 4) + 4);
    cVar1 = *(char *)((int)piVar5 + 0x21);
    while (cVar1 == '\0') {
      FUN_008575b0(piVar5[2]);
      piVar6 = (int *)*piVar5;
      FUN_0089120c(piVar5);
      piVar5 = piVar6;
      cVar1 = *(char *)((int)piVar6 + 0x21);
    }
    *(int *)(*(int *)(iVar8 + 4) + 4) = *(int *)(iVar8 + 4);
    *(undefined4 *)*(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar8 + 4);
    *(int *)(*(int *)(iVar8 + 4) + 8) = *(int *)(iVar8 + 4);
    *(undefined4 *)(iVar8 + 8) = 0;
    iVar8 = iVar8 + 0x10;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}

