
/* WARNING: Removing unreachable block (ram,0x0053cd2f) */

void FUN_0053c9a0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  short ****ppppsVar5;
  undefined4 uVar6;
  int local_54;
  int local_50;
  short ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092f11c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    break;
  case 1:
    goto LAB_0053ca19;
  case 2:
    break;
  case 3:
    goto LAB_0053ca19;
  case 4:
    break;
  case 5:
LAB_0053ca19:
    FUN_005855b0();
    FUN_00585330();
    goto LAB_0053ca29;
  default:
    goto switchD_0053c9ec_default;
  }
  FUN_005855b0();
  FUN_00585330();
LAB_0053ca29:
  FUN_0041f490();
switchD_0053c9ec_default:
  if (*(char *)(param_1 + 3) == '\0') {
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8._0_1_ = 1;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    FUN_005740f0();
    if (local_50 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_50 + 0x24) < 8) {
      psVar4 = (short *)(local_50 + 0x10);
    }
    else {
      psVar4 = *(short **)(local_50 + 0x10);
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    goto switchD_0053cb97_default;
  }
  if (*(char *)(param_1 + 3) == '\n') {
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (local_54 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_54 + 0x24) < 8) {
      psVar4 = (short *)(local_54 + 0x10);
    }
    else {
      psVar4 = *(short **)(local_54 + 0x10);
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    goto switchD_0053cb97_default;
  }
  iVar3 = FUN_005855b0();
  FUN_005740f0();
  if (local_54 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar4 = (short *)(local_54 + 0x10);
  if (7 < *(uint *)(local_54 + 0x24)) {
    psVar4 = *(short **)psVar4;
  }
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00404300();
  switch(*(undefined1 *)(param_1 + 3)) {
  case 1:
    goto LAB_0053cbe0;
  case 2:
    break;
  case 3:
    FUN_005855b0();
    FUN_00585330();
    FUN_00404420();
    goto switchD_0053cb97_default;
  case 4:
    break;
  case 5:
    goto LAB_0053cbe0;
  case 6:
    break;
  case 7:
LAB_0053cbe0:
    FUN_005855b0();
    FUN_00585330();
    FUN_00404420();
    goto switchD_0053cb97_default;
  case 8:
    break;
  case 9:
    if (*(char *)(param_1 + 2) == '\x04') {
      local_8._0_1_ = 2;
      FUN_00425330();
      FUN_004f6b20();
      FUN_004054c0();
      FUN_00402250();
      local_8._0_1_ = 3;
      uVar6 = 0x123;
      FUN_005854b0(0x123);
      FUN_00585330(uVar6);
      FUN_004ed610();
      local_8._0_1_ = 2;
      FUN_0058b270(0xca);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004fa440();
    }
  default:
    goto switchD_0053cb97_default;
  }
  FUN_005855b0();
  FUN_00585330();
  FUN_00404420();
switchD_0053cb97_default:
  ppppsVar5 = (short ****)local_30[0];
  if (local_1c < 8) {
    ppppsVar5 = local_30;
  }
  do {
    sVar1 = *(short *)ppppsVar5;
    ppppsVar5 = (short ****)((int)ppppsVar5 + 2);
  } while (sVar1 != 0);
  FUN_00402160();
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8._0_1_ = 5;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004d6b30();
  if (7 < local_1c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

