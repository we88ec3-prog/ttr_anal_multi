
/* Library Function - Single Match
    __Strxfrm
   
   Library: Visual Studio 2010 Release */

size_t __cdecl __Strxfrm(char *_String1,char *_End1,char *param_3,char *param_4,_Collvec *param_5)

{
  int iVar1;
  wchar_t *_Code_page;
  size_t sVar2;
  uint _CchDest;
  uint _Size;
  size_t local_8;
  
  local_8 = 0xffffffff;
  _CchDest = (int)_End1 - (int)_String1;
  _Size = (int)param_4 - (int)param_3;
  if (param_5 == (_Collvec *)0x0) {
    iVar1 = ____lc_handle_func();
    param_4 = *(char **)(iVar1 + 4);
    _Code_page = (wchar_t *)____lc_collate_cp_func();
  }
  else {
    param_4 = (char *)param_5->_Page;
    _Code_page = param_5->_LocaleName;
  }
  if ((param_4 == (char *)0x0) && (_Code_page == (wchar_t *)0x0)) {
    local_8 = _Size;
    if (_Size <= _CchDest) {
      FID_conflict__memcpy(_String1,param_3,_Size);
    }
  }
  else {
    sVar2 = ___crtLCMapStringA((_locale_t)0x0,(LPCWSTR)param_4,0x400,param_3,_Size,(LPSTR)0x0,0,
                               (int)_Code_page,1);
    if ((sVar2 != 0) && (local_8 = sVar2, (int)sVar2 <= (int)_CchDest)) {
      ___crtLCMapStringA((_locale_t)0x0,(LPCWSTR)param_4,0x400,param_3,_Size,_String1,_CchDest,
                         (int)_Code_page,1);
    }
  }
  return local_8;
}

