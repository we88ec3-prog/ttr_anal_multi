
void FUN_004cd0a0(void)

{
  uint uVar1;
  int iVar2;
  int local_50;
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
  puStack_c = &LAB_0091b58c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = 0;
  DAT_00fe1bcc = 0;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_14 = uVar1;
  FUN_00402160(L"UI/ImageSets/TeamRankIcon_32.dds",0x20);
  local_8 = 0;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00736880(uVar1);
    _atexit(FUN_00bce6f0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  DAT_00fe1bcc = FUN_00736b00(local_30);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (DAT_00fe1bcc == 0) {
    local_38 = 7;
    local_3c = 0;
    local_4c = local_4c & 0xffff0000;
    FUN_00402160(L"UI/ImageSets/TeamRankIcon_32.dds",0x20);
    local_8 = 2;
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    FUN_00736f40(&local_50);
    if (local_50 != DAT_00fcde34) {
      (**(code **)(**(int **)(local_50 + 0x28) + 4))();
      iVar2 = *(int *)(local_50 + 0x28);
    }
    DAT_00fe1bcc = iVar2;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

