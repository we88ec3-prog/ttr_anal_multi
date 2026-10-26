
void FUN_007aca80(char *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined **ppuVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  int **ppiVar21;
  undefined **local_2e0;
  undefined2 local_2dc;
  uint local_2d4;
  undefined **local_2d0;
  undefined2 local_2cc;
  uint local_2c4;
  undefined **local_2c0;
  int *local_2b8;
  undefined4 local_2b4;
  char *local_2ac;
  char *local_2a8 [2];
  int local_2a0;
  int *local_29c;
  uint local_298;
  undefined4 local_294;
  undefined1 local_28d;
  undefined4 local_28c;
  undefined **local_288;
  int *local_280;
  int *local_27c;
  int *local_278;
  int local_274 [4];
  int local_264;
  uint local_260 [4];
  undefined4 local_250;
  uint local_24c;
  int *local_244;
  int *local_240;
  int *local_23c;
  char local_234 [263];
  undefined4 uStack_12d;
  uint local_24;
  undefined **local_20;
  undefined2 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928695;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28d = param_2 != 0;
  local_2ac = param_1;
  local_2b4 = 0;
  local_2b8 = (int *)FUN_007b2620(local_14);
  *local_2b8 = (int)local_2b8;
  local_2b8[1] = (int)local_2b8;
  local_2b8[2] = (int)local_2b8;
  *(undefined1 *)(local_2b8 + 0xe) = 1;
  *(undefined1 *)((int)local_2b8 + 0x39) = 1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_278 = (int *)FUN_0072e2e0(&DAT_00c0dc30);
  piVar13 = local_278;
  do {
    if (piVar13 == (int *)0x0) {
      piVar13 = (int *)*local_2b8;
      local_278 = piVar13;
      if (piVar13 != local_2b8) {
        do {
          piVar16 = piVar13 + 3;
          if (0xf < (uint)piVar13[8]) {
            piVar16 = (int *)*piVar16;
          }
          __splitpath((char *)piVar16,(char *)0x0,local_234,(char *)((int)&uStack_12d + 1),
                      (char *)&local_24);
          puVar5 = &local_24;
          do {
            uVar6 = *puVar5;
            puVar5 = (uint *)((int)puVar5 + 1);
          } while ((char)uVar6 != '\0');
          uVar6 = (int)puVar5 - (int)&local_24;
          puVar5 = &uStack_12d;
          do {
            pcVar9 = (char *)((int)puVar5 + 1);
            puVar5 = (uint *)((int)puVar5 + 1);
          } while (*pcVar9 != '\0');
          puVar18 = &local_24;
          for (uVar17 = uVar6 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
            *puVar5 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(char *)puVar5 = (char)*puVar18;
            puVar18 = (uint *)((int)puVar18 + 1);
            puVar5 = (uint *)((int)puVar5 + 1);
          }
          local_27c = (int *)FUN_00891268(0x4c);
          local_8._0_1_ = 6;
          if (local_27c == (int *)0x0) {
            local_280 = (int *)0x0;
          }
          else {
            local_280 = (int *)FUN_007d4d00(local_27c);
          }
          piVar16 = local_280;
          local_8._0_1_ = 0;
          pcVar9 = local_2ac;
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(local_2ac,(int)pcVar9 - (int)(local_2ac + 1));
          FUN_007add40((int)&uStack_12d + 1,piVar16);
          bVar3 = false;
          local_29c = (int *)0x0;
          if (piVar13[0xb] - piVar13[10] >> 6 == 0) {
LAB_007ad68c:
            if (piVar16 != (int *)0x0) {
              (**(code **)*piVar16)(1);
            }
          }
          else {
            local_2a0 = 0;
            do {
              iVar14 = local_278[10];
              if ((int *)(local_278[0xb] - iVar14 >> 6) <= local_29c) {
                    /* WARNING: Subroutine does not return */
                FUN_0087db7d("invalid vector<T> subscript");
              }
              local_28c = CONCAT13(local_28d,
                                   CONCAT12(*(undefined1 *)(local_2a0 + 8 + iVar14),
                                            *(undefined2 *)(local_2a0 + iVar14)));
              local_288 = (undefined **)(uint)*(ushort *)(local_2a0 + 4 + iVar14);
              if ((DAT_00fe1bc0 & 1) == 0) {
                DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
                local_8._0_1_ = 7;
                FUN_007bef00();
                _atexit((_func_4879 *)&LAB_00bcec50);
                local_8._0_1_ = 0;
              }
              iVar10 = FUN_007bf8a0(local_28c,local_288,local_280);
              if (iVar10 == 0) {
                piVar13 = local_278;
                piVar16 = local_280;
                if (!bVar3) goto LAB_007ad68c;
                break;
              }
              if ((DAT_00fe1bc0 & 1) == 0) {
                DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
                local_8._0_1_ = 8;
                FUN_007bef00();
                _atexit((_func_4879 *)&LAB_00bcec50);
                local_8._0_1_ = 0;
              }
              local_2dc = *(undefined2 *)(local_2a0 + 0xc + iVar14);
              local_2e0 = local_288;
              uVar11 = FUN_007c1af0();
              FUN_007c0b70(&DAT_00fe1b90,uVar11);
              if ((DAT_00fe1bc0 & 1) == 0) {
                DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
                local_8._0_1_ = 9;
                FUN_007bef00();
                _atexit((_func_4879 *)&LAB_00bcec50);
                local_8._0_1_ = 0;
              }
              local_2cc = *(undefined2 *)(local_2a0 + 0x10 + iVar14);
              local_2d4 = local_28c;
              local_2d0 = local_288;
              uVar11 = FUN_007c1af0();
              FUN_007c0b70(&DAT_00fe1ba0,uVar11);
              if ((DAT_00fe1bc0 & 1) == 0) {
                DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
                local_8._0_1_ = 10;
                FUN_007bef00();
                _atexit((_func_4879 *)&LAB_00bcec50);
                local_8._0_1_ = 0;
              }
              ppuVar4 = local_288;
              FUN_007bf960(&DAT_00fe1b60,local_28c,local_288);
              local_27c = (int *)(local_2a0 + 0x30 + iVar14);
              local_298 = 0;
              if (*(int *)(local_2a0 + 0x34 + iVar14) - *(int *)(local_2a0 + 0x30 + iVar14) >> 2 !=
                  0) {
                local_2c4 = local_28c;
                local_2c0 = ppuVar4;
                do {
                  iVar10 = *local_27c;
                  iVar14 = local_298 * 4;
                  if ((DAT_00fe1bc0 & 1) == 0) {
                    DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
                    local_8._0_1_ = 0xb;
                    FUN_007bef00();
                    _atexit((_func_4879 *)&LAB_00bcec50);
                    local_8._0_1_ = 0;
                  }
                  uVar11 = *(undefined4 *)(iVar10 + iVar14);
                  local_294 = uVar11;
                  puVar5 = (uint *)FUN_007c01e0(&DAT_00fe1bb0);
                  puVar19 = (undefined4 *)puVar5[1];
                  if (&local_294 < puVar19) {
                    puVar2 = (undefined4 *)*puVar5;
                    if (&local_294 < puVar2) goto LAB_007ad5a9;
                    if (puVar19 == (undefined4 *)puVar5[2]) {
                      uVar6 = (int)puVar19 - (int)puVar2 >> 2;
                      if (0x3ffffffe < uVar6) goto LAB_007ad242;
                      uVar6 = uVar6 + 1;
                      uVar17 = (int)puVar5[2] - (int)puVar2 >> 2;
                      if (uVar17 < uVar6) {
                        if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                          uVar17 = 0;
                        }
                        else {
                          uVar17 = uVar17 + (uVar17 >> 1);
                        }
                        if (uVar17 < uVar6) {
                          uVar17 = uVar6;
                        }
                        FUN_00797980(uVar17);
                      }
                    }
                    if ((undefined4 *)puVar5[1] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar5[1] =
                           *(undefined4 *)(*puVar5 + ((int)&local_294 - (int)puVar2 >> 2) * 4);
                    }
                  }
                  else {
LAB_007ad5a9:
                    if (puVar19 == (undefined4 *)puVar5[2]) {
                      uVar6 = (int)((int)puVar19 - *puVar5) >> 2;
                      if (0x3ffffffe < uVar6) goto LAB_007ad242;
                      uVar6 = uVar6 + 1;
                      uVar17 = (int)((int)puVar5[2] - *puVar5) >> 2;
                      if (uVar17 < uVar6) {
                        if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                          uVar17 = 0;
                        }
                        else {
                          uVar17 = uVar17 + (uVar17 >> 1);
                        }
                        if (uVar17 < uVar6) {
                          uVar17 = uVar6;
                        }
                        FUN_00797980(uVar17);
                      }
                    }
                    if ((undefined4 *)puVar5[1] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar5[1] = uVar11;
                    }
                  }
                  puVar5[1] = puVar5[1] + 4;
                  local_298 = local_298 + 1;
                } while (local_298 < (uint)(local_27c[1] - *local_27c >> 2));
              }
              local_2a0 = local_2a0 + 0x40;
              local_29c = (int *)((int)local_29c + 1);
              bVar3 = true;
              piVar13 = local_278;
            } while (local_29c < (int *)(local_278[0xb] - local_278[10] >> 6));
          }
          if (*(char *)((int)piVar13 + 0x39) == '\0') {
            piVar16 = (int *)piVar13[2];
            if (*(char *)((int)piVar16 + 0x39) == '\0') {
              cVar1 = *(char *)(*piVar16 + 0x39);
              piVar13 = piVar16;
              piVar16 = (int *)*piVar16;
              while (local_278 = piVar13, cVar1 == '\0') {
                cVar1 = *(char *)(*piVar16 + 0x39);
                piVar13 = piVar16;
                piVar16 = (int *)*piVar16;
              }
            }
            else {
              cVar1 = *(char *)(piVar13[1] + 0x39);
              piVar20 = (int *)piVar13[1];
              piVar16 = piVar13;
              while ((piVar13 = piVar20, local_278 = piVar13, cVar1 == '\0' &&
                     (piVar16 == (int *)piVar13[2]))) {
                cVar1 = *(char *)(piVar13[1] + 0x39);
                piVar20 = (int *)piVar13[1];
                piVar16 = piVar13;
              }
            }
          }
        } while (piVar13 != local_2b8);
      }
      local_278 = (int *)FUN_0072e360();
      if (local_278 != (int *)0x0) {
        local_28c = CONCAT13(local_28d,(undefined3)local_28c);
        local_288 = (undefined **)0x0;
        do {
          piVar13 = local_278;
          iVar10 = (int)local_278 + 0x44;
          for (iVar14 = *(int *)((int)local_278 + 0x94); iVar14 != iVar10;
              iVar14 = *(int *)(iVar14 + 0x50)) {
            pcVar9 = (char *)(iVar14 + 0x14);
            if (0xf < *(uint *)(iVar14 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar12 = __stricmp(pcVar9,"Index");
            if (iVar12 == 0) {
              if (iVar14 != 0) {
                puVar19 = (undefined4 *)(iVar14 + 0x30);
                if (0xf < *(uint *)(iVar14 + 0x44)) {
                  puVar19 = (undefined4 *)*puVar19;
                }
                if (puVar19 != (undefined4 *)0x0) {
                  local_27c = (int *)FUN_008917b4(puVar19);
                  goto LAB_007ad749;
                }
              }
              break;
            }
          }
          local_27c = (int *)0x0;
LAB_007ad749:
          for (iVar14 = *(int *)((int)piVar13 + 0x94); iVar14 != iVar10;
              iVar14 = *(int *)(iVar14 + 0x50)) {
            pcVar9 = (char *)(iVar14 + 0x14);
            if (0xf < *(uint *)(iVar14 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar12 = __stricmp(pcVar9,"Level");
            if (iVar12 == 0) {
              if (iVar14 != 0) {
                puVar19 = (undefined4 *)(iVar14 + 0x30);
                if (0xf < *(uint *)(iVar14 + 0x44)) {
                  puVar19 = (undefined4 *)*puVar19;
                }
                if (puVar19 != (undefined4 *)0x0) {
                  local_280 = (int *)FUN_008917b4(puVar19);
                  goto LAB_007ad781;
                }
              }
              break;
            }
          }
          local_280 = (int *)0x0;
LAB_007ad781:
          for (iVar14 = *(int *)((int)piVar13 + 0x94); iVar14 != iVar10;
              iVar14 = *(int *)(iVar14 + 0x50)) {
            pcVar9 = (char *)(iVar14 + 0x14);
            if (0xf < *(uint *)(iVar14 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar12 = __stricmp(pcVar9,"Part");
            if (iVar12 == 0) {
              if (iVar14 != 0) {
                puVar19 = (undefined4 *)(iVar14 + 0x30);
                if (0xf < *(uint *)(iVar14 + 0x44)) {
                  puVar19 = (undefined4 *)*puVar19;
                }
                if (puVar19 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar19);
                  goto LAB_007ad7b4;
                }
              }
              break;
            }
          }
          uVar6 = 1;
LAB_007ad7b4:
          local_298 = uVar6;
          for (iVar14 = *(int *)((int)piVar13 + 0x94); iVar14 != iVar10;
              iVar14 = *(int *)(iVar14 + 0x50)) {
            pcVar9 = (char *)(iVar14 + 0x14);
            if (0xf < *(uint *)(iVar14 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar12 = __stricmp(pcVar9,"Value");
            if (iVar12 == 0) {
              if (iVar14 != 0) {
                puVar19 = (undefined4 *)(iVar14 + 0x30);
                if (0xf < *(uint *)(iVar14 + 0x44)) {
                  puVar19 = (undefined4 *)*puVar19;
                }
                if (puVar19 != (undefined4 *)0x0) {
                  local_294 = FUN_008917b4(puVar19);
                  goto LAB_007ad7f5;
                }
              }
              break;
            }
          }
          local_294 = 1;
LAB_007ad7f5:
          local_28c._0_3_ = CONCAT12(local_280._0_1_,local_27c._0_2_);
          piVar13 = (int *)FUN_00891268(0x4c);
          local_27c = piVar13;
          if (piVar13 == (int *)0x0) {
            piVar13 = (int *)0x0;
          }
          else {
            *piVar13 = (int)IS3D::CItemBase::vftable;
            piVar13[6] = 0xf;
            piVar13[5] = 0;
            *(undefined1 *)(piVar13 + 1) = 0;
            piVar13[8] = 1;
            piVar13[9] = 0;
            piVar13[10] = 0;
            piVar13[0xb] = 0;
            piVar13[0xc] = 0;
            local_8._0_1_ = 0xe;
            piVar13[0xe] = 0x3f800000;
            piVar13[0x11] = 0;
            iVar14 = FUN_00891268(0x18);
            if (iVar14 == 0) {
              local_2a8[0] = (char *)0x0;
              std::exception::exception((exception *)&local_2e0,local_2a8);
              local_2e0 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(&local_2e0,&DAT_00c857a8);
            }
            piVar13[0x10] = iVar14;
            *(int *)iVar14 = iVar14;
            *(int *)(piVar13[0x10] + 4) = piVar13[0x10];
            *(int *)(piVar13[0x10] + 8) = piVar13[0x10];
            *(undefined1 *)(piVar13[0x10] + 0x14) = 1;
            *(undefined1 *)(piVar13[0x10] + 0x15) = 1;
          }
          local_8._0_1_ = 0;
          piVar13[8] = uVar6 + 100;
          pcVar9 = local_2ac;
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          local_29c = piVar13;
          FUN_00402a70(local_2ac,(int)pcVar9 - (int)(local_2ac + 1));
          iVar14 = FUN_0072e360();
          if ((iVar14 != 0) && (local_280 = (int *)FUN_0072e360(), local_280 != (int *)0x0)) {
            local_27c = piVar13 + 0xf;
            do {
              piVar16 = local_280;
              piVar20 = local_280 + 0x11;
              for (piVar13 = (int *)local_280[0x25]; piVar13 != piVar20;
                  piVar13 = (int *)piVar13[0x14]) {
                piVar15 = piVar13 + 5;
                if (0xf < (uint)piVar13[10]) {
                  piVar15 = (int *)*piVar15;
                }
                iVar14 = __stricmp((char *)piVar15,"Key");
                if (iVar14 == 0) {
                  if (piVar13 != (int *)0x0) {
                    piVar15 = piVar13 + 0xc;
                    if (0xf < (uint)piVar13[0x11]) {
                      piVar15 = (int *)*piVar15;
                    }
                    if (piVar15 != (int *)0x0) {
                      uVar6 = FUN_008917b4(piVar15);
                      goto LAB_007ada01;
                    }
                  }
                  break;
                }
              }
              uVar6 = 0;
LAB_007ada01:
              for (piVar13 = (int *)piVar16[0x25]; piVar13 != piVar20;
                  piVar13 = (int *)piVar13[0x14]) {
                piVar16 = piVar13 + 5;
                if (0xf < (uint)piVar13[10]) {
                  piVar16 = (int *)*piVar16;
                }
                iVar14 = __stricmp((char *)piVar16,"Value");
                if (iVar14 == 0) {
                  if (piVar13 != (int *)0x0) {
                    piVar16 = piVar13 + 0xc;
                    if (0xf < (uint)piVar13[0x11]) {
                      piVar16 = (int *)*piVar16;
                    }
                    if (piVar16 != (int *)0x0) {
                      local_2c0 = (undefined **)FUN_008917b4(piVar16);
                      goto LAB_007ada3a;
                    }
                  }
                  break;
                }
              }
              local_2c0 = (undefined **)0x0;
LAB_007ada3a:
              piVar13 = local_27c;
              local_2c4 = uVar6;
              uVar11 = FUN_0057ef20();
              FUN_0082f200(piVar13,uVar11);
              local_280 = (int *)FUN_0072e3c0();
            } while (local_280 != (int *)0x0);
          }
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 0xf;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
            local_8._0_1_ = 0;
          }
          uVar6 = local_28c;
          piVar13 = local_29c;
          iVar14 = FUN_007bf8a0(local_28c,local_288,local_29c);
          if (iVar14 == 0) {
            (**(code **)*piVar13)(1);
          }
          else {
            if ((DAT_00fe1bc0 & 1) == 0) {
              DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
              local_8._0_1_ = 0x10;
              FUN_007bef00();
              _atexit((_func_4879 *)&LAB_00bcec50);
              local_8._0_1_ = 0;
            }
            local_2d4 = uVar6;
            local_2d0 = local_288;
            local_2cc = (undefined2)local_298;
            uVar11 = FUN_007c1af0();
            FUN_007c0b70(&DAT_00fe1b90,uVar11);
            if ((DAT_00fe1bc0 & 1) == 0) {
              DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
              local_8._0_1_ = 0x11;
              FUN_007bef00();
              _atexit((_func_4879 *)&LAB_00bcec50);
              local_8._0_1_ = 0;
            }
            local_24 = uVar6;
            local_20 = local_288;
            local_1c = (undefined2)local_294;
            uVar11 = FUN_007c1af0();
            FUN_007c0b70(&DAT_00fe1ba0,uVar11);
          }
          local_278 = (int *)FUN_0072e3c0();
        } while (local_278 != (int *)0x0);
      }
      local_8 = 0x12;
      FUN_007b20b0(*local_2b8,local_2b8);
      FUN_0089120c(local_2b8);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar12 = (**(code **)(*local_278 + 0x14))();
    pcVar9 = (char *)0x0;
    local_24c = 0xf;
    local_250 = 0;
    local_260[0] = local_260[0] & 0xffffff00;
    local_244 = (int *)0x0;
    local_240 = (int *)0x0;
    local_23c = (int *)0x0;
    iVar14 = iVar12 + 0x44;
    local_8._0_1_ = 1;
    iVar10 = *(int *)(iVar12 + 0x94);
    if (iVar10 != iVar14) {
      do {
        pcVar9 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar9 = *(char **)pcVar9;
        }
        iVar7 = __stricmp(pcVar9,"File");
        if (iVar7 == 0) {
          if (iVar10 != 0) {
            if (*(uint *)(iVar10 + 0x44) < 0x10) {
              pcVar9 = (char *)(iVar10 + 0x30);
            }
            else {
              pcVar9 = *(char **)(iVar10 + 0x30);
            }
            goto LAB_007acc3a;
          }
          break;
        }
        iVar10 = *(int *)(iVar10 + 0x50);
      } while (iVar10 != iVar14);
      pcVar9 = (char *)0x0;
    }
LAB_007acc3a:
    pcVar8 = pcVar9;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
    for (iVar10 = *(int *)(iVar12 + 0x94); iVar10 != iVar14; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar9 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,"Index");
      if (iVar7 == 0) {
        if (iVar10 != 0) {
          puVar19 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar19 = (undefined4 *)*puVar19;
          }
          if (puVar19 != (undefined4 *)0x0) {
            local_274[0] = FUN_008917b4(puVar19);
            goto LAB_007acc89;
          }
        }
        break;
      }
    }
    local_274[0] = 0;
LAB_007acc89:
    for (iVar10 = *(int *)(iVar12 + 0x94); iVar10 != iVar14; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar9 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,"CharIndex");
      if (iVar7 == 0) {
        if (iVar10 != 0) {
          puVar19 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar19 = (undefined4 *)*puVar19;
          }
          if (puVar19 != (undefined4 *)0x0) {
            local_274[1] = FUN_008917b4(puVar19);
            goto LAB_007accbf;
          }
        }
        break;
      }
    }
    local_274[1] = 0;
LAB_007accbf:
    for (iVar10 = *(int *)(iVar12 + 0x94); iVar10 != iVar14; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar9 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,"Level");
      if (iVar7 == 0) {
        if (iVar10 != 0) {
          puVar19 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar19 = (undefined4 *)*puVar19;
          }
          if (puVar19 != (undefined4 *)0x0) {
            local_274[2] = FUN_008917b4(puVar19);
            goto LAB_007accf9;
          }
        }
        break;
      }
    }
    local_274[2] = 0;
