
void FUN_00778930(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 local_a0 [5];
  uint local_8c;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_009213eb;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = 0;
  if (param_1 != 0) {
    FUN_00756010(in_ECX + 0x2ec,local_14);
    local_84[0] = local_84[0] & 0xffff0000;
    local_70 = 7;
    local_74 = 0;
    FUN_00402160(L"ImageSet",8);
    local_8 = 0;
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    FUN_00402160(L"Rect",4);
    local_8._0_1_ = 1;
    do {
      FUN_0040ef80();
      local_8._0_1_ = 2;
      FUN_0044fa80(local_68,local_84,local_a0);
      local_8._0_1_ = 3;
      FUN_0044fa80(local_4c,&local_30,local_a0);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_00776810(param_1);
      FUN_00755d10(param_1);
      if (7 < local_38) {
        FUN_0089120c(local_4c[0]);
      }
      local_38 = 7;
      local_3c = 0;
      local_4c[0] = local_4c[0] & 0xffff0000;
      if (7 < local_54) {
        FUN_0089120c(local_68[0]);
      }
      local_8._0_1_ = 1;
      local_54 = 7;
      local_58 = 0;
      local_68[0] = local_68[0] & 0xffff0000;
      if (7 < local_8c) {
        FUN_0089120c(local_a0[0]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 9);
    FUN_00755d10(param_1);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_70) {
      FUN_0089120c(local_84[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

