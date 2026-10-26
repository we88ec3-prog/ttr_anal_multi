
void FUN_008c1a90(int param_1)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  int *in_EDX;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  
  piVar9 = (int *)(param_1 + 0x4c);
  *piVar9 = *in_EAX * 4;
  *(int *)(param_1 + 0x50) = in_EAX[1] * 4;
  *(int *)(param_1 + 0x54) = *in_ECX * 4;
  *(int *)(param_1 + 0x58) = in_ECX[1] * 4;
  *(int *)(param_1 + 0x5c) = *in_EDX * 4;
  iVar1 = *(int *)(param_1 + 0x50);
  *(int *)(param_1 + 0x60) = in_EDX[1] * 4;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x40);
  iVar4 = *(int *)(param_1 + 0x58);
  iVar5 = *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x68) = iVar5;
  iVar3 = iVar1;
  if (iVar4 < iVar1) {
    iVar3 = iVar4;
  }
  if (iVar1 < iVar4) {
    iVar1 = iVar4;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  if (iVar4 < iVar3) {
    iVar3 = iVar4;
  }
  if (iVar1 < iVar4) {
    iVar1 = iVar4;
  }
  if (iVar5 < iVar3) {
    iVar3 = iVar5;
  }
  if (iVar1 < iVar5) {
    iVar1 = iVar5;
  }
  if ((iVar3 >> 8 < *(int *)(param_1 + 0x14)) && (*(int *)(param_1 + 0x10) <= iVar1 >> 8))
  goto LAB_008c1b40;
LAB_008c1b20:
  FUN_008c15f0(*piVar9,piVar9[1]);
  if (piVar9 == (int *)(param_1 + 0x4c)) {
    return;
  }
  piVar9 = piVar9 + -6;
LAB_008c1b40:
  do {
    uVar10 = piVar9[6] - *piVar9;
    uVar8 = piVar9[7] - piVar9[1];
    iVar4 = (uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f);
    iVar1 = (uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f);
    if (iVar1 < iVar4) {
      iVar5 = 0xec;
      iVar3 = 0x61;
    }
    else {
      iVar3 = 0xec;
      iVar5 = 0x61;
    }
    iVar1 = iVar1 * iVar3 + iVar4 * iVar5 >> 8;
    if (iVar1 < 0x8000) {
      iVar1 = iVar1 * 0x2a;
      iVar4 = piVar9[2] - *piVar9;
      iVar5 = piVar9[3] - piVar9[1];
      uVar2 = iVar4 * uVar8 - iVar5 * uVar10;
      uVar6 = (int)uVar2 >> 0x1f;
      if ((int)((uVar2 ^ uVar6) - uVar6) <= iVar1) {
        iVar3 = piVar9[4] - *piVar9;
        iVar7 = piVar9[5] - piVar9[1];
        uVar2 = iVar3 * uVar8 - iVar7 * uVar10;
        uVar6 = (int)uVar2 >> 0x1f;
        if ((((int)((uVar2 ^ uVar6) - uVar6) <= iVar1) &&
            ((int)((iVar5 - uVar8) * iVar5 + (iVar4 - uVar10) * iVar4) < 1)) &&
           ((int)((iVar7 - uVar8) * iVar7 + (iVar3 - uVar10) * iVar3) < 1)) goto LAB_008c1b20;
      }
    }
    FUN_008c19e0();
    piVar9 = piVar9 + 6;
  } while( true );
}

