
undefined4 * FUN_006bce70(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a7b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FUI::CScenarioTalkBox::vftable;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_006f4380();
    _atexit((_func_4879 *)&LAB_00bce6d0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  uVar1 = FUN_006bda20(local_14,&DAT_00fdf3c8);
  uVar1 = FUN_006bdb00(uVar1);
  uVar1 = FUN_006bdba0(uVar1);
  uVar1 = FUN_006bdc40(uVar1);
  uVar1 = FUN_006bdce0(uVar1);
  FUN_006bdd80(uVar1);
  ExceptionList = local_10;
  return param_1;
}

