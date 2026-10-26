
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    private: int __cdecl std::num_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Getffldx(char *,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > &,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   &,class std::ios_base &,int *)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getffldx
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,char *param_1
          ,istreambuf_iterator<char,std::char_traits<char>_> *param_2,
          istreambuf_iterator<char,std::char_traits<char>_> *param_3,ios_base *param_4,int *param_5)

{
  char cVar1;
  istreambuf_iterator<char,std::char_traits<char>_> iVar2;
  bool bVar3;
  istreambuf_iterator<char,std::char_traits<char>_> iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  char ****ppppcVar8;
  lconv *plVar9;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *pnVar10;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_00;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_01;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_02;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_03;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_04;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *extraout_ECX_05;
  int iVar11;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar12;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar13;
  int *in_stack_00000018;
  char cVar14;
  ios_base *piVar15;
  undefined1 local_74 [4];
  int *local_70;
  int *local_6c;
  int local_68;
  int local_64;
  istreambuf_iterator<char,std::char_traits<char>_> local_5d;
  ios_base *local_5c;
  char local_55;
  istreambuf_iterator<char,std::char_traits<char>_> *local_54;
  char local_4d;
  char ***local_4c [4];
  int local_3c;
  uint local_38;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x87f112;
  local_5c = param_4;
  local_6c = in_stack_00000018;
  uVar5 = FUN_004318d0(local_74);
  local_8 = 0;
  piVar6 = (int *)FUN_006efcf0(uVar5);
  local_8 = 0xffffffff;
  local_70 = piVar6;
  FUN_004327c0();
  FUN_0042fd00(local_4c);
  local_8 = 1;
  local_54 = param_2;
  local_55 = '\0';
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_5c);
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
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) goto LAB_0087f1ae;
      *param_2 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
    }
    local_54 = param_2 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
LAB_0087f1ae:
  piVar15 = local_5c;
  local_64 = 0;
  local_68 = 0;
  *(undefined2 *)local_54 = 0x7830;
  local_54 = local_54 + 2;
  local_4d = '\0';
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_5c);
  if (!bVar3) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] == (istreambuf_iterator<char,std::char_traits<char>_>)0x30) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
      bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar15
                        );
      if (bVar3) {
LAB_0087f22a:
        local_4d = '\x01';
      }
      else {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x78) {
          if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          }
          if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x58)
          goto LAB_0087f22a;
        }
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
      }
    }
  }
  ppppcVar8 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar8 = local_4c;
  }
  cVar14 = (char)param_1;
  if (*(char *)ppppcVar8 == '\x7f') {
LAB_0087f46b:
    while (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                             (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                      piVar15), !bVar3) {
      pnVar10 = extraout_ECX_03;
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        pnVar10 = extraout_ECX_02;
      }
      iVar11 = _Hexdig(pnVar10,cVar14,(char)param_3[5],'0','a');
      if (iVar11 < 0) break;
      if (local_64 < 0x24) {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if ((param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) ||
           (local_64 != 0)) {
          local_64 = local_64 + 1;
          *local_54 = *(istreambuf_iterator<char,std::char_traits<char>_> *)
                       ("0123456789abcdef" + iVar11);
          local_54 = local_54 + 1;
        }
      }
      else {
        local_68 = local_68 + 1;
      }
      local_4d = '\x01';
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
      piVar15 = local_5c;
    }
  }
  else {
    ppppcVar8 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar8 = local_4c;
    }
    if (*(char *)ppppcVar8 < '\x01') goto LAB_0087f46b;
    if (local_3c == 0) {
      local_5d = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
    }
    else {
      local_5d = (istreambuf_iterator<char,std::char_traits<char>_>)(**(code **)(*piVar6 + 8))();
    }
    local_20 = 0;
    local_1c = 0xf;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    FUN_0046e1b0(1,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar11 = 0;
    bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar15);
    pnVar10 = extraout_ECX;
    if (!bVar3) {
      do {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          pnVar10 = extraout_ECX_00;
        }
        iVar7 = _Hexdig(pnVar10,cVar14,(char)param_3[5],'0','a');
        if (iVar7 < 0) {
          ppppcVar8 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar8 = local_30;
          }
          if ((*(char *)((int)ppppcVar8 + iVar11) == '\0') ||
             (local_5d == (istreambuf_iterator<char,std::char_traits<char>_>)0x0)) break;
          if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          }
          if (param_3[5] != local_5d) break;
          FUN_00429630(1,0);
          iVar11 = iVar11 + 1;
        }
        else {
          local_4d = '\x01';
          if (local_64 < 0x24) {
            if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
            }
            if ((param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) ||
               (local_64 != 0)) {
              local_64 = local_64 + 1;
              *local_54 = *(istreambuf_iterator<char,std::char_traits<char>_> *)
                           ("0123456789abcdef" + iVar7);
              local_54 = local_54 + 1;
            }
          }
          else {
            local_68 = local_68 + 1;
          }
          ppppcVar8 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar8 = local_30;
          }
          if (*(char *)((int)ppppcVar8 + iVar11) != '\x7f') {
            ppppcVar8 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar8 = local_30;
            }
            *(char *)((int)ppppcVar8 + iVar11) = *(char *)((int)ppppcVar8 + iVar11) + '\x01';
          }
        }
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
        bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                          (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                   local_5c);
        pnVar10 = extraout_ECX_01;
      } while (!bVar3);
      if (iVar11 != 0) {
        ppppcVar8 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar8 = local_30;
        }
        if (*(char *)((int)ppppcVar8 + iVar11) < '\x01') {
          local_55 = '\x01';
        }
        else {
          iVar11 = iVar11 + 1;
        }
      }
    }
    if (local_38 < 0x10) {
      local_4c[0] = (char ***)local_4c;
    }
    if (local_55 == '\0') {
      while( true ) {
        if ((iVar11 == 0) || (cVar1 = *(char *)local_4c[0], cVar1 == '\x7f')) goto LAB_0087f3ea;
        iVar11 = iVar11 + -1;
        if (iVar11 != 0) break;
LAB_0087f3c9:
        if (iVar11 == 0) {
          ppppcVar8 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar8 = local_30;
          }
          if (cVar1 < *(char *)ppppcVar8) goto LAB_0087f3e6;
        }
        if ('\0' < *(char *)((int)local_4c[0] + 1)) {
          local_4c[0] = (char ***)((int)local_4c[0] + 1);
        }
      }
      ppppcVar8 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar8 = local_30;
      }
      if (cVar1 == *(char *)((int)ppppcVar8 + iVar11)) goto LAB_0087f3c9;
