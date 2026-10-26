
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,void *
   &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this;
  uint *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  istreambuf_iterator<char,std::char_traits<char>_> *local_48;
  undefined1 local_44 [4];
  int local_40;
  undefined4 local_3c;
  char *local_38;
  istreambuf_iterator<char,std::char_traits<char>_> local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = in_stack_00000020;
  puVar1 = in_stack_0000001c;
  uStack_4 = 0x38;
  local_8 = 0x87fca8;
  local_40 = 0;
  FUN_004318d0(local_44);
  local_8 = 0;
  local_38 = (char *)_Getifld(this,local_38,local_34,
                              (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                              (int)&stack0x00000010,(locale *)0x800);
  local_8 = 0xffffffff;
  FUN_004327c0();
  local_3c = __Stoulx(local_34,&local_48,local_38,&local_40);
  local_38 = (char *)0x0;
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&stack0x00000010);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_48 == local_34) || (local_40 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *puVar2 = local_3c;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  FUN_0089dbbc();
  return;
}

