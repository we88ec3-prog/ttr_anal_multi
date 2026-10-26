
undefined4 FUN_0080eb30(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 4) = 0;
  while (iVar1 != 0) {
    Sleep(10);
    iVar1 = *(int *)(in_ECX + 8);
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))();
  if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x10))();
    if (*(int *)(in_ECX + 0x10) != 0) {
      FUN_0089120c(*(int *)(in_ECX + 0x10));
      *(undefined4 *)(in_ECX + 0x10) = 0;
    }
  }
  return 0;
}

