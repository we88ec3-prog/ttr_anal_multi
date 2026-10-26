
/* Library Function - Single Match
    private: int __cdecl std::time_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Getint(class std::istreambuf_iterator<char,struct
   std::char_traits<char> > &,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   &,int,int,int &)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getint
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          istreambuf_iterator<char,std::char_traits<char>_> *param_1,
          istreambuf_iterator<char,std::char_traits<char>_> *param_2,int param_3,int param_4,
          int *param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar4;
  int *in_stack_00000018;
  istreambuf_iterator<char,std::char_traits<char>_> *local_34;
  int local_30;
  istreambuf_iterator<char,struct_std::char_traits<char>_> *local_2c;
  istreambuf_iterator<char,std::char_traits<char>_> local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2c = (istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_3;
  piVar4 = local_28;
  bVar1 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_2,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_3);
  if (!bVar1) {
    if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
    }
    if (param_2[5] == (istreambuf_iterator<char,std::char_traits<char>_>)0x2b) {
      local_28[0] = (istreambuf_iterator<char,std::char_traits<char>_>)0x2b;
    }
    else {
      if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
      }
      if (param_2[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) goto LAB_0088e3d4;
      local_28[0] = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
    }
    piVar4 = local_28 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
  }
LAB_0088e3d4:
  bVar1 = false;
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_2c);
  if (!bVar2) {
    do {
      if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
      }
      if (param_2[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) break;
      bVar1 = true;
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
      bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_2c);
    } while (!bVar2);
    if (bVar1) {
      *piVar4 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      piVar4 = piVar4 + 1;
    }
  }
  while (bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_2c), !bVar2)
  {
    if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
    }
    if ((char)param_2[5] < '0') break;
    if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
    }
    if ('9' < (char)param_2[5]) break;
    if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
    }
    *piVar4 = param_2[5];
    if (piVar4 < local_28 + 0x1f) {
      piVar4 = piVar4 + 1;
    }
    bVar1 = true;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
  }
  if (!bVar1) {
    piVar4 = local_28;
  }
  *piVar4 = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
  local_30 = 0;
  iVar3 = __Stolx(local_28,&local_34,10,&local_30);
  istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_2c);
  if ((((local_34 != local_28) && (local_30 == 0)) && (param_4 <= iVar3)) && (iVar3 <= (int)param_5)
     ) {
    *in_stack_00000018 = iVar3;
  }
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

