
void FUN_0050cee0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  uint *puVar17;
  undefined1 auStack_114 [4];
  int aiStack_110 [2];
  int *piStack_108;
  int iStack_104;
  int iStack_100;
  undefined4 *puStack_fc;
  undefined4 local_f8;
  int local_f4;
  undefined4 uStack_f0;
  int local_ec;
  char *pcStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined **appuStack_dc [3];
  uint local_d0;
  undefined4 local_c0;
  uint local_bc;
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
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
  puStack_10 = &LAB_0092405d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_114;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffee0;
  ExceptionList = &local_14;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar8 = FUN_0072e2e0("AREA_DESC");
    if (iVar8 != 0) {
      local_ec = FUN_0072e360(uVar7);
      while (local_ec != 0) {
        iVar8 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar8 == 0) {
LAB_0050cffb:
          local_f8 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar8 + 0x30);
          if (0xf < *(uint *)(iVar8 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_0050cffb;
          local_f8 = FUN_008917b4(puVar9);
        }
        local_f4 = FUN_0050d920();
        local_bc = 0xf;
        local_c0 = 0;
        local_d0 = local_d0 & 0xffffff00;
        FUN_00402a70(&DAT_00c0ce30,4);
        local_c._0_1_ = 1;
        uVar10 = FUN_0072ecf0(&DAT_00bf2375);
        local_c = CONCAT31(local_c._1_3_,2);
        FUN_00440130(uVar10);
        if (0xf < local_a0) {
          FUN_0089120c(local_b4);
        }
        local_c = local_c & 0xffffff00;
        local_a0 = 0xf;
        local_a4 = 0;
        local_b4 = local_b4 & 0xffffff00;
        if (0xf < local_bc) {
          FUN_0089120c(local_d0);
        }
        iVar8 = FUN_007300a0("LEVEL_LIMIT");
        if (iVar8 == 0) {
LAB_0050d0df:
          uVar6 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar8 + 0x30);
          if (0xf < *(uint *)(iVar8 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_0050d0df;
          uVar6 = FUN_008917b4(puVar9);
        }
        *(undefined1 *)(local_f4 + 0x1c) = uVar6;
        iStack_104 = FUN_0072e360();
        if (iStack_104 != 0) {
          do {
            iVar12 = iStack_104;
            iVar15 = iStack_104 + 0x44;
            for (iVar8 = *(int *)(iStack_104 + 0x94); iVar8 != iVar15;
                iVar8 = *(int *)(iVar8 + 0x50)) {
              pcVar13 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar13 = *(char **)pcVar13;
              }
              iVar11 = __stricmp(pcVar13,"ID");
              if (iVar11 == 0) {
                if (iVar8 != 0) {
                  puVar9 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar9 = (undefined4 *)*puVar9;
                  }
                  if (puVar9 != (undefined4 *)0x0) {
                    uStack_f0 = FUN_008917b4(puVar9);
                    goto LAB_0050d153;
                  }
                }
                break;
              }
            }
            uStack_f0 = 0;
LAB_0050d153:
            uVar10 = uStack_f0;
            uStack_e4 = local_f8;
            uStack_e0 = uStack_f0;
            puVar9 = (undefined4 *)FUN_0050db70();
            *puVar9 = uVar10;
            puStack_fc = puVar9;
            for (iVar8 = *(int *)(iVar12 + 0x94); iVar8 != iVar15; iVar8 = *(int *)(iVar8 + 0x50)) {
              pcVar13 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar13 = *(char **)pcVar13;
              }
              iVar11 = __stricmp(pcVar13,"MINLV");
              if (iVar11 == 0) {
                if (iVar8 != 0) {
                  puVar16 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar16 = (undefined4 *)*puVar16;
                  }
                  if (puVar16 != (undefined4 *)0x0) {
                    uVar10 = FUN_008917b4(puVar16);
                    goto LAB_0050d1aa;
                  }
                }
                break;
              }
            }
            uVar10 = 0;
LAB_0050d1aa:
            puVar9[8] = uVar10;
            for (iVar8 = *(int *)(iVar12 + 0x94); iVar8 != iVar15; iVar8 = *(int *)(iVar8 + 0x50)) {
              pcVar13 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar13 = *(char **)pcVar13;
              }
              iVar12 = __stricmp(pcVar13,"MAXLV");
              if (iVar12 == 0) {
                if (iVar8 != 0) {
                  puVar16 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar16 = (undefined4 *)*puVar16;
                  }
                  if (puVar16 != (undefined4 *)0x0) {
                    uVar10 = FUN_008917b4(puVar16);
                    goto LAB_0050d1de;
                  }
                }
                break;
              }
            }
            uVar10 = 0;
