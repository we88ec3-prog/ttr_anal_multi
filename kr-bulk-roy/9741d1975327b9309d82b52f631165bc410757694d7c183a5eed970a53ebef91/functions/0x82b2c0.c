
void FUN_0082b2c0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_158 [4];
  undefined4 local_148;
  uint local_144;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  int local_128;
  uint local_124;
  undefined4 local_114;
  uint local_110;
  undefined **local_108 [19];
  uint local_bc;
  undefined4 local_ac;
  uint local_a8;
  uint local_90 [4];
  undefined4 local_80;
  uint local_7c;
  undefined1 local_74;
  undefined4 local_70;
  uint local_6c;
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
  puStack_c = &LAB_00925bfc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_134 = param_1;
  local_18 = uVar2;
  FUN_0072ee30(local_108);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 == '\0') || (iVar3 = FUN_0072e2e0("TEAM_RANK"), iVar3 == 0)) {
    local_108[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_a8) {
      local_8 = 0xffffffff;
      local_108[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_bc);
    }
    local_a8 = 0xf;
    local_ac = 0;
    local_bc = local_bc & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_128 = FUN_0072e360(uVar2);
    while (local_128 != 0) {
      iVar3 = FUN_007300a0(&DAT_00c0ea40);
      if (iVar3 == 0) {
LAB_0082b417:
        local_130 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0082b417;
        local_130 = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_007300a0("min_point");
      if (iVar3 == 0) {
LAB_0082b44b:
        local_12c = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0082b44b;
        local_12c = FUN_008917b4(puVar4);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00bed1d4,4);
      local_8._0_1_ = 1;
      uVar5 = FUN_0072ecf0(&DAT_00bf2375);
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      local_8._0_1_ = 3;
      FUN_00403040(uVar5,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_00402a50();
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_110) {
        FUN_0089120c(local_124);
      }
      local_110 = 0xf;
      local_114 = 0;
      local_124 = local_124 & 0xffffff00;
      local_8._0_1_ = 8;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_158[0] = local_158[0] & 0xffff0000;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      local_144 = 7;
      local_148 = 0;
      FUN_004026e0(local_90,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,9);
      local_74 = (undefined1)local_130;
      local_70 = local_12c;
      local_58 = 7;
      local_5c = 0;
      local_6c = local_6c & 0xffff0000;
      FUN_004026e0(local_158,0,0xffffffff);
      if (7 < local_144) {
        FUN_0089120c(local_158[0]);
      }
      local_144 = 7;
      local_148 = 0;
      local_158[0] = local_158[0] & 0xffff0000;
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0082b780();
      if (7 < local_58) {
        FUN_0089120c(local_6c);
      }
      local_8 = local_8 & 0xffffff00;
      local_58 = 7;
      local_5c = 0;
      local_6c = local_6c & 0xffff0000;
      if (7 < local_7c) {
        FUN_0089120c(local_90[0]);
      }
      local_90[0] = local_90[0] & 0xffff0000;
      local_7c = 7;
      local_80 = 0;
      local_128 = FUN_0072e3c0();
    }
    local_8 = 0xffffffff;
    local_108[0] = TiXmlDocument::vftable;
    if (0xf < local_a8) {
      FUN_0089120c(local_bc);
    }
    local_a8 = 0xf;
    local_ac = 0;
    local_bc = local_bc & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

