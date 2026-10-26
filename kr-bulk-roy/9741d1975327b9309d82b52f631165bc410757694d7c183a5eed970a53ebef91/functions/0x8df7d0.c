
int FUN_008df7d0(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  char *pcVar11;
  int *piVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  byte *pbVar16;
  bool bVar17;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  int local_14;
  uint local_10;
  uint local_c;
  char local_5;
  
  puVar7 = param_2;
  piVar12 = *(int **)(param_2[0x18] + 4);
  local_10 = CONCAT31(local_10._1_3_,1);
  local_5 = '\0';
  local_18 = piVar12;
  iVar8 = FUN_008b8fc0(piVar12,&DAT_00bd7d94);
  if (iVar8 == 0) {
    return 0xb;
  }
  local_c = FUN_008b8ff0(puVar7[0x18],"postscript-cmaps");
  local_14 = FUN_008b8fc0(piVar12,"pshinter");
  param_2 = (undefined4 *)FUN_008b97e0(param_1,0);
  if (param_2 != (undefined4 *)0x0) {
    return (int)param_2;
  }
  param_2 = (undefined4 *)(**(code **)(iVar8 + 4))(param_1,puVar7,param_3,param_4,param_5);
  if (param_2 == (undefined4 *)0x0) {
    if (puVar7[0x25] != 0x4f54544f) {
      return 2;
    }
    if (param_3 < 0) {
      return 0;
    }
    local_5 = '\x01';
    param_2 = (undefined4 *)(*(code *)puVar7[0x7f])(puVar7,0x68656164,param_1,0);
    if (param_2 == (undefined4 *)0x0) {
      local_10 = local_10 & 0xffffff00;
      param_2 = (undefined4 *)(**(code **)(iVar8 + 8))(param_1,puVar7,param_3,param_4,param_5);
    }
    else {
      param_2 = (undefined4 *)(**(code **)(iVar8 + 0x20))(puVar7,param_1);
    }
    if (param_2 != (undefined4 *)0x0) {
      return (int)param_2;
    }
    param_2 = (undefined4 *)(*(code *)puVar7[0x7f])(puVar7,0x43464620,param_1,0);
  }
  else {
    param_2 = (undefined4 *)FUN_008b97e0(param_1,0);
  }
  if (param_2 != (undefined4 *)0x0) {
    return (int)param_2;
  }
  local_1c = puVar7[0x19];
  iVar8 = FUN_008baee0(local_1c,0xba4,&param_2);
  if (param_2 != (undefined4 *)0x0) {
    return (int)param_2;
  }
  puVar7[0xa4] = iVar8;
  param_2 = (undefined4 *)FUN_008deb20(local_18,param_1,param_3,local_10);
  if (param_2 != (undefined4 *)0x0) {
    return (int)param_2;
  }
  *(int *)(iVar8 + 0xb88) = local_14;
  *(uint *)(iVar8 + 0xb8c) = local_c;
  puVar7[1] = param_3;
  puVar7[4] = *(undefined4 *)(iVar8 + 0xc);
  if ((*(int *)(iVar8 + 0x5b0) == 0xffff) && (local_c == 0)) {
    return 0xb;
  }
  if (*(char *)(iVar8 + 0x56c) == '\0') {
    uVar9 = 1000;
    if ((char)local_10 == '\0') {
      uVar9 = (uint)*(ushort *)(puVar7 + 0x11);
    }
    *(uint *)(iVar8 + 0x570) = uVar9;
  }
  iVar15 = *(int *)(iVar8 + 0x568);
  if (iVar15 < 0) {
    iVar15 = -iVar15;
  }
  if (iVar15 != 0x10000) {
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x570),iVar15);
    *(undefined4 *)(iVar8 + 0x570) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x55c),iVar15);
    *(undefined4 *)(iVar8 + 0x55c) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x564),iVar15);
    *(undefined4 *)(iVar8 + 0x564) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x560),iVar15);
    *(undefined4 *)(iVar8 + 0x560) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x568),iVar15);
    *(undefined4 *)(iVar8 + 0x568) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x574),iVar15);
    *(undefined4 *)(iVar8 + 0x574) = uVar10;
    uVar10 = FUN_008b7f40(*(undefined4 *)(iVar8 + 0x578),iVar15);
    *(undefined4 *)(iVar8 + 0x578) = uVar10;
  }
  *(int *)(iVar8 + 0x574) = (int)*(short *)(iVar8 + 0x576);
  *(int *)(iVar8 + 0x578) = (int)*(short *)(iVar8 + 0x57a);
  local_14 = *(int *)(iVar8 + 0x768);
  if (local_14 != 0) {
    local_18 = (int *)(iVar8 + 0x768 + local_14 * 4);
    do {
      iVar15 = *local_18;
      if (*(char *)(iVar15 + 0x40) == '\0') {
        *(undefined4 *)(iVar15 + 0x30) = *(undefined4 *)(iVar8 + 0x55c);
        *(undefined4 *)(iVar15 + 0x34) = *(undefined4 *)(iVar8 + 0x560);
        *(undefined4 *)(iVar15 + 0x38) = *(undefined4 *)(iVar8 + 0x564);
        *(undefined4 *)(iVar15 + 0x3c) = *(undefined4 *)(iVar8 + 0x568);
        *(undefined4 *)(iVar15 + 0x48) = *(undefined4 *)(iVar8 + 0x574);
        *(undefined4 *)(iVar15 + 0x4c) = *(undefined4 *)(iVar8 + 0x578);
        *(undefined4 *)(iVar15 + 0x44) = *(undefined4 *)(iVar8 + 0x570);
      }
      else if (*(char *)(iVar8 + 0x56c) != '\0') {
        uVar9 = *(uint *)(iVar8 + 0x570);
        if ((uVar9 < 2) || (local_c = *(uint *)(iVar15 + 0x44), local_c < 2)) {
          local_c = 1;
        }
        else if (uVar9 < local_c) {
          local_c = uVar9;
        }
        FUN_008b8050(iVar8 + 0x55c,iVar15 + 0x30,local_c);
        FUN_008b8140(iVar15 + 0x48,iVar8 + 0x55c,local_c);
        uVar10 = FUN_008b7dc0(*(undefined4 *)(iVar15 + 0x44),*(undefined4 *)(iVar8 + 0x570),local_c)
        ;
        *(undefined4 *)(iVar15 + 0x44) = uVar10;
      }
      local_c = *(uint *)(iVar15 + 0x3c);
      if ((int)local_c < 0) {
        local_c = -local_c;
      }
      if (local_c != 0x10000) {
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x44),local_c);
        *(undefined4 *)(iVar15 + 0x44) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x30),local_c);
        *(undefined4 *)(iVar15 + 0x30) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x38),local_c);
        *(undefined4 *)(iVar15 + 0x38) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x34),local_c);
        *(undefined4 *)(iVar15 + 0x34) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x3c),local_c);
        *(undefined4 *)(iVar15 + 0x3c) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x48),local_c);
        *(undefined4 *)(iVar15 + 0x48) = uVar10;
        uVar10 = FUN_008b7f40(*(undefined4 *)(iVar15 + 0x4c),local_c);
        *(undefined4 *)(iVar15 + 0x4c) = uVar10;
      }
      local_18 = local_18 + -1;
      *(int *)(iVar15 + 0x4c) = (int)*(short *)(iVar15 + 0x4e);
      local_14 = local_14 + -1;
      *(int *)(iVar15 + 0x48) = (int)*(short *)(iVar15 + 0x4a);
    } while (local_14 != 0);
  }
  if ((char)local_10 == '\0') goto LAB_008dfeaf;
  *puVar7 = *(undefined4 *)(iVar8 + 8);
  if (*(int *)(iVar8 + 0x5b0) == 0xffff) {
    puVar7[4] = *(undefined4 *)(iVar8 + 0x4a0);
  }
  else {
    puVar7[4] = *(int *)(iVar8 + 0x490) + 1;
  }
  puVar7[0xd] = (int)*(short *)(iVar8 + 0x582);
  puVar7[0xe] = (int)*(short *)(iVar8 + 0x586);
  puVar7[0xf] = *(int *)(iVar8 + 0x588) + 0xffff >> 0x10;
  iVar15 = *(int *)(iVar8 + 0x58c) + 0xffff;
  puVar7[0x10] = iVar15 >> 0x10;
  uVar4 = *(ushort *)(iVar8 + 0x570);
  *(ushort *)(puVar7 + 0x11) = uVar4;
  sVar6 = (short)(((uint)uVar4 * 0xc) / 10);
  sVar5 = (short)((uint)iVar15 >> 0x10);
  *(short *)(puVar7 + 0x12) = *(short *)(puVar7 + 0xe);
  *(short *)((int)puVar7 + 0x4a) = sVar6;
  *(short *)((int)puVar7 + 0x46) = sVar5;
  if ((int)sVar6 < (int)sVar5 - (int)*(short *)(puVar7 + 0xe)) {
    *(short *)((int)puVar7 + 0x4a) = sVar5 - *(short *)(puVar7 + 0xe);
  }
  *(undefined2 *)(puVar7 + 0x14) = *(undefined2 *)(iVar8 + 0x54e);
  *(undefined2 *)((int)puVar7 + 0x52) = *(undefined2 *)(iVar8 + 0x552);
  iVar15 = FUN_008ddf90(param_3);
  puVar7[5] = iVar15;
  if (iVar15 == 0) {
    iVar15 = FUN_008de030();
    if (iVar15 != 0) {
      uVar10 = FUN_008df670();
      puVar7[5] = uVar10;
    }
  }
  else {
    pcVar11 = (char *)FUN_008de030();
    local_18 = (int *)puVar7[5];
    FUN_008df690();
    if ((*(int *)(iVar8 + 0x53c) == 0) || (piVar12 = (int *)FUN_008de030(), piVar12 == (int *)0x0))
    {
      piVar12 = local_18;
    }
    if ((pcVar11 != (char *)0x0) && (piVar12 != (int *)0x0)) {
      cVar1 = *pcVar11;
      while (cVar1 != '\0') {
        cVar1 = *pcVar11;
        cVar2 = (char)*piVar12;
        if (cVar1 == cVar2) {
          piVar12 = (int *)((int)piVar12 + 1);
LAB_008dfd1e:
          pcVar11 = pcVar11 + 1;
        }
        else {
          if ((cVar1 == ' ') || (cVar1 == '-')) goto LAB_008dfd1e;
          if ((cVar2 != ' ') && (cVar2 != '-')) {
            if (((char)*piVar12 == '\0') && (*pcVar11 != '\0')) {
              iVar15 = FUN_008df670();
              FUN_008df740(puVar7[5]);
              if (iVar15 != 0) {
                puVar7[6] = iVar15;
                goto LAB_008dfd34;
              }
            }
            break;
          }
          piVar12 = (int *)((int)piVar12 + 1);
        }
        cVar1 = *pcVar11;
      }
    }
  }
  uVar10 = FUN_008df670();
  puVar7[6] = uVar10;
