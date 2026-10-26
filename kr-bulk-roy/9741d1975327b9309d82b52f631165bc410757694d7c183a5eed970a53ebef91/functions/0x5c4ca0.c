
void FUN_005c4ca0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined4 ****ppppuVar7;
  undefined4 uVar8;
  int iVar9;
  int local_ec;
  undefined4 local_e4 [5];
  uint local_d0;
  undefined **local_c8 [6];
  undefined4 *local_b0;
  undefined4 local_a8;
  uint local_94;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined4 ***local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926f84;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar5;
  FUN_0072ed80(local_c8);
  local_8 = 0;
  FUN_0047f540(L"UI/Data/ImageList.xml",uVar5);
  local_8._0_1_ = 1;
  cVar4 = FUN_0072f110(1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
  if (cVar4 == '\0') {
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
    FUN_004297b0();
    ppppuVar7 = (undefined4 ****)local_34[0];
    if (local_20 < 0x10) {
      ppppuVar7 = local_34;
    }
    iVar6 = FUN_0072e2e0(ppppuVar7);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
    if (iVar6 == 0) {
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
      FUN_004297b0();
      ppppuVar7 = (undefined4 ****)local_50[0];
      if (local_3c < 0x10) {
        ppppuVar7 = local_50;
      }
      iVar6 = FUN_0072e2e0(ppppuVar7);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (undefined4 ***)((uint)local_50[0] & 0xffffff00);
      while (iVar6 != 0) {
        FUN_00764d80(local_e4,&DAT_00bed1fc);
        local_8._0_1_ = 2;
        FUN_005c5040(param_1);
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_d0) {
          FUN_0089120c(local_e4[0]);
        }
        FUN_004297b0();
        ppppuVar7 = (undefined4 ****)local_34[0];
        if (local_20 < 0x10) {
          ppppuVar7 = local_34;
        }
        iVar6 = FUN_0072e320(ppppuVar7);
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
      }
      iVar6 = *(int *)(param_1 + 0x454);
      iVar9 = *(int *)(param_1 + 0x458) - iVar6;
      iVar3 = iVar9 >> 0x1f;
      uVar5 = 0;
      if (iVar9 / 0x2c + iVar3 != iVar3) {
        local_ec = 0;
        do {
          FUN_005c5620(local_ec + iVar6);
          iVar6 = *(int *)(param_1 + 0x454);
          local_ec = local_ec + 0x2c;
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)((*(int *)(param_1 + 0x458) - iVar6) / 0x2c));
      }
      if (*(int *)(param_1 + 0x454) != *(int *)(param_1 + 0x458)) {
        uVar8 = FUN_005c7870(*(int *)(param_1 + 0x458));
        FUN_005c7ba0(*(undefined4 *)(param_1 + 0x458),local_ec);
        *(undefined4 *)(param_1 + 0x458) = uVar8;
      }
      local_c8[0] = TiXmlDocument::vftable;
      if (0xf < local_68) {
        FUN_0089120c(local_7c);
      }
      local_68 = 0xf;
      local_6c = 0;
      local_7c = local_7c & 0xffffff00;
      local_c8[0] = TiXmlNode::vftable;
      local_8 = 4;
      puVar2 = local_b0;
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        puVar2 = (undefined4 *)puVar2[0x10];
        (*(code *)*puVar1)(1);
      }
      if (0xf < local_94) {
        FUN_0089120c(local_a8);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

