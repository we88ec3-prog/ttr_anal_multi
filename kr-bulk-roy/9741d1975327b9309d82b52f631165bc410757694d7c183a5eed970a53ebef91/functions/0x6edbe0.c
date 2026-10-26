
void FUN_006edbe0(char *param_1)

{
  HANDLE pvVar1;
  WORD WVar2;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_408,0x400,param_1,&stack0x00000008);
  WVar2 = 0xf;
  pvVar1 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar1,WVar2);
  FUN_006ed980("ALERT: %s\n",local_408);
  WVar2 = 7;
  pvVar1 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar1,WVar2);
  MessageBoxA((HWND)0x0,local_408,"ALERT",0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

