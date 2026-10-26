
void FUN_006edb60(char *param_1)

{
  HANDLE pvVar1;
  WORD WVar2;
  char local_410 [1028];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_410,0x400,param_1,&stack0x00000008);
  WVar2 = 0xe;
  pvVar1 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar1,WVar2);
  FUN_006ed980("WARNING: %s\n",local_410);
  WVar2 = 7;
  pvVar1 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar1,WVar2);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

