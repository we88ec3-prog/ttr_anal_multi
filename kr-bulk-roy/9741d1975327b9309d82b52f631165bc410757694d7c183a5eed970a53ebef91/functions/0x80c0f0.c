
void FUN_0080c0f0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911698;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  iVar3 = FUN_0080c1c0(in_ECX);
  if (iVar3 != *(int *)(param_1 + 4)) {
    cVar1 = FUN_005436a0(uVar2);
    if (cVar1 == '\0') goto LAB_0080c190;
  }
  local_24 = 0xf;
  local_28 = 0;
  local_38[0] = local_38[0] & 0xffffff00;
  FUN_0040b0b0(in_ECX,0);
  local_1c = 0;
  local_8 = 0;
  uVar4 = FUN_005435c0(local_38);
  FUN_0080c6c0(iVar3,uVar4);
  if (0xf < local_24) {
    FUN_0089120c(local_38[0]);
  }
LAB_0080c190:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

