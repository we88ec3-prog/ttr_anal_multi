
void FUN_0082bb00(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  double dVar12;
  float local_160;
  float local_15c;
  undefined **local_158 [19];
  uint local_10c;
  undefined4 local_fc;
  uint local_f8;
  undefined2 local_e0;
  undefined1 local_dc;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c0;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 local_a4;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_88;
  undefined4 local_78;
  undefined4 local_74;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
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
  puStack_c = &LAB_00925b86;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_158);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_158[0] = TiXmlDocument::vftable;
    if (0xf < local_f8) {
      FUN_0089120c(local_10c,uVar2);
    }
    local_f8 = 0xf;
    local_fc = 0;
    local_10c = local_10c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e360();
    iVar3 = FUN_0072e360();
    while (iVar3 != 0) {
      FUN_0072e360();
      iVar4 = FUN_0072e360();
      iVar5 = FUN_0072e360();
      iVar6 = FUN_0072e360();
      local_6c = 0.0;
      local_68 = 0.0;
      local_64 = 0.0;
      local_e0 = 0;
      local_60 = 30.0;
      local_c8 = 0xf;
      local_cc = 0;
      local_dc = 0;
      local_58 = 0.0;
      local_ac = 0xf;
      local_54 = 0.0;
      local_b0 = 0;
      local_c0 = 0;
      local_90 = 0xf;
      local_94 = 0;
      local_a4 = 0;
      local_74 = 0xf;
      local_78 = 0;
      local_88 = 0;
      local_5c = 2;
      local_8._0_1_ = 1;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00c53814,4);
      local_8._0_1_ = 2;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402bb0(uVar7);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      for (iVar9 = *(int *)(iVar3 + 0x94); iVar9 != iVar3 + 0x44; iVar9 = *(int *)(iVar9 + 0x50)) {
        pcVar10 = (char *)(iVar9 + 0x14);
        if (0xf < *(uint *)(iVar9 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar8 = __stricmp(pcVar10,"Type");
        if (iVar8 == 0) {
          if (iVar9 != 0) {
            puVar11 = (undefined4 *)(iVar9 + 0x30);
            if (0xf < *(uint *)(iVar9 + 0x44)) {
              puVar11 = (undefined4 *)*puVar11;
            }
            if (puVar11 != (undefined4 *)0x0) {
              local_e0 = FUN_008917b4(puVar11);
              goto LAB_0082bd2a;
            }
          }
          break;
        }
      }
      local_e0 = 0;
LAB_0082bd2a:
      for (iVar9 = *(int *)(iVar3 + 0x94); iVar9 != iVar3 + 0x44; iVar9 = *(int *)(iVar9 + 0x50)) {
        pcVar10 = (char *)(iVar9 + 0x14);
        if (0xf < *(uint *)(iVar9 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar8 = __stricmp(pcVar10,"Speed");
        if (iVar8 == 0) {
          if (iVar9 != 0) {
            pcVar10 = (char *)(iVar9 + 0x30);
            if (0xf < *(uint *)(iVar9 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 != (char *)0x0) {
              dVar12 = _atof(pcVar10);
              local_15c = (float)dVar12;
              goto LAB_0082bd68;
            }
          }
          break;
        }
      }
      local_15c = 0.0;
LAB_0082bd68:
      local_6c = local_15c;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("EffectFile",10);
      local_8._0_1_ = 4;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00402bb0(uVar7);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_8._0_1_ = 1;
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("GroundTargetingEffect",0x15);
      local_8._0_1_ = 6;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_00402bb0(uVar7);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_8._0_1_ = 1;
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("ImpactEffect",0xc);
      local_8._0_1_ = 8;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_00402bb0(uVar7);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      iVar3 = *(int *)(iVar4 + 0x94);
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      for (; iVar3 != iVar4 + 0x44; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar10 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar9 = __stricmp(pcVar10,"Lifetime");
        if (iVar9 == 0) {
          if (iVar3 != 0) {
            pcVar10 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 != (char *)0x0) {
              dVar12 = _atof(pcVar10);
              local_15c = (float)dVar12;
              goto LAB_0082bf26;
            }
          }
          break;
        }
      }
      local_15c = 0.0;
LAB_0082bf26:
      local_64 = local_15c;
      for (iVar3 = *(int *)(iVar4 + 0x94); iVar3 != iVar4 + 0x44; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar10 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar9 = __stricmp(pcVar10,"TraceTime");
        if (iVar9 == 0) {
          if (iVar3 != 0) {
            pcVar10 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 != (char *)0x0) {
              dVar12 = _atof(pcVar10);
              local_15c = (float)dVar12;
              goto LAB_0082bf66;
            }
          }
          break;
        }
      }
      local_15c = 0.0;
LAB_0082bf66:
      local_68 = local_15c;
      for (iVar3 = *(int *)(iVar5 + 0x94); iVar3 != iVar5 + 0x44; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar10 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar4 = __stricmp(pcVar10,"Radius");
        if (iVar4 == 0) {
          if (iVar3 != 0) {
            pcVar10 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 != (char *)0x0) {
              dVar12 = _atof(pcVar10);
              local_15c = (float)dVar12;
              goto LAB_0082bfaf;
            }
          }
          break;
        }
      }
      local_15c = 0.0;
LAB_0082bfaf:
      local_58 = local_15c;
      for (iVar3 = *(int *)(iVar5 + 0x94); iVar3 != iVar5 + 0x44; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar10 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar4 = __stricmp(pcVar10,"SplashRadius");
        if (iVar4 == 0) {
          if (iVar3 != 0) {
            pcVar10 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 != (char *)0x0) {
              dVar12 = _atof(pcVar10);
              local_15c = (float)dVar12;
              goto LAB_0082bfef;
            }
          }
          break;
        }
      }
      local_15c = 0.0;
LAB_0082bfef:
      local_54 = local_15c;
      if (iVar6 != 0) {
        iVar3 = FUN_007300a0("Altitude");
        if (iVar3 == 0) {
LAB_0082c15a:
          local_160 = 10.0;
        }
        else {
          pcVar10 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar10 = *(char **)pcVar10;
          }
          if (pcVar10 == (char *)0x0) goto LAB_0082c15a;
          dVar12 = _atof(pcVar10);
          local_160 = (float)dVar12;
        }
        local_60 = local_160;
        iVar3 = FUN_007300a0(&DAT_00c53878);
        if (iVar3 != 0) {
          puVar11 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar11 = (undefined4 *)*puVar11;
          }
          if (puVar11 != (undefined4 *)0x0) {
            local_5c = FUN_008917b4(puVar11);
            goto LAB_0082c19f;
          }
        }
        local_5c = 1;
      }
LAB_0082c19f:
      FUN_0082c340();
      FUN_0082c2b0();
      iVar3 = FUN_0072e3c0();
      local_8 = local_8 & 0xffffff00;
      FUN_004ccf90();
    }
    local_8 = 0xffffffff;
    local_158[0] = TiXmlDocument::vftable;
    if (0xf < local_f8) {
      FUN_0089120c(local_10c);
    }
    local_f8 = 0xf;
    local_fc = 0;
    local_10c = local_10c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

