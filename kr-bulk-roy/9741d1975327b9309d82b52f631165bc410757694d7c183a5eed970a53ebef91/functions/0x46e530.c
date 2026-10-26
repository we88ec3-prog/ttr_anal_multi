
void FUN_0046e530(void)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *local_16c;
  int iStack_168;
  int iStack_164;
  undefined1 auStack_160 [8];
  uint uStack_158;
  undefined4 uStack_148;
  uint uStack_144;
  uint uStack_13c;
  undefined4 uStack_12c;
  uint uStack_128;
  undefined4 uStack_120;
  uint uStack_11c;
  undefined4 uStack_10c;
  uint uStack_108;
  uint uStack_100;
  undefined4 uStack_f0;
  uint uStack_ec;
  undefined4 uStack_e4;
  undefined **local_e0 [19];
  uint local_94;
  undefined4 local_84;
  uint local_80;
  uint uStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092558a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_16c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffe88;
  ExceptionList = &local_14;
  FUN_0072ee30(local_e0);
  local_c = 0;
  cVar2 = FUN_0072f110(0);
  piVar1 = local_16c;
  if ((cVar2 != '\0') && (iVar4 = FUN_0072e2e0("ONSCREENKEYTABLE"), piVar1 = local_16c, iVar4 != 0))
  {
    local_16c = (int *)FUN_0072e360(uVar3);
    while (piVar1 = (int *)0x0, local_16c != (int *)0x0) {
      iStack_168 = (**(code **)(*local_16c + 0x14))();
      uStack_108 = 0xf;
      uStack_10c = 0;
      uStack_11c = uStack_11c & 0xffffff00;
      uStack_ec = 0xf;
      uStack_f0 = 0;
      uStack_100 = uStack_100 & 0xffffff00;
      iStack_164 = iStack_168 + 0x44;
      local_c = CONCAT31(local_c._1_3_,1);
      iVar4 = FUN_007300a0(&DAT_00c014f4);
      if (iVar4 == 0) {
LAB_0046e69b:
        uStack_120 = 0;
      }
      else {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_0046e69b;
        uStack_120 = FUN_008917b4(puVar5);
      }
      uStack_144 = 0xf;
      uStack_148 = 0;
      uStack_158 = uStack_158 & 0xffffff00;
      FUN_00402a70("lower",5);
      local_c._0_1_ = 2;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,3);
      FUN_00402bb0(uVar6);
      if (0xf < uStack_128) {
        FUN_0089120c(uStack_13c);
      }
      local_c._0_1_ = 1;
      uStack_128 = 0xf;
      uStack_12c = 0;
      uStack_13c = uStack_13c & 0xffffff00;
      if (0xf < uStack_144) {
        FUN_0089120c(uStack_158);
      }
      uStack_144 = 0xf;
      uStack_148 = 0;
      uStack_158 = uStack_158 & 0xffffff00;
      FUN_00402a70("upper",5);
      local_c._0_1_ = 4;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,5);
      FUN_00402bb0(uVar6);
      if (0xf < uStack_128) {
        FUN_0089120c(uStack_13c);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      uStack_128 = 0xf;
      uStack_12c = 0;
      uStack_13c = uStack_13c & 0xffffff00;
      if (0xf < uStack_144) {
        FUN_0089120c(uStack_158);
      }
      iVar4 = FUN_007300a0("keyid");
      if (iVar4 == 0) {
LAB_0046e7f1:
        uStack_e4 = 0;
      }
      else {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_0046e7f1;
        uStack_e4 = FUN_008917b4(puVar5);
      }
      FUN_0046f200();
      local_c._0_1_ = 6;
      uVar6 = FUN_0046f580();
      FUN_0046f270(auStack_160,uVar6);
      local_c = CONCAT31(local_c._1_3_,1);
      if (0xf < uStack_30) {
        FUN_0089120c(uStack_44);
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
      uStack_44 = uStack_44 & 0xffffff00;
      if (0xf < uStack_4c) {
        FUN_0089120c(uStack_60);
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      uStack_60 = uStack_60 & 0xffffff00;
      FUN_0046eaa0(&DAT_00fc0d84);
      local_c = local_c & 0xffffff00;
      if (0xf < uStack_ec) {
        FUN_0089120c(uStack_100);
      }
      uStack_ec = 0xf;
      uStack_f0 = 0;
      uStack_100 = uStack_100 & 0xffffff00;
      if (0xf < uStack_108) {
        FUN_0089120c(uStack_11c);
      }
      local_16c = (int *)local_16c[0x10];
      uStack_108 = 0xf;
      uStack_10c = 0;
      uStack_11c = uStack_11c & 0xffffff00;
    }
  }
  local_16c = piVar1;
  local_c = 0xffffffff;
  local_e0[0] = TiXmlDocument::vftable;
  if (0xf < local_80) {
    local_c = 0xffffffff;
    local_e0[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_94);
  }
  local_80 = 0xf;
  local_84 = 0;
  local_94 = local_94 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_16c);
  return;
}

