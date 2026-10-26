
void FUN_00813670(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined **local_90 [17];
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925deb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_0072ed80(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_4c != '\0') || (iVar2 = FUN_0072e2e0("AVATAR"), iVar2 == 0)) {
    local_90[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_30) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
    goto LAB_00813872;
  }
  iVar2 = FUN_0072e360(uVar1);
  while (iVar2 != 0) {
    iVar2 = FUN_007300a0("Level");
    if (iVar2 != 0) {
      puVar3 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      if (puVar3 != (undefined4 *)0x0) {
        FUN_008917b4(puVar3);
      }
    }
    iVar2 = FUN_007300a0("CoinNeed");
    if (iVar2 == 0) {
LAB_008137bd:
      uVar4 = 0;
    }
    else {
      puVar3 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      if (puVar3 == (undefined4 *)0x0) goto LAB_008137bd;
      uVar4 = FUN_008917b4(puVar3);
    }
    puVar3 = (undefined4 *)FUN_004c2880();
    *puVar3 = uVar4;
    iVar2 = FUN_0072e3c0();
  }
  iVar2 = FUN_0072e360();
  if (iVar2 != 0) {
    iVar2 = FUN_007300a0("ItemNo");
    if (iVar2 == 0) {
LAB_00813827:
      uVar4 = 0;
    }
    else {
      puVar3 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      if (puVar3 == (undefined4 *)0x0) goto LAB_00813827;
      uVar4 = FUN_008917b4(puVar3);
    }
    *(undefined4 *)(param_1 + 0x20) = uVar4;
  }
  local_8 = 0xffffffff;
  local_90[0] = TiXmlDocument::vftable;
  if (0xf < local_30) {
    FUN_0089120c(local_44);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
LAB_00813872:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

