
void FUN_00606820(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00755e50();
  FUN_006ae700();
  FUN_006ae7f0();
  FUN_006069c0();
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0xe0) = 0;
  }
  return;
}

