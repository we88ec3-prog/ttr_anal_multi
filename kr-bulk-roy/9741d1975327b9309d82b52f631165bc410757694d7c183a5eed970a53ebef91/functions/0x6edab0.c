
void FUN_006edab0(int param_1,char *param_2)

{
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1 <= DAT_00d63d78) {
    _vsprintf_s(local_40c,0x400,param_2,&stack0x0000000c);
    FUN_006ed980(&DAT_00c42098,local_40c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

