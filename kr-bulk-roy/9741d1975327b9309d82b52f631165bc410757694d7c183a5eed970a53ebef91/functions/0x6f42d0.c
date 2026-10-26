
void FUN_006f42d0(void)

{
  UINT UVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int unaff_ESI;
  CHAR local_110 [264];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  UVar1 = GetSystemDirectoryA(local_110,0x105);
  if (UVar1 != 0) {
    _strcat_s(local_110,0x105,"\\imm32.dll");
    hModule = LoadLibraryA(local_110);
    *(HMODULE *)(unaff_ESI + 4) = hModule;
    if (hModule != (HMODULE)0x0) {
      pFVar2 = GetProcAddress(hModule,"ImmLockIMC");
      *(FARPROC *)(unaff_ESI + 8) = pFVar2;
      pFVar2 = GetProcAddress(*(HMODULE *)(unaff_ESI + 4),"ImmUnlockIMC");
      *(FARPROC *)(unaff_ESI + 0xc) = pFVar2;
      pFVar2 = GetProcAddress(*(HMODULE *)(unaff_ESI + 4),"ImmLockIMCC");
      *(FARPROC *)(unaff_ESI + 0x10) = pFVar2;
      pFVar2 = GetProcAddress(*(HMODULE *)(unaff_ESI + 4),"ImmUnlockIMCC");
      *(FARPROC *)(unaff_ESI + 0x14) = pFVar2;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

