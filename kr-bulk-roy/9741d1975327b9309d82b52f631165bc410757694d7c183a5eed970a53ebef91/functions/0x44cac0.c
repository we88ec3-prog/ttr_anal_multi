
void FUN_0044cac0(undefined4 param_1,HMODULE param_2)

{
  DWORD DVar1;
  HANDLE hFile;
  BOOL BVar2;
  int *piVar3;
  uint uStack_1bc;
  _FILETIME local_1a8;
  int *local_1a0;
  DWORD local_19c;
  undefined4 local_198;
  CHAR local_194 [264];
  CHAR local_8c;
  undefined1 local_8b [107];
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00d61f20 ^ 0xc863c8;
  uStack_1bc = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&uStack_1bc;
  ExceptionList = &local_14;
  local_198 = param_1;
  local_8 = 0;
  local_20 = uStack_1bc;
  DVar1 = GetModuleFileNameA(param_2,local_194,0x104);
  if ((DVar1 != 0) && ((short)param_2->unused == 0x5a4d)) {
    piVar3 = (int *)((int)&param_2->unused + param_2[0xf].unused);
    local_1a0 = piVar3;
    if (*piVar3 == 0x4550) {
      hFile = CreateFileA(local_194,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
      local_8c = '\0';
      _memset(local_8b,0,99);
      DVar1 = 0;
      if (hFile != (HANDLE)0xffffffff) {
        local_19c = GetFileSize(hFile,(LPDWORD)0x0);
        BVar2 = GetFileTime(hFile,(LPFILETIME)0x0,(LPFILETIME)0x0,&local_1a8);
        if (BVar2 != 0) {
          wsprintfA(&local_8c," - file date is ");
          lstrlenA(&local_8c);
          FUN_0044ca40(local_1a8.dwLowDateTime,local_1a8.dwHighDateTime);
          piVar3 = local_1a0;
        }
        CloseHandle(hFile);
        DVar1 = local_19c;
      }
      FUN_0044c9e0("%s, loaded at 0x%08x - %d bytes - %08x%s\r\n",local_194,param_2,DVar1,piVar3[2],
                   &local_8c);
    }
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}

