
void FUN_00733f90(undefined4 param_1,char *param_2)

{
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_408 = '\0';
  _memset(local_407,0,0x3ff);
  if (param_2 != (char *)0x0) {
    _vsprintf_s(&local_408,0x400,param_2,&stack0x0000000c);
  }
  FUN_0073b690(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

