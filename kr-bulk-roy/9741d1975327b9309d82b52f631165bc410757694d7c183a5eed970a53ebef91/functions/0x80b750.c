
void FUN_0080b750(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  undefined1 local_40 [4];
  int local_3c;
  int local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009116c8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0x3c);
  local_14 = uVar3;
  local_38 = FUN_0080c1c0(in_ECX);
  if ((local_38 == *(int *)(param_1 + 0x3c)) || (cVar2 = FUN_005436a0(uVar3), cVar2 != '\0')) {
    local_3c = *(int *)(param_1 + 0x3c);
    piVar4 = &local_3c;
  }
  else {
    piVar4 = &local_38;
  }
  if (*piVar4 == iVar1) {
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    FUN_0040b0b0(in_ECX,0);
    local_18 = param_2;
    local_8 = 0;
    uVar5 = FUN_005435c0(local_34);
    FUN_00574b80(param_1 + 0x38,local_40,uVar5);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

