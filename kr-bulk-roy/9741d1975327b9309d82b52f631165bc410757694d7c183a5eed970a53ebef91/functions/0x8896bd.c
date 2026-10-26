
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,unsigned int &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,unsigned int &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,int param_6,uint *param_7,int *param_8)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  char *local_48;
  undefined4 *local_44;
  undefined1 local_40 [4];
  int local_3c;
  char *local_38;
  char local_34;
  char local_33 [43];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_8;
  puVar1 = param_7;
  iVar5 = param_6;
  uStack_4 = 0x38;
  local_8 = 0x8896c9;
  local_3c = 0;
  local_44 = param_1;
  uVar4 = FUN_004318d0(local_40);
  local_8 = 0;
  uVar4 = Getifld(local_38,&local_34,&param_2,&param_4,*(undefined4 *)(iVar5 + 0x14),uVar4);
  local_8 = 0xffffffff;
  FUN_004327c0();
  local_38 = local_33;
  if (local_34 != '-') {
    local_38 = &local_34;
  }
  iVar5 = __Stoulx(local_38,&local_48,uVar4,&local_3c);
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_48 == local_38) || (local_3c != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    if (local_34 == '-') {
      iVar5 = -iVar5;
    }
    *piVar2 = iVar5;
  }
  *local_44 = param_2;
  local_44[1] = param_3;
  FUN_0089dbbc();
  return;
}

