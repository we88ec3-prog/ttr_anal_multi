
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e8d00(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  short *psVar6;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00930136;
  local_14 = ExceptionList;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    ExceptionList = &local_14;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    local_c = 0xffffffff;
    FUN_004f6950();
    FUN_004ec270();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    FUN_005740f0();
    if (local_28 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar6 = (short *)(local_28 + 0x10);
    if (7 < *(uint *)(local_28 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160();
    local_c._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 5;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 3;
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x197) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    FUN_004f6a30();
    FUN_004ed610();
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    if (*(int *)(in_ECX + 0x5ec0) != 0) {
      FUN_004ed410();
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 6;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_0058ab80();
    ExceptionList = local_14;
    return 1;
  }
  if (cVar1 == '\x01') {
    ExceptionList = &local_14;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 7;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    local_c = 0xffffffff;
    FUN_004f6950();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 8;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    iVar5 = FUN_005854b0();
    FUN_005740f0();
    if (local_24 == *(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar6 = (short *)(local_24 + 0x10);
    if (7 < *(uint *)(local_24 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160();
    local_c = 9;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c._0_1_ = 10;
      local_c._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = CONCAT31(local_c._1_3_,9);
    }
    iVar5 = FUN_005854b0();
    FUN_005740f0();
    if (local_24 == *(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    FUN_004f6a30();
    FUN_004ed610();
  }
  else {
    if (cVar1 == '\x02') {
      ExceptionList = &local_14;
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 0xb;
    }
    else if (cVar1 == '\x03') {
      ExceptionList = &local_14;
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 0xc;
    }
    else if (cVar1 == '\x04') {
      ExceptionList = &local_14;
      FUN_00425330();
      FUN_004f6950();
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 0xd;
    }
    else if (cVar1 == '\x05') {
      ExceptionList = &local_14;
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 0xe;
    }
    else {
      if (cVar1 != '\x06') {
        return 0;
      }
      ExceptionList = &local_14;
      FUN_004054c0();
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 0xf;
    }
    FUN_005854b0();
    uVar4 = FUN_00585330();
    FUN_00402250(uVar4);
  }
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_14;
  return 0;
}

