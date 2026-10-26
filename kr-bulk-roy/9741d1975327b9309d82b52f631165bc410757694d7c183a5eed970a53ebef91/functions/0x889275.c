
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,long double &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,long double &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,uint *param_7,double *param_8)

{
  uint *puVar1;
  double *pdVar2;
  char cVar3;
  undefined4 uVar4;
  float10 fVar5;
  int *piVar6;
  double local_58;
  undefined1 *local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [60];
  uint local_8;
  
  pdVar2 = param_8;
  puVar1 = param_7;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48 = 0;
  local_4c = 0;
  piVar6 = &local_48;
  uVar4 = Getffld();
  fVar5 = (float10)FUN_00890bf5(local_44,&local_50,uVar4,piVar6);
  local_58 = (double)fVar5;
  if (local_4c != 0) {
    local_58 = _ldexp(local_58,local_4c << 2);
  }
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_50 == local_44) || (local_48 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *pdVar2 = local_58;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

