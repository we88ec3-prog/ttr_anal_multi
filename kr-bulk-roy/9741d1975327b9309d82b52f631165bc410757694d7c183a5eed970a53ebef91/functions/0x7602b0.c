
void FUN_007602b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  int *piVar8;
  int iVar9;
  
  piVar8 = (int *)(in_ECX + 0x94);
  iVar6 = 4;
  do {
    if (*piVar8 != 0) {
      (**(code **)(*(int *)*piVar8 + 0x48))();
    }
    piVar8 = piVar8 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  piVar8 = *(int **)(in_ECX + 0xa4);
  iVar7 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) - (piVar8[5] - piVar8[3]);
  iVar6 = (piVar8[5] - piVar8[3]) + iVar7;
  (**(code **)(*piVar8 + 0xbc))(0,iVar7,piVar8[4] - piVar8[2],iVar6);
  if (0 < unaff_ESI) {
    iVar9 = *(int *)(in_ECX + 0xd4);
    if (iVar9 == 0) {
      iVar4 = ((((*(int *)(in_ECX + 0x10) - (unaff_ESI + -1) * *(int *)(in_ECX + 0xd0)) -
                *(int *)(in_ECX + 0xcc)) - *(int *)(in_ECX + 200)) - *(int *)(in_ECX + 8)) /
              unaff_ESI;
      puVar1 = *(undefined4 **)(in_ECX + 100);
      iVar9 = 0;
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar5 = 0;
        if (iVar9 != 0) {
          iVar5 = *(int *)(in_ECX + 0xd0);
        }
        iVar5 = (iVar5 + iVar4) * iVar9 + *(int *)(in_ECX + 200);
        (**(code **)(*(int *)puVar2[2] + 0xbc))(iVar5,iVar7,iVar4 + iVar5,iVar6);
        *(uint *)(puVar2[2] + 0x28) = *(uint *)(puVar2[2] + 0x28) | 0x100;
        iVar9 = iVar9 + 1;
      }
    }
    else if (iVar9 == 1) {
      iVar4 = *(int *)(*(int *)(in_ECX + 0xa4) + 0x10) - *(int *)(*(int *)(in_ECX + 0xa4) + 8);
      puVar1 = *(undefined4 **)(in_ECX + 100);
      iVar9 = 0;
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar5 = 0;
        if (iVar9 != 0) {
          iVar5 = *(int *)(in_ECX + 0xd0);
        }
        iVar5 = (iVar5 + iVar4) * iVar9 + *(int *)(in_ECX + 200);
        (**(code **)(*(int *)puVar2[2] + 0xbc))(iVar5,iVar7,iVar4 + iVar5,iVar6);
        *(uint *)(puVar2[2] + 0x28) = *(uint *)(puVar2[2] + 0x28) | 0x100;
        iVar9 = iVar9 + 1;
      }
    }
    else if (iVar9 == 2) {
      iVar9 = *(int *)(*(int *)(in_ECX + 0xa4) + 0x10) - *(int *)(*(int *)(in_ECX + 0xa4) + 8);
      piVar8 = *(int **)(in_ECX + 0xac);
      piVar3 = (int *)*piVar8;
      while (piVar3 != piVar8) {
        FUN_00754470();
        FUN_0049e6a0();
      }
      puVar1 = *(undefined4 **)(in_ECX + 100);
      iVar4 = *(int *)(in_ECX + 200);
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        piVar8 = (int *)puVar2[2];
        iVar5 = iVar9;
        if (iVar9 <= piVar8[4] - piVar8[2]) {
          iVar5 = piVar8[4] - piVar8[2];
        }
        (**(code **)(*piVar8 + 0xbc))(iVar4,iVar7,iVar4 + iVar5,iVar6);
        *(uint *)(puVar2[2] + 0x28) = *(uint *)(puVar2[2] + 0x28) | 0x100;
        iVar4 = iVar4 + (*(int *)(puVar2[2] + 0x10) - *(int *)(puVar2[2] + 8)) +
                        *(int *)(in_ECX + 0xd0);
      }
    }
  }
  if ((((*(int *)(in_ECX + 0x24) != 0) &&
       (*(int *)(in_ECX + 0x34) != *(int *)(in_ECX + 0x2c) &&
        -1 < *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x2c))) &&
      (*(int *)(in_ECX + 0x38) != *(int *)(in_ECX + 0x30) &&
       -1 < *(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x30))) &&
     ((*(uint *)(in_ECX + 0x28) & 0x100000) == 0)) {
    FUN_00753020(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x30),
                 *(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38));
  }
  return;
}

