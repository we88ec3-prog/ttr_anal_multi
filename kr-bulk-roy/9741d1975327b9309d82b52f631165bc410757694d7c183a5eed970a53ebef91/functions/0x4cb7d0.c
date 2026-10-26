
void FUN_004cb7d0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0x15c);
  if ((iVar1 != 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x370) != 0)) {
    FUN_007a7cc0(iVar1,0);
    FUN_007a7bf0(0,0,0,0);
  }
  return;
}

