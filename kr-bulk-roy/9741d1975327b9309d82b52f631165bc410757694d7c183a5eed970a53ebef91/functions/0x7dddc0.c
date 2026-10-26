
void FUN_007dddc0(void)

{
  float fVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char ******ppppppcVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  float *pfVar11;
  char *pcVar12;
  char ******ppppppcVar13;
  int iVar14;
  double dVar15;
  undefined1 auStack_134 [4];
  int local_130;
  int local_12c;
  float local_128;
  int local_124;
  float local_120;
  float local_11c [2];
  undefined1 local_114 [8];
  uint local_10c [4];
  uint local_fc;
  uint local_f8;
  undefined4 *local_f0;
  char *****local_ec [4];
  undefined4 local_dc;
  uint local_d8;
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
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00926566;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_134;
  ExceptionList = &local_14;
  FUN_007ddc50(DAT_00d61f20 ^ (uint)&stack0xfffffec0);
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = local_b4 & 0xffffff00;
  FUN_00402a70("Map/Object/ObjProps.xml",0x17);
  local_c = 0;
  FUN_0072ee30(local_98);
  local_c._0_1_ = 1;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_c = (uint)local_c._1_3_ << 8;
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
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_c._0_1_ = 2;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_c._0_1_ = 1;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(local_ec,"ObjProps.xml");
      local_c._0_1_ = 3;
      FUN_007edcd0();
      local_c._0_1_ = 1;
      FUN_007ee080();
    }
    local_124 = FUN_0072e360();
    FUN_0072e360();
    iVar4 = FUN_0072e360();
    local_130 = iVar4;
    while (iVar4 != 0) {
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"File");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            goto LAB_007ddfdf;
          }
          break;
        }
      }
      pcVar12 = (char *)0x0;
LAB_007ddfdf:
      local_d8 = 0xf;
      local_dc = 0;
      local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
      pcVar6 = pcVar12;
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
      local_c._0_1_ = 4;
      ppppppcVar13 = (char ******)local_ec[0];
      if (local_d8 < 0x10) {
        ppppppcVar13 = local_ec;
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      ppppppcVar7 = ppppppcVar13;
      do {
        cVar3 = *(char *)ppppppcVar7;
        ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
      } while (cVar3 != '\0');
      FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
      iVar4 = local_12c;
      local_c = CONCAT31(local_c._1_3_,5);
      local_120 = (float)FUN_007b6f30(local_10c);
      fVar1 = *(float *)(iVar4 + 0x30);
      if (local_120 == fVar1) {
LAB_007de0f1:
        local_128 = fVar1;
        pfVar11 = &local_128;
      }
      else {
        uVar2 = *(uint *)((int)local_120 + 0x1c);
        uVar8 = local_fc;
        if (uVar2 <= local_fc) {
          uVar8 = uVar2;
        }
        uVar8 = FUN_00407e70(uVar8);
        if (uVar8 == 0) {
          if (local_fc < uVar2) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = (uint)(local_fc != uVar2);
          }
        }
        if ((int)uVar8 < 0) goto LAB_007de0f1;
        pfVar11 = &local_120;
      }
      fVar1 = *pfVar11;
      local_c._0_1_ = 4;
      if (0xf < local_f8) {
        FUN_0089120c(local_10c[0]);
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      if (fVar1 == *(float *)(local_12c + 0x30)) {
        puVar9 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = 1;
          puVar9[5] = 0x4b7fffff;
          puVar9[1] = 0;
          puVar9[6] = 0x4b7fffff;
          puVar9[2] = 0;
          puVar9[3] = 1;
          puVar9[4] = 0;
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        FUN_00403040(local_ec,0,0xffffffff);
        iVar4 = local_12c + 0x2c;
        local_c._0_1_ = 6;
        local_f0 = puVar9;
        uVar10 = FUN_00552de0(local_10c);
        FUN_007e2910(iVar4,local_11c,uVar10);
        local_c._0_1_ = 4;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
      }
      else {
        puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
      }
      *puVar9 = 0;
      iVar4 = FUN_0072e3c0();
      local_c._0_1_ = 1;
      local_130 = iVar4;
      if (0xf < local_d8) {
        FUN_0089120c(local_ec[0]);
      }
    }
    FUN_0072e360();
    iVar4 = FUN_0072e360();
    local_130 = iVar4;
    while (iVar4 != 0) {
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"File");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            goto LAB_007de27f;
          }
          break;
        }
      }
      pcVar12 = (char *)0x0;
