
void FUN_004314b0(wchar_t param_1)

{
  int in_ECX;
  mbstate_t local_14;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = 0;
  __Wcrtomb(local_10,param_1,&local_14,(_Cvtvec *)(in_ECX + 0x18));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

