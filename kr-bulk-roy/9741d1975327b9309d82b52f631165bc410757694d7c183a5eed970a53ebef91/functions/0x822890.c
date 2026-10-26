
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00822890(undefined4 param_1)

{
  char **ppcVar1;
  char **ppcVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  undefined4 uVar16;
  int *piVar17;
  int *piVar18;
  undefined4 uVar19;
  uint uVar20;
  int *piVar21;
  undefined **local_164 [3];
  undefined **local_158 [3];
  int local_14c;
  int *local_148;
  int local_144;
  int *local_140;
  undefined4 local_13c;
  undefined4 *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  undefined4 *local_11c;
  int *local_118;
  int local_114;
  char *local_110;
  char *local_10c;
  int *local_108;
  int *local_104;
  undefined **local_100 [19];
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
  uint local_88 [4];
  undefined4 local_78;
  uint local_74;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925f26;
  local_10 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_134 = param_1;
  local_18 = uVar8;
  FUN_0072ee30(local_100);
  local_8 = 0;
  cVar4 = FUN_0072f110(0);
  if (cVar4 == '\0') {
    local_8 = 0xffffffff;
    local_100[0] = TiXmlDocument::vftable;
    if (0xf < local_a0) {
      FUN_0089120c(local_b4);
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = local_b4 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e360(uVar8);
    local_120 = FUN_0072e360();
    iVar10 = local_120;
    while (iVar10 != 0) {
      piVar9 = (int *)FUN_00891268(0x58);
      local_104 = piVar9;
      if (piVar9 == (int *)0x0) {
        local_108 = (int *)0x0;
      }
      else {
        piVar9[9] = 7;
        piVar9[8] = 0;
        *(undefined2 *)(piVar9 + 4) = 0;
        piVar9[0x10] = 7;
        piVar9[0xf] = 0;
        *(undefined2 *)(piVar9 + 0xb) = 0;
        local_8 = CONCAT31(local_8._1_3_,3);
        piVar9[0x14] = 0;
        iVar10 = FUN_00891268(0x18);
        if (iVar10 == 0) {
          local_10c = (char *)0x0;
          std::exception::exception((exception *)local_158,&local_10c);
          local_158[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_158,&DAT_00c857a8);
        }
        piVar9[0x13] = iVar10;
        *(int *)iVar10 = iVar10;
        *(int *)(piVar9[0x13] + 4) = piVar9[0x13];
        *(int *)(piVar9[0x13] + 8) = piVar9[0x13];
        *(undefined1 *)(piVar9[0x13] + 0x14) = 1;
        *(undefined1 *)(piVar9[0x13] + 0x15) = 1;
        local_108 = piVar9;
      }
      iVar10 = local_120 + 0x44;
      local_8 = local_8 & 0xffffff00;
      for (iVar13 = *(int *)(local_120 + 0x94); iVar13 != iVar10; iVar13 = *(int *)(iVar13 + 0x50))
      {
        pcVar15 = (char *)(iVar13 + 0x14);
        if (0xf < *(uint *)(iVar13 + 0x28)) {
          pcVar15 = *(char **)pcVar15;
        }
        iVar11 = __stricmp(pcVar15,"ID");
        if (iVar11 == 0) {
          if (iVar13 != 0) {
            puVar12 = (undefined4 *)(iVar13 + 0x30);
            if (0xf < *(uint *)(iVar13 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              iVar10 = FUN_008917b4(puVar12);
              goto LAB_00822a39;
            }
          }
          break;
        }
      }
      iVar10 = 0;
LAB_00822a39:
      *local_108 = iVar10;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 4;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8._0_1_ = 6;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      FUN_00402a70(&DAT_00c0dfbc,4);
      local_8._0_1_ = 7;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,9);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      piVar9 = local_108;
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      FUN_00440130(local_88);
      FUN_00440130(local_6c);
      iVar10 = FUN_0072e360();
      if (iVar10 != 0) {
        iVar10 = FUN_007300a0("CP_TOTAL");
        if (iVar10 == 0) {
LAB_00822b82:
          uVar6 = 0;
        }
        else {
          puVar12 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar12 = (undefined4 *)*puVar12;
          }
          if (puVar12 == (undefined4 *)0x0) goto LAB_00822b82;
          uVar6 = FUN_008917b4(puVar12);
        }
        *(undefined2 *)(piVar9 + 2) = uVar6;
        iVar10 = FUN_007300a0("MIN_LEVEL");
        if (iVar10 == 0) {
LAB_00822baf:
          uVar5 = 1;
        }
        else {
          puVar12 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar12 = (undefined4 *)*puVar12;
          }
          if (puVar12 == (undefined4 *)0x0) goto LAB_00822baf;
          uVar5 = FUN_008917b4(puVar12);
        }
        *(undefined1 *)(piVar9 + 3) = uVar5;
        iVar10 = FUN_007300a0("OPTIMAL_LEVEL");
        if (iVar10 == 0) {
LAB_00822bde:
          uVar5 = 1;
        }
        else {
          puVar12 = (undefined4 *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            puVar12 = (undefined4 *)*puVar12;
          }
          if (puVar12 == (undefined4 *)0x0) goto LAB_00822bde;
          uVar5 = FUN_008917b4(puVar12);
        }
        *(undefined1 *)((int)piVar9 + 0xd) = uVar5;
      }
      iVar13 = FUN_0072e360();
      for (iVar10 = *(int *)(iVar13 + 0x94); iVar10 != iVar13 + 0x44;
          iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar15 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar15 = *(char **)pcVar15;
        }
        iVar11 = __stricmp(pcVar15,"FIRSTSTAGE");
        if (iVar11 == 0) {
          if (iVar10 != 0) {
            puVar12 = (undefined4 *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              iVar10 = FUN_008917b4(puVar12);
              goto LAB_00822c2f;
            }
          }
          break;
        }
      }
      iVar10 = 0;
LAB_00822c2f:
      local_108[1] = iVar10;
      if (iVar13 != 0) {
        local_114 = FUN_0072e360();
        while (local_114 != 0) {
          piVar9 = (int *)FUN_00891268(0x2c);
          local_8._0_1_ = 10;
          local_104 = piVar9;
          if (piVar9 == (int *)0x0) {
            local_118 = (int *)0x0;
          }
          else {
            piVar9[5] = 0;
            iVar10 = FUN_00891268(0x18);
            if (iVar10 == 0) {
              local_10c = (char *)0x0;
              std::exception::exception((exception *)local_164,&local_10c);
              local_164[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(local_164,&DAT_00c857a8);
            }
            piVar9[4] = iVar10;
            *(int *)iVar10 = iVar10;
            *(int *)(piVar9[4] + 4) = piVar9[4];
            *(int *)(piVar9[4] + 8) = piVar9[4];
            *(undefined1 *)(piVar9[4] + 0x14) = 1;
            *(undefined1 *)(piVar9[4] + 0x15) = 1;
            piVar9[7] = 0;
            piVar9[8] = 0;
            piVar9[9] = 0;
            local_118 = piVar9;
          }
          iVar13 = local_114;
          piVar9 = local_118;
          iVar11 = local_114 + 0x44;
          local_8 = CONCAT31(local_8._1_3_,9);
          for (iVar10 = *(int *)(local_114 + 0x94); iVar10 != iVar11;
              iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar15 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar15 = *(char **)pcVar15;
            }
            iVar14 = __stricmp(pcVar15,"STAGEID");
            if (iVar14 == 0) {
              if (iVar10 != 0) {
                puVar12 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar12 = (undefined4 *)*puVar12;
                }
                if (puVar12 != (undefined4 *)0x0) {
                  iVar10 = FUN_008917b4(puVar12);
                  goto LAB_00822d2c;
                }
              }
              break;
            }
          }
          iVar10 = 0;
LAB_00822d2c:
          *piVar9 = iVar10;
          for (iVar10 = *(int *)(iVar13 + 0x94); iVar10 != iVar11; iVar10 = *(int *)(iVar10 + 0x50))
          {
            pcVar15 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar15 = *(char **)pcVar15;
            }
            iVar14 = __stricmp(pcVar15,"TOTAL_CP");
            if (iVar14 == 0) {
              if (iVar10 != 0) {
                puVar12 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar12 = (undefined4 *)*puVar12;
                }
                if (puVar12 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar12);
                  goto LAB_00822da1;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_00822da1:
          iVar10 = *(int *)(iVar13 + 0x94);
          local_130 = CONCAT22(local_130._2_2_,uVar6);
          for (; iVar10 != iVar11; iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar15 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar15 = *(char **)pcVar15;
            }
            iVar14 = __stricmp(pcVar15,"BOSS_COUNT");
            if (iVar14 == 0) {
              if (iVar10 != 0) {
                puVar12 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar12 = (undefined4 *)*puVar12;
                }
                if (puVar12 != (undefined4 *)0x0) {
                  uVar5 = FUN_008917b4(puVar12);
                  goto LAB_00822dd9;
                }
              }
              break;
            }
          }
          uVar5 = 0;
LAB_00822dd9:
          iVar10 = *(int *)(iVar13 + 0x94);
          local_130._0_3_ = CONCAT12(uVar5,(undefined2)local_130);
          for (; iVar10 != iVar11; iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar15 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar15 = *(char **)pcVar15;
            }
            iVar14 = __stricmp(pcVar15,"FAIL_CP");
            if (iVar14 == 0) {
              if (iVar10 != 0) {
                puVar12 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar12 = (undefined4 *)*puVar12;
                }
                if (puVar12 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar12);
                  goto LAB_00822e0f;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_00822e0f:
          iVar10 = *(int *)(iVar13 + 0x94);
          local_12c = CONCAT22(local_12c._2_2_,uVar6);
          for (; iVar10 != iVar11; iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar15 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar15 = *(char **)pcVar15;
            }
            iVar13 = __stricmp(pcVar15,"START_CP");
            if (iVar13 == 0) {
              if (iVar10 != 0) {
                puVar12 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar12 = (undefined4 *)*puVar12;
                }
                if (puVar12 != (undefined4 *)0x0) {
                  uVar7 = FUN_008917b4(puVar12);
                  goto LAB_00822e4a;
                }
              }
              break;
            }
          }
          uVar7 = 0;
