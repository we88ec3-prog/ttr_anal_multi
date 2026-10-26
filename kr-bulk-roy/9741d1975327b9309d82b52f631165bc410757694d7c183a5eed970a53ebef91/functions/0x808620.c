
void FUN_00808620(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x18);
  if (iVar2 != 0) {
    FUN_008093a0(iVar2);
    FUN_0089120c(iVar2);
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  iVar2 = *(int *)(in_ECX + 0x14);
  if (iVar2 != 0) {
    FUN_008093a0(iVar2);
    FUN_0089120c(iVar2);
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar4 = (undefined4 *)*puVar3;
  while (puVar4 != puVar3) {
    iVar2 = puVar4[4];
    if (iVar2 != 0) {
      FUN_008081c0(iVar2);
      FUN_0089120c(iVar2);
      puVar4[4] = 0;
    }
    if (*(char *)((int)puVar4 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar4 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x15);
        puVar8 = (undefined4 *)puVar4[1];
        puVar5 = puVar4;
        while ((puVar4 = puVar8, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x15);
          puVar8 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
      }
    }
  }
  piVar6 = *(int **)(*(int *)(in_ECX + 8) + 4);
  cVar1 = *(char *)((int)piVar6 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar6[2]);
    piVar7 = (int *)*piVar6;
    FUN_0089120c(piVar6);
    piVar6 = piVar7;
    cVar1 = *(char *)((int)piVar7 + 0x15);
  }
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

