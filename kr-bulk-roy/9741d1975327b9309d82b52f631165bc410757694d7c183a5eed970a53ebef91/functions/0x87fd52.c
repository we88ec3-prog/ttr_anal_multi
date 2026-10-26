
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    private: int __cdecl std::num_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Getffld(char *,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > &,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   &,class std::ios_base &,int *)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getffld
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,char *param_1
          ,istreambuf_iterator<char,std::char_traits<char>_> *param_2,
          istreambuf_iterator<char,std::char_traits<char>_> *param_3,ios_base *param_4,int *param_5)

{
  char cVar1;
  istreambuf_iterator<char,std::char_traits<char>_> iVar2;
  ios_base *piVar3;
  bool bVar4;
  istreambuf_iterator<char,std::char_traits<char>_> iVar5;
  undefined4 uVar6;
  char ****ppppcVar7;
  lconv *plVar8;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar9;
  int iVar10;
  undefined1 local_70 [4];
  istreambuf_iterator<char,std::char_traits<char>_> *local_6c;
  int *local_68;
  ios_base *local_64;
  int local_60;
  int local_5c;
  istreambuf_iterator<char,std::char_traits<char>_> local_56;
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
  
  uStack_4 = 0x60;
  local_8 = 0x87fd5e;
  local_64 = param_4;
  local_6c = param_2;
  if ((param_5[5] & 0x3000U) == 0x3000) {
    _Getffldx((num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)param_5,
              param_1,param_2,param_3,param_4,param_5);
    goto LAB_008802f9;
  }
  uVar6 = FUN_004318d0(local_70);
  local_8 = 0;
  local_68 = (int *)FUN_006efcf0(uVar6);
  local_8 = 0xffffffff;
  FUN_004327c0();
  FUN_0042fd00(local_4c);
  local_8 = 1;
  local_54 = param_2;
  local_55 = '\0';
  bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_64);
  if (!bVar4) {
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
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d) goto LAB_0087fe1a;
      *param_2 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
    }
    local_54 = param_2 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
  }
LAB_0087fe1a:
  local_4d = '\0';
  local_5c = 0;
  local_60 = 0;
  ppppcVar7 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar7 = local_4c;
  }
  if (*(char *)ppppcVar7 == '\x7f') {
LAB_0087fff4:
    bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_64)
    ;
    if (!bVar4) {
      do {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if ((char)param_3[5] < '0') break;
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if ('9' < (char)param_3[5]) break;
        if (local_5c < 0x24) {
          if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          }
          if ((param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) ||
             (local_5c != 0)) {
            if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
            }
            local_5c = local_5c + 1;
            *local_54 = param_3[5];
            local_54 = local_54 + 1;
          }
        }
        else {
          local_60 = local_60 + 1;
        }
        local_4d = '\x01';
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
        bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                          (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                   local_64);
      } while (!bVar4);
      goto LAB_00880084;
    }
  }
  else {
    ppppcVar7 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar7 = local_4c;
    }
    if (*(char *)ppppcVar7 < '\x01') goto LAB_0087fff4;
    if (local_3c == 0) {
      local_56 = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
    }
    else {
      local_56 = (istreambuf_iterator<char,std::char_traits<char>_>)(**(code **)(*local_68 + 8))();
    }
    iVar10 = 0;
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    FUN_0046e1b0(1,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_64)
    ;
    if (!bVar4) {
      do {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if ((char)param_3[5] < '0') {
LAB_0087ff1f:
          ppppcVar7 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar7 = local_30;
          }
          if ((*(char *)((int)ppppcVar7 + iVar10) == '\0') ||
             (local_56 == (istreambuf_iterator<char,std::char_traits<char>_>)0x0)) break;
          if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          }
          if (param_3[5] != local_56) break;
          FUN_00429630(1,0);
          iVar10 = iVar10 + 1;
        }
        else {
          if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
          }
          if ('9' < (char)param_3[5]) goto LAB_0087ff1f;
          local_4d = '\x01';
          if (local_5c < 0x24) {
            if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
            }
            if ((param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) ||
               (local_5c != 0)) {
              if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
              }
              local_5c = local_5c + 1;
              *local_54 = param_3[5];
              local_54 = local_54 + 1;
            }
          }
          else {
            local_60 = local_60 + 1;
          }
          ppppcVar7 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar7 = local_30;
          }
          if (*(char *)((int)ppppcVar7 + iVar10) != '\x7f') {
            ppppcVar7 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar7 = local_30;
            }
            *(char *)((int)ppppcVar7 + iVar10) = *(char *)((int)ppppcVar7 + iVar10) + '\x01';
          }
        }
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
        bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                          (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                   local_64);
      } while (!bVar4);
      if (iVar10 != 0) {
        ppppcVar7 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar7 = local_30;
        }
        if (*(char *)((int)ppppcVar7 + iVar10) < '\x01') {
          local_55 = '\x01';
        }
        else {
          iVar10 = iVar10 + 1;
        }
      }
    }
    if (local_38 < 0x10) {
      local_4c[0] = (char ***)local_4c;
    }
    if (local_55 == '\0') {
      while( true ) {
        if ((iVar10 == 0) || (cVar1 = *(char *)local_4c[0], cVar1 == '\x7f')) goto LAB_0087ffe0;
        iVar10 = iVar10 + -1;
        if (iVar10 != 0) break;
LAB_0087ffbf:
        if (iVar10 == 0) {
          ppppcVar7 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar7 = local_30;
          }
          if (cVar1 < *(char *)ppppcVar7) goto LAB_0087ffdc;
        }
        if ('\0' < *(char *)((int)local_4c[0] + 1)) {
          local_4c[0] = (char ***)((int)local_4c[0] + 1);
        }
      }
      ppppcVar7 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar7 = local_30;
      }
      if (cVar1 == *(char *)((int)ppppcVar7 + iVar10)) goto LAB_0087ffbf;
