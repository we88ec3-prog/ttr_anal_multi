
void FUN_0050db70(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *in_EDX;
  undefined1 local_c8 [4];
  int local_c4;
  int local_c0;
  undefined1 local_bc [88];
  undefined2 local_64;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910523;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = FUN_0050e0a0(local_14);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0xc) <= *in_EDX) &&
       ((*(int *)(iVar1 + 0xc) < *in_EDX || (*(int *)(iVar1 + 0x10) <= in_EDX[1]))))
    goto LAB_0050dc58;
  }
  local_50 = 7;
  local_2c = 7;
  local_54 = 0;
  local_64 = 0;
  local_30 = 0;
  local_40 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_c4 = *in_EDX;
  local_c0 = in_EDX[1];
  FUN_0050e1a0(local_bc);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar2 = FUN_0050fd80(&local_c4);
  FUN_0050f170(in_ECX,local_c8,iVar1,uVar2);
  FUN_0050dde0();
  FUN_0050dde0();
LAB_0050dc58:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

