
/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 2010 Release */

void __cdecl __mtterm(void)

{
  code *pcVar1;
  int iVar2;
  
  if (DAT_00d62108 != -1) {
    iVar2 = DAT_00d62108;
    pcVar1 = DecodePointer(DAT_00f8d4f4);
    (*pcVar1)(iVar2);
    DAT_00d62108 = -1;
  }
  if (DAT_00d6210c != 0xffffffff) {
    TlsFree(DAT_00d6210c);
    DAT_00d6210c = 0xffffffff;
  }
  __mtdeletelocks();
  return;
}

