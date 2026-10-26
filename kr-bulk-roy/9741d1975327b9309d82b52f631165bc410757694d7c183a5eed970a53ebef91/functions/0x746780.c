
void FUN_00746780(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *extraout_EDX;
  
  puVar1 = *(undefined4 **)(param_1 + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[2];
    if ((*(byte *)((int)piVar3 + 0x2a) & 1) != 0) {
      (**(code **)(*piVar3 + 0x11c))();
      puVar4 = (undefined4 *)piVar3[0x19];
      for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
        FUN_00746c10();
      }
      if ((piVar3[10] & 0x10000U) != 0) {
        piVar3[10] = piVar3[10] ^ 0x10000;
      }
    }
    piVar3 = (int *)puVar2[2];
    if (((uint)piVar3[10] >> 0xf & 1) != 0) {
      (**(code **)(*piVar3 + 0x120))();
      puVar4 = (undefined4 *)piVar3[0x19];
      for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
        FUN_00746b80();
      }
      if ((piVar3[10] & 0x8000U) != 0) {
        piVar3[10] = piVar3[10] ^ 0x8000;
      }
    }
    *(undefined4 *)(puVar2[2] + 0x60) = 0;
    iVar6 = puVar2[2];
    *(undefined4 *)(iVar6 + 0x24) = 0;
    if ((*(int *)(iVar6 + 0x3c) != 0) && ((*(uint *)(iVar6 + 0x28) & 0x40000) == 0)) {
      FUN_007486f0(0);
    }
    puVar4 = *(undefined4 **)(iVar6 + 100);
    puVar5 = (undefined4 *)*puVar4;
    while (puVar5 != puVar4) {
      FUN_007486f0(*(undefined4 *)(iVar6 + 0x24));
      puVar5 = (undefined4 *)*extraout_EDX;
    }
    iVar6 = *(int *)(param_1 + 0x24);
    if ((iVar6 != 0) && (iVar7 = puVar2[2], iVar7 != 0)) {
      FUN_007503c0();
      FUN_007501e0(iVar7);
      puVar4 = *(undefined4 **)(iVar6 + 0x1438);
      for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
        if (*(int *)(puVar5[2] + 0xc) == iVar7) {
          *(undefined4 *)(puVar5[2] + 0xc) = 0;
        }
      }
      puVar4 = *(undefined4 **)(iVar6 + 0x142c);
      for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
        if (*(int *)(puVar5[2] + 0xc) == iVar7) {
          *(undefined4 *)(puVar5[2] + 0xc) = 0;
        }
      }
      FUN_00750290(iVar7);
      puVar4 = *(undefined4 **)(iVar7 + 100);
      for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
        FUN_00750190(puVar5[2]);
      }
    }
  }
  piVar3 = *(int **)(param_1 + 100);
  piVar8 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(param_1 + 100) + 4) = *(int *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x68) = 0;
  if (piVar8 != *(int **)(param_1 + 100)) {
    do {
      piVar3 = (int *)*piVar8;
      FUN_0089120c(piVar8);
      piVar8 = piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 100));
  }
  return;
}

