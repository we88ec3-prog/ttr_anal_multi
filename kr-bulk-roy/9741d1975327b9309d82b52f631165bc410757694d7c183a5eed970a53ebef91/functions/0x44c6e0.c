
void FUN_0044c6e0(undefined4 *param_1)

{
  WCHAR WVar1;
  short sVar2;
  FILE *pFVar3;
  FILE *_File;
  int _FileHandle;
  size_t _Count;
  void *_DstBuf;
  wchar_t *pwVar4;
  WCHAR *pWVar5;
  short *psVar6;
  HANDLE pvVar7;
  DWORD DVar8;
  HANDLE hObject;
  UINT UVar9;
  FARPROC pFVar10;
  BOOL BVar11;
  FILE *local_594;
  undefined4 *local_590;
  DWORD DStack_58c;
  undefined4 *puStack_588;
  undefined4 uStack_584;
  _PROCESS_INFORMATION _Stack_580;
  _STARTUPINFOA _Stack_570;
  WCHAR local_528;
  undefined1 auStack_526 [518];
  char acStack_320 [256];
  WCHAR aWStack_220 [266];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_594;
  local_590 = param_1;
  _fflush(DAT_00fba804);
  _fclose(DAT_00fba804);
  FUN_0044d150(param_1);
  pFVar3 = _fopen("Tartaros.log","ab");
  local_594 = pFVar3;
  _File = _fopen("Log.txt","rb");
  if (pFVar3 == (FILE *)0x0) {
    pFVar3 = _File;
    if (_File == (FILE *)0x0) goto LAB_0044c7c4;
  }
  else if (_File != (FILE *)0x0) {
    _FileHandle = __fileno(_File);
    _Count = __filelength(_FileHandle);
    _DstBuf = (void *)FUN_00891268(_Count);
    _fread(_DstBuf,1,_Count,_File);
    _fclose(_File);
    pFVar3 = local_594;
    _fwrite(_DstBuf,1,_Count,local_594);
    _fclose(pFVar3);
    DeleteFileA("Log.txt");
    FUN_0089120c(_DstBuf);
    goto LAB_0044c7c4;
  }
  _fclose(pFVar3);
LAB_0044c7c4:
  GetModuleFileNameW((HMODULE)0x0,&local_528,0x208);
  pwVar4 = _wcschr(&local_528,L'.');
  if (pwVar4 == (wchar_t *)0x0) {
    pWVar5 = &local_528;
    do {
      WVar1 = *pWVar5;
      pWVar5 = pWVar5 + 1;
    } while (WVar1 != L'\0');
    pwVar4 = (wchar_t *)(auStack_526 + ((int)pWVar5 - (int)auStack_526 >> 1) * 2 + -2);
  }
  psVar6 = &DAT_00bfc120;
  do {
    sVar2 = *psVar6;
    *(short *)((int)(pwVar4 + -0x5fe090) + (int)psVar6) = sVar2;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  pvVar7 = GetCurrentProcess();
  DVar8 = GetCurrentProcessId();
  hObject = CreateFileW(&local_528,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
  DStack_58c = GetCurrentThreadId();
  puStack_588 = local_590;
  uStack_584 = 0;
  UVar9 = GetSystemDirectoryW(aWStack_220,0x105);
  if (UVar9 != 0) {
    _wcscat_s(aWStack_220,0x104,L"\\dbghelp.dll");
    local_594 = (FILE *)LoadLibraryW(aWStack_220);
    if (local_594 != (FILE *)0x0) {
      pFVar10 = GetProcAddress((HMODULE)local_594,"MiniDumpWriteDump");
      if (pFVar10 != (FARPROC)0x0) {
        (*pFVar10)(pvVar7,DVar8,hObject,0,
                   -(uint)(local_590 != (undefined4 *)0x0) & (uint)&DStack_58c,0,0);
      }
      FreeLibrary((HMODULE)local_594);
    }
  }
  CloseHandle(hObject);
  _memset(&_Stack_570,0,0x44);
  _Stack_580.hProcess = (HANDLE)0x0;
  _Stack_580.hThread = (HANDLE)0x0;
  _Stack_580.dwProcessId = 0;
  _Stack_580.dwThreadId = 0;
  _Stack_570.cb = 0x44;
  _sprintf(acStack_320,"Niche %u",*(undefined4 *)*local_590);
  BVar11 = CreateProcessA("DumpAgent.exe",acStack_320,(LPSECURITY_ATTRIBUTES)0x0,
                          (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCSTR)0x0,&_Stack_570,
                          &_Stack_580);
  if (BVar11 == 0) {
    DVar8 = GetLastError();
    FID_conflict__wprintf("CreateProcess failed (%d)\n",DVar8);
  }
  __security_check_cookie(local_c ^ (uint)&local_594);
  return;
}

