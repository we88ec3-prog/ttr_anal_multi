
undefined4 FUN_004b7950(undefined2 *param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  short *psVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined2 local_84 [8];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_58;
  short *psStack_54;
  int iStack_50;
  undefined2 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009308e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  param_1 = *(undefined2 **)((int)param_1 + 2);
  FUN_008438c0();
  if ((local_14 != DAT_00f8d91c) && (iVar2 = *(int *)(local_14 + 0x10), iVar2 != 0)) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 2;
      local_38 = 0x4b7a32;
      FUN_00584c40();
      local_38 = 0x4b7a3c;
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    param_1 = (undefined2 *)0x196;
    local_38 = 0x4b7a5a;
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    psStack_54 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psStack_54 = *(short **)psStack_54;
    }
    local_38 = 7;
    local_3c = 0;
    local_4c = 0;
    psVar4 = psStack_54;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    iStack_50 = (int)psVar4 - (int)(psStack_54 + 1) >> 1;
    uStack_58 = 0x4b7ab6;
    FUN_00402160();
    local_8 = 3;
    param_1 = local_84;
    local_70 = 7;
    local_74 = 0;
    local_84[0] = 0;
    FUN_004026e0(iVar2,0,0xffffffff);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 5;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 4;
    param_1 = (undefined2 *)0x1b9;
    FUN_005740f0(&param_1);
    if (iVar2 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    puVar5 = (undefined4 *)(iVar2 + 0x10);
    if (7 < *(uint *)(iVar2 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0043b280(puVar5);
    uStack_6c = 0xca;
    local_8 = 0xffffffff;
    local_70 = 0x4b7b78;
    FUN_0058b270();
  }
  ExceptionList = local_10;
  return 0;
}