LAB_0050d1de:
            puVar9[9] = uVar10;
            local_bc = 0xf;
            local_c0 = 0;
            local_d0 = local_d0 & 0xffffff00;
            FUN_00402a70(&DAT_00c0ce30,4);
            local_c._0_1_ = 3;
            uVar10 = FUN_0072ecf0(&DAT_00bf2375);
            local_c = CONCAT31(local_c._1_3_,4);
            FUN_00440130(uVar10);
            if (0xf < local_a0) {
              FUN_0089120c(local_b4);
            }
            local_c = local_c & 0xffffff00;
            local_a0 = 0xf;
            local_a4 = 0;
            local_b4 = local_b4 & 0xffffff00;
            if (0xf < local_bc) {
              FUN_0089120c(local_d0);
            }
            local_bc = 0xf;
            local_c0 = 0;
            local_d0 = local_d0 & 0xffffff00;
            FUN_00402a70(&DAT_00c0dfbc,4);
            local_c._0_1_ = 5;
            uVar10 = FUN_0072ecf0(&DAT_00bf2375);
            local_c = CONCAT31(local_c._1_3_,6);
            FUN_00440130(uVar10);
            if (0xf < local_a0) {
              FUN_0089120c(local_b4);
            }
            local_c = local_c & 0xffffff00;
            local_a0 = 0xf;
            local_a4 = 0;
            local_b4 = local_b4 & 0xffffff00;
            if (0xf < local_bc) {
              FUN_0089120c(local_d0);
            }
            iVar8 = FUN_0072e360();
            iVar12 = local_f4;
            while (iStack_100 = iVar8, local_f4 = iVar12, iVar8 != 0) {
              for (iVar12 = *(int *)(iVar8 + 0x94); iVar12 != iVar8 + 0x44;
                  iVar12 = *(int *)(iVar12 + 0x50)) {
                pcVar13 = (char *)(iVar12 + 0x14);
                if (0xf < *(uint *)(iVar12 + 0x28)) {
                  pcVar13 = *(char **)pcVar13;
                }
                iVar15 = __stricmp(pcVar13,"map");
                if (iVar15 == 0) {
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)(iVar12 + 0x30);
                    if (0xf < *(uint *)(iVar12 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      aiStack_110[0] = FUN_008917b4(puVar9);
                      goto LAB_0050d38f;
                    }
                  }
                  break;
                }
              }
              aiStack_110[0] = 0;
LAB_0050d38f:
              aiStack_110[1] = aiStack_110[0];
              puVar9 = (undefined4 *)FUN_006ceed0();
              puVar9[1] = uStack_f0;
              *puVar9 = local_f8;
              piStack_108 = (int *)FUN_0050dc80();
              for (iVar12 = *(int *)(iVar8 + 0x94); iVar12 != iVar8 + 0x44;
                  iVar12 = *(int *)(iVar12 + 0x50)) {
                pcVar13 = (char *)(iVar12 + 0x14);
                if (0xf < *(uint *)(iVar12 + 0x28)) {
                  pcVar13 = *(char **)pcVar13;
                }
                iVar15 = __stricmp(pcVar13,"diffyculty");
                if (iVar15 == 0) {
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)(iVar12 + 0x30);
                    if (0xf < *(uint *)(iVar12 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      iVar8 = FUN_008917b4(puVar9);
                      goto LAB_0050d3f9;
                    }
                  }
                  break;
                }
              }
              iVar8 = 0;
