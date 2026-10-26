
undefined4 * FUN_0086e370(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int local_1c;
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091c206;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[0xf] = 0;
  param_1[2] = 7;
  param_1[0xe] = 1;
  puVar3 = DAT_00fe34d8;
  local_8 = 0;
  *param_1 = gbDxEffectScriptCommandsRenderColorTarget::vftable;
  if (puVar3 == (undefined *)0x0) {
    if ((DAT_00fe3480 & 1) == 0) {
      DAT_00fe3480 = DAT_00fe3480 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00862d10(uVar1);
      _atexit((_func_4879 *)&LAB_00bd0e20);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    puVar3 = &DAT_00fe3488;
    DAT_00fe34d8 = &DAT_00fe3488;
  }
  local_18[0] = 7;
  FUN_008438c0(local_18);
  if (local_1c == *(int *)(puVar3 + 0x44)) {
    uVar2 = FUN_0057ef20();
    FUN_0057e850(puVar3 + 0x40,uVar2);
  }
  ExceptionList = local_10;
  return param_1;
}

