
/* Library Function - Single Match
    _wcstombs_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl
_wcstombs_s(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,wchar_t *_Src,
           size_t _MaxCountInBytes)

{
  errno_t eVar1;
  
  eVar1 = __wcstombs_s_l(_PtNumOfCharConverted,_Dst,_DstSizeInBytes,_Src,_MaxCountInBytes,
                         (_locale_t)0x0);
  return eVar1;
}

