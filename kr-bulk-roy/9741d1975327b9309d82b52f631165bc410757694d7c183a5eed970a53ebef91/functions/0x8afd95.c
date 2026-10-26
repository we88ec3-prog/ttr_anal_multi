
/* Library Function - Single Match
    __cwait
   
   Library: Visual Studio 2010 Release */

intptr_t __cdecl __cwait(int *_TermStat,intptr_t _ProcHandle,int _Action)

{
  intptr_t hProcess;
  DWORD DVar1;
  BOOL BVar2;
  int *piVar3;
  ulong *puVar4;
  intptr_t iVar5;
  
  hProcess = _ProcHandle;
  if ((_ProcHandle == -1) || (_ProcHandle == -2)) {
    piVar3 = __errno();
    *piVar3 = 10;
    iVar5 = -1;
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)_ProcHandle,0xffffffff);
    if ((DVar1 != 0) ||
       (BVar2 = GetExitCodeProcess((HANDLE)hProcess,(LPDWORD)&_ProcHandle), iVar5 = hProcess,
       BVar2 == 0)) {
      DVar1 = GetLastError();
      if (DVar1 == 6) {
        piVar3 = __errno();
        *piVar3 = 10;
        puVar4 = ___doserrno();
        *puVar4 = 6;
      }
      else {
        DVar1 = GetLastError();
        __dosmaperr(DVar1);
      }
      _ProcHandle = -1;
      iVar5 = -1;
    }
    CloseHandle((HANDLE)hProcess);
    if (_TermStat != (int *)0x0) {
      *_TermStat = _ProcHandle;
    }
  }
  return iVar5;
}

