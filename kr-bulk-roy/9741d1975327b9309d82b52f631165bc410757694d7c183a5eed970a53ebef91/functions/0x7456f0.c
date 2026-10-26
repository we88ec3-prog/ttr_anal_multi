
void FUN_007456f0(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int **ppiVar7;
  int *piVar8;
  int *in_ECX;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 **ppuVar11;
  code *pcVar12;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  int *piStack_20;
  int *piStack_1c;
  uint uStack_18;
  int *piStack_14;
  
  FUN_00823850();
  piVar8 = (int *)in_ECX[0x19];
  piVar6 = (int *)*piVar8;
  *piVar8 = (int)piVar8;
  *(int *)(in_ECX[0x19] + 4) = in_ECX[0x19];
  in_ECX[0x1a] = 0;
  if (piVar6 != (int *)in_ECX[0x19]) {
    do {
      piVar8 = (int *)*piVar6;
      FUN_0089120c(piVar6);
      piVar6 = piVar8;
    } while (piVar8 != (int *)in_ECX[0x19]);
  }
  if ((in_ECX[10] & 0x8000U) != 0) {
    in_ECX[10] = in_ECX[10] ^ 0x8000;
  }
  if ((in_ECX[10] & 0x10000U) != 0) {
    in_ECX[10] = in_ECX[10] ^ 0x10000;
  }
  if ((in_ECX[10] & 0x20000U) != 0) {
    in_ECX[10] = in_ECX[10] ^ 0x20000;
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar4 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x28))();
    in_ECX[7] = iVar4;
  }
  piStack_1c = *(int **)(param_1 + 0x50);
  piVar8 = (int *)*piStack_1c;
  if (piVar8 != piStack_1c) {
    do {
      piStack_20 = (int *)(**(code **)(*(int *)piVar8[4] + 0x28))();
      puVar10 = (undefined4 *)((undefined4 *)in_ECX[0x14])[1];
      cVar1 = *(char *)((int)puVar10 + 0x15);
      uVar2 = piVar8[3];
      puStack_28 = (undefined4 *)in_ECX[0x14];
      while (cVar1 == '\0') {
        if ((uint)puVar10[3] < uVar2) {
          puVar9 = (undefined4 *)puVar10[2];
          puVar10 = puStack_28;
        }
        else {
          puVar9 = (undefined4 *)*puVar10;
        }
        puStack_28 = puVar10;
        puVar10 = puVar9;
        cVar1 = *(char *)((int)puVar9 + 0x15);
      }
      puVar10 = (undefined4 *)in_ECX[0x14];
      if ((puStack_28 == puVar10) || (uVar2 < (uint)puStack_28[3])) {
        puStack_24 = puVar10;
        ppuVar11 = &puStack_24;
      }
      else {
        ppuVar11 = &puStack_28;
      }
      if (*ppuVar11 == puVar10) {
        piStack_20[0x11] = (int)in_ECX;
        piStack_20[0x12] = uVar2;
        uStack_18 = uVar2;
        piStack_14 = piStack_20;
        uVar5 = FUN_0057ef20();
        FUN_0082f200(in_ECX + 0x13,uVar5);
      }
      if (*(char *)((int)piVar8 + 0x15) == '\0') {
        piVar6 = (int *)piVar8[2];
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar6 + 0x15);
          piVar8 = piVar6;
          piVar6 = (int *)*piVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar8 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x15);
          piVar3 = (int *)piVar8[1];
          piVar6 = piVar8;
          while ((piVar8 = piVar3, cVar1 == '\0' && (piVar6 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar3 = (int *)piVar8[1];
            piVar6 = piVar8;
          }
        }
      }
    } while (piVar8 != piStack_1c);
  }
  puVar10 = *(undefined4 **)(param_1 + 100);
  for (puVar9 = (undefined4 *)*puVar10; puVar9 != puVar10; puVar9 = (undefined4 *)*puVar9) {
    piVar8 = (int *)((int *)in_ECX[0x14])[1];
    cVar1 = *(char *)((int)piVar8 + 0x15);
    piStack_1c = (int *)in_ECX[0x14];
    while (cVar1 == '\0') {
      if ((uint)piVar8[3] < *(uint *)(puVar9[2] + 0x48)) {
        piVar6 = (int *)piVar8[2];
        piVar8 = piStack_1c;
      }
      else {
        piVar6 = (int *)*piVar8;
      }
      piStack_1c = piVar8;
      piVar8 = piVar6;
      cVar1 = *(char *)((int)piVar6 + 0x15);
    }
    if ((piStack_1c == (int *)in_ECX[0x14]) || (*(uint *)(puVar9[2] + 0x48) < (uint)piStack_1c[3]))
    {
      piStack_20 = (int *)in_ECX[0x14];
      ppiVar7 = &piStack_20;
    }
    else {
      ppiVar7 = &piStack_1c;
    }
    if ((*ppiVar7 != (int *)in_ECX[0x14]) && (iVar4 = (*ppiVar7)[4], iVar4 != 0)) {
      (**(code **)(*in_ECX + 0x70))(iVar4);
    }
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    piVar8 = (int *)in_ECX[0xf];
    if ((in_ECX[10] & 0x40000U) == 0) {
      iVar4 = *in_ECX;
      piVar8 = (int *)(**(code **)(*piVar8 + 0x28))();
      pcVar12 = *(code **)(iVar4 + 0x50);
    }
    else {
      pcVar12 = *(code **)(*in_ECX + 0x50);
    }
    (*pcVar12)(piVar8);
  }
  (**(code **)(*in_ECX + 0x114))();
  return;
}

