
void FUN_006f0db0(void)

{
  FILE **_File;
  int *piVar1;
  errno_t eVar2;
  int unaff_ESI;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _File = (FILE **)(unaff_ESI + 0x194);
  if (*(FILE **)(unaff_ESI + 0x194) != (FILE *)0x0) {
    _fclose(*(FILE **)(unaff_ESI + 0x194));
    *_File = (FILE *)0x0;
  }
  if (*(char *)(unaff_ESI + 0x1d0) == '\0') {
    GetLocalTime(&local_18);
    piVar1 = (int *)(unaff_ESI + 0x74);
    if (0xf < *(uint *)(unaff_ESI + 0x88)) {
      piVar1 = (int *)*piVar1;
    }
    FUN_00401d90("%s_%04d_%02d_%02d_%02d_%02d_%02d.txt",piVar1,local_18.wYear,local_18.wMonth,
                 local_18.wDay,local_18.wHour,local_18.wMinute,local_18.wSecond);
    eVar2 = _fopen_s(_File,(char *)(unaff_ESI + 0x90),"acb");
    if (eVar2 != 0) {
      FID_conflict__wprintf("Can\'t write to the log file!\n");
      *_File = (FILE *)0x0;
      *(undefined1 *)(unaff_ESI + 0x1d0) = 1;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

