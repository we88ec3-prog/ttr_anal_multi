
void FUN_008d8190(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_008b97e0();
  if (iVar1 == 0) {
    iVar1 = FUN_008bacd0();
    if (iVar1 == 0) {
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + *(int *)(unaff_ESI + 0x48) * 0x10000
      ;
    }
  }
  return;
}

