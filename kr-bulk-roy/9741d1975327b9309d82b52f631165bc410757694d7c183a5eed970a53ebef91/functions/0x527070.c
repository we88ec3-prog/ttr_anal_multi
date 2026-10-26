
void FUN_00527070(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_e4;
  uint local_d0;
  undefined **local_c8 [17];
  char local_84;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933b66;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_c8);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_0072f110(0);
  if ((local_84 == '\0') && (iVar3 = FUN_0072e2e0("TALKTABLESET"), iVar3 != 0)) {
    piVar1 = *(int **)(iVar3 + 0x18);
    while (piVar1 != (int *)0x0) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      local_8._0_1_ = 1;
      iVar3 = (**(code **)(*piVar1 + 0x14))(uVar2);
      if (iVar3 == 0) {
        if (0xf < local_20) {
          FUN_0089120c(local_34);
        }
      }
      else {
        local_3c = 0xf;
        local_40 = 0;
        local_50 = local_50 & 0xffffff00;
        FUN_00402a70(&DAT_00c0d5f0,4);
        local_8._0_1_ = 2;
        uVar4 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00402bb0(uVar4);
        if (0xf < local_d0) {
          FUN_0089120c(local_e4);
        }
        local_8._0_1_ = 1;
        local_d0 = 0xf;
        local_e4 = local_e4 & 0xffffff00;
        if (0xf < local_3c) {
          FUN_0089120c(local_50);
        }
        local_3c = 0xf;
        local_40 = 0;
        local_50 = local_50 & 0xffffff00;
        FUN_00526960(param_1);
        if (0xf < local_20) {
          FUN_0089120c(local_34);
        }
      }
      local_20 = 0xf;
      piVar1 = (int *)piVar1[0x10];
      local_34 = local_34 & 0xffffff00;
      local_24 = 0;
    }
    local_8 = 0xffffffff;
    local_c8[0] = TiXmlDocument::vftable;
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_c8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_68) {
      local_8 = 0xffffffff;
      local_c8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

