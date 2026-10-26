
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,float &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,float &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,uint *param_7,float *param_8)

{
  uint *puVar1;
  float *pfVar2;
  char cVar3;
  undefined4 uVar4;
  float10 fVar5;
  int *piVar6;
  undefined1 *local_54;
  int local_50;
  int local_4c;
  float local_48;
  undefined1 local_44 [60];
  uint local_8;
  
  pfVar2 = param_8;
  puVar1 = param_7;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  local_50 = 0;
  piVar6 = &local_4c;
  uVar4 = Getffld();
  fVar5 = (float10)__Stofx(local_44,&local_54,uVar4,piVar6);
  local_48 = (float)fVar5;
  if (local_50 != 0) {
    fVar5 = (float10)ldexpf(local_48,local_50 << 2);
    local_48 = (float)fVar5;
  }
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_54 == local_44) || (local_4c != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *pfVar2 = local_48;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

