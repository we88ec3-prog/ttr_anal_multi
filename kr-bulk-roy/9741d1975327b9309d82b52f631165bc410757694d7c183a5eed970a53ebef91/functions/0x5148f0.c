
void FUN_005148f0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
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
  puStack_c = &LAB_00923d0b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_48 == '\0') {
    iVar2 = FUN_0072e2e0(&DAT_00c0e3ac);
    if (iVar2 != 0) {
      iVar2 = FUN_0072e360(uVar1);
      while (iVar2 != 0) {
        iVar2 = FUN_007300a0("Class");
        if (iVar2 == 0) {
LAB_00514a2d:
          local_98 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_00514a2d;
          local_98 = FUN_008917b4(puVar3);
        }
        iVar2 = FUN_007300a0(&DAT_00c0e3c8);
        if (iVar2 == 0) {
LAB_00514a5c:
          local_94 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_00514a5c;
          local_94 = FUN_008917b4(puVar3);
        }
        iVar2 = FUN_007300a0("RefineStoneCount");
        if (iVar2 == 0) {
LAB_00514a8d:
          uVar4 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_00514a8d;
          uVar4 = FUN_008917b4(puVar3);
        }
        iVar2 = FUN_007300a0("Level");
        if (iVar2 == 0) {
LAB_00514ab7:
          local_90 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_00514ab7;
          local_90 = FUN_008917b4(puVar3);
        }
        if (0 < local_90) {
          local_90 = local_90 + -1;
        }
        puVar3 = &local_94;
        uVar5 = FUN_00515b90(&DAT_00fe308c,&local_98);
        FUN_00829960(uVar5,puVar3);
        puVar3 = (undefined4 *)FUN_004c2880();
        *puVar3 = uVar4;
        iVar2 = FUN_0072e3c0();
      }
      local_8 = 0xffffffff;
      local_8c[0] = TiXmlDocument::vftable;
      if (0xf < local_2c) {
        FUN_0089120c(local_40);
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = local_40 & 0xffffff00;
      FUN_0072e040();
      goto LAB_00514b54;
    }
    FUN_006edb60("LoadFailed : %s","Table/ItemLevelupRequireTable.xml");
  }
  else {
    FUN_006edb60("LoadFailed : %s","Table/ItemLevelupRequireTable.xml");
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
LAB_00514b54:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

