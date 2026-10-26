
undefined4 * FUN_0086fbd0(undefined4 *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int local_20;
  undefined4 local_1c;
  undefined *local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091c146;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[0xf] = 0;
  param_1[2] = 0x10;
  param_1[0xe] = 1;
  puVar4 = DAT_00fe34d8;
  local_8 = 0;
  *param_1 = gbDxEffectScriptCommandsClear::vftable;
  if (puVar4 == (undefined *)0x0) {
    if ((DAT_00fe3480 & 1) == 0) {
      DAT_00fe3480 = DAT_00fe3480 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00862d10(uVar2);
      _atexit((_func_4879 *)&LAB_00bd0e20);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    puVar4 = &DAT_00fe3488;
    DAT_00fe34d8 = &DAT_00fe3488;
  }
  local_18 = puVar4 + 0x40;
  local_1c = 0x10;
  FUN_008438c0(&local_1c);
  puVar1 = local_18;
  if (local_20 == *(int *)(puVar4 + 0x44)) {
    uVar3 = FUN_0057ef20();
    FUN_0057e850(puVar1,uVar3);
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  ExceptionList = local_10;
  return param_1;
}

