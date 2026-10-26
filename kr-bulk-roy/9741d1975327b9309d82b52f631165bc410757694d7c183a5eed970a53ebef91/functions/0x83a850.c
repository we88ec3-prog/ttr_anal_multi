
void FUN_0083a850(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_94;
  undefined4 local_90 [16];
  undefined4 local_50 [17];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_94;
  piVar1 = *(int **)(in_ECX + 0xec);
  if (piVar1 != (int *)0x0) {
    local_94 = in_ECX;
    FUN_0079c530();
    puVar3 = local_90;
    puVar4 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    (**(code **)(*piVar1 + 0xb0))(piVar1,2,local_50);
    puVar3 = (undefined4 *)(local_94 + 0x98);
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_94);
  return;
}

