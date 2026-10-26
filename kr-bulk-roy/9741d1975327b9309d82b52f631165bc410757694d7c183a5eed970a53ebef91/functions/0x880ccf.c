
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,int>::do_in(int &,char const
   *,char const *,char const * &,unsigned short *,unsigned short *,unsigned short * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,int>::do_in(int &,char const *,char
   const *,char const * &,wchar_t *,wchar_t *,wchar_t * &)const 
   
   Library: Visual Studio 2010 Release */

bool do_in(mbstate_t *param_1,int param_2,int param_3,int *param_4,int param_5,wchar_t *param_6,
          int *param_7)

{
  int iVar1;
  size_t sVar2;
  int in_ECX;
  bool bVar3;
  
  *param_4 = param_2;
  *param_7 = param_5;
  iVar1 = *param_4;
  bVar3 = iVar1 != param_3;
  do {
    if (iVar1 == param_3) {
      return bVar3;
    }
    if ((wchar_t *)*param_7 == param_6) {
      return bVar3;
    }
    iVar1 = __Mbrtowc((wchar_t *)*param_7,(char *)*param_4,param_3 - *param_4,param_1,
                      (_Cvtvec *)(in_ECX + 8));
    if (iVar1 == -2) {
      *param_4 = param_3;
      return bVar3;
    }
    if (iVar1 == -1) {
      return (bool)2;
    }
    if (iVar1 == 0) {
      if (*(short *)*param_7 == 0) {
        sVar2 = _strlen((char *)*param_4);
        iVar1 = sVar2 + 1;
        goto LAB_00880d3e;
      }
    }
    else {
LAB_00880d3e:
      if (iVar1 == -3) {
        iVar1 = 0;
      }
    }
    *param_4 = *param_4 + iVar1;
    *param_7 = *param_7 + 2;
    bVar3 = false;
    iVar1 = *param_4;
  } while( true );
}

