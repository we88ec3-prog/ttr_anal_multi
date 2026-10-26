
/* Library Function - Single Match
    _freopen
   
   Library: Visual Studio 2010 Release */

FILE * __cdecl _freopen(char *_Filename,char *_Mode,FILE *_File)

{
  FILE *local_8;
  
  local_8 = (FILE *)0x0;
  __freopen_helper(&local_8,_Filename,_Mode,_File,0x40);
  return local_8;
}

