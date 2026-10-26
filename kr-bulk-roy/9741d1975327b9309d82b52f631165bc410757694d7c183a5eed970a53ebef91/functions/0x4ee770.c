
void FUN_004ee770(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined1 auStack_b4 [4];
  int local_b0;
  uint *local_ac;
  undefined4 local_a8 [4];
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
  puStack_10 = &LAB_0092496b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_b4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff40;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar3 = FUN_0072e2e0("INVENTORY_EXPAND_INFO");
    if (iVar3 == 0) {
      FUN_006edb60("Not InventoryExpandInfo File!");
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
      local_b0 = FUN_0072e360(uVar2);
      if (local_b0 != 0) {
        local_ac = (uint *)(param_1 + 8);
        do {
          iVar3 = FUN_007300a0(&DAT_00c0d378);
          if (iVar3 == 0) {
LAB_004ee913:
            local_a8[0] = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_004ee913;
            local_a8[0] = FUN_008917b4(puVar4);
          }
          iVar3 = FUN_007300a0(&DAT_00c0d37c);
          if (iVar3 == 0) {
LAB_004ee940:
            local_a8[1] = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_004ee940;
            local_a8[1] = FUN_008917b4(puVar4);
          }
          iVar3 = FUN_007300a0("MIN_LEVEL");
          if (iVar3 == 0) {
LAB_004ee96d:
            uVar5 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_004ee96d;
            uVar5 = FUN_008917b4(puVar4);
          }
          local_a8[2] = uVar5;
          iVar3 = FUN_007300a0("LEELOO");
          if (iVar3 == 0) {
LAB_004ee99c:
            uVar6 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_004ee99c;
            uVar6 = FUN_008917b4(puVar4);
          }
          puVar1 = local_ac;
          puVar4 = (undefined4 *)local_ac[1];
          local_a8[3] = uVar6;
          if (local_a8 < puVar4) {
            puVar7 = (undefined4 *)*local_ac;
            if (local_a8 < puVar7) goto LAB_004ee9f1;
            if (puVar4 == (undefined4 *)local_ac[2]) {
              FUN_0053ec00();
            }
            puVar4 = (undefined4 *)puVar1[1];
            puVar7 = (undefined4 *)(((int)local_a8 - (int)puVar7 & 0xfffffff0U) + *puVar1);
            if (puVar4 != (undefined4 *)0x0) {
              *puVar4 = *puVar7;
              puVar4[1] = puVar7[1];
              puVar4[2] = puVar7[2];
              puVar4[3] = puVar7[3];
            }
          }
          else {
LAB_004ee9f1:
            if (puVar4 == (undefined4 *)local_ac[2]) {
              FUN_0053ec00();
            }
            puVar4 = (undefined4 *)puVar1[1];
            if (puVar4 != (undefined4 *)0x0) {
              *puVar4 = local_a8[0];
              puVar4[1] = local_a8[1];
              puVar4[2] = uVar5;
              puVar4[3] = uVar6;
            }
          }
          puVar1[1] = puVar1[1] + 0x10;
          local_b0 = FUN_0072e3c0();
        } while (local_b0 != 0);
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
    FUN_006edb60("Load Error CInventoryExpandInfo::_LoadTable");
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
  __security_check_cookie(local_1c ^ (uint)auStack_b4);
  return;
}

