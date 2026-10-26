
void FUN_00713ec0(int param_1,char *param_2)

{
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_408,0x400,param_2,&stack0x0000000c);
  _fprintf(*(FILE **)(param_1 + 4),"%s",local_408);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

