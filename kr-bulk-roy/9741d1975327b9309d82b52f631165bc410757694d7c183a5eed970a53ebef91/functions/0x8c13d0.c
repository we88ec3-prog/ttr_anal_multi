
void FUN_008c13d0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x20) != 0 || *(int *)(unaff_ESI + 0x24) != 0) {
    iVar1 = FUN_008c1360();
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(unaff_ESI + 0x20);
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(unaff_ESI + 0x24);
  }
  return;
}

