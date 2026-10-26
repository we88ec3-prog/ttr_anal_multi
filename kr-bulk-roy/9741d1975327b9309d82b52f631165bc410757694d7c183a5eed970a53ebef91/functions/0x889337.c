
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,void * &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,void * &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  undefined1 *local_48;
  undefined1 local_44 [4];
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = in_stack_00000020;
  puVar1 = in_stack_0000001c;
  uStack_4 = 0x38;
  local_8 = 0x889343;
  local_40 = 0;
  uVar4 = FUN_004318d0(local_44);
  local_8 = 0;
  local_38 = Getifld(local_38,local_34,&param_2,&stack0x00000010,0x800,uVar4);
  local_8 = 0xffffffff;
  FUN_004327c0();
  local_3c = __Stoulx(local_34,&local_48,local_38,&local_40);
  local_38 = 0;
  cVar3 = equal(&stack0x00000010);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_48 == local_34) || (local_40 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *puVar2 = local_3c;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_0089dbbc();
  return;
}

