
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,int>::do_out(int &,unsigned
   short const *,unsigned short const *,unsigned short const * &,char *,char *,char * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,int>::do_out(int &,wchar_t const
   *,wchar_t const *,wchar_t const * &,char *,char *,char * &)const 
   
   Library: Visual Studio 2010 Release */

void do_out(mbstate_t *param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,
           int *param_7)

{
  char *pcVar1;
  mbstate_t mVar2;
  int iVar3;
  size_t _Size;
  int in_ECX;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *param_4 = param_2;
  *param_7 = param_5;
  iVar3 = *param_4;
  do {
    if ((iVar3 == param_3) || (*param_7 == param_6)) goto LAB_00880e53;
    pcVar1 = (char *)*param_7;
    iVar3 = ____mb_cur_max_func();
    if (param_6 - (int)pcVar1 < iVar3) {
      mVar2 = *param_1;
      _Size = __Wcrtomb(local_10,*(wchar_t *)*param_4,param_1,(_Cvtvec *)(in_ECX + 8));
      if ((int)_Size < 0) goto LAB_00880e53;
      if (param_6 - *param_7 < (int)_Size) {
        *param_1 = mVar2;
LAB_00880e53:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      FID_conflict__memcpy((void *)*param_7,local_10,_Size);
      *param_4 = *param_4 + 2;
      *param_7 = *param_7 + _Size;
    }
    else {
      iVar3 = __Wcrtomb(pcVar1,*(wchar_t *)*param_4,param_1,(_Cvtvec *)(in_ECX + 8));
      if (iVar3 < 0) goto LAB_00880e53;
      *param_4 = *param_4 + 2;
      *param_7 = *param_7 + iVar3;
    }
    iVar3 = *param_4;
  } while( true );
}

