
undefined4 FUN_00873b80(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint local_c [2];
  
  local_c[0] = 0;
  FUN_00784fd0(param_1);
  if ((*(int *)(in_ECX + 0x30) != 0) && (uVar1 = *(uint *)(*(int *)(in_ECX + 0x30) + 4), uVar1 != 0)
     ) {
    local_c[0] = local_c[0] | uVar1;
  }
  if ((*(int *)(in_ECX + 0x38) != 0) && (iVar2 = *(int *)(*(int *)(in_ECX + 0x38) + 4), iVar2 != 0))
  {
    local_c[0] = local_c[0] | iVar2 << 8;
  }
  if ((*(int *)(in_ECX + 0x34) != 0) && (iVar2 = *(int *)(*(int *)(in_ECX + 0x34) + 4), iVar2 != 0))
  {
    local_c[0] = local_c[0] | iVar2 << 0x10;
  }
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_c,4,0);
  if (*(int *)(in_ECX + 0x30) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x30) + 0x10))(param_1);
  }
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0x10))(param_1);
  }
  if (*(int *)(in_ECX + 0x34) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x10))(param_1);
  }
  return 1;
}

