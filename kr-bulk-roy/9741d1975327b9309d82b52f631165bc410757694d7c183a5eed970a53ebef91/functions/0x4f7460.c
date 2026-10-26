
void FUN_004f7460(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *_Str1;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_ec;
  undefined **local_e4 [19];
  uint local_98;
  undefined4 local_88;
  uint local_84;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009245ab;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  FUN_0072ee30(local_e4);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 != '\0') {
    FUN_0072e360(uVar3);
    iVar4 = FUN_0072e360();
    while (iVar4 != 0) {
      for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
        _Str1 = (char *)(iVar1 + 0x14);
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          _Str1 = *(char **)_Str1;
        }
        iVar5 = __stricmp(_Str1,"SPECIES");
        if (iVar5 == 0) {
          if (iVar1 != 0) {
            puVar7 = (undefined4 *)(iVar1 + 0x30);
            if (0xf < *(uint *)(iVar1 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 != (undefined4 *)0x0) {
              local_ec = FUN_008917b4(puVar7);
              goto LAB_004f7551;
            }
          }
          break;
        }
      }
      local_ec = 0;
LAB_004f7551:
      local_3c = 7;
      local_40 = 0;
      local_50[0] = local_50[0] & 0xffff0000;
      local_8._0_1_ = 1;
      local_58 = 0xf;
      local_5c = 0;
      local_6c = local_6c & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 2;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00440130(uVar6);
      if (0xf < local_1c) {
        FUN_0089120c(local_30);
      }
      local_8._0_1_ = 1;
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      if (0xf < local_58) {
        FUN_0089120c(local_6c);
      }
      local_34 = local_ec;
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      FUN_004026e0(local_50,0,0xffffffff);
      local_8._0_1_ = 4;
      uVar6 = FUN_005063f0(&local_34);
      FUN_00480690(&DAT_00fb7480,uVar6);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      iVar4 = FUN_0072e3c0();
      if (7 < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_3c = 7;
      local_40 = 0;
      local_50[0] = local_50[0] & 0xffff0000;
    }
  }
  local_8 = 0xffffffff;
  local_e4[0] = TiXmlDocument::vftable;
  if (0xf < local_84) {
    FUN_0089120c(local_98);
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = local_98 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

