
void FUN_00709ed0(void)

{
  DWORD DVar1;
  CHAR local_88 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  DVar1 = GetLastError();
  DVar1 = FormatMessageA(0x1200,(LPCVOID)0x0,DVar1,0,local_88,0x80,(va_list *)0x0);
  if (DVar1 != 0) {
    FUN_006f5510(local_88);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006f5580();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

