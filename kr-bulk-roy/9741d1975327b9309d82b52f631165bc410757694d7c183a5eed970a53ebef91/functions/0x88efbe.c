
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::time_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,struct tm const *,char,char)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::do_put
          (time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,tm *param_7,undefined1 param_8,char param_9)

{
  size_t sVar1;
  char ****ppppcVar2;
  int iVar3;
  char ***local_38 [4];
  size_t local_28;
  uint local_24;
  undefined4 local_1c;
  undefined1 uStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_28 = 0;
  uStack_18 = 0;
  local_24 = 0xf;
  local_38[0] = (char ***)((uint)local_38[0] & 0xffffff00);
  local_8 = 0;
  if (param_9 == '\0') {
    local_1c._0_3_ = CONCAT12(param_8,0x2521);
    local_1c = (uint)(uint3)local_1c;
  }
  else {
    local_1c._0_3_ = CONCAT12(param_9,0x2521);
    local_1c = CONCAT13(param_8,(uint3)local_1c);
  }
  iVar3 = 0x10;
  while( true ) {
    FUN_00429630(iVar3,0);
    ppppcVar2 = (char ****)local_38[0];
    if (local_24 < 0x10) {
      ppppcVar2 = local_38;
    }
    sVar1 = __Strftime((char *)ppppcVar2,local_28,(char *)&local_1c,param_7,*(void **)(this + 8));
    if (sVar1 != 0) break;
    iVar3 = iVar3 * 2;
  }
  ppppcVar2 = (char ****)local_38[0];
  if (local_24 < 0x10) {
    ppppcVar2 = local_38;
  }
  while (sVar1 = sVar1 - 1, sVar1 != 0) {
    ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
    FUN_006efb60(*(char *)ppppcVar2);
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

