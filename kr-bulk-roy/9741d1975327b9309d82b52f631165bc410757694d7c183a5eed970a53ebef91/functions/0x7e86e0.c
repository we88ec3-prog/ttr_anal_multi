
void FUN_007e86e0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_98 [80];
  undefined4 local_48;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914813;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  iVar3 = FUN_007e8a00(param_1);
  if ((iVar3 == *(int *)(in_ECX + 4)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_48 = 0;
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_8 = 0;
    FUN_007e9380(local_98,param_1,&local_48);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = FUN_007e92b0(local_98);
    FUN_007e8e90(iVar3,uVar4);
    FUN_007e8840();
    if (local_28 != 0) {
      FUN_0089120c(local_28);
    }
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

