
void FUN_00511e40(void)

{
  code *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  __time32_t _Var7;
  char *****pppppcVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int *piVar14;
  uint uVar15;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int local_178;
  int iStack_174;
  uint uStack_170;
  int iStack_16c;
  undefined4 *local_168;
  undefined4 *local_164;
  int aiStack_160 [5];
  undefined4 *puStack_14c;
  uint local_140;
  undefined4 uStack_13c;
  int *piStack_138;
  int *piStack_134;
  int *local_130;
  uint local_12c;
  tm local_124;
  tm tStack_100;
  char ****appppcStack_dc [4];
  int iStack_cc;
  uint uStack_c8;
  char ****appppcStack_c0 [4];
  int iStack_b0;
  uint uStack_ac;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923ee1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_184;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffe70;
  ExceptionList = &local_14;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar4 = FUN_0072e2e0("CASH_PRODUCT_LIST");
    if (iVar4 == 0) {
      FUN_006edb60("Invalid CashProductList File");
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_178 = FUN_0072e360(uVar3);
      if (local_178 != 0) {
        do {
          local_168 = (undefined4 *)FUN_00891268(0x74);
          if (local_168 == (undefined4 *)0x0) {
            local_168 = (undefined4 *)0x0;
          }
          else {
            *local_168 = 0;
            local_168[5] = 0;
            local_168[6] = 7;
            *(undefined2 *)(local_168 + 1) = 0;
            local_168[8] = 0;
            local_168[9] = 0;
            *(undefined1 *)(local_168 + 10) = 0;
            local_168[0xb] = 0;
            local_168[0xc] = 0;
            local_168[0xd] = 0;
            local_168[0x13] = 7;
            local_168[0x12] = 0;
            *(undefined2 *)(local_168 + 0xe) = 0;
            local_168[0x15] = 0;
            local_168[0x16] = 0;
            local_168[0x17] = 0;
            local_168[0x19] = 0;
            local_168[0x1a] = 0;
            local_168[0x1b] = 0;
          }
          puVar9 = local_168;
          local_164 = local_168;
          iVar4 = FUN_007300a0("PRODUCT");
          if (iVar4 == 0) {
LAB_00512042:
            uVar6 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_00512042;
            uVar6 = FUN_008917b4(puVar5);
          }
          *puVar9 = uVar6;
          local_124.tm_year = 0xf;
          local_124.tm_mon = 0;
          local_124.tm_sec = local_124.tm_sec & 0xffffff00;
          FUN_00402a70("EXPLAIN",7);
          local_c._0_1_ = 1;
          uVar6 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,2);
          FUN_00440130(uVar6);
          if (0xf < local_12c) {
            FUN_0089120c(local_140);
          }
          local_c = local_c & 0xffffff00;
          local_12c = 0xf;
          local_130 = (int *)0x0;
          local_140 = local_140 & 0xffffff00;
          if (0xf < (uint)local_124.tm_year) {
            FUN_0089120c(local_124.tm_sec);
          }
          iVar4 = FUN_007300a0("NOW_SELLING");
          if (iVar4 == 0) {
LAB_00512112:
            uVar6 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_00512112;
            uVar6 = FUN_008917b4(puVar5);
          }
          puVar9[0xb] = uVar6;
          iVar4 = FUN_007300a0("SELLING_STATE");
          if (iVar4 == 0) {
LAB_0051213e:
            uVar6 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0051213e;
            uVar6 = FUN_008917b4(puVar5);
          }
          puVar9[8] = uVar6;
          iVar4 = FUN_007300a0("SELLING_TYPE");
          if (iVar4 == 0) {
LAB_0051216a:
            uVar6 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0051216a;
            uVar6 = FUN_008917b4(puVar5);
          }
          puVar9[9] = uVar6;
          iVar4 = FUN_007300a0("SHOP_TYPE");
          if (iVar4 == 0) {
LAB_00512196:
            uVar2 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_00512196;
            uVar2 = FUN_008917b4(puVar5);
          }
          *(undefined1 *)(puVar9 + 10) = uVar2;
          local_12c = 0xf;
          local_130 = (int *)0x0;
          local_140 = local_140 & 0xffffff00;
          FUN_00402a70("SELL_START_DAY",0xe);
          local_c._0_1_ = 3;
          FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,5);
          if (0xf < local_12c) {
            FUN_0089120c(local_140);
          }
          local_12c = 0xf;
          local_130 = (int *)0x0;
          local_140 = local_140 & 0xffffff00;
          if (iStack_cc != 0) {
            iStack_184 = 0;
            iStack_180 = 0;
            iStack_16c = 0;
            iStack_17c = 0;
            iStack_174 = 0;
            uStack_170 = 0;
            pppppcVar8 = (char *****)appppcStack_dc[0];
            if (uStack_c8 < 0x10) {
              pppppcVar8 = appppcStack_dc;
            }
            FID_conflict__sscanf
                      ((char *)pppppcVar8,"%04d-%02d-%02dT%02d:%02d:%02d",&iStack_184,&iStack_180,
                       &iStack_16c,&iStack_17c,&iStack_174,&uStack_170);
            local_124.tm_year = iStack_184 + -0x76c;
            local_124.tm_wday = 0;
            local_124.tm_yday = 0;
            local_124.tm_isdst = 0;
            local_124.tm_mon = iStack_180 + -1;
            local_124.tm_hour = iStack_17c;
            local_124.tm_mday = iStack_16c;
            local_124.tm_min = iStack_174;
            local_124.tm_sec = uStack_170;
            _Var7 = __mktime32(&local_124);
            puVar9[0xc] = _Var7;
          }
          local_124.tm_year = 0xf;
          local_124.tm_mon = 0;
          local_124.tm_sec = local_124.tm_sec & 0xffffff00;
          FUN_00402a70("SELL_END_DAY",0xc);
          local_c._0_1_ = 6;
          FUN_0072ecf0(&DAT_00bf2375);
          local_c._0_1_ = 8;
          if (0xf < (uint)local_124.tm_year) {
            FUN_0089120c(local_124.tm_sec);
          }
          local_124.tm_year = 0xf;
          local_124.tm_mon = 0;
          local_124.tm_sec = local_124.tm_sec & 0xffffff00;
          if (iStack_b0 != 0) {
            uStack_170 = 0;
            iStack_17c = 0;
            iStack_174 = 0;
            iStack_184 = 0;
            iStack_180 = 0;
            iStack_16c = 0;
            pppppcVar8 = (char *****)appppcStack_c0[0];
            if (uStack_ac < 0x10) {
              pppppcVar8 = appppcStack_c0;
            }
            FID_conflict__sscanf
                      ((char *)pppppcVar8,"%04d-%02d-%02dT%02d:%02d:%02d",&uStack_170,&iStack_17c,
                       &iStack_174,&iStack_184,&iStack_180,&iStack_16c);
            if (uStack_170 != 9999) {
              tStack_100.tm_wday = 0;
              tStack_100.tm_yday = 0;
              tStack_100.tm_isdst = 0;
              tStack_100.tm_year = uStack_170 - 0x76c;
              tStack_100.tm_mon = iStack_17c + -1;
              tStack_100.tm_hour = iStack_184;
              tStack_100.tm_mday = iStack_174;
              tStack_100.tm_min = iStack_180;
              tStack_100.tm_sec = iStack_16c;
              _Var7 = __mktime32(&tStack_100);
              puVar9[0xd] = _Var7;
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 9;
                FUN_00584c40(&DAT_00fe5ac4);
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c._0_1_ = 8;
              }
              aiStack_160[3] = 0x1c8;
              FUN_005740f0(aiStack_160 + 3);
              if (aiStack_160[2] == DAT_00fe5ac8) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              puVar9 = (undefined4 *)(aiStack_160[2] + 0x10);
              if (7 < *(uint *)(aiStack_160[2] + 0x24)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              uVar6 = FUN_00421540(puVar9,uStack_170);
              local_c._0_1_ = 10;
              FUN_00402800(uVar6);
              local_c._0_1_ = 8;
              if (7 < local_12c) {
                FUN_0089120c(local_140);
              }
            }
          }
          iVar4 = FUN_0072e360();
          if (iVar4 != 0) {
            iVar4 = FUN_0072e360();
            while (iVar4 != 0) {
              iVar12 = iVar4 + 0x44;
              for (iVar11 = *(int *)(iVar4 + 0x94); iVar11 != iVar12;
                  iVar11 = *(int *)(iVar11 + 0x50)) {
                pcVar13 = (char *)(iVar11 + 0x14);
                if (0xf < *(uint *)(iVar11 + 0x28)) {
                  pcVar13 = *(char **)pcVar13;
                }
                iVar10 = __stricmp(pcVar13,"QTY");
                if (iVar10 == 0) {
                  if (iVar11 != 0) {
                    puVar9 = (undefined4 *)(iVar11 + 0x30);
                    if (0xf < *(uint *)(iVar11 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      uStack_a4 = FUN_008917b4(puVar9);
                      goto LAB_005125ba;
                    }
                  }
                  break;
                }
              }
              uStack_a4 = 0;
LAB_005125ba:
              for (iVar11 = *(int *)(iVar4 + 0x94); iVar11 != iVar12;
                  iVar11 = *(int *)(iVar11 + 0x50)) {
                pcVar13 = (char *)(iVar11 + 0x14);
                if (0xf < *(uint *)(iVar11 + 0x28)) {
                  pcVar13 = *(char **)pcVar13;
                }
                iVar10 = __stricmp(pcVar13,"PERIOD");
                if (iVar10 == 0) {
                  if (iVar11 != 0) {
                    puVar9 = (undefined4 *)(iVar11 + 0x30);
                    if (0xf < *(uint *)(iVar11 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      uStack_a0 = FUN_008917b4(puVar9);
                      goto LAB_005125fa;
                    }
                  }
                  break;
                }
              }
              uStack_a0 = 0;
LAB_005125fa:
              for (iVar4 = *(int *)(iVar4 + 0x94); iVar4 != iVar12; iVar4 = *(int *)(iVar4 + 0x50))
              {
                pcVar13 = (char *)(iVar4 + 0x14);
                if (0xf < *(uint *)(iVar4 + 0x28)) {
                  pcVar13 = *(char **)pcVar13;
                }
                iVar11 = __stricmp(pcVar13,"PRICE");
                if (iVar11 == 0) {
                  if (iVar4 != 0) {
                    puVar9 = (undefined4 *)(iVar4 + 0x30);
                    if (0xf < *(uint *)(iVar4 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      uStack_9c = FUN_008917b4(puVar9);
                      goto LAB_0051263a;
                    }
                  }
                  break;
                }
              }
              uStack_9c = 0;
LAB_0051263a:
              FUN_0052ef90();
              iVar4 = FUN_0072e3c0();
            }
          }
          for (iVar4 = *(int *)(local_178 + 0x18); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
            pcVar13 = (char *)(iVar4 + 0x20);
            if (0xf < *(uint *)(iVar4 + 0x34)) {
              pcVar13 = *(char **)pcVar13;
            }
            iVar12 = __stricmp(pcVar13,"OPTION_LIST");
            if (iVar12 == 0) {
              if (iVar4 != 0) {
                iVar4 = FUN_0072e360();
                while (iStack_184 = iVar4, iVar4 != 0) {
                  piVar14 = (int *)0x0;
                  piStack_138 = (int *)0x0;
                  piStack_134 = (int *)0x0;
                  local_130 = (int *)0x0;
                  local_c._0_1_ = 0xb;
                  for (iVar12 = *(int *)(iVar4 + 0x94); iVar12 != iVar4 + 0x44;
                      iVar12 = *(int *)(iVar12 + 0x50)) {
                    pcVar13 = (char *)(iVar12 + 0x14);
                    if (0xf < *(uint *)(iVar12 + 0x28)) {
                      pcVar13 = *(char **)pcVar13;
                    }
                    iVar11 = __stricmp(pcVar13,"ID");
                    if (iVar11 == 0) {
                      if (iVar12 != 0) {
                        puVar9 = (undefined4 *)(iVar12 + 0x30);
                        if (0xf < *(uint *)(iVar12 + 0x44)) {
                          puVar9 = (undefined4 *)*puVar9;
                        }
                        if (puVar9 != (undefined4 *)0x0) {
                          local_140 = FUN_008917b4(puVar9);
                          goto LAB_005127a1;
                        }
                      }
                      break;
                    }
                  }
                  local_140 = 0;
LAB_005127a1:
                  for (iVar12 = *(int *)(iVar4 + 0x94); iVar12 != iVar4 + 0x44;
                      iVar12 = *(int *)(iVar12 + 0x50)) {
                    pcVar13 = (char *)(iVar12 + 0x14);
                    if (0xf < *(uint *)(iVar12 + 0x28)) {
                      pcVar13 = *(char **)pcVar13;
                    }
                    iVar11 = __stricmp(pcVar13,"RANK");
                    if (iVar11 == 0) {
                      if (iVar12 != 0) {
                        puVar9 = (undefined4 *)(iVar12 + 0x30);
                        if (0xf < *(uint *)(iVar12 + 0x44)) {
                          puVar9 = (undefined4 *)*puVar9;
                        }
                        if (puVar9 != (undefined4 *)0x0) {
                          uStack_13c = FUN_008917b4(puVar9);
                          goto LAB_005127da;
                        }
                      }
                      break;
                    }
                  }
                  uStack_13c = 0;
LAB_005127da:
                  iVar4 = FUN_0072e360();
                  while (iStack_180 = iVar4, iVar4 != 0) {
                    for (iVar12 = *(int *)(iVar4 + 0x94); iVar12 != iVar4 + 0x44;
                        iVar12 = *(int *)(iVar12 + 0x50)) {
                      pcVar13 = (char *)(iVar12 + 0x14);
                      if (0xf < *(uint *)(iVar12 + 0x28)) {
                        pcVar13 = *(char **)pcVar13;
                      }
                      iVar11 = __stricmp(pcVar13,"ID");
                      if (iVar11 == 0) {
                        if (iVar12 != 0) {
                          puVar9 = (undefined4 *)(iVar12 + 0x30);
                          if (0xf < *(uint *)(iVar12 + 0x44)) {
                            puVar9 = (undefined4 *)*puVar9;
                          }
                          if (puVar9 != (undefined4 *)0x0) {
                            aiStack_160[0] = FUN_008917b4(puVar9);
                            goto LAB_0051283b;
                          }
                        }
                        break;
                      }
                    }
                    aiStack_160[0] = 0;
LAB_0051283b:
                    for (iVar12 = *(int *)(iVar4 + 0x94); iVar12 != iVar4 + 0x44;
                        iVar12 = *(int *)(iVar12 + 0x50)) {
                      pcVar13 = (char *)(iVar12 + 0x14);
                      if (0xf < *(uint *)(iVar12 + 0x28)) {
                        pcVar13 = *(char **)pcVar13;
                      }
                      iVar11 = __stricmp(pcVar13,"VALUE");
                      if (iVar11 == 0) {
                        if (iVar12 != 0) {
                          puVar9 = (undefined4 *)(iVar12 + 0x30);
                          if (0xf < *(uint *)(iVar12 + 0x44)) {
                            puVar9 = (undefined4 *)*puVar9;
                          }
                          if (puVar9 != (undefined4 *)0x0) {
                            iVar4 = FUN_008917b4(puVar9);
                            goto LAB_00512870;
                          }
                        }
                        break;
                      }
                    }
                    iVar4 = 0;
LAB_00512870:
                    aiStack_160[1] = iVar4;
                    if ((aiStack_160 < piVar14) && (piStack_138 <= aiStack_160)) {
                      iVar4 = (int)aiStack_160 - (int)piStack_138 >> 3;
                      if (piVar14 == local_130) {
                        uVar3 = (int)piVar14 - (int)piStack_138 >> 3;
                        if (0x1ffffffe < uVar3) goto LAB_00512c94;
                        uVar3 = uVar3 + 1;
                        uVar15 = (int)local_130 - (int)piStack_138 >> 3;
                        if (uVar15 < uVar3) {
                          if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                            uVar15 = 0;
                          }
                          else {
                            uVar15 = uVar15 + (uVar15 >> 1);
                          }
                          if (uVar15 < uVar3) {
                            uVar15 = uVar3;
                          }
                          FUN_004e7330(uVar15);
                          piVar14 = piStack_134;
                        }
                      }
                      if (piVar14 != (int *)0x0) {
                        *piVar14 = piStack_138[iVar4 * 2];
                        piVar14[1] = piStack_138[iVar4 * 2 + 1];
                      }
                    }
                    else {
                      if (piVar14 == local_130) {
                        uVar3 = (int)piVar14 - (int)piStack_138 >> 3;
                        if (0x1ffffffe < uVar3) goto LAB_00512c94;
                        uVar3 = uVar3 + 1;
                        uVar15 = (int)local_130 - (int)piStack_138 >> 3;
                        if (uVar15 < uVar3) {
                          if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                            uVar15 = 0;
                          }
                          else {
                            uVar15 = uVar15 + (uVar15 >> 1);
                          }
                          if (uVar15 < uVar3) {
                            uVar15 = uVar3;
                          }
                          FUN_004e7330(uVar15);
                          piVar14 = piStack_134;
                        }
                      }
                      if (piVar14 != (int *)0x0) {
                        *piVar14 = aiStack_160[0];
                        piVar14[1] = iVar4;
                      }
                    }
                    piVar14 = piVar14 + 2;
                    piStack_134 = piVar14;
                    iVar4 = FUN_0072e3c0();
                  }
                  FUN_00512ca0();
                  local_c._0_1_ = 8;
                  if (piStack_138 != (int *)0x0) {
                    FUN_0089120c(piStack_138);
                  }
                  iVar4 = FUN_0072e3c0();
                }
              }
              break;
            }
          }
          aiStack_160[4] = *local_168;
          puStack_14c = local_168;
          uVar6 = FUN_0057ef20();
          FUN_0057e850(&DAT_00fb1368,uVar6);
          if ((&local_164 < DAT_00fb135c) && (DAT_00fb1358 <= &local_164)) {
            iVar4 = (int)&local_164 - (int)DAT_00fb1358;
            if (DAT_00fb135c == DAT_00fb1360) {
              uVar3 = (int)DAT_00fb135c - (int)DAT_00fb1358 >> 2;
              if (0x3ffffffe < uVar3) {
LAB_00512c94:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar3 = uVar3 + 1;
              uVar15 = (int)DAT_00fb1360 - (int)DAT_00fb1358 >> 2;
              if (uVar15 < uVar3) {
                if (0x3fffffff - (uVar15 >> 1) < uVar15) {
                  uVar15 = 0;
                }
                else {
                  uVar15 = uVar15 + (uVar15 >> 1);
                }
                if (uVar15 < uVar3) {
                  uVar15 = uVar3;
                }
                FUN_00797980(uVar15);
              }
            }
            if (DAT_00fb135c != (undefined4 **)0x0) {
              *DAT_00fb135c = DAT_00fb1358[iVar4 >> 2];
            }
          }
          else {
            if (DAT_00fb135c == DAT_00fb1360) {
              uVar3 = (int)DAT_00fb135c - (int)DAT_00fb1358 >> 2;
              if (0x3ffffffe < uVar3) goto LAB_00512c94;
              uVar3 = uVar3 + 1;
              uVar15 = (int)DAT_00fb1360 - (int)DAT_00fb1358 >> 2;
              if (uVar15 < uVar3) {
                if (0x3fffffff - (uVar15 >> 1) < uVar15) {
                  uVar15 = 0;
                }
                else {
                  uVar15 = uVar15 + (uVar15 >> 1);
                }
                if (uVar15 < uVar3) {
                  uVar15 = uVar3;
                }
                FUN_00797980(uVar15);
              }
            }
            if (DAT_00fb135c != (undefined4 **)0x0) {
              *DAT_00fb135c = local_168;
            }
          }
          DAT_00fb135c = DAT_00fb135c + 1;
          if (0xf < uStack_ac) {
            FUN_0089120c(appppcStack_c0[0]);
          }
          local_c = (uint)local_c._1_3_ << 8;
          uStack_ac = 0xf;
          iStack_b0 = 0;
          appppcStack_c0[0] = (char ****)((uint)appppcStack_c0[0] & 0xffffff00);
          if (0xf < uStack_c8) {
            FUN_0089120c(appppcStack_dc[0]);
          }
          uStack_c8 = 0xf;
          iStack_cc = 0;
          appppcStack_dc[0] = (char ****)((uint)appppcStack_dc[0] & 0xffffff00);
          local_178 = FUN_0072e3c0();
        } while (local_178 != 0);
        local_178 = 0;
      }
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    FUN_006edb60("Cannot find valid CashProductList table file");
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_184);
  return;
}

