
void FUN_00514740(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_8c [17];
  char local_48;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923d4b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_48 == '\0') {
    iVar2 = FUN_0072e2e0("ITEM_ENCHANT_CHARGE");
    if (iVar2 != 0) {
      FUN_0072e2e0("EQUIP_LEVELUP");
      FUN_00514f50(uVar1);
      FUN_0072e2e0("EQUIP_OPEN_SLOT");
      FUN_00515090();
      FUN_0072e2e0("EQUIP_REINFORCE");
      FUN_00515200();
      FUN_0072e2e0("REINFORCE_STONE_COMPOUND");
      FUN_00515340();
      FUN_0072e2e0("REFINE_STONE_GRADE");
      FUN_00515450();
      local_8 = 0xffffffff;
      local_8c[0] = TiXmlDocument::vftable;
      if (0xf < local_2c) {
        FUN_0089120c(local_40);
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = local_40 & 0xffffff00;
      FUN_0072e040();
      goto LAB_005148cd;
    }
    FUN_006edb60("LoadFailed : %s","Table/ItemEnchantCharge.xml");
  }
  else {
    FUN_006edb60("LoadFailed : %s","Table/ItemEnchantCharge.xml");
  }
  local_8c[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_2c) {
    local_8 = 0xffffffff;
    local_8c[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_0072e040();
LAB_005148cd:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

