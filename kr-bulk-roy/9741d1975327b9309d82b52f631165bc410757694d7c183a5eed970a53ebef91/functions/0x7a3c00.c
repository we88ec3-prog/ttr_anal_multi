
void FUN_007a3c00(uint *param_1)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  char *****pppppcVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 *****pppppuVar13;
  undefined4 *****pppppuVar14;
  int iVar15;
  double dVar16;
  int local_188;
  int local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  uint *local_168;
  float local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  int local_154;
  int local_150 [2];
  undefined **local_148 [19];
  uint local_fc;
  undefined4 local_ec;
  uint local_e8;
  uint local_d0 [4];
  undefined4 local_c0;
  uint local_bc;
  undefined4 ****local_b4 [4];
  undefined4 local_a4;
  uint local_a0;
  char ****local_98 [4];
  undefined4 local_88;
  uint local_84;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined4 ****local_60 [4];
  undefined4 local_50;
  uint local_4c;
  char ****local_44 [4];
  undefined4 local_34;
  uint local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926682;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_168 = param_1;
  local_18 = uVar5;
  FUN_0072ee30(local_148);
  local_8 = 0;
  cVar4 = FUN_0072f110(0);
  if (cVar4 == '\0') {
    local_8 = 0xffffffff;
    local_148[0] = TiXmlDocument::vftable;
    if (0xf < local_e8) {
      FUN_0089120c(local_fc);
    }
  }
  else {
    FUN_0072e360(uVar5);
    iVar6 = FUN_0072e360();
    iVar9 = iVar6;
    while (local_154 = iVar9, iVar6 != 0) {
      iVar15 = iVar9 + 0x44;
      for (iVar6 = *(int *)(iVar9 + 0x94); iVar6 != iVar15; iVar6 = *(int *)(iVar6 + 0x50)) {
        pcVar11 = (char *)(iVar6 + 0x14);
        if (0xf < *(uint *)(iVar6 + 0x28)) {
          pcVar11 = *(char **)pcVar11;
        }
        iVar7 = __stricmp(pcVar11,"BaseElement");
        if (iVar7 == 0) {
          if (iVar6 != 0) {
            pcVar11 = (char *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              pcVar11 = *(char **)pcVar11;
            }
            goto LAB_007a3d01;
          }
          break;
        }
      }
      pcVar11 = (char *)0x0;
LAB_007a3d01:
      local_a0 = 0xf;
      local_a4 = 0;
      local_b4[0] = (undefined4 ****)((uint)local_b4[0] & 0xffffff00);
      pcVar8 = pcVar11;
      do {
        cVar4 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar4 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar8 - (int)(pcVar11 + 1));
      iVar6 = *(int *)(iVar9 + 0x94);
      local_160 = 0;
      local_15c = 0;
      local_158 = 0;
      for (; iVar6 != iVar15; iVar6 = *(int *)(iVar6 + 0x50)) {
        pcVar11 = (char *)(iVar6 + 0x14);
        if (0xf < *(uint *)(iVar6 + 0x28)) {
          pcVar11 = *(char **)pcVar11;
        }
        iVar7 = __stricmp(pcVar11,"Scale");
        if (iVar7 == 0) {
          if (iVar6 != 0) {
            pcVar11 = (char *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              pcVar11 = *(char **)pcVar11;
            }
            if (pcVar11 != (char *)0x0) {
              dVar16 = _atof(pcVar11);
              local_164 = (float)dVar16;
              goto LAB_007a3d83;
            }
          }
          break;
        }
      }
      local_164 = 1.0;
LAB_007a3d83:
      local_84 = 0xf;
      local_88 = 0;
      local_98[0] = (char ****)((uint)local_98[0] & 0xffffff00);
      local_8 = CONCAT31(local_8._1_3_,2);
      for (iVar9 = *(int *)(iVar9 + 0x94); iVar9 != iVar15; iVar9 = *(int *)(iVar9 + 0x50)) {
        pcVar11 = (char *)(iVar9 + 0x14);
        if (0xf < *(uint *)(iVar9 + 0x28)) {
          pcVar11 = *(char **)pcVar11;
        }
        iVar6 = __stricmp(pcVar11,"Offset");
        if (iVar6 == 0) {
          if (iVar9 != 0) {
            pcVar11 = (char *)(iVar9 + 0x30);
            if (0xf < *(uint *)(iVar9 + 0x44)) {
              pcVar11 = *(char **)pcVar11;
            }
            goto LAB_007a3dcc;
          }
          break;
        }
      }
      pcVar11 = (char *)0x0;
LAB_007a3dcc:
      pcVar8 = pcVar11;
      do {
        cVar4 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar4 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar8 - (int)(pcVar11 + 1));
      pppppcVar10 = (char *****)local_98[0];
      if (local_84 < 0x10) {
        pppppcVar10 = local_98;
      }
      iVar9 = FID_conflict__sscanf((char *)pppppcVar10,"%f %f %f",&local_17c,&local_16c,&local_180);
      if (iVar9 == 3) {
        local_178 = local_17c;
        local_160 = local_17c;
        local_174 = local_16c;
        local_15c = local_16c;
        local_170 = local_180;
        local_158 = local_180;
      }
      iVar6 = FUN_0072e360();
      iVar9 = iVar6;
      while (local_150[1] = iVar9, iVar6 != 0) {
        for (iVar6 = *(int *)(iVar9 + 0x94); iVar6 != iVar9 + 0x44; iVar6 = *(int *)(iVar6 + 0x50))
        {
          pcVar11 = (char *)(iVar6 + 0x14);
          if (0xf < *(uint *)(iVar6 + 0x28)) {
            pcVar11 = *(char **)pcVar11;
          }
          iVar15 = __stricmp(pcVar11,"Name");
          if (iVar15 == 0) {
            if (iVar6 != 0) {
              pcVar11 = (char *)(iVar6 + 0x30);
              if (0xf < *(uint *)(iVar6 + 0x44)) {
                pcVar11 = *(char **)pcVar11;
              }
              goto LAB_007a3f2e;
            }
            break;
          }
        }
        pcVar11 = (char *)0x0;
LAB_007a3f2e:
        local_68 = 0xf;
        local_6c = 0;
        local_7c = local_7c & 0xffffff00;
        pcVar8 = pcVar11;
        do {
          cVar4 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar4 != '\0');
        FUN_00402a70(pcVar11,(int)pcVar8 - (int)(pcVar11 + 1));
        local_8 = CONCAT31(local_8._1_3_,3);
        for (iVar6 = *(int *)(iVar9 + 0x94); iVar6 != iVar9 + 0x44; iVar6 = *(int *)(iVar6 + 0x50))
        {
          pcVar11 = (char *)(iVar6 + 0x14);
          if (0xf < *(uint *)(iVar6 + 0x28)) {
            pcVar11 = *(char **)pcVar11;
          }
          iVar15 = __stricmp(pcVar11,"Image");
          if (iVar15 == 0) {
            if (iVar6 != 0) {
              pcVar11 = (char *)(iVar6 + 0x30);
              if (0xf < *(uint *)(iVar6 + 0x44)) {
                pcVar11 = *(char **)pcVar11;
              }
              goto LAB_007a3f99;
            }
            break;
          }
        }
        pcVar11 = (char *)0x0;
LAB_007a3f99:
        local_4c = 0xf;
        local_50 = 0;
        local_60[0] = (undefined4 ****)((uint)local_60[0] & 0xffffff00);
        pcVar8 = pcVar11;
        do {
          cVar4 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar4 != '\0');
        FUN_00402a70(pcVar11,(int)pcVar8 - (int)(pcVar11 + 1));
        local_8._0_1_ = 4;
        local_150[0] = FUN_00891268(0x80);
        local_8._0_1_ = 5;
        if (local_150[0] == 0) {
          iVar9 = 0;
        }
        else {
          pppppuVar14 = (undefined4 *****)local_b4[0];
          if (local_a0 < 0x10) {
            pppppuVar14 = local_b4;
          }
          pppppuVar13 = (undefined4 *****)local_60[0];
          if (local_4c < 0x10) {
            pppppuVar13 = local_60;
          }
          iVar9 = FUN_007d67f0(local_150[0],pppppuVar13,pppppuVar14);
        }
        local_30 = 0xf;
        local_34 = 0;
        local_44[0] = (char ****)((uint)local_44[0] & 0xffffff00);
        local_8._0_1_ = 6;
        local_bc = 0xf;
        local_c0 = 0;
        local_d0[0] = local_d0[0] & 0xffffff00;
        local_150[0] = iVar9;
        FUN_00402a70("Frame",5);
        local_8._0_1_ = 7;
        iVar6 = FUN_007a4680(local_d0,local_44);
        local_8 = CONCAT31(local_8._1_3_,6);
        if (0xf < local_bc) {
          FUN_0089120c(local_d0[0]);
        }
        if (iVar6 == 0) {
          iVar15 = local_150[1] + 0x44;
          for (iVar6 = *(int *)(local_150[1] + 0x94); iVar6 != iVar15;
              iVar6 = *(int *)(iVar6 + 0x50)) {
            pcVar11 = (char *)(iVar6 + 0x14);
            if (0xf < *(uint *)(iVar6 + 0x28)) {
              pcVar11 = *(char **)pcVar11;
            }
            iVar7 = __stricmp(pcVar11,"Frame");
            if (iVar7 == 0) {
              if (iVar6 != 0) {
                if (*(uint *)(iVar6 + 0x44) < 0x10) {
                  pcVar11 = (char *)(iVar6 + 0x30);
                }
                else {
                  pcVar11 = *(char **)(iVar6 + 0x30);
                }
                goto LAB_007a410f;
              }
              break;
            }
          }
          pcVar11 = (char *)0x0;
LAB_007a410f:
          pcVar8 = pcVar11;
          do {
            cVar4 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar4 != '\0');
          FUN_00402a70(pcVar11,(int)pcVar8 - (int)(pcVar11 + 1));
          pppppcVar10 = (char *****)local_44[0];
          if (local_30 < 0x10) {
            pppppcVar10 = local_44;
          }
          iVar6 = FID_conflict__sscanf
                            ((char *)pppppcVar10,"%d %d %d %d",&local_28,&local_24,&local_188,
                             &local_184);
          if (iVar6 == 4) {
            local_20 = local_28 + local_188;
            local_1c = local_24 + local_184;
            *(int *)(iVar9 + 0x58) = local_28;
            *(int *)(iVar9 + 0x5c) = local_24;
            *(int *)(iVar9 + 0x60) = local_20;
            *(int *)(iVar9 + 100) = local_1c;
            *(undefined4 *)(iVar9 + 0x54) = 1;
          }
        }
        puVar3 = local_168;
        *(undefined4 *)(iVar9 + 0x6c) = local_160;
        *(undefined4 *)(iVar9 + 0x70) = local_15c;
        *(undefined4 *)(iVar9 + 0x74) = local_158;
        *(float *)(iVar9 + 0x78) = local_164;
        piVar1 = (int *)local_168[1];
        if (local_150 < piVar1) {
          piVar2 = (int *)*local_168;
          if (local_150 < piVar2) goto LAB_007a4257;
          if (piVar1 == (int *)local_168[2]) {
            uVar5 = (int)piVar1 - (int)piVar2 >> 2;
            if (0x3ffffffe < uVar5) goto LAB_007a4419;
            uVar5 = uVar5 + 1;
            uVar12 = (int)local_168[2] - (int)piVar2 >> 2;
            if (uVar12 < uVar5) {
              if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar5) {
                uVar12 = uVar5;
              }
              FUN_00797980(uVar12);
            }
          }
          if ((undefined4 *)puVar3[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar3[1] =
                 *(undefined4 *)(*puVar3 + ((int)local_150 - (int)piVar2 >> 2) * 4);
          }
        }
        else {
LAB_007a4257:
          if (piVar1 == (int *)local_168[2]) {
            uVar5 = (int)((int)piVar1 - *local_168) >> 2;
            if (0x3ffffffe < uVar5) {
LAB_007a4419:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar5 = uVar5 + 1;
            uVar12 = (int)((int)local_168[2] - *local_168) >> 2;
            if (uVar12 < uVar5) {
              if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar5) {
                uVar12 = uVar5;
              }
              FUN_00797980(uVar12);
            }
          }
          if ((int *)puVar3[1] != (int *)0x0) {
            *(int *)puVar3[1] = iVar9;
          }
        }
        puVar3[1] = puVar3[1] + 4;
        iVar6 = FUN_0072e3c0();
        local_150[1] = iVar6;
        if (0xf < local_30) {
          FUN_0089120c(local_44[0]);
        }
        local_30 = 0xf;
        local_34 = 0;
        local_44[0] = (char ****)((uint)local_44[0] & 0xffffff00);
        if (0xf < local_4c) {
          FUN_0089120c(local_60[0]);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        local_4c = 0xf;
        local_50 = 0;
        local_60[0] = (undefined4 ****)((uint)local_60[0] & 0xffffff00);
        if (0xf < local_68) {
          FUN_0089120c(local_7c);
        }
        local_68 = 0xf;
        local_6c = 0;
        local_7c = local_7c & 0xffffff00;
        iVar9 = local_150[1];
      }
      iVar6 = FUN_0072e3c0();
      local_154 = iVar6;
      if (0xf < local_84) {
        FUN_0089120c(local_98[0]);
      }
      local_8 = local_8 & 0xffffff00;
      local_84 = 0xf;
      local_88 = 0;
      local_98[0] = (char ****)((uint)local_98[0] & 0xffffff00);
      if (0xf < local_a0) {
        FUN_0089120c(local_b4[0]);
      }
      local_a0 = 0xf;
      local_a4 = 0;
      local_b4[0] = (undefined4 ****)((uint)local_b4[0] & 0xffffff00);
      iVar9 = local_154;
    }
    local_8 = 0xffffffff;
    local_148[0] = TiXmlDocument::vftable;
    if (0xf < local_e8) {
      FUN_0089120c(local_fc);
    }
  }
  local_fc = local_fc & 0xffffff00;
  local_e8 = 0xf;
  local_ec = 0;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