LAB_007de27f:
      local_d8 = 0xf;
      local_dc = 0;
      local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
      pcVar6 = pcVar12;
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
      local_c._0_1_ = 7;
      ppppppcVar13 = (char ******)local_ec[0];
      if (local_d8 < 0x10) {
        ppppppcVar13 = local_ec;
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      ppppppcVar7 = ppppppcVar13;
      do {
        cVar3 = *(char *)ppppppcVar7;
        ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
      } while (cVar3 != '\0');
      FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
      iVar4 = local_12c;
      local_c = CONCAT31(local_c._1_3_,8);
      local_128 = (float)FUN_007b6f30(local_10c);
      fVar1 = *(float *)(iVar4 + 0x30);
      if (local_128 == fVar1) {
LAB_007de391:
        local_11c[0] = fVar1;
        pfVar11 = local_11c;
      }
      else {
        uVar2 = *(uint *)((int)local_128 + 0x1c);
        uVar8 = local_fc;
        if (uVar2 <= local_fc) {
          uVar8 = uVar2;
        }
        uVar8 = FUN_00407e70(uVar8);
        if (uVar8 == 0) {
          if (local_fc < uVar2) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = (uint)(local_fc != uVar2);
          }
        }
        if ((int)uVar8 < 0) goto LAB_007de391;
        pfVar11 = &local_128;
      }
      fVar1 = *pfVar11;
      local_c._0_1_ = 7;
      if (0xf < local_f8) {
        FUN_0089120c(local_10c[0]);
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      if (fVar1 == *(float *)(local_12c + 0x30)) {
        puVar9 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = 1;
          puVar9[5] = 0x4b7fffff;
          puVar9[1] = 0;
          puVar9[6] = 0x4b7fffff;
          puVar9[2] = 0;
          puVar9[3] = 1;
          puVar9[4] = 0;
        }
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        local_f8 = 0xf;
        FUN_00403040(local_ec,0,0xffffffff);
        iVar4 = local_12c + 0x2c;
        local_c._0_1_ = 9;
        local_f0 = puVar9;
        uVar10 = FUN_00552de0(local_10c);
        FUN_007e2910(iVar4,local_114,uVar10);
        local_c._0_1_ = 7;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
      }
      else {
        puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
      }
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"Value");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 != (char *)0x0) {
              dVar15 = _atof(pcVar12);
              local_120 = (float)dVar15;
              goto LAB_007de4bf;
            }
          }
          break;
        }
      }
      local_120 = 0.0;
LAB_007de4bf:
      puVar9[5] = local_120;
      iVar4 = FUN_0072e3c0();
      local_c._0_1_ = 1;
      local_130 = iVar4;
      if (0xf < local_d8) {
        FUN_0089120c(local_ec[0]);
      }
    }
    FUN_0072e360();
    iVar4 = FUN_0072e360();
    local_130 = iVar4;
    while (iVar4 != 0) {
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"File");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            goto LAB_007de561;
          }
          break;
        }
      }
      pcVar12 = (char *)0x0;
LAB_007de561:
      local_d8 = 0xf;
      local_dc = 0;
      local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
      pcVar6 = pcVar12;
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
      local_c._0_1_ = 10;
      ppppppcVar13 = (char ******)local_ec[0];
      if (local_d8 < 0x10) {
        ppppppcVar13 = local_ec;
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      ppppppcVar7 = ppppppcVar13;
      do {
        cVar3 = *(char *)ppppppcVar7;
        ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
      } while (cVar3 != '\0');
      FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
      iVar4 = local_12c;
      local_c = CONCAT31(local_c._1_3_,0xb);
      local_11c[0] = (float)FUN_007b6f30(local_10c);
      fVar1 = *(float *)(iVar4 + 0x30);
      if (local_11c[0] == fVar1) {
LAB_007de6a2:
        local_128 = fVar1;
        pfVar11 = &local_128;
      }
      else {
        uVar2 = *(uint *)((int)local_11c[0] + 0x1c);
        uVar8 = local_fc;
        if (uVar2 <= local_fc) {
          uVar8 = uVar2;
        }
        uVar8 = FUN_00407e70(uVar8);
        if (uVar8 == 0) {
          if (local_fc < uVar2) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = (uint)(local_fc != uVar2);
          }
        }
        if ((int)uVar8 < 0) goto LAB_007de6a2;
        pfVar11 = local_11c;
      }
      fVar1 = *pfVar11;
      local_c._0_1_ = 10;
      if (0xf < local_f8) {
        FUN_0089120c(local_10c[0]);
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      if (fVar1 == *(float *)(local_12c + 0x30)) {
        puVar9 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = 1;
          puVar9[5] = 0x4b7fffff;
          puVar9[1] = 0;
          puVar9[6] = 0x4b7fffff;
          puVar9[2] = 0;
          puVar9[3] = 1;
          puVar9[4] = 0;
        }
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        local_f8 = 0xf;
        FUN_00403040(local_ec,0,0xffffffff);
        iVar4 = local_12c + 0x2c;
        local_c._0_1_ = 0xc;
        local_f0 = puVar9;
        uVar10 = FUN_00552de0(local_10c);
        FUN_007e2910(iVar4,local_114,uVar10);
        local_c._0_1_ = 10;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
      }
      else {
        puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
      }
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"Value");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 != (char *)0x0) {
              dVar15 = _atof(pcVar12);
              local_120 = (float)dVar15;
              goto LAB_007de7d0;
            }
          }
          break;
        }
      }
      local_120 = 0.0;
