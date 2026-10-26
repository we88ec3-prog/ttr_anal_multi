
/* Library Function - Single Match
    __wcstombs_s_l
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl
__wcstombs_s_l(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,wchar_t *_Src,
              size_t _MaxCountInBytes,_locale_t _Locale)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  errno_t local_8;
  
  local_8 = 0;
  if (_Dst == (char *)0x0) {
    if (_DstSizeInBytes == 0) goto LAB_008980d8;
  }
  else if (_DstSizeInBytes != 0) {
LAB_008980d8:
    if (_Dst != (char *)0x0) {
      *_Dst = '\0';
    }
    if (_PtNumOfCharConverted != (size_t *)0x0) {
      *_PtNumOfCharConverted = 0;
    }
    sVar1 = _MaxCountInBytes;
    if (_DstSizeInBytes < _MaxCountInBytes) {
      sVar1 = _DstSizeInBytes;
    }
    if (sVar1 < 0x80000000) {
      iVar2 = __wcstombs_l_helper(_Dst,_Src,sVar1,_Locale);
      if (iVar2 == -1) {
        if (_Dst != (char *)0x0) {
          *_Dst = '\0';
        }
        piVar3 = __errno();
        return *piVar3;
      }
      uVar4 = iVar2 + 1;
      if (_Dst != (char *)0x0) {
        if (_DstSizeInBytes < uVar4) {
          if ((_MaxCountInBytes != 0xffffffff) && (*_Dst = '\0', _DstSizeInBytes <= uVar4)) {
            piVar3 = __errno();
            iVar2 = 0x22;
            goto LAB_00898126;
          }
          local_8 = 0x50;
          uVar4 = _DstSizeInBytes;
        }
        _Dst[uVar4 - 1] = '\0';
      }
      if (_PtNumOfCharConverted == (size_t *)0x0) {
        return local_8;
      }
      *_PtNumOfCharConverted = uVar4;
      return local_8;
    }
  }
  piVar3 = __errno();
  iVar2 = 0x16;
LAB_00898126:
  *piVar3 = iVar2;
  FUN_00893343();
  return iVar2;
}

