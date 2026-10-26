
void FUN_0058ef10(int param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *in_ECX;
  undefined4 in_EDX;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931b88;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_30 = local_30 & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  psVar3 = in_ECX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_34 = in_EDX;
  local_14 = uVar2;
  FUN_00402160(in_ECX,(int)psVar3 - (int)(in_ECX + 1) >> 1);
  local_8 = 0;
  FUN_0058f3c0(&local_3c);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30,uVar2);
  }
  local_30 = local_30 & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  if (local_3c != *(int *)(param_1 + 0x48)) {
    FUN_0058cf70(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

