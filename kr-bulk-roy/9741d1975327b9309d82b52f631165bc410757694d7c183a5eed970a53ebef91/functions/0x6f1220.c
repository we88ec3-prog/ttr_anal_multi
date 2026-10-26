
void FUN_006f1220(char *param_1)

{
  int *piVar1;
  FILE *pFVar2;
  int *in_ECX;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  EnterCriticalSection((LPCRITICAL_SECTION)in_ECX[0x4e]);
  if ((FILE *)in_ECX[0x49] != (FILE *)0x0) {
    _fputs(param_1,(FILE *)in_ECX[0x49]);
    *(short *)(in_ECX + 0x4a) = (short)in_ECX[0x4a] + 1;
    if ((uint)*(ushort *)(in_ECX + 0x4a) == in_ECX[0x4d]) {
      in_ECX[0x4b] = in_ECX[0x4b] + 1;
      *(undefined2 *)(in_ECX + 0x4a) = 0;
      if (in_ECX[0x4b] == in_ECX[0x4c]) {
        _fclose((FILE *)in_ECX[0x49]);
        in_ECX[0x4b] = 0;
        GetLocalTime(&local_18);
        piVar1 = in_ECX + 1;
        if (0xf < (uint)in_ECX[6]) {
          piVar1 = (int *)*piVar1;
        }
        _sprintf_s((char *)(in_ECX + 8),0x104,"%s_%04d_%02d_%02d_%02d_%02d_%02d.txt",piVar1,
                   (uint)local_18.wYear,(uint)local_18.wMonth,(uint)local_18.wDay,
                   (uint)local_18.wHour,(uint)local_18.wMinute,(uint)local_18.wSecond);
        pFVar2 = _fopen((char *)(in_ECX + 8),"a");
      }
      else {
        (**(code **)(*in_ECX + 4))("Flush File\n");
        _fclose((FILE *)in_ECX[0x49]);
        in_ECX[0x49] = 0;
        pFVar2 = _fopen((char *)(in_ECX + 8),"a");
      }
      in_ECX[0x49] = (int)pFVar2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)in_ECX[0x4e]);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

