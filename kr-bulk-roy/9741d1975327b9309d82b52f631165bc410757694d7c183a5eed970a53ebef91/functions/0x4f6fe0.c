
void FUN_004f6fe0(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *_Str1;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_e8;
  undefined **local_e4 [19];
  uint local_98;
  undefined4 local_88;
  uint local_84;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924603;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  FUN_0072ee30(local_e4);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') {
    local_8 = 0xffffffff;
    local_e4[0] = TiXmlDocument::vftable;
    if (0xf < local_84) {
      FUN_0089120c(local_98);
    }
  }
  else {
    FUN_0072e360(uVar3);
    iVar4 = FUN_0072e360();
    while (iVar4 != 0) {
      for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
        _Str1 = (char *)(iVar1 + 0x14);
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          _Str1 = *(char **)_Str1;
        }
        iVar5 = __stricmp(_Str1,"Index");
        if (iVar5 == 0) {
          if (iVar1 != 0) {
            puVar7 = (undefined4 *)(iVar1 + 0x30);
            if (0xf < *(uint *)(iVar1 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 != (undefined4 *)0x0) {
              local_e8 = FUN_008917b4(puVar7);
              goto LAB_004f70e2;
            }
          }
          break;
        }
      }
      local_e8 = 0;
LAB_004f70e2:
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      FUN_00402a70(&DAT_00c0d66c,4);
      local_8._0_1_ = 1;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8._0_1_ = 3;
      if (0xf < local_1c) {
        FUN_0089120c(local_30);
      }
      local_50 = local_e8;
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_00403040(local_6c,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,4);
      uVar6 = FUN_004f98b0(&local_50);
      FUN_004f8eb0(&DAT_00fb7520,uVar6);
      iVar4 = FUN_0072e3c0();
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_8 = local_8 & 0xffffff00;
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      if (0xf < local_58) {
        FUN_0089120c(local_6c[0]);
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = local_6c[0] & 0xffffff00;
    }
    local_8 = 0xffffffff;
    local_e4[0] = TiXmlDocument::vftable;
    if (0xf < local_84) {
      FUN_0089120c(local_98);
    }
  }
  local_88 = 0;
  local_84 = 0xf;
  local_98 = local_98 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

