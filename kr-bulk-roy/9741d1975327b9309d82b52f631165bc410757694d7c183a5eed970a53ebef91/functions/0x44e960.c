
void FUN_0044e960(undefined4 param_1)

{
  undefined2 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  float fVar13;
  double dVar14;
  undefined1 auStack_1dc [4];
  undefined2 *puStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  float fStack_1cc;
  undefined4 local_1c8;
  int iStack_1c4;
  int iStack_1c0;
  undefined2 *puStack_1bc;
  undefined1 auStack_1b8 [8];
  undefined1 auStack_1b0 [8];
  undefined1 auStack_1a8 [8];
  uint uStack_1a0;
  undefined4 uStack_190;
  uint uStack_18c;
  uint auStack_180 [4];
  undefined4 uStack_170;
  uint uStack_16c;
  uint uStack_160;
  undefined4 uStack_150;
  uint uStack_14c;
  uint auStack_144 [4];
  undefined4 uStack_134;
  uint uStack_130;
  uint uStack_124;
  undefined4 uStack_114;
  uint uStack_110;
  uint uStack_108;
  undefined4 uStack_f8;
  uint uStack_f4;
  uint auStack_ec [4];
  undefined4 uStack_dc;
  uint uStack_d8;
  uint auStack_d0 [4];
  undefined4 uStack_c0;
  uint uStack_bc;
  uint auStack_b4 [4];
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925770;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_1dc;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffe18;
  ExceptionList = &local_14;
  local_1c8 = param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar2 = FUN_0072f110(0);
  if ((cVar2 != '\0') && (iVar4 = FUN_0072e2e0("LUCKYBOXDATA"), iVar4 != 0)) {
    piVar5 = (int *)FUN_0072e2e0("USETHEMA");
    (**(code **)(*piVar5 + 0x14))(uVar3);
    uStack_f4 = 0xf;
    uStack_f8 = 0;
    uStack_108 = uStack_108 & 0xffffff00;
    FUN_00402a70(&DAT_00bed1d4,4);
    local_c._0_1_ = 1;
    FUN_0072ecf0(&DAT_00bf2375);
    local_c._0_1_ = 3;
    if (0xf < uStack_f4) {
      FUN_0089120c(uStack_108);
    }
    uStack_f4 = 0xf;
    uStack_f8 = 0;
    uStack_108 = uStack_108 & 0xffffff00;
    uVar6 = FUN_004028b0(auStack_b4);
    local_c._0_1_ = 4;
    FUN_00402800(uVar6);
    local_c = CONCAT31(local_c._1_3_,3);
    if (7 < uStack_16c) {
      FUN_0089120c(auStack_180[0]);
    }
    iStack_1d4 = FUN_0072e360();
    while (iStack_1d4 != 0) {
      iStack_1c4 = FUN_00891268(0x58);
      local_c._0_1_ = 5;
      if (iStack_1c4 == 0) {
        iStack_1d0 = 0;
      }
      else {
        iStack_1d0 = FUN_0044f520(iStack_1c4);
      }
      local_c._0_1_ = 3;
      uStack_18c = 0xf;
      uStack_190 = 0;
      uStack_1a0 = uStack_1a0 & 0xffffff00;
      iStack_1c4 = iStack_1d0;
      FUN_00402a70(&DAT_00bed1d4,4);
      local_c._0_1_ = 6;
      FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 8;
      if (0xf < uStack_18c) {
        FUN_0089120c(uStack_1a0);
      }
      uStack_18c = 0xf;
      uStack_190 = 0;
      uStack_1a0 = uStack_1a0 & 0xffffff00;
      uStack_110 = 0xf;
      uStack_114 = 0;
      uStack_124 = uStack_124 & 0xffffff00;
      FUN_00402a70(&DAT_00bfca9c,4);
      local_c._0_1_ = 9;
      FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 0xb;
      if (0xf < uStack_110) {
        FUN_0089120c(uStack_124);
      }
      uStack_110 = 0xf;
      uStack_114 = 0;
      uStack_124 = uStack_124 & 0xffffff00;
      uVar6 = FUN_004028b0(auStack_ec);
      local_c._0_1_ = 0xc;
      FUN_00402800(uVar6);
      local_c._0_1_ = 0xb;
      if (7 < uStack_16c) {
        FUN_0089120c(auStack_180[0]);
      }
      uVar6 = FUN_004028b0(auStack_d0);
      local_c._0_1_ = 0xd;
      FUN_00402800(uVar6);
      local_c = CONCAT31(local_c._1_3_,0xb);
      if (7 < uStack_16c) {
        FUN_0089120c(auStack_180[0]);
      }
      iVar4 = FUN_0072e360();
      if (iVar4 != 0) {
        iVar4 = FUN_0072e360();
        while (iVar4 != 0) {
          puVar7 = (undefined2 *)FUN_00891268(0x38);
          puStack_1d8 = (undefined2 *)0x0;
          if (puVar7 != (undefined2 *)0x0) {
            *(undefined4 *)(puVar7 + 10) = 7;
            *(undefined4 *)(puVar7 + 8) = 0;
            *puVar7 = 0;
            *(undefined4 *)(puVar7 + 0x18) = 7;
            *(undefined4 *)(puVar7 + 0x16) = 0;
            puVar7[0xe] = 0;
            puStack_1d8 = puVar7;
          }
          uStack_18c = 0xf;
          uStack_190 = 0;
          uStack_1a0 = uStack_1a0 & 0xffffff00;
          FUN_00402a70(&DAT_00bed1d4,4);
          local_c._0_1_ = 0xe;
          FUN_0072ecf0(&DAT_00bf2375);
          local_c._0_1_ = 0x10;
          if (0xf < uStack_18c) {
            FUN_0089120c(uStack_1a0);
          }
          uStack_18c = 0xf;
          uStack_14c = 0xf;
          uStack_190 = 0;
          uStack_1a0 = uStack_1a0 & 0xffffff00;
          uStack_150 = 0;
          uStack_160 = uStack_160 & 0xffffff00;
          FUN_00402a70(&DAT_00bfca9c,4);
          local_c._0_1_ = 0x11;
          FUN_0072ecf0(&DAT_00bf2375);
          local_c._0_1_ = 0x13;
          if (0xf < uStack_14c) {
            FUN_0089120c(uStack_160);
          }
          uStack_14c = 0xf;
          uStack_150 = 0;
          uStack_160 = uStack_160 & 0xffffff00;
          uVar6 = FUN_004028b0(auStack_180);
          local_c._0_1_ = 0x14;
          FUN_00402800(uVar6);
          local_c._0_1_ = 0x13;
          if (7 < uStack_18c) {
            FUN_0089120c(uStack_1a0);
          }
          uVar6 = FUN_004028b0(auStack_144);
          local_c._0_1_ = 0x15;
          FUN_00402800(uVar6);
          local_c._0_1_ = 0x13;
          if (7 < uStack_18c) {
            FUN_0089120c(uStack_1a0);
          }
          uVar6 = FUN_0044fa40(&puStack_1d8);
          iVar4 = iStack_1d0 + 0x48;
          local_c = CONCAT31(local_c._1_3_,0x16);
          uVar6 = FUN_0044fc70(uVar6);
          FUN_0044fb30(iVar4,auStack_1b0,uVar6);
          if (7 < uStack_18c) {
            FUN_0089120c(uStack_1a0);
          }
          if (0xf < uStack_130) {
            FUN_0089120c(auStack_144[0]);
          }
          local_c = CONCAT31(local_c._1_3_,0xb);
          uStack_130 = 0xf;
          uStack_134 = 0;
          auStack_144[0] = auStack_144[0] & 0xffffff00;
          if (0xf < uStack_16c) {
            FUN_0089120c(auStack_180[0]);
          }
          iVar4 = FUN_0072e3c0();
        }
      }
      iVar4 = FUN_0072e360();
      if ((iVar4 != 0) &&
         (puStack_1d8 = (undefined2 *)FUN_0072e360(), puStack_1d8 != (undefined2 *)0x0)) {
        iStack_1c0 = iStack_1d0 + 0x38;
        do {
          puVar8 = (undefined2 *)FUN_00891268(0x34);
          puVar7 = (undefined2 *)0x0;
          if (puVar8 != (undefined2 *)0x0) {
            *(undefined4 *)(puVar8 + 8) = 0;
            *(undefined4 *)(puVar8 + 10) = 7;
            *puVar8 = 0;
            puVar7 = puVar8;
          }
          uStack_14c = 0xf;
          uStack_150 = 0;
          uStack_160 = uStack_160 & 0xffffff00;
          puStack_1bc = puVar7;
          FUN_00402a70(&DAT_00bed1d4,4);
          local_c._0_1_ = 0x17;
          FUN_0072ecf0(&DAT_00bf2375);
          local_c._0_1_ = 0x19;
          if (0xf < uStack_14c) {
            FUN_0089120c(uStack_160);
          }
          uStack_14c = 0xf;
          uStack_150 = 0;
          uStack_160 = uStack_160 & 0xffffff00;
          uVar6 = FUN_004028b0(auStack_180);
          local_c._0_1_ = 0x1a;
          FUN_00402800(uVar6);
          local_c = CONCAT31(local_c._1_3_,0x19);
          if (7 < uStack_130) {
            FUN_0089120c(auStack_144[0]);
          }
          puVar1 = puStack_1d8;
          puVar12 = puStack_1d8 + 0x22;
          for (puVar8 = *(undefined2 **)(puStack_1d8 + 0x4a); puVar8 != puVar12;
              puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"rectx");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                pcVar9 = (char *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  pcVar9 = *(char **)pcVar9;
                }
                if (pcVar9 != (char *)0x0) {
                  dVar14 = _atof(pcVar9);
                  fVar13 = (float)dVar14;
                  fStack_1cc = fVar13;
                  goto LAB_0044f0cb;
                }
              }
              break;
            }
          }
          fVar13 = 0.0;
LAB_0044f0cb:
          puVar8 = *(undefined2 **)(puVar1 + 0x4a);
          *(float *)(puVar7 + 0xe) = fVar13;
          for (; puVar8 != puVar12; puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"recty");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                pcVar9 = (char *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  pcVar9 = *(char **)pcVar9;
                }
                if (pcVar9 != (char *)0x0) {
                  dVar14 = _atof(pcVar9);
                  fVar13 = (float)dVar14;
                  fStack_1cc = fVar13;
                  goto LAB_0044f102;
                }
              }
              break;
            }
          }
          fVar13 = 0.0;
