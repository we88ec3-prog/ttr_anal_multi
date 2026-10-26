
/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __cdecl std::_Maklocstr<unsigned short>(char const *,unsigned short *,struct
   _Cvtvec const &)
    wchar_t * __cdecl std::_Maklocstr<wchar_t>(char const *,wchar_t *,struct _Cvtvec const &)
   
   Library: Visual Studio 2010 Release */

wchar_t * _Maklocstr<>(char *param_1,undefined4 param_2,_Cvtvec *param_3)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  mbstate_t local_14;
  mbstate_t local_10;
  wchar_t *local_c;
  wchar_t local_8 [2];
  
  iVar5 = 0;
  local_10 = 0;
  sVar1 = _strlen(param_1);
  sVar4 = sVar1 + 1;
  local_c = (wchar_t *)param_1;
  while ((sVar4 != 0 &&
         (iVar2 = __Mbrtowc(local_8,(char *)local_c,sVar4,&local_10,param_3), 0 < iVar2))) {
    local_c = (wchar_t *)((int)local_c + iVar2);
    iVar5 = iVar5 + 1;
    sVar4 = sVar4 - iVar2;
  }
  uVar6 = iVar5 + 1;
  pwVar3 = (wchar_t *)
           FUN_0087dc3d(-(uint)((int)((ulonglong)uVar6 * 2 >> 0x20) != 0) |
                        (uint)((ulonglong)uVar6 * 2));
  local_14 = 0;
  local_c = pwVar3;
  while ((uVar6 != 0 && (iVar5 = __Mbrtowc(pwVar3,param_1,sVar1 + 1,&local_14,param_3), 0 < iVar5)))
  {
    param_1 = param_1 + iVar5;
    pwVar3 = pwVar3 + 1;
    uVar6 = uVar6 - 1;
  }
  *pwVar3 = L'\0';
  return local_c;
}

