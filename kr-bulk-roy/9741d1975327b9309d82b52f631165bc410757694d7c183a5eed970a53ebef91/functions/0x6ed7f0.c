
void FUN_006ed7f0(int param_1)

{
  HMODULE hModule;
  BOOL BVar1;
  uint uVar2;
  uint *unaff_ESI;
  _OSVERSIONINFOA local_b8;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fe31ac == '\0') {
    DAT_00fe31ac = '\x01';
    hModule = GetModuleHandleW(L"USER32");
    if (hModule != (HMODULE)0x0) {
      _memset(&local_b8.dwMajorVersion,0,0x90);
      local_b8.dwOSVersionInfoSize = 0x94;
      GetVersionExA(&local_b8);
      if (local_b8.dwPlatformId == 2) {
        DAT_00fe31b0 = GetProcAddress(hModule,"GetMonitorInfoW");
      }
      else {
        DAT_00fe31b0 = GetProcAddress(hModule,"GetMonitorInfoA");
      }
    }
  }
  if (DAT_00fe31b0 == (FARPROC)0x0) {
    if ((((param_1 == 0x12340042) && (unaff_ESI != (uint *)0x0)) && (0x27 < *unaff_ESI)) &&
       (BVar1 = SystemParametersInfoA(0x30,0,&local_1c,0), BVar1 != 0)) {
      unaff_ESI[1] = 0;
      unaff_ESI[2] = 0;
      uVar2 = GetSystemMetrics(0);
      unaff_ESI[3] = uVar2;
      uVar2 = GetSystemMetrics(1);
      unaff_ESI[4] = uVar2;
      unaff_ESI[5] = local_1c;
      unaff_ESI[6] = local_18;
      unaff_ESI[7] = local_14;
      unaff_ESI[8] = local_10;
      unaff_ESI[9] = 1;
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  (*DAT_00fe31b0)(param_1);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

