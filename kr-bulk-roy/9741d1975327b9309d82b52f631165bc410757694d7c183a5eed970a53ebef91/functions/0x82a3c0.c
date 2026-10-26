
void FUN_0082a3c0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  uint local_fc;
  uint local_e8;
  uint local_e0;
  uint local_cc;
  undefined **local_c4 [19];
  uint local_78;
  undefined4 local_68;
  uint local_64;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925c61;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_004803c0(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_0072ee30(local_c4);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e360(uVar2), iVar3 != 0)) {
    iVar3 = FUN_0072e360(uVar2);
    while (iVar3 != 0) {
      iVar3 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar3 == 0) {
LAB_0082a4e3:
        iVar3 = -1;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0082a4e3;
        iVar3 = FUN_008917b4(puVar4);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffff0000;
      local_8._0_1_ = 1;
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 2;
      uVar5 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00440130(uVar5);
      if (0xf < local_cc) {
        FUN_0089120c(local_e0);
      }
      local_8._0_1_ = 1;
      local_cc = 0xf;
      local_e0 = local_e0 & 0xffffff00;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      if (0 < iVar3) {
        uVar5 = FUN_0082a710(local_30);
        local_8._0_1_ = 4;
        uVar5 = FUN_005063f0(uVar5);
        FUN_00506030(in_ECX,uVar5);
        if (7 < local_e8) {
          FUN_0089120c(local_fc);
        }
        local_e8 = 7;
        local_fc = local_fc & 0xffff0000;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_30[0] = local_30[0] & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      iVar3 = FUN_0072e3c0();
    }
  }
  local_c4[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_64) {
    local_8 = 0xffffffff;
    local_c4[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_78);
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = local_78 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

