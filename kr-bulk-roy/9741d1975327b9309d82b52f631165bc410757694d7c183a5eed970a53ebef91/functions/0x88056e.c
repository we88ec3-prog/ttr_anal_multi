
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,double
   &)const 
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,long
   double &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,int *param_6,uint *param_7,double *param_8)

{
  uint *puVar1;
  double *pdVar2;
  bool bVar3;
  int iVar4;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  float10 fVar5;
  int *piVar6;
  double local_58;
  istreambuf_iterator<char,std::char_traits<char>_> *local_50;
  int local_4c;
  int local_48;
  istreambuf_iterator<char,std::char_traits<char>_> local_44 [60];
  uint local_8;
  
  pdVar2 = param_8;
  puVar1 = param_7;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48 = 0;
  local_4c = 0;
  piVar6 = &local_48;
  iVar4 = std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getffld
                    (in_ECX,(char *)in_ECX,local_44,
                     (istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (ios_base *)&param_4,param_6);
  fVar5 = (float10)FUN_00890b8c(local_44,&local_50,iVar4,piVar6);
  local_58 = (double)fVar5;
  if (local_4c != 0) {
    local_58 = _ldexp(local_58,local_4c << 2);
  }
  bVar3 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar3) {
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

