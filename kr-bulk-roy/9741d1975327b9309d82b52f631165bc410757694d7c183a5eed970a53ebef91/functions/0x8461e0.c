
undefined4 FUN_008461e0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x74) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 8))(), iVar1 == 0)) {
    return 0;
  }
  if ((*(int **)(in_ECX + 0x78) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 8))(), iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x24);
}

