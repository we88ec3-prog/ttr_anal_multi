
void FUN_006c5830(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_006ad0e0();
  iVar1 = *(int *)(*(int *)(in_ECX + 0xa8) + 0xcc);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0xe0) = 0;
  }
  return;
}

