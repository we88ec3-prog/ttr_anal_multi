
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::time_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   >::do_get_date(class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> >,class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short>
   >,class std::ios_base &,int &,struct tm *)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get_date(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,struct tm *)const 
   
   Library: Visual Studio 2010 Release */

void do_get_date(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,uint *param_7,int param_8)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int *in_ECX;
  int *piVar5;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  piVar5 = in_ECX + 5;
  local_c = FUN_004303a0(0x30,0,piVar5);
  local_c = local_c & 0xffff;
  local_14 = FUN_004303a0(0x3a,0,piVar5);
  local_14 = local_14 & 0xffff;
  local_18 = FUN_004303a0(0x2c,0,piVar5);
  local_18 = local_18 & 0xffff;
  local_1c = FUN_004303a0(0x2f,0,piVar5);
  local_1c = local_1c & 0xffff;
  local_10 = FUN_004303a0(0x20,0,piVar5);
  local_10 = local_10 & 0xffff;
  local_8 = (**(code **)(*in_ECX + 4))();
  if (local_8 == 0) {
    local_8 = 2;
  }
  cVar2 = equal(&param_4);
  puVar1 = param_7;
  if (cVar2 != '\0') goto LAB_0088438d;
  if ((char)param_3 == '\0') {
    Peek();
  }
  if (param_3._2_2_ < (ushort)local_c) {
LAB_0088433f:
    (**(code **)(*in_ECX + 0x14))(&local_24,param_2,param_3,param_4,param_5,param_6,puVar1,param_8);
    local_8 = 2;
LAB_00884360:
    param_2 = local_24;
    param_3 = local_20;
  }
  else {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if ((local_c & 0xffff) + 9 < param_3 >> 0x10) goto LAB_0088433f;
    if (local_8 != 2) {
      if (local_8 == 1) {
        uVar3 = Getint();
        *puVar1 = *puVar1 | uVar3;
        goto LAB_0088438d;
      }
      (**(code **)(*in_ECX + 0x18))
                (&local_24,param_2,param_3,param_4,param_5,param_6,puVar1,param_8);
      goto LAB_00884360;
    }
    piVar5 = (int *)(param_8 + 0x10);
    uVar3 = Getint();
    *puVar1 = *puVar1 | uVar3;
    *piVar5 = *piVar5 + -1;
  }
LAB_0088438d:
  while( true ) {
    cVar2 = equal(&param_4);
    if (cVar2 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ != (ushort)local_10) break;
    Inc();
  }
  uVar3 = local_10;
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') goto LAB_00884415;
  if ((char)param_3 == '\0') {
    Peek();
  }
  if (param_3._2_2_ != (ushort)local_14) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ != (ushort)local_18) {
      if ((char)param_3 == '\0') {
        Peek();
      }
      if (param_3._2_2_ != (ushort)local_1c) goto LAB_00884415;
    }
  }
  do {
    Inc();
LAB_00884415:
    cVar2 = equal(&param_4);
    if (cVar2 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
  } while (param_3._2_2_ == (ushort)uVar3);
  cVar2 = equal(&param_4);
  if (cVar2 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if ((ushort)local_c <= param_3._2_2_) {
      if ((char)param_3 == '\0') {
        Peek();
      }
      if (param_3 >> 0x10 <= (local_c & 0xffff) + 9) {
        if ((local_8 == 1) || (local_8 == 3)) {
          piVar5 = (int *)(param_8 + 0x10);
          uVar3 = Getint();
          *puVar1 = *puVar1 | uVar3;
          *piVar5 = *piVar5 + -1;
          uVar3 = local_10;
        }
        else {
          uVar4 = Getint();
          *puVar1 = *puVar1 | uVar4;
        }
        goto LAB_00884521;
      }
    }
    if (local_8 == 2) {
      *puVar1 = *puVar1 | 2;
    }
    else {
      (**(code **)(*in_ECX + 0x14))
                (&local_24,param_2,param_3,param_4,param_5,param_6,puVar1,param_8);
      param_2 = local_24;
      param_3 = local_20;
      if (local_8 == 4) {
        local_8 = 3;
      }
    }
  }
LAB_00884521:
  while( true ) {
    cVar2 = equal(&param_4);
    if (cVar2 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ != (ushort)uVar3) break;
    Inc();
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') goto LAB_008845a6;
  if ((char)param_3 == '\0') {
    Peek();
  }
  if (param_3._2_2_ != (ushort)local_14) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ != (ushort)local_18) {
      if ((char)param_3 == '\0') {
        Peek();
      }
      if (param_3._2_2_ != (ushort)local_1c) goto LAB_008845a6;
    }
  }
  do {
    Inc();
LAB_008845a6:
    cVar2 = equal(&param_4);
    if (cVar2 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
  } while (param_3._2_2_ == (ushort)uVar3);
  cVar2 = equal(&param_4);
  if (cVar2 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    uVar3 = local_c;
    if (param_3._2_2_ < (ushort)local_c) {
LAB_0088466e:
      if (local_8 != 4) goto LAB_00884674;
      (**(code **)(*in_ECX + 0x14))
                (&local_24,param_2,param_3,param_4,param_5,param_6,puVar1,param_8);
    }
    else {
      if ((char)param_3 == '\0') {
        Peek();
      }
      if ((uVar3 & 0xffff) + 9 < param_3 >> 0x10) goto LAB_0088466e;
      if (local_8 == 4) {
        piVar5 = (int *)(param_8 + 0x10);
        uVar3 = Getint();
        *puVar1 = *puVar1 | uVar3;
        *piVar5 = *piVar5 + -1;
        goto LAB_008846a3;
      }
      if (local_8 == 3) {
        uVar3 = Getint();
        *puVar1 = *puVar1 | uVar3;
        goto LAB_008846a3;
      }
      (**(code **)(*in_ECX + 0x18))
                (&local_24,param_2,param_3,param_4,param_5,param_6,puVar1,param_8);
    }
    param_2 = local_24;
    param_3 = local_20;
  }
  else {
LAB_00884674:
    *puVar1 = *puVar1 | 2;
  }
LAB_008846a3:
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

