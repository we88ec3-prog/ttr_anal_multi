
/* Library Function - Multiple Matches With Same Base Name
    private: int __cdecl std::time_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Getint(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,int,int,int
   &)const 
    private: int __cdecl std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Getint(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,int,int,int &)const 
   
   Library: Visual Studio 2010 Release */

void Getint(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  undefined4 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  char *pcVar5;
  char *local_44;
  int *local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  char local_29;
  char local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  param_1 = param_1 + 0x14;
  local_34 = param_3;
  local_40 = param_6;
  local_30 = _Maklocchr<>(0x30,0,param_1);
  local_30 = local_30 & 0xffff;
  pcVar5 = local_28;
  cVar2 = equal(local_34);
  if (cVar2 == '\0') {
    if (*(char *)(param_2 + 4) == '\0') {
      Peek();
    }
    local_38 = (uint)*(ushort *)(param_2 + 6);
    sVar3 = _Maklocchr<>(0x2b,0,param_1);
    if ((short)local_38 == sVar3) {
      local_28[0] = '+';
    }
    else {
      if (*(char *)(param_2 + 4) == '\0') {
        Peek();
      }
      local_38 = (uint)*(ushort *)(param_2 + 6);
      sVar3 = _Maklocchr<>(0x2d,0,param_1);
      if ((short)local_38 != sVar3) goto LAB_00883b1e;
      local_28[0] = '-';
    }
    pcVar5 = local_28 + 1;
    Inc();
  }
LAB_00883b1e:
  uVar1 = local_34;
  local_29 = '\0';
  cVar2 = equal(local_34);
  if (cVar2 == '\0') {
    do {
      if (*(char *)(param_2 + 4) == '\0') {
        Peek();
      }
      if (*(short *)(param_2 + 6) != (ushort)local_30) break;
      local_29 = '\x01';
      Inc();
      cVar2 = equal(uVar1);
    } while (cVar2 == '\0');
    if (local_29 != '\0') {
      *pcVar5 = '0';
      pcVar5 = pcVar5 + 1;
    }
  }
  while (cVar2 = equal(uVar1), cVar2 == '\0') {
    if (*(char *)(param_2 + 4) == '\0') {
      Peek();
    }
    if (*(ushort *)(param_2 + 6) < (ushort)local_30) break;
    if (*(char *)(param_2 + 4) == '\0') {
      Peek();
    }
    if ((local_30 & 0xffff) + 9 < (uint)*(ushort *)(param_2 + 6)) break;
    if (*(char *)(param_2 + 4) == '\0') {
      Peek();
    }
    *pcVar5 = (*(char *)(param_2 + 6) - (char)local_30) + '0';
    if (pcVar5 < local_28 + 0x1f) {
      pcVar5 = pcVar5 + 1;
    }
    local_29 = '\x01';
    Inc();
  }
  if (local_29 == '\0') {
    pcVar5 = local_28;
  }
  *pcVar5 = '\0';
  local_3c = 0;
  iVar4 = __Stolx(local_28,&local_44,10,&local_3c);
  equal(local_34);
  if ((((local_44 != local_28) && (local_3c == 0)) && (param_4 <= iVar4)) && (iVar4 <= param_5)) {
    *local_40 = iVar4;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

