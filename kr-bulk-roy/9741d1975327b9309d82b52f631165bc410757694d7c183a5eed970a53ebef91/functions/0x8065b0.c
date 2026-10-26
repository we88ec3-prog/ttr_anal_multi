
undefined4 FUN_008065b0(void)

{
  LONG *lpAddend;
  DWORD DVar1;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0xa0c8) != 0) && (*(int *)(unaff_ESI + 0xa0b4) != 2)) {
    lpAddend = (LONG *)(unaff_ESI + 0xa0bc);
    if (*(int *)(unaff_ESI + 0xa0bc) == 0) {
      DVar1 = GetTickCount();
      *(DWORD *)(unaff_ESI + 0xa0c4) = DVar1;
    }
    if (*(int *)(unaff_ESI + 0xa0cc) < *lpAddend) {
      InterlockedExchange(lpAddend,0);
      DVar1 = GetTickCount();
      if (DVar1 - *(int *)(unaff_ESI + 0xa0c4) < *(uint *)(unaff_ESI + 0xa0d0)) {
        return 1;
      }
    }
    else {
      InterlockedIncrement(lpAddend);
    }
    return 0;
  }
  return 0;
}

