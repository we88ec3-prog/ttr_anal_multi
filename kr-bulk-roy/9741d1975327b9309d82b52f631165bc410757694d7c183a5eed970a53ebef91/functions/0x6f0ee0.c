
void FUN_006f0ee0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) != 0) {
    *(undefined1 *)(in_ECX + 0x1a8) = 1;
    FUN_004fb7d0();
    *(undefined4 *)(in_ECX + 100) = 0;
    CloseHandle(*(HANDLE *)(in_ECX + 0x70));
    CloseHandle(*(HANDLE *)(in_ECX + 0x6c));
    FUN_006f0c90();
    if (*(FILE **)(in_ECX + 0x194) != (FILE *)0x0) {
      _fclose(*(FILE **)(in_ECX + 0x194));
      *(undefined4 *)(in_ECX + 0x194) = 0;
    }
  }
  return;
}

