
void FUN_006f31c0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  local_14 = uVar1;
  FUN_006f3280(local_30,param_3,local_34);
  local_8 = 0;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - param_1 >> 1;
  }
  FUN_00498360(iVar2,local_30,0,0xffffffff);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