LAB_007accf9:
    for (iVar10 = *(int *)(iVar12 + 0x94); iVar10 != iVar14; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar9 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,"Part");
      if (iVar7 == 0) {
        if (iVar10 != 0) {
          puVar19 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar19 = (undefined4 *)*puVar19;
          }
          if (puVar19 != (undefined4 *)0x0) {
            local_274[3] = FUN_008917b4(puVar19);
            goto LAB_007acd32;
          }
        }
        break;
      }
    }
    local_274[3] = 1;
LAB_007acd32:
    for (iVar10 = *(int *)(iVar12 + 0x94); iVar10 != iVar14; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar9 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar12 = __stricmp(pcVar9,"Avatar");
      if (iVar12 == 0) {
        if (iVar10 != 0) {
          puVar19 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar19 = (undefined4 *)*puVar19;
          }
          if (puVar19 != (undefined4 *)0x0) {
            local_264 = FUN_008917b4(puVar19);
            goto LAB_007acd69;
          }
        }
        break;
      }
    }
    local_264 = 0;
LAB_007acd69:
    iVar14 = FUN_0072e360();
    if (iVar14 != 0) {
      iVar14 = FUN_0072e360();
      while (iVar14 != 0) {
        for (iVar10 = *(int *)(iVar14 + 0x94); iVar10 != iVar14 + 0x44;
            iVar10 = *(int *)(iVar10 + 0x50)) {
          pcVar9 = (char *)(iVar10 + 0x14);
          if (0xf < *(uint *)(iVar10 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar12 = __stricmp(pcVar9,"Index");
          if (iVar12 == 0) {
            if (iVar10 != 0) {
              puVar19 = (undefined4 *)(iVar10 + 0x30);
              if (0xf < *(uint *)(iVar10 + 0x44)) {
                puVar19 = (undefined4 *)*puVar19;
              }
              if (puVar19 != (undefined4 *)0x0) {
                iVar14 = FUN_008917b4(puVar19);
                goto LAB_007acdda;
              }
            }
            break;
          }
        }
        iVar14 = 0;
LAB_007acdda:
        local_2a0 = iVar14;
        if ((&local_2a0 < local_240) && (local_244 <= &local_2a0)) {
          iVar14 = (int)&local_2a0 - (int)local_244;
          if (local_240 == local_23c) {
            uVar6 = (int)local_240 - (int)local_244 >> 2;
            if (0x3ffffffe < uVar6) goto LAB_007ad242;
            uVar6 = uVar6 + 1;
            uVar17 = (int)local_23c - (int)local_244 >> 2;
            if (uVar17 < uVar6) {
              if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                uVar17 = 0;
              }
              else {
                uVar17 = uVar17 + (uVar17 >> 1);
              }
              if (uVar17 < uVar6) {
                uVar17 = uVar6;
              }
              FUN_00797980(uVar17);
            }
          }
          if (local_240 != (int *)0x0) {
            *local_240 = local_244[iVar14 >> 2];
          }
        }
        else {
          if (local_240 == local_23c) {
            uVar6 = (int)local_240 - (int)local_244 >> 2;
            if (0x3ffffffe < uVar6) goto LAB_007ad242;
            uVar6 = uVar6 + 1;
            uVar17 = (int)local_23c - (int)local_244 >> 2;
            if (uVar17 < uVar6) {
              if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                uVar17 = 0;
              }
              else {
                uVar17 = uVar17 + (uVar17 >> 1);
              }
              if (uVar17 < uVar6) {
                uVar17 = uVar6;
              }
              FUN_00797980(uVar17);
            }
          }
          if (local_240 != (int *)0x0) {
            *local_240 = iVar14;
          }
        }
        local_240 = local_240 + 1;
        iVar14 = FUN_0072e3c0();
      }
    }
    puVar5 = (uint *)FUN_007b1a20(local_260);
    piVar13 = (int *)puVar5[1];
    if ((local_274 < piVar13) && (piVar16 = (int *)*puVar5, piVar16 <= local_274)) {
      if (piVar13 == (int *)puVar5[2]) {
        uVar6 = (int)piVar13 - (int)piVar16 >> 6;
        if (0x3fffffe < uVar6) goto LAB_007ad242;
        uVar6 = uVar6 + 1;
        uVar17 = (int)puVar5[2] - (int)piVar16 >> 6;
        if (uVar17 < uVar6) {
          if (0x3ffffff - (uVar17 >> 1) < uVar17) {
            uVar17 = 0;
          }
          else {
            uVar17 = uVar17 + (uVar17 >> 1);
          }
          if (uVar17 < uVar6) {
            uVar17 = uVar6;
          }
          FUN_007b2170(uVar17);
        }
      }
      local_280 = (int *)puVar5[1];
      piVar13 = (int *)(((int)local_274 - (int)piVar16 & 0xffffffc0U) + *puVar5);
      local_8._0_1_ = 2;
      local_27c = local_280;
      if (local_280 != (int *)0x0) {
        *local_280 = *piVar13;
        local_280[1] = piVar13[1];
        local_280[2] = piVar13[2];
        local_280[3] = piVar13[3];
        local_280[4] = piVar13[4];
        local_280[10] = 0xf;
        local_280[9] = 0;
        *(undefined1 *)(local_280 + 5) = 0;
        FUN_00403040(piVar13 + 5,0,0xffffffff);
        ppiVar21 = (int **)(piVar13 + 0xc);
        local_8._0_1_ = 3;
LAB_007ad1ad:
        FUN_0062d9b0(ppiVar21);
      }
    }
    else {
      if (piVar13 == (int *)puVar5[2]) {
        uVar6 = (int)((int)piVar13 - *puVar5) >> 6;
        if (0x3fffffe < uVar6) {
LAB_007ad242:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar6 = uVar6 + 1;
        uVar17 = (int)((int)puVar5[2] - *puVar5) >> 6;
        if (uVar17 < uVar6) {
          if (0x3ffffff - (uVar17 >> 1) < uVar17) {
            uVar17 = 0;
          }
          else {
            uVar17 = uVar17 + (uVar17 >> 1);
          }
          if (uVar17 < uVar6) {
            uVar17 = uVar6;
          }
          FUN_007b2170(uVar17);
        }
      }
      local_280 = (int *)puVar5[1];
      local_8._0_1_ = 4;
      local_27c = local_280;
      if (local_280 != (int *)0x0) {
        *local_280 = local_274[0];
        local_280[1] = local_274[1];
        local_280[2] = local_274[2];
        local_280[3] = local_274[3];
        local_280[4] = local_264;
        local_280[10] = 0xf;
        local_280[9] = 0;
        *(undefined1 *)(local_280 + 5) = 0;
        FUN_00403040(local_260,0,0xffffffff);
        ppiVar21 = &local_244;
        local_8._0_1_ = 5;
        goto LAB_007ad1ad;
      }
    }
    puVar5[1] = puVar5[1] + 0x40;
    for (piVar13 = (int *)local_278[0x10]; piVar13 != (int *)0x0; piVar13 = (int *)piVar13[0x10]) {
      piVar16 = piVar13 + 8;
      if (0xf < (uint)piVar13[0xd]) {
        piVar16 = (int *)*piVar16;
      }
      iVar14 = __stricmp((char *)piVar16,"Item");
      if (iVar14 == 0) goto LAB_007ad1ec;
    }
    piVar13 = (int *)0x0;
LAB_007ad1ec:
    local_8._0_1_ = 0;
    local_278 = piVar13;
    if (local_244 != (int *)0x0) {
      FUN_0089120c(local_244);
    }
    local_244 = (int *)0x0;
    local_240 = (int *)0x0;
    local_23c = (int *)0x0;
    if (0xf < local_24c) {
      FUN_0089120c(local_260[0]);
    }
  } while( true );
}

