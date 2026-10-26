
undefined4 FUN_0083b010(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  if (*param_2 == 0) {
    (**(code **)(**(int **)(in_ECX + 0xec) + 0x104))(*(int **)(in_ECX + 0xec),param_1,0);
    return 0;
  }
  puVar1 = (undefined4 *)FUN_0083eb10();
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xec) + 0x104))
                      (*(int **)(in_ECX + 0xec),param_1,*puVar1);
    if (-1 < iVar2) {
      return 1;
    }
  }
  (**(code **)(**(int **)(in_ECX + 0xec) + 0x104))(*(int **)(in_ECX + 0xec),param_1,0);
  return 0;
}

