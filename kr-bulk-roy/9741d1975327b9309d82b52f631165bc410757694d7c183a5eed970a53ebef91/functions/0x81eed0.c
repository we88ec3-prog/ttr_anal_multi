
void FUN_0081eed0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint local_13c;
  uint local_128;
  undefined **local_120 [19];
  uint local_d4;
  undefined4 local_c4;
  uint local_c0;
  uint local_a4;
  undefined4 local_94;
  uint local_90;
  uint local_78;
  undefined4 local_68;
  uint local_64;
  uint local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009260cc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  FUN_0072ee30(local_120);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 == '\0') || (iVar4 = FUN_0072e360(uVar3), iVar4 == 0)) goto joined_r0x0081f24e;
  iVar4 = FUN_007300a0("banner");
  if (iVar4 == 0) {
LAB_0081efb4:
    uVar2 = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_0081efb4;
    uVar2 = FUN_008917b4(puVar5);
  }
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  iVar4 = FUN_0072e360();
  while (iVar4 != 0) {
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_20 = 7;
    local_24 = 0;
    local_34 = local_34 & 0xffff0000;
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = FUN_007300a0(&DAT_00bed1d0);
    if (iVar4 == 0) {
LAB_0081f036:
      local_40 = 0;
    }
    else {
      puVar5 = (undefined4 *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (puVar5 == (undefined4 *)0x0) goto LAB_0081f036;
      local_40 = FUN_008917b4(puVar5);
    }
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = local_a4 & 0xffffff00;
    FUN_00402a70("target",6);
    local_8._0_1_ = 2;
    uVar6 = FUN_0072ecf0(&DAT_00bf2375);
    local_48 = 0xf;
    local_4c = 0;
    local_5c = local_5c & 0xffffff00;
    local_8._0_1_ = 4;
    FUN_00403040(uVar6,0,0xffffffff);
    local_8._0_1_ = 5;
    uVar6 = FUN_00402a50();
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_00402800(uVar6);
    if (7 < local_128) {
      FUN_0089120c(local_13c);
    }
    local_128 = 7;
    local_13c = local_13c & 0xffff0000;
    if (0xf < local_48) {
      FUN_0089120c(local_5c);
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = local_5c & 0xffffff00;
    if (0xf < local_64) {
      FUN_0089120c(local_78);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_64 = 0xf;
    local_68 = 0;
    local_78 = local_78 & 0xffffff00;
    if (0xf < local_90) {
      FUN_0089120c(local_a4);
    }
    iVar4 = FUN_007300a0("product");
    if (iVar4 == 0) {
LAB_0081f16b:
      local_3c = 0;
    }
    else {
      puVar5 = (undefined4 *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (puVar5 == (undefined4 *)0x0) goto LAB_0081f16b;
      local_3c = FUN_008917b4(puVar5);
    }
    iVar4 = FUN_007300a0(&DAT_00bfb854);
    if (iVar4 == 0) {
LAB_0081f197:
      local_38 = 0;
    }
    else {
      puVar5 = (undefined4 *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (puVar5 == (undefined4 *)0x0) goto LAB_0081f197;
      local_38 = FUN_008917b4(puVar5);
    }
    FUN_0081f720();
    local_8._0_1_ = 7;
    uVar6 = FUN_0081f9d0(param_1);
    FUN_0081f770(param_1,uVar6);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (7 < local_64) {
      FUN_0089120c(local_78);
    }
    local_78 = local_78 & 0xffff0000;
    local_64 = 7;
    local_68 = 0;
    iVar4 = FUN_0072e3c0();
    if (7 < local_20) {
      FUN_0089120c(local_34);
    }
    local_20 = 7;
    local_24 = 0;
    local_34 = local_34 & 0xffff0000;
  }
joined_r0x0081f24e:
  local_120[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_c0) {
    local_8 = 0xffffffff;
    local_120[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_d4);
  }
  local_c0 = 0xf;
  local_c4 = 0;
  local_d4 = local_d4 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

