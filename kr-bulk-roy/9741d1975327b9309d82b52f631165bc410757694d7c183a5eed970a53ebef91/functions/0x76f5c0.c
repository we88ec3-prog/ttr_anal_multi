
void FUN_0076f5c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xec);
  *(char *)(in_ECX + 0xf5) = (char)param_1;
  if (iVar1 != 0) {
    (**(code **)(**(int **)(iVar1 + 0x104) + 0x94))(param_1);
    (**(code **)(**(int **)(iVar1 + 0x108) + 0x94))(param_1);
  }
  return;
}

