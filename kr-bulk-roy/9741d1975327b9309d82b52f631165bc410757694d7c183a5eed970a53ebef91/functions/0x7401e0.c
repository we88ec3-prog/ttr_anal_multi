
undefined4 FUN_007401e0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((0 < *(int *)(in_ECX + 4)) &&
     (iVar1 = *(int *)(in_ECX + 4) + -1, *(int *)(in_ECX + 4) = iVar1, iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 4);
}

