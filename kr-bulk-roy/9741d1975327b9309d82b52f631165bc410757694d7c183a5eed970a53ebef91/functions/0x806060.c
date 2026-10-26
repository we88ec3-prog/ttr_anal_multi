
undefined4 FUN_00806060(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(unaff_ESI + 0xa0d4));
  iVar1 = *(int *)(unaff_ESI + 0xa074);
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&stack0x00000004);
  if (*(int *)(unaff_ESI + 0xa078) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_ESI + 0xa078) = *(int *)(unaff_ESI + 0xa078) + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_ESI + 0xa0d4));
  *(undefined1 *)(unaff_ESI + 0xa024) = 1;
  return 1;
}

