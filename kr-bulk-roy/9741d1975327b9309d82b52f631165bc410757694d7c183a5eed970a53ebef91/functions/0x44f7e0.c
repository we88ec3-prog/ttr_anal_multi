
void FUN_0044f7e0(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  
  puStack_c = &LAB_0090de00;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x48) < 1) {
    iVar2 = in_ECX + 0x10;
  }
  else {
    iVar2 = in_ECX + 0x50 + *(int *)(in_ECX + 0x48) * 0x1c;
  }
  local_20 = 0;
  local_1c = 7;
  local_30 = local_30 & 0xffff0000;
  FUN_004026e0(iVar2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00736f40(&local_34);
  iVar2 = local_34;
  if (local_34 == *(int *)(in_ECX + 4)) {
    piVar1 = (int *)FUN_00736f40(&local_34);
    iVar2 = *piVar1;
  }
  iVar2 = *(int *)(iVar2 + 0x28);
  FUN_00736f40(&local_34);
  if (local_34 != *(int *)(iVar2 + 0x3c)) {
    iVar2 = *(int *)(local_34 + 0x28);
    *param_1 = *(undefined4 *)(iVar2 + 0x1c);
    param_1[1] = *(undefined4 *)(iVar2 + 0x20);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  local_30 = local_30 & 0xffff0000;
  local_20 = 0;
  local_1c = 7;
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

