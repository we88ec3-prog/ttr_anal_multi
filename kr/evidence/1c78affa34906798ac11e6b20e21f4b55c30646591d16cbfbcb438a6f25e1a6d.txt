
int FUN_0053e690(void)

{
  int iVar1;
  int unaff_ESI;
  int local_8;
  
  FUN_008438c0(&stack0x00000004);
  if (local_8 != *(int *)(unaff_ESI + 4)) {
    iVar1 = *(int *)(local_8 + 0x10);
    if (*(int *)(iVar1 + 0x48) == 0) {
      FUN_0053e120();
    }
    *(int *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + 1;
    return iVar1;
  }
  return 0;
}

