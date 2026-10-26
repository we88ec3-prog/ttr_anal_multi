
void FUN_00497d40(int param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  short ****ppppsVar4;
  short ****ppppsVar5;
  int local_38;
  int local_34;
  short ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00930eb8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 0;
    local_38 = 0x12d;
    FUN_005740f0();
    if (local_34 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar3 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar3 = *(short **)psVar3;
    }
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    FUN_00404300();
  }
  if ((*(byte *)(param_1 + 2) & 4) != 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8._0_1_ = 0;
    }
    FUN_005740f0();
    if (local_38 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar3 = (short *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      psVar3 = *(short **)psVar3;
    }
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    FUN_00404300();
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8._0_1_ = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8._0_1_ = 0;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 4;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8._0_1_ = 0;
  }
  FUN_005740f0();
  if (local_38 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar3 = (short *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    psVar3 = *(short **)psVar3;
  }
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160();
  local_8._0_1_ = 5;
  ppppsVar5 = (short ****)local_30[0];
  if (local_1c < 8) {
    ppppsVar5 = local_30;
  }
  ppppsVar4 = ppppsVar5;
  do {
    sVar1 = *(short *)ppppsVar4;
    ppppsVar4 = (short ****)((int)ppppsVar4 + 2);
  } while (sVar1 != 0);
  FUN_00402160(ppppsVar5,(int)ppppsVar4 - (int)((int)ppppsVar5 + 2) >> 1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0058b270(0xca);
  if (7 < local_1c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

