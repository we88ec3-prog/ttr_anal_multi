
/* Library Function - Single Match
    __wfopen
   
   Library: Visual Studio 2010 Release */

FILE * __cdecl __wfopen(wchar_t *_Filename,wchar_t *_Mode)

{
  FILE *pFVar1;
  
  pFVar1 = __wfsopen(_Filename,_Mode,0x40);
  return pFVar1;
}