LAB_008dfd34:
  uVar9 = 0x811;
  if (local_5 != '\0') {
    uVar9 = 0x819;
  }
  if (*(char *)(iVar8 + 0x544) != '\0') {
    uVar9 = uVar9 | 4;
  }
  puVar7[2] = puVar7[2] | uVar9;
  local_c = (uint)(*(int *)(iVar8 + 0x548) != 0);
  pbVar13 = (byte *)FUN_008de030();
  if (pbVar13 != (byte *)0x0) {
    pbVar16 = &DAT_00c4651c;
    pbVar14 = pbVar13;
    do {
      bVar3 = *pbVar14;
      bVar17 = bVar3 < *pbVar16;
      if (bVar3 != *pbVar16) {
LAB_008dfe30:
        iVar15 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_008dfe35;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar14[1];
      bVar17 = bVar3 < pbVar16[1];
      if (bVar3 != pbVar16[1]) goto LAB_008dfe30;
      pbVar14 = pbVar14 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar3 != 0);
    iVar15 = 0;
LAB_008dfe35:
    if (iVar15 != 0) {
      pcVar11 = "Black";
      do {
        bVar3 = *pbVar13;
        bVar17 = bVar3 < (byte)*pcVar11;
        if (bVar3 != *pcVar11) {
LAB_008dfe60:
          iVar15 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_008dfe65;
        }
        if (bVar3 == 0) break;
        bVar3 = pbVar13[1];
        bVar17 = bVar3 < (byte)pcVar11[1];
        if (bVar3 != pcVar11[1]) goto LAB_008dfe60;
        pbVar13 = pbVar13 + 2;
        pcVar11 = pcVar11 + 2;
      } while (bVar3 != 0);
      iVar15 = 0;
LAB_008dfe65:
      if (iVar15 != 0) goto LAB_008dfe6d;
    }
    local_c = local_c | 2;
  }
LAB_008dfe6d:
  if ((((local_c & 2) == 0) && ((char *)puVar7[6] != (char *)0x0)) &&
     ((iVar15 = _strncmp((char *)puVar7[6],"Bold",4), iVar15 == 0 ||
      (iVar15 = _strncmp((char *)puVar7[6],"Black",5), iVar15 == 0)))) {
    local_c = local_c | 2;
  }
  puVar7[3] = local_c;
LAB_008dfeaf:
  if (((*(int *)(iVar8 + 0x5b0) != 0xffff) ||
      (puVar7[2] = puVar7[2] | 0x200, *(int *)(iVar8 + 0x5b0) != 0xffff)) &&
     ((char)local_10 != '\0')) {
    puVar7[2] = puVar7[2] | 0x1000;
  }
  local_1c = puVar7[9];
  uVar9 = 0;
  if (local_1c != 0) {
    piVar12 = (int *)puVar7[10];
    do {
      sVar5 = *(short *)(*piVar12 + 8);
      if (((sVar5 == 3) && (*(short *)(*piVar12 + 10) == 1)) || (sVar5 == 0)) goto LAB_008dff6f;
      uVar9 = uVar9 + 1;
      piVar12 = piVar12 + 1;
    } while (uVar9 < (uint)puVar7[9]);
  }
  if (((char)local_10 == '\0') || (*(int *)(iVar8 + 0x5b0) == 0xffff)) {
    local_28 = puVar7;
    local_20 = 0x10003;
    local_24 = 0x756e6963;
    param_2 = (undefined4 *)FUN_008bcc30(&DAT_00bea140,0,&local_28,0);
    if ((param_2 == (undefined4 *)0x0) || ((char)param_2 == -0x5d)) {
      param_2 = (undefined4 *)0x0;
      if ((puVar7[0x17] == 0) && (local_1c != puVar7[9])) {
        puVar7[0x17] = *(undefined4 *)(puVar7[10] + local_1c * 4);
      }
LAB_008dff6f:
      if (*(int *)(iVar8 + 0x7c) != 0) {
        local_28 = puVar7;
        if (*(int *)(iVar8 + 0x78) == 0) {
          local_20 = 7;
          local_24 = 0x41444f42;
        }
        else if (*(int *)(iVar8 + 0x78) == 1) {
          local_20 = 0x10007;
          local_24 = 0x41444245;
        }
        else {
          local_20 = 0x20007;
          local_24 = 0x41444243;
        }
        iVar8 = FUN_008bcc30(&DAT_00bea118,0,&local_28,0);
        return iVar8;
      }
    }
  }
  return (int)param_2;
}

