
void FUN_004ec030(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_ac [4];
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
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
  puStack_10 = &LAB_0092287b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if ((((local_54 == '\0') && (iVar2 = FUN_0072e2e0("GUILD_INFO"), iVar2 != 0)) &&
      (iVar2 = FUN_0072e2e0("LEVEL_INFO"), iVar2 != 0)) && (iVar2 = FUN_0072e360(uVar1), iVar2 != 0)
     ) {
    local_a8 = param_1 + 0x5f24;
    do {
      iVar2 = FUN_007300a0("LEVEL");
      if (iVar2 == 0) {
LAB_004ec172:
        local_a4 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_004ec172;
        local_a4 = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0("NUMBER");
      if (iVar2 == 0) {
LAB_004ec19f:
        local_a0 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_004ec19f;
        local_a0 = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0(&DAT_00c0d2d4);
      if (iVar2 == 0) {
LAB_004ec1cc:
        local_9c = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_004ec1cc;
        local_9c = FUN_008917b4(puVar3);
      }
      FUN_0052ef90();
      iVar2 = FUN_0072e3c0();
    } while (iVar2 != 0);
  }
  local_98[0] = TiXmlDocument::vftable;
  local_c = 0xffffffff;
  if (0xf < local_38) {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}

