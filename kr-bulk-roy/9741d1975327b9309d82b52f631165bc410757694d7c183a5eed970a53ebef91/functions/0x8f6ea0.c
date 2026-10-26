
void FUN_008f6ea0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int in_EDX;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  uVar1 = *(uint *)(in_ECX + 0x68) & 4;
  iVar8 = 0x40;
  if (uVar1 == 0) {
    if (((*(byte *)(param_1 + 0xc) & 1) == 0) || ((*(byte *)(param_2 + 0xc) & 1) == 0)) {
      iVar8 = (uint)(in_EDX == 1) * 2 + 0x3b;
    }
    else {
      iVar8 = (-(uint)(in_EDX != 1) & 0xfffffffa) + 0x37;
    }
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_2 + 4);
  uVar2 = FUN_008f6d50();
  uVar5 = ((iVar6 + iVar3) / 2 - (int)uVar2 / 2) + param_3;
  iVar6 = uVar5 - (uVar5 & 0xffffffc0);
  iVar3 = (uVar5 + uVar2) - (uVar5 + uVar2 & 0xffffffc0);
  uVar10 = 0x40 - iVar6;
  uVar4 = 0;
  if ((iVar6 != 0) && (iVar3 != 0)) {
    if (iVar8 < (int)uVar2) {
      if ((0x3f < iVar8) ||
         ((((iVar6 < iVar8 && ((int)uVar10 < iVar8)) && (iVar3 < iVar8)) && (0x40 - iVar3 < iVar8)))
         ) {
        uVar7 = uVar2 & 0x3f;
        if (uVar7 < 0x20) {
          if (((int)uVar10 <= (int)uVar7) || (iVar3 <= (int)uVar7)) goto LAB_008f6fca;
        }
        else {
          uVar7 = 0x40 - iVar8;
        }
        uVar9 = iVar8 - iVar3;
        uVar4 = uVar10 - uVar7;
        if ((int)(iVar8 - uVar10) <= (int)uVar4) {
          uVar4 = -(iVar8 - uVar10);
        }
        if ((int)(iVar3 - uVar7) <= (int)uVar9) {
          uVar9 = -(iVar3 - uVar7);
        }
        if ((int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)) <
            (int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f))) {
          uVar4 = uVar9;
        }
      }
    }
    else if ((iVar3 < (int)uVar2) && (uVar4 = uVar10, iVar3 < (int)uVar10)) {
      uVar4 = -iVar3;
    }
  }
LAB_008f6fca:
  if (uVar1 == 0) {
    if ((int)uVar4 < 0xf) {
      if ((int)uVar4 < -0xe) {
        uVar4 = 0xfffffff2;
      }
    }
    else {
      uVar4 = 0xe;
    }
  }
  iVar8 = uVar5 + uVar4;
  if (*(int *)(param_2 + 4) <= *(int *)(param_1 + 4)) {
    *(uint *)(param_1 + 8) = uVar2 + iVar8;
    *(int *)(param_2 + 8) = iVar8;
    return;
  }
  *(int *)(param_1 + 8) = iVar8;
  *(uint *)(param_2 + 8) = iVar8 + uVar2;
  return;
}

