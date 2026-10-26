
void FUN_00604d10(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xdc) != 0)) {
    FUN_00604a90(in_ECX);
    return;
  }
  FUN_00604a90(in_ECX);
  return;
}

