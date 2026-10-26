
undefined4 * FUN_00681af0(undefined4 *param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928bd3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0075af30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *param_1 = FUI::CShopTradeInsideClient::vftable;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_00757200(param_1 + 0x4a);
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x35] = 0xffffffff;
  param_1[0x33] = 0xffffffff;
  uVar2 = DAT_00fe5b2c & 1;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  if (uVar2 == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = 0xf0;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5b10) {
    FUN_00757710();
    local_18 = 0;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x55]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 1;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x55]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 2;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x55]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 3;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x55]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    ExceptionList = local_10;
    return param_1;
  }
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined4 *)(*pcVar1)();
  return puVar3;
}

