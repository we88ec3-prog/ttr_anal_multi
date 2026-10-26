
undefined4 FUN_00495c50(int param_1)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  short *psVar4;
  short *psVar5;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931102;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 2) == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8 = 0xffffffff;
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8 = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    psVar4 = (short *)(local_14 + 0x10);
    psVar5 = psVar4;
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
      psVar5 = psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
  }
  else {
    if (*(int *)(param_1 + 2) != 1) goto LAB_00495f7d;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 5;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8 = 0xffffffff;
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8 = 6;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 7;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,6);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    psVar4 = (short *)(local_14 + 0x10);
    psVar5 = psVar4;
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
      psVar5 = psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_00495f7d:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 8;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058afa0();
  ExceptionList = local_10;
  return 1;
}

