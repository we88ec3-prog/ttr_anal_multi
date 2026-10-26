
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int
   &,unsigned int &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,int param_7,uint *param_8,int *param_9)

{
  uint *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this;
  istreambuf_iterator<char,std::char_traits<char>_> *local_48;
  undefined4 *local_44;
  undefined1 local_40 [4];
  int local_3c;
  istreambuf_iterator<char,std::char_traits<char>_> *local_38;
  istreambuf_iterator<char,std::char_traits<char>_> local_34;
  istreambuf_iterator<char,std::char_traits<char>_> local_33 [43];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_9;
  puVar1 = param_8;
  iVar4 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x87f913;
  local_3c = 0;
  local_44 = param_2;
  FUN_004318d0(local_40);
  local_8 = 0;
  iVar4 = _Getifld(this,(char *)local_38,&local_34,
                   (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                   *(locale **)(iVar4 + 0x14));
  local_8 = 0xffffffff;
  FUN_004327c0();
  local_38 = local_33;
  if (local_34 != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) {
    local_38 = &local_34;
  }
  iVar4 = __Stoulx(local_38,&local_48,iVar4,&local_3c);
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_48 == local_38) || (local_3c != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    if (local_34 == (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) {
      iVar4 = -iVar4;
    }
    *piVar2 = iVar4;
  }
  *local_44 = param_3;
  local_44[1] = param_4;
  FUN_0089dbbc();
  return;
}

