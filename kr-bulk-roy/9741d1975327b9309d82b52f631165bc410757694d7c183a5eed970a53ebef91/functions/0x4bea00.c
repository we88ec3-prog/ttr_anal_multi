
undefined4 FUN_004bea00(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930808;
  local_10 = ExceptionList;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\x01') {
    ExceptionList = &local_10;
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
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar2 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar2 != 0);
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
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    psVar6 = psVar4;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
  }
  else if (cVar1 == '\a') {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 5;
    iVar7 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar7 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    psVar6 = psVar4;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
  }
  else {
    if (cVar1 == '\0') {
      ExceptionList = &local_10;
      FUN_004054c0();
      FUN_00402250();
      local_8 = 6;
    }
    else {
      if (cVar1 != '\t') {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      FUN_00402250();
      local_8 = 7;
    }
    FUN_005854b0();
    uVar5 = FUN_00585330();
    FUN_00402250(uVar5);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return 0;
}

