
undefined4 FUN_006f82d0(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  undefined8 uVar15;
  int local_18;
  uint local_10;
  int local_c;
  
  iVar3 = *(int *)(param_1 + 0x2c);
  local_18 = iVar3 + -1;
  bVar1 = *(byte *)(param_1 + 0x4b);
  if ((((0xfa < bVar1) ||
       (uVar11 = (uint)*(byte *)(param_1 + 0x48), (int)uVar11 < *(int *)(param_1 + 0x24))) ||
      ((*(int *)(param_1 + 0x30) != iVar3 && (*(int *)(param_1 + 0x30) != 0)))) ||
     (iVar4 = *(int *)(param_1 + 0xc),
     ((byte)*(undefined4 *)(iVar4 + -4 + iVar3 * 4) & 0x3f) != 0x1e)) {
    return 0;
  }
  local_c = 0;
  if (param_2 < 1) {
    return *(undefined4 *)(iVar4 + local_18 * 4);
  }
LAB_006f8343:
  uVar6 = *(uint *)(iVar4 + local_c * 4);
  uVar7 = uVar6 & 0x3f;
  uVar12 = 0;
  uVar10 = uVar6 >> 6 & 0xff;
  local_10 = 0;
  if (0x25 < uVar7) {
    return 0;
  }
  uVar9 = (uint)bVar1;
  if (uVar9 <= uVar10) {
    return 0;
  }
  bVar2 = (&DAT_00c0b914)[uVar7];
  if ((bVar2 & 3) == 0) {
    uVar12 = uVar6 >> 0x17;
    local_10 = uVar6 >> 0xe & 0x1ff;
    iVar5 = FUN_006f8270(bVar2 >> 4 & 3);
    if (iVar5 == 0) {
      return 0;
    }
    uVar6 = FUN_006f8270(bVar2 >> 2 & 3);
joined_r0x006f84a0:
    if (uVar6 == 0) {
      return 0;
    }
  }
  else if ((bVar2 & 3) == 1) {
    uVar12 = uVar6 >> 0xe;
    if ((((&DAT_00c0b914)[uVar7] & 0x30) == 0x30) && (*(int *)(param_1 + 0x28) <= (int)uVar12)) {
      return 0;
    }
  }
  else if ((bVar2 & 3) == 2) {
    uVar12 = (uVar6 >> 0xe) - 0x1ffff;
    if (((&DAT_00c0b914)[uVar7] & 0x30) == 0x20) {
      iVar5 = ((uVar6 >> 0xe) - 0x1fffe) + local_c;
      if (iVar5 < 0) {
        return 0;
      }
      if (iVar3 <= iVar5) {
        return 0;
      }
      if ((0 < iVar5) && (uVar6 = *(uint *)(iVar4 + -4 + iVar5 * 4), ((byte)uVar6 & 0x3f) == 0x22))
      {
        uVar6 = uVar6 & 0x7fc000;
        goto joined_r0x006f84a0;
      }
    }
  }
  else {
    local_10 = 0;
  }
  if ((((&DAT_00c0b914)[uVar7] & 0x40) != 0) && (uVar10 == param_3)) {
    local_18 = local_c;
  }
  if ((char)(&DAT_00c0b914)[uVar7] < '\0') {
    if (iVar3 <= local_c + 2) {
      return 0;
    }
    if (((byte)*(undefined4 *)(iVar4 + 4 + local_c * 4) & 0x3f) != 0x16) {
      return 0;
    }
  }
  switch(uVar7) {
  case 2:
    if (local_10 != 0) {
      bVar14 = SBORROW4(local_c + 2,iVar3);
      bVar13 = (local_c + 2) - iVar3 < 0;
      goto LAB_006f8696;
    }
    break;
  case 3:
    if (((int)uVar10 <= (int)param_3) && ((int)param_3 <= (int)uVar12)) {
      local_18 = local_c;
    }
    break;
  case 4:
  case 8:
    bVar14 = SBORROW4(uVar12,uVar11);
    bVar13 = (int)(uVar12 - uVar11) < 0;
    goto LAB_006f8696;
  case 5:
  case 7:
    if (*(int *)(*(int *)(param_1 + 8) + 8 + uVar12 * 0x10) != 4) {
      return 0;
    }
    break;
  case 0xb:
    if (uVar9 <= uVar10 + 1) {
      return 0;
    }
    if (param_3 == uVar10 + 1) {
      local_18 = local_c;
    }
    break;
  case 0x15:
    bVar14 = SBORROW4(uVar12,local_10);
    bVar13 = (int)(uVar12 - local_10) < 0;
    goto LAB_006f8696;
  case 0x16:
    goto switchD_006f8434_caseD_16;
  case 0x1c:
  case 0x1d:
    if ((uVar12 != 0) && ((int)uVar9 <= (int)((uVar12 - 1) + uVar10))) {
      return 0;
    }
    if (local_10 == 0) {
      uVar15 = FUN_006f8240();
      iVar5 = (int)((ulonglong)uVar15 >> 0x20);
      if ((int)uVar15 == 0) {
        return 0;
      }
    }
    else {
      iVar5 = local_c;
      if ((local_10 != 1) && ((int)uVar9 <= (int)((local_10 - 2) + uVar10))) {
        return 0;
      }
    }
    if ((int)uVar10 <= (int)param_3) {
      local_18 = iVar5;
    }
    break;
  case 0x1e:
    if (0 < (int)(uVar12 - 1)) {
      iVar5 = (uVar12 - 2) + uVar10;
      bVar14 = SBORROW4(iVar5,uVar9);
      bVar13 = (int)(iVar5 - uVar9) < 0;
      goto LAB_006f8696;
    }
    break;
  case 0x1f:
  case 0x20:
    if (uVar9 <= uVar10 + 3) {
      return 0;
    }
    goto switchD_006f8434_caseD_16;
  case 0x21:
    if (local_10 == 0) {
      return 0;
    }
    if (uVar9 <= local_10 + 2 + uVar10) {
      return 0;
    }
    if ((int)(uVar10 + 2) <= (int)param_3) {
      local_18 = local_c;
    }
    break;
  case 0x22:
    if ((0 < (int)uVar12) && ((int)uVar9 <= (int)(uVar12 + uVar10))) {
      return 0;
    }
    if (local_10 == 0) {
      local_c = local_c + 1;
    }
    break;
  case 0x24:
    if (*(int *)(param_1 + 0x34) <= (int)uVar12) {
      return 0;
    }
    uVar6 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + uVar12 * 4) + 0x48);
    if (iVar3 <= (int)(uVar6 + local_c)) {
      return 0;
    }
    iVar5 = 1;
    if (uVar6 != 0) {
      puVar8 = (uint *)(iVar4 + 4 + local_c * 4);
      do {
        if (((*puVar8 & 0x3f) != 4) && ((*puVar8 & 0x3f) != 0)) {
          return 0;
        }
        iVar5 = iVar5 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar5 <= (int)uVar6);
    }
    if (param_3 != 0xff) {
      local_c = uVar6 + local_c;
    }
    break;
  case 0x25:
    if ((*(byte *)(param_1 + 0x4a) & 2) == 0) {
      return 0;
    }
    if ((*(byte *)(param_1 + 0x4a) & 4) != 0) {
      return 0;
    }
    if ((uVar12 == 0) && (iVar5 = FUN_006f8240(), iVar5 == 0)) {
      return 0;
    }
    iVar5 = (uVar12 - 2) + uVar10;
    bVar14 = SBORROW4(iVar5,uVar9);
    bVar13 = (int)(iVar5 - uVar9) < 0;
LAB_006f8696:
    if (bVar14 == bVar13) {
      return 0;
    }
  }
switchD_006f8434_caseD_6:
  local_c = local_c + 1;
  if (param_2 <= local_c) {
    return *(undefined4 *)(iVar4 + local_18 * 4);
  }
  goto LAB_006f8343;
switchD_006f8434_caseD_16:
  iVar5 = uVar12 + 1 + local_c;
  if (((param_3 != 0xff) && (local_c < iVar5)) && (iVar5 <= param_2)) {
    local_c = uVar12 + local_c;
  }
  goto switchD_006f8434_caseD_6;
}

