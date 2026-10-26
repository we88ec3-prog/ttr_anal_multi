
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get_date(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,struct
   tm *)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get_date
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,uint *param_8,int param_9)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_00;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_01;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_02;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_03;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_04;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_05;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_06;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_07;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *ptVar4;
  int *piVar5;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = (**(code **)(*(int *)this + 4))();
  if (local_8 == 0) {
    local_8 = 2;
  }
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  puVar1 = param_8;
  if (bVar2) goto LAB_0088e8a9;
  ptVar4 = extraout_ECX;
  if ((char)param_4 == '\0') {
    istreambuf_iterator<char,std::char_traits<char>_>::_Peek
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    ptVar4 = extraout_ECX_00;
  }
  if (param_4._1_1_ < '0') {
LAB_0088e85a:
    (**(code **)(*(int *)this + 0x14))
              (&local_10,param_3,param_4,param_5,param_6,param_7,puVar1,param_9);
    local_8 = 2;
LAB_0088e87f:
    param_3 = local_10;
    param_4 = local_c;
  }
  else {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      ptVar4 = extraout_ECX_01;
    }
    if ('9' < param_4._1_1_) goto LAB_0088e85a;
    if (local_8 != 2) {
      if (local_8 == 1) {
        uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                        (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                        1,(int *)0x1f);
        *puVar1 = *puVar1 | uVar3;
        goto LAB_0088e8a9;
      }
      (**(code **)(*(int *)this + 0x18))
                (&local_10,param_3,param_4,param_5,param_6,param_7,puVar1,param_9);
      goto LAB_0088e87f;
    }
    piVar5 = (int *)(param_9 + 0x10);
    uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,1,
                    (int *)0xc);
    *puVar1 = *puVar1 | uVar3;
    *piVar5 = *piVar5 + -1;
  }
LAB_0088e8a9:
  while (bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                           ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                            (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5),
        !bVar2) {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ != ' ') break;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
  }
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar2) goto LAB_0088e922;
  if ((char)param_4 == '\0') {
    istreambuf_iterator<char,std::char_traits<char>_>::_Peek
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
  }
  if (param_4._1_1_ != ':') {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ != ',') {
      if ((char)param_4 == '\0') {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      }
      if (param_4._1_1_ != '/') goto LAB_0088e922;
    }
  }
  do {
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
LAB_0088e922:
    bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                       (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
    if (bVar2) break;
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
  } while (param_4._1_1_ == ' ');
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (!bVar2) {
    ptVar4 = extraout_ECX_02;
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      ptVar4 = extraout_ECX_03;
    }
    if ('/' < param_4._1_1_) {
      if ((char)param_4 == '\0') {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
        ptVar4 = extraout_ECX_04;
      }
      if (param_4._1_1_ < ':') {
        if ((local_8 == 1) || (local_8 == 3)) {
          piVar5 = (int *)(param_9 + 0x10);
          uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                          (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                          (int)&param_5,1,(int *)0xc);
          *puVar1 = *puVar1 | uVar3;
          *piVar5 = *piVar5 + -1;
        }
        else {
          uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                          (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                          (int)&param_5,1,(int *)0x1f);
          *puVar1 = *puVar1 | uVar3;
        }
        goto LAB_0088ea1e;
      }
    }
    if (local_8 == 2) {
      *puVar1 = *puVar1 | 2;
    }
    else {
      (**(code **)(*(int *)this + 0x14))
                (&local_10,param_3,param_4,param_5,param_6,param_7,puVar1,param_9);
      param_3 = local_10;
      param_4 = local_c;
      if (local_8 == 4) {
        local_8 = 3;
      }
    }
  }
LAB_0088ea1e:
  while (bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                           ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                            (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5),
        !bVar2) {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ != ' ') break;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
  }
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar2) goto LAB_0088ea97;
  if ((char)param_4 == '\0') {
    istreambuf_iterator<char,std::char_traits<char>_>::_Peek
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
  }
  if (param_4._1_1_ != ':') {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ != ',') {
      if ((char)param_4 == '\0') {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      }
      if (param_4._1_1_ != '/') goto LAB_0088ea97;
    }
  }
  do {
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
LAB_0088ea97:
    bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                       (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
    if (bVar2) break;
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
  } while (param_4._1_1_ == ' ');
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar2) {
LAB_0088eb5a:
    *puVar1 = *puVar1 | 2;
  }
  else {
    ptVar4 = extraout_ECX_05;
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      ptVar4 = extraout_ECX_06;
    }
    if (param_4._1_1_ < '0') {
LAB_0088eb54:
      if (local_8 != 4) goto LAB_0088eb5a;
      (**(code **)(*(int *)this + 0x14))
                (&local_10,param_3,param_4,param_5,param_6,param_7,puVar1,param_9);
    }
    else {
      if ((char)param_4 == '\0') {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
        ptVar4 = extraout_ECX_07;
      }
      if ('9' < param_4._1_1_) goto LAB_0088eb54;
      if (local_8 == 4) {
        piVar5 = (int *)(param_9 + 0x10);
        uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                        (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                        1,(int *)0xc);
        *puVar1 = *puVar1 | uVar3;
        *piVar5 = *piVar5 + -1;
        goto LAB_0088eb89;
      }
      if (local_8 == 3) {
        uVar3 = _Getint(ptVar4,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                        (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                        1,(int *)0x1f);
        *puVar1 = *puVar1 | uVar3;
        goto LAB_0088eb89;
      }
      (**(code **)(*(int *)this + 0x18))
                (&local_10,param_3,param_4,param_5,param_6,param_7,puVar1,param_9);
    }
    param_3 = local_10;
    param_4 = local_c;
  }
LAB_0088eb89:
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar2) {
    *puVar1 = *puVar1 | 1;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
}

