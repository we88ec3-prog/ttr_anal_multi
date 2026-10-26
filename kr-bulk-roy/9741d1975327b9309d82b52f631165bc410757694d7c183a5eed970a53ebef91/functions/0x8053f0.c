
void FUN_008053f0(void)

{
  int iVar1;
  WSADATA local_19c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = WSAStartup(0x202,&local_19c);
  if (((iVar1 == 0) && ((char)local_19c.wVersion == '\x02')) &&
     ((char)(local_19c.wVersion >> 8) == '\x02')) {
    DAT_00fba7c6 = 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

