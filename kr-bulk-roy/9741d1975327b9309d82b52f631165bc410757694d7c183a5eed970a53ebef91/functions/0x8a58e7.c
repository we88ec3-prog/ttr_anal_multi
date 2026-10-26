
/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2010 Release */

int __cdecl __mtinit(void)

{
  HMODULE hModule;
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  _ptiddata _Ptd;
  DWORD DVar4;
  code *pcVar5;
  _ptiddata p_Var6;
  
  hModule = GetModuleHandleW(L"KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    __mtterm();
    return 0;
  }
  DAT_00f8d4e8 = GetProcAddress(hModule,"FlsAlloc");
  DAT_00f8d4ec = GetProcAddress(hModule,"FlsGetValue");
  DAT_00f8d4f0 = GetProcAddress(hModule,"FlsSetValue");
  DAT_00f8d4f4 = GetProcAddress(hModule,"FlsFree");
  if ((((DAT_00f8d4e8 == (FARPROC)0x0) || (DAT_00f8d4ec == (FARPROC)0x0)) ||
      (DAT_00f8d4f0 == (FARPROC)0x0)) || (DAT_00f8d4f4 == (FARPROC)0x0)) {
    DAT_00f8d4ec = TlsGetValue_exref;
    DAT_00f8d4e8 = (FARPROC)&LAB_008a554c;
    DAT_00f8d4f0 = TlsSetValue_exref;
    DAT_00f8d4f4 = TlsFree_exref;
  }
  DAT_00d6210c = TlsAlloc();
  if ((DAT_00d6210c != 0xffffffff) && (BVar1 = TlsSetValue(DAT_00d6210c,DAT_00f8d4ec), BVar1 != 0))
  {
    __init_pointers();
    DAT_00f8d4e8 = EncodePointer(DAT_00f8d4e8);
    DAT_00f8d4ec = EncodePointer(DAT_00f8d4ec);
    DAT_00f8d4f0 = EncodePointer(DAT_00f8d4f0);
    DAT_00f8d4f4 = EncodePointer(DAT_00f8d4f4);
    iVar2 = __mtinitlocks();
    if (iVar2 != 0) {
      pcVar5 = __freefls_4;
      pcVar3 = DecodePointer(DAT_00f8d4e8);
      DAT_00d62108 = (*pcVar3)(pcVar5);
      if ((DAT_00d62108 != -1) && (_Ptd = __calloc_crt(1,0x214), _Ptd != (_ptiddata)0x0)) {
        iVar2 = DAT_00d62108;
        p_Var6 = _Ptd;
        pcVar3 = DecodePointer(DAT_00f8d4f0);
        iVar2 = (*pcVar3)(iVar2,p_Var6);
        if (iVar2 != 0) {
          __initptd(_Ptd,(pthreadlocinfo)0x0);
          DVar4 = GetCurrentThreadId();
          _Ptd->_thandle = 0xffffffff;
          _Ptd->_tid = DVar4;
          return 1;
        }
      }
    }
    __mtterm();
  }
  return 0;
}

