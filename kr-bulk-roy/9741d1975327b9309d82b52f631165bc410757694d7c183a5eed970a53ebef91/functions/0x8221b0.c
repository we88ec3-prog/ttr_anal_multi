
void FUN_008221b0(void)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined **local_110 [6];
  undefined4 *local_f8;
  uint local_f0;
  undefined4 uStack_e0;
  uint local_dc;
  uint local_c4;
  undefined4 local_b4;
  uint local_b0;
  undefined **local_98 [6];
  undefined4 *puStack_80;
  undefined4 local_78;
  uint local_64;
  uint uStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925f8f;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_134;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffec0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072ee30(local_110);
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_00823850(uVar3);
  FUN_00844c60();
  cVar2 = FUN_0072f110(0);
  if (cVar2 != '\0') {
    FUN_0072e2e0("TIOS_CONVERTER");
    iVar4 = FUN_0072e360();
    while (iVar4 != 0) {
      iVar4 = FUN_007300a0("item_no");
      if (iVar4 == 0) {
LAB_008222bd:
        uVar6 = 0;
      }
      else {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_008222bd;
        uVar6 = FUN_008917b4(puVar5);
      }
      iVar4 = FUN_007300a0("item_exp");
      if (iVar4 == 0) {
LAB_008222e7:
        local_130 = 0;
      }
      else {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_008222e7;
        local_130 = FUN_008917b4(puVar5);
      }
      local_134 = uVar6;
      uVar6 = FUN_0057ef20();
      FUN_0057e850(&DAT_00fb9370,uVar6);
      iVar4 = FUN_0072e3c0();
    }
  }
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') goto LAB_0082249d;
  FUN_0072e2e0("TIOS_CONVERTER_EXP_TABLE");
  FUN_0072e360();
  iVar4 = FUN_007300a0("max_exp");
  if (iVar4 == 0) {
LAB_00822385:
    DAT_00fb936c = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_00822385;
    DAT_00fb936c = FUN_008917b4(puVar5);
  }
  iVar4 = FUN_0072e360();
  while (local_12c = iVar4, iVar4 != 0) {
    iVar10 = iVar4 + 0x44;
    for (iVar9 = *(int *)(iVar4 + 0x94); iVar9 != iVar10; iVar9 = *(int *)(iVar9 + 0x50)) {
      pcVar8 = (char *)(iVar9 + 0x14);
      if (0xf < *(uint *)(iVar9 + 0x28)) {
        pcVar8 = *(char **)pcVar8;
      }
      iVar7 = __stricmp(pcVar8,"tios_grade");
      if (iVar7 == 0) {
        if (iVar9 != 0) {
          puVar5 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            local_134 = FUN_008917b4(puVar5);
            goto LAB_008223f5;
          }
        }
        break;
      }
    }
    local_134 = 0;
LAB_008223f5:
    for (iVar9 = *(int *)(iVar4 + 0x94); iVar9 != iVar10; iVar9 = *(int *)(iVar9 + 0x50)) {
      pcVar8 = (char *)(iVar9 + 0x14);
      if (0xf < *(uint *)(iVar9 + 0x28)) {
        pcVar8 = *(char **)pcVar8;
      }
      iVar7 = __stricmp(pcVar8,"need_exp");
      if (iVar7 == 0) {
        if (iVar9 != 0) {
          puVar5 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            uVar6 = FUN_008917b4(puVar5);
            goto LAB_00822429;
          }
        }
        break;
      }
    }
    uVar6 = 0;
LAB_00822429:
    for (iVar4 = *(int *)(iVar4 + 0x94); iVar4 != iVar10; iVar4 = *(int *)(iVar4 + 0x50)) {
      pcVar8 = (char *)(iVar4 + 0x14);
      if (0xf < *(uint *)(iVar4 + 0x28)) {
        pcVar8 = *(char **)pcVar8;
      }
      iVar9 = __stricmp(pcVar8,"product_id");
      if (iVar9 == 0) {
        if (iVar4 != 0) {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            local_11c = FUN_008917b4(puVar5);
            goto LAB_0082245a;
          }
        }
        break;
      }
    }
    local_11c = 0;
LAB_0082245a:
    local_124 = local_134;
    local_120 = uVar6;
    uVar6 = FUN_00821c50();
    FUN_00517bf0(&DAT_00fb9380,uVar6);
    iVar4 = FUN_0072e3c0();
  }
LAB_0082249d:
  local_110[0] = TiXmlDocument::vftable;
  if (0xf < local_b0) {
    FUN_0089120c(local_c4);
  }
  local_b0 = 0xf;
  local_b4 = 0;
  local_c4 = local_c4 & 0xffffff00;
  local_110[0] = TiXmlNode::vftable;
  local_c = CONCAT31(local_c._1_3_,3);
  puVar5 = local_f8;
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    puVar5 = (undefined4 *)puVar5[0x10];
    (*(code *)*puVar1)(1);
  }
  if (0xf < local_dc) {
    FUN_0089120c(local_f0);
  }
  local_dc = 0xf;
  uStack_e0 = 0;
  local_f0 = local_f0 & 0xffffff00;
  local_110[0] = TiXmlBase::vftable;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < uStack_38) {
    FUN_0089120c(uStack_4c);
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  uStack_4c = uStack_4c & 0xffffff00;
  local_98[0] = TiXmlNode::vftable;
  local_c = 5;
  puVar5 = puStack_80;
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    puVar5 = (undefined4 *)puVar5[0x10];
    (*(code *)*puVar1)(1);
  }
  if (0xf < local_64) {
    FUN_0089120c(local_78);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_134);
  return;
}

