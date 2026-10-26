
void FUN_007b1a20(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint local_40 [4];
  undefined4 local_30;
  uint local_2c;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cb78;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  iVar3 = FUN_00856250(param_1);
  if (iVar3 != *(int *)(in_ECX + 4)) {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 == '\0') goto LAB_007b1b06;
  }
  local_8 = 0;
  local_2c = 0xf;
  local_30 = 0;
  local_40[0] = local_40[0] & 0xffffff00;
  FUN_00403040(param_1,0,0xffffffff);
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  uVar4 = FUN_007b2aa0(local_40);
  FUN_007b2680(iVar3,uVar4);
  if (local_24 != 0) {
    FUN_007b2be0(param_1);
    FUN_0089120c(local_24);
  }
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (0xf < local_2c) {
    FUN_0089120c(local_40[0]);
  }
LAB_007b1b06:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

