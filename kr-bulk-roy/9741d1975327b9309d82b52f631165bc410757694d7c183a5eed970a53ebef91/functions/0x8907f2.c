
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::money_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char>
   > >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,bool,class
   std::ios_base &,char,class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > const &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::do_put
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,char *param_8)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 auStack_6c [16];
  undefined4 uStack_5c;
  char *pcStack_58;
  int iStack_54;
  undefined1 *local_40;
  undefined4 local_3c;
  money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *local_38;
  uint local_34;
  undefined1 local_30 [16];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8907fe;
  local_3c = param_6;
  if (0xf < *(uint *)(param_8 + 0x14)) {
    param_8 = *(char **)param_8;
  }
  uVar1 = local_34 >> 8;
  local_34 = local_34 & 0xffffff00;
  if (*param_8 == '-') {
    local_34 = CONCAT31((int3)uVar1,1);
    param_8 = param_8 + 1;
  }
  iVar3 = 0;
  cVar2 = *param_8;
  while (('/' < cVar2 && (cVar2 < ':'))) {
    iVar3 = iVar3 + 1;
    cVar2 = param_8[iVar3];
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = 0;
  uStack_5c = 0x89084f;
  pcStack_58 = param_8;
  iStack_54 = iVar3;
  FUN_00402a70();
  local_8 = 0;
  if (iVar3 == 0) {
    iStack_54 = 0x30;
    pcStack_58 = (char *)0x1;
    uStack_5c = 0x890862;
    FUN_00429630();
  }
  local_40 = auStack_6c;
  FUN_00403130(local_30);
  _Putmfld(local_38,param_2,param_3,param_4,param_5,local_3c,param_7,local_34);
  iStack_54 = 0;
  pcStack_58 = (char *)0x1;
  uStack_5c = 0x890899;
  FUN_00402f30();
  iStack_54 = 0x8908a0;
  FUN_0089dbbc();
  return;
}

