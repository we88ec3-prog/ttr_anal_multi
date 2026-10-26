
void FUN_0082a7b0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925c9b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
  }
  else {
    iVar3 = FUN_0072e360(uVar2);
    if (iVar3 != 0) {
      iVar3 = FUN_0072e360(uVar2);
      while (iVar3 != 0) {
        iVar3 = FUN_007300a0("ProductID");
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0(&DAT_00c537a0);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0(&DAT_00c537a4);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0("Contribution");
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        uVar5 = FUN_0082b0b0();
        FUN_0082ae70(param_1,uVar5);
        iVar3 = FUN_0072e3c0();
      }
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_44 = local_44 & 0xffffff00;
      goto LAB_0082a9ea;
    }
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
      local_44 = local_44 & 0xffffff00;
      goto LAB_0082a9ea;
    }
  }
  local_44 = local_44 & 0xffffff00;
LAB_0082a9ea:
  local_34 = 0;
  local_30 = 0xf;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

