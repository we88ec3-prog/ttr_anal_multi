
void FUN_00528900(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  int local_e4;
  int local_e0;
  uint local_d4;
  uint local_d0;
  undefined4 local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b4 [4];
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
  puStack_10 = &LAB_009238fc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_e4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff10;
  ExceptionList = &local_14;
  local_e0 = param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar3 = FUN_0072e2e0("STATUS_LIST");
    if (iVar3 == 0) {
      FUN_006edb60("Can\'t load file: %s","Table/StatusList.xml");
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
      local_e4 = FUN_0072e360(uVar2);
      if (local_e4 != 0) {
        local_e0 = local_e0 + 8;
        do {
          local_a0 = 7;
          local_a4 = 0;
          local_b4[0] = local_b4[0] & 0xffff0000;
          local_c._0_1_ = 1;
          iVar3 = FUN_007300a0(&DAT_00c0ce30);
          if (iVar3 == 0) {
            pcVar7 = (char *)0x0;
          }
          else {
            pcVar7 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
          }
          local_c0 = 0xf;
          local_c4 = 0;
          local_d4 = local_d4 & 0xffffff00;
          pcVar4 = pcVar7;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar7,(int)pcVar4 - (int)(pcVar7 + 1));
          local_c._0_1_ = 2;
          FUN_00440130(&local_d4);
          local_c = CONCAT31(local_c._1_3_,1);
          if (0xf < local_c0) {
            FUN_0089120c(local_d4);
          }
          iVar3 = FUN_007300a0(&DAT_00bfb82c);
          if (iVar3 == 0) {
LAB_00528b55:
            local_d4 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_00528b55;
            local_d4 = FUN_008917b4(puVar5);
          }
          local_bc = 7;
          local_c0 = 0;
          local_d0 = local_d0 & 0xffff0000;
          FUN_004026e0(local_b4,0,0xffffffff);
          iVar3 = local_e0;
          local_c = CONCAT31(local_c._1_3_,3);
          uVar6 = FUN_005063f0(&local_d4);
          FUN_00506030(iVar3,uVar6);
          if (7 < local_bc) {
            FUN_0089120c(local_d0);
          }
          local_c = local_c & 0xffffff00;
          local_bc = 7;
          local_c0 = 0;
          local_d0 = local_d0 & 0xffff0000;
          if (7 < local_a0) {
            FUN_0089120c(local_b4[0]);
          }
          local_a0 = 7;
          local_a4 = 0;
          local_b4[0] = local_b4[0] & 0xffff0000;
          local_e4 = FUN_0072e3c0();
        } while (local_e4 != 0);
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
    FUN_006edb60("Can\'t load file: %s","Table/StatusList.xml");
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
  __security_check_cookie(local_1c ^ (uint)&local_e4);
  return;
}

