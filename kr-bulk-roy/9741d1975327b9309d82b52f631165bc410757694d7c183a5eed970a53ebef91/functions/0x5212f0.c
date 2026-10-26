
/* WARNING: Type propagation algorithm not settling */

void FUN_005212f0(undefined4 param_1)

{
  short sVar1;
  wchar_t wVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  uint *puVar5;
  char cVar6;
  int *piVar7;
  long lVar8;
  int iVar9;
  undefined4 uVar10;
  short *******pppppppsVar11;
  char *pcVar12;
  wchar_t *pwVar13;
  wchar_t *_Str;
  short *psVar14;
  undefined4 *******pppppppuVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  char *pcVar18;
  short *psVar19;
  undefined1 uVar20;
  uint *puVar21;
  undefined2 uVar22;
  short *******pppppppsVar23;
  uint *puVar24;
  undefined *puVar25;
  undefined1 local_688 [4];
  int local_684;
  int *local_680;
  long local_67c;
  uint *local_678;
  int local_674;
  int local_670;
  int local_66c;
  int local_668;
  int local_664;
  int local_660;
  int local_65c;
  int local_658;
  int local_654;
  int local_650;
  int local_64c;
  int local_648;
  int local_644;
  int local_640;
  int local_63c;
  int local_638;
  int local_634;
  undefined4 local_630;
  int local_62c;
  int local_628;
  int local_624;
  int local_620;
  int local_61c;
  int local_618;
  int local_614;
  int local_610;
  int local_60c;
  int local_608;
  int local_604;
  int local_600;
  int local_5fc;
  long local_5f8;
  int local_5f4;
  int local_5f0;
  int local_5ec;
  int local_5e8;
  int local_5e4;
  int local_5e0;
  int local_5dc;
  int local_5d8;
  int local_5d4;
  int local_5d0;
  int local_5cc;
  int local_5c8;
  int local_5c4;
  int local_5c0;
  int local_5bc;
  int local_5b8;
  int local_5b4;
  int local_5b0;
  wchar_t *local_5ac;
  int local_5a8;
  int local_5a4;
  int local_5a0;
  int local_59c;
  int local_598;
  int local_594;
  int local_590;
  uint *local_58c;
  int local_588;
  int local_584;
  int local_580;
  uint *local_57c;
  int local_578;
  int local_574;
  char local_56d;
  uint *local_56c [53];
  undefined1 local_498;
  uint local_494;
  undefined4 local_484;
  uint local_480;
  undefined4 local_474;
  uint local_460;
  short *******local_458 [4];
  undefined4 local_448;
  uint local_444;
  undefined4 *******local_43c [4];
  undefined4 local_42c;
  uint local_428;
  wchar_t local_420 [260];
  short local_218;
  undefined1 local_216 [510];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923a6e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_630 = param_1;
  local_56c[3] = (uint *)0x0;
  local_56c[4] = (uint *)0x0;
  FUN_0071bc20(local_18);
  local_8 = 0;
  local_498 = 0;
  local_480 = 0xf;
  local_484 = 0;
  local_494 = local_494 & 0xffffff00;
  FUN_00402a70("Table/ItemTable2.xml",0x14);
  local_8 = 1;
  local_428 = 0xf;
  local_42c = 0;
  local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffffff00);
  FUN_00402a70("Table/ItemTable2.xml",0x14);
  local_8 = CONCAT31(local_8._1_3_,2);
  pppppppuVar15 = local_43c[0];
  if (local_428 < 0x10) {
    pppppppuVar15 = local_43c;
  }
  piVar7 = (int *)FUN_00714770(pppppppuVar15,&DAT_00bed1e0);
  if (piVar7 == (int *)0x0) {
    cVar6 = '\0';
  }
  else {
    (**(code **)(*piVar7 + 0x38))();
    uVar10 = (**(code **)(*piVar7 + 0x2c))();
    cVar6 = FUN_00499340(uVar10);
    (**(code **)(*piVar7 + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (0xf < local_428) {
    FUN_0089120c(local_43c[0]);
  }
  if (cVar6 == '\0') {
    FUN_006edb60("Cannot find valid item table file");
  }
  else {
    local_57c = local_56c[3];
    piVar7 = (int *)FUN_0071ba40("ITEM_TABLE");
    local_57c = (uint *)*piVar7;
    if (local_57c != (uint *)0x0) {
      FUN_00719da0(local_56c + 1);
      if (local_56c[1] != (uint *)0x0) {
LAB_005214e0:
        puVar21 = local_56c[1];
        FUN_0071baa0(&DAT_00c0e550);
        if (local_5ec != 0) {
          if (*(char **)(local_5ec + 8) == (char *)0x0) {
            lVar8 = 0;
          }
          else {
            lVar8 = _strtol(*(char **)(local_5ec + 8),(char **)0x0,10);
          }
          if (lVar8 == 0) goto LAB_00522a86;
          iVar9 = FUN_00891268(0x158);
          if (iVar9 == 0) {
            local_56c[2] = (uint *)0x0;
          }
          else {
            local_56c[2] = (uint *)FUN_00520b50();
          }
          puVar21 = local_56c[2];
          *local_56c[2] = lVar8;
          local_444 = 7;
          local_448 = 0;
          local_458[0] = (short *******)((uint)local_458[0] & 0xffff0000);
          local_8._0_1_ = 3;
          uVar10 = FUN_00719f10(local_56c + 1,&DAT_00bf2375);
          local_8._0_1_ = 4;
          FUN_00440130(uVar10);
          local_8._0_1_ = 3;
          if (0xf < local_428) {
            FUN_0089120c(local_43c[0]);
          }
          lVar8 = 0;
          FUN_0071baa0("class");
          if (local_628 != 0) {
            if (*(char **)(local_628 + 8) == (char *)0x0) {
              lVar8 = 0;
            }
            else {
              lVar8 = _strtol(*(char **)(local_628 + 8),(char **)0x0,10);
            }
          }
          puVar21[2] = lVar8;
          pppppppsVar23 = local_458[0];
          if (local_444 < 8) {
            pppppppsVar23 = (short *******)local_458;
          }
          pppppppsVar11 = pppppppsVar23;
          do {
            sVar1 = *(short *)pppppppsVar11;
            pppppppsVar11 = (short *******)((int)pppppppsVar11 + 2);
          } while (sVar1 != 0);
          FUN_00402160(pppppppsVar23,(int)pppppppsVar11 - (int)((int)pppppppsVar23 + 2) >> 1);
          lVar8 = 0;
          FUN_0071baa0(&DAT_00c0e8d4);
          if (local_65c != 0) {
            if (*(char **)(local_65c + 8) == (char *)0x0) {
              lVar8 = 0;
            }
            else {
              lVar8 = _strtol(*(char **)(local_65c + 8),(char **)0x0,10);
            }
          }
          local_56c[2][3] = lVar8;
          uVar20 = 0;
          FUN_0071baa0("trade_limit_type");
          if (local_664 != 0) {
            if (*(char **)(local_664 + 8) == (char *)0x0) {
              uVar20 = 0;
            }
            else {
              lVar8 = _strtol(*(char **)(local_664 + 8),(char **)0x0,10);
              uVar20 = (undefined1)lVar8;
            }
          }
          *(undefined1 *)(local_56c[2] + 0x3b) = uVar20;
          lVar8 = 0;
          FUN_0071baa0("gettype");
          if (local_66c != 0) {
            if (*(char **)(local_66c + 8) == (char *)0x0) {
              lVar8 = 0;
            }
            else {
              lVar8 = _strtol(*(char **)(local_66c + 8),(char **)0x0,10);
            }
          }
          local_56c[2][0x21] = lVar8;
          FUN_00719da0(&local_674);
          if ((local_674 != 0) && (*(int *)(local_674 + 0x10) != 0)) {
            if ((*(int *)(local_674 + 0x10) == 0) ||
               (pcVar18 = *(char **)(*(int *)(local_674 + 0x10) + 0xc), pcVar18 == (char *)0x0)) {
              pcVar18 = "";
            }
            local_428 = 0xf;
            local_42c = 0;
            local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffffff00);
            pcVar12 = pcVar18;
            do {
              cVar6 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar6 != '\0');
            FUN_00402a70(pcVar18,(int)pcVar12 - (int)(pcVar18 + 1));
            local_8._0_1_ = 5;
            FUN_00440130(local_43c);
            local_8._0_1_ = 3;
            if (0xf < local_428) {
              FUN_0089120c(local_43c[0]);
            }
          }
          FUN_00719da0(&local_650);
          if ((local_650 != 0) && (*(int *)(local_650 + 0x10) != 0)) {
            if ((*(int *)(local_650 + 0x10) == 0) ||
               (pcVar18 = *(char **)(*(int *)(local_650 + 0x10) + 0xc), pcVar18 == (char *)0x0)) {
              pcVar18 = "";
            }
            local_428 = 0xf;
            local_42c = 0;
            local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffffff00);
            pcVar12 = pcVar18;
            do {
              cVar6 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar6 != '\0');
            FUN_00402a70(pcVar18,(int)pcVar12 - (int)(pcVar18 + 1));
            local_8._0_1_ = 6;
            FUN_00440130(local_43c);
            local_8._0_1_ = 3;
            if (0xf < local_428) {
              FUN_0089120c(local_43c[0]);
            }
          }
          FUN_00719da0(&local_578);
          if (local_578 != 0) {
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e904);
            if (local_668 != 0) {
              if (*(char **)(local_668 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_668 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][4] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("phy_ratio_table_id");
            if (local_624 != 0) {
              if (*(char **)(local_624 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_624 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][5] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("phy_per_level");
            if (local_5c4 != 0) {
              if (*(char **)(local_5c4 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5c4 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][6] = lVar8;
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e92c);
            if (local_658 != 0) {
              if (*(char **)(local_658 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_658 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x10] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("men_ratio_table_id");
            if (local_5cc != 0) {
              if (*(char **)(local_5cc + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5cc + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x11] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("men_per_level");
            if (local_62c != 0) {
              if (*(char **)(local_62c + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_62c + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x12] = lVar8;
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e954);
            if (local_5d4 != 0) {
              if (*(char **)(local_5d4 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5d4 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][10] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("mag_ratio_table_id");
            if (local_638 != 0) {
              if (*(char **)(local_638 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_638 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0xb] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("mag_per_level");
            if (local_5dc != 0) {
              if (*(char **)(local_5dc + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5dc + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0xc] = lVar8;
          }
          FUN_00719da0(&local_574);
          if (local_574 != 0) {
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e904);
            if (local_634 != 0) {
              if (*(char **)(local_634 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_634 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][7] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("phy_ratio_table_id");
            if (local_5e4 != 0) {
              if (*(char **)(local_5e4 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5e4 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][8] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("phy_per_level");
            if (local_63c != 0) {
              if (*(char **)(local_63c + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_63c + 8),(char **)0x0,10);
              }
            }
            local_56c[2][9] = lVar8;
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e92c);
            if (local_5b8 != 0) {
              if (*(char **)(local_5b8 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5b8 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x13] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("men_ratio_table_id");
            if (local_644 != 0) {
              if (*(char **)(local_644 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_644 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x14] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("men_per_level");
            if (local_5f4 != 0) {
              if (*(char **)(local_5f4 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5f4 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x15] = lVar8;
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e954);
            if (local_640 != 0) {
              if (*(char **)(local_640 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_640 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0xd] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("mag_ratio_table_id");
            if (local_5fc != 0) {
              if (*(char **)(local_5fc + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5fc + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0xe] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("mag_per_level");
            if (local_660 != 0) {
              if (*(char **)(local_660 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_660 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0xf] = lVar8;
          }
          FUN_00719da0(&local_584);
          if (local_584 != 0) {
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0e98c);
            if (local_604 != 0) {
              if (*(char **)(local_604 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_604 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][1] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("minlv");
            if (local_648 != 0) {
              if (*(char **)(local_648 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_648 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x1e] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("maxlv");
            if (local_60c != 0) {
              if (*(char **)(local_60c + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_60c + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x1f] = lVar8;
          }
          FUN_00719da0(&local_594);
          if (local_594 != 0) {
            uVar22 = 0;
            FUN_0071baa0("minrank");
            if (local_64c != 0) {
              if (*(char **)(local_64c + 8) == (char *)0x0) {
                uVar22 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_64c + 8),(char **)0x0,10);
                uVar22 = (undefined2)lVar8;
              }
            }
            *(undefined2 *)(local_56c[2] + 0x24) = uVar22;
            uVar22 = 0;
            FUN_0071baa0("maxrank");
            if (local_614 != 0) {
              if (*(char **)(local_614 + 8) == (char *)0x0) {
                uVar22 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_614 + 8),(char **)0x0,10);
                uVar22 = (undefined2)lVar8;
              }
            }
            *(undefined2 *)((int)local_56c[2] + 0x92) = uVar22;
          }
          FUN_00719da0(&local_590);
          if (local_590 != 0) {
            uVar22 = 0;
            FUN_0071baa0("minrank");
            if (local_654 != 0) {
              if (*(char **)(local_654 + 8) == (char *)0x0) {
                uVar22 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_654 + 8),(char **)0x0,10);
                uVar22 = (undefined2)lVar8;
              }
            }
            *(undefined2 *)(local_56c[2] + 0x25) = uVar22;
            uVar22 = 0;
            FUN_0071baa0("maxrank");
            if (local_61c != 0) {
              if (*(char **)(local_61c + 8) == (char *)0x0) {
                uVar22 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_61c + 8),(char **)0x0,10);
                uVar22 = (undefined2)lVar8;
              }
            }
            *(undefined2 *)((int)local_56c[2] + 0x96) = uVar22;
          }
          FUN_00719da0(&local_588);
          if (local_588 != 0) {
            lVar8 = 0;
            FUN_0071baa0("can_change_look");
            if (local_670 != 0) {
              if (*(char **)(local_670 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_670 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x22] = lVar8;
            lVar8 = 0;
            FUN_0071baa0("can_extract_look");
            if (local_5bc != 0) {
              if (*(char **)(local_5bc + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5bc + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x23] = lVar8;
          }
          FUN_00719da0(&local_5b4);
          if (local_5b4 != 0) {
            lVar8 = 0;
            FUN_0071baa0("contract");
            if (local_5c0 != 0) {
              if (*(char **)(local_5c0 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5c0 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x20] = lVar8;
          }
          FUN_00719da0(&local_598);
          if (local_598 != 0) {
            lVar8 = 0;
            FUN_0071baa0("group");
            if (local_5c8 != 0) {
              if (*(char **)(local_5c8 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5c8 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x1c] = lVar8;
          }
          FUN_00719da0(&local_5a0);
          if (local_5a0 != 0) {
            lVar8 = 0;
            FUN_0071baa0("grade");
            if (local_5d0 != 0) {
              if (*(char **)(local_5d0 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5d0 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x16] = lVar8;
          }
          FUN_00719da0(&local_5a8);
          if (local_5a8 != 0) {
            lVar8 = 0;
            FUN_0071baa0(&DAT_00c0ea40);
            if (local_5d8 != 0) {
              if (*(char **)(local_5d8 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5d8 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x17] = lVar8;
          }
          FUN_00719da0(&local_59c);
          if (local_59c != 0) {
            lVar8 = 0;
            FUN_0071baa0("target");
            if (local_5e0 != 0) {
              if (*(char **)(local_5e0 + 8) == (char *)0x0) {
                lVar8 = 0;
              }
              else {
                lVar8 = _strtol(*(char **)(local_5e0 + 8),(char **)0x0,10);
              }
            }
            local_56c[2][0x1b] = lVar8;
          }
          FUN_00719da0(&local_5a4);
          if (local_5a4 != 0) {
            local_56d = '\x01';
            FUN_00719da0(&local_580);
            while (local_580 != 0) {
              if (local_56d == '\0') {
                uVar10 = 2;
                puVar25 = &DAT_00c02b94;
LAB_005222e9:
                FUN_00404300(puVar25,uVar10);
              }
              else if (local_56c[2][0x31] != 0) {
                uVar10 = 1;
                puVar25 = &DAT_00bfb894;
                goto LAB_005222e9;
              }
              lVar8 = 0;
              FUN_0071baa0("status");
              if (local_5e8 != 0) {
                if (*(char **)(local_5e8 + 8) == (char *)0x0) {
                  lVar8 = 0;
                }
                else {
                  lVar8 = _strtol(*(char **)(local_5e8 + 8),(char **)0x0,10);
                }
              }
              puVar21 = (uint *)0x0;
              local_56c[0] = (uint *)0x0;
              FUN_0071baa0("value");
              if (local_5f0 != 0) {
                if (*(char **)(local_5f0 + 8) == (char *)0x0) {
                  puVar21 = (uint *)0x0;
                  local_56c[0] = puVar21;
                }
                else {
                  puVar21 = (uint *)_strtol(*(char **)(local_5f0 + 8),(char **)0x0,10);
                  local_56c[0] = puVar21;
                }
              }
              local_67c = lVar8;
              local_678 = puVar21;
              FUN_004fc620();
              iVar9 = DAT_00fc0e34;
              local_5f8 = lVar8;
              FUN_005740f0(&local_5f8);
              if (local_600 != *(int *)(iVar9 + 0xc)) {
                _Str = (wchar_t *)(local_600 + 0x10);
                if (7 < *(uint *)(local_600 + 0x24)) {
                  _Str = *(wchar_t **)_Str;
                }
                if (_Str != (wchar_t *)0x0) {
                  if (puVar21 == (uint *)0x0) {
                    uVar10 = FUN_004ed610();
                    local_8._0_1_ = 7;
                    FUN_004041f0(uVar10,0,0xffffffff);
                  }
                  else {
                    local_218 = 0;
                    _memset(local_216,0,0x1fe);
                    pwVar13 = _wcsstr(_Str,L"%");
                    _wcsstr(_Str,L"10x");
                    iVar9 = (int)local_420 - (int)_Str;
                    do {
                      wVar2 = *_Str;
                      *(wchar_t *)(iVar9 + (int)_Str) = wVar2;
                      _Str = _Str + 1;
                    } while (wVar2 != L'\0');
                    local_5ac = (wchar_t *)0x0;
                    _wcstok_s(local_420,L"(",&local_5ac);
                    if (local_5ac != (wchar_t *)0x0) {
                      *local_5ac = L'\0';
                    }
                    psVar19 = &DAT_00c02bac;
                    if ((int)local_56c[0] < 0) {
                      psVar19 = &DAT_00bed1fc;
                    }
                    local_428 = 7;
                    local_42c = 0;
                    local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
                    psVar14 = psVar19;
                    do {
                      sVar1 = *psVar14;
                      psVar14 = psVar14 + 1;
                    } while (sVar1 != 0);
                    FUN_00402160(psVar19,(int)psVar14 - (int)(psVar19 + 1) >> 1);
                    local_8._0_1_ = 8;
                    uVar10 = FUN_0040ef80();
                    local_8._0_1_ = 9;
                    FUN_004041f0(uVar10,0,0xffffffff);
                    local_8._0_1_ = 8;
                    if (7 < local_460) {
                      FUN_0089120c(local_474);
                    }
                    psVar19 = &DAT_00c02ba8;
                    if (pwVar13 == (wchar_t *)0x0) {
                      psVar19 = &DAT_00bed1fc;
                    }
                    psVar14 = psVar19;
                    do {
                      sVar1 = *psVar14;
                      psVar14 = psVar14 + 1;
                    } while (sVar1 != 0);
                    FUN_00404300(psVar19,(int)psVar14 - (int)(psVar19 + 1) >> 1);
                    pppppppuVar15 = local_43c[0];
                    if (local_428 < 8) {
                      pppppppuVar15 = local_43c;
                    }
                    FUN_0040aeb0(L"%s : %s",local_420,pppppppuVar15);
                    psVar19 = &local_218;
                    do {
                      sVar1 = *psVar19;
                      psVar19 = psVar19 + 1;
                    } while (sVar1 != 0);
                    FUN_00404300(&local_218,(int)psVar19 - (int)local_216 >> 1);
                  }
                  local_8._0_1_ = 3;
                  if (7 < local_428) {
                    local_8._0_1_ = 3;
                    FUN_0089120c(local_43c[0]);
                  }
                  local_56d = '\0';
                }
              }
              piVar7 = (int *)FUN_00719e00(local_688);
              local_580 = *piVar7;
            }
          }
          FUN_00719da0(&local_57c);
          if ((local_57c != (uint *)0x0) && (FUN_00719da0(&local_58c), local_58c != (uint *)0x0)) {
LAB_00522680:
            puVar21 = local_58c;
            puVar24 = (uint *)0x0;
            FUN_0071baa0(&DAT_00c0ea84);
            if (local_608 != 0) {
              if (*(char **)(local_608 + 8) == (char *)0x0) {
                puVar24 = (uint *)0x0;
              }
              else {
                puVar24 = (uint *)_strtol(*(char **)(local_608 + 8),(char **)0x0,10);
              }
            }
            puVar5 = local_56c[2];
            ppuVar3 = (uint **)local_56c[2][0x4f];
            local_56c[0] = puVar24;
            if (local_56c < ppuVar3) {
              ppuVar4 = (uint **)local_56c[2][0x4e];
              if (local_56c < ppuVar4) goto LAB_0052271f;
              if (ppuVar3 == (uint **)local_56c[2][0x50]) {
                FUN_006d6240();
              }
              if ((undefined4 *)puVar5[0x4f] != (undefined4 *)0x0) {
                *(undefined4 *)puVar5[0x4f] =
                     *(undefined4 *)(puVar5[0x4e] + ((int)local_56c - (int)ppuVar4 >> 2) * 4);
              }
            }
            else {
LAB_0052271f:
              if (ppuVar3 == (uint **)local_56c[2][0x50]) {
                FUN_006d6240();
              }
              if ((undefined4 *)puVar5[0x4f] != (undefined4 *)0x0) {
                *(undefined4 *)puVar5[0x4f] = puVar24;
              }
            }
            puVar5[0x4f] = puVar5[0x4f] + 4;
            if (puVar21 != (uint *)0x0) {
              for (puVar21 = (uint *)puVar21[6]; puVar21 != (uint *)0x0;
                  puVar21 = (uint *)puVar21[6]) {
                if (((char *)puVar21[2] != (char *)0x0) &&
                   (iVar9 = __stricmp("EQUIP_POS",(char *)puVar21[2]), iVar9 == 0))
                goto LAB_00522780;
              }
            }
            goto LAB_005227be;
          }
LAB_005227d0:
          puVar21 = local_56c[1];
          if (local_56c[1] != (uint *)0x0) {
            for (puVar24 = (uint *)local_56c[1][4]; puVar24 != (uint *)0x0;
                puVar24 = (uint *)puVar24[6]) {
              if (((char *)puVar24[2] != (char *)0x0) &&
                 (iVar9 = __stricmp("UNIDENTIFIED",(char *)puVar24[2]), iVar9 == 0)) {
                if (puVar24 == (uint *)0x0) goto LAB_00522850;
                goto LAB_0052281b;
              }
            }
            goto LAB_005228ed;
          }
          goto LAB_005229e3;
        }
        goto LAB_00522a86;
      }
LAB_00522b08:
      local_8 = 0xffffffff;
      FUN_00401000();
      goto LAB_00522b1f;
    }
  }
  local_8 = 0xffffffff;
  if (0xf < local_480) {
    FUN_0089120c(local_494);
  }
  local_480 = 0xf;
  local_484 = 0;
  local_494 = local_494 & 0xffffff00;
  FUN_0071bc90(local_56c + 3);
LAB_00522b1f:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_00522780:
  do {
    if (puVar21 != (uint *)0x0) {
      if ((*puVar21 & 7) == 1) goto LAB_005227c0;
      for (puVar21 = (uint *)puVar21[6]; puVar21 != (uint *)0x0; puVar21 = (uint *)puVar21[6]) {
        if (((char *)puVar21[2] != (char *)0x0) &&
           (iVar9 = __stricmp("EQUIP_POS",(char *)puVar21[2]), iVar9 == 0)) goto LAB_005227b8;
      }
    }
    puVar21 = (uint *)0x0;
LAB_005227b8:
  } while (puVar21 != (uint *)0x0);
LAB_005227be:
  puVar21 = (uint *)0x0;
LAB_005227c0:
  local_58c = puVar21;
  if (puVar21 == (uint *)0x0) goto LAB_005227d0;
  goto LAB_00522680;
LAB_0052281b:
  do {
    if ((*puVar24 & 7) == 1) {
      lVar8 = 0;
      local_56c[0] = puVar24;
      FUN_0071baa0("origin");
      if (local_610 != 0) {
        if (*(char **)(local_610 + 8) == (char *)0x0) {
          lVar8 = 0;
        }
        else {
          lVar8 = _strtol(*(char **)(local_610 + 8),(char **)0x0,10);
        }
      }
      puVar21 = local_56c[2];
      local_56c[2][0x18] = lVar8;
      lVar8 = 0;
      FUN_0071baa0("option_level");
      if (local_618 != 0) {
        if (*(char **)(local_618 + 8) == (char *)0x0) {
          lVar8 = 0;
        }
        else {
          lVar8 = _strtol(*(char **)(local_618 + 8),(char **)0x0,10);
        }
      }
      puVar21[0x1a] = lVar8;
      puVar21 = local_56c[1];
      break;
    }
    for (puVar24 = (uint *)puVar24[6]; puVar24 != (uint *)0x0; puVar24 = (uint *)puVar24[6]) {
      if (((char *)puVar24[2] != (char *)0x0) &&
         (iVar9 = __stricmp("UNIDENTIFIED",(char *)puVar24[2]), iVar9 == 0)) goto LAB_00522852;
    }
LAB_00522850:
    puVar24 = (uint *)0x0;
LAB_00522852:
  } while (puVar24 != (uint *)0x0);
LAB_005228ed:
  for (puVar21 = (uint *)puVar21[4]; puVar21 != (uint *)0x0; puVar21 = (uint *)puVar21[6]) {
    if (((char *)puVar21[2] != (char *)0x0) &&
       (iVar9 = __stricmp("ORIGIN",(char *)puVar21[2]), iVar9 == 0)) {
      local_56c[0] = puVar21;
      if (puVar21 == (uint *)0x0) goto LAB_00522934;
      goto LAB_00522929;
    }
  }
LAB_005229e3:
  uVar10 = local_630;
  switch(local_56c[2][2]) {
  case 6:
  case 0x17:
  case 0x18:
    *(undefined1 *)(local_56c[2] + 0x3b) = 0xff;
    break;
  case 0x16:
    if ((char)local_56c[2][0x3b] == '\0') {
      *(undefined1 *)(local_56c[2] + 0x3b) = 2;
    }
  }
  local_684 = *local_56c[2];
  local_680 = (int *)local_56c[2];
  uVar17 = FUN_0057ef20();
  FUN_0057e850(uVar10,uVar17);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_444) {
    FUN_0089120c(local_458[0]);
  }
  local_444 = 7;
  local_448 = 0;
  local_458[0] = (short *******)((uint)local_458[0] & 0xffff0000);
  puVar21 = local_56c[1];
LAB_00522a86:
  if (puVar21 != (uint *)0x0) {
    for (puVar21 = (uint *)puVar21[6]; puVar21 != (uint *)0x0; puVar21 = (uint *)puVar21[6]) {
      if (((char *)puVar21[2] != (char *)0x0) &&
         (iVar9 = __stricmp("ITEM",(char *)puVar21[2]), iVar9 == 0)) {
        if (puVar21 == (uint *)0x0) goto LAB_00522af0;
        goto LAB_00522ab9;
      }
    }
  }
LAB_00522af6:
  puVar21 = (uint *)0x0;
LAB_00522af8:
  local_56c[1] = puVar21;
  if (puVar21 == (uint *)0x0) goto LAB_00522b08;
  goto LAB_005214e0;
LAB_00522934:
  while( true ) {
    puVar16 = (undefined4 *)FUN_0071bb00("ORIGIN");
    puVar21 = (uint *)*puVar16;
    local_56c[0] = puVar21;
    if (puVar21 == (uint *)0x0) break;
LAB_00522929:
    local_56c[0] = puVar21;
    if ((*puVar21 & 7) == 1) {
      lVar8 = 0;
      FUN_0071baa0("origin");
      if (local_620 != 0) {
        if (*(char **)(local_620 + 8) == (char *)0x0) {
          lVar8 = 0;
        }
        else {
          lVar8 = _strtol(*(char **)(local_620 + 8),(char **)0x0,10);
        }
      }
      puVar21 = local_56c[2];
      local_56c[2][0x18] = lVar8;
      lVar8 = 0;
      FUN_0071baa0("class");
      if (local_5b0 != 0) {
        if (*(char **)(local_5b0 + 8) == (char *)0x0) {
          lVar8 = 0;
        }
        else {
          lVar8 = _strtol(*(char **)(local_5b0 + 8),(char **)0x0,10);
        }
      }
      puVar21[0x19] = lVar8;
      break;
    }
  }
  goto LAB_005229e3;
LAB_00522ab9:
  do {
    if ((*puVar21 & 7) == 1) goto LAB_00522af8;
    for (puVar21 = (uint *)puVar21[6]; puVar21 != (uint *)0x0; puVar21 = (uint *)puVar21[6]) {
      if (((char *)puVar21[2] != (char *)0x0) &&
         (iVar9 = __stricmp("ITEM",(char *)puVar21[2]), iVar9 == 0)) goto LAB_00522af2;
    }
LAB_00522af0:
    puVar21 = (uint *)0x0;
LAB_00522af2:
  } while (puVar21 != (uint *)0x0);
  goto LAB_00522af6;
}

