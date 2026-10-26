
undefined4 FUN_0070a0a0(LPCSTR param_1,LPCSTR param_2)

{
  int *piVar1;
  HMODULE pHVar2;
  FARPROC pFVar3;
  
  piVar1 = (int *)FUN_00709f50(param_1);
  if (*piVar1 == 0) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 == (HMODULE)0x0) {
      FUN_00709ed0();
    }
    *piVar1 = (int)pHVar2;
    if (pHVar2 == (HMODULE)0x0) {
      return 1;
    }
  }
  pFVar3 = GetProcAddress((HMODULE)*piVar1,param_2);
  if (pFVar3 == (FARPROC)0x0) {
    FUN_00709ed0();
    return 2;
  }
  FUN_006f55b0(pFVar3,0);
  return 0;
}

