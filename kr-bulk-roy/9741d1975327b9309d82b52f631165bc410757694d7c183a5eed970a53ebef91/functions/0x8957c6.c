
/* Library Function - Single Match
    __ultoa_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __ultoa_s(ulong _Val,char *_DstBuf,size_t _Size,int _Radix)

{
  errno_t eVar1;
  
  eVar1 = xtoa_s(_Size,_Radix,0);
  return eVar1;
}

