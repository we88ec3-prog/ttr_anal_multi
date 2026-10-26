
/* Library Function - Single Match
    _tmpnam
   
   Library: Visual Studio 2010 Release */

char * __cdecl _tmpnam(char *_Buffer)

{
  char *local_8;
  
  local_8 = (char *)0x0;
  __tmpnam_helper(_Buffer,0xffffffff,0,0x7fff,&local_8);
  return local_8;
}

