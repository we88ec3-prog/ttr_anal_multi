
void FUN_00750920(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x1438);
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&stack0x00000004);
  if (*(int *)(unaff_EDI + 0x143c) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_EDI + 0x143c) = *(int *)(unaff_EDI + 0x143c) + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

