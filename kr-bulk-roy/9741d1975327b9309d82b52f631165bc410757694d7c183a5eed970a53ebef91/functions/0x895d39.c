
/* Library Function - Single Match
    __beginthread
   
   Library: Visual Studio 2010 Release */

uintptr_t __cdecl __beginthread(_StartAddress *_StartAddress,uint _StackSize,void *_ArgList)

{
  int *piVar1;
  _ptiddata _Ptd;
  _ptiddata p_Var2;
  HANDLE hThread;
  DWORD DVar3;
  
  DVar3 = 0;
  if (_StartAddress == (_StartAddress *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
  }
  else {
    ___set_flsgetvalue();
    _Ptd = __calloc_crt(1,0x214);
    if (_Ptd != (_ptiddata)0x0) {
      p_Var2 = __getptd();
      __initptd(_Ptd,p_Var2->ptlocinfo);
      _Ptd->_initaddr = _StartAddress;
      _Ptd->_initarg = _ArgList;
      hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,_StackSize,__threadstart_4,_Ptd,4,
                             &_Ptd->_tid);
      _Ptd->_thandle = (uintptr_t)hThread;
      if ((hThread != (HANDLE)0x0) && (DVar3 = ResumeThread(hThread), DVar3 != 0xffffffff)) {
        return (uintptr_t)hThread;
      }
      DVar3 = GetLastError();
    }
    _free(_Ptd);
    if (DVar3 != 0) {
      __dosmaperr(DVar3);
    }
  }
  return 0xffffffff;
}