LAB_0087f3e6:
      local_55 = '\x01';
    }
LAB_0087f3ea:
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00402f30(1,0);
  }
  if ((local_4d != '\0') && (local_64 == 0)) {
    *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
    local_54 = local_54 + 1;
  }
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_5c);
  if (!bVar3) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    iVar2 = param_3[5];
    iVar4 = (istreambuf_iterator<char,std::char_traits<char>_>)(**(code **)(*local_70 + 4))();
    if (iVar2 == iVar4) {
      plVar9 = _localeconv();
      *local_54 = *(istreambuf_iterator<char,std::char_traits<char>_> *)plVar9->decimal_point;
      local_54 = local_54 + 1;
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
  }
  piVar12 = local_54;
  if (local_64 == 0) {
    while (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                             (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                      local_5c), !bVar3) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) break;
      local_68 = local_68 + -1;
      local_4d = '\x01';
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
    piVar12 = local_54;
    if (local_68 < 0) {
      *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      local_68 = local_68 + 1;
      piVar12 = local_54 + 1;
    }
  }
  while (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                           (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                    local_5c), !bVar3) {
    pnVar10 = extraout_ECX_05;
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      pnVar10 = extraout_ECX_04;
    }
    iVar11 = _Hexdig(pnVar10,cVar14,(char)param_3[5],'0','a');
    if (iVar11 < 0) break;
    if (local_64 < 0x24) {
      *piVar12 = *(istreambuf_iterator<char,std::char_traits<char>_> *)("0123456789abcdef" + iVar11)
      ;
      piVar12 = piVar12 + 1;
      local_64 = local_64 + 1;
    }
    local_4d = '\x01';
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
  piVar13 = piVar12;
  if ((local_4d == '\0') ||
     (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                 local_5c), bVar3)) goto LAB_0087f6a5;
  if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
    istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
  }
  if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x70) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x50) goto LAB_0087f6a5;
  }
  *piVar12 = (istreambuf_iterator<char,std::char_traits<char>_>)0x70;
  piVar13 = piVar12 + 1;
  istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  local_4d = '\0';
  iVar11 = 0;
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_5c);
  if (!bVar3) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] == (istreambuf_iterator<char,std::char_traits<char>_>)0x2b) {
      *piVar13 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2b;
    }
    else {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) goto LAB_0087f605;
      *piVar13 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
    }
    piVar13 = piVar12 + 2;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
LAB_0087f605:
  bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_5c);
  if (!bVar3) {
    do {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) break;
      local_4d = '\x01';
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
      bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                 local_5c);
    } while (!bVar3);
    if (local_4d != '\0') {
      *piVar13 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      piVar13 = piVar13 + 1;
    }
  }
  while (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                           (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                    local_5c), !bVar3) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if ((char)param_3[5] < '0') break;
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if ('9' < (char)param_3[5]) break;
    if (iVar11 < 8) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      *piVar13 = param_3[5];
      piVar13 = piVar13 + 1;
      iVar11 = iVar11 + 1;
    }
    local_4d = '\x01';
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
LAB_0087f6a5:
  if ((local_55 != '\0') || (local_4d == '\0')) {
    piVar13 = param_2;
  }
  *piVar13 = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
  *local_6c = local_68;
  FUN_00402f30(1,0);
  iVar11 = FUN_0089dbbc();
  return iVar11;
}

