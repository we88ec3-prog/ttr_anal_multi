
void FUN_006f2890(HWND param_1)

{
  UINT UVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  HIMC pHVar3;
  int unaff_ESI;
  CHAR local_110 [264];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  UVar1 = ImmGetIMEFileNameA(*(HKL *)(unaff_ESI + 0x74),local_110,0x104);
  if (UVar1 != 0) {
    if (*(HMODULE *)(unaff_ESI + 0x8c) != (HMODULE)0x0) {
      FreeLibrary(*(HMODULE *)(unaff_ESI + 0x8c));
    }
    hModule = LoadLibraryA(local_110);
    *(HMODULE *)(unaff_ESI + 0x8c) = hModule;
    if (hModule != (HMODULE)0x0) {
      pFVar2 = GetProcAddress(hModule,"GetReadingString");
      *(FARPROC *)(unaff_ESI + 0x90) = pFVar2;
      pFVar2 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0x8c),"ShowReadingWindow");
      *(FARPROC *)(unaff_ESI + 0x94) = pFVar2;
      if (pFVar2 != (FARPROC)0x0) {
        pHVar3 = ImmGetContext(param_1);
        if (pHVar3 != (HIMC)0x0) {
          (**(code **)(unaff_ESI + 0x94))(pHVar3,0);
          ImmReleaseContext(param_1,pHVar3);
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

