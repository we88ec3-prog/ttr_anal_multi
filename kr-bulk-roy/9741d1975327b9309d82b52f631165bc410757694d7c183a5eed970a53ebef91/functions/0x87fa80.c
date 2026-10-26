
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int
   &,unsigned long &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int param_7,uint *param_8,undefined4 *param_9)

{
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this_00;
  istreambuf_iterator<char,std::char_traits<char>_> *local_44;
  undefined4 *local_40;
  undefined1 local_3c [4];
  int local_38;
  istreambuf_iterator<char,std::char_traits<char>_> local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = param_9;
  puVar1 = param_8;
  iVar4 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x87fa8c;
  local_38 = 0;
  local_40 = param_2;
  FUN_004318d0(local_3c);
  local_8 = 0;
  this_00 = (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)&local_38;
  iVar4 = _Getifld(this_00,(char *)this,local_34,
                   (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                   *(locale **)(iVar4 + 0x14));
  uVar5 = __Stoulx(local_34,&local_44,iVar4,this_00);
  local_8 = 0xffffffff;
  FUN_004327c0();
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_44 == local_34) || (local_38 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *puVar2 = uVar5;
  }
  *local_40 = param_3;
  local_40[1] = param_4;
  FUN_0089dbbc();
  return;
}

