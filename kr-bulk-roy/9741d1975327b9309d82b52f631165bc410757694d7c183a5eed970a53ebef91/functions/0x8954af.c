
/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 2010 Release */

int __cdecl _isxdigit(int _C)

{
  int iVar1;
  
  if (DAT_00f8cb10 == 0) {
    return *(ushort *)(PTR_DAT_00d62868 + _C * 2) & 0x80;
  }
  iVar1 = __isxdigit_l(_C,(_locale_t)0x0);
  return iVar1;
}

