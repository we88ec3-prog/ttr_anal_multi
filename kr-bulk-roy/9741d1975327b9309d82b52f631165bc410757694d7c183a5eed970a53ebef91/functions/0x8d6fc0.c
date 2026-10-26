
/* WARNING: Type propagation algorithm not settling */

void FUN_008d6fc0(int param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  byte *local_28;
  int local_24;
  char *local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  uint local_10;
  int local_c;
  char local_5;
  
  local_24 = param_2[4];
  local_20 = (char *)param_2[2];
  iVar8 = 0;
  pbVar9 = (byte *)0x0;
  local_34 = 0;
  local_18 = 0;
  local_5 = '\0';
  (*(code *)param_2[7])(param_2);
  pcVar2 = (char *)*param_2;
  if ((pcVar2 < local_20) && (cVar1 = *pcVar2, *param_2 = (int)(pcVar2 + 1), cVar1 == '[')) {
    (*(code *)param_2[7])(param_2);
    local_2c = 0;
    local_10 = 0;
    local_30 = 0;
    local_14 = (byte *)0x0;
    if ((char *)*param_2 < local_20) {
      do {
        local_28 = (byte *)*param_2;
        bVar6 = *local_28;
        if (bVar6 == 0x5d) {
          *param_2 = *param_2 + 1;
          goto LAB_008d7362;
        }
        if (bVar6 != 0x3c) {
          if (9 < bVar6 - 0x30) goto LAB_008d7125;
          if (local_5 == '\0') {
            local_10 = (*(code *)param_2[9])(param_2);
            if (-1 < (int)local_10) {
              (*(code *)param_2[8])(param_2);
              if (param_2[3] != 0) {
                return;
              }
              iVar3 = *param_2;
              local_18 = iVar3 + 1;
              if ((int)local_10 <= (int)local_20 - iVar3) {
                *param_2 = iVar3 + 1 + local_10;
                goto LAB_008d7125;
              }
              goto LAB_008d7348;
            }
LAB_008d7354:
            local_c = 3;
          }
          else {
LAB_008d7348:
            local_c = 3;
          }
          goto LAB_008d735f;
        }
        (*(code *)param_2[8])(param_2);
        if (param_2[3] != 0) goto LAB_008d7362;
        local_10 = ((*param_2 - (int)local_28) + -1) / 2;
        local_18 = FUN_008bc7d0(local_24,1,local_30,local_10,local_18,&local_c);
        if (local_c != 0) goto LAB_008d735f;
        *param_2 = (int)local_28;
        local_5 = '\x01';
        (*(code *)param_2[0xb])(param_2,local_18,local_10,&local_38,1);
        local_30 = local_10;
        local_10 = local_38;
LAB_008d7125:
        if (local_18 == 0) goto LAB_008d7354;
        if (((local_10 & 1) != 0) && (*(char *)((local_10 - 1) + local_18) == '\0')) {
          local_10 = local_10 - 1;
        }
        if (local_10 == 0) goto LAB_008d7354;
        local_1c = 0;
        if (0 < (int)local_10) {
          do {
            if (local_2c == 0) {
              if ((byte *)0xb < local_14) {
                iVar3 = *(int *)(param_1 + 0x1ec);
                iVar8 = (uint)*(byte *)(iVar3 + 4) * 0x10 + (uint)*(byte *)(iVar3 + 5);
                pbVar9 = (byte *)(iVar8 * 0x10 + 0xc);
                local_2c = 1;
                local_34 = iVar8;
                uVar5 = FUN_008bc7d0(local_24,1,0xc,pbVar9,iVar3,&local_c);
                *(undefined4 *)(param_1 + 0x1ec) = uVar5;
                if (local_c == 0) goto LAB_008d71d4;
                goto LAB_008d735f;
              }
              bVar6 = *(byte *)(local_1c + local_18);
LAB_008d72fe:
              local_14[*(int *)(param_1 + 0x1ec)] = bVar6;
LAB_008d730a:
              local_14 = local_14 + 1;
            }
            else {
              if (local_2c == 1) {
LAB_008d71d4:
                if (local_14 < pbVar9) {
                  local_14[*(int *)(param_1 + 0x1ec)] = *(byte *)(local_1c + local_18);
                  goto LAB_008d730a;
                }
                iVar3 = 0;
                local_2c = 0;
                local_28 = (byte *)0x0;
                if (1 < iVar8) {
                  puVar4 = (undefined1 *)(*(int *)(param_1 + 0x1ec) + 0x1a);
                  iVar7 = (iVar8 - 2U >> 1) + 1;
                  iVar3 = iVar7 * 2;
                  do {
                    local_2c = local_2c +
                               (CONCAT31(CONCAT21(CONCAT11(puVar4[-2],puVar4[-1]),*puVar4),puVar4[1]
                                        ) + 3U & 0xfffffffc);
                    local_28 = local_28 +
                               (CONCAT31(CONCAT21(CONCAT11(puVar4[0xe],puVar4[0xf]),puVar4[0x10]),
                                         puVar4[0x11]) + 3U & 0xfffffffc);
                    puVar4 = puVar4 + 0x20;
                    iVar7 = iVar7 + -1;
                    iVar8 = local_34;
                  } while (iVar7 != 0);
                }
                if (iVar3 < iVar8) {
                  iVar7 = *(int *)(param_1 + 0x1ec) + 0x18 + iVar3 * 0x10;
                  pbVar9 = pbVar9 + (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                 (*(int *)(param_1 + 0x1ec) + 0x18 +
                                                                 iVar3 * 0x10),
                                                                *(undefined1 *)(iVar7 + 1)),
                                                       *(undefined1 *)(iVar7 + 2)),
                                              *(undefined1 *)(iVar7 + 3)) + 3U & 0xfffffffc);
                }
                pbVar9 = pbVar9 + (int)(local_28 + local_2c);
                local_2c = 2;
                *(byte **)(param_1 + 0x1f0) = pbVar9;
                uVar5 = FUN_008bc7d0(local_24,1,iVar8 * 0x10 + 0xc,pbVar9 + 1,
                                     *(undefined4 *)(param_1 + 0x1ec),&local_c);
                *(undefined4 *)(param_1 + 0x1ec) = uVar5;
                if (local_c == 0) goto LAB_008d72f0;
                goto LAB_008d735f;
              }
              if (local_2c == 2) {
LAB_008d72f0:
                if (local_14 < pbVar9) {
                  bVar6 = *(byte *)(local_1c + local_18);
                  goto LAB_008d72fe;
                }
                goto LAB_008d7354;
              }
            }
            local_1c = local_1c + 1;
          } while (local_1c < (int)local_10);
        }
        (*(code *)param_2[7])(param_2);
      } while ((char *)*param_2 < local_20);
    }
  }
  local_c = 3;
LAB_008d735f:
  param_2[3] = local_c;
LAB_008d7362:
  if (local_5 != '\0') {
    FUN_008b9f80(local_24,local_18);
  }
  return;
}

