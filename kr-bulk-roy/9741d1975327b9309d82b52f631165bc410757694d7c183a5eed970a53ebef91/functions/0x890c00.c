
/* Library Function - Single Match
    __Strcoll
   
   Library: Visual Studio 2010 Release */

int __cdecl __Strcoll(char *param_1,char *param_2,char *param_3,char *param_4,_Collvec *param_5)

{
  int iVar1;
  wchar_t *_Code_page;
  size_t _Size;
  int *piVar2;
  LPCWSTR _LocaleName;
  size_t _CchCount1;
  size_t _CchCount2;
  
  _CchCount1 = (int)param_2 - (int)param_1;
  _CchCount2 = (int)param_4 - (int)param_3;
  if (param_5 == (_Collvec *)0x0) {
    iVar1 = ____lc_handle_func();
    _LocaleName = *(LPCWSTR *)(iVar1 + 4);
    _Code_page = (wchar_t *)____lc_collate_cp_func();
  }
  else {
    _LocaleName = (LPCWSTR)param_5->_Page;
    _Code_page = param_5->_LocaleName;
  }
  if (_LocaleName == (LPCWSTR)0x0) {
    _Size = _CchCount1;
    if ((int)_CchCount2 <= (int)_CchCount1) {
      _Size = _CchCount2;
    }
    iVar1 = _memcmp(param_1,param_3,_Size);
    if ((iVar1 == 0) && (_CchCount1 != _CchCount2)) {
      iVar1 = (uint)((int)_CchCount2 <= (int)_CchCount1) * 2 + -1;
    }
  }
  else {
    iVar1 = ___crtCompareStringA
                      ((_locale_t)0x0,_LocaleName,0x1000,param_1,_CchCount1,param_3,_CchCount2,
                       (int)_Code_page);
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

