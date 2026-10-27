
undefined4 * FUN_00506ad0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00929968;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 1;
  uStack_7 = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  iVar2 = FUN_00891268(0x38,uVar1);
  local_8 = 2;
  if (iVar2 != 0) {
    FUN_005245b0(iVar2);
  }
  local_8 = 1;
  FUN_00443d10();
  iVar2 = FUN_00891268(0x20,uVar1);
  local_8 = 3;
  if (iVar2 != 0) {
    FUN_005073e0(iVar2);
  }
  local_8 = 1;
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x24);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CSquareUserData::vftable;
    puVar3[1] = CSquareUserData::vftable;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    DAT_00fe1aa0 = puVar3;
    puVar3[6] = 0;
    puVar3[7] = 1;
    *(undefined1 *)(puVar3 + 8) = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x20);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CSquareChannelState::vftable;
    puVar3[1] = CSquareChannelState::vftable;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    DAT_00fe1a88 = puVar3;
    puVar3[6] = 0;
    puVar3[7] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x18);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CShopMgr::vftable;
    puVar3[1] = CShopMgr::vftable;
    DAT_00fe1db4 = puVar3;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x18);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CBuffExplainTable::vftable;
    puVar3[1] = CBuffExplainTable::vftable;
    DAT_00fc0c6c = puVar3;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  }
  FUN_00443d10();
  iVar2 = FUN_00891268(0x18);
  local_8 = 4;
  if (iVar2 != 0) {
    FUN_00533200(iVar2);
  }
  local_8 = 1;
  FUN_00443d10();
  iVar2 = FUN_00891268(0x18);
  local_8 = 5;
  if (iVar2 != 0) {
    FUN_00528780(iVar2);
  }
  local_8 = 1;
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CInventoryExpandInfo::vftable;
    puVar3[1] = CInventoryExpandInfo::vftable;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    DAT_00fe1d9c = puVar3;
    puVar3[6] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x24);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CMissionDescData::vftable;
    puVar3[1] = CMissionDescData::vftable;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    DAT_00fe1aa4 = puVar3;
    *(undefined2 *)(puVar3 + 8) = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x18);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CCharUpgradeInfoTable::vftable;
    puVar3[1] = CCharUpgradeInfoTable::vftable;
    DAT_00fe1df4 = puVar3;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x38);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CScenarioDescData::vftable;
    puVar3[1] = CScenarioDescData::vftable;
    *(undefined1 *)((int)puVar3 + 0x12) = 0;
    *(undefined2 *)(puVar3 + 3) = 0x50;
    *(undefined2 *)((int)puVar3 + 0xe) = 0;
    *(undefined2 *)(puVar3 + 4) = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    DAT_00fe18f8 = puVar3;
    puVar3[9] = 0;
    *(undefined2 *)(puVar3 + 10) = 0;
    *(undefined4 *)((int)puVar3 + 0x2a) = 0;
    *(undefined4 *)((int)puVar3 + 0x2e) = 0;
    *(undefined4 *)((int)puVar3 + 0x32) = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x24);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CRaidDescData::vftable;
    puVar3[1] = CRaidDescData::vftable;
    DAT_00fe1b58 = puVar3;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x5c);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CInfiniteDungeonDescData::vftable;
    puVar3[1] = CInfiniteDungeonDescData::vftable;
    DAT_00fc0c68 = puVar3;
    puVar3[0x13] = 0;
    puVar3[0x14] = 0;
    puVar3[0x15] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x6c);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CEternalTowerDescData::vftable;
    puVar3[1] = CEternalTowerDescData::vftable;
    DAT_00fb7618 = puVar3;
    puVar3[0x17] = 0;
    puVar3[0x18] = 0;
    puVar3[0x19] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0x28);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = IDataTable::vftable;
    *puVar3 = CDailyDungeonDescData::vftable;
    puVar3[1] = CDailyDungeonDescData::vftable;
    DAT_00fb7348 = puVar3;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
  }
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0xc);
  if (puVar3 != (undefined4 *)0x0) {
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      local_8 = 7;
      FUN_00523540();
      local_8 = 8;
      FUN_00521080(&DAT_00f8d9bc);
      _atexit((_func_4879 *)&LAB_00bccc50);
    }
    *puVar3 = CSingletonSupport<CItemTable,void>::vftable;
    puVar3[1] = &DAT_00f8d9ac;
    puVar3[2] = FUN_00523450;
  }
  local_8 = 1;
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0xc);
  if (puVar3 != (undefined4 *)0x0) {
    if ((DAT_00fe1de0 & 1) == 0) {
      DAT_00fe1de0 = DAT_00fe1de0 | 1;
      local_8 = 10;
      FUN_00519060();
      _atexit(FUN_00bcef60);
    }
    *puVar3 = CSingletonSupport<CItemCompoundTable,void>::vftable;
    puVar3[1] = &DAT_00fe1de4;
    puVar3[2] = &LAB_00519670;
  }
  local_8 = 1;
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0xc);
  if (puVar3 != (undefined4 *)0x0) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0xc;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    *puVar3 = CSingletonSupport<CItemProductTable,void>::vftable;
    puVar3[1] = &DAT_00f8d918;
    puVar3[2] = FUN_0051d7d0;
  }
  local_8 = 1;
  FUN_00443d10();
  puVar3 = (undefined4 *)FUN_00891268(0xc);
  if (puVar3 != (undefined4 *)0x0) {
    if ((DAT_00fe1dcc & 1) == 0) {
      DAT_00fe1dcc = DAT_00fe1dcc | 1;
      local_8 = 0xe;
      FUN_0051ed80();
      _atexit(FUN_00bcefc0);
    }
    *puVar3 = CSingletonSupport<CItemSetTable,void>::vftable;
    puVar3[1] = &DAT_00fe1dd0;
    puVar3[2] = &LAB_0051ec00;
  }
  _local_8 = CONCAT31(uStack_7,1);
  FUN_00443d10();
  ExceptionList = local_10;
  return param_1;
}

