
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,unsigned long &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,unsigned long &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,int param_6,uint *param_7,undefined4 *param_8)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  undefined1 *local_44;
  undefined4 *local_40;
  undefined1 local_3c [4];
  int local_38;
  undefined1 local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar3 = param_8;
  puVar2 = param_7;
  iVar1 = param_6;
  uStack_4 = 0x38;
  local_8 = 0x889842;
  local_38 = 0;
  local_40 = param_1;
  uVar5 = FUN_004318d0(local_3c);
  local_8 = 0;
  uVar5 = Getifld(in_ECX,local_34,&param_2,&param_4,*(undefined4 *)(iVar1 + 0x14),uVar5,&local_38);
  uVar5 = __Stoulx(local_34,&local_44,uVar5);
  local_8 = 0xffffffff;
  FUN_004327c0();
  cVar4 = equal(&param_4);
  if (cVar4 != '\0') {
    *puVar2 = *puVar2 | 1;
  }
  if ((local_44 == local_34) || (local_38 != 0)) {
    *puVar2 = *puVar2 | 2;
  }
  else {
    *puVar3 = uVar5;
  }
  *local_40 = param_2;
  local_40[1] = param_3;
  FUN_0089dbbc();
  return;
}