LAB_00822e4a:
          local_12c = CONCAT22(uVar7,(undefined2)local_12c);
          local_118[1] = local_130;
          local_118[2] = local_12c;
          if (*local_118 == local_108[1]) {
            *(undefined2 *)((int)local_108 + 10) = uVar6;
          }
          iVar10 = FUN_0072e360();
          if (iVar10 != 0) {
            iVar10 = FUN_0072e360();
            while (local_10c = (char *)iVar10, iVar10 != 0) {
              local_11c = (undefined4 *)FUN_00891268(0x14);
              if (local_11c == (undefined4 *)0x0) {
                local_11c = (undefined4 *)0x0;
              }
              else {
                local_11c[1] = 0;
                local_11c[2] = 0;
                local_11c[3] = 0;
              }
              for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar10 + 0x44;
                  iVar13 = *(int *)(iVar13 + 0x50)) {
                pcVar15 = (char *)(iVar13 + 0x14);
                if (0xf < *(uint *)(iVar13 + 0x28)) {
                  pcVar15 = *(char **)pcVar15;
                }
                iVar11 = __stricmp(pcVar15,"ID");
                if (iVar11 == 0) {
                  if (iVar13 != 0) {
                    puVar12 = (undefined4 *)(iVar13 + 0x30);
                    if (0xf < *(uint *)(iVar13 + 0x44)) {
                      puVar12 = (undefined4 *)*puVar12;
                    }
                    if (puVar12 != (undefined4 *)0x0) {
                      uVar16 = FUN_008917b4(puVar12);
                      goto LAB_00822f90;
                    }
                  }
                  break;
                }
              }
              uVar16 = 0;
LAB_00822f90:
              *local_11c = uVar16;
              local_104 = (int *)FUN_0072e360();
              puVar12 = local_11c;
              if (local_104 != (int *)0x0) {
                do {
                  local_110 = (char *)FUN_00891268(8);
                  piVar18 = local_104;
                  piVar21 = local_104 + 0x11;
                  for (piVar9 = (int *)local_104[0x25]; piVar9 != piVar21;
                      piVar9 = (int *)piVar9[0x14]) {
                    piVar17 = piVar9 + 5;
                    if (0xf < (uint)piVar9[10]) {
                      piVar17 = (int *)*piVar17;
                    }
                    iVar10 = __stricmp((char *)piVar17,"STAGEID");
                    if (iVar10 == 0) {
                      if (piVar9 != (int *)0x0) {
                        piVar17 = piVar9 + 0xc;
                        if (0xf < (uint)piVar9[0x11]) {
                          piVar17 = (int *)*piVar17;
                        }
                        if (piVar17 != (int *)0x0) {
                          uVar16 = FUN_008917b4(piVar17);
                          goto LAB_0082300a;
                        }
                      }
                      break;
                    }
                  }
                  uVar16 = 0;
LAB_0082300a:
                  *(undefined4 *)local_110 = uVar16;
                  for (piVar9 = (int *)piVar18[0x25]; piVar9 != piVar21;
                      piVar9 = (int *)piVar9[0x14]) {
                    piVar18 = piVar9 + 5;
                    if (0xf < (uint)piVar9[10]) {
                      piVar18 = (int *)*piVar18;
                    }
                    iVar10 = __stricmp((char *)piVar18,"RATIO");
                    if (iVar10 == 0) {
                      if (piVar9 != (int *)0x0) {
                        piVar18 = piVar9 + 0xc;
                        if (0xf < (uint)piVar9[0x11]) {
                          piVar18 = (int *)*piVar18;
                        }
                        if (piVar18 != (int *)0x0) {
                          uVar16 = FUN_008917b4(piVar18);
                          goto LAB_0082304a;
                        }
                      }
                      break;
                    }
                  }
                  uVar16 = 0;
LAB_0082304a:
                  *(undefined4 *)(local_110 + 4) = uVar16;
                  ppcVar1 = (char **)puVar12[2];
                  if (&local_110 < ppcVar1) {
                    ppcVar2 = (char **)puVar12[1];
                    if (&local_110 < ppcVar2) goto LAB_00823157;
                    if (ppcVar1 == (char **)puVar12[3]) {
                      uVar8 = (int)ppcVar1 - (int)ppcVar2 >> 2;
                      if (0x3ffffffe < uVar8) goto LAB_00823612;
                      uVar8 = uVar8 + 1;
                      uVar20 = (int)puVar12[3] - (int)ppcVar2 >> 2;
                      if (uVar20 < uVar8) {
                        if (0x3fffffff - (uVar20 >> 1) < uVar20) {
                          uVar20 = 0;
                        }
                        else {
                          uVar20 = uVar20 + (uVar20 >> 1);
                        }
                        if (uVar20 < uVar8) {
                          uVar20 = uVar8;
                        }
                        FUN_00797980(uVar20);
                      }
                    }
                    if ((undefined4 *)puVar12[2] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar12[2] =
                           *(undefined4 *)(puVar12[1] + ((int)&local_110 - (int)ppcVar2 >> 2) * 4);
                    }
                  }
                  else {
LAB_00823157:
                    if (ppcVar1 == (char **)puVar12[3]) {
                      uVar8 = (int)ppcVar1 - puVar12[1] >> 2;
                      if (0x3ffffffe < uVar8) goto LAB_00823612;
                      uVar8 = uVar8 + 1;
                      uVar20 = (int)puVar12[3] - puVar12[1] >> 2;
                      if (uVar20 < uVar8) {
                        if (0x3fffffff - (uVar20 >> 1) < uVar20) {
                          uVar20 = 0;
                        }
                        else {
                          uVar20 = uVar20 + (uVar20 >> 1);
                        }
                        if (uVar20 < uVar8) {
                          uVar20 = uVar8;
                        }
                        FUN_00797980(uVar20);
                      }
                    }
                    if ((undefined4 *)puVar12[2] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar12[2] = local_110;
                    }
                  }
                  puVar12[2] = puVar12[2] + 4;
                  local_104 = (int *)FUN_0072e3c0();
                } while (local_104 != (int *)0x0);
                local_104 = (int *)0x0;
              }
              local_13c = *local_11c;
              piVar9 = local_118 + 3;
              local_138 = local_11c;
              uVar16 = FUN_0057ef20();
              FUN_0057e850(piVar9,uVar16);
              iVar10 = FUN_0072e3c0();
            }
          }
          iVar10 = FUN_0072e360();
          if (iVar10 != 0) {
            piVar9 = (int *)FUN_0072e360();
            piVar18 = local_118;
            while (local_104 = piVar9, piVar9 != (int *)0x0) {
              for (piVar21 = (int *)piVar9[0x25]; piVar21 != piVar9 + 0x11;
                  piVar21 = (int *)piVar21[0x14]) {
                piVar17 = piVar21 + 5;
                if (0xf < (uint)piVar21[10]) {
                  piVar17 = (int *)*piVar17;
                }
                iVar10 = __stricmp((char *)piVar17,"PRODUCT");
                if (iVar10 == 0) {
                  if (piVar21 != (int *)0x0) {
                    piVar17 = piVar21 + 0xc;
                    if (0xf < (uint)piVar21[0x11]) {
                      piVar17 = (int *)*piVar17;
                    }
                    if (piVar17 != (int *)0x0) {
                      local_128 = FUN_008917b4(piVar17);
                      goto LAB_0082329d;
                    }
                  }
                  break;
                }
              }
              local_128 = 0;
LAB_0082329d:
              for (piVar21 = (int *)piVar9[0x25]; piVar21 != piVar9 + 0x11;
                  piVar21 = (int *)piVar21[0x14]) {
                piVar17 = piVar21 + 5;
                if (0xf < (uint)piVar21[10]) {
                  piVar17 = (int *)*piVar17;
                }
                iVar10 = __stricmp((char *)piVar17,"QTY");
                if (iVar10 == 0) {
                  if (piVar21 != (int *)0x0) {
                    piVar9 = piVar21 + 0xc;
                    if (0xf < (uint)piVar21[0x11]) {
                      piVar9 = (int *)*piVar9;
                    }
                    if (piVar9 != (int *)0x0) {
                      uVar5 = FUN_008917b4(piVar9);
                      goto LAB_008232dd;
                    }
                  }
                  break;
                }
              }
              uVar5 = 1;
LAB_008232dd:
              local_124 = CONCAT31(local_124._1_3_,uVar5);
              puVar12 = (undefined4 *)piVar18[8];
              if (&local_128 < puVar12) {
                puVar3 = (undefined4 *)piVar18[7];
                if (&local_128 < puVar3) goto LAB_008233bd;
                if (puVar12 == (undefined4 *)piVar18[9]) {
                  uVar8 = (int)puVar12 - (int)puVar3 >> 3;
                  if (0x1ffffffe < uVar8) goto LAB_00823612;
                  uVar8 = uVar8 + 1;
                  uVar20 = piVar18[9] - (int)puVar3 >> 3;
                  if (uVar20 < uVar8) {
                    if (0x1fffffff - (uVar20 >> 1) < uVar20) {
                      uVar20 = 0;
                    }
                    else {
                      uVar20 = uVar20 + (uVar20 >> 1);
                    }
                    if (uVar20 < uVar8) {
                      uVar20 = uVar8;
                    }
                    FUN_004e7330(uVar20);
                  }
                }
                puVar12 = (undefined4 *)piVar18[8];
                puVar3 = (undefined4 *)(piVar18[7] + ((int)&local_128 - (int)puVar3 >> 3) * 8);
                if (puVar12 != (undefined4 *)0x0) {
                  *puVar12 = *puVar3;
                  uVar16 = puVar3[1];
                  goto LAB_0082341a;
                }
              }
              else {
LAB_008233bd:
                if (puVar12 == (undefined4 *)piVar18[9]) {
                  uVar8 = (int)puVar12 - piVar18[7] >> 3;
                  if (0x1ffffffe < uVar8) {
LAB_00823612:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar8 = uVar8 + 1;
                  uVar20 = piVar18[9] - piVar18[7] >> 3;
                  if (uVar20 < uVar8) {
                    if (0x1fffffff - (uVar20 >> 1) < uVar20) {
                      uVar20 = 0;
                    }
                    else {
                      uVar20 = uVar20 + (uVar20 >> 1);
                    }
                    if (uVar20 < uVar8) {
                      uVar20 = uVar8;
                    }
                    FUN_004e7330(uVar20);
                  }
                }
                puVar12 = (undefined4 *)piVar18[8];
                if (puVar12 != (undefined4 *)0x0) {
                  *puVar12 = local_128;
                  uVar16 = local_124;
LAB_0082341a:
                  puVar12[1] = uVar16;
                }
              }
              piVar18[8] = piVar18[8] + 8;
              piVar9 = (int *)FUN_0072e3c0();
            }
          }
          local_14c = *local_118;
          piVar9 = local_108 + 0x12;
          local_148 = local_118;
          uVar16 = FUN_0057ef20();
          FUN_0057e850(piVar9,uVar16);
          local_114 = FUN_0072e3c0();
        }
      }
      uVar16 = local_134;
      local_144 = *local_108;
      local_140 = local_108;
      uVar19 = FUN_0057ef20();
      FUN_0057e850(uVar16,uVar19);
      iVar10 = FUN_0072e3c0();
      local_120 = iVar10;
      if (0xf < local_58) {
        FUN_0089120c(local_6c[0]);
      }
      local_8 = local_8 & 0xffffff00;
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = local_6c[0] & 0xffffff00;
      if (0xf < local_74) {
        FUN_0089120c(local_88[0]);
      }
      local_74 = 0xf;
      local_78 = 0;
      local_88[0] = local_88[0] & 0xffffff00;
    }
    local_8 = 0xffffffff;
    local_100[0] = TiXmlDocument::vftable;
    _DAT_00fba918 = local_134;
    if (0xf < local_a0) {
      FUN_0089120c(local_b4);
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = local_b4 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

