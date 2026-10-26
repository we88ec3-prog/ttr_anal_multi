
/* Library Function - Single Match
    __access_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __access_s(char *_Filename,int _AccessMode)

{
  ulong *puVar1;
  int *piVar2;
  DWORD DVar3;
  int iVar4;
  
  if ((_Filename == (char *)0x0) || ((_AccessMode & 0xfffffff9U) != 0)) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    iVar4 = 0x16;
    *piVar2 = 0x16;
    FUN_00893343();
  }
  else {
    DVar3 = GetFileAttributesA(_Filename);
    if (DVar3 == 0xffffffff) {
      DVar3 = GetLastError();
      __dosmaperr(DVar3);
    }
    else {
      if ((((DVar3 & 0x10) != 0) || ((DVar3 & 1) == 0)) || ((_AccessMode & 2U) == 0)) {
        return 0;
      }
      puVar1 = ___doserrno();
      *puVar1 = 5;
      piVar2 = __errno();
      *piVar2 = 0xd;
    }
    piVar2 = __errno();
    iVar4 = *piVar2;
  }
  return iVar4;
}

