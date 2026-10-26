
/* Library Function - Single Match
    ___crtCompareStringW
   
   Library: Visual Studio 2010 Release */

int __cdecl
___crtCompareStringW
          (LPCWSTR _LocaleName,DWORD _DwCmpFlags,LPCWSTR _LpString1,int _CchCount1,
          LPCWSTR _LpString2,int _CchCount2)

{
  int iVar1;
  
  if (0 < _CchCount1) {
    _CchCount1 = _wcsnlen(_LpString1,_CchCount1);
  }
  if (0 < _CchCount2) {
    _CchCount2 = _wcsnlen(_LpString2,_CchCount2);
  }
  if ((_CchCount1 == 0) || (_CchCount2 == 0)) {
    if (_CchCount1 == _CchCount2) {
      iVar1 = 2;
    }
    else {
      iVar1 = (uint)(-1 < _CchCount1 - _CchCount2) * 2 + 1;
    }
  }
  else {
    iVar1 = CompareStringW((LCID)_LocaleName,_DwCmpFlags,_LpString1,_CchCount1,_LpString2,_CchCount2
                          );
  }
  return iVar1;
}

