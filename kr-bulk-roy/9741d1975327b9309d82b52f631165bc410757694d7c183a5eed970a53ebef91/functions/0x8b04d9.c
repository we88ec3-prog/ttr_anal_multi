
/* Library Function - Single Match
    __mbsnbcpy_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __mbsnbcpy_s(uchar *_Dst,size_t _SizeInBytes,uchar *_Src,size_t _MaxCount)

{
  errno_t eVar1;
  
  eVar1 = __mbsnbcpy_s_l(_Dst,_SizeInBytes,_Src,_MaxCount,(_locale_t)0x0);
  return eVar1;
}

