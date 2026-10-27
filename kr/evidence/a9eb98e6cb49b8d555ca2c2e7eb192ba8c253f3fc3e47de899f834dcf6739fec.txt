
void FUN_00536280(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *******pppppppcVar5;
  uint uVar6;
  undefined1 local_120 [8];
  uint local_118;
  undefined4 local_114;
  int *local_110;
  undefined **local_10c [17];
  char local_c8;
  uint local_c0;
  undefined4 local_b0;
  uint local_ac;
  uint local_90 [4];
  undefined4 local_80;
  uint local_7c;
  uint local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  char ******local_4c [4];
  int local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092331e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0072ee30(local_10c);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_c8 == '\0') && (iVar2 = FUN_0072e2e0("TRIGGERMSG"), iVar2 != 0)) {
    local_110 = (int *)FUN_0072e2e0("TRIGGER");
    if (local_110 != (int *)0x0) {
      do {
        (**(code **)(*local_110 + 0x14))();
        iVar2 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar2 == 0) {
LAB_005363d7:
          local_114 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_005363d7;
          local_114 = FUN_008917b4(puVar3);
        }
        local_7c = 7;
        local_80 = 0;
        local_90[0] = local_90[0] & 0xffff0000;
        local_8._0_1_ = 1;
        local_30 = local_30 & 0xffffff00;
        local_1c = 0xf;
        local_20 = 0;
        FUN_00402a70(&DAT_00c0f260,4);
        local_8._0_1_ = 2;
        uVar4 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00440130(uVar4);
        if (0xf < local_54) {
          FUN_0089120c(local_68);
        }
        local_8._0_1_ = 1;
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        FUN_00402a70("COLOR",5);
        local_8._0_1_ = 4;
        FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,6);
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        if (local_3c == 7) {
          pppppppcVar5 = (char *******)local_4c[0];
          if (local_38 < 0x10) {
            pppppppcVar5 = local_4c;
          }
          if (*(char *)pppppppcVar5 != '#') goto LAB_00536574;
          uVar1 = FUN_0049b1b0();
          local_118 = FUN_0049b1b0();
          uVar6 = FUN_0049b1b0();
          local_74 = ((uVar1 | 0xffffff00) << 8 | local_118 & 0xff) << 8 | uVar6 & 0xff;
        }
        else {
LAB_00536574:
          local_74 = 0xffffffff;
        }
        local_70 = local_114;
        local_58 = 7;
        local_5c = 0;
        local_6c = local_6c & 0xffff0000;
        FUN_004026e0(local_90,0,0xffffffff);
        local_50 = local_74;
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00536f00();
        FUN_00536bc0(local_120);
        if (7 < local_58) {
          FUN_0089120c(local_6c);
        }
        local_58 = 7;
        local_5c = 0;
        local_6c = local_6c & 0xffff0000;
        if (0xf < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = (char ******)((uint)local_4c[0] & 0xffffff00);
        if (7 < local_7c) {
          FUN_0089120c(local_90[0]);
        }
        local_7c = 7;
        local_80 = 0;
        local_90[0] = local_90[0] & 0xffff0000;
        local_110 = (int *)FUN_0072e320("TRIGGER");
      } while (local_110 != (int *)0x0);
      local_110 = (int *)0x0;
    }
    local_8 = 0xffffffff;
    local_10c[0] = TiXmlDocument::vftable;
    if (0xf < local_ac) {
      FUN_0089120c(local_c0);
    }
    local_ac = 0xf;
    local_b0 = 0;
    local_c0 = local_c0 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_10c[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_ac) {
      local_8 = 0xffffffff;
      local_10c[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_c0,uVar1);
    }
    local_ac = 0xf;
    local_b0 = 0;
    local_c0 = local_c0 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

