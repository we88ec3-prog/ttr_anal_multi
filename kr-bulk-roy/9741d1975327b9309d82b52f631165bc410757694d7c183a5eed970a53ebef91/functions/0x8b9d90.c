
void FUN_008b9d90(int *param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int *local_8;
  
  iVar8 = param_1[1];
  iVar6 = *param_1;
  iVar2 = -iVar6;
  if (iVar6 < iVar8) {
    if (iVar2 < iVar8) {
      iVar9 = 0x5a0000;
      iVar4 = iVar2;
      iVar6 = iVar8;
    }
    else {
      iVar9 = ((iVar8 < 1) - 1 & 0x1680000) - 0xb40000;
      iVar4 = -iVar8;
      iVar6 = iVar2;
    }
  }
  else if (iVar8 < iVar2) {
    iVar9 = -0x5a0000;
    iVar4 = iVar6;
    iVar6 = -iVar8;
  }
  else {
    iVar9 = 0;
    iVar4 = iVar8;
  }
  local_8 = &DAT_00bd6e20;
  local_c = 1;
  iVar8 = 1;
  do {
    bVar3 = (byte)local_c;
    iVar2 = iVar8 + iVar4 >> (bVar3 & 0x1f);
    if (iVar4 < 1) {
      iVar2 = -iVar2;
      iVar5 = iVar6 + iVar8 >> (bVar3 & 0x1f);
      iVar1 = -*local_8;
    }
    else {
      iVar5 = -(iVar6 + iVar8 >> (bVar3 & 0x1f));
      iVar1 = *local_8;
    }
    iVar4 = iVar4 + iVar5;
    iVar2 = iVar2 + iVar6;
    iVar5 = iVar8 * 2;
    iVar6 = iVar5 + iVar4 >> (bVar3 + 1 & 0x1f);
    if (iVar4 < 1) {
      iVar6 = -iVar6;
      iVar7 = iVar5 + iVar2 >> (bVar3 + 1 & 0x1f);
      iVar5 = -local_8[1];
    }
    else {
      iVar7 = -(iVar5 + iVar2 >> (bVar3 + 1 & 0x1f));
      iVar5 = local_8[1];
    }
    iVar9 = iVar9 + iVar1 + iVar5;
    iVar4 = iVar4 + iVar7;
    iVar6 = iVar2 + iVar6;
    local_8 = local_8 + 2;
    local_c = local_c + 2;
    iVar8 = iVar8 * 4;
  } while (local_c < 0x17);
  if (-1 < iVar9) {
    param_1[1] = iVar9 + 0x10U & 0xffffffe0;
    *param_1 = iVar6;
    return;
  }
  *param_1 = iVar6;
  param_1[1] = -(0x10U - iVar9 & 0xffffffe0);
  return;
}

