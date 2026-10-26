
void FUN_006f0d00(char *param_1)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x1d0) == '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x34));
    if (*(int *)(in_EAX + 0x194) == 0) {
      FUN_006f0db0();
    }
    if (*(FILE **)(in_EAX + 0x194) != (FILE *)0x0) {
      _fputs(param_1,*(FILE **)(in_EAX + 0x194));
      *(int *)(in_EAX + 0x198) = *(int *)(in_EAX + 0x198) + 1;
      if (*(int *)(in_EAX + 0x19c) <= *(int *)(in_EAX + 0x198)) {
        _fflush(*(FILE **)(in_EAX + 0x194));
        *(int *)(in_EAX + 0x1a0) = *(int *)(in_EAX + 0x1a0) + 1;
        *(undefined4 *)(in_EAX + 0x198) = 0;
        if (*(int *)(in_EAX + 0x1a4) <= *(int *)(in_EAX + 0x1a0)) {
          FUN_006f0db0();
          *(undefined4 *)(in_EAX + 0x1a0) = 0;
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x34));
  }
  return;
}

