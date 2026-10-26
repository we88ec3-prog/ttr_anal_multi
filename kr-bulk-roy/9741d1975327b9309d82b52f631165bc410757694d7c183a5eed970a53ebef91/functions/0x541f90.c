
void FUN_00541f90(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int *_Str1;
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
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    iVar3 = FUN_0072e2e0("PRELOADLIST");
    if (iVar3 == 0) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44,uVar2);
      }
      local_30 = 0xf;
      local_34 = 0;
      local_44 = local_44 & 0xffffff00;
      FUN_0072e040();
      goto LAB_005421e7;
    }
    piVar4 = (int *)FUN_0072e2e0("Preload");
joined_r0x0054206e:
    if (piVar4 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar4 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0("Category");
        if (iVar3 == 0) {
LAB_005420c7:
          local_94 = 1;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_005420c7;
          local_94 = FUN_008917b4(puVar5);
        }
        iVar3 = FUN_007300a0("Prefix");
        if (iVar3 == 0) {
LAB_005420fa:
          uVar6 = 1;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_005420fa;
          uVar6 = FUN_008917b4(puVar5);
        }
        iVar3 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar3 == 0) {
LAB_00542127:
          uVar7 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_00542127;
          uVar7 = FUN_008917b4(puVar5);
        }
        local_94 = ((uVar6 & 0xff) - 1 | (local_94 & 0xff) << 8) << 0x10 | uVar7 & 0xffff;
        FUN_00804260(&local_94);
      }
      for (piVar4 = (int *)piVar4[0x10]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
        _Str1 = piVar4 + 8;
        if (0xf < (uint)piVar4[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"Preload");
        if (iVar3 == 0) goto joined_r0x0054206e;
      }
      piVar4 = (int *)0x0;
      goto joined_r0x0054206e;
    }
  }
  local_8 = 0xffffffff;
  local_90[0] = TiXmlDocument::vftable;
  if (0xf < local_30) {
    FUN_0089120c(local_44,uVar2);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
LAB_005421e7:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

