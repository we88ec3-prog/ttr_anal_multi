
void FUN_00513120(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined2 local_a2;
  undefined4 local_a0;
  int local_9c;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009227ab;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_a4;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar2 = FUN_0072e2e0("CHAR_UPGRADE_INFO");
    if (iVar2 == 0) {
      FUN_006edb60("Not CharUpgradeInfo File!");
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
      iVar2 = FUN_0072e360(uVar1);
      if (iVar2 != 0) {
        local_9c = param_1 + 8;
        do {
          iVar2 = FUN_007300a0(&DAT_00c02328);
          if (iVar2 == 0) {
LAB_005132a1:
            local_a4 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_005132a1;
            local_a4 = FUN_008917b4(puVar3);
          }
          iVar2 = FUN_007300a0("LEVEL");
          if (iVar2 == 0) {
LAB_005132ce:
            local_a3 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_005132ce;
            local_a3 = FUN_008917b4(puVar3);
          }
          iVar2 = FUN_007300a0("SKILL_EXP");
          if (iVar2 == 0) {
LAB_005132fb:
            local_a2 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_005132fb;
            local_a2 = FUN_008917b4(puVar3);
          }
          iVar2 = FUN_007300a0("LEELOO");
          if (iVar2 == 0) {
LAB_00513329:
            local_a0 = 0;
          }
          else {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 == (undefined4 *)0x0) goto LAB_00513329;
            local_a0 = FUN_008917b4(puVar3);
          }
          FUN_004fc620();
          iVar2 = FUN_0072e3c0();
        } while (iVar2 != 0);
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
    FUN_006edb60("Not Open CharUpgradeInfo File!");
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
  __security_check_cookie(local_1c ^ (uint)&local_a4);
  return;
}

