
void FUN_0058cf70(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *in_ECX;
  int unaff_EDI;
  int local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = param_1;
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  psVar3 = in_ECX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_14 = uVar2;
  FUN_00402160(in_ECX,(int)psVar3 - (int)(in_ECX + 1) >> 1);
  local_8 = 0;
  FUN_00539110(&local_38);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30,uVar2);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  if (local_38 != *(int *)(unaff_EDI + 8)) {
    FUN_004026e0(local_38 + 0x28,0,0xffffffff);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

