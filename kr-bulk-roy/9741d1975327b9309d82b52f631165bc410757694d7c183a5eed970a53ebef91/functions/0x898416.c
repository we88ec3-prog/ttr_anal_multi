
/* Library Function - Single Match
    _ferror
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __cdecl _ferror(FILE *_File)

{
  int *piVar1;
  
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0;
  }
  return _File->_flag & 0x20;
}

