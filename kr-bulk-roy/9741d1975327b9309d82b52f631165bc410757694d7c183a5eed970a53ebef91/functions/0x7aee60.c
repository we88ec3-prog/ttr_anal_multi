
/* WARNING: Type propagation algorithm not settling */

void FUN_007aee60(int *param_1,char *param_2)

{
  uint **ppuVar1;
  uint *puVar2;
  char cVar3;
  ushort uVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  char *pcVar8;
  char *******pppppppcVar9;
  int iVar10;
  uint *puVar11;
  char *******pppppppcVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint **ppuVar15;
  int *piVar16;
  uint uVar17;
  int iVar18;
  char *pcVar19;
  undefined2 uVar20;
  char *pcVar21;
  uint *puVar22;
  long lVar23;
  float10 fVar24;
  int local_400;
  int local_3fc;
  int local_3f8;
  int local_3f4;
  int local_3ec;
  int local_3e8;
  int local_3e4;
  uint *local_3e0 [3];
  int local_3d4;
  uint *local_3d0;
  uint *local_3cc;
  uint *local_3c8;
  uint *local_3c4 [2];
  uint local_3bc;
  undefined4 local_3ac;
  uint local_3a8;
  undefined **local_3a0;
  undefined1 local_390;
  undefined4 local_38f;
  undefined4 local_38b;
  undefined4 local_387;
  undefined4 uStack_383;
  undefined4 uStack_37f;
  undefined4 local_37b;
  undefined4 local_377;
  undefined4 local_373;
  char local_36f [27];
  uint local_354;
  undefined4 local_344;
  uint local_340;
  undefined4 local_32c;
  uint local_328;
  undefined4 local_318;
  uint local_314;
  char *******local_30c [4];
  undefined4 local_2fc;
  uint local_2f8;
  long local_2f0;
  uint local_2ec;
  undefined4 local_2dc;
  uint local_2d8;
  uint local_2d0;
  undefined4 local_2c0;
  uint local_2bc;
  uint local_2b4;
  undefined4 local_2a4;
  uint local_2a0;
  char *******local_298 [4];
  undefined4 local_288;
  uint local_284;
  uint local_27c;
  int local_270;
  int local_26c;
  uint local_268;
  char *******local_260 [3];
  int local_254;
  char *local_250;
  uint local_24c;
  char *******local_244 [3];
  char local_238 [4];
  uint local_234;
  uint local_230;
  char cStack_229;
  char local_228 [264];
  char local_120 [88];
  ushort local_c8;
  undefined1 local_a8;
  byte local_a7;
  float local_a4;
  char local_a0;
  undefined1 local_9f;
  undefined4 local_9c;
  undefined4 local_60;
  float local_24;
  undefined4 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093545d;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00719da0();
  FUN_0071baa0();
  pcVar21 = (char *)0x0;
  if (local_3d0 == (uint *)0x0) {
    pcVar8 = (char *)0x0;
  }
  else {
    pcVar8 = (char *)local_3d0[2];
    if (pcVar8 == (char *)0x0) {
      pcVar8 = "";
    }
  }
  local_2f8 = 0xf;
  local_2fc = 0;
  local_30c[0] = (char *******)((uint)local_30c[0] & 0xffffff00);
  do {
    cVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar7 != '\0');
  FUN_00402a70();
  local_8 = 0;
  do {
    cVar7 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar7 != '\0');
  FUN_00402a70();
  FUN_0071baa0();
  if (local_3d0 == (uint *)0x0) {
    pppppppcVar9 = local_30c[0];
    if (local_2f8 < 0x10) {
      pppppppcVar9 = (char *******)local_30c;
    }
    FUN_0071baa0();
    if ((local_3d0 != (uint *)0x0) && (pcVar21 = (char *)local_3d0[2], pcVar21 == (char *)0x0)) {
      pcVar21 = "";
    }
    do {
      cVar7 = *pcVar21;
      pcVar21 = pcVar21 + 1;
    } while (cVar7 != '\0');
    FUN_00402a70();
    do {
      cVar7 = *(char *)pppppppcVar9;
      pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
    } while (cVar7 != '\0');
    FUN_00402a70();
  }
  else {
    FUN_0071baa0();
    if (local_3d0 == (uint *)0x0) {
      pcVar21 = (char *)0x0;
    }
    else {
      pcVar21 = (char *)local_3d0[2];
      if (pcVar21 == (char *)0x0) {
        pcVar21 = "";
      }
    }
    local_2bc = 0xf;
    local_2c0 = 0;
    local_2d0 = local_2d0 & 0xffffff00;
    do {
      cVar7 = *pcVar21;
      pcVar21 = pcVar21 + 1;
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_270 = 0;
    local_26c = 0;
    local_268 = 0;
    local_8._0_1_ = 2;
    local_24c = 0xf;
    local_250 = (char *)0x0;
    local_260[0] = (char *******)((uint)local_260[0] & 0xffffff00);
    FUN_00402a70();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_007da6b0();
    if (0xf < local_24c) {
      FUN_0089120c();
    }
    local_230 = 0xf;
    local_234 = 0;
    local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
    local_8._0_1_ = 4;
    local_3c8 = (uint *)((local_26c - local_270) / 0x1c);
    if (0 < (int)local_3c8) {
      pcVar21 = (char *)(local_270 + (int)local_3c8 * 0x1c);
      do {
        local_3c8 = (uint *)((int)local_3c8 + -1);
        pcVar19 = pcVar21 + -0x1c;
        pcVar8 = pcVar19;
        if (0xf < *(uint *)(pcVar21 + -8)) {
          pcVar8 = *(char **)pcVar19;
        }
        pcVar21 = _strstr(pcVar8,"Avatar");
        if (pcVar21 != (char *)0x0) break;
        local_24c = 0xf;
        local_260[0] = (char *******)((uint)local_260[0] & 0xffffff00);
        local_250 = pcVar21;
        FUN_00402a70();
        local_8._0_1_ = 5;
        FUN_007b25e0();
        local_8._0_1_ = 6;
        FUN_006ddbb0();
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00402bb0();
        if (0xf < local_2d8) {
          FUN_0089120c();
        }
        local_2d8 = 0xf;
        local_2dc = 0;
        local_2ec = local_2ec & 0xffffff00;
        if (0xf < local_284) {
          FUN_0089120c();
        }
        local_8._0_1_ = 4;
        local_284 = 0xf;
        local_288 = 0;
        local_298[0] = (char *******)((uint)local_298[0] & 0xffffff00);
        if (0xf < local_24c) {
          FUN_0089120c();
        }
        pcVar21 = pcVar19;
      } while (0 < (int)local_3c8);
    }
    pppppppcVar9 = local_30c[0];
    if (local_2f8 < 0x10) {
      pppppppcVar9 = (char *******)local_30c;
    }
    pppppppcVar12 = local_244[0];
    if (local_230 < 0x10) {
      pppppppcVar12 = (char *******)local_244;
    }
    do {
      cVar7 = *(char *)pppppppcVar12;
      pppppppcVar12 = (char *******)((int)pppppppcVar12 + 1);
    } while (cVar7 != '\0');
    FUN_00402a70();
    do {
      cVar7 = *(char *)pppppppcVar9;
      pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
    } while (cVar7 != '\0');
    FUN_00402a70();
    if (0xf < local_230) {
      FUN_0089120c();
    }
    local_230 = 0xf;
    local_234 = 0;
    local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
    if (local_270 != 0) {
      FUN_00440a80();
      FUN_0089120c();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_2bc) {
      FUN_0089120c();
    }
  }
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  FUN_00719da0();
  if ((local_3e0[2] != (uint *)0x0) && (FUN_00719da0(), local_3c4[1] != (uint *)0x0)) {
LAB_007af403:
    FUN_0071baa0();
    if (local_3e0[2] == (uint *)0x0) {
      pcVar21 = (char *)0x0;
    }
    else {
      pcVar21 = (char *)local_3e0[2][2];
      if (pcVar21 == (char *)0x0) {
        pcVar21 = "";
      }
    }
    local_24c = 0xf;
    local_250 = (char *)0x0;
    local_260[0] = (char *******)((uint)local_260[0] & 0xffffff00);
    do {
      cVar7 = *pcVar21;
      pcVar21 = pcVar21 + 1;
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_8._0_1_ = 8;
    pppppppcVar9 = local_260[0];
    if (local_24c < 0x10) {
      pppppppcVar9 = (char *******)local_260;
    }
    local_2bc = 0xf;
    local_2c0 = 0;
    local_2d0 = local_2d0 & 0xffffff00;
    do {
      cVar7 = *(char *)pppppppcVar9;
      pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_8._0_1_ = 9;
    FUN_00556090();
    local_8._0_1_ = 8;
    if (0xf < local_2bc) {
      FUN_0089120c();
    }
    FUN_0071baa0();
    if (local_3cc == (uint *)0x0) {
      pcVar21 = (char *)0x0;
    }
    else {
      pcVar21 = (char *)local_3cc[2];
      if (pcVar21 == (char *)0x0) {
        pcVar21 = "";
      }
    }
    local_230 = 0xf;
    local_234 = 0;
    local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
    do {
      cVar7 = *pcVar21;
      pcVar21 = pcVar21 + 1;
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_8 = CONCAT31(local_8._1_3_,10);
    iVar10 = FUN_00407e70();
    if (iVar10 != 0 || local_234 != 0) {
      puVar11 = (uint *)FUN_00891268();
      if (puVar11 == (uint *)0x0) {
        local_3c8 = (uint *)0x0;
      }
      else {
        *(undefined1 *)puVar11 = 0;
        puVar11[0x11] = 0;
        puVar11[0x12] = 0;
        puVar11[0x13] = 0;
        *(undefined2 *)(puVar11 + 0x15) = 0;
        puVar11[0x16] = 0;
        _memset((undefined1 *)((int)puVar11 + 1),0,0x40);
        local_3c8 = puVar11;
      }
      local_3e0[0] = local_3c8;
      pppppppcVar9 = local_260[0];
      if (local_24c < 0x10) {
        pppppppcVar9 = (char *******)local_260;
      }
      pppppppcVar12 = pppppppcVar9;
      do {
        cVar7 = *(char *)pppppppcVar12;
        *(char *)((int)pppppppcVar12 + (int)((int)local_3c8 + (1 - (int)pppppppcVar9))) = cVar7;
        uVar13 = local_234;
        pppppppcVar12 = (char *******)((int)pppppppcVar12 + 1);
      } while (cVar7 != '\0');
      puVar11 = *(uint **)(local_3d4 + 0xa4);
      local_3c4[0] = *(uint **)(local_3d4 + 0xa8);
      if (puVar11 != local_3c4[0]) {
        do {
          pcVar8 = (char *)*puVar11;
          pcVar21 = pcVar8 + 1;
          do {
            cVar7 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar7 != '\0');
          iVar10 = FUN_00407e70();
          if (((iVar10 == 0) && ((uint)((int)pcVar8 - (int)pcVar21) <= uVar13)) &&
             (uVar13 == (int)pcVar8 - (int)pcVar21)) {
            puVar11 = (uint *)*puVar11;
            if (puVar11 != (uint *)0x0) goto LAB_007af7c4;
            break;
          }
          puVar11 = puVar11 + 1;
        } while (puVar11 != local_3c4[0]);
      }
      puVar11 = (uint *)FUN_00891268();
      iVar10 = local_3d4;
      if (puVar11 == (uint *)0x0) {
        puVar11 = (uint *)0x0;
      }
      else {
        puVar11[8] = 0;
        puVar11[9] = 0;
        puVar11[10] = 0;
        *puVar11 = 0;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11[3] = 0;
        puVar11[4] = 0;
        puVar11[5] = 0;
        puVar11[6] = 0;
        puVar11[7] = 0;
      }
      local_3c4[0] = puVar11;
      pppppppcVar9 = local_244[0];
      if (local_230 < 0x10) {
        pppppppcVar9 = (char *******)local_244;
      }
      iVar18 = (int)puVar11 - (int)pppppppcVar9;
      do {
        cVar7 = *(char *)pppppppcVar9;
        *(char *)((int)pppppppcVar9 + iVar18) = cVar7;
        pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
      } while (cVar7 != '\0');
      ppuVar15 = *(uint ***)(local_3d4 + 0xa8);
      puVar22 = (uint *)(local_3d4 + 0xa4);
      if ((local_3c4 < ppuVar15) && (ppuVar1 = (uint **)*puVar22, ppuVar1 <= local_3c4)) {
        if (ppuVar15 == *(uint ***)(local_3d4 + 0xac)) {
          uVar13 = (int)ppuVar15 - (int)ppuVar1 >> 2;
          if (0x3ffffffe < uVar13) goto LAB_007afe3a;
          if ((uint)((int)*(uint ***)(local_3d4 + 0xac) - (int)ppuVar1 >> 2) < uVar13 + 1) {
            FUN_00797980();
          }
        }
        if (*(undefined4 **)(iVar10 + 0xa8) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar10 + 0xa8) =
               *(undefined4 *)(*puVar22 + ((int)local_3c4 - (int)ppuVar1 >> 2) * 4);
        }
      }
      else {
        if (ppuVar15 == *(uint ***)(local_3d4 + 0xac)) {
          uVar13 = (int)((int)ppuVar15 - *puVar22) >> 2;
          if (0x3ffffffe < uVar13) goto LAB_007afe3a;
          if ((uint)((int)((int)*(uint ***)(local_3d4 + 0xac) - *puVar22) >> 2) < uVar13 + 1) {
            FUN_00797980();
          }
        }
        if (*(undefined4 **)(iVar10 + 0xa8) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar10 + 0xa8) = puVar11;
        }
      }
      *(int *)(iVar10 + 0xa8) = *(int *)(iVar10 + 0xa8) + 4;
      puVar11 = local_3c4[0];
LAB_007af7c4:
      puVar2 = local_3c8;
      puVar22 = puVar11 + 8;
      *(char *)local_3c8 = (char)((int)(puVar11[9] - puVar11[8]) >> 2);
      if (puVar11 != (uint *)0x0) {
        ppuVar15 = (uint **)puVar11[9];
        if ((local_3e0 < ppuVar15) && (ppuVar1 = (uint **)*puVar22, ppuVar1 <= local_3e0)) {
          if (ppuVar15 == (uint **)puVar11[10]) {
            uVar13 = (int)ppuVar15 - (int)ppuVar1 >> 2;
            if (0x3ffffffe < uVar13) {
LAB_007afe3a:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30();
            }
            if ((uint)((int)puVar11[10] - (int)ppuVar1 >> 2) < uVar13 + 1) {
              FUN_00797980();
            }
          }
          if ((undefined4 *)puVar11[9] != (undefined4 *)0x0) {
            *(undefined4 *)puVar11[9] =
                 *(undefined4 *)(*puVar22 + ((int)local_3e0 - (int)ppuVar1 >> 2) * 4);
          }
        }
        else {
          if (ppuVar15 == (uint **)puVar11[10]) {
            uVar13 = (int)((int)ppuVar15 - *puVar22) >> 2;
            if (0x3ffffffe < uVar13) goto LAB_007afe3a;
            if ((uint)((int)((int)puVar11[10] - *puVar22) >> 2) < uVar13 + 1) {
              FUN_00797980();
            }
          }
          if ((undefined4 *)puVar11[9] != (undefined4 *)0x0) {
            *(undefined4 *)puVar11[9] = puVar2;
          }
        }
        puVar11[9] = puVar11[9] + 4;
      }
    }
    if (local_3c4[1] != (uint *)0x0) {
      for (puVar11 = (uint *)local_3c4[1][6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6])
      {
        if (((char *)puVar11[2] != (char *)0x0) &&
           (iVar10 = __stricmp("Mesh",(char *)puVar11[2]), iVar10 == 0)) {
          if (puVar11 == (uint *)0x0) goto LAB_007afe24;
          goto LAB_007afdf2;
        }
      }
    }
    goto LAB_007af8d4;
  }
LAB_007af936:
  if ((local_3e4 != 0) && (FUN_00719da0(), local_3cc != (uint *)0x0)) {
    puVar11 = local_3cc;
    local_3cc = (uint *)(local_3d4 + 0x74);
LAB_007af977:
    if (puVar11 != (uint *)0x0) {
      for (uVar13 = puVar11[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
        if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
           (iVar10 = __stricmp("File",*(char **)(uVar13 + 4)), iVar10 == 0)) {
          pcVar21 = *(char **)(uVar13 + 8);
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "";
          }
          goto LAB_007af9a8;
        }
      }
    }
    pcVar21 = (char *)0x0;
LAB_007af9a8:
    local_230 = 0xf;
    local_234 = 0;
    local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
    do {
      cVar7 = *pcVar21;
      pcVar21 = pcVar21 + 1;
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_8._0_1_ = 0xb;
    pppppppcVar9 = local_244[0];
    if (local_230 < 0x10) {
      pppppppcVar9 = (char *******)local_244;
    }
    local_2bc = 0xf;
    local_2c0 = 0;
    local_2d0 = local_2d0 & 0xffffff00;
    do {
      cVar7 = *(char *)pppppppcVar9;
      pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
    } while (cVar7 != '\0');
    FUN_00402a70();
    local_8 = CONCAT31(local_8._1_3_,0xc);
    FUN_00556090();
    if (0xf < local_2bc) {
      FUN_0089120c();
    }
    if (puVar11 != (uint *)0x0) {
      for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
        if (((char *)puVar11[2] != (char *)0x0) &&
           (iVar10 = __stricmp("Texture",(char *)puVar11[2]), iVar10 == 0)) {
          if (puVar11 == (uint *)0x0) goto LAB_007afe94;
          goto LAB_007afe62;
        }
      }
    }
    goto LAB_007afa94;
  }
LAB_007afabc:
  if (local_3fc != 0) {
    FUN_00719da0();
    puVar11 = local_3cc;
joined_r0x007afae8:
    if (puVar11 != (uint *)0x0) {
      if (puVar11 != (uint *)0x0) {
        for (uVar13 = puVar11[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
          if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
             (iVar10 = __stricmp("Target",*(char **)(uVar13 + 4)), iVar10 == 0)) {
            pcVar21 = *(char **)(uVar13 + 8);
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "";
            }
            goto LAB_007afb26;
          }
        }
      }
      pcVar21 = (char *)0x0;
LAB_007afb26:
      if (puVar11 != (uint *)0x0) {
        for (uVar13 = puVar11[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
          if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
             (iVar10 = __stricmp("Source",*(char **)(uVar13 + 4)), iVar10 == 0)) {
            pcVar8 = *(char **)(uVar13 + 8);
            if (pcVar8 == (char *)0x0) {
              pcVar8 = "";
            }
            goto LAB_007afb57;
          }
        }
      }
      pcVar8 = (char *)0x0;
LAB_007afb57:
      local_2a0 = 0xf;
      local_2a4 = 0;
      local_2b4 = local_2b4 & 0xffffff00;
      do {
        cVar7 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_8._0_1_ = 0xd;
      local_284 = 0xf;
      local_288 = 0;
      local_298[0] = (char *******)((uint)local_298[0] & 0xffffff00);
      do {
        cVar7 = *pcVar21;
        pcVar21 = pcVar21 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_8 = CONCAT31(local_8._1_3_,0xe);
      FUN_007b1740();
      if (puVar11 != (uint *)0x0) {
        for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
          if (((char *)puVar11[2] != (char *)0x0) &&
             (iVar10 = __stricmp("ReplaceInfo",(char *)puVar11[2]), iVar10 == 0)) {
            if (puVar11 == (uint *)0x0) goto LAB_007aff12;
            goto LAB_007afee0;
          }
        }
      }
      goto LAB_007afc14;
    }
  }
  if (local_400 != 0) {
    FUN_00719da0();
    while (local_3c4[0] != (uint *)0x0) {
      FUN_00719f10();
      local_8._0_1_ = 0xf;
      FUN_00719f10();
      local_8 = CONCAT31(local_8._1_3_,0x10);
      FUN_007c54e0();
      if (0xf < local_284) {
        FUN_0089120c();
      }
      local_8 = local_8 & 0xffffff00;
      local_284 = 0xf;
      local_288 = 0;
      local_298[0] = (char *******)((uint)local_298[0] & 0xffffff00);
      if (0xf < local_2d8) {
        FUN_0089120c();
      }
      puVar14 = (undefined4 *)FUN_00719e00();
      local_3c4[0] = (uint *)*puVar14;
    }
  }
  if (local_3ec != 0) {
    FUN_00719da0();
    puVar11 = local_3c4[0];
    while (puVar11 != (uint *)0x0) {
      FUN_0071baa0();
      if (local_3cc == (uint *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = (char *)local_3cc[2];
        if (pcVar21 == (char *)0x0) {
          pcVar21 = "";
        }
      }
      local_230 = 0xf;
      local_234 = 0;
      local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
      do {
        cVar7 = *pcVar21;
        pcVar21 = pcVar21 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_8 = CONCAT31(local_8._1_3_,0x11);
      FUN_0071baa0();
      if ((local_3ec != 0) && (*(char **)(local_3ec + 8) != (char *)0x0)) {
        _strtol(*(char **)(local_3ec + 8),(char **)0x0,10);
      }
      FUN_007d62c0();
      puVar14 = (undefined4 *)FUN_00719e00();
      puVar11 = (uint *)*puVar14;
      local_8 = local_8 & 0xffffff00;
      local_3c4[0] = puVar11;
      if (0xf < local_230) {
        FUN_0089120c();
      }
    }
  }
  local_254 = 0;
  local_250 = (char *)0x0;
  local_24c = 0;
  local_8._0_1_ = 0x12;
  if (local_3f4 != 0) {
    FUN_00719da0();
    puVar11 = local_3c4[0];
    while (puVar11 != (uint *)0x0) {
      lVar23 = 0;
      local_2f0 = 0;
      local_2d8 = 0xf;
      local_2dc = 0;
      local_2ec = local_2ec & 0xffffff00;
      local_8._0_1_ = 0x13;
      FUN_00402a70();
      local_8 = CONCAT31(local_8._1_3_,0x14);
      FUN_0071baa0();
      if (local_3cc != (uint *)0x0) {
        if ((char *)local_3cc[2] == (char *)0x0) {
          lVar23 = 0;
        }
        else {
          lVar23 = _strtol((char *)local_3cc[2],(char **)0x0,10);
        }
      }
      local_2f0 = lVar23;
      FUN_00719f10();
      local_8._0_1_ = 0x15;
      FUN_00402bb0();
      local_8._0_1_ = 0x14;
      if (0xf < local_284) {
        FUN_0089120c();
      }
      FUN_007b1970();
      puVar14 = (undefined4 *)FUN_00719e00();
      puVar11 = (uint *)*puVar14;
      local_8._0_1_ = 0x12;
      local_3c4[0] = puVar11;
      if (0xf < local_2d8) {
        FUN_0089120c();
      }
    }
  }
  FUN_007c5710();
  local_8._0_1_ = 0x16;
  FUN_007c5780();
  local_8._0_1_ = 0x17;
  if (local_3f8 != 0) {
    FUN_00719da0();
    puVar11 = local_3c4[1];
    while (puVar11 != (uint *)0x0) {
      FUN_007ac3b0();
      local_24 = 40.0;
      local_20 = 0;
      local_8._0_1_ = 0x18;
      FUN_0071baa0();
      if (local_3cc == (uint *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = (char *)local_3cc[2];
        if (pcVar21 == (char *)0x0) {
          pcVar21 = "";
        }
      }
      do {
        cVar7 = *pcVar21;
        pcVar21 = pcVar21 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_230 = 0xf;
      local_234 = 0;
      local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
      FUN_00403040();
      local_8._0_1_ = 0x19;
      iVar10 = FUN_00440930();
      uVar13 = iVar10 + 1;
      local_3c4[0] = (uint *)0x0;
      if (local_234 < uVar13) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d();
      }
      uVar17 = local_234 - iVar10;
      if (local_234 - uVar13 < local_234 - iVar10) {
        uVar17 = local_234 - uVar13;
      }
      pppppppcVar9 = local_244[0];
      if (local_230 < 0x10) {
        pppppppcVar9 = (char *******)local_244;
      }
      FID_conflict__memcpy(local_3c4,(void *)(uVar13 + (int)pppppppcVar9),uVar17);
      ppuVar15 = local_3c4;
      local_2bc = 0xf;
      local_2c0 = 0;
      local_2d0 = local_2d0 & 0xffffff00;
      do {
        cVar7 = *(char *)ppuVar15;
        ppuVar15 = (uint **)((int)ppuVar15 + 1);
      } while (cVar7 != '\0');
      FUN_0040b310();
      local_8._0_1_ = 0x1a;
      iVar10 = FUN_006ddac0();
      local_8._0_1_ = 0x19;
      if (0xf < local_2bc) {
        FUN_0089120c();
      }
      if (iVar10 == 0) {
        local_268 = 0xf;
        local_26c = 0;
        local_27c = local_27c & 0xffffff00;
        FUN_00403040();
        local_8._0_1_ = 0x1b;
        FUN_00401ed0();
        FUN_0072ee30();
        local_8 = CONCAT31(local_8._1_3_,0x1c);
        cVar7 = FUN_0072f110();
        if (cVar7 != '\0') {
          local_3e0[1] = (uint *)&stack0xfffffbb0;
          FUN_007b18b0(&stack0xfffffbb0,&local_254);
          FUN_007ade80(local_3d4);
        }
        local_8 = CONCAT31(local_8._1_3_,0x1b);
        local_3a0 = TiXmlDocument::vftable;
        if (0xf < local_340) {
          FUN_0089120c();
        }
        local_340 = 0xf;
        local_344 = 0;
        local_354 = local_354 & 0xffffff00;
        FUN_0072e040();
        uVar13 = local_268;
      }
      else {
        FUN_0071baa0();
        uVar4 = 0;
        if (local_3f8 != 0) {
          if (*(char **)(local_3f8 + 8) == (char *)0x0) {
            uVar4 = 0;
          }
          else {
            lVar23 = _strtol(*(char **)(local_3f8 + 8),(char **)0x0,10);
            uVar4 = (ushort)lVar23;
          }
        }
        local_c8 = uVar4;
        local_a8 = FUN_0071a040();
        fVar24 = (float10)FUN_00719fe0();
        local_24 = (float)fVar24;
        FUN_0071baa0();
        bVar5 = 0xff;
        if (local_3f4 != 0) {
          if (*(char **)(local_3f4 + 8) == (char *)0x0) {
            bVar5 = 0;
          }
          else {
            lVar23 = _strtol(*(char **)(local_3f4 + 8),(char **)0x0,10);
            bVar5 = (byte)lVar23;
          }
        }
        local_a7 = bVar5;
        fVar24 = (float10)FUN_00719fe0();
        local_a4 = (float)fVar24;
        FUN_0071baa0();
        uVar6 = 0;
        if (local_3ec != 0) {
          if (*(char **)(local_3ec + 8) == (char *)0x0) {
            uVar6 = 0;
          }
          else {
            lVar23 = _strtol(*(char **)(local_3ec + 8),(char **)0x0,10);
            uVar6 = (char)lVar23;
          }
        }
        local_9f = uVar6;
        local_a0 = '\0';
        FUN_00719f10();
        local_8._0_1_ = 0x1d;
        cVar7 = '\0';
        pcVar21 = (char *)&DAT_00fbabf8;
        do {
          pppppppcVar9 = local_298[0];
          if (local_284 < 0x10) {
            pppppppcVar9 = (char *******)local_298;
          }
          pcVar8 = pcVar21;
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar8 = *(char **)pcVar21;
          }
          iVar10 = __stricmp(pcVar8,(char *)pppppppcVar9);
          cVar3 = cVar7;
          if (iVar10 == 0) break;
          pcVar21 = pcVar21 + 0x1c;
          cVar7 = cVar7 + '\x01';
          cVar3 = local_a0;
        } while ((int)pcVar21 < 0xfbac84);
        local_a0 = cVar3;
        if (local_a7 == 0xffffffff) {
          if (local_c8 < 0x40) {
            local_a7 = (byte)*(undefined4 *)(&DAT_00d63a60 + (uint)local_c8 * 4);
          }
          else {
            local_a7 = 0;
          }
        }
        FUN_00719da0();
        if (local_3c8 != (uint *)0x0) {
          FUN_0071baa0();
          if (local_400 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            pcVar21 = *(char **)(local_400 + 8);
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "";
            }
          }
          _strncpy(local_228,pcVar21,0x104);
          pcVar21 = local_228;
          do {
            cVar7 = *pcVar21;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          FUN_00402a70();
          FUN_0071baa0();
          if (local_3fc == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            pcVar21 = *(char **)(local_3fc + 8);
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "";
            }
          }
          _strncpy(local_228,pcVar21,0x104);
          pcVar21 = local_228;
          do {
            cVar7 = *pcVar21;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          FUN_00402a70();
          local_9c = 1;
          if ((DAT_00fe1770 & 1) == 0) {
            DAT_00fe1770 = DAT_00fe1770 | 1;
            local_8._0_1_ = 0x1e;
            FUN_007b7da0();
            _atexit((_func_4879 *)&LAB_00bce790);
            local_8._0_1_ = 0x1d;
          }
          FUN_007b8480();
        }
        FUN_00719da0();
        if (local_3e0[0] != (uint *)0x0) {
          FUN_0071baa0();
          if (local_3e0[2] == (uint *)0x0) {
            pcVar21 = (char *)0x0;
          }
          else {
            pcVar21 = (char *)local_3e0[2][2];
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "";
            }
          }
          _strncpy(local_228,pcVar21,0x104);
          pcVar21 = local_228;
          do {
            cVar7 = *pcVar21;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          FUN_00402a70();
          FUN_0071baa0();
          if (local_3e4 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            pcVar21 = *(char **)(local_3e4 + 8);
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "";
            }
          }
          _strncpy(local_228,pcVar21,0x104);
          pcVar21 = local_228;
          do {
            cVar7 = *pcVar21;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          FUN_00402a70();
          local_60 = 1;
        }
        local_3e0[1] = (uint *)FUN_00891268();
        local_8._0_1_ = 0x1f;
        if (local_3e0[1] != (uint *)0x0) {
          FUN_007da950();
        }
        local_8 = CONCAT31(local_8._1_3_,0x1d);
        local_3e0[1] = (uint *)(uint)local_c8;
        iVar10 = *(int *)(local_3d4 + 0xd8);
        piVar16 = (int *)FUN_0082ef00();
        if (*piVar16 != iVar10) {
          MessageBoxA((HWND)0x0,"Collision","Error",0);
        }
        FUN_0057ef20();
        FUN_0082f200();
        uVar13 = local_284;
      }
      if (0xf < uVar13) {
        FUN_0089120c();
      }
      puVar14 = (undefined4 *)FUN_00719e00();
      puVar11 = (uint *)*puVar14;
      local_3c4[1] = puVar11;
      if (0xf < local_230) {
        FUN_0089120c();
      }
      local_230 = 0xf;
      local_234 = 0;
      local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
      local_8._0_1_ = 0x17;
      FUN_007ac410();
    }
  }
  FUN_00719da0();
  if (local_3c8 == (uint *)0x0) {
    FUN_00719da0();
    if (local_3c4[1] != (uint *)0x0) {
      do {
        local_3c8 = (uint *)FUN_00891268();
        if (local_3c8 == (uint *)0x0) {
          local_3c8 = (uint *)0x0;
        }
        else {
          local_3c8[1] = 0;
          *(undefined2 *)local_3c8 = 0;
          local_3c8[10] = 0;
          local_3c8[0xb] = 0;
          local_3c8[0xc] = 0;
          local_3c8[0xe] = 0;
          local_3c8[0xf] = 0;
          local_3c8[0x10] = 0;
          *(undefined2 *)(local_3c8 + 0x12) = 0;
          local_3c8[2] = 0;
          local_3c8[3] = 0;
          local_3c8[4] = 0;
          local_3c8[5] = 0;
          local_3c8[6] = 0;
          local_3c8[7] = 0;
          local_3c8[8] = 0;
          local_3c8[9] = 0;
        }
        puVar11 = local_3c8;
        *(undefined2 *)(local_3c8 + 0x12) = 1;
        uVar13 = 0;
        FUN_0071baa0();
        if (local_3e0[1] != (uint *)0x0) {
          if (*(char **)((int)local_3e0[1] + 8) == (char *)0x0) {
            uVar13 = 0;
          }
          else {
            uVar13 = _strtol(*(char **)((int)local_3e0[1] + 8),(char **)0x0,10);
          }
        }
        puVar11[1] = uVar13;
        *(undefined2 *)puVar11 = 0;
        FUN_0071baa0();
        if (local_3cc == (uint *)0x0) {
          pcVar21 = (char *)0x0;
        }
        else {
          pcVar21 = (char *)local_3cc[2];
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "";
          }
        }
        pcVar8 = pcVar21;
        do {
          cVar7 = *pcVar8;
          pcVar8[(int)((int)puVar11 + (8 - (int)pcVar21))] = cVar7;
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        FUN_00719da0();
        while (local_3c4[0] != (uint *)0x0) {
          local_32c = 0;
          local_38f = 0;
          local_38b = 0;
          local_387 = 0;
          uStack_383 = 0;
          uStack_37f = 0;
          local_37b = 0;
          local_377 = 0;
          local_373 = 0;
          _memset(local_36f,0,0x40);
          FUN_0071baa0();
          uVar6 = 0;
          if (param_1 != (int *)0x0) {
            if ((char *)param_1[2] == (char *)0x0) {
              uVar6 = 0;
            }
            else {
              lVar23 = _strtol((char *)param_1[2],(char **)0x0,10);
              uVar6 = (char)lVar23;
            }
          }
          local_390 = uVar6;
          pcVar21 = (char *)FUN_00719f10();
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar21 = *(char **)pcVar21;
          }
          iVar10 = (int)&local_38f - (int)pcVar21;
          do {
            cVar7 = *pcVar21;
            pcVar21[iVar10] = cVar7;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          if (0xf < local_284) {
            FUN_0089120c();
          }
          pcVar21 = (char *)FUN_00719f10();
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar21 = *(char **)pcVar21;
          }
          iVar10 = -(int)pcVar21;
          do {
            cVar7 = *pcVar21;
            pcVar21[(int)(local_36f + iVar10)] = cVar7;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          if (0xf < local_284) {
            FUN_0089120c();
          }
          FUN_007b16d0();
          puVar14 = (undefined4 *)FUN_00719e00();
          local_3c4[0] = (uint *)*puVar14;
        }
        FUN_0057ef20();
        FUN_0082f200();
        puVar14 = (undefined4 *)FUN_00719e00();
        local_3c4[1] = (uint *)*puVar14;
      } while (local_3c4[1] != (uint *)0x0);
      local_3c4[1] = (uint *)0x0;
    }
  }
  else {
    do {
      FUN_00719da0();
      while (local_3c4[0] != (uint *)0x0) {
        local_3e0[0] = (uint *)FUN_00891268();
        if (local_3e0[0] == (uint *)0x0) {
          local_3e0[0] = (uint *)0x0;
        }
        else {
          local_3e0[0][1] = 0;
          *(undefined2 *)local_3e0[0] = 0;
          local_3e0[0][10] = 0;
          local_3e0[0][0xb] = 0;
          local_3e0[0][0xc] = 0;
          local_3e0[0][0xe] = 0;
          local_3e0[0][0xf] = 0;
          local_3e0[0][0x10] = 0;
          *(undefined2 *)(local_3e0[0] + 0x12) = 0;
          local_3e0[0][2] = 0;
          local_3e0[0][3] = 0;
          local_3e0[0][4] = 0;
          local_3e0[0][5] = 0;
          local_3e0[0][6] = 0;
          local_3e0[0][7] = 0;
          local_3e0[0][8] = 0;
          local_3e0[0][9] = 0;
        }
        puVar11 = local_3e0[0];
        uVar20 = 0;
        FUN_0071baa0();
        if (local_3e0[1] != (uint *)0x0) {
          if (*(char **)((int)local_3e0[1] + 8) == (char *)0x0) {
            uVar20 = 0;
          }
          else {
            lVar23 = _strtol(*(char **)((int)local_3e0[1] + 8),(char **)0x0,10);
            uVar20 = (undefined2)lVar23;
          }
        }
        *(undefined2 *)(puVar11 + 0x12) = uVar20;
        uVar13 = 0;
        FUN_0071baa0();
        if (local_3cc != (uint *)0x0) {
          if ((char *)local_3cc[2] == (char *)0x0) {
            uVar13 = 0;
          }
          else {
            uVar13 = _strtol((char *)local_3cc[2],(char **)0x0,10);
          }
        }
        puVar11[1] = uVar13;
        *(undefined2 *)puVar11 = 0;
        pcVar21 = (char *)FUN_00719f10();
        if (0xf < *(uint *)(pcVar21 + 0x14)) {
          pcVar21 = *(char **)pcVar21;
        }
        pcVar8 = pcVar21;
        do {
          cVar7 = *pcVar8;
          pcVar8[(int)((int)puVar11 + (8 - (int)pcVar21))] = cVar7;
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        if (0xf < local_284) {
          FUN_0089120c();
        }
        FUN_00719da0();
        while (local_3c4[1] != (uint *)0x0) {
          local_32c = 0;
          local_38f = 0;
          local_38b = 0;
          local_387 = 0;
          uStack_383 = 0;
          uStack_37f = 0;
          local_37b = 0;
          local_377 = 0;
          local_373 = 0;
          _memset(local_36f,0,0x40);
          FUN_0071baa0();
          uVar6 = 0;
          if (local_3e8 != 0) {
            if (*(char **)(local_3e8 + 8) == (char *)0x0) {
              uVar6 = 0;
            }
            else {
              lVar23 = _strtol(*(char **)(local_3e8 + 8),(char **)0x0,10);
              uVar6 = (char)lVar23;
            }
          }
          local_390 = uVar6;
          pcVar21 = (char *)FUN_00719f10();
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar21 = *(char **)pcVar21;
          }
          iVar10 = (int)&local_38f - (int)pcVar21;
          do {
            cVar7 = *pcVar21;
            pcVar21[iVar10] = cVar7;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          if (0xf < local_284) {
            FUN_0089120c();
          }
          pcVar21 = (char *)FUN_00719f10();
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar21 = *(char **)pcVar21;
          }
          iVar10 = -(int)pcVar21;
          do {
            cVar7 = *pcVar21;
            pcVar21[(int)(local_36f + iVar10)] = cVar7;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          if (0xf < local_284) {
            FUN_0089120c();
          }
          cVar7 = FUN_0071a040();
          if (cVar7 != '\0') {
            local_32c = 1;
          }
          FUN_007b16d0();
          puVar14 = (undefined4 *)FUN_00719e00();
          local_3c4[1] = (uint *)*puVar14;
        }
        FUN_00719da0();
        while (local_3e4 != 0) {
          *param_1 = *param_1 + 1;
          FUN_007d4560();
          iVar10 = FUN_00891268();
          local_8._0_1_ = 0x20;
          if (iVar10 == 0) {
            local_3e0[2] = (uint *)0x0;
          }
          else {
            local_3e0[2] = (uint *)FUN_007d4d00();
          }
          uVar13 = DAT_00fe1bc0 & 1;
          local_3e0[2][8] = *param_1 + 1000;
          if (uVar13 == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 0x21;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
          }
          local_8._0_1_ = 0x17;
          FUN_007c01e0();
          FUN_004a8680();
          pcVar21 = (char *)FUN_00719f10();
          if (0xf < *(uint *)(pcVar21 + 0x14)) {
            pcVar21 = *(char **)pcVar21;
          }
          __splitpath(pcVar21,(char *)0x0,local_120,local_228,local_238);
          if (0xf < local_284) {
            FUN_0089120c();
          }
          puVar11 = local_3e0[2];
          pcVar21 = local_238;
          do {
            cVar7 = *pcVar21;
            pcVar21 = pcVar21 + 1;
          } while (cVar7 != '\0');
          uVar13 = (int)pcVar21 - (int)local_238;
          pcVar21 = &cStack_229;
          do {
            pcVar8 = pcVar21 + 1;
            pcVar21 = pcVar21 + 1;
          } while (*pcVar8 != '\0');
          pcVar8 = local_238;
          for (uVar17 = uVar13 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
            *(undefined4 *)pcVar21 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar21 = pcVar21 + 4;
          }
          for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *pcVar21 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar21 = pcVar21 + 1;
          }
          FUN_007add40();
          if ((DAT_00fb79e8 & 1) == 0) {
            DAT_00fb79e8 = DAT_00fb79e8 | 1;
            local_8._0_1_ = 0x22;
            FUN_00798de0();
            _atexit((_func_4879 *)&LAB_00bcd2e0);
            local_8._0_1_ = 0x17;
          }
          iVar10 = FUN_0079a5f0();
          if (iVar10 != 0) {
            (**(code **)(*puVar11 + 4))();
          }
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 0x23;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
            local_8._0_1_ = 0x17;
          }
          iVar10 = FUN_007bf8a0();
          if (iVar10 == 0) {
            (**(code **)*puVar11)();
          }
          else {
            FUN_00719f10();
            if ((DAT_00fe1bc0 & 1) == 0) {
              DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
              local_8._0_1_ = 0x25;
              FUN_007bef00();
              _atexit((_func_4879 *)&LAB_00bcec50);
            }
            local_8._0_1_ = 0x24;
            FUN_007bf960();
            local_8._0_1_ = 0x17;
            if (0xf < local_284) {
              FUN_0089120c();
            }
          }
          piVar16 = (int *)FUN_00719e00();
          local_3e4 = *piVar16;
        }
        FUN_0057ef20();
        FUN_0082f200();
        puVar14 = (undefined4 *)FUN_00719e00();
        local_3c4[0] = (uint *)*puVar14;
      }
      puVar14 = (undefined4 *)FUN_00719e00();
      local_3c8 = (uint *)*puVar14;
    } while (local_3c8 != (uint *)0x0);
  }
  if (local_3d0 != (uint *)0x0) {
    FUN_00719da0();
    puVar11 = local_3e0[2];
    while (puVar11 != (uint *)0x0) {
      local_3d0 = puVar11;
      if ((*puVar11 & 7) != 1) {
        local_3d0 = (uint *)0x0;
      }
      FUN_0071baa0();
      if (local_3e0[1] == (uint *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = *(char **)((int)local_3e0[1] + 8);
        if (pcVar21 == (char *)0x0) {
          pcVar21 = "";
        }
      }
      local_268 = 0xf;
      local_26c = 0;
      local_27c = local_27c & 0xffffff00;
      do {
        cVar7 = *pcVar21;
        pcVar21 = pcVar21 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_8._0_1_ = 0x26;
      if ((puVar11 == (uint *)0x0) || (local_3d0 = puVar11, (*puVar11 & 7) != 1)) {
        local_3d0 = (uint *)0x0;
      }
      FUN_0071baa0();
      if (local_3cc == (uint *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = (char *)local_3cc[2];
        if (pcVar21 == (char *)0x0) {
          pcVar21 = "";
        }
      }
      local_230 = 0xf;
      local_234 = 0;
      local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
      do {
        cVar7 = *pcVar21;
        pcVar21 = pcVar21 + 1;
      } while (cVar7 != '\0');
      FUN_00402a70();
      local_8 = CONCAT31(local_8._1_3_,0x27);
      FUN_007c5430();
      puVar14 = (undefined4 *)FUN_00719e00();
      puVar11 = (uint *)*puVar14;
      local_3e0[2] = puVar11;
      if (0xf < local_230) {
        FUN_0089120c();
      }
      local_8._0_1_ = 0x17;
      local_230 = 0xf;
      local_234 = 0;
      local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
      if (0xf < local_268) {
        FUN_0089120c();
      }
    }
  }
  if (0xf < local_314) {
    FUN_0089120c();
  }
  local_314 = 0xf;
  local_318 = 0;
  local_328 = local_328 & 0xffffff00;
  if (0xf < local_3a8) {
    FUN_0089120c();
  }
  local_3a8 = 0xf;
  local_3ac = 0;
  local_3bc = local_3bc & 0xffffff00;
  if (local_254 != 0) {
    FUN_007b2b40();
    FUN_0089120c();
  }
  if (0xf < local_2f8) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_007afdf2:
  do {
    if ((*puVar11 & 7) == 1) goto LAB_007af8d6;
    for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
      if (((char *)puVar11[2] != (char *)0x0) &&
         (iVar10 = __stricmp("Mesh",(char *)puVar11[2]), iVar10 == 0)) goto LAB_007afe26;
    }
LAB_007afe24:
    puVar11 = (uint *)0x0;
LAB_007afe26:
  } while (puVar11 != (uint *)0x0);
LAB_007af8d4:
  puVar11 = (uint *)0x0;
LAB_007af8d6:
  local_3c4[1] = puVar11;
  if (0xf < local_230) {
    FUN_0089120c();
  }
  local_8 = local_8 & 0xffffff00;
  local_230 = 0xf;
  local_234 = 0;
  local_244[0] = (char *******)((uint)local_244[0] & 0xffffff00);
  if (0xf < local_24c) {
    FUN_0089120c();
  }
  if (puVar11 == (uint *)0x0) goto LAB_007af936;
  goto LAB_007af403;
LAB_007afe62:
  do {
    if ((*puVar11 & 7) == 1) goto LAB_007afa96;
    for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
      if (((char *)puVar11[2] != (char *)0x0) &&
         (iVar10 = __stricmp("Texture",(char *)puVar11[2]), iVar10 == 0)) goto LAB_007afe96;
    }
LAB_007afe94:
    puVar11 = (uint *)0x0;
LAB_007afe96:
  } while (puVar11 != (uint *)0x0);
LAB_007afa94:
  puVar11 = (uint *)0x0;
LAB_007afa96:
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_230) {
    FUN_0089120c();
  }
  if (puVar11 == (uint *)0x0) goto LAB_007afabc;
  goto LAB_007af977;
LAB_007afee0:
  do {
    if ((*puVar11 & 7) == 1) goto LAB_007afc16;
    for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
      if (((char *)puVar11[2] != (char *)0x0) &&
         (iVar10 = __stricmp("ReplaceInfo",(char *)puVar11[2]), iVar10 == 0)) goto LAB_007aff14;
    }
LAB_007aff12:
    puVar11 = (uint *)0x0;
LAB_007aff14:
  } while (puVar11 != (uint *)0x0);
LAB_007afc14:
  puVar11 = (uint *)0x0;
LAB_007afc16:
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_284) {
    FUN_0089120c();
  }
  local_284 = 0xf;
  local_288 = 0;
  local_298[0] = (char *******)((uint)local_298[0] & 0xffffff00);
  if (0xf < local_2a0) {
    FUN_0089120c();
  }
  goto joined_r0x007afae8;
}

