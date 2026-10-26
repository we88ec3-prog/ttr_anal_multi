
void FUN_005a7530(void)

{
  int iVar1;
  DWORD DVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb4);
  if (((iVar1 != 0) && (*(char *)(iVar1 + 0xa8) == '\0')) && (*(int *)(iVar1 + 0x9c) != 0)) {
    DVar2 = timeGetTime();
    if (0x5dc < DVar2 - *(int *)(iVar1 + 0xa4)) {
      FUN_006bd400();
    }
  }
  return;
}

