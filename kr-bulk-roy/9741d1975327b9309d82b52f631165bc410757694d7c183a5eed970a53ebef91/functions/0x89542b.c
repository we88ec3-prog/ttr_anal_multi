
/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2010 Release */

int __cdecl _isdigit(int _C)

{
  int iVar1;
  
  if (DAT_00f8cb10 == 0) {
    return *(ushort *)(PTR_DAT_00d62868 + _C * 2) & 4;
  }
  iVar1 = __isdigit_l(_C,(_locale_t)0x0);
  return iVar1;
}