LAB_007de7d0:
      puVar9[6] = local_120;
      iVar4 = FUN_0072e3c0();
      local_c._0_1_ = 1;
      local_130 = iVar4;
      if (0xf < local_d8) {
        FUN_0089120c(local_ec[0]);
      }
    }
    FUN_0072e360();
    iVar4 = FUN_0072e360();
    local_130 = iVar4;
    while (iVar4 != 0) {
      iVar14 = local_130 + 0x44;
      for (iVar4 = *(int *)(local_130 + 0x94); iVar4 != iVar14; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar12 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar12 = *(char **)pcVar12;
        }
        iVar5 = __stricmp(pcVar12,"File");
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            pcVar12 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            goto LAB_007de879;
          }
          break;
        }
      }
      pcVar12 = (char *)0x0;
LAB_007de879:
      local_d8 = 0xf;
      local_dc = 0;
      local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
      pcVar6 = pcVar12;
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
      local_c._0_1_ = 0xd;
      ppppppcVar13 = (char ******)local_ec[0];
      if (local_d8 < 0x10) {
        ppppppcVar13 = local_ec;
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      ppppppcVar7 = ppppppcVar13;
      do {
        cVar3 = *(char *)ppppppcVar7;
        ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
      } while (cVar3 != '\0');
      FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
      iVar4 = local_12c;
      local_c = CONCAT31(local_c._1_3_,0xe);
      local_11c[0] = (float)FUN_007b6f30(local_10c);
      fVar1 = *(float *)(iVar4 + 0x30);
      if (local_11c[0] == fVar1) {
LAB_007de9b6:
        local_128 = fVar1;
        pfVar11 = &local_128;
      }
      else {
        uVar2 = *(uint *)((int)local_11c[0] + 0x1c);
        uVar8 = local_fc;
        if (uVar2 <= local_fc) {
          uVar8 = uVar2;
        }
        uVar8 = FUN_00407e70(uVar8);
        if (uVar8 == 0) {
          if (local_fc < uVar2) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = (uint)(local_fc != uVar2);
          }
        }
        if ((int)uVar8 < 0) goto LAB_007de9b6;
        pfVar11 = local_11c;
      }
      fVar1 = *pfVar11;
      local_c._0_1_ = 0xd;
      if (0xf < local_f8) {
        FUN_0089120c(local_10c[0]);
      }
      local_f8 = 0xf;
      local_fc = 0;
      local_10c[0] = local_10c[0] & 0xffffff00;
      if (fVar1 == *(float *)(local_12c + 0x30)) {
        puVar9 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = 1;
          puVar9[5] = 0x4b7fffff;
          puVar9[1] = 0;
          puVar9[6] = 0x4b7fffff;
          puVar9[2] = 0;
          puVar9[3] = 1;
          puVar9[4] = 0;
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        FUN_00403040(local_ec,0,0xffffffff);
        iVar4 = local_12c + 0x2c;
        local_c._0_1_ = 0xf;
        local_f0 = puVar9;
        uVar10 = FUN_00552de0(local_10c);
        FUN_007e2910(iVar4,local_114,uVar10);
        local_c._0_1_ = 0xd;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
      }
      else {
        puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
      }
      puVar9[1] = 1;
      iVar4 = FUN_0072e3c0();
      local_c._0_1_ = 1;
      local_130 = iVar4;
      if (0xf < local_d8) {
        FUN_0089120c(local_ec[0]);
      }
    }
    iVar4 = FUN_0072e360();
    if ((iVar4 != 0) && (local_130 = FUN_0072e360(), iVar4 = local_12c, local_130 != 0)) {
      iVar14 = local_12c + 0x2c;
      do {
        iVar5 = FUN_007300a0(&DAT_00c0d66c);
        if (iVar5 == 0) {
          pcVar12 = (char *)0x0;
        }
        else {
          pcVar12 = (char *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            pcVar12 = *(char **)pcVar12;
          }
        }
        local_d8 = 0xf;
        local_dc = 0;
        local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
        pcVar6 = pcVar12;
        do {
          cVar3 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
        local_c._0_1_ = 0x10;
        ppppppcVar13 = (char ******)local_ec[0];
        if (local_d8 < 0x10) {
          ppppppcVar13 = local_ec;
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        ppppppcVar7 = ppppppcVar13;
        do {
          cVar3 = *(char *)ppppppcVar7;
          ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
        } while (cVar3 != '\0');
        FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
        local_c = CONCAT31(local_c._1_3_,0x11);
        local_11c[0] = (float)FUN_007b6f30(local_10c);
        if ((local_11c[0] == *(float *)(iVar4 + 0x30)) || (cVar3 = FUN_0049ae30(), cVar3 != '\0')) {
          local_128 = *(float *)(iVar4 + 0x30);
          pfVar11 = &local_128;
        }
        else {
          pfVar11 = local_11c;
        }
        fVar1 = *pfVar11;
        local_c._0_1_ = 0x10;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        if (fVar1 == *(float *)(local_12c + 0x30)) {
          puVar9 = (undefined4 *)FUN_00891268(0x1c);
          if (puVar9 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            *puVar9 = 1;
            puVar9[5] = 0x4b7fffff;
            puVar9[1] = 0;
            puVar9[6] = 0x4b7fffff;
            puVar9[2] = 0;
            puVar9[3] = 1;
            puVar9[4] = 0;
          }
          local_f8 = 0xf;
          local_fc = 0;
          local_10c[0] = local_10c[0] & 0xffffff00;
          FUN_00403040(local_ec,0,0xffffffff);
          local_c._0_1_ = 0x12;
          local_f0 = puVar9;
          uVar10 = FUN_00552de0(local_10c);
          FUN_007e2910(iVar14,local_114,uVar10);
          local_c._0_1_ = 0x10;
          if (0xf < local_f8) {
            FUN_0089120c(local_10c[0]);
          }
        }
        else {
          puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
        }
        puVar9[2] = 1;
        local_130 = FUN_0072e3c0();
        local_c._0_1_ = 1;
        if (0xf < local_d8) {
          FUN_0089120c(local_ec[0]);
        }
      } while (local_130 != 0);
    }
    iVar4 = FUN_0072e360();
    if ((iVar4 != 0) && (local_130 = FUN_0072e360(), iVar4 = local_12c, local_130 != 0)) {
      iVar14 = local_12c + 0x2c;
      do {
        iVar5 = FUN_007300a0(&DAT_00c0d66c);
        if (iVar5 == 0) {
          pcVar12 = (char *)0x0;
        }
        else {
          pcVar12 = (char *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            pcVar12 = *(char **)pcVar12;
          }
        }
        local_d8 = 0xf;
        local_dc = 0;
        local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
        pcVar6 = pcVar12;
        do {
          cVar3 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
        local_c._0_1_ = 0x13;
        ppppppcVar13 = (char ******)local_ec[0];
        if (local_d8 < 0x10) {
          ppppppcVar13 = local_ec;
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        ppppppcVar7 = ppppppcVar13;
        do {
          cVar3 = *(char *)ppppppcVar7;
          ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
        } while (cVar3 != '\0');
        FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
        local_c = CONCAT31(local_c._1_3_,0x14);
        local_11c[0] = (float)FUN_007b6f30(local_10c);
        if ((local_11c[0] == *(float *)(iVar4 + 0x30)) || (cVar3 = FUN_0049ae30(), cVar3 != '\0')) {
          local_128 = *(float *)(iVar4 + 0x30);
          pfVar11 = &local_128;
        }
        else {
          pfVar11 = local_11c;
        }
        fVar1 = *pfVar11;
        local_c._0_1_ = 0x13;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        if (fVar1 == *(float *)(local_12c + 0x30)) {
          puVar9 = (undefined4 *)FUN_00891268(0x1c);
          if (puVar9 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            *puVar9 = 1;
            puVar9[5] = 0x4b7fffff;
            puVar9[1] = 0;
            puVar9[6] = 0x4b7fffff;
            puVar9[2] = 0;
            puVar9[3] = 1;
            puVar9[4] = 0;
          }
          local_f8 = 0xf;
          local_fc = 0;
          local_10c[0] = local_10c[0] & 0xffffff00;
          FUN_00403040(local_ec,0,0xffffffff);
          local_c._0_1_ = 0x15;
          local_f0 = puVar9;
          uVar10 = FUN_00552de0(local_10c);
          FUN_007e2910(iVar14,local_114,uVar10);
          local_c._0_1_ = 0x13;
          if (0xf < local_f8) {
            FUN_0089120c(local_10c[0]);
          }
        }
        else {
          puVar9 = *(undefined4 **)((int)fVar1 + 0x28);
        }
        puVar9[3] = 0;
        local_130 = FUN_0072e3c0();
        local_c._0_1_ = 1;
        if (0xf < local_d8) {
          FUN_0089120c(local_ec[0]);
        }
      } while (local_130 != 0);
    }
    iVar4 = FUN_0072e360();
    if ((iVar4 != 0) && (local_130 = FUN_0072e360(), local_130 != 0)) {
      local_124 = local_12c + 0x2c;
      do {
        iVar4 = FUN_007300a0(&DAT_00c0d66c);
        if (iVar4 == 0) {
          pcVar12 = (char *)0x0;
        }
        else {
          pcVar12 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar12 = *(char **)pcVar12;
          }
        }
        local_d8 = 0xf;
        local_dc = 0;
        local_ec[0] = (char *****)((uint)local_ec[0] & 0xffffff00);
        pcVar6 = pcVar12;
        do {
          cVar3 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
        local_c._0_1_ = 0x16;
        ppppppcVar13 = (char ******)local_ec[0];
        if (local_d8 < 0x10) {
          ppppppcVar13 = local_ec;
        }
        local_f8 = 0xf;
        local_fc = 0;
        local_10c[0] = local_10c[0] & 0xffffff00;
        ppppppcVar7 = ppppppcVar13;
        do {
          cVar3 = *(char *)ppppppcVar7;
          ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
        } while (cVar3 != '\0');
        FUN_00402a70(ppppppcVar13,(int)ppppppcVar7 - (int)((int)ppppppcVar13 + 1));
        local_c._0_1_ = 0x17;
        FUN_007df190(local_11c);
        local_c._0_1_ = 0x16;
        if (0xf < local_f8) {
          FUN_0089120c(local_10c[0]);
        }
        if (local_11c[0] == *(float *)(local_12c + 0x30)) {
          puVar9 = (undefined4 *)FUN_00891268(0x1c);
          if (puVar9 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            *puVar9 = 1;
            puVar9[5] = 0x4b7fffff;
            puVar9[1] = 0;
            puVar9[6] = 0x4b7fffff;
            puVar9[2] = 0;
            puVar9[3] = 1;
            puVar9[4] = 0;
          }
          local_f8 = 0xf;
          local_fc = 0;
          local_10c[0] = local_10c[0] & 0xffffff00;
          FUN_00403040(local_ec,0,0xffffffff);
          local_c._0_1_ = 0x18;
          local_f0 = puVar9;
          uVar10 = FUN_00552de0(local_10c);
          FUN_007e2910(local_124,local_114,uVar10);
          local_c._0_1_ = 0x16;
          if (0xf < local_f8) {
            FUN_0089120c(local_10c[0]);
          }
        }
        else {
          puVar9 = *(undefined4 **)((int)local_11c[0] + 0x28);
        }
        puVar9[4] = 1;
        local_130 = FUN_0072e3c0();
        local_c._0_1_ = 1;
        if (0xf < local_d8) {
          FUN_0089120c(local_ec[0]);
        }
      } while (local_130 != 0);
    }
    local_c = (uint)local_c._1_3_ << 8;
    FUN_00407fb0();
  }
  if (0xf < local_a0) {
    FUN_0089120c(local_b4);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_134);
  return;
}

