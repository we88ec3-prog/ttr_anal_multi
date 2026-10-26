
int FUN_008d22e0(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint local_2c;
  byte *local_28;
  int local_24;
  undefined4 *local_20;
  byte *local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar9 = param_1;
  uVar6 = (uint)&local_2c ^ (uint)&param_1 ^ (uint)&param_2;
  local_2c = ((int)((int)uVar6 >> 10 ^ uVar6) >> 10 ^ uVar6) & 0xffff;
  local_8 = param_1;
  local_14 = 0;
  local_24 = 0;
  if (local_2c == 0) {
    local_2c = 0x7384;
  }
  *(int *)(param_1 + 0x470) = param_1 + 0x70;
  *(int *)(param_1 + 0x540) = param_1 + 0x474;
  local_20 = *(undefined4 **)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x40) = 0;
  puVar11 = (undefined4 *)(param_1 + 0x474);
  if ((*(int *)(param_1 + 0x5d0) != 0) && (*(int *)(param_1 + 0x5d4) != 0)) {
    _memset(*(void **)(param_1 + 0x5d0),0,*(int *)(param_1 + 0x5d4) * 4);
  }
  *(int *)(iVar9 + 0x478) = param_2;
  local_28 = (byte *)(param_2 + param_3);
  *(byte **)(iVar9 + 0x47c) = local_28;
  pbVar13 = *(byte **)(iVar9 + 0x478);
  *puVar11 = pbVar13;
  local_c = *(uint *)(iVar9 + 0x18);
  local_10 = *(uint *)(iVar9 + 0x1c);
  local_18 = 0;
  if (local_20 != (undefined4 *)0x0) {
    (*(code *)local_20[1])(*local_20);
  }
  param_3 = param_3 & 0xffffff;
  if (local_28 <= pbVar13) {
    return local_18;
  }
  do {
    iVar2 = local_8;
    piVar4 = *(int **)(param_1 + 0x470);
    pbVar12 = pbVar13 + 1;
    uVar6 = 0;
    iVar9 = 0;
    local_1c = pbVar12;
    switch(*pbVar13) {
    case 1:
      uVar6 = 0x10;
      break;
    default:
      bVar3 = *pbVar13;
      if (bVar3 < 0x20) {
        return 0xa0;
      }
      if (bVar3 < 0xf7) {
        iVar9 = bVar3 - 0x8b;
      }
      else {
        local_1c = pbVar13 + 2;
        if (local_28 < local_1c) {
          return 0xa0;
        }
        bVar3 = *pbVar13;
        if (bVar3 < 0xfb) {
          iVar9 = (pbVar13[1] - 0xf694) + (uint)bVar3 * 0x100;
        }
        else {
          iVar9 = ((uint)bVar3 * -0x100 - (uint)pbVar13[1]) + 0xfa94;
        }
      }
LAB_008d25c3:
      if (param_3._3_1_ == '\0') {
        iVar9 = iVar9 << 0x10;
      }
      break;
    case 3:
      uVar6 = 0x12;
      break;
    case 4:
      uVar6 = 0xe;
      break;
    case 5:
      uVar6 = 9;
      break;
    case 6:
      uVar6 = 6;
      break;
    case 7:
      uVar6 = 0xd;
      break;
    case 8:
      uVar6 = 0xb;
      break;
    case 9:
      uVar6 = 5;
      break;
    case 10:
      uVar6 = 0x16;
      break;
    case 0xb:
      uVar6 = 0x18;
      break;
    case 0xc:
      if (local_28 < pbVar12) {
        return 0xa0;
      }
      local_1c = pbVar13 + 2;
      switch(*pbVar12) {
      case 0:
        uVar6 = 0xf;
        break;
      case 1:
        uVar6 = 0x13;
        break;
      case 2:
        uVar6 = 0x11;
        break;
      default:
        goto switchD_008d24c9_caseD_3;
      case 6:
        uVar6 = 3;
        break;
      case 7:
        uVar6 = 4;
        break;
      case 0xc:
        uVar6 = 0x14;
        break;
      case 0x10:
        uVar6 = 0x15;
        break;
      case 0x11:
        uVar6 = 0x17;
        break;
      case 0x21:
        uVar6 = 0x19;
      }
      break;
    case 0xd:
      uVar6 = 2;
      break;
    case 0xe:
      uVar6 = 1;
      break;
    case 0xf:
      uVar6 = 0x1a;
      break;
    case 0x15:
      uVar6 = 10;
      break;
    case 0x16:
      uVar6 = 7;
      break;
    case 0x1e:
      uVar6 = 0xc;
      break;
    case 0x1f:
      uVar6 = 8;
      break;
    case 0xff:
      local_1c = pbVar13 + 5;
      if (local_28 < local_1c) {
        return 0xa0;
      }
      iVar9 = CONCAT31(CONCAT21(CONCAT11(*pbVar12,pbVar13[2]),pbVar13[3]),pbVar13[4]);
      if (iVar9 + 32000U < 0xfa01) goto LAB_008d25c3;
      if (param_3._3_1_ == '\0') {
        param_3 = CONCAT13(1,(undefined3)param_3);
      }
    }
    pbVar13 = local_1c;
    if (((0 < local_24) && (uVar6 != 0)) && ((uVar6 < 0x16 || (0x18 < uVar6)))) {
      local_24 = 0;
    }
    if (param_3._3_1_ != '\0') {
      if (uVar6 != 0) {
        if (uVar6 != 0x14) {
          param_3 = param_3 & 0xffffff;
        }
        goto LAB_008d25f9;
      }
LAB_008d25fd:
      if (0x3ff < (int)((int)piVar4 + (-0x70 - param_1) & 0xfffffffcU)) {
switchD_008d24c9_caseD_3:
        return 0xa0;
      }
      *piVar4 = iVar9;
      *(int **)(param_1 + 0x470) = piVar4 + 1;
      goto LAB_008d3039;
    }
LAB_008d25f9:
    if (uVar6 == 0) goto LAB_008d25fd;
    if (uVar6 != 0x15) {
      if ((int)piVar4 + (-0x70 - param_1) >> 2 < (int)(&DAT_00be7cc8)[uVar6]) {
        return 0xa1;
      }
      if (0x19 < uVar6 - 1) {
        return 0xa0;
      }
      iVar9 = (*(code *)(&PTR_LAB_008d32e0)[uVar6 - 1])();
      return iVar9;
    }
    if ((int)((int)piVar4 + (-0x70 - param_1) & 0xfffffffcU) < 8) {
      return 0xa1;
    }
    iVar7 = (int)*(short *)((int)piVar4 + -6);
    iVar9 = (int)*(short *)((int)piVar4 + -2);
    if ((int)piVar4 + (-0x78 - param_1) >> 2 < iVar7) {
      return 0xa1;
    }
    puVar1 = (uint *)(piVar4 + (-2 - iVar7));
    local_14 = 0;
    local_24 = 0;
    switch(iVar9) {
    case 0:
      if (iVar7 != 3) {
        return 0xa0;
      }
      if (*(int *)(param_1 + 0x578) == 0) {
        return 0xa0;
      }
      if (*(int *)(param_1 + 0x57c) != 7) {
        return 0xa0;
      }
      *puVar1 = local_c;
      local_14 = 2;
      puVar1[1] = local_10;
      *(uint **)(param_1 + 0x470) = puVar1 + 2;
      break;
    case 1:
      if (iVar7 != 0) {
        return 0xa0;
      }
      *(undefined4 *)(param_1 + 0x578) = 1;
      *(undefined4 *)(param_1 + 0x57c) = 0;
      local_18 = FUN_008d0b90(local_8,local_c,local_10);
      if (local_18 != 0) {
        return local_18;
      }
      local_18 = FUN_008d0a40(iVar2,6);
      if (local_18 != 0) {
        return local_18;
      }
      goto LAB_008d2b00;
    case 2:
      if (iVar7 != 0) {
        return 0xa0;
      }
      if (*(int *)(param_1 + 0x578) == 0) {
        return 0xa0;
      }
      uVar6 = *(uint *)(param_1 + 0x57c);
      *(uint *)(param_1 + 0x57c) = uVar6 + 1;
      if (5 < uVar6 - 1) goto LAB_008d2b00;
      if ((uVar6 == 3) || (uVar6 == 6)) {
        uVar6 = 1;
      }
      else {
        uVar6 = uVar6 & 0xffffff00;
      }
      FUN_008d0a80(local_8,local_c,local_10,uVar6);
      *(uint **)(param_1 + 0x470) = puVar1 + local_14;
      break;
    case 3:
      if (iVar7 != 1) {
        return 0xa0;
      }
      local_14 = iVar7;
      if (local_20 == (undefined4 *)0x0) goto LAB_008d2b00;
      (*(code *)local_20[5])(*local_20,(int)*(short *)(*(int *)(local_8 + 0x14) + 2));
      *(uint **)(param_1 + 0x470) = puVar1 + local_14;
      break;
    default:
      if (iVar7 < 0) {
        return 0xa0;
      }
      local_24 = iVar7;
      if (iVar9 < 0) {
        return 0xa0;
      }
LAB_008d2b00:
      *(uint **)(param_1 + 0x470) = puVar1 + local_14;
      break;
    case 0xc:
    case 0xd:
      *(int *)(param_1 + 0x470) = param_1 + 0x70;
      break;
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
      puVar5 = *(uint **)(param_1 + 0x5b8);
      if (puVar5 == (uint *)0x0) {
        return 0xa0;
      }
      iVar9 = ((iVar9 == 0x12) - 0xd) + iVar9;
      if (iVar7 != *puVar5 * iVar9) {
        return 0xa0;
      }
      puVar10 = puVar1 + iVar9;
      puVar8 = puVar1;
      for (iVar2 = iVar9; iVar2 != 0; iVar2 = iVar2 + -1) {
        local_14 = *puVar8;
        uVar6 = 1;
        local_1c = pbVar13;
        if (1 < *puVar5) {
          do {
            iVar7 = FUN_008b7f10(*puVar10,*(undefined4 *)(puVar5[0x22] + uVar6 * 4));
            local_14 = local_14 + iVar7;
            uVar6 = uVar6 + 1;
            puVar10 = puVar10 + 1;
          } while (uVar6 < *puVar5);
        }
        *puVar8 = local_14;
        puVar8 = puVar8 + 1;
        pbVar13 = local_1c;
      }
      *(uint **)(param_1 + 0x470) = puVar1 + iVar9;
      local_14 = iVar9;
      break;
    case 0x13:
      piVar4 = *(int **)(param_1 + 0x5b8);
      if (iVar7 != 1) {
        return 0xa0;
      }
      if (piVar4 == (int *)0x0) {
        return 0xa0;
      }
      iVar9 = (int)*(short *)((int)puVar1 + 2);
      if (iVar9 < 0) {
        return 0xa0;
      }
      if (*(uint *)(param_1 + 0x5d4) < (uint)(iVar9 + *piVar4)) {
        return 0xa0;
      }
      FID_conflict__memcpy
                ((void *)(*(int *)(param_1 + 0x5d0) + iVar9 * 4),(void *)piVar4[0x22],*piVar4 * 4);
      *(uint **)(param_1 + 0x470) = puVar1 + local_14;
      pbVar13 = local_1c;
      break;
    case 0x14:
      if (iVar7 != 2) {
        return 0xa0;
      }
      *puVar1 = *puVar1 + puVar1[1];
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x15:
      if (iVar7 != 2) {
        return 0xa0;
      }
      *puVar1 = *puVar1 - puVar1[1];
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x16:
      if (iVar7 != 2) {
        return 0xa0;
      }
      uVar6 = FUN_008b7f10(*puVar1,puVar1[1]);
      *puVar1 = uVar6;
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x17:
      if (iVar7 != 2) {
        return 0xa0;
      }
      if (puVar1[1] == 0) {
        return 0xa0;
      }
      uVar6 = FUN_008b7f40(*puVar1,puVar1[1]);
      *puVar1 = uVar6;
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x18:
      if (iVar7 != 2) {
        return 0xa0;
      }
      if (*(int *)(param_1 + 0x5b8) == 0) {
        return 0xa0;
      }
      uVar6 = (uint)*(short *)((int)puVar1 + 6);
      if ((int)uVar6 < 0) {
        return 0xa0;
      }
      if (*(uint *)(param_1 + 0x5d4) <= uVar6) {
        return 0xa0;
      }
      *(uint *)(*(int *)(param_1 + 0x5d0) + uVar6 * 4) = *puVar1;
      *(uint **)(param_1 + 0x470) = puVar1;
      break;
    case 0x19:
      if (iVar7 != 1) {
        return 0xa0;
      }
      if (*(int *)(param_1 + 0x5b8) == 0) {
        return 0xa0;
      }
      uVar6 = (uint)*(short *)((int)puVar1 + 2);
      if ((int)uVar6 < 0) {
        return 0xa0;
      }
      if (*(uint *)(param_1 + 0x5d4) <= uVar6) {
        return 0xa0;
      }
      local_14 = 1;
      *puVar1 = *(uint *)(*(int *)(param_1 + 0x5d0) + uVar6 * 4);
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x1b:
      if (iVar7 != 4) {
        return 0xa0;
      }
      if ((int)puVar1[3] < (int)puVar1[2]) {
        *puVar1 = puVar1[1];
      }
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
      break;
    case 0x1c:
      if (iVar7 != 0) {
        return 0xa0;
      }
      uVar6 = local_2c;
      if (0x7fff < (int)local_2c) {
        uVar6 = local_2c + 1;
      }
      *puVar1 = uVar6;
      local_2c = FUN_008b7f10(local_2c,0x10000 - local_2c);
      if (local_2c == 0) {
        local_2c = 0x2873;
      }
      local_14 = 1;
      *(uint **)(param_1 + 0x470) = puVar1 + 1;
    }
LAB_008d3039:
    if (local_28 <= pbVar13) {
      return local_18;
    }
  } while( true );
}

