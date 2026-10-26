
/* WARNING: Type propagation algorithm not settling */

void FUN_0052fc50(int param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  short *******pppppppsVar10;
  uint uVar11;
  char *pcVar12;
  short *******pppppppsVar13;
  int local_f8;
  int *local_ec;
  undefined **local_e8 [17];
  char local_a4;
  uint local_9c;
  undefined4 local_8c;
  uint local_88;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  short *******local_50 [4];
  undefined4 local_40;
  uint local_3c;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923653;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar4;
  FUN_0072ee30(local_e8);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_a4 == '\0') && (iVar5 = FUN_0072e2e0("SKILLEXPLAINTABLE"), iVar5 != 0)) {
    for (piVar3 = *(int **)(iVar5 + 0x18); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      iVar5 = (**(code **)(*piVar3 + 0x14))(uVar4);
      if (iVar5 != 0) {
        iVar5 = FUN_007300a0(&DAT_00bfaf5c);
        if (iVar5 == 0) {
LAB_0052fda5:
          local_ec = (int *)0x0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_0052fda5;
          local_ec = (int *)FUN_008917b4(puVar6);
        }
        FUN_008438c0(&local_ec);
        if (((local_f8 != *(int *)(param_1 + 4)) && (iVar5 = *(int *)(local_f8 + 0x10), iVar5 != 0))
           && (local_ec = (int *)piVar3[6], local_ec != (int *)0x0)) {
          do {
            iVar7 = (**(code **)(*local_ec + 0x14))();
            if (*(uint *)(iVar7 + 0x34) < 0x10) {
              pcVar12 = (char *)(iVar7 + 0x20);
            }
            else {
              pcVar12 = *(char **)(iVar7 + 0x20);
            }
            iVar8 = __stricmp(pcVar12,"EXPLAIN");
            if (iVar8 == 0) {
              if ((*(int **)(iVar7 + 0x18) != (int *)0x0) &&
                 (iVar7 = (**(code **)(**(int **)(iVar7 + 0x18) + 0x30))(), iVar7 != 0)) {
                pcVar12 = (char *)(iVar7 + 0x20);
                if (0xf < *(uint *)(iVar7 + 0x34)) {
                  pcVar12 = *(char **)pcVar12;
                }
                if (pcVar12 != (char *)0x0) {
                  local_3c = 7;
                  local_40 = 0;
                  local_50[0] = (short *******)((uint)local_50[0] & 0xffff0000);
                  local_8._0_1_ = 1;
                  local_58 = 0xf;
                  local_5c = 0;
                  local_6c[0] = local_6c[0] & 0xffffff00;
                  pcVar9 = pcVar12;
                  do {
                    cVar1 = *pcVar9;
                    pcVar9 = pcVar9 + 1;
                  } while (cVar1 != '\0');
                  FUN_00402a70(pcVar12,(int)pcVar9 - (int)(pcVar12 + 1));
                  local_8._0_1_ = 2;
                  FUN_00440130(local_6c);
                  local_8 = CONCAT31(local_8._1_3_,1);
                  if (0xf < local_58) {
                    FUN_0089120c(local_6c[0]);
                  }
                  if (local_3c < 8) {
                    pppppppsVar13 = (short *******)local_50;
LAB_0052fedc:
                    pppppppsVar10 = pppppppsVar13;
                    do {
                      sVar2 = *(short *)pppppppsVar10;
                      pppppppsVar10 = (short *******)((int)pppppppsVar10 + 2);
                    } while (sVar2 != 0);
                    FUN_00402160(pppppppsVar13,
                                 (int)pppppppsVar10 - (int)((int)pppppppsVar13 + 2) >> 1);
                  }
                  else {
                    pppppppsVar13 = local_50[0];
                    if (local_50[0] != (short *******)0x0) goto LAB_0052fedc;
                  }
                  local_8 = local_8 & 0xffffff00;
                  if (7 < local_3c) {
                    FUN_0089120c(local_50[0]);
                  }
                }
              }
            }
            else {
              iVar8 = __stricmp(pcVar12,"LEVEL");
              if (iVar8 != 0) {
                FUN_006edb60(&DAT_00c0f0c8);
                goto LAB_00530049;
              }
              iVar8 = FUN_007300a0(&DAT_00c0e044);
              if (iVar8 == 0) {
LAB_0052ff63:
                uVar11 = 0;
              }
              else {
                puVar6 = (undefined4 *)(iVar8 + 0x30);
                if (0xf < *(uint *)(iVar8 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 == (undefined4 *)0x0) goto LAB_0052ff63;
                uVar11 = FUN_008917b4(puVar6);
              }
              if (((*(char *)(iVar5 + 0x24) == '\x01') &&
                  (uVar11 <= (uint)((*(int *)(iVar5 + 0x54) - *(int *)(iVar5 + 0x50)) / 0x28))) &&
                 ((*(int *)(iVar5 + 0x50) + -0x28 + uVar11 * 0x28 != 0 &&
                  ((*(int **)(iVar7 + 0x18) != (int *)0x0 &&
                   (iVar7 = (**(code **)(**(int **)(iVar7 + 0x18) + 0x30))(), iVar7 != 0)))))) {
                pcVar12 = (char *)(iVar7 + 0x20);
                if (0xf < *(uint *)(iVar7 + 0x34)) {
                  pcVar12 = *(char **)pcVar12;
                }
                if (pcVar12 != (char *)0x0) {
                  local_20 = 0xf;
                  local_24 = 0;
                  local_34[0] = local_34[0] & 0xffffff00;
                  pcVar9 = pcVar12;
                  do {
                    cVar1 = *pcVar9;
                    pcVar9 = pcVar9 + 1;
                  } while (cVar1 != '\0');
                  FUN_00402a70(pcVar12,(int)pcVar9 - (int)(pcVar12 + 1));
                  local_8._0_1_ = 3;
                  FUN_00440130(local_34);
                  local_8 = (uint)local_8._1_3_ << 8;
                  if (0xf < local_20) {
                    FUN_0089120c(local_34[0]);
                  }
                  local_20 = 0xf;
                  local_24 = 0;
                  local_34[0] = local_34[0] & 0xffffff00;
                }
              }
            }
LAB_00530049:
            local_ec = (int *)local_ec[0x10];
          } while (local_ec != (int *)0x0);
          local_ec = (int *)0x0;
        }
      }
    }
    local_8 = 0xffffffff;
    local_e8[0] = TiXmlDocument::vftable;
    if (0xf < local_88) {
      FUN_0089120c(local_9c);
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = local_9c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_e8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_88) {
      local_8 = 0xffffffff;
      local_e8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_9c);
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = local_9c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

