
void FUN_0044f640(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint in_stack_0000001c;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bc10;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x48) < 1) {
    iVar3 = in_ECX + 0x10;
  }
  else {
    iVar3 = in_ECX + 0x50 + *(int *)(in_ECX + 0x48) * 0x1c;
  }
  local_20 = 0;
  local_1c = 7;
  local_30 = local_30 & 0xffff0000;
  local_14 = uVar1;
  FUN_004026e0(iVar3,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00736f40(&local_34);
  iVar3 = local_34;
  if (local_34 == *(int *)(in_ECX + 4)) {
    piVar2 = (int *)FUN_00736f40(&local_34);
    iVar3 = *piVar2;
  }
  iVar3 = *(int *)(iVar3 + 0x28);
  FUN_00736f40(&local_34);
  if (local_34 == *(int *)(iVar3 + 0x4c)) {
    FUN_00736f40(&local_34);
    iVar3 = *(int *)(local_34 + 0x28);
    FUN_00736f40(&local_34);
    FUN_0044fa80(param_1,iVar3 + 0x1c,*(int *)(local_34 + 0x28) + 0x1c);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  else {
    FUN_0044fa80(param_1,iVar3 + 0x1c,*(int *)(local_34 + 0x28) + 0x1c,uVar1);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  local_30 = local_30 & 0xffff0000;
  local_20 = 0;
  local_1c = 7;
  if (7 < in_stack_0000001c) {
    local_1c = 7;
    local_20 = 0;
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

