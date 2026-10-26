
void FUN_006edd00(char *param_1)

{
  char local_410 [1028];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_410,0x400,param_1,&stack0x00000008);
  FUN_006ed980(&DAT_00c42098,local_410);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

