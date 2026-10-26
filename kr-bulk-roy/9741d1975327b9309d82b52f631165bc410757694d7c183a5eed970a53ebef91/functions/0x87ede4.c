
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    private: int __cdecl std::num_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Getifld(char *,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > &,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   &,int,class std::locale const &)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getifld
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,char *param_1
          ,istreambuf_iterator<char,std::char_traits<char>_> *param_2,
          istreambuf_iterator<char,std::char_traits<char>_> *param_3,int param_4,locale *param_5)

{
  istreambuf_iterator<char,std::char_traits<char>_> iVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  void *pvVar8;
  char ****ppppcVar9;
  int iVar10;
  size_t local_64;
  char local_5c;
  istreambuf_iterator<char,std::char_traits<char>_> *local_54;
  istreambuf_iterator<char,std::char_traits<char>_> local_4e;
  char ***local_4c [4];
  int local_3c;
  uint local_38;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x87edf0;
  piVar6 = (int *)FUN_006efcf0();
  FUN_0042fd00(local_4c);
  local_8 = 0;
  if (local_3c == 0) {
    local_4e = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
  }
  else {
    local_4e = (istreambuf_iterator<char,std::char_traits<char>_>)(**(code **)(*piVar6 + 8))();
  }
  local_54 = param_2;
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_4);
  if (!bVar3) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] == (istreambuf_iterator<char,std::char_traits<char>_>)0x2b) {
      *param_2 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2b;
    }
    else {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) goto LAB_0087ee7b;
      *param_2 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
    }
    local_54 = param_2 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
LAB_0087ee7b:
  uVar7 = (uint)param_5 & 0xe00;
  if (uVar7 == 0x400) {
    bVar4 = 8;
  }
  else if (uVar7 == 0x800) {
    bVar4 = 0x10;
  }
  else {
    bVar4 = -(uVar7 != 0) & 10;
  }
  local_5c = '\0';
  bVar3 = false;
  bVar5 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_4);
  if (bVar5) {
LAB_0087ef42:
    if (bVar4 != 0) {
LAB_0087ef48:
      if (bVar4 != 10) goto LAB_0087ef4d;
    }
    local_64 = 10;
  }
  else {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) goto LAB_0087ef42;
    local_5c = '\x01';
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    bVar5 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_4);
    if (bVar5) {
LAB_0087ef35:
      if (bVar4 == 0) {
        bVar4 = 8;
        goto LAB_0087ef42;
      }
      goto LAB_0087ef48;
    }
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x78) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x58) goto LAB_0087ef35;
    }
    if ((bVar4 != 0) && (bVar4 != 0x10)) goto LAB_0087ef35;
    bVar4 = 0x10;
    local_5c = '\0';
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
LAB_0087ef4d:
    local_64 = ((bVar4 != 8) - 1 & 0xfffffff2) + 0x16;
  }
  local_20 = 0;
  local_1c = 0xf;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  FUN_0046e1b0(1,local_5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar10 = 0;
  bVar5 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_4);
  if (!bVar5) {
    do {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      iVar1 = param_3[5];
      *local_54 = iVar1;
      pvVar8 = _memchr("0123456789abcdefABCDEF",(int)(char)iVar1,local_64);
      if (pvVar8 == (void *)0x0) {
        ppppcVar9 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar9 = local_30;
        }
        if ((*(char *)((int)ppppcVar9 + iVar10) == '\0') ||
           (local_4e == (istreambuf_iterator<char,std::char_traits<char>_>)0x0)) break;
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if (param_3[5] != local_4e) break;
        FUN_00429630(1,0);
        iVar10 = iVar10 + 1;
      }
      else {
        if (((bVar3) || (*local_54 != (istreambuf_iterator<char,std::char_traits<char>_>)0x30)) &&
           (local_54 < param_2 + 0x1f)) {
          local_54 = local_54 + 1;
          bVar3 = true;
        }
        local_5c = '\x01';
        ppppcVar9 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar9 = local_30;
        }
        if (*(char *)((int)ppppcVar9 + iVar10) != '\x7f') {
          ppppcVar9 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar9 = local_30;
          }
          *(char *)((int)ppppcVar9 + iVar10) = *(char *)((int)ppppcVar9 + iVar10) + '\x01';
        }
      }
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
      bVar5 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)param_4
                        );
    } while (!bVar5);
    if (iVar10 != 0) {
      ppppcVar9 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar9 = local_30;
      }
      if (*(char *)((int)ppppcVar9 + iVar10) < '\x01') {
        local_5c = '\0';
      }
      else {
        iVar10 = iVar10 + 1;
      }
    }
  }
  if (local_38 < 0x10) {
    local_4c[0] = (char ***)local_4c;
  }
  if (local_5c == '\0') {
LAB_0087f0d9:
    local_54 = param_2;
  }
  else {
    while ((iVar10 != 0 && (cVar2 = *(char *)local_4c[0], cVar2 != '\x7f'))) {
      iVar10 = iVar10 + -1;
      if (iVar10 != 0) {
        ppppcVar9 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar9 = local_30;
        }
        if (cVar2 != *(char *)((int)ppppcVar9 + iVar10)) goto LAB_0087f0d9;
      }
      if (iVar10 == 0) {
        ppppcVar9 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar9 = local_30;
        }
        if (cVar2 < *(char *)ppppcVar9) goto LAB_0087f0d9;
      }
      if ('\0' < *(char *)((int)local_4c[0] + 1)) {
        local_4c[0] = (char ***)((int)local_4c[0] + 1);
      }
    }
    if (!bVar3) {
      *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      local_54 = local_54 + 1;
    }
  }
  *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
  FUN_00402f30(1,0);
  FUN_00402f30(1,0);
  iVar10 = FUN_0089dbbc();
  return iVar10;
}

