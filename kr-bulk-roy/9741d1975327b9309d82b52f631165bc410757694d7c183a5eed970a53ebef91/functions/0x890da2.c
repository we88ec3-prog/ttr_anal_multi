
/* Library Function - Single Match
    __Wcsxfrm
   
   Library: Visual Studio 2010 Release */

size_t __cdecl
__Wcsxfrm(wchar_t *_String1,wchar_t *_End1,wchar_t *param_3,wchar_t *param_4,_Collvec *param_5)

{
  int iVar1;
  LPCWSTR _LocaleName;
  LPWSTR _LpDestStr;
  uint uVar2;
  uint _CchSrc;
  uint uVar3;
  
  _CchSrc = (int)param_4 - (int)param_3 >> 1;
  uVar3 = (int)_End1 - (int)_String1 >> 1;
  if (param_5 == (_Collvec *)0x0) {
    iVar1 = ____lc_handle_func();
    _LocaleName = *(LPCWSTR *)(iVar1 + 4);
  }
  else {
    _LocaleName = (LPCWSTR)param_5->_Page;
  }
  if (_LocaleName == (LPCWSTR)0x0) {
    uVar2 = _CchSrc;
    if (_CchSrc <= uVar3) {
      FID_conflict__memcpy(_String1,param_3,_CchSrc * 2);
    }
  }
  else {
    _LpDestStr = __malloc_crt(uVar3);
    uVar2 = 0xffffffff;
    if (_LpDestStr != (LPWSTR)0x0) {
      uVar2 = ___crtLCMapStringW(_LocaleName,0x400,param_3,_CchSrc,_LpDestStr,uVar3);
      uVar3 = 0;
      if (uVar2 == 0) {
        uVar2 = ___crtLCMapStringW(_LocaleName,0x400,param_3,_CchSrc,(LPWSTR)0x0,0);
        if (uVar2 == 0) {
          uVar2 = 0x7fffffff;
        }
      }
      else if (uVar2 != 0) {
        do {
          _String1[uVar3] = (ushort)*(byte *)(uVar3 + (int)_LpDestStr);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
      }
      _free(_LpDestStr);
    }
  }
  return uVar2;
}

