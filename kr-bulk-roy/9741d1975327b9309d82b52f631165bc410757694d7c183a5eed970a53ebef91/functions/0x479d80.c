
void FUN_00479d80(undefined4 param_1)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  short *psVar4;
  undefined4 *in_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091b840;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  psVar2 = *(short **)*in_ECX;
  psVar4 = psVar2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  local_14 = uVar3;
  FUN_00404300(psVar2,(int)psVar4 - (int)(psVar2 + 1) >> 1);
  if (local_20 < (int)in_ECX[1]) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_8._0_1_ = 1;
    FUN_00402340(in_ECX[1] - local_20,in_ECX[2]);
    FUN_004041f0(local_30,0,0xffffffff);
    FUN_004026e0(local_4c,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0],uVar3);
    }
  }
  FUN_004041f0(local_30,0,0xffffffff);
  uVar5 = extraout_EDX;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
    uVar5 = extraout_EDX_00;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar5,param_1);
  return;
}

