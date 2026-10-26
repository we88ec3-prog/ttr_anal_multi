
void FUN_0074e480(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x1480);
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&stack0x00000004);
  if (*(int *)(unaff_EDI + 0x1484) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_EDI + 0x1484) = *(int *)(unaff_EDI + 0x1484) + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

