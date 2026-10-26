
void FUN_006f0400(undefined4 param_1,char *param_2)

{
  undefined4 unaff_EDI;
  char local_80c;
  undefined1 local_80b [2051];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_2 == (char *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_80c = '\0';
  _memset(local_80b,0,0x7ff);
  __vsnprintf_s(&local_80c,0x800,0x800,param_2,&stack0x0000000c);
  FUN_006f0220(unaff_EDI);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

