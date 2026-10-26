
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e9a00(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ff94;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
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
    if (local_18 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160();
    local_8._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 4;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 2;
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x197) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    FUN_004f6a30();
    FUN_004ed610();
  }
  else if (cVar1 == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    iVar5 = FUN_005854b0();
    FUN_005740f0();
    if (local_18 == *(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160();
    local_8 = 6;
    iVar5 = FUN_005854b0();
    FUN_005740f0();
    if (local_18 == *(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar7 = psVar6;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
  }
  else {
    if (cVar1 == '\x02') {
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 7;
    }
    else {
      if (cVar1 != '\x03') goto LAB_004e9d8e;
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 8;
    }
    FUN_005854b0();
    uVar4 = FUN_00585330();
    FUN_00402250(uVar4);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004e9d8e:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 9;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0();
  ExceptionList = local_10;
  return 0;
}

