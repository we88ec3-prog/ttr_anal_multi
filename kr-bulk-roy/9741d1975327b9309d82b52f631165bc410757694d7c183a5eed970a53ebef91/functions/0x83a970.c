
void FUN_0083a970(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_94 [4];
  undefined4 local_90 [16];
  undefined4 local_50 [17];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_94;
  if (*(int *)(in_ECX + 0xec) != 0) {
    FUN_0079c530();
    piVar1 = *(int **)(in_ECX + 0xec);
    puVar3 = local_90;
    puVar4 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    (**(code **)(*piVar1 + 0xb0))(piVar1,0x100,local_50);
  }
  __security_check_cookie(local_c ^ (uint)auStack_94);
  return;
}

