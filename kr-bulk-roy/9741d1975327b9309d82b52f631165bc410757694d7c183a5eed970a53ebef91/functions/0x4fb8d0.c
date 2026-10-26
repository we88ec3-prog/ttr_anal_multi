
undefined4 FUN_004fb8d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    uVar1 = FUN_004fcbb0(*(int *)(in_ECX + 8));
    FUN_004fcc10(*(undefined4 *)(in_ECX + 8),in_ECX);
    *(undefined4 *)(in_ECX + 8) = uVar1;
  }
  return 1;
}

