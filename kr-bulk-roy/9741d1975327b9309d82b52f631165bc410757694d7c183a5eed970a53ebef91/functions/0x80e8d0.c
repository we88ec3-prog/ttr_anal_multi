
undefined4 FUN_0080e8d0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uintptr_t uVar1;
  void *unaff_ESI;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)unaff_ESI + 0x28);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int *)((int)unaff_ESI + 4) == 0) && (*(int *)((int)unaff_ESI + 8) == 0)) {
    *(undefined4 *)((int)unaff_ESI + 4) = 1;
    *(undefined4 *)((int)unaff_ESI + 8) = 1;
    uVar1 = __beginthread(FUN_0080e850,0,unaff_ESI);
    if (uVar1 != 0) {
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
    FUN_006edb60(&DAT_00c51b84);
    *(undefined4 *)((int)unaff_ESI + 4) = 0;
    *(undefined4 *)((int)unaff_ESI + 8) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

