
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,long
   double &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int *param_7,uint *param_8,double *param_9)

{
  uint *puVar1;
  double *pdVar2;
  bool bVar3;
  int iVar4;
  float10 fVar5;
  int *piVar6;
  double local_58;
  istreambuf_iterator<char,std::char_traits<char>_> *local_50;
  int local_4c;
  int local_48;
  istreambuf_iterator<char,std::char_traits<char>_> local_44 [60];
  uint local_8;
  
  pdVar2 = param_9;
  puVar1 = param_8;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48 = 0;
  local_4c = 0;
  piVar6 = &local_48;
  iVar4 = _Getffld(this,(char *)this,local_44,
                   (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                   (ios_base *)&param_5,param_7);
  fVar5 = (float10)FUN_00890bf5(local_44,&local_50,iVar4,piVar6);
  local_58 = (double)fVar5;
  if (local_4c != 0) {
    local_58 = _ldexp(local_58,local_4c << 2);
  }
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_50 == local_44) || (local_48 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *pdVar2 = local_58;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

