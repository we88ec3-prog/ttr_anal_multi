
int FUN_006ed930(undefined4 param_1)

{
  HMODULE hModule;
  int iVar1;
  
  if (DAT_00fe31b4 == '\0') {
    DAT_00fe31b4 = '\x01';
    hModule = GetModuleHandleW(L"USER32");
    if (hModule != (HMODULE)0x0) {
      DAT_00fe31b8 = GetProcAddress(hModule,"MonitorFromWindow");
    }
  }
  if (DAT_00fe31b8 == (FARPROC)0x0) {
    return 0x12340042;
  }
  iVar1 = (*DAT_00fe31b8)(param_1,1);
  return iVar1;
}

