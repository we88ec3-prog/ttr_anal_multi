
uint FUN_008bd6d0(undefined4 *param_1,uint *param_2,int param_3,int *param_4)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  short *psVar6;
  char *pcVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  bool bVar13;
  undefined4 *local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  uint local_18;
  undefined4 *local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar10 = 0;
  local_1c = (undefined4 *)0x0;
  local_20 = 0;
  local_8 = 0;
  local_10 = 0;
  if (((param_4 == (int *)0x0) && (-1 < param_3)) || (param_2 == (uint *)0x0)) {
    return 6;
  }
  if ((*param_2 & 2) == 0) {
LAB_008bd710:
    local_c = local_c & 0xffffff00;
  }
  else {
    local_c = CONCAT31(local_c._1_3_,1);
    if (param_2[4] == 0) goto LAB_008bd710;
  }
  uVar3 = FUN_008bb080(param_1,param_2,&local_8);
  uVar11 = local_8;
  if (uVar3 == 0) {
    local_20 = *param_1;
    if (((*param_2 & 8) == 0) || (puVar8 = (undefined4 *)param_2[5], puVar8 == (undefined4 *)0x0)) {
      local_14 = param_1 + 5;
      puVar8 = local_14 + param_1[4];
      uVar3 = 0xb;
      local_24 = puVar8;
      if (local_14 < puVar8) {
        do {
          if ((**(byte **)*local_14 & 1) != 0) {
            uVar3 = 0;
            uVar9 = 0;
            if ((*param_2 & 0x10) != 0) {
              uVar3 = param_2[6];
              uVar9 = param_2[7];
            }
            local_1c = (undefined4 *)*local_14;
            uVar3 = FUN_008bb770(&local_8,local_c,param_3,uVar3,uVar9,&local_10);
            uVar11 = local_8;
            local_18 = uVar3;
            if (uVar3 == 0) goto LAB_008bd907;
            pbVar4 = *(byte **)(*(int *)*local_14 + 8);
            pcVar7 = "truetype";
            do {
              bVar1 = *pbVar4;
              bVar13 = bVar1 < (byte)*pcVar7;
              if (bVar1 != *pcVar7) {
LAB_008bd860:
                iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                goto LAB_008bd865;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar13 = bVar1 < (byte)pcVar7[1];
              if (bVar1 != pcVar7[1]) goto LAB_008bd860;
              pbVar4 = pbVar4 + 2;
              pcVar7 = pcVar7 + 2;
            } while (bVar1 != 0);
            iVar10 = 0;
LAB_008bd865:
            if ((iVar10 == 0) && ((char)uVar3 == -0x72)) {
              iVar5 = FUN_008b97e0(local_8,0);
              iVar10 = local_10;
              if (iVar5 != 0) break;
              uVar3 = FUN_008bb9e0(param_1,uVar11,param_3,param_4);
              if (uVar3 == 0) goto LAB_008bd8f0;
            }
            puVar8 = local_24;
            iVar10 = local_10;
            if ((char)uVar3 != '\x02') break;
          }
          local_14 = local_14 + 1;
          iVar10 = local_10;
        } while (local_14 < puVar8);
      }
      goto LAB_008bd8b4;
    }
    local_1c = puVar8;
    if ((*(byte *)*puVar8 & 1) == 0) {
      uVar3 = 0x20;
    }
    else {
      uVar3 = 0;
      uVar9 = 0;
      if ((*param_2 & 0x10) != 0) {
        uVar3 = param_2[6];
        uVar9 = param_2[7];
      }
      uVar3 = FUN_008bb770(&local_8,local_c,param_3,uVar3,uVar9,&local_10);
      iVar10 = local_10;
      uVar11 = local_8;
      local_18 = uVar3;
      if (uVar3 == 0) {
LAB_008bd907:
        iVar5 = FUN_008baee0(local_20,0xc,&local_18);
        iVar10 = local_10;
        uVar3 = local_18;
        if (local_18 == 0) {
          *(int *)(iVar5 + 8) = local_10;
          FUN_008ba090(*(int *)(local_10 + 0x60) + 0x10,iVar5);
          if (-1 < param_3) {
            uVar3 = FUN_008bb230(iVar10,0);
            if ((uVar3 != 0) || (uVar3 = FUN_008bbed0(iVar10,&local_24), uVar3 != 0))
            goto LAB_008bda42;
            *(undefined4 **)(iVar10 + 0x58) = local_24;
          }
          iVar5 = 0;
          if ((*(byte *)(iVar10 + 8) & 1) != 0) {
            if (*(short *)(iVar10 + 0x4a) < 0) {
              *(short *)(iVar10 + 0x4a) = -*(short *)(iVar10 + 0x4a);
            }
            if ((*(byte *)(iVar10 + 8) & 0x20) == 0) {
              *(undefined2 *)(iVar10 + 0x4e) = *(undefined2 *)(iVar10 + 0x4a);
            }
          }
          if (((*(byte *)(iVar10 + 8) & 2) != 0) && (0 < *(int *)(iVar10 + 0x1c))) {
            iVar12 = 0;
            do {
              sVar2 = *(short *)(*(int *)(iVar10 + 0x20) + iVar12);
              psVar6 = (short *)(*(int *)(iVar10 + 0x20) + iVar12);
              if (sVar2 < 0) {
                *psVar6 = -sVar2;
              }
              if (*(int *)(psVar6 + 4) < 0) {
                *(int *)(psVar6 + 4) = (int)-psVar6[4];
              }
              if (*(int *)(psVar6 + 6) < 0) {
                *(int *)(psVar6 + 6) = -*(int *)(psVar6 + 6);
              }
              iVar5 = iVar5 + 1;
              iVar12 = iVar12 + 0x10;
            } while (iVar5 < *(int *)(iVar10 + 0x1c));
          }
          puVar8 = *(undefined4 **)(iVar10 + 0x80);
          *puVar8 = 0x10000;
          puVar8[1] = 0;
          puVar8[2] = 0;
          puVar8[3] = 0x10000;
          puVar8[4] = 0;
          puVar8[5] = 0;
          puVar8[0xe] = 1;
          if (param_4 != (int *)0x0) {
            *param_4 = iVar10;
            return uVar3;
          }
LAB_008bda4a:
          FUN_008bbe50(iVar10);
          return uVar3;
        }
LAB_008bda42:
        if (iVar5 != 0) goto LAB_008bda4a;
        goto LAB_008bd7a5;
      }
    }
  }
  else {
LAB_008bd8b4:
    uVar9 = uVar3 & 0xff;
    if (((uVar9 == 0x51) || (uVar9 == 2)) || (uVar9 == 0x55)) {
      uVar3 = FUN_008bd670(param_3,param_2);
      if (uVar3 == 0) {
LAB_008bd8f0:
        FUN_008ba2d0(uVar11,local_c & 0xff);
        return 0;
      }
      if ((char)uVar3 == '\x02') {
        uVar3 = 2;
      }
    }
  }
  FUN_008ba2d0(uVar11,local_c & 0xff);
LAB_008bd7a5:
  if (iVar10 != 0) {
    FUN_008bb670(local_20,iVar10,local_1c);
  }
  return uVar3;
}

