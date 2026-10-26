
void FUN_006ed980(char *param_1)

{
  errno_t eVar1;
  DWORD DVar2;
  int iVar3;
  char *_Format;
  _SYSTEMTIME local_420;
  char local_410 [1028];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_410,0x400,param_1,&stack0x00000008);
  if (DAT_00fe31bc == 0) {
    eVar1 = _fopen_s(&DAT_00fba804,"log.txt","wct");
    if (eVar1 != 0) {
      FID_conflict__wprintf("WARNING: Cannot open log file!\n");
      DAT_00fe31bc = 100;
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    DAT_00fe31bc = 1;
  }
  else if (DAT_00fe31bc != 1) goto LAB_006eda81;
  GetLocalTime(&local_420);
  DVar2 = GetTickCount();
  _fprintf(DAT_00fba804,"[%2d%02d%02d][%02d:%02d:%02d][%010u] ",(uint)local_420.wYear % 100,
           (uint)local_420.wMonth,(uint)local_420.wDay,(uint)local_420.wHour,(uint)local_420.wMinute
           ,(uint)local_420.wSecond,DVar2);
  _fprintf(DAT_00fba804,"%s",local_410);
LAB_006eda81:
  _Format = "%s";
  iVar3 = FUN_00894fab(&DAT_00bfc638,local_410);
  _fprintf((FILE *)(iVar3 + 0x20),_Format);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

