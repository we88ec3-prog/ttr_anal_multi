
void FUN_006f11e0(void)

{
  int in_ECX;
  
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 0x138));
  if (*(FILE **)(in_ECX + 0x124) != (FILE *)0x0) {
    _fclose(*(FILE **)(in_ECX + 0x124));
  }
  *(undefined4 *)(in_ECX + 0x124) = 0;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 0x138));
  return;
}

