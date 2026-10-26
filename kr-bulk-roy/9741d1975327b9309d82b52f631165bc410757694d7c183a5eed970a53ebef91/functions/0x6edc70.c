
void FUN_006edc70(char *param_1)

{
  code *pcVar1;
  HANDLE pvVar2;
  WORD WVar3;
  char local_410 [1028];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _vsprintf_s(local_410,0x400,param_1,&stack0x00000008);
  WVar3 = 0xc;
  pvVar2 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar2,WVar3);
  FUN_006ed980("ERROR: %s\n",local_410);
  WVar3 = 7;
  pvVar2 = GetStdHandle(0xfffffff5);
  SetConsoleTextAttribute(pvVar2,WVar3);
  MessageBoxA((HWND)0x0,local_410,"ERROR",0x10);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

