
void FUN_00541c00(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *_Str1;
  uint uVar5;
  uint uVar6;
  uint local_94;
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
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007b6d70(local_18);
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    iVar2 = FUN_0072e2e0("TOWNLIST");
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_30 = 0xf;
      local_34 = 0;
      local_44 = local_44 & 0xffffff00;
      FUN_0072e040();
      goto LAB_00541ee5;
    }
    piVar3 = (int *)FUN_0072e2e0(&DAT_00c067ec);
joined_r0x00541cdf:
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 0x14))();
      if (iVar2 != 0) {
        iVar2 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar2 == 0) {
LAB_00541d1d:
          iVar2 = 0;
        }
        else {
          puVar4 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_00541d1d;
          iVar2 = FUN_008917b4(puVar4);
        }
        if (iVar2 == param_1) {
          iVar2 = FUN_0072e2e0("NPCLIST");
          if (iVar2 == 0) {
            local_8 = 0xffffffff;
            FUN_00407fb0();
            goto LAB_00541ee5;
          }
          piVar3 = (int *)FUN_0072e2e0(&DAT_00c0d83c);
          goto joined_r0x00541d99;
        }
      }
      for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
        _Str1 = piVar3 + 8;
        if (0xf < (uint)piVar3[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar2 = __stricmp((char *)_Str1,"TOWN");
        if (iVar2 == 0) goto joined_r0x00541cdf;
      }
      piVar3 = (int *)0x0;
      goto joined_r0x00541cdf;
    }
  }
LAB_00541ea1:
  local_8 = 0xffffffff;
  local_90[0] = TiXmlDocument::vftable;
  if (0xf < local_30) {
    FUN_0089120c(local_44);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
LAB_00541ee5:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
joined_r0x00541d99:
  if (piVar3 == (int *)0x0) goto LAB_00541ea1;
  iVar2 = (**(code **)(*piVar3 + 0x14))();
  if (iVar2 != 0) {
    iVar2 = FUN_007300a0("CATEGORY");
    if (iVar2 == 0) {
LAB_00541de9:
      local_94 = 6;
    }
    else {
      puVar4 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_00541de9;
      local_94 = FUN_008917b4(puVar4);
    }
    iVar2 = FUN_007300a0("PREFIX");
    if (iVar2 == 0) {
LAB_00541e1d:
      uVar5 = 1;
    }
    else {
      puVar4 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_00541e1d;
      uVar5 = FUN_008917b4(puVar4);
    }
    iVar2 = FUN_007300a0(&DAT_00bfb82c);
    if (iVar2 == 0) {
LAB_00541e4a:
      uVar6 = 0;
    }
    else {
      puVar4 = (undefined4 *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_00541e4a;
      uVar6 = FUN_008917b4(puVar4);
    }
    local_94 = ((uVar5 & 0xff) - 1 | (local_94 & 0xff) << 8) << 0x10 | uVar6 & 0xffff;
    FUN_00804260(&local_94);
  }
  piVar3 = (int *)FUN_0072e320(&DAT_00c0d83c);
  goto joined_r0x00541d99;
}

