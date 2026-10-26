
/* Library Function - Single Match
    __Wcscoll
   
   Library: Visual Studio 2010 Release */

int __cdecl
__Wcscoll(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4,_Collvec *param_5)

{
  int iVar1;
  LPCWSTR _LocaleName;
  int *piVar2;
  int _CchCount1;
  int _CchCount2;
  
  _CchCount1 = (int)param_2 - (int)param_1 >> 1;
  _CchCount2 = (int)param_4 - (int)param_3 >> 1;
  if (param_5 == (_Collvec *)0x0) {
    iVar1 = ____lc_handle_func();
    _LocaleName = *(LPCWSTR *)(iVar1 + 4);
  }
  else {
    _LocaleName = (LPCWSTR)param_5->_Page;
  }
  if (_LocaleName == (LPCWSTR)0x0) {
    iVar1 = _CchCount1;
    if (_CchCount2 <= _CchCount1) {
      iVar1 = _CchCount2;
    }
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (*param_1 != *param_3) {
        iVar1 = (-(uint)((ushort)*param_1 < (ushort)*param_3) & 0xfffffffe) + 1;
        goto LAB_00890d4d;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
    }
    iVar1 = 0;
LAB_00890d4d:
    if ((iVar1 == 0) && (_CchCount1 != _CchCount2)) {
      iVar1 = (uint)(_CchCount2 <= _CchCount1) * 2 + -1;
    }
  }
  else {
    iVar1 = ___crtCompareStringW(_LocaleName,0x1000,param_1,_CchCount1,param_3,_CchCount2);
    if (iVar1 == 0) {
      piVar2 = __errno();
      *piVar2 = 0x16;
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = iVar1 + -2;
    }
  }
  return iVar1;
}

