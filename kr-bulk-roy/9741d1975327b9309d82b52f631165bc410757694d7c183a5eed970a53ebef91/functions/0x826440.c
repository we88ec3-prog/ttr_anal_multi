
void FUN_00826440(undefined4 param_1)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_98;
  undefined4 local_94;
  undefined **local_90 [19];
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
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_94 = param_1;
  local_18 = uVar3;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if ((cVar2 == '\0') || (iVar4 = FUN_0072e360(uVar3), iVar4 == 0)) {
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
  else {
    iVar4 = FUN_0072e360(uVar3);
    if (iVar4 != 0) {
      iVar4 = FUN_0072e360(uVar3);
      while (iVar4 != 0) {
        iVar4 = FUN_007300a0("index");
        if (iVar4 == 0) {
LAB_0082656b:
          local_98 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0082656b;
          local_98 = FUN_008917b4(puVar5);
        }
        uVar1 = local_94;
        uVar6 = FUN_006bde40(&local_98);
        FUN_00436890(uVar1,uVar6);
        iVar4 = FUN_0072e3c0();
      }
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
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