LAB_0087ffdc:
      local_55 = '\x01';
    }
LAB_0087ffe0:
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00402f30(1,0);
LAB_00880084:
    if ((local_4d != '\0') && (local_5c == 0)) {
      *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      local_54 = local_54 + 1;
    }
  }
  bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)local_64);
  if (!bVar4) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    iVar2 = param_3[5];
    iVar5 = (istreambuf_iterator<char,std::char_traits<char>_>)(**(code **)(*local_68 + 4))();
    if (iVar2 == iVar5) {
      plVar8 = _localeconv();
      *local_54 = *(istreambuf_iterator<char,std::char_traits<char>_> *)plVar8->decimal_point;
      local_54 = local_54 + 1;
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
  }
  piVar3 = local_64;
  if (local_5c == 0) {
    while (bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                             (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                      piVar3), !bVar4) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) break;
      local_60 = local_60 + -1;
      local_4d = '\x01';
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
    if (local_60 < 0) {
      local_60 = local_60 + 1;
      *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
      local_54 = local_54 + 1;
    }
  }
  bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar3);
  iVar10 = local_5c;
  while (!bVar4) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if ((char)param_3[5] < '0') break;
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if ('9' < (char)param_3[5]) break;
    if (iVar10 < 0x24) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      *local_54 = param_3[5];
      iVar10 = iVar10 + 1;
      local_54 = local_54 + 1;
    }
    local_4d = '\x01';
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar3);
  }
  if ((local_4d != '\0') &&
     (bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar3)
     , !bVar4)) {
    if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
    }
    if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x65) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x45) goto LAB_008802d3;
    }
    *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x65;
    local_54 = local_54 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    local_4d = '\0';
    iVar10 = 0;
    bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar3);
    if (!bVar4) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if (param_3[5] == (istreambuf_iterator<char,std::char_traits<char>_>)0x2b) {
        *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2b;
      }
      else {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x2d)
        goto LAB_0088022f;
        *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x2d;
      }
      local_54 = local_54 + 1;
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
LAB_0088022f:
    bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                      (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)piVar3);
    if (!bVar4) {
      do {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        if (param_3[5] != (istreambuf_iterator<char,std::char_traits<char>_>)0x30) break;
        local_4d = '\x01';
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
        bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                          (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                   piVar3);
      } while (!bVar4);
      if (local_4d != '\0') {
        *local_54 = (istreambuf_iterator<char,std::char_traits<char>_>)0x30;
        local_54 = local_54 + 1;
      }
    }
    while (bVar4 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                             (param_3,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                      piVar3), !bVar4) {
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if ((char)param_3[5] < '0') break;
      if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
      }
      if ('9' < (char)param_3[5]) break;
      if (iVar10 < 8) {
        if (param_3[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_3);
        }
        *local_54 = param_3[5];
        iVar10 = iVar10 + 1;
        local_54 = local_54 + 1;
      }
      local_4d = '\x01';
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_3);
    }
  }
LAB_008802d3:
  piVar9 = local_6c;
  if ((local_55 == '\0') && (local_4d != '\0')) {
    piVar9 = local_54;
  }
  *piVar9 = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
  FUN_00402f30(1,0);
LAB_008802f9:
  iVar10 = FUN_0089dbbc();
  return iVar10;
}

