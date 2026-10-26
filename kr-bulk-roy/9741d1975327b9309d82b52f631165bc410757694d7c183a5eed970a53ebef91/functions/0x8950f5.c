
/* Library Function - Single Match
    __unlock_file
   
   Library: Visual Studio 2010 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)0xd61af7 < _File) && (_File < (FILE *)0xd61d59)) {
    _File->_flag = _File->_flag & 0xffff7fff;
    FUN_008a717e(((int)&_File[-0x6b0d8]._base >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}