LAB_0050d3f9:
              piVar1 = piStack_108;
              piStack_108[1] = iVar8;
              *piStack_108 = aiStack_110[0];
              piStack_108[6] = (int)puStack_fc;
              piStack_108[7] = local_f4;
              aiStack_110[1] = FUN_0072e360();
              puVar9 = puStack_fc;
              while (puStack_fc = puVar9, aiStack_110[1] != 0) {
                iVar12 = aiStack_110[1] + 0x44;
                for (iVar8 = *(int *)(aiStack_110[1] + 0x94); iVar8 != iVar12;
                    iVar8 = *(int *)(iVar8 + 0x50)) {
                  pcVar13 = (char *)(iVar8 + 0x14);
                  if (0xf < *(uint *)(iVar8 + 0x28)) {
                    pcVar13 = *(char **)pcVar13;
                  }
                  iVar15 = __stricmp(pcVar13,"product");
                  if (iVar15 == 0) {
                    if (iVar8 != 0) {
                      puVar9 = (undefined4 *)(iVar8 + 0x30);
                      if (0xf < *(uint *)(iVar8 + 0x44)) {
                        puVar9 = (undefined4 *)*puVar9;
                      }
                      if (puVar9 != (undefined4 *)0x0) {
                        iVar8 = FUN_008917b4(puVar9);
                        goto LAB_0050d46b;
                      }
                    }
                    break;
                  }
                }
                iVar8 = 0;
LAB_0050d46b:
                piVar2 = (int *)piVar1[3];
                aiStack_110[0] = iVar8;
                if (aiStack_110 < piVar2) {
                  piVar3 = (int *)piVar1[2];
                  if (aiStack_110 < piVar3) goto LAB_0050d5f9;
                  if (piVar2 == (int *)piVar1[4]) {
                    uVar7 = (int)piVar2 - (int)piVar3 >> 2;
                    if (0x3ffffffe < uVar7) goto LAB_0050d874;
                    uVar7 = uVar7 + 1;
                    uVar14 = piVar1[4] - (int)piVar3 >> 2;
                    if (uVar14 < uVar7) {
                      if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                        uVar14 = 0;
                      }
                      else {
                        uVar14 = uVar14 + (uVar14 >> 1);
                      }
                      if (uVar14 < uVar7) {
                        uVar14 = uVar7;
                      }
                      FUN_00797980(uVar14);
                    }
                  }
                  if ((undefined4 *)piVar1[3] != (undefined4 *)0x0) {
                    *(undefined4 *)piVar1[3] =
                         *(undefined4 *)(piVar1[2] + ((int)aiStack_110 - (int)piVar3 >> 2) * 4);
                  }
                }
                else {
LAB_0050d5f9:
                  if (piVar2 == (int *)piVar1[4]) {
                    uVar7 = (int)piVar2 - piVar1[2] >> 2;
                    if (0x3ffffffe < uVar7) goto LAB_0050d874;
                    uVar7 = uVar7 + 1;
                    uVar14 = piVar1[4] - piVar1[2] >> 2;
                    if (uVar14 < uVar7) {
                      if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                        uVar14 = 0;
                      }
                      else {
                        uVar14 = uVar14 + (uVar14 >> 1);
                      }
                      if (uVar14 < uVar7) {
                        uVar14 = uVar7;
                      }
                      FUN_00797980(uVar14);
                    }
                  }
                  if ((int *)piVar1[3] != (int *)0x0) {
                    *(int *)piVar1[3] = iVar8;
                  }
                }
                piVar1[3] = piVar1[3] + 4;
                aiStack_110[1] = FUN_0072e3c0();
                puVar9 = puStack_fc;
              }
              ppiVar4 = (int **)puVar9[0x12];
              puVar17 = puVar9 + 0x11;
              if (&piStack_108 < ppiVar4) {
                ppiVar5 = (int **)*puVar17;
                if (&piStack_108 < ppiVar5) goto LAB_0050d6dd;
                if (ppiVar4 == (int **)puVar9[0x13]) {
                  uVar7 = (int)ppiVar4 - (int)ppiVar5 >> 2;
                  if (0x3ffffffe < uVar7) goto LAB_0050d874;
                  uVar7 = uVar7 + 1;
                  uVar14 = (int)puVar9[0x13] - (int)ppiVar5 >> 2;
                  if (uVar14 < uVar7) {
                    if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar7) {
                      uVar14 = uVar7;
                    }
                    FUN_00797980(uVar14);
                  }
                }
                if ((undefined4 *)puVar9[0x12] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar9[0x12] =
                       *(undefined4 *)(*puVar17 + ((int)&piStack_108 - (int)ppiVar5 >> 2) * 4);
                }
              }
              else {
LAB_0050d6dd:
                if (ppiVar4 == (int **)puVar9[0x13]) {
                  uVar7 = (int)((int)ppiVar4 - *puVar17) >> 2;
                  if (0x3ffffffe < uVar7) {
LAB_0050d874:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar7 = uVar7 + 1;
                  uVar14 = (int)((int)puVar9[0x13] - *puVar17) >> 2;
                  if (uVar14 < uVar7) {
                    if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar7) {
                      uVar14 = uVar7;
                    }
                    FUN_00797980(uVar14);
                  }
                }
                if ((undefined4 *)puVar9[0x12] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar9[0x12] = piStack_108;
                }
              }
              puVar9[0x12] = puVar9[0x12] + 4;
              iVar8 = FUN_0072e3c0();
              iVar12 = local_f4;
            }
            if (((*(int *)(iVar12 + 0x2c) + *(int *)(iVar12 + 0x30) & 3U) == 0) &&
               (*(uint *)(iVar12 + 0x28) <= *(int *)(iVar12 + 0x30) + 4U >> 2)) {
              FUN_00636f70(iVar12 + 0x20);
            }
            uVar7 = *(int *)(iVar12 + 0x2c) + *(int *)(iVar12 + 0x30);
            uVar14 = uVar7 >> 2;
            if (*(uint *)(iVar12 + 0x28) <= uVar14) {
              uVar14 = uVar14 - *(uint *)(iVar12 + 0x28);
            }
            if (*(int *)(*(int *)(iVar12 + 0x24) + uVar14 * 4) == 0) {
              iVar8 = FUN_00891268(0x10);
              if (iVar8 == 0) {
                pcStack_e8 = (char *)0x0;
                std::exception::exception((exception *)appuStack_dc,&pcStack_e8);
                appuStack_dc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(appuStack_dc,&DAT_00c857a8);
              }
              *(int *)(*(int *)(iVar12 + 0x24) + uVar14 * 4) = iVar8;
            }
            piVar1 = (int *)(*(int *)(*(int *)(iVar12 + 0x24) + uVar14 * 4) + (uVar7 & 3) * 4);
            if (piVar1 != (int *)0x0) {
              *piVar1 = (int)puStack_fc;
            }
            *(int *)(iVar12 + 0x30) = *(int *)(iVar12 + 0x30) + 1;
            iStack_104 = FUN_0072e3c0();
          } while (iStack_104 != 0);
          iStack_104 = 0;
        }
        local_ec = FUN_0072e3c0();
      }
    }
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    FUN_006edb60(&DAT_00c0df54);
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  local_3c = 0;
  local_38 = 0xf;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_114);
  return;
}

