
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,float
   &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int *param_7,uint *param_8,float *param_9)

{
  uint *puVar1;
  float *pfVar2;
  bool bVar3;
  int iVar4;
  float10 fVar5;
  int *piVar6;
  istreambuf_iterator<char,std::char_traits<char>_> *local_54;
  int local_50;
  int local_4c;
  float local_48;
  istreambuf_iterator<char,std::char_traits<char>_> local_44 [60];
  uint local_8;
  
  pfVar2 = param_9;
  puVar1 = param_8;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  local_50 = 0;
  piVar6 = &local_4c;
  iVar4 = _Getffld(this,(char *)this,local_44,
                   (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                   (ios_base *)&param_5,param_7);
  fVar5 = (float10)__Stofx(local_44,&local_54,iVar4,piVar6);
  local_48 = (float)fVar5;
  if (local_50 != 0) {
    fVar5 = (float10)ldexpf(local_48,local_50 << 2);
    local_48 = (float)fVar5;
  }
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if ((local_54 == local_44) || (local_4c != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *pfVar2 = local_48;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

