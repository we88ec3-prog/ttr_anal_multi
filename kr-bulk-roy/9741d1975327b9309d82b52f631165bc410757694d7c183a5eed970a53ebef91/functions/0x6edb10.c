
void FUN_006edb10(char *param_1)

{
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_408,0x400,param_1,&stack0x00000008);
  FUN_006edab0(0,&DAT_00bfc638,local_408);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

