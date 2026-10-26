
void FUN_00601860(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 auStack_90 [16];
  undefined4 uStack_80;
  short *psStack_7c;
  int iStack_78;
  undefined2 local_74 [8];
  undefined4 local_64;
  undefined2 *local_60;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 *puStack_3c;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e83c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120();
    puStack_3c = (undefined4 *)0x6018b1;
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  puStack_3c = (undefined4 *)0x6018da;
  FUN_008438c0();
  if (local_20 == DAT_00f8d91c) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_20 + 0x10);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    puStack_3c = (undefined4 *)0x601914;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((double)*(int *)(iVar5 + 0x24) * 0.05 <= (double)DAT_00f94244) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 5;
      FUN_00587480();
      puStack_3c = (undefined4 *)0x601a5d;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puStack_3c = (undefined4 *)0x601a6b;
    puStack_3c = (undefined4 *)FUN_00891268();
    if (puStack_3c == (undefined4 *)0x0) {
      puStack_3c = (undefined4 *)0x0;
    }
    else {
      puStack_3c[1] = 0xffffffff;
      puStack_3c[2] = 0xffffffff;
      puStack_3c[3] = 0;
      puStack_3c[4] = 0xf4387;
      *puStack_3c = FoxUI::FXUIEventI2::vftable;
      puStack_3c[5] = param_2;
      puStack_3c[6] = param_3;
    }
    local_1c = (undefined1 *)local_58;
    local_44 = 7;
    local_48 = 0;
    local_60 = &DAT_00bed1fc;
    local_58[0] = 0;
    local_64 = 0x601ac1;
    FUN_00402160();
    local_c = 6;
    FUN_008fed10();
    local_20 = auStack_90;
    FUN_00412df0();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 8;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 7;
    local_20 = (undefined1 *)0xea;
    FUN_005740f0(&local_20);
    if (param_4 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar4 = (undefined4 *)(param_4 + 0x10);
    if (7 < *(uint *)(param_4 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    local_c = CONCAT31(local_c._1_3_,6);
    FUN_00424c80(puVar4);
    iStack_78 = 0xcf;
  }
  else {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 2;
      FUN_00587480();
      puStack_3c = (undefined4 *)0x60195d;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puStack_3c = (undefined4 *)0x0;
    local_1c = (undefined1 *)local_58;
    local_44 = 7;
    local_48 = 0;
    local_60 = &DAT_00bed1fc;
    local_58[0] = 0;
    local_64 = 0x60198a;
    FUN_00402160();
    local_c = 3;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      local_60 = (undefined2 *)0x6019b1;
      FUN_00584c40();
      local_60 = (undefined2 *)0x6019bb;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    local_20 = (undefined1 *)0xc;
    local_60 = (undefined2 *)0x6019de;
    FUN_005740f0();
    if (param_4 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psStack_7c = (short *)(param_4 + 0x10);
    if (7 < *(uint *)(param_4 + 0x24)) {
      psStack_7c = *(short **)psStack_7c;
    }
    local_20 = (undefined1 *)local_74;
    local_60 = (undefined2 *)0x7;
    local_64 = 0;
    local_74[0] = 0;
    psVar3 = psStack_7c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    iStack_78 = (int)psVar3 - (int)(psStack_7c + 1) >> 1;
    uStack_80 = 0x601a2c;
    FUN_00402160();
    iStack_78 = 0xca;
  }
  local_c = 0xffffffff;
  psStack_7c = (short *)0x601b8c;
  FUN_0058b270();
  ExceptionList = local_14;
  return;
}

