
undefined4 FUN_00557180(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if ((*(int *)(in_ECX + 8) != 0) && (iVar2 = *(int *)(in_ECX + 0x10), -1 < iVar2)) {
    iVar1 = **(int **)(in_ECX + 4);
    if (0 < iVar2) {
      do {
        FUN_0049e6a0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    return **(undefined4 **)(iVar1 + 0x10);
  }
  return 0;
}

