
int FUN_0083c500(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914193;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  iVar4 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_0083ff20(in_ECX + 0x144,param_1), iVar2 != 0)) {
    iVar3 = FUN_00891268(0x1d0,uVar1);
    local_c = 0;
    if (iVar3 != 0) {
      iVar4 = FUN_00854c30(iVar3);
    }
    local_c = 0xffffffff;
    FUN_0083ece0(&local_28,iVar2 + 0x20);
    local_c = 1;
    for (; local_28 != local_24; local_28 = local_28 + 0x10) {
      FUN_008558f0(local_28);
    }
    *(int *)(iVar4 + 0x16c) = param_1;
    local_c = 0xffffffff;
    FUN_0083f1b0(&local_28);
    ExceptionList = local_14;
    return iVar4;
  }
  ExceptionList = local_14;
  return 0;
}

