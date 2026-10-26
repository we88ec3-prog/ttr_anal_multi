
/* Library Function - Single Match
    __ultow_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __ultow_s(ulong _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix)

{
  errno_t eVar1;
  
  eVar1 = xtow_s(_SizeInWords,_Radix,0);
  return eVar1;
}

