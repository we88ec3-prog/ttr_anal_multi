
/* Library Function - Single Match
    __fileno
   
   Library: Visual Studio 2010 Release */

int __cdecl __fileno(FILE *_File)

{
  int *piVar1;
  
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return -1;
  }
  return _File->_file;
}

