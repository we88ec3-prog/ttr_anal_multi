
/* WARNING: Type propagation algorithm not settling */

void FUN_0051e0d0(undefined4 param_1)

{
  int *piVar1;
  uint *puVar2;
  char **ppcVar3;
  char **ppcVar4;
  int *piVar5;
  char cVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  uint uVar15;
  uint *puVar16;
  int *piVar17;
  uint *puVar18;
  uint auStack_194 [2];
  undefined4 *local_18c;
  char *apcStack_188 [4];
  int iStack_178;
  undefined **appuStack_174 [5];
  undefined4 local_160;
  uint local_15c [4];
  undefined4 local_14c;
  uint local_148;
  uint *local_140;
  uint *local_13c;
  uint *local_138;
  uint *local_130;
  uint *local_12c;
  undefined4 local_128;
  uint local_11c;
  int iStack_118;
  undefined4 *puStack_114;
  undefined4 uStack_110;
  undefined4 local_10c;
  uint local_108;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  uint uStack_f8;
  undefined4 uStack_e8;
  uint uStack_e4;
  int iStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  int *piStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923b11;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_194;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffe60;
  ExceptionList = &local_14;
  apcStack_188[3] = (char *)param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar6 = FUN_0072f110(0);
  if (cVar6 == '\0') {
    FUN_006edb60("Cannot find valid ItemSet Table File");
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
    FUN_0072e2e0("ITEM_SET");
    puVar8 = (undefined4 *)FUN_0072e360(uVar7);
    while (local_18c = puVar8, puVar8 != (undefined4 *)0x0) {
      local_148 = 7;
      local_14c = 0;
      local_15c[0] = local_15c[0] & 0xffff0000;
      local_140 = (uint *)0x0;
      local_13c = (uint *)0x0;
      local_138 = (uint *)0x0;
      local_130 = (uint *)0x0;
      local_12c = (uint *)0x0;
      local_128 = 0;
      local_c._1_3_ = (undefined3)(local_c >> 8);
      local_c = CONCAT31(local_c._1_3_,1);
      iVar9 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar9 == 0) {
LAB_0051e25e:
        local_160 = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar9 + 0x30);
        if (0xf < *(uint *)(iVar9 + 0x44)) {
          puVar10 = (undefined4 *)*puVar10;
        }
        if (puVar10 == (undefined4 *)0x0) goto LAB_0051e25e;
        local_160 = FUN_008917b4(puVar10);
      }
      local_108 = 0xf;
      local_10c = 0;
      local_11c = local_11c & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_c._0_1_ = 2;
      uVar11 = FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,3);
      FUN_00440130(uVar11);
      if (0xf < local_a0) {
        FUN_0089120c(local_b4);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      local_a0 = 0xf;
      local_a4 = 0;
      local_b4 = local_b4 & 0xffffff00;
      if (0xf < local_108) {
        FUN_0089120c(local_11c);
      }
      for (iVar9 = *(int *)((int)puVar8 + 0x18); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x40)) {
        pcVar14 = (char *)(iVar9 + 0x20);
        if (0xf < *(uint *)(iVar9 + 0x34)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar12 = __stricmp(pcVar14,"MEMBER_LIST");
        if (iVar12 == 0) {
          if (iVar9 != 0) {
            iVar9 = FUN_0072e360();
            puVar8 = local_18c;
            while (local_18c = puVar8, iVar9 != 0) {
              for (iVar12 = *(int *)(iVar9 + 0x94); iVar12 != iVar9 + 0x44;
                  iVar12 = *(int *)(iVar12 + 0x50)) {
                pcVar14 = (char *)(iVar12 + 0x14);
                if (0xf < *(uint *)(iVar12 + 0x28)) {
                  pcVar14 = *(char **)pcVar14;
                }
                iVar13 = __stricmp(pcVar14,"ITEM");
                if (iVar13 == 0) {
                  if (iVar12 != 0) {
                    puVar8 = (undefined4 *)(iVar12 + 0x30);
                    if (0xf < *(uint *)(iVar12 + 0x44)) {
                      puVar8 = (undefined4 *)*puVar8;
                    }
                    if (puVar8 != (undefined4 *)0x0) {
                      uVar7 = FUN_008917b4(puVar8);
                      goto LAB_0051e3ba;
                    }
                  }
                  break;
                }
              }
              uVar7 = 0;
LAB_0051e3ba:
              auStack_194[0] = uVar7;
              if ((DAT_00f8d9a8 & 1) == 0) {
                DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
                local_c._0_1_ = 4;
                DAT_00f8d9b4 = 0;
                iVar9 = FUN_00891268(0x18);
                if (iVar9 == 0) {
                  apcStack_188[2] = (char *)0x0;
                  std::exception::exception((exception *)appuStack_174,apcStack_188 + 2);
                  appuStack_174[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  __CxxThrowException_8(appuStack_174,&DAT_00c857a8);
                }
                DAT_00f8d9b0 = iVar9;
                *(int *)iVar9 = iVar9;
                *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
                *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
                *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
                *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
                local_c._0_1_ = 5;
                FUN_00521080(&DAT_00f8d9bc);
                _atexit((_func_4879 *)&LAB_00bccc50);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              auStack_194[1] = uVar7;
              FUN_008438c0(auStack_194 + 1);
              if ((iStack_178 != DAT_00f8d9b0) && (*(int *)(iStack_178 + 0x10) != 0)) {
                *(undefined4 *)(*(int *)(iStack_178 + 0x10) + 0x74) = local_160;
              }
              if ((auStack_194 < local_13c) && (local_140 <= auStack_194)) {
                iVar9 = (int)auStack_194 - (int)local_140;
                if (local_13c == local_138) {
                  FUN_006d6240();
                }
                if (local_13c != (uint *)0x0) {
                  *local_13c = local_140[iVar9 >> 2];
                }
              }
              else {
                if (local_13c == local_138) {
                  FUN_006d6240();
                }
                if (local_13c != (uint *)0x0) {
                  *local_13c = uVar7;
                }
              }
              local_13c = local_13c + 1;
              iVar9 = FUN_0072e3c0();
              puVar8 = local_18c;
            }
          }
          break;
        }
      }
      for (iVar9 = *(int *)((int)puVar8 + 0x18); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x40)) {
        pcVar14 = (char *)(iVar9 + 0x20);
        if (0xf < *(uint *)(iVar9 + 0x34)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar12 = __stricmp(pcVar14,"OPTION_LIST");
        if (iVar12 == 0) {
          if (iVar9 != 0) {
            auStack_194[1] = FUN_0072e360();
            if (auStack_194[1] != 0) {
              do {
                uVar7 = auStack_194[1];
                iVar12 = auStack_194[1] + 0x44;
                for (iVar9 = *(int *)(auStack_194[1] + 0x94); iVar9 != iVar12;
                    iVar9 = *(int *)(iVar9 + 0x50)) {
                  pcVar14 = (char *)(iVar9 + 0x14);
                  if (0xf < *(uint *)(iVar9 + 0x28)) {
                    pcVar14 = *(char **)pcVar14;
                  }
                  iVar13 = __stricmp(pcVar14,"MEMBER_COUNT");
                  if (iVar13 == 0) {
                    if (iVar9 != 0) {
                      puVar8 = (undefined4 *)(iVar9 + 0x30);
                      if (0xf < *(uint *)(iVar9 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        auStack_194[0] = FUN_008917b4(puVar8);
                        goto LAB_0051e5c5;
                      }
                    }
                    break;
                  }
                }
                auStack_194[0] = 0;
LAB_0051e5c5:
                for (iVar9 = *(int *)(uVar7 + 0x94); iVar9 != iVar12; iVar9 = *(int *)(iVar9 + 0x50)
                    ) {
                  pcVar14 = (char *)(iVar9 + 0x14);
                  if (0xf < *(uint *)(iVar9 + 0x28)) {
                    pcVar14 = *(char **)pcVar14;
                  }
                  iVar13 = __stricmp(pcVar14,"OPTION");
                  if (iVar13 == 0) {
                    if (iVar9 != 0) {
                      puVar8 = (undefined4 *)(iVar9 + 0x30);
                      if (0xf < *(uint *)(iVar9 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        apcStack_188[0] = (char *)FUN_008917b4(puVar8);
                        goto LAB_0051e5f9;
                      }
                    }
                    break;
                  }
                }
                apcStack_188[0] = (char *)0x0;
LAB_0051e5f9:
                for (iVar9 = *(int *)(uVar7 + 0x94); iVar9 != iVar12; iVar9 = *(int *)(iVar9 + 0x50)
                    ) {
                  pcVar14 = (char *)(iVar9 + 0x14);
                  if (0xf < *(uint *)(iVar9 + 0x28)) {
                    pcVar14 = *(char **)pcVar14;
                  }
                  iVar13 = __stricmp(pcVar14,"VALUE");
                  if (iVar13 == 0) {
                    if (iVar9 != 0) {
                      puVar8 = (undefined4 *)(iVar9 + 0x30);
                      if (0xf < *(uint *)(iVar9 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar11 = FUN_008917b4(puVar8);
                        goto LAB_0051e62d;
                      }
                    }
                    break;
                  }
                }
                uVar11 = 0;
LAB_0051e62d:
                iVar9 = (int)local_12c - (int)local_130 >> 0x1f;
                iVar12 = ((int)local_12c - (int)local_130) / 0x14 + iVar9;
                uVar7 = 0;
                puVar16 = local_130;
                apcStack_188[1] = (char *)uVar11;
                if (iVar12 != iVar9) {
                  do {
                    if (*puVar16 == auStack_194[0]) {
                      ppcVar3 = (char **)local_130[uVar7 * 5 + 2];
                      puVar16 = local_130 + uVar7 * 5 + 1;
                      if ((apcStack_188 < ppcVar3) &&
                         (ppcVar4 = (char **)*puVar16, ppcVar4 <= apcStack_188)) {
                        if (ppcVar3 == (char **)puVar16[2]) {
                          uVar7 = (int)ppcVar3 - (int)ppcVar4 >> 3;
                          if (0x1ffffffe < uVar7) {
LAB_0051eb6c:
                    /* WARNING: Subroutine does not return */
                            FUN_0087db30("vector<T> too long");
                          }
                          uVar7 = uVar7 + 1;
                          uVar15 = (int)puVar16[2] - (int)ppcVar4 >> 3;
                          if (uVar15 < uVar7) {
                            if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                              uVar15 = 0;
                            }
                            else {
                              uVar15 = uVar15 + (uVar15 >> 1);
                            }
                            if (uVar15 < uVar7) {
                              uVar15 = uVar7;
                            }
                            FUN_004e7330(uVar15);
                          }
                        }
                        puVar10 = (undefined4 *)puVar16[1];
                        puVar8 = (undefined4 *)
                                 (*puVar16 + ((int)apcStack_188 - (int)ppcVar4 >> 3) * 8);
                        if (puVar10 != (undefined4 *)0x0) {
                          *puVar10 = *puVar8;
                          puVar10[1] = puVar8[1];
                        }
                        puVar16[1] = puVar16[1] + 8;
                      }
                      else {
                        if (ppcVar3 == (char **)puVar16[2]) {
                          uVar7 = (int)((int)ppcVar3 - *puVar16) >> 3;
                          if (0x1ffffffe < uVar7) goto LAB_0051eb6c;
                          uVar7 = uVar7 + 1;
                          uVar15 = (int)((int)puVar16[2] - *puVar16) >> 3;
                          if (uVar15 < uVar7) {
                            if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                              uVar15 = 0;
                            }
                            else {
                              uVar15 = uVar15 + (uVar15 >> 1);
                            }
                            if (uVar15 < uVar7) {
                              uVar15 = uVar7;
                            }
                            FUN_004e7330(uVar15);
                          }
                        }
                        puVar8 = (undefined4 *)puVar16[1];
                        if (puVar8 != (undefined4 *)0x0) {
                          *puVar8 = apcStack_188[0];
                          puVar8[1] = uVar11;
                        }
                        puVar16[1] = puVar16[1] + 8;
                      }
                      goto LAB_0051e6ee;
                    }
                    uVar7 = uVar7 + 1;
                    puVar16 = puVar16 + 5;
                  } while (uVar7 < (uint)(iVar12 - iVar9));
                }
                iStack_118 = 0;
                puStack_114 = (undefined4 *)0x0;
                uStack_110 = 0;
                local_c._0_1_ = 6;
                local_11c = auStack_194[0];
                FUN_004e7330(1);
                if (puStack_114 != (undefined4 *)0x0) {
                  *puStack_114 = apcStack_188[0];
                  puStack_114[1] = uVar11;
                }
                puStack_114 = puStack_114 + 2;
                FUN_0051ec10();
                local_c = CONCAT31(local_c._1_3_,1);
                if (iStack_118 != 0) {
                  FUN_0089120c(iStack_118);
                }
LAB_0051e6ee:
                auStack_194[1] = FUN_0072e3c0();
              } while (auStack_194[1] != 0);
              auStack_194[1] = 0;
            }
            FUN_0051f670(local_130,local_12c,((int)local_12c - (int)local_130) / 0x14,FUN_008613a0);
          }
          break;
        }
      }
      uStack_100 = local_160;
      local_18c = &uStack_fc;
      uStack_fc = local_160;
      uStack_e4 = 7;
      uStack_e8 = 0;
      uStack_f8 = uStack_f8 & 0xffff0000;
      FUN_004026e0(local_15c,0,0xffffffff);
      local_c._0_1_ = 7;
      FUN_007e8a90(&iStack_dc,&local_140);
      local_c._0_1_ = 8;
      FUN_0051f910(&piStack_cc,&local_130);
      pcVar14 = apcStack_188[3];
      local_c = CONCAT31(local_c._1_3_,9);
      uVar11 = FUN_0051f7b0(&uStack_100);
      FUN_0051f450(pcVar14,uVar11);
      piVar5 = piStack_c8;
      if (piStack_cc != (int *)0x0) {
        if (piStack_cc != piStack_c8) {
          piVar17 = piStack_cc + 1;
          do {
            if (*piVar17 != 0) {
              FUN_0089120c(*piVar17);
            }
            *piVar17 = 0;
            piVar17[1] = 0;
            piVar17[2] = 0;
            piVar1 = piVar17 + 4;
            piVar17 = piVar17 + 5;
          } while (piVar1 != piVar5);
        }
        FUN_0089120c(piStack_cc);
      }
      piStack_cc = (int *)0x0;
      piStack_c8 = (int *)0x0;
      uStack_c4 = 0;
      if (iStack_dc != 0) {
        FUN_0089120c(iStack_dc);
      }
      iStack_dc = 0;
      uStack_d8 = 0;
      uStack_d4 = 0;
      if (7 < uStack_e4) {
        FUN_0089120c(uStack_f8);
      }
      puVar16 = local_12c;
      local_c = local_c & 0xffffff00;
      uStack_e4 = 7;
      uStack_e8 = 0;
      uStack_f8 = uStack_f8 & 0xffff0000;
      if (local_130 != (uint *)0x0) {
        if (local_130 != local_12c) {
          puVar18 = local_130 + 1;
          do {
            if (*puVar18 != 0) {
              FUN_0089120c(*puVar18);
            }
            *puVar18 = 0;
            puVar18[1] = 0;
            puVar18[2] = 0;
            puVar2 = puVar18 + 4;
            puVar18 = puVar18 + 5;
          } while (puVar2 != puVar16);
        }
        FUN_0089120c(local_130);
      }
      local_130 = (uint *)0x0;
      local_12c = (uint *)0x0;
      local_128 = 0;
      if (local_140 != (uint *)0x0) {
        FUN_0089120c(local_140);
      }
      local_140 = (uint *)0x0;
      local_13c = (uint *)0x0;
      local_138 = (uint *)0x0;
      if (7 < local_148) {
        FUN_0089120c(local_15c[0]);
      }
      local_148 = 7;
      local_14c = 0;
      local_15c[0] = local_15c[0] & 0xffff0000;
      puVar8 = (undefined4 *)FUN_0072e3c0();
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
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_194);
  return;
}

