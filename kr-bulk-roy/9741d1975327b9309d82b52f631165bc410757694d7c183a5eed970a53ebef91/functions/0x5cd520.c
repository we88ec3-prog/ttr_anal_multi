
/* WARNING: Type propagation algorithm not settling */

void FUN_005cd520(int param_1)

{
  ushort uVar1;
  code *pcVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *******pppppppuVar11;
  int iVar12;
  ushort *******pppppppuVar13;
  int *piVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined4 uStack_ec;
  int *piStack_e8;
  int iStack_e4;
  uint uStack_e0;
  int local_dc;
  int *piStack_d8;
  int *piStack_d4;
  int iStack_d0;
  int *piStack_cc;
  int *piStack_c8;
  int iStack_c4;
  undefined4 uStack_c0;
  int iStack_bc;
  uint uStack_b8;
  undefined4 *puStack_b4;
  undefined4 *puStack_b0;
  uint uStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  undefined4 *******pppppppuStack_54;
  int iStack_50;
  undefined4 uStack_44;
  uint uStack_40;
  ushort *******apppppppuStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f529;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_ec;
  ExceptionList = &local_14;
  local_dc = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff08);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  if ((DAT_00fba7a4 != (int *)0x0) &&
     (iVar5 = (**(code **)(*DAT_00fba7a4 + 0x1c))(0), iStack_98 = iVar5, iVar5 != 0)) {
    iStack_64 = *(int *)(iVar5 + 0x3c8);
    iStack_60 = *(int *)(iVar5 + 0x3cc);
    iStack_a0 = *(int *)(iVar5 + 0x3d0);
    piStack_c8 = (int *)(uint)*(ushort *)(iVar5 + 0x88);
    uStack_c0 = *(undefined4 *)(iVar5 + 0x400);
    uStack_e0 = *(uint *)(iVar5 + 0x404);
    iStack_bc = *(int *)(iVar5 + 0x408);
    FUN_0040f060();
    iStack_c4 = DAT_00fba7a4[4];
    uStack_24 = 7;
    uStack_28 = 0;
    apppppppuStack_38[0] = (ushort *******)((uint)apppppppuStack_38[0] & 0xffff0000);
    local_c = 0;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_c = 2;
      FUN_00590760();
      _atexit((_func_4879 *)&LAB_00bce760);
    }
    puStack_b4 = (undefined4 *)0x0;
    puStack_b0 = (undefined4 *)0x0;
    uStack_ac = 0;
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_006d4dc0(0x10,2);
    FUN_00402160(&DAT_00bed1fc,0);
    puVar16 = puStack_b4;
    if (puStack_b4 == puStack_b0) {
      FUN_0041f490(apppppppuStack_38);
    }
    else {
      FUN_00594a80(*puStack_b4);
      puVar16 = puStack_b4;
    }
    local_c._0_1_ = 1;
    if (puVar16 != (undefined4 *)0x0) {
      FUN_0089120c(puVar16);
    }
    iVar8 = local_dc;
    pppppppuVar13 = apppppppuStack_38[0];
    if (uStack_24 < 8) {
      pppppppuVar13 = (ushort *******)apppppppuStack_38;
    }
    if (*(uint *)(local_dc + 0x198) < 8) {
      puVar6 = (ushort *)(local_dc + 0x184);
    }
    else {
      puVar6 = *(ushort **)(local_dc + 0x184);
    }
    do {
      uVar1 = *puVar6;
      bVar18 = uVar1 < *(ushort *)pppppppuVar13;
      if (uVar1 != *(ushort *)pppppppuVar13) {
LAB_005cd74c:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_005cd751;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar6[1];
      bVar18 = uVar1 < *(ushort *)((int)pppppppuVar13 + 2);
      if (uVar1 != *(ushort *)((int)pppppppuVar13 + 2)) goto LAB_005cd74c;
      puVar6 = puVar6 + 2;
      pppppppuVar13 = pppppppuVar13 + 1;
    } while (uVar1 != 0);
    iVar7 = 0;
LAB_005cd751:
    if (iVar7 != 0) {
      FUN_00757800(apppppppuStack_38);
      (**(code **)(**(int **)(iVar8 + 0x2e0) + 200))();
      FUN_004026e0(apppppppuStack_38,0,0xffffffff);
    }
    iVar8 = FUN_00404ba0();
    if ((((piStack_c8 < (int *)0xa) &&
         (iVar8 = (int)piStack_c8 * 0x210 + *(int *)(iVar8 + 0x6924), *(int *)(iVar8 + 0x5c) != 0))
        && (iVar8 != 0)) && (iStack_9c = iVar8 + 500, iStack_9c != 0)) {
      iStack_d0 = CONCAT31(iStack_d0._1_3_,
                           *(undefined1 *)((uint)(*(char *)(iVar8 + 0x1f6) != '\0') + iStack_9c));
      piVar9 = piStack_c8;
      iVar7 = iStack_d0;
      FUN_0040f7f0(piStack_c8,iStack_d0);
      piStack_c8 = (int *)FUN_00819220(piVar9,iVar7);
      if (((piStack_c8 == (int *)0x0) || (*(int *)(iVar8 + 0x5c) == 0)) ||
         ((iVar8 == 0 || (iVar8 = iVar8 + 0x1d4, iStack_a4 = iVar8, iVar8 == 0)))) {
        FUN_004fa440();
        goto LAB_005ce392;
      }
      if (*(char *)(local_dc + 0x37c) == '\0') {
        piStack_cc = *(int **)(iVar5 + 1000);
        iStack_d0 = 1;
      }
      else {
        piStack_cc = (int *)0x0;
        iStack_d0 = 3;
      }
      piStack_d8 = (int *)0x0;
      if (iStack_d0 != 0) {
        piVar9 = (int *)(local_dc + 0x10c);
        do {
          if (*(char *)(local_dc + 0x37c) == '\0') {
            piStack_e8 = piStack_cc;
          }
          else {
            piStack_e8 = piStack_d8;
          }
          iStack_94 = 0;
          do {
            iVar5 = iStack_94;
            uStack_40 = 7;
            uStack_44 = 0;
            pppppppuStack_54 = (undefined4 *******)((uint)pppppppuStack_54 & 0xffff0000);
            piStack_d4 = piVar9;
            if ((DAT_00fdfb10 & 1) == 0) {
              DAT_00fdfb10 = DAT_00fdfb10 | 1;
              local_c._0_1_ = 0xe;
              FUN_00590760();
              _atexit((_func_4879 *)&LAB_00bce760);
            }
            local_c._0_1_ = 0xd;
            FUN_00594610(&DAT_00fdfb18,1);
            if (((byte)piStack_e8 < 4) && ((byte)(iVar5 + 1U) < 0xb)) {
              uStack_b8 = (uint)*(ushort *)
                                 ((int)piStack_c8 +
                                 (((uint)piStack_e8 & 0xff) * 0xb + (iVar5 + 1U & 0xff)) * 2 + 4);
            }
            else {
              uStack_b8 = 0;
            }
            FUN_00826280(&uStack_b8);
            if (((iStack_5c == *(int *)(iVar8 + 4)) ||
                (puVar16 = *(undefined4 **)(iStack_5c + 0x10), puVar16 == (undefined4 *)0x0)) ||
               (*(ushort *)(puVar16 + 1) == 0)) {
              pppppppuVar11 = pppppppuStack_54;
              if (uStack_40 < 8) {
                pppppppuVar11 = &pppppppuStack_54;
              }
              (**(code **)(*(int *)*piVar9 + 0x1a4))(0xffffffff,0,pppppppuVar11);
            }
            else {
              uVar19 = *puVar16;
              uStack_b8 = (uint)*(ushort *)(puVar16 + 1);
              uVar10 = FUN_00484eb0();
              iVar8 = FUN_00530530(uVar10);
              uVar10 = FUN_00484eb0();
              iStack_90 = FUN_005305c0(uVar10);
              uVar10 = FUN_00484eb0();
              iStack_e4 = FUN_00530650(uVar10);
              FUN_00830e10();
              local_c._0_1_ = 0xf;
              uStack_8c = (undefined4 *)0x0;
              uStack_6c = 0;
              uStack_88 = 0;
              uStack_84 = 0;
              uStack_68 = 0;
              cVar3 = FUN_005cf550(&uStack_8c,uVar19);
              uVar15 = uStack_ec;
              iVar5 = iStack_90;
              if (cVar3 != '\0') {
                iVar8 = iVar8 + (short)uStack_8c +
                        ((int)uStack_88._2_2_ * (iVar8 + (short)uStack_8c)) / 100;
                iVar5 = iStack_90 + uStack_8c._2_2_ +
                        ((int)(short)uStack_84 * (iStack_90 + uStack_8c._2_2_)) / 100;
                iStack_e4 = iStack_e4 + (short)uStack_88 +
                            ((int)uStack_84._2_2_ * (iStack_e4 + (short)uStack_88)) / 100;
              }
              uStack_ec = CONCAT13(1,(undefined3)uStack_ec);
              if (iVar8 + iStack_64 < 0) {
                uStack_ec = uVar15 & 0xffffff;
              }
              if (iVar5 + iStack_60 < 0) {
                uStack_ec = uStack_ec & 0xffffff;
              }
              if (iStack_e4 + iStack_a0 < 0) {
                uStack_ec = uStack_ec & 0xffffff;
              }
              cVar3 = FUN_005ceb90(iStack_98,uVar19);
              piVar9 = piStack_d4;
              if (cVar3 == '\0') {
                cVar3 = uStack_ec._3_1_;
              }
              else {
                cVar3 = '\0';
              }
              if ((*(char *)(local_dc + 0x37d) == '\0') && (cVar3 != '\0')) {
                pppppppuVar11 = pppppppuStack_54;
                if (uStack_40 < 8) {
                  pppppppuVar11 = &pppppppuStack_54;
                }
                (**(code **)(*(int *)*piStack_d4 + 0x1a4))(uVar19,uStack_b8,pppppppuVar11);
                piVar14 = *(int **)(*piVar9 + 0x250);
                if (piVar14 != (int *)0x0) {
                  uVar19 = 1;
LAB_005cdb57:
                  (**(code **)(*piVar14 + 0x90))(uVar19);
                }
              }
              else {
                pppppppuVar11 = pppppppuStack_54;
                if (uStack_40 < 8) {
                  pppppppuVar11 = &pppppppuStack_54;
                }
                (**(code **)(*(int *)*piStack_d4 + 0x1a4))(uVar19,uStack_b8,pppppppuVar11);
                piVar14 = *(int **)(*piVar9 + 0x250);
                if (piVar14 != (int *)0x0) {
                  uVar19 = 0;
                  goto LAB_005cdb57;
                }
              }
              FUN_00484eb0();
              iVar5 = FUN_005302d0();
              if (iVar5 == 1) {
LAB_005cdbcc:
                iVar5 = *(int *)(*piVar9 + 0x288);
                piVar9 = *(int **)(*piVar9 + 0x284);
                if (iVar5 == 0) {
                  iVar8 = *piVar9;
                  piVar9 = piStack_cc;
LAB_005cdc19:
                  (**(code **)(iVar8 + 0x94))(piVar9 != (int *)0x0);
                }
                else if (iVar5 == 1) {
                  (**(code **)(*piVar9 + 0x94))(uStack_ec != 0);
                }
                else {
                  iVar8 = *piVar9;
                  piVar9 = piStack_c8;
                  if (iVar5 == 2) goto LAB_005cdc19;
                  (**(code **)(iVar8 + 0x94))(0);
                }
              }
              else {
                FUN_00484eb0();
                iVar5 = FUN_005302d0();
                if (iVar5 == 2) goto LAB_005cdbcc;
                FUN_00484eb0();
                iVar5 = FUN_005302d0();
                if (iVar5 == 8) goto LAB_005cdbcc;
                FUN_00484eb0();
                iVar5 = FUN_005302d0();
                if (iVar5 == 9) goto LAB_005cdbcc;
                FUN_00484eb0();
                iVar5 = FUN_005302d0();
                if (iVar5 == 0xb) goto LAB_005cdbcc;
                (**(code **)(**(int **)(*piVar9 + 0x284) + 0x94))(0);
              }
              piStack_c8 = &iStack_90;
              local_1c = CONCAT31(local_1c._1_3_,0x10);
              FUN_004ca160(*uStack_8c,uStack_8c);
              FUN_0089120c(uStack_8c);
              iVar5 = iStack_94;
              piVar9 = piStack_d4;
              iVar8 = iStack_a4;
            }
            local_c._0_1_ = 1;
            if (7 < uStack_40) {
              FUN_0089120c(pppppppuStack_54);
            }
            iStack_94 = iVar5 + 1;
            piVar9 = piVar9 + 1;
          } while (iStack_94 < 6);
          piStack_d8 = (int *)((int)piStack_d8 + 1);
          piStack_d4 = piVar9;
        } while ((int)piStack_d8 < iStack_d0);
      }
      if (iStack_c4 != 0) {
        piStack_d4 = (int *)0x0;
        do {
          puStack_b4 = (undefined4 *)0x0;
          puStack_b0 = (undefined4 *)0x0;
          uStack_c0 = CONCAT31(uStack_c0._1_3_,
                               *(undefined1 *)((uint)(*(char *)(iStack_9c + 2) != '\0') + iStack_9c)
                              );
          iVar8 = FUN_0054f330(iStack_c4,uStack_c0,0,10,&puStack_b4);
          puVar16 = puStack_b0;
          iVar5 = 0;
          if ((iVar8 != 0) && (puStack_b0 != (undefined4 *)0x0)) {
            iVar5 = FUN_00403470();
            uStack_e0 = ((int)puStack_b4 - (int)puVar16) % (int)puStack_b4;
            iVar8 = FUN_008fed10();
            iVar5 = *(int *)(iVar5 + 0xb0 + iVar8 * 4);
          }
          iVar8 = local_dc;
          if (*(int *)(local_dc + 0x260) != iVar5) {
            FUN_00745100();
            (**(code **)(**(int **)(iVar8 + 0x264) + 200))();
            *(int *)(iVar8 + 0x260) = iVar5;
          }
          iStack_d0 = (int)piStack_d4 * 6;
          piStack_e8 = (int *)(iVar8 + 0x298 + (int)piStack_d4 * 0x18);
          iStack_e4 = 0;
          piStack_d8 = (int *)0x0;
          do {
            piVar9 = piStack_d8;
            piVar14 = piStack_d4;
            if (piStack_d4 == (int *)0x0) {
              piVar14 = piStack_cc;
            }
            iVar5 = (int)piStack_d8 + (int)piVar14 * 6;
            iVar8 = local_dc + 0x298;
            if (0 < *(int *)(local_dc + 0x298 + iVar5 * 4)) {
              if ((DAT_00f94394 & 1) == 0) {
                DAT_00f94394 = DAT_00f94394 | 1;
                local_c._0_1_ = 0x11;
                FUN_005c3de0();
                _atexit((_func_4879 *)&LAB_00bccc30);
                local_c._0_1_ = 1;
              }
              uStack_e0 = (0xf - *(int *)(iVar8 + iVar5 * 4)) % 0xf;
              iVar5 = FUN_008fed10();
              iStack_e4 = *(int *)(&DAT_00f944b0 + iVar5 * 4);
            }
            if (*piStack_e8 < 1) {
              pppppppuStack_54 = (undefined4 *******)0x0;
              iStack_50 = 0;
              iStack_bc = CONCAT31(iStack_bc._1_3_,
                                   *(undefined1 *)
                                    ((uint)(*(char *)(iStack_9c + 2) != '\0') + iStack_9c));
              iVar8 = FUN_0054f330(iStack_c4,iStack_bc,piVar14,(&DAT_00f832d4)[(int)piVar9 * 4],
                                   &pppppppuStack_54);
              iVar5 = iStack_50;
              if ((iVar8 == 0) || (iStack_50 == 0)) {
                iStack_e4 = 0;
              }
              else {
                if ((DAT_00f94394 & 1) == 0) {
                  DAT_00f94394 = DAT_00f94394 | 1;
                  local_c._0_1_ = 0x12;
                  FUN_005c3de0();
                  _atexit((_func_4879 *)&LAB_00bccc30);
                  local_c._0_1_ = 1;
                }
                uStack_e0 = ((int)pppppppuStack_54 - iVar5) % (int)pppppppuStack_54;
                iVar7 = FUN_008fed10();
                iStack_e4 = *(int *)(&DAT_00f94448 + iVar7 * 4);
              }
              if (((iVar8 != 0) && (iVar5 != 0)) && (iVar5 == 1)) {
                *piStack_e8 = 0xf;
              }
            }
            else {
              *piStack_e8 = *piStack_e8 + -1;
            }
            iVar5 = local_dc;
            if (piStack_e8[-0x3e] != iStack_e4) {
              iVar12 = iStack_d0 + (int)piStack_d8;
              iVar7 = *(int *)(local_dc + 0x1e8 + iVar12 * 4);
              iVar8 = local_dc + 0x1e8;
              if (((*(char *)(iVar7 + 0xa4) != '\0') &&
                  (piVar9 = *(int **)(iVar7 + 0x94), piVar9 != (int *)0x0)) &&
                 (iVar7 = (**(code **)(*piVar9 + 4))(), iVar7 == 0xbf6b)) {
                FUN_0077b200();
                iVar5 = local_dc;
              }
              (**(code **)(**(int **)(iVar8 + iVar12 * 4) + 200))();
              if ((piStack_d4 != (int *)0x0) && (*(char *)(iVar5 + 0x37c) != '\0')) {
                iVar7 = iStack_d0 + (int)piStack_d8;
                iVar8 = *(int *)(iVar5 + 0x218 + iVar7 * 4);
                if ((*(char *)(iVar8 + 0xa4) != '\0') &&
                   ((piVar9 = *(int **)(iVar8 + 0x94), piVar9 != (int *)0x0 &&
                    (iVar8 = (**(code **)(*piVar9 + 4))(), iVar8 == 0xbf6b)))) {
                  FUN_0077b200();
                }
                (**(code **)(**(int **)(iVar5 + 0x218 + iVar7 * 4) + 200))();
              }
              piStack_e8[-0x3e] = iStack_e4;
              piVar9 = piStack_d8;
            }
            piStack_e8 = piStack_e8 + 1;
            piStack_d8 = (int *)((int)piVar9 + 1);
          } while ((int)piStack_d8 < 6);
          piStack_d4 = (int *)((int)piStack_d4 + 1);
        } while ((int)piStack_d4 < 3);
      }
      uVar15 = 0;
      piStack_d8 = (int *)0x94;
      do {
        piStack_e8 = (int *)0x0;
        do {
          puStack_b0 = (undefined4 *)0x0;
          uStack_ac = uStack_ac & 0xffffff00;
          iStack_a8 = 0;
          uStack_c0 = CONCAT31(uStack_c0._1_3_,
                               *(undefined1 *)((uint)(*(char *)(iStack_9c + 2) != '\0') + iStack_9c)
                              );
          iVar5 = FUN_0054f330(iStack_c4,uStack_c0,uVar15,(&DAT_00f832d4)[(int)piStack_e8 * 4],
                               &puStack_b4);
          puVar16 = puStack_b0;
          if (uVar15 != 0) {
            if (((byte)uVar15 < 4) && ((byte)((byte)piStack_e8 + 1) < 0xb)) {
              uStack_e0 = (uint)*(ushort *)
                                 ((int)piStack_c8 +
                                 ((uVar15 & 0xff) * 0xb + (uint)(byte)((byte)piStack_e8 + 1)) * 2 +
                                 4);
            }
            else {
              uStack_e0 = 0;
            }
            FUN_00826280(&uStack_e0);
            if (((iStack_bc == *(int *)(iStack_a4 + 4)) || (*(int *)(iStack_bc + 0x10) == 0)) ||
               (*(short *)(*(int *)(iStack_bc + 0x10) + 4) == 0)) {
LAB_005ce127:
              bVar4 = 0;
              piStack_cc = (int *)((uint)piStack_cc & 0xffffff00);
            }
            else {
              bVar4 = 1;
              piStack_cc = (int *)CONCAT31(piStack_cc._1_3_,1);
              if ((iVar5 != 0) && (puVar16 != (undefined4 *)0x0)) goto LAB_005ce127;
            }
            piVar9 = *(int **)(local_dc + ((int)piStack_d8 + (int)piStack_e8) * 4);
            if (((byte)((uint)piVar9[10] >> 9) & 1) != bVar4) {
              (**(code **)(*piVar9 + 0xa0))(piStack_cc);
            }
          }
          if (((iVar5 != 0) && (puVar16 == (undefined4 *)0x0)) && ((char)uStack_ac != '\0')) {
            if (((byte)uVar15 < 4) && ((byte)((byte)piStack_e8 + 1) < 0xb)) {
              uVar17 = (uint)*(ushort *)
                              ((int)piStack_c8 +
                              ((uVar15 & 0xff) * 0xb + (uint)(byte)((byte)piStack_e8 + 1)) * 2 + 4);
            }
            else {
              uVar17 = 0;
            }
            if ((DAT_00fc1094 & 1) == 0) {
              DAT_00fc1094 = DAT_00fc1094 | 1;
              local_c._0_1_ = 0x13;
              FUN_0052f7e0();
              _atexit((_func_4879 *)&LAB_00bcdc80);
              local_c._0_1_ = 1;
            }
            if (DAT_00fc10c8 == 0) {
LAB_005ce1e8:
              uStack_e0 = uVar17;
              FUN_008438c0(&uStack_e0);
              if (iStack_98 == DAT_00fc109c) {
                DAT_00fc10c8 = 0;
              }
              else {
                DAT_00fc10c8 = *(int *)(iStack_98 + 0x10);
              }
              if (DAT_00fc10c8 == 0) goto LAB_005ce34f;
            }
            else if (*(uint *)(DAT_00fc10c8 + 4) != uVar17) {
              DAT_00fc10c8 = 0;
              goto LAB_005ce1e8;
            }
            if (*(uint *)(DAT_00fc10c8 + 0x1c) < 8) {
              iVar5 = DAT_00fc10c8 + 8;
            }
            else {
              iVar5 = *(int *)(DAT_00fc10c8 + 8);
            }
            if (iVar5 != 0) {
              if ((DAT_00fe5b08 & 1) == 0) {
                DAT_00fe5b08 = DAT_00fe5b08 | 1;
                local_c._0_1_ = 0x14;
                FUN_00584c40(&DAT_00fe5ae8);
                _atexit((_func_4879 *)&LAB_00bcf380);
                local_c._0_1_ = 1;
              }
              uStack_e0 = 0x56;
              FUN_005740f0(&uStack_e0);
              if (iStack_a0 == DAT_00fe5aec) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              uVar19 = FUN_004ed610();
              if ((DAT_00fb11e0 & 1) == 0) {
                DAT_00fb11e0 = DAT_00fb11e0 | 1;
                local_c._0_1_ = 0x16;
                FUN_004d4d10();
                _atexit((_func_4879 *)&LAB_00bccef0);
              }
              local_c._0_1_ = 0x15;
              FUN_004d6b30(uVar19);
              local_c._0_1_ = 1;
              if (7 < uStack_40) {
                FUN_0089120c(pppppppuStack_54);
              }
              iStack_d0 = iStack_a8;
              if (iStack_a8 != 0) {
                iVar8 = iStack_c4 + 4;
                iVar5 = FUN_0054f4e0(iVar8);
                *(undefined1 *)(iVar5 + 8) = 0;
                iVar5 = FUN_0054f4e0(iVar8);
                *(undefined4 *)(iVar5 + 4) = 0;
              }
            }
          }
LAB_005ce34f:
          piStack_e8 = (int *)((int)piStack_e8 + 1);
        } while ((int)piStack_e8 < 6);
        piStack_d8 = (int *)((int)piStack_d8 + 6);
        uVar15 = uVar15 + 1;
      } while ((int)piStack_d8 < 0xa6);
    }
    if (7 < uStack_24) {
      FUN_0089120c(apppppppuStack_38[0]);
    }
  }
LAB_005ce392:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_ec);
  return;
}

