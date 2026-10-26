
int * FUN_008f2630(int *param_1,uint param_2,uint param_3,char param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *local_84;
  int *local_80;
  int *local_7c;
  int *local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  int *local_10;
  int local_c;
  char local_5;
  
  iVar8 = *param_1;
  iVar1 = param_1[3];
  bVar4 = false;
  local_10 = (int *)0x0;
  local_5 = '\0';
  if ((1 < param_3) && (*(ushort *)(iVar8 + 0x122) < param_3)) {
    return (int *)0x15;
  }
  if (*(uint *)(iVar8 + 0x10) <= param_2) {
    return (int *)0x10;
  }
  param_1[5] = param_2;
  if ((*(byte *)(param_1 + 4) & 1) == 0) {
    local_14 = *(uint *)(param_1[1] + 0x30);
    local_18 = *(uint *)(param_1[1] + 0x34);
  }
  else {
    local_18 = 0x10000;
    local_14 = 0x10000;
  }
  local_c = iVar8;
  if (*(int *)(*(int *)(iVar8 + 0x80) + 0x30) == 0) {
    local_1c = (int *)FUN_008ea840(iVar8,param_2,param_1 + 7);
  }
  else {
    puVar2 = *(undefined4 **)(*(int *)(iVar8 + 0x80) + 0x30);
    local_84 = (int *)(**(code **)*puVar2)(puVar2[1],param_2,&local_3c);
    if (local_84 != (int *)0x0) {
      return local_84;
    }
    local_5 = '\x01';
    param_1[7] = local_38;
    local_80 = local_84;
    local_7c = local_84;
    local_78 = local_84;
    local_74 = local_84;
    local_70 = local_84;
    local_6c = local_84;
    local_68 = local_84;
    local_64 = local_84;
    local_60 = local_84;
    local_1c = local_84;
    FUN_008b9790(&local_84,local_3c,local_38);
    param_1[6] = (int)&local_84;
  }
  if (param_1[7] < 1) {
LAB_008f27ad:
    if ((param_1[7] == 0) || ((short)param_1[8] == 0)) {
      param_1[9] = 0;
      param_1[0xb] = 0;
      param_1[10] = 0;
      param_1[0xc] = 0;
      piVar6 = (int *)FUN_008eacd0(param_2);
      if ((piVar6 == (int *)0x0) && (param_4 == '\0')) {
        param_1[0x11] = param_1[9] - param_1[0xd];
        param_1[0x2f] = param_1[0xc] + param_1[0x2c];
        param_1[0x12] = 0;
        param_1[0x13] = param_1[0xe] + (param_1[9] - param_1[0xd]);
        param_1[0x14] = 0;
        param_1[0x2e] = 0;
        param_1[0x30] = 0;
        param_1[0x31] = (param_1[0xc] + param_1[0x2c]) - param_1[0x2d];
        FUN_008ead70(param_2);
        if (*(char *)(*param_1 + 0x2a0) != '\0') {
          uVar3 = *(undefined4 *)(*param_1 + 100);
          piVar6 = (int *)FUN_008f1390(param_2,&local_10,4);
          if (piVar6 != (int *)0x0) goto LAB_008f2cfb;
          param_1[0x11] = param_1[0x11] + *local_10;
          param_1[0x12] = param_1[0x12] + local_10[1];
          param_1[0x13] = param_1[0x13] + local_10[2];
          param_1[0x14] = param_1[0x14] + local_10[3];
          param_1[0x2e] = param_1[0x2e] + local_10[4];
          param_1[0x2f] = param_1[0x2f] + local_10[5];
          param_1[0x30] = param_1[0x30] + local_10[6];
          param_1[0x31] = param_1[0x31] + local_10[7];
          FUN_008b9f80(uVar3,local_10);
        }
        uVar5 = local_14;
        if ((*(byte *)(param_1 + 4) & 1) == 0) {
          iVar8 = FUN_008b7f10(param_1[0x11],local_14);
          param_1[0x11] = iVar8;
          iVar8 = FUN_008b7f10(param_1[0x13],uVar5);
          param_1[0x13] = iVar8;
          iVar8 = FUN_008b7f10(param_1[0x2e],uVar5);
          param_1[0x2e] = iVar8;
          iVar8 = FUN_008b7f10(param_1[0x2f],local_18);
          param_1[0x2f] = iVar8;
          iVar8 = FUN_008b7f10(param_1[0x30],uVar5);
          param_1[0x30] = iVar8;
          iVar8 = FUN_008b7f10(param_1[0x31],local_18);
          param_1[0x31] = iVar8;
        }
        piVar6 = (int *)0x0;
      }
    }
    else {
      param_1[0x11] = param_1[9] - param_1[0xd];
      param_1[0x12] = 0;
      param_1[0x2f] = param_1[0x2c] + param_1[0xc];
      param_1[0x13] = param_1[0xe] + (param_1[9] - param_1[0xd]);
      param_1[0x31] = (param_1[0x2c] + param_1[0xc]) - param_1[0x2d];
      param_1[0x14] = 0;
      param_1[0x2e] = 0;
      param_1[0x30] = 0;
      FUN_008ead70(param_2);
      if ((short)param_1[8] < 1) {
        if ((short)param_1[8] == -1) {
          local_1c = (int *)(int)*(short *)(iVar1 + 0x16);
          local_34 = (int)*(short *)(iVar1 + 0x14);
          piVar6 = (int *)(**(code **)(iVar8 + 0x210))(param_1);
          if (piVar6 == (int *)0x0) {
            local_30 = param_1[0x2a];
            (**(code **)(local_c + 0x204))(param_1);
            if (*(char *)(local_c + 0x2a0) != '\0') {
              local_20 = *(int **)(local_c + 100);
              piVar6 = (int *)FUN_008f1390(param_2,&local_10,*(int *)(iVar1 + 0x54) + 4);
              if (piVar6 != (int *)0x0) goto LAB_008f2d10;
              iVar8 = *(int *)(iVar1 + 0x54);
              iVar7 = 0;
              if (0 < iVar8) {
                piVar9 = (int *)(*(int *)(iVar1 + 0x30) * 0x20 + *(int *)(iVar1 + 0x58) + 8);
                iVar7 = 0;
                do {
                  if ((*(byte *)(piVar9 + -1) & 2) != 0) {
                    *piVar9 = *piVar9 + (int)(short)local_10[iVar7 * 2];
                    piVar9[1] = piVar9[1] + (int)(short)local_10[iVar7 * 2 + 1];
                  }
                  iVar7 = iVar7 + 1;
                  piVar9 = piVar9 + 8;
                } while (iVar7 < iVar8);
              }
              param_1[0x11] = param_1[0x11] + local_10[iVar7 * 2];
              param_1[0x12] = param_1[0x12] + local_10[iVar7 * 2 + 1];
              param_1[0x13] = param_1[0x13] + local_10[iVar7 * 2 + 2];
              param_1[0x14] = param_1[0x14] + local_10[iVar7 * 2 + 3];
              param_1[0x2e] = param_1[0x2e] + local_10[iVar7 * 2 + 4];
              param_1[0x2f] = param_1[0x2f] + local_10[iVar7 * 2 + 5];
              param_1[0x30] = param_1[0x30] + local_10[iVar7 * 2 + 6];
              param_1[0x31] = param_1[0x31] + local_10[iVar7 * 2 + 7];
              FUN_008b9f80(local_20,local_10);
            }
            if ((*(byte *)(param_1 + 4) & 1) == 0) {
              iVar8 = FUN_008b7f10(param_1[0x11],local_14);
              param_1[0x11] = iVar8;
              iVar8 = FUN_008b7f10(param_1[0x13],local_14);
              param_1[0x13] = iVar8;
              iVar8 = FUN_008b7f10(param_1[0x2e],local_14);
              param_1[0x2e] = iVar8;
              iVar8 = FUN_008b7f10(param_1[0x2f],local_18);
              param_1[0x2f] = iVar8;
              iVar8 = FUN_008b7f10(param_1[0x30],local_14);
              param_1[0x30] = iVar8;
              iVar8 = FUN_008b7f10(param_1[0x31],local_18);
              param_1[0x31] = iVar8;
            }
            if ((param_1[4] & 0x400U) == 0) {
              local_14 = *(uint *)(iVar1 + 0x54);
              local_20 = *(int **)(iVar1 + 0x30);
              local_10 = local_1c;
              local_28 = param_1[6];
              local_2c = param_1[7];
              FUN_008b8370(iVar1);
              local_18 = 0;
              if (local_14 == 0) {
                iVar8 = 0;
              }
              else {
                local_24 = param_3 + 1;
                param_3 = (int)local_20 << 5;
                do {
                  local_58 = param_1[0x12];
                  local_5c = param_1[0x11];
                  local_50 = param_1[0x14];
                  local_54 = param_1[0x13];
                  local_48 = param_1[0x2f];
                  local_4c = param_1[0x2e];
                  local_40 = param_1[0x31];
                  local_44 = param_1[0x30];
                  local_20 = (int *)(int)*(short *)(iVar1 + 0x16);
                  piVar6 = (int *)FUN_008f2630(param_1,*(undefined4 *)
                                                        (*(int *)(iVar1 + 0x34) + param_3),local_24,
                                               0);
                  if (piVar6 != (int *)0x0) goto LAB_008f2d10;
                  iVar8 = *(int *)(iVar1 + 0x34) + param_3;
                  if ((*(ushort *)(iVar8 + 4) & 0x200) == 0) {
                    param_1[0x11] = local_5c;
                    param_1[0x12] = local_58;
                    param_1[0x13] = local_54;
                    param_1[0x14] = local_50;
                    param_1[0x2e] = local_4c;
                    param_1[0x2f] = local_48;
                    param_1[0x30] = local_44;
                    param_1[0x31] = local_40;
                  }
                  local_10 = (int *)(int)*(short *)(iVar1 + 0x16);
                  if (local_10 != local_20) {
                    FUN_008eb1d0(param_1,local_1c,local_20);
                  }
                  param_3 = param_3 + 0x20;
                  local_18 = local_18 + 1;
                } while (local_18 < local_14);
              }
              param_1[6] = local_28;
              param_1[7] = local_2c;
              param_1[0x2a] = local_30;
              if ((((*(byte *)(param_1 + 4) & 2) == 0) && ((*(ushort *)(iVar8 + 4) & 0x100) != 0))
                 && (local_1c < local_10)) {
                FUN_008f23e0(param_1,local_1c,local_34);
              }
            }
            else {
              FUN_008b8370(iVar1);
              *(undefined4 *)(param_1[2] + 0x48) = 0x636f6d70;
            }
            goto LAB_008f2d10;
          }
        }
        else {
          piVar6 = (int *)&DAT_00000014;
        }
      }
      else {
        piVar6 = (int *)(**(code **)(iVar8 + 0x20c))(param_1);
        if (piVar6 == (int *)0x0) {
          (**(code **)(local_c + 0x204))(param_1);
          piVar6 = (int *)FUN_008f2190();
          if (piVar6 == (int *)0x0) {
            FUN_008b8370(iVar1);
          }
          goto LAB_008f2d10;
        }
      }
    }
LAB_008f2cfb:
    if (!bVar4) goto LAB_008f2d10;
  }
  else {
    if ((param_1[0x15] == 0) && (*(int *)(*(int *)(iVar8 + 0x80) + 0x30) == 0)) {
      piVar6 = (int *)0x8;
      goto LAB_008f2d10;
    }
    piVar6 = (int *)(**(code **)(iVar8 + 0x200))
                              (param_1,param_2,param_1[0x15] + (int)local_1c,param_1[7]);
    if (piVar6 != (int *)0x0) goto LAB_008f2d10;
    bVar4 = true;
    piVar6 = (int *)(**(code **)(local_c + 0x208))(param_1);
    if (((piVar6 == (int *)0x0) && (piVar6 = (int *)FUN_008eacd0(param_2), piVar6 == (int *)0x0)) &&
       (iVar8 = local_c, param_4 == '\0')) goto LAB_008f27ad;
  }
  (**(code **)(local_c + 0x204))(param_1);
LAB_008f2d10:
  if (local_5 != '\0') {
    piVar9 = *(int **)(*(int *)(local_c + 0x80) + 0x30);
    (**(code **)(*piVar9 + 4))(piVar9[1],&local_3c);
  }
  return piVar6;
}

