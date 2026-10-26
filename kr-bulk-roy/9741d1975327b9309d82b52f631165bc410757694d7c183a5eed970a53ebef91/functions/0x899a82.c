
/* Library Function - Single Match
    _tmpfile
   
   Library: Visual Studio 2010 Release */

FILE * __cdecl _tmpfile(void)

{
  FILE *local_8;
  
  local_8 = (FILE *)0x0;
  __tmpfile_helper(&local_8,0x40);
  return local_8;
}