LAB_0044f102:
          puVar8 = *(undefined2 **)(puVar1 + 0x4a);
          *(float *)(puVar7 + 0x10) = fVar13;
          for (; puVar8 != puVar12; puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"left");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                puVar11 = (undefined4 *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  puVar11 = (undefined4 *)*puVar11;
                }
                if (puVar11 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar11);
                  goto LAB_0044f13a;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_0044f13a:
          *(undefined4 *)(puVar7 + 0x12) = uVar6;
          for (puVar8 = *(undefined2 **)(puVar1 + 0x4a); puVar8 != puVar12;
              puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"top");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                puVar11 = (undefined4 *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  puVar11 = (undefined4 *)*puVar11;
                }
                if (puVar11 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar11);
                  goto LAB_0044f16e;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_0044f16e:
          *(undefined4 *)(puVar7 + 0x14) = uVar6;
          for (puVar8 = *(undefined2 **)(puVar1 + 0x4a); puVar8 != puVar12;
              puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"right");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                puVar11 = (undefined4 *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  puVar11 = (undefined4 *)*puVar11;
                }
                if (puVar11 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar11);
                  goto LAB_0044f1aa;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_0044f1aa:
          *(undefined4 *)(puVar7 + 0x16) = uVar6;
          for (puVar8 = *(undefined2 **)(puVar1 + 0x4a); puVar8 != puVar12;
              puVar8 = *(undefined2 **)(puVar8 + 0x28)) {
            pcVar9 = (char *)(puVar8 + 10);
            if (0xf < *(uint *)(puVar8 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar4 = __stricmp(pcVar9,"bottom");
            if (iVar4 == 0) {
              if (puVar8 != (undefined2 *)0x0) {
                puVar11 = (undefined4 *)(puVar8 + 0x18);
                if (0xf < *(uint *)(puVar8 + 0x22)) {
                  puVar11 = (undefined4 *)*puVar11;
                }
                if (puVar11 != (undefined4 *)0x0) {
                  uVar6 = FUN_008917b4(puVar11);
                  goto LAB_0044f1de;
                }
              }
              break;
            }
          }
          uVar6 = 0;
LAB_0044f1de:
          *(undefined4 *)(puVar7 + 0x18) = uVar6;
          uVar6 = FUN_0044fa40(&puStack_1bc);
          iVar4 = iStack_1c0;
          local_c = CONCAT31(local_c._1_3_,0x1b);
          uVar6 = FUN_0044fc70(uVar6);
          FUN_0044fb30(iVar4,auStack_1a8,uVar6);
          if (7 < uStack_130) {
            FUN_0089120c(auStack_144[0]);
          }
          local_c = CONCAT31(local_c._1_3_,0xb);
          if (0xf < uStack_16c) {
            FUN_0089120c(auStack_180[0]);
          }
          puStack_1d8 = (undefined2 *)FUN_0072e3c0();
        } while (puStack_1d8 != (undefined2 *)0x0);
      }
      uVar10 = FUN_0044fa40(&iStack_1c4);
      uVar6 = local_1c8;
      local_c = CONCAT31(local_c._1_3_,0x1c);
      uVar10 = FUN_0044fc70(uVar10);
      FUN_0044fb30(uVar6,auStack_1b8,uVar10);
      if (7 < uStack_16c) {
        FUN_0089120c(auStack_180[0]);
      }
      uStack_16c = 7;
      uStack_170 = 0;
      auStack_180[0] = auStack_180[0] & 0xffff0000;
      if (0xf < uStack_bc) {
        FUN_0089120c(auStack_d0[0]);
      }
      local_c = CONCAT31(local_c._1_3_,3);
      uStack_bc = 0xf;
      uStack_c0 = 0;
      auStack_d0[0] = auStack_d0[0] & 0xffffff00;
      if (0xf < uStack_d8) {
        FUN_0089120c(auStack_ec[0]);
      }
      uStack_d8 = 0xf;
      uStack_dc = 0;
      auStack_ec[0] = auStack_ec[0] & 0xffffff00;
      iStack_1d4 = FUN_0072e3c0();
    }
    if (0xf < uStack_a0) {
      FUN_0089120c(auStack_b4[0]);
    }
    uStack_a0 = 0xf;
    uStack_a4 = 0;
    auStack_b4[0] = auStack_b4[0] & 0xffffff00;
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_1dc);
  return;
}

