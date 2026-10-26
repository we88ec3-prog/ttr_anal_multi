
void FUN_006f38a0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_108 [64];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(**(int **)(in_ECX + 4) + 100))(*(int **)(in_ECX + 4));
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))(*(int **)(in_ECX + 4),0x100,local_108);
  if (iVar1 < 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(*(int **)(in_ECX + 4));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(in_ECX + 4) + 100))(*(int **)(in_ECX + 4));
      iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))(*(int **)(in_ECX + 4),0x100,local_108);
      if (-1 < iVar1) goto LAB_006f3925;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_006f3925:
  puVar2 = local_108;
  puVar3 = (undefined4 *)(in_ECX + 8);
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

