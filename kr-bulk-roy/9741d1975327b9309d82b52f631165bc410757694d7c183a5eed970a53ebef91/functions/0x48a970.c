
void FUN_0048a970(void)

{
  FILE *pFVar1;
  FILE *_File;
  int _FileHandle;
  size_t _Count;
  void *_DstBuf;
  BOOL BVar2;
  _STARTUPINFOA local_16c;
  _PROCESS_INFORMATION local_120;
  FILE *local_110;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pFVar1 = _fopen("Tartaros.log","ab");
  local_110 = pFVar1;
  _File = _fopen("Log.txt","rb");
  if (pFVar1 == (FILE *)0x0) {
    pFVar1 = _File;
    if (_File == (FILE *)0x0) goto LAB_0048aa1b;
  }
  else if (_File != (FILE *)0x0) {
    _FileHandle = __fileno(_File);
    _Count = __filelength(_FileHandle);
    _DstBuf = (void *)FUN_0087dc3d(_Count);
    _fread(_DstBuf,1,_Count,_File);
    _fclose(_File);
    pFVar1 = local_110;
    _fwrite(_DstBuf,1,_Count,local_110);
    _fclose(pFVar1);
    DeleteFileA("Log.txt");
    FUN_00891d3d(_DstBuf);
    goto LAB_0048aa1b;
  }
  _fclose(pFVar1);
LAB_0048aa1b:
  _memset(&local_16c,0,0x44);
  local_120.hProcess = (HANDLE)0x0;
  local_120.hThread = (HANDLE)0x0;
  local_120.dwProcessId = 0;
  local_120.dwThreadId = 0;
  local_16c.cb = 0x44;
  builtin_strncpy(local_10c,"Niche",6);
  _memset(local_10c + 6,0,0xfa);
  BVar2 = CreateProcessA("DumpAgent.exe",local_10c,(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCSTR)0x0,&local_16c,
                         &local_120);
  if (BVar2 == 0) {
    GetLastError();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

