
void FUN_0044c9e0(LPCSTR param_1)

{
  DWORD nNumberOfBytesToWrite;
  HANDLE unaff_ESI;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  DWORD local_7dc;
  CHAR local_7d8 [2000];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  wvsprintfA(local_7d8,param_1,&stack0x00000008);
  lpOverlapped = (LPOVERLAPPED)0x0;
  lpNumberOfBytesWritten = &local_7dc;
  nNumberOfBytesToWrite = lstrlenA(local_7d8);
  WriteFile(unaff_ESI,local_7d8,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

