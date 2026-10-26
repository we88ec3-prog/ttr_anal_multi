
int FUN_00872ae0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar1 = 0;
  iVar2 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  iVar3 = 1;
  local_8 = 0;
  if (1 < iVar2) {
    do {
      iVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 0x184) + iVar3 * 4) + 0x54))();
      iVar1 = local_8 + iVar1;
      iVar3 = iVar3 + 1;
      local_8 = iVar1;
    } while (iVar3 < iVar2);
  }
  return iVar1;
}

