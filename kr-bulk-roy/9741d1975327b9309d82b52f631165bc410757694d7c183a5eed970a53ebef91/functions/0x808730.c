
void FUN_00808730(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
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
  FUN_0072ee30(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_4c == '\0') && (iVar2 = FUN_0072e2e0("AILIST"), iVar2 != 0)) {
    iVar3 = FUN_0072e2e0("ITEMLIST");
    if (iVar3 == 0) {
      local_8 = 0xffffffff;
      FUN_00407fb0();
    }
    else {
      iVar3 = FUN_0072e360(uVar1);
      while (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bfaf5c);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0(&DAT_00c1a980);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_00808940(param_1);
          }
        }
        iVar3 = FUN_0072e3c0();
      }
      (**(code **)(*param_1 + 4))(iVar2);
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_30 = 0xf;
      local_34 = 0;
      local_44 = local_44 & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
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
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

