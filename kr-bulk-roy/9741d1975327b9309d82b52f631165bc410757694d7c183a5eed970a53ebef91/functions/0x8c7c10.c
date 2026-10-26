
void FUN_008c7c10(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined2 uVar10;
  int iVar11;
  undefined4 uVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  undefined2 *puVar16;
  bool bVar17;
  uint local_40;
  int local_30;
  int local_28;
  ushort local_24;
  ushort local_22;
  int local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar4 = *(int *)(param_2 + 0x214);
  iVar11 = 0;
  bVar7 = false;
  bVar8 = false;
  if (0 < param_4) {
    do {
      iVar5 = *(int *)(param_5 + iVar11 * 8);
      if (iVar5 == 0x69677066) {
        bVar7 = true;
      }
      else if (iVar5 == 0x69677073) {
        bVar8 = true;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_4);
  }
  if ((*(int *)(*(int *)(param_2 + 0x80) + 0x30) == 0) && (iVar11 = FUN_008c2ad0(), iVar11 == 0)) {
    iVar11 = FUN_008c2ad0();
    bVar9 = false;
    if (iVar11 != 0) goto LAB_008c7c98;
  }
  else {
LAB_008c7c98:
    bVar9 = true;
  }
  bVar17 = false;
  iVar11 = (**(code **)(param_2 + 0x1fc))(param_2,0x73626978,param_1,0);
  if (iVar11 == 0) {
    bVar9 = false;
LAB_008c7ccc:
    if (*(code **)(iVar4 + 0x44) == (code *)0x0) goto LAB_008c7cef;
    local_28 = (**(code **)(iVar4 + 0x44))(param_2,param_1);
    bVar17 = local_28 == 0;
    if ((!bVar17) || (iVar5 = 0, iVar11 == 0)) goto LAB_008c7cef;
  }
  else {
    if (!bVar9) goto LAB_008c7ccc;
LAB_008c7cef:
    local_28 = (**(code **)(iVar4 + 0x18))(param_2,param_1);
    iVar5 = local_28;
    if (local_28 != 0) goto LAB_008c8354;
  }
  local_28 = iVar5;
  if (*(short *)(param_2 + 0xb2) == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_28 = (**(code **)(iVar4 + 0x24))(param_2,param_1);
  local_28 = (**(code **)(iVar4 + 0x20))(param_2,param_1);
  local_28 = (**(code **)(iVar4 + 0x30))(param_2,param_1);
  iVar11 = (**(code **)(iVar4 + 0x2c))(param_2,param_1);
  local_28 = iVar11;
  if (!bVar17) {
    local_28 = (**(code **)(iVar4 + 0x1c))(param_2,param_1,0);
    if (local_28 == 0) {
      local_28 = (**(code **)(iVar4 + 0x5c))(param_2,param_1,0);
      if ((char)local_28 == -0x72) {
        local_28 = 0x93;
        piVar6 = *(int **)(*(int *)(param_2 + 0x80) + 0x30);
        if ((piVar6 == (int *)0x0) || (*(int *)(*piVar6 + 8) == 0)) goto LAB_008c8354;
        *(undefined2 *)(param_2 + 0xfa) = 0;
        local_28 = 0;
      }
      else {
LAB_008c7e12:
        if (local_28 != 0) goto LAB_008c8354;
      }
    }
    else {
      if ((char)local_28 != -0x72) goto LAB_008c7e12;
      if (*(int *)(param_2 + 0x94) == 0x74727565) {
        bVar9 = false;
        local_28 = 0;
      }
      else {
        local_28 = 0x8f;
        piVar6 = *(int **)(*(int *)(param_2 + 0x80) + 0x30);
        if ((piVar6 == (int *)0x0) || (*(int *)(*piVar6 + 8) == 0)) goto LAB_008c8354;
        *(undefined2 *)(param_2 + 0xfa) = 0;
        local_28 = 0;
      }
    }
    local_28 = (**(code **)(iVar4 + 0x1c))(param_2,param_1,1);
    if ((local_28 == 0) &&
       (local_28 = (**(code **)(iVar4 + 0x5c))(param_2,param_1,1), local_28 == 0)) {
      *(undefined1 *)(param_2 + 0x124) = 1;
    }
    else if ((char)local_28 != -0x72) goto LAB_008c8354;
    local_28 = (**(code **)(iVar4 + 0x28))(param_2,param_1);
    if (local_28 != 0) {
      *(undefined2 *)(param_2 + 0x16c) = 0xffff;
    }
  }
  if ((*(code **)(iVar4 + 0x60) != (code *)0x0) &&
     (local_28 = (**(code **)(iVar4 + 0x60))(param_2,param_1), local_28 != 0)) {
    if ((char)local_28 != -0x72) goto LAB_008c8354;
    local_28 = 0;
  }
  local_28 = (**(code **)(iVar4 + 0x40))(param_2,param_1);
  if (local_28 != 0) {
    if ((char)local_28 != -0x72) goto LAB_008c8354;
    *(undefined4 *)(param_2 + 0x224) = 0;
  }
  local_28 = (**(code **)(iVar4 + 0x3c))(param_2,param_1);
  local_28 = (**(code **)(iVar4 + 0x38))(param_2,param_1);
  piVar6 = (int *)(param_2 + 0x14);
  piVar1 = (int *)(param_2 + 0x18);
  *(uint *)(param_2 + 0x10) = (uint)*(ushort *)(param_2 + 0x108);
  *piVar6 = 0;
  *piVar1 = 0;
  if ((*(short *)(param_2 + 0x16c) == -1) || ((*(ushort *)(param_2 + 0x1ac) & 0x100) == 0)) {
    local_28 = FUN_008c7170(param_2,0x15,piVar6);
    if ((local_28 != 0) ||
       (((iVar5 = 0, *piVar6 == 0 &&
         (((!bVar7 &&
           (local_28 = FUN_008c7170(param_2,0x10,piVar6), iVar5 = local_28, local_28 != 0)) ||
          ((local_28 = iVar5, iVar5 = local_28, *piVar6 == 0 &&
           (local_28 = FUN_008c7170(param_2,1,piVar6), iVar5 = local_28, local_28 != 0)))))) ||
        (local_28 = iVar5, local_28 = FUN_008c7170(param_2,0x16,piVar1), local_28 != 0))))
    goto LAB_008c8354;
    if (*piVar1 == 0) goto LAB_008c7fc8;
  }
  else {
    if (((!bVar7) && (local_28 = FUN_008c7170(param_2,0x10,piVar6), local_28 != 0)) ||
       ((*piVar6 == 0 && (local_28 = FUN_008c7170(param_2,1,piVar6), local_28 != 0))))
    goto LAB_008c8354;
LAB_008c7fc8:
    if (((!bVar8) && (local_28 = FUN_008c7170(param_2,0x11,piVar1), local_28 != 0)) ||
       ((*piVar1 == 0 && (local_28 = FUN_008c7170(param_2,2,piVar1), local_28 != 0))))
    goto LAB_008c8354;
  }
  uVar14 = *(uint *)(param_2 + 8);
  if ((*(int *)(param_2 + 0x2dc) == 2) || (*(int *)(param_2 + 0x2dc) == 3)) {
    uVar14 = uVar14 | 0x4000;
  }
  if (bVar9) {
    uVar14 = uVar14 | 1;
  }
  uVar15 = uVar14 | 0x18;
  if ((iVar11 == 0) && (*(int *)(param_2 + 0x1d4) != 0x30000)) {
    uVar15 = uVar14 | 0x218;
  }
  if (*(int *)(param_2 + 0x1e0) != 0) {
    uVar15 = uVar15 | 4;
  }
  if (*(char *)(param_2 + 0x124) != '\0') {
    uVar15 = uVar15 | 0x20;
  }
  if (*(int *)(param_2 + 0x2f0) != 0) {
    uVar15 = uVar15 | 0x40;
  }
  iVar11 = FUN_008c2ad0();
  if (((iVar11 != 0) && (iVar11 = FUN_008c2ad0(), iVar11 != 0)) &&
     (iVar11 = FUN_008c2ad0(), iVar11 != 0)) {
    uVar15 = uVar15 | 0x100;
  }
  uVar14 = 0;
  *(uint *)(param_2 + 8) = uVar15;
  if ((bVar9) && (*(short *)(param_2 + 0x16c) != -1)) {
    uVar2 = *(ushort *)(param_2 + 0x1ac);
    if (((uVar2 & 0x200) != 0) || ((uVar2 & 1) != 0)) {
      uVar14 = 1;
    }
    if ((uVar2 & 0x20) != 0) {
      uVar14 = uVar14 | 2;
    }
  }
  else {
    if ((*(ushort *)(param_2 + 0xcc) & 1) != 0) {
      uVar14 = 2;
    }
    if ((*(ushort *)(param_2 + 0xcc) & 2) != 0) {
      uVar14 = uVar14 | 1;
    }
  }
  *(uint *)(param_2 + 0xc) = uVar14;
  FUN_008c69d0(param_2);
  local_30 = 0;
  if (0 < *(int *)(param_2 + 0x24)) {
    do {
      iVar11 = *(int *)(*(int *)(param_2 + 0x28) + local_30 * 4);
      uVar12 = FUN_008c7390();
      *(undefined4 *)(iVar11 + 4) = uVar12;
      local_30 = local_30 + 1;
    } while (local_30 < *(int *)(param_2 + 0x24));
  }
  uVar14 = *(uint *)(param_2 + 0x2e0);
  if (uVar14 != 0) {
    local_40 = (uint)*(ushort *)(param_2 + 0xb2);
    sVar3 = *(short *)(param_2 + 0x16e);
    if ((*(ushort *)(param_2 + 0xb2) == 0) || (*(short *)(param_2 + 0x16c) == -1)) {
      sVar3 = 1;
      local_40 = 1;
    }
    uVar12 = FUN_008bc7d0(*(undefined4 *)(*(int *)(param_2 + 0x68) + 0x1c),0x10,0,uVar14,0,&local_28
                         );
    *(undefined4 *)(param_2 + 0x20) = uVar12;
    if (local_28 != 0) goto LAB_008c8354;
    if (uVar14 != 0) {
      local_30 = 0;
      uVar15 = 0;
      iVar11 = local_28;
      do {
        local_28 = iVar11;
        puVar16 = (undefined2 *)(*(int *)(param_2 + 0x20) + local_30);
        local_28 = (**(code **)(iVar4 + 0x6c))(param_2,uVar15,&local_24);
        if (local_28 != 0) goto LAB_008c8354;
        *puVar16 = (short)(local_10 >> 6);
        local_30 = local_30 + 0x10;
        uVar15 = uVar15 + 1;
        puVar16[1] = (short)((int)((uint)local_24 * (int)sVar3 + (local_40 >> 1)) / (int)local_40);
        *(uint *)(puVar16 + 4) = (uint)local_24 << 6;
        *(uint *)(puVar16 + 6) = (uint)local_22 << 6;
        *(uint *)(puVar16 + 2) = (uint)local_22 << 6;
        iVar11 = 0;
      } while (uVar15 < uVar14);
    }
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 2;
    *(uint *)(param_2 + 0x1c) = uVar14;
  }
  if ((*(uint *)(param_2 + 8) & 3) == 0) {
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 1;
  }
  if ((*(byte *)(param_2 + 8) & 1) != 0) {
    *(int *)(param_2 + 0x34) = (int)*(short *)(param_2 + 0xc4);
    *(int *)(param_2 + 0x38) = (int)*(short *)(param_2 + 0xc6);
    *(int *)(param_2 + 0x3c) = (int)*(short *)(param_2 + 200);
    *(undefined2 *)(param_2 + 0x44) = *(undefined2 *)(param_2 + 0xb2);
    sVar3 = *(short *)(param_2 + 0xde);
    *(int *)(param_2 + 0x40) = (int)*(short *)(param_2 + 0xca);
    sVar13 = *(short *)(param_2 + 0xdc);
    *(short *)(param_2 + 0x46) = sVar13;
    *(short *)(param_2 + 0x48) = sVar3;
    *(short *)(param_2 + 0x4a) = (*(short *)(param_2 + 0xe0) - sVar3) + sVar13;
    if (((sVar13 == 0) && (sVar3 == 0)) && (*(short *)(param_2 + 0x16c) != -1)) {
      sVar3 = *(short *)(param_2 + 0x1b2);
      if ((sVar3 == 0) && (*(short *)(param_2 + 0x1b4) == 0)) {
        sVar13 = -*(short *)(param_2 + 0x1ba);
        *(short *)(param_2 + 0x46) = *(short *)(param_2 + 0x1b8);
        *(short *)(param_2 + 0x4a) = *(short *)(param_2 + 0x1b8) + *(short *)(param_2 + 0x1ba);
      }
      else {
        sVar13 = *(short *)(param_2 + 0x1b4);
        *(short *)(param_2 + 0x46) = sVar3;
        *(short *)(param_2 + 0x4a) = (*(short *)(param_2 + 0x1b6) - sVar13) + sVar3;
      }
      *(short *)(param_2 + 0x48) = sVar13;
    }
    *(undefined2 *)(param_2 + 0x4c) = *(undefined2 *)(param_2 + 0xe2);
    if (*(char *)(param_2 + 0x124) == '\0') {
      uVar10 = *(undefined2 *)(param_2 + 0x4a);
    }
    else {
      uVar10 = *(undefined2 *)(param_2 + 0x132);
    }
    *(undefined2 *)(param_2 + 0x4e) = uVar10;
    *(short *)(param_2 + 0x50) = *(short *)(param_2 + 0x1dc) - *(short *)(param_2 + 0x1de) / 2;
    *(short *)(param_2 + 0x52) = *(short *)(param_2 + 0x1de);
  }
LAB_008c8354:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

