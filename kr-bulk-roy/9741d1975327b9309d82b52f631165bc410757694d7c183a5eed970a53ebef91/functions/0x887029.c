
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::time_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,struct tm const *,char,char)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::time_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,struct tm const *,char,char)const 
   
   Library: Visual Studio 2010 Release */

void do_put(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,tm *param_6,undefined1 param_7,char param_8)

{
  size_t sVar1;
  char ****ppppcVar2;
  int iVar3;
  size_t sVar4;
  char *_Str;
  mbstate_t local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 *local_40;
  int local_3c;
  char ***local_38 [4];
  size_t local_28;
  uint local_24;
  undefined4 local_1c;
  undefined1 uStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_28 = 0;
  local_40 = param_1;
  uStack_18 = 0;
  local_24 = 0xf;
  local_38[0] = (char ***)((uint)local_38[0] & 0xffffff00);
  local_8 = 0;
  if (param_8 == '\0') {
    local_1c._0_3_ = CONCAT12(param_7,0x2521);
    local_1c = (uint)(uint3)local_1c;
  }
  else {
    local_1c._0_3_ = CONCAT12(param_8,0x2521);
    local_1c = CONCAT13(param_7,(uint3)local_1c);
  }
  local_3c = 0x10;
  while( true ) {
    FUN_00429630(local_3c,0);
    ppppcVar2 = (char ****)local_38[0];
    if (local_24 < 0x10) {
      ppppcVar2 = local_38;
    }
    sVar1 = __Strftime((char *)ppppcVar2,local_28,(char *)&local_1c,param_6,*(void **)(local_48 + 8)
                      );
    if (sVar1 != 0) break;
    local_3c = local_3c * 2;
  }
  local_4c = 0;
  sVar1 = sVar1 - 1;
  ppppcVar2 = (char ****)local_38[0];
  if (local_24 < 0x10) {
    ppppcVar2 = local_38;
  }
  _Str = (char *)((int)ppppcVar2 + 1);
  if (sVar1 != 0) {
    do {
      iVar3 = __Mbrtowc((wchar_t *)&local_44,_Str,sVar1,&local_4c,(_Cvtvec *)(local_48 + 0xc));
      if (iVar3 == -3) {
        iVar3 = 0;
      }
      else if (-3 < iVar3) {
        if (iVar3 < 0) break;
        if ((iVar3 == 0) && ((wchar_t)local_44 == L'\0')) {
          sVar4 = _strlen(_Str);
          iVar3 = sVar4 + 1;
        }
      }
      sVar1 = sVar1 - iVar3;
      _Str = _Str + iVar3;
      FID_conflict_operator_(local_44);
    } while (sVar1 != 0);
  }
  *local_40 = param_2;
  local_40[1] = param_3;
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

