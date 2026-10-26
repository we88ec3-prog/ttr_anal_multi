
void FUN_005c5040(int param_1)

{
  void *pvVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 ****ppppuVar7;
  char *pcVar8;
  char ****ppppcVar9;
  int *piVar10;
  undefined1 local_16c [8];
  void *local_164;
  void *local_160;
  int *local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  void *local_144;
  undefined **local_140 [19];
  uint local_f4;
  undefined4 local_e4;
  uint local_e0;
  char ***local_c4 [4];
  undefined4 local_b4;
  uint local_b0;
  char ***local_a8 [4];
  undefined4 local_98;
  uint local_94;
  undefined4 ***local_8c [4];
  undefined4 local_7c;
  uint local_78;
  undefined4 ***local_70 [4];
  undefined4 local_60;
  uint local_5c;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 ***local_34 [3];
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926f24;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_150 = param_1;
  local_18 = uVar3;
  FUN_0072ed80(local_140);
  local_8 = 0;
  FUN_0047f540();
  local_8._0_1_ = 1;
  cVar2 = FUN_0072f110(1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_40) {
    FUN_0089120c(local_54[0],uVar3);
  }
  if (cVar2 == '\0') {
    local_8 = 0xffffffff;
    local_140[0] = TiXmlDocument::vftable;
    if (0xf < local_e0) {
      FUN_0089120c(local_f4,uVar3);
    }
    local_e0 = 0xf;
    local_e4 = 0;
    local_f4 = local_f4 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_004297b0();
    ppppuVar7 = (undefined4 ****)local_34[0];
    if (local_20 < 0x10) {
      ppppuVar7 = local_34;
    }
    iVar4 = FUN_0072e2e0(ppppuVar7);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
    if (iVar4 == 0) {
      local_8 = 0xffffffff;
      local_140[0] = TiXmlDocument::vftable;
      if (0xf < local_e0) {
        FUN_0089120c(local_f4);
      }
      local_e0 = 0xf;
      local_e4 = 0;
      local_f4 = local_f4 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      FUN_004297b0();
      ppppuVar7 = (undefined4 ****)local_70[0];
      if (local_5c < 0x10) {
        ppppuVar7 = local_70;
      }
      local_14c = FUN_0072e2e0(ppppuVar7);
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      local_5c = 0xf;
      local_60 = 0;
      local_70[0] = (undefined4 ***)((uint)local_70[0] & 0xffffff00);
      if (local_14c != 0) {
        do {
          FUN_00764d80(local_54,&DAT_00bed1fc);
          iVar4 = local_150 + 4;
          local_8._0_1_ = 2;
          FUN_005c72f0(&local_154);
          if (local_154 == *(int *)(local_150 + 8)) {
            local_144 = _malloc(0x18);
            local_8._0_1_ = 3;
            if (local_144 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_00763ba0();
            }
            local_8._0_1_ = 2;
            local_38 = local_38 & 0xffff0000;
            local_24 = 7;
            local_28 = 0;
            local_148 = iVar5;
            FUN_004026e0(local_54,0,0xffffffff);
            local_8._0_1_ = 4;
            local_1c = iVar5;
            uVar6 = FUN_0044fc70(&local_38);
            FUN_005c78c0(iVar4,local_16c,uVar6);
            local_8._0_1_ = 2;
            if (7 < local_24) {
              FUN_0089120c(local_38);
            }
          }
          else {
            local_148 = *(int *)(local_154 + 0x28);
          }
          FUN_004297b0();
          ppppuVar7 = (undefined4 ****)local_34[0];
          if (local_20 < 0x10) {
            ppppuVar7 = local_34;
          }
          iVar4 = FUN_0072e2e0(ppppuVar7);
          if (0xf < local_20) {
            FUN_0089120c(local_34[0]);
          }
          local_20 = 0xf;
          local_24 = 0;
          local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
          while (iVar4 != 0) {
            piVar10 = (int *)0x0;
            local_144 = (void *)0x0;
            FUN_00429860(&local_144);
            FUN_00764d80(local_8c,&DAT_00bed1fc);
            local_164 = _malloc(0xa0);
            local_8._0_1_ = 6;
            if (local_164 != (void *)0x0) {
              ppppuVar7 = (undefined4 ****)local_8c[0];
              if (local_78 < 8) {
                ppppuVar7 = local_8c;
              }
              piVar10 = (int *)FUN_00763060(local_164,ppppuVar7);
            }
            pvVar1 = local_144;
            local_8 = CONCAT31(local_8._1_3_,5);
            FUN_0082ef00(&local_144);
            if (local_158 == *(int *)(local_148 + 0xc)) {
              piVar10[3] = (int)pvVar1;
              local_160 = pvVar1;
              local_15c = piVar10;
              uVar6 = FUN_0057ef20();
              FUN_0082f200(local_148 + 8,uVar6);
            }
            else if (piVar10 != (int *)0x0) {
              (**(code **)(*piVar10 + 0x1c))(1);
            }
            local_8._0_1_ = 2;
            if (7 < local_78) {
              FUN_0089120c(local_8c[0]);
            }
            local_8c[0] = (undefined4 ***)((uint)local_8c[0] & 0xffff0000);
            local_78 = 7;
            local_7c = 0;
            FUN_004297b0();
            ppppcVar9 = (char ****)local_c4[0];
            if (local_b0 < 0x10) {
              ppppcVar9 = local_c4;
            }
            for (iVar4 = *(int *)(iVar4 + 0x40); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
              pcVar8 = (char *)(iVar4 + 0x20);
              if (0xf < *(uint *)(iVar4 + 0x34)) {
                pcVar8 = *(char **)pcVar8;
              }
              iVar5 = __stricmp(pcVar8,(char *)ppppcVar9);
              if (iVar5 == 0) goto LAB_005c54b1;
            }
            iVar4 = 0;
LAB_005c54b1:
            if (0xf < local_b0) {
              FUN_0089120c(local_c4[0]);
            }
            local_b0 = 0xf;
            local_b4 = 0;
            local_c4[0] = (char ***)((uint)local_c4[0] & 0xffffff00);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (7 < local_40) {
            FUN_0089120c(local_54[0]);
          }
          local_54[0] = local_54[0] & 0xffff0000;
          local_40 = 7;
          local_44 = 0;
          FUN_004297b0();
          ppppcVar9 = (char ****)local_a8[0];
          if (local_94 < 0x10) {
            ppppcVar9 = local_a8;
          }
          for (iVar4 = *(int *)(local_14c + 0x40); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
            pcVar8 = (char *)(iVar4 + 0x20);
            if (0xf < *(uint *)(iVar4 + 0x34)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar5 = __stricmp(pcVar8,(char *)ppppcVar9);
            if (iVar5 == 0) goto LAB_005c5569;
          }
          iVar4 = 0;
LAB_005c5569:
          if (0xf < local_94) {
            FUN_0089120c(local_a8[0]);
          }
          local_94 = 0xf;
          local_98 = 0;
          local_a8[0] = (char ***)((uint)local_a8[0] & 0xffffff00);
          local_14c = iVar4;
        } while (iVar4 != 0);
        local_14c = 0;
      }
      local_8 = 0xffffffff;
      local_140[0] = TiXmlDocument::vftable;
      if (0xf < local_e0) {
        FUN_0089120c(local_f4);
      }
      local_e0 = 0xf;
      local_e4 = 0;
      local_f4 = local_f4 & 0xffffff00;
      FUN_0072e040();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

