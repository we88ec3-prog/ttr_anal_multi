
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: int __cdecl std::num_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Getifld(char *,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,int,class
   std::locale const &)const 
    private: int __cdecl std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Getifld(char *,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,int,class std::locale const &)const 
   
   Library: Visual Studio 2010 Release */

void Getifld(int param_1,char *param_2,int param_3,undefined4 param_4,uint param_5,
            undefined4 param_6)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int *piVar8;
  void *pvVar9;
  char ****ppppcVar10;
  int iVar11;
  size_t local_70;
  char local_5c;
  char *local_58;
  char ***local_4c [4];
  int local_3c;
  uint local_38;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x88714f;
  piVar8 = (int *)FUN_00430690(param_6);
  FUN_0042fd00(local_4c);
  sVar4 = 0;
  local_8 = 0;
  if (local_3c != 0) {
    sVar4 = (**(code **)(*piVar8 + 8))();
  }
  param_1 = param_1 + 8;
  sVar5 = FUN_004303a0(0x30,0,param_1);
  local_58 = param_2;
  cVar2 = equal(param_4);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar7 = *(short *)(param_3 + 6);
    sVar6 = FUN_004303a0(0x2b,0,param_1);
    if (sVar7 == sVar6) {
      *param_2 = '+';
    }
    else {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar7 = *(short *)(param_3 + 6);
      sVar6 = FUN_004303a0(0x2d,0,param_1);
      if (sVar7 != sVar6) goto LAB_0088721b;
      *param_2 = '-';
    }
    local_58 = param_2 + 1;
    Inc();
  }
LAB_0088721b:
  param_5 = param_5 & 0xe00;
  if (param_5 == 0x400) {
    bVar3 = 8;
  }
  else if (param_5 == 0x800) {
    bVar3 = 0x10;
  }
  else {
    bVar3 = -(param_5 != 0) & 10;
  }
  local_5c = '\0';
  bVar1 = false;
  cVar2 = equal(param_4);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if (*(short *)(param_3 + 6) != sVar5) goto LAB_0088730d;
    local_5c = '\x01';
    Inc();
    cVar2 = equal(param_4);
    if (cVar2 != '\0') {
LAB_008872ff:
      if (bVar3 == 0) {
        bVar3 = 8;
        goto LAB_0088730d;
      }
      goto LAB_00887314;
    }
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar5 = *(short *)(param_3 + 6);
    sVar7 = FUN_004303a0(0x78,0,param_1);
    if (sVar5 != sVar7) {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar5 = *(short *)(param_3 + 6);
      sVar7 = FUN_004303a0(0x58,0,param_1);
      if (sVar5 != sVar7) goto LAB_008872ff;
    }
    if ((bVar3 != 0) && (bVar3 != 0x10)) goto LAB_008872ff;
    bVar3 = 0x10;
    local_5c = '\0';
    Inc();
LAB_0088731a:
    local_70 = ((bVar3 != 8) - 1 & 0xfffffff2) + 0x16;
  }
  else {
LAB_0088730d:
    if (bVar3 != 0) {
LAB_00887314:
      if (bVar3 != 10) goto LAB_0088731a;
    }
    local_70 = 10;
  }
  iVar11 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  FUN_0046e1b0(1,local_5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  cVar2 = equal(param_4);
  if (cVar2 == '\0') {
    do {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      cVar2 = _Maklocbyte<>(*(undefined2 *)(param_3 + 6),param_1);
      *local_58 = cVar2;
      pvVar9 = _memchr("0123456789abcdefABCDEF",(int)cVar2,local_70);
      if (pvVar9 == (void *)0x0) {
        ppppcVar10 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar10 = local_30;
        }
        if ((*(char *)((int)ppppcVar10 + iVar11) == '\0') || (sVar4 == 0)) break;
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        if (*(short *)(param_3 + 6) != sVar4) break;
        FUN_00429630(1,0);
        iVar11 = iVar11 + 1;
      }
      else {
        if (((bVar1) || (*local_58 != '0')) && (local_58 < param_2 + 0x1f)) {
          local_58 = local_58 + 1;
          bVar1 = true;
        }
        local_5c = '\x01';
        ppppcVar10 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar10 = local_30;
        }
        if (*(char *)((int)ppppcVar10 + iVar11) != '\x7f') {
          ppppcVar10 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar10 = local_30;
          }
          *(char *)((int)ppppcVar10 + iVar11) = *(char *)((int)ppppcVar10 + iVar11) + '\x01';
        }
      }
      Inc();
      cVar2 = equal(param_4);
    } while (cVar2 == '\0');
    if (iVar11 != 0) {
      ppppcVar10 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar10 = local_30;
      }
      if (*(char *)((int)ppppcVar10 + iVar11) < '\x01') {
        local_5c = '\0';
      }
      else {
        iVar11 = iVar11 + 1;
      }
    }
  }
  if (local_38 < 0x10) {
    local_4c[0] = (char ***)local_4c;
  }
  if (local_5c == '\0') {
LAB_008874b5:
    local_58 = param_2;
  }
  else {
    while ((iVar11 != 0 && (cVar2 = *(char *)local_4c[0], cVar2 != '\x7f'))) {
      iVar11 = iVar11 + -1;
      if (iVar11 != 0) {
        ppppcVar10 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar10 = local_30;
        }
        if (cVar2 != *(char *)((int)ppppcVar10 + iVar11)) goto LAB_008874b5;
      }
      if (iVar11 == 0) {
        ppppcVar10 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar10 = local_30;
        }
        if (cVar2 < *(char *)ppppcVar10) goto LAB_008874b5;
      }
      if ('\0' < *(char *)((int)local_4c[0] + 1)) {
        local_4c[0] = (char ***)((int)local_4c[0] + 1);
      }
    }
    if (!bVar1) {
      *local_58 = '0';
      local_58 = local_58 + 1;
    }
  }
  *local_58 = '\0';
  FUN_00402f30(1,0);
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

