
undefined4 FUN_0064af10(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00912510;
  local_14 = ExceptionList;
  switch(param_1 + -1) {
  case 0:
  case 2:
    iVar1 = in_ECX[0x3e];
    ExceptionList = &local_14;
    FUN_007e8a90(&local_28,*(int *)(iVar1 + 0xa8) + 0x114);
    local_c = 0;
    iVar3 = FUN_00649250();
    if (iVar3 < 1) {
      iVar3 = local_24 - local_28 >> 2;
    }
    FUN_006491d0(iVar1,**(undefined4 **)(local_28 + -4 + iVar3 * 4));
    if (local_28 != 0) {
      FUN_0089120c(local_28);
    }
    break;
  case 1:
  case 3:
    iVar1 = in_ECX[0x3e];
    ExceptionList = &local_14;
    FUN_007e8a90(&local_28,*(int *)(iVar1 + 0xa8) + 0x114);
    local_c = 1;
    uVar2 = FUN_00649250();
    if (uVar2 < (local_24 - local_28 >> 2) - 1U) {
      iVar3 = uVar2 + 1;
    }
    else {
      iVar3 = 0;
    }
    FUN_006491d0(iVar1,**(undefined4 **)(local_28 + iVar3 * 4));
    if (local_28 != 0) {
      FUN_0089120c(local_28);
      ExceptionList = local_14;
      return 1;
    }
    break;
  default:
    if (param_1 != 0x2af9) {
      return 0;
    }
    ExceptionList = &local_14;
    (**(code **)(*in_ECX + 0xd4))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    ExceptionList = local_14;
    return 1;
  }
  ExceptionList = local_14;
  return 1;
}

