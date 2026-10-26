
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,int>::do_unshift(int &,char
   *,char *,char * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,int>::do_unshift(int &,char *,char
   *,char * &)const 
   
   Library: Visual Studio 2010 Release */

void do_unshift(mbstate_t *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int in_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  size_t _Size;
  mbstate_t mVar3;
  undefined4 uVar4;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar4 = 0;
  *param_4 = param_2;
  mVar3 = *param_1;
  iVar1 = __Wcrtomb(local_10,L'\0',param_1,(_Cvtvec *)(in_ECX + 8));
  uVar2 = extraout_EDX;
  if (iVar1 < 1) {
    uVar4 = 2;
  }
  else {
    _Size = iVar1 - 1;
    if (param_3 - *param_4 < (int)_Size) {
      *param_1 = mVar3;
      uVar4 = 1;
    }
    else if (0 < (int)_Size) {
      FID_conflict__memcpy((void *)*param_4,local_10,_Size);
      *param_4 = *param_4 + _Size;
      uVar2 = extraout_EDX_00;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,uVar2,mVar3,uVar4);
  return;
}

