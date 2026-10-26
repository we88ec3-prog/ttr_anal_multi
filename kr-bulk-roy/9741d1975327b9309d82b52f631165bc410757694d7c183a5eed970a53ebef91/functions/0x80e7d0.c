
undefined4 FUN_0080e7d0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x18) != 0) && (*(int *)(in_ECX + 0x1c) != 0)) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))();
    if ((iVar1 == 0) && ((*(int *)(in_ECX + 4) == 0 && (*(int *)(in_ECX + 8) == 0)))) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
      (**(code **)(**(int **)(in_ECX + 0x14) + 8))();
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))(*(undefined4 *)(in_ECX + 0x10));
      if (iVar1 != 0) {
        (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))();
        (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))();
        (**(code **)(**(int **)(in_ECX + 0x14) + 0x20))(*(undefined4 *)(in_ECX + 0x20));
        FUN_0080e8d0();
      }
    }
  }
  return 0;
}

