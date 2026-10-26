
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,int>::do_length(int const
   &,char const *,char const *,unsigned int)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,int>::do_length(int const &,char
   const *,char const *,unsigned int)const 
   
   Library: Visual Studio 2010 Release */

uint do_length(mbstate_t *param_1,char *param_2,char *param_3,uint param_4)

{
  int iVar1;
  size_t sVar2;
  int in_ECX;
  uint uVar3;
  char *_Str;
  mbstate_t local_8;
  
  local_8 = *param_1;
  uVar3 = 0;
  _Str = param_2;
  if (param_4 != 0) {
    while (_Str != param_3) {
      iVar1 = __Mbrtowc((wchar_t *)&param_1,_Str,(int)param_3 - (int)_Str,&local_8,
                        (_Cvtvec *)(in_ECX + 8));
      if (iVar1 == -2) {
        return uVar3;
      }
      if (iVar1 == -1) {
        return uVar3;
      }
      if (iVar1 == 0) {
        if ((wchar_t)param_1 == L'\0') {
          sVar2 = _strlen(_Str);
          iVar1 = sVar2 + 1;
          goto LAB_00880ebd;
        }
      }
      else {
LAB_00880ebd:
        if (iVar1 == -3) {
          iVar1 = 0;
        }
      }
      _Str = _Str + iVar1;
      uVar3 = uVar3 + 1;
      if (param_4 <= uVar3) {
        return uVar3;
      }
    }
  }
  return uVar3;
}

