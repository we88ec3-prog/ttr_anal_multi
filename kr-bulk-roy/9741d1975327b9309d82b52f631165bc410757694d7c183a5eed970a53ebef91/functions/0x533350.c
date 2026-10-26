
void FUN_00533350(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 auStack_114 [4];
  int local_110;
  int local_10c;
  uint local_100;
  uint uStack_fc;
  undefined4 uStack_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint local_ec;
  undefined4 uStack_e4;
  uint uStack_e0;
  uint local_d8;
  undefined4 local_d4;
  uint local_d0 [4];
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
  puStack_10 = &LAB_00923427;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_114;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffee0;
  ExceptionList = &local_14;
  local_10c = param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar2 = FUN_0072e2e0("TOWNLIST");
    if (iVar2 == 0) {
      local_c = 0xffffffff;
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
      local_110 = FUN_0072e360(uVar1);
      if (local_110 != 0) {
        local_10c = local_10c + 8;
        do {
          local_bc = 7;
          local_c0 = 0;
          local_d0[0] = local_d0[0] & 0xffff0000;
          local_c = CONCAT31(local_c._1_3_,1);
          iVar2 = FUN_007300a0(&DAT_00bfb82c);
          if (iVar2 == 0) {
LAB_0053351c:
            local_d8 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_0053351c;
            local_d8 = FUN_008917b4(puVar3);
          }
          iVar2 = FUN_007300a0(&DAT_00bfb800);
          if (iVar2 == 0) {
LAB_0053354a:
            local_d4 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_0053354a;
            local_d4 = FUN_008917b4(puVar3);
          }
          local_a0 = 0xf;
          local_a4 = 0;
          local_b4 = local_b4 & 0xffffff00;
          FUN_00402a70(&DAT_00c0ce30,4);
          local_c._0_1_ = 2;
          uVar4 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00440130(uVar4);
          if (0xf < local_ec) {
            FUN_0089120c(local_100);
          }
          local_c._0_1_ = 1;
          local_ec = 0xf;
          local_f0 = 0;
          local_100 = local_100 & 0xffffff00;
          if (0xf < local_a0) {
            FUN_0089120c(local_b4);
          }
          local_100 = local_d8;
          uStack_fc = local_d8;
          uStack_f8 = local_d4;
          uStack_e0 = 7;
          uStack_e4 = 0;
          uStack_f4 = uStack_f4 & 0xffff0000;
          FUN_004026e0(local_d0,0,0xffffffff);
          iVar2 = local_10c;
          local_c = CONCAT31(local_c._1_3_,4);
          uVar4 = FUN_00533ea0(&local_100);
          FUN_00533c40(iVar2,uVar4);
          if (7 < uStack_e0) {
            FUN_0089120c(uStack_f4);
          }
          local_c = local_c & 0xffffff00;
          uStack_e0 = 7;
          uStack_e4 = 0;
          uStack_f4 = uStack_f4 & 0xffff0000;
          if (7 < local_bc) {
            FUN_0089120c(local_d0[0]);
          }
          local_d0[0] = local_d0[0] & 0xffff0000;
          local_bc = 7;
          local_c0 = 0;
          local_110 = FUN_0072e3c0();
        } while (local_110 != 0);
      }
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_114);
  return;
}

