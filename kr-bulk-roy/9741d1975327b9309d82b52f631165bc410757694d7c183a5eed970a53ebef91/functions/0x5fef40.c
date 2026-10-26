
undefined4 * FUN_005fef40(undefined4 *param_1)

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
  puStack_c = &LAB_00928f23;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x42] = 0xffffffff;
  param_1[0x43] = 0xffffffff;
  local_8 = 0;
  *param_1 = FUI::CInventoryInsideWindow::vftable;
  FUN_00757200(param_1 + 0x45);
  local_8._0_1_ = 1;
  *(undefined2 *)(param_1 + 0x56) = 0;
  param_1[0x5c] = 7;
  param_1[0x5b] = 0;
  *(undefined2 *)(param_1 + 0x57) = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  uVar2 = DAT_00fe5b2c & 1;
  param_1[0x44] = 0;
  if (uVar2 == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = 0xf1;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5b10) {
    FUN_00757710();
    local_18 = 0;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x50]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 1;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x50]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 2;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x50]) {
      *(undefined4 *)(local_14 + 0x18) = 0xffc3c27c;
      *(undefined1 *)(local_14 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_14 + 0x10),*(int *)(local_14 + 0x14) - *(int *)(local_14 + 0x10),
                   0xffc3c27c);
    }
    local_18 = 3;
    FUN_00848020(&local_18);
    if (local_14 != param_1[0x50]) {
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

