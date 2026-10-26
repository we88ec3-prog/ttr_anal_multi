
undefined4 FUN_008ef5a0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  ushort uVar11;
  ushort uVar12;
  int local_8;
  
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  if (*(short *)(param_1 + 0xd8) == *(short *)(param_1 + 0xda)) {
    *(code **)(param_1 + 0x250) = FUN_008ec550;
    *(code **)(param_1 + 0x254) = FUN_008ec5c0;
    *(code **)(param_1 + 600) = FUN_008ec610;
  }
  else {
    *(code **)(param_1 + 0x250) = FUN_008ec570;
    *(code **)(param_1 + 0x254) = FUN_008ec5e0;
    *(code **)(param_1 + 600) = FUN_008ec630;
  }
  FUN_008ecda0();
  FUN_008eca80();
  while( true ) {
    iVar6 = *(int *)(param_1 + 0x168);
    bVar3 = *(byte *)(*(int *)(param_1 + 0x164) + iVar6);
    *(byte *)(param_1 + 0x170) = bVar3;
    iVar5 = (int)*(char *)((int)&PTR_Rsrc_Icon_1_412_ImageData_159325__00beae88 + (uint)bVar3);
    *(int *)(param_1 + 0x174) = iVar5;
    if (iVar5 < 0) break;
LAB_008ef66d:
    if (*(int *)(param_1 + 0x16c) < *(int *)(param_1 + 0x174) + *(int *)(param_1 + 0x168))
    goto LAB_008f01fd;
    iVar6 = *(int *)(param_1 + 0x10) -
            (uint)((byte)(&DAT_00bead88)[*(byte *)(param_1 + 0x170)] >> 4);
    *(int *)(param_1 + 0x1c) = iVar6;
    if (iVar6 < 0) {
      if (*(char *)(param_1 + 0x231) != '\0') {
        *(undefined4 *)(param_1 + 0xc) = 0x81;
        goto LAB_008f0204;
      }
      uVar11 = 0;
      if (((&DAT_00bead88)[*(byte *)(param_1 + 0x170)] & 0xf0) != 0) {
        do {
          *(undefined4 *)(*(int *)(param_1 + 0x18) + (uint)uVar11 * 4) = 0;
          uVar11 = uVar11 + 1;
        } while (uVar11 < (byte)(&DAT_00bead88)[*(byte *)(param_1 + 0x170)] >> 4);
      }
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    uVar7 = ((byte)(&DAT_00bead88)[*(byte *)(param_1 + 0x170)] & 0xf) + *(int *)(param_1 + 0x1c);
    *(uint *)(param_1 + 0x20) = uVar7;
    if (*(uint *)(param_1 + 0x14) < uVar7) {
      *(undefined4 *)(param_1 + 0xc) = 0x82;
      goto LAB_008f0204;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    puVar2 = (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c) * 4);
    bVar3 = *(byte *)(param_1 + 0x170);
    *(undefined1 *)(param_1 + 0x178) = 1;
    switch(bVar3) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      uVar11 = (ushort)(bVar3 & 1) << 0xe;
      uVar12 = uVar11 ^ 0x4000;
      if (bVar3 < 4) {
        *(ushort *)(param_1 + 0x126) = uVar11;
        *(ushort *)(param_1 + 0x128) = uVar12;
        *(ushort *)(param_1 + 0x122) = uVar11;
        *(ushort *)(param_1 + 0x124) = uVar12;
      }
      if ((bVar3 & 2) == 0) {
        *(ushort *)(param_1 + 0x12a) = uVar11;
        *(ushort *)(param_1 + 300) = uVar12;
      }
      FUN_008ecda0();
      break;
    case 6:
    case 7:
      cVar4 = FUN_008ecf60(bVar3,(undefined4 *)(param_1 + 0x126));
      if (cVar4 == '\0') {
        *(undefined4 *)(param_1 + 0x122) = *(undefined4 *)(param_1 + 0x126);
        FUN_008ecda0();
      }
      break;
    case 8:
    case 9:
      cVar4 = FUN_008ecf60(bVar3,param_1 + 0x12a);
      if (cVar4 == '\0') {
        FUN_008ecda0();
      }
      break;
    case 10:
      FUN_008ecef0((undefined4 *)(param_1 + 0x126));
      *(undefined4 *)(param_1 + 0x122) = *(undefined4 *)(param_1 + 0x126);
      FUN_008ecda0();
      break;
    case 0xb:
      FUN_008ecef0(param_1 + 0x12a);
      FUN_008ecda0();
      break;
    case 0xc:
      *puVar2 = (int)*(short *)(param_1 + 0x126);
      puVar2[1] = (int)*(short *)(param_1 + 0x128);
      break;
    case 0xd:
      *puVar2 = (int)*(short *)(param_1 + 0x12a);
      puVar2[1] = (int)*(short *)(param_1 + 300);
      break;
    case 0xe:
      *(undefined4 *)(param_1 + 0x12a) = *(undefined4 *)(param_1 + 0x126);
      FUN_008ecda0();
      break;
    case 0xf:
      FUN_008ee9c0();
      break;
    case 0x10:
      *(short *)(param_1 + 0x11c) = (short)*puVar2;
      break;
    case 0x11:
      *(short *)(param_1 + 0x11e) = (short)*puVar2;
      break;
    case 0x12:
      *(short *)(param_1 + 0x120) = (short)*puVar2;
      break;
    case 0x13:
      FUN_008ed9c0();
      break;
    case 0x14:
      FUN_008eda10();
      break;
    case 0x15:
      FUN_008eda60();
      break;
    case 0x16:
      FUN_008edab0();
      break;
    case 0x17:
      if ((int)*puVar2 < 0) {
        *(undefined4 *)(param_1 + 0xc) = 0x84;
      }
      else {
        *(uint *)(param_1 + 0x130) = *puVar2;
      }
      break;
    case 0x18:
      *(undefined4 *)(param_1 + 0x138) = 1;
      *(code **)(param_1 + 0x238) = FUN_008ec8c0;
      break;
    case 0x19:
      *(undefined4 *)(param_1 + 0x138) = 0;
      *(code **)(param_1 + 0x238) = FUN_008ec8f0;
      break;
    case 0x1a:
      *(uint *)(param_1 + 0x134) = *puVar2;
      break;
    case 0x1b:
      FUN_008ed130();
      break;
    case 0x1c:
      if ((*puVar2 == 0) && (*(int *)(param_1 + 0x1c) == 0)) {
        *(undefined4 *)(param_1 + 0xc) = 0x84;
      }
      piVar1 = (int *)(param_1 + 0x168);
      *piVar1 = *piVar1 + *puVar2;
      if ((*piVar1 < 0) ||
         ((0 < *(int *)(param_1 + 0x1ac) &&
          (*(int *)(*(int *)(*(int *)(param_1 + 0x1b4) + -4 + *(int *)(param_1 + 0x1ac) * 0x10) + 8)
           < *(int *)(param_1 + 0x168))))) {
        *(undefined4 *)(param_1 + 0xc) = 0x84;
      }
      *(undefined1 *)(param_1 + 0x178) = 0;
      break;
    case 0x1d:
      *(uint *)(param_1 + 0x140) = *puVar2;
      break;
    case 0x1e:
      *(uint *)(param_1 + 0x144) = *puVar2;
      break;
    case 0x1f:
      uVar8 = FUN_008b7f10(*puVar2,*(undefined4 *)(param_1 + 0x104));
      *(undefined4 *)(param_1 + 0x148) = uVar8;
      break;
    case 0x20:
      puVar2[1] = *puVar2;
      break;
    case 0x21:
    case 0x59:
    case 0x7e:
    case 0x7f:
      break;
    case 0x22:
      *(undefined4 *)(param_1 + 0x20) = 0;
      break;
    case 0x23:
      uVar7 = *puVar2;
      *puVar2 = puVar2[1];
      puVar2[1] = uVar7;
      break;
    case 0x24:
      *puVar2 = *(uint *)(param_1 + 0x10);
      break;
    case 0x25:
      uVar7 = *puVar2;
      if (((int)uVar7 < 1) || (*(int *)(param_1 + 0x1c) < (int)uVar7)) {
        if (*(char *)(param_1 + 0x231) != '\0') {
          *(undefined4 *)(param_1 + 0xc) = 0x86;
        }
        *puVar2 = 0;
      }
      else {
        *puVar2 = *(uint *)(*(int *)(param_1 + 0x18) + (*(int *)(param_1 + 0x1c) - uVar7) * 4);
      }
      break;
    case 0x26:
      FUN_008ecfe0();
      break;
    case 0x27:
      FUN_008eebf0();
      break;
    case 0x28:
    case 0x7b:
    case 0x83:
    case 0x84:
    case 0x8f:
switchD_008ef72d_caseD_28:
      FUN_008ef500();
      break;
    case 0x29:
      FUN_008eef70();
      break;
    case 0x2a:
      FUN_008ed350(puVar2);
      break;
    case 0x2b:
      FUN_008ed290();
      break;
    case 0x2c:
      FUN_008ed160();
      break;
    case 0x2d:
      FUN_008ed230();
      break;
    case 0x2e:
    case 0x2f:
      FUN_008ee2f0();
      break;
    case 0x30:
    case 0x31:
      FUN_008ef130(param_1);
      break;
    case 0x32:
    case 0x33:
      FUN_008edea0();
      break;
    case 0x34:
    case 0x35:
      FUN_008edf50();
      break;
    case 0x36:
    case 0x37:
      FUN_008ee050(param_1);
      break;
    case 0x38:
      FUN_008ee120();
      break;
    case 0x39:
      FUN_008eec80();
      break;
    case 0x3a:
    case 0x3b:
      FUN_008ee1e0(puVar2);
      break;
    case 0x3c:
      FUN_008ee8e0();
      break;
    case 0x3d:
      *(undefined4 *)(param_1 + 0x138) = 2;
      *(code **)(param_1 + 0x238) = FUN_008ec990;
      break;
    case 0x3e:
    case 0x3f:
      FUN_008ee370();
      break;
    case 0x40:
      FUN_008ed4e0(puVar2);
      break;
    case 0x41:
      FUN_008ed560(puVar2);
      break;
    case 0x42:
      if (*puVar2 < (uint)*(ushort *)(param_1 + 0x1d4)) {
        *(uint *)(*(int *)(param_1 + 0x1d8) + *puVar2 * 4) = puVar2[1];
      }
      else {
        cVar4 = *(char *)(param_1 + 0x231);
joined_r0x008efe81:
        if (cVar4 != '\0') {
LAB_008efe87:
          *(undefined4 *)(param_1 + 0xc) = 0x86;
        }
      }
      break;
    case 0x43:
      if (*puVar2 < (uint)*(ushort *)(param_1 + 0x1d4)) {
        *puVar2 = *(uint *)(*(int *)(param_1 + 0x1d8) + *puVar2 * 4);
      }
      else {
LAB_008efba7:
        if (*(char *)(param_1 + 0x231) != '\0') goto LAB_008efe87;
        *puVar2 = 0;
      }
      break;
    case 0x44:
      if (*(uint *)(param_1 + 0x17c) <= *puVar2) {
        cVar4 = *(char *)(param_1 + 0x231);
        goto joined_r0x008efe81;
      }
      (**(code **)(param_1 + 0x254))(param_1,*puVar2,puVar2[1]);
      break;
    case 0x45:
      if (*(uint *)(param_1 + 0x17c) <= *puVar2) goto LAB_008efba7;
      uVar7 = (**(code **)(param_1 + 0x250))(param_1,*puVar2);
      *puVar2 = uVar7;
      break;
    case 0x46:
    case 0x47:
      FUN_008ed690();
      break;
    case 0x48:
      FUN_008ed6f0(puVar2);
      break;
    case 0x49:
    case 0x4a:
      FUN_008ed780(puVar2);
      break;
    case 0x4b:
    case 0x4c:
      uVar7 = FUN_008ec500();
      *puVar2 = uVar7;
      break;
    case 0x4d:
      *(undefined1 *)(param_1 + 0x13c) = 1;
      break;
    case 0x4e:
      *(undefined1 *)(param_1 + 0x13c) = 0;
      break;
    case 0x4f:
      *(undefined4 *)(param_1 + 0xc) = 0x87;
      break;
    case 0x50:
      *puVar2 = (uint)((int)*puVar2 < (int)puVar2[1]);
      break;
    case 0x51:
      *puVar2 = (uint)((int)*puVar2 <= (int)puVar2[1]);
      break;
    case 0x52:
      *puVar2 = (uint)((int)puVar2[1] < (int)*puVar2);
      break;
    case 0x53:
      *puVar2 = (uint)((int)puVar2[1] <= (int)*puVar2);
      break;
    case 0x54:
      *puVar2 = (uint)(*puVar2 == puVar2[1]);
      break;
    case 0x55:
      *puVar2 = (uint)(*puVar2 != puVar2[1]);
      break;
    case 0x56:
      bVar3 = (**(code **)(param_1 + 0x238))(param_1,*puVar2,0);
      *puVar2 = (uint)((bVar3 & 0x7f) == 0x40);
      break;
    case 0x57:
      uVar7 = (**(code **)(param_1 + 0x238))(param_1,*puVar2,0);
      *puVar2 = (uint)((uVar7 & 0x7f) == 0);
      break;
    case 0x58:
      FUN_008ed0e0();
      break;
    case 0x5a:
      if ((*puVar2 == 0) || (puVar2[1] == 0)) {
        *puVar2 = 0;
      }
      else {
        *puVar2 = 1;
      }
      break;
    case 0x5b:
      if ((*puVar2 == 0) && (puVar2[1] == 0)) {
        *puVar2 = 0;
      }
      else {
        *puVar2 = 1;
      }
      break;
    case 0x5c:
      *puVar2 = (uint)(*puVar2 == 0);
      break;
    case 0x5d:
    case 0x71:
    case 0x72:
      FUN_008ef2a0();
      break;
    case 0x5e:
      *(short *)(param_1 + 0x14c) = (short)*puVar2;
      break;
    case 0x5f:
      *(short *)(param_1 + 0x14e) = (short)*puVar2;
      break;
    case 0x60:
      *puVar2 = *puVar2 + puVar2[1];
      break;
    case 0x61:
      *puVar2 = *puVar2 - puVar2[1];
      break;
    case 0x62:
      if (puVar2[1] == 0) {
        *(undefined4 *)(param_1 + 0xc) = 0x85;
      }
      else {
        uVar7 = FUN_008b7e80(*puVar2,0x40,puVar2[1]);
        *puVar2 = uVar7;
      }
      break;
    case 99:
      uVar7 = FUN_008b7dc0(*puVar2,puVar2[1],0x40);
      *puVar2 = uVar7;
      break;
    case 100:
      uVar7 = *puVar2;
      if ((int)uVar7 < 0) {
        uVar7 = -uVar7;
      }
      *puVar2 = uVar7;
      break;
    case 0x65:
      *puVar2 = -*puVar2;
      break;
    case 0x66:
      *puVar2 = *puVar2 & 0xffffffc0;
      break;
    case 0x67:
      *puVar2 = *puVar2 + 0x3f & 0xffffffc0;
      break;
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
      uVar7 = (**(code **)(param_1 + 0x238))
                        (param_1,*puVar2,*(undefined4 *)(param_1 + -0x98 + (uint)bVar3 * 4));
      *puVar2 = uVar7;
      break;
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
      uVar7 = FUN_008ec890(param_1,*puVar2,*(undefined4 *)(param_1 + -0xa8 + (uint)bVar3 * 4));
      *puVar2 = uVar7;
      break;
    case 0x70:
      uVar7 = *puVar2;
      if (*(uint *)(param_1 + 0x17c) <= uVar7) {
        cVar4 = *(char *)(param_1 + 0x231);
        goto joined_r0x008efe81;
      }
      uVar8 = FUN_008b7f10(puVar2[1],*(undefined4 *)(param_1 + 0x104));
      *(undefined4 *)(*(int *)(param_1 + 0x180) + uVar7 * 4) = uVar8;
      break;
    case 0x73:
    case 0x74:
    case 0x75:
      FUN_008ef3b0();
      break;
    case 0x76:
      FUN_008ecb10();
      *(undefined4 *)(param_1 + 0x138) = 6;
      *(code **)(param_1 + 0x238) = FUN_008ec9c0;
      break;
    case 0x77:
      FUN_008ecb10();
      *(undefined4 *)(param_1 + 0x138) = 7;
      *(code **)(param_1 + 0x238) = FUN_008eca20;
      break;
    case 0x78:
      if (puVar2[1] != 0) {
        if ((*puVar2 == 0) && (*(int *)(param_1 + 0x1c) == 0)) {
          *(undefined4 *)(param_1 + 0xc) = 0x84;
        }
        piVar1 = (int *)(param_1 + 0x168);
        *piVar1 = *piVar1 + *puVar2;
        if ((*piVar1 < 0) ||
           ((0 < *(int *)(param_1 + 0x1ac) &&
            (*(int *)(*(int *)(*(int *)(param_1 + 0x1b4) + -4 + *(int *)(param_1 + 0x1ac) * 0x10) +
                     8) < *(int *)(param_1 + 0x168))))) {
          *(undefined4 *)(param_1 + 0xc) = 0x84;
        }
        *(undefined1 *)(param_1 + 0x178) = 0;
      }
      break;
    case 0x79:
      if (puVar2[1] == 0) {
        if ((*puVar2 == 0) && (*(int *)(param_1 + 0x1c) == 0)) {
          *(undefined4 *)(param_1 + 0xc) = 0x84;
        }
        piVar1 = (int *)(param_1 + 0x168);
        *piVar1 = *piVar1 + *puVar2;
        if ((*piVar1 < 0) ||
           ((0 < *(int *)(param_1 + 0x1ac) &&
            (*(int *)(*(int *)(*(int *)(param_1 + 0x1b4) + -4 + *(int *)(param_1 + 0x1ac) * 0x10) +
                     8) < *(int *)(param_1 + 0x168))))) {
          *(undefined4 *)(param_1 + 0xc) = 0x84;
        }
        *(undefined1 *)(param_1 + 0x178) = 0;
      }
      break;
    case 0x7a:
      *(undefined4 *)(param_1 + 0x138) = 5;
      *(code **)(param_1 + 0x238) = FUN_008ec890;
      break;
    case 0x7c:
      *(undefined4 *)(param_1 + 0x138) = 4;
      *(code **)(param_1 + 0x238) = FUN_008ec960;
      break;
    case 0x7d:
      *(undefined4 *)(param_1 + 0x138) = 3;
      *(code **)(param_1 + 0x238) = FUN_008ec930;
      break;
    case 0x80:
      FUN_008edc40();
      break;
    case 0x81:
      FUN_008edcd0();
      break;
    case 0x82:
      FUN_008edd20();
      break;
    case 0x85:
      FUN_008edb70();
      break;
    case 0x86:
    case 0x87:
      FUN_008ed8d0();
      break;
    case 0x88:
      FUN_008ef4b0();
      break;
    case 0x89:
      FUN_008ed420();
      break;
    case 0x8a:
      FUN_008ed030();
      break;
    case 0x8b:
      if ((int)*puVar2 < (int)puVar2[1]) {
        *puVar2 = puVar2[1];
      }
      break;
    case 0x8c:
      if ((int)puVar2[1] < (int)*puVar2) {
        *puVar2 = puVar2[1];
      }
      break;
    case 0x8d:
      FUN_008edc30();
      break;
    case 0x8e:
      FUN_008edb30();
      break;
    default:
      if (bVar3 < 0xe0) {
        if (bVar3 < 0xc0) {
          if (bVar3 < 0xb8) {
            if (bVar3 < 0xb0) goto switchD_008ef72d_caseD_28;
            FUN_008ed5d0(puVar2);
          }
          else {
            FUN_008ed630(puVar2);
          }
        }
        else {
          FUN_008ee4a0();
        }
      }
      else {
        FUN_008ee6a0();
      }
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      if (*(char *)(param_1 + 0x178) != '\0') {
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + *(int *)(param_1 + 0x174);
      }
      local_8 = local_8 + 1;
      if (1000000 < local_8) {
        return 0x8b;
      }
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0x80) goto LAB_008f0204;
      uVar9 = *(uint *)(param_1 + 0x1a0);
      uVar7 = uVar9 + *(int *)(param_1 + 0x198) * 0x18;
      while( true ) {
        if (uVar7 <= uVar9) {
          *(undefined4 *)(param_1 + 0xc) = 0x80;
          goto LAB_008f0204;
        }
        if ((*(char *)(uVar9 + 0x10) != '\0') &&
           (*(char *)(param_1 + 0x170) == *(char *)(uVar9 + 0xc))) break;
        uVar9 = uVar9 + 0x18;
      }
      if (*(int *)(param_1 + 0x1b0) <= *(int *)(param_1 + 0x1ac)) {
        *(undefined4 *)(param_1 + 0xc) = 0x86;
        goto LAB_008f0204;
      }
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x1ac) * 0x10 + *(int *)(param_1 + 0x1b4));
      *puVar10 = *(undefined4 *)(param_1 + 0x160);
      iVar6 = *(int *)(param_1 + 0x168);
      puVar10[3] = uVar9;
      puVar10[1] = iVar6 + 1;
      puVar10[2] = 1;
      cVar4 = FUN_008ec690();
      if (cVar4 == '\x01') goto LAB_008f0204;
    }
    if (*(int *)(param_1 + 0x16c) <= *(int *)(param_1 + 0x168)) {
      if (*(int *)(param_1 + 0x1ac) < 1) {
        return 0;
      }
      goto LAB_008f01fd;
    }
    if (*(char *)(param_1 + 0x1e8) != '\0') {
      return 0;
    }
  }
  if (iVar6 + 1 < *(int *)(param_1 + 0x16c)) {
    *(uint *)(param_1 + 0x174) = 2 - (uint)*(byte *)(*(int *)(param_1 + 0x164) + 1 + iVar6) * iVar5;
    goto LAB_008ef66d;
  }
LAB_008f01fd:
  *(undefined4 *)(param_1 + 0xc) = 0x83;
LAB_008f0204:
  if ((*(int *)(param_1 + 0xc) != 0) && (*(char *)(param_1 + 0x1e8) == '\0')) {
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x12d) = 0;
  }
  return *(undefined4 *)(param_1 + 0xc);
}

