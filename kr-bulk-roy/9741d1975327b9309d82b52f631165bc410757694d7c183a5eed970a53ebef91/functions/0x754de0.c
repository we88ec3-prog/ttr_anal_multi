
void FUN_00754de0(int *param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  if (*(int *)(in_ECX + 0x150) != 0) {
    iVar1 = *(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa4);
    iVar2 = *(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xa8);
    local_18 = 0;
    local_14 = 0;
    local_10 = iVar1;
    local_c = iVar2;
    FUN_00758ea0(in_ECX + 0xe8,&local_28,&local_18,*(undefined4 *)(in_ECX + 0x120));
    if (-1 < local_28) {
      local_28 = 0;
    }
    if (local_20 <= iVar1) {
      local_20 = iVar1;
    }
    if (-1 < local_24) {
      local_24 = 0;
    }
    if (local_1c <= iVar2) {
      local_1c = iVar2;
    }
    *param_1 = local_28;
    param_1[1] = local_24;
    param_1[2] = local_20;
    param_1[3] = local_1c;
    return;
  }
  *param_1 = *(int *)(in_ECX + 0xa4);
  param_1[1] = *(int *)(in_ECX + 0xa8);
  iVar1 = *(int *)(in_ECX + 0xb0);
  param_1[2] = *(int *)(in_ECX + 0xac);
  param_1[3] = iVar1;
  return;
}

