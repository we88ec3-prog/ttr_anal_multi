
undefined4 * FUN_0086f050(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_1c;
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c191;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[0xf] = 0;
  param_1[2] = 0xb;
  param_1[0xe] = 1;
  *param_1 = gbDxEffectScriptCommandsMultiPass::vftable;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  local_8 = 1;
  if (DAT_00fe34d8 == (undefined *)0x0) {
    if ((DAT_00fe3480 & 1) == 0) {
      DAT_00fe3480 = DAT_00fe3480 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_00862d10(uVar3);
      _atexit((_func_4879 *)&LAB_00bd0e20);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    DAT_00fe34d8 = &DAT_00fe3488;
  }
  puVar2 = DAT_00fe34d8;
  local_18[0] = 0xb;
  puVar1 = DAT_00fe34d8 + 0x40;
  FUN_008438c0(local_18);
  if (local_1c == *(int *)(puVar2 + 0x44)) {
    uVar4 = FUN_0057ef20();
    FUN_0057e850(puVar1,uVar4);
  }
  ExceptionList = local_10;
  return param_1;
}

