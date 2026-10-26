
void FUN_006f1150(void)

{
  int *piVar1;
  FILE *pFVar2;
  int in_ECX;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *(undefined2 *)(in_ECX + 0x128) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  GetLocalTime(&local_18);
  piVar1 = (int *)(in_ECX + 4);
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar1 = (int *)*piVar1;
  }
  _sprintf_s((char *)(in_ECX + 0x20),0x104,"%s_%04d_%02d_%02d_%02d_%02d_%02d.txt",piVar1,
             (uint)local_18.wYear,(uint)local_18.wMonth,(uint)local_18.wDay,(uint)local_18.wHour,
             (uint)local_18.wMinute,(uint)local_18.wSecond);
  pFVar2 = _fopen((char *)(in_ECX + 0x20),"a");
  *(FILE **)(in_ECX + 0x124) = pFVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

