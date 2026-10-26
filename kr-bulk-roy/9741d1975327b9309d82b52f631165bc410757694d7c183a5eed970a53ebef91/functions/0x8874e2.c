
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: int __cdecl std::num_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Getffld(char *,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::ios_base &,int *)const 
    private: int __cdecl std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Getffld(char *,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::ios_base &,int *)const 
   
   Library: Visual Studio 2010 Release */

void Getffld(int param_1,char *param_2,int param_3,undefined4 param_4,int param_5,undefined4 param_6
            )

{
  short sVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  char ****ppppcVar6;
  lconv *plVar7;
  char *pcVar8;
  ushort uVar9;
  int iVar10;
  undefined1 local_7c [4];
  uint local_78;
  int *local_74;
  int local_70;
  char *local_6c;
  undefined4 local_68;
  int local_64;
  int local_60;
  uint local_5c;
  char local_55;
  char *local_54;
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
  local_8 = 0x8874ee;
  local_6c = param_2;
  local_68 = param_4;
  if ((*(uint *)(param_5 + 0x14) & 0x3000) == 0x3000) {
    Getffldx(param_1,param_2,param_3,param_4,param_5,param_6);
    goto LAB_00887b7a;
  }
  uVar5 = FUN_004318d0(local_7c);
  local_8 = 0;
  local_74 = (int *)FUN_00430690(uVar5);
  local_8 = 0xffffffff;
  FUN_004327c0();
  FUN_0042fd00(local_4c);
  param_1 = param_1 + 8;
  local_8 = 1;
  local_70 = param_1;
  local_5c = FUN_004303a0(0x30,0,param_1);
  local_5c = local_5c & 0xffff;
  local_54 = local_6c;
  local_55 = '\0';
  cVar3 = equal(local_68);
  if (cVar3 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar4 = FUN_004303a0(0x2b,0,param_1);
    if (sVar1 == sVar4) {
      *local_6c = '+';
    }
    else {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar1 = *(short *)(param_3 + 6);
      sVar4 = FUN_004303a0(0x2d,0,param_1);
      if (sVar1 != sVar4) goto LAB_008875f0;
      *local_6c = '-';
    }
    local_54 = local_6c + 1;
    Inc();
  }
LAB_008875f0:
  iVar10 = 0;
  local_4d = '\0';
  local_64 = 0;
  local_60 = 0;
  ppppcVar6 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar6 = local_4c;
  }
  if (*(char *)ppppcVar6 == '\x7f') {
LAB_008877ed:
    cVar3 = equal(local_68);
    if (cVar3 == '\0') {
      do {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        if (*(ushort *)(param_3 + 6) < (ushort)local_5c) break;
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        if ((local_5c & 0xffff) + 9 < (uint)*(ushort *)(param_3 + 6)) break;
        if (local_64 < 0x24) {
          if (*(char *)(param_3 + 4) == '\0') {
            Peek();
          }
          uVar2 = local_5c;
          if ((*(short *)(param_3 + 6) != (short)local_5c) || (local_64 != 0)) {
            if (*(char *)(param_3 + 4) == '\0') {
              Peek();
            }
            local_64 = local_64 + 1;
            *local_54 = (*(char *)(param_3 + 6) - (char)uVar2) + '0';
            local_54 = local_54 + 1;
          }
        }
        else {
          local_60 = local_60 + 1;
        }
        local_4d = '\x01';
        Inc();
        cVar3 = equal(local_68);
      } while (cVar3 == '\0');
      goto LAB_00887894;
    }
  }
  else {
    ppppcVar6 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar6 = local_4c;
    }
    if (*(char *)ppppcVar6 < '\x01') goto LAB_008877ed;
    if (local_3c == 0) {
      local_78 = 0;
    }
    else {
      local_78 = (**(code **)(*local_74 + 8))();
      local_78 = local_78 & 0xffff;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    FUN_0046e1b0(1,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    cVar3 = equal(local_68);
    if (cVar3 == '\0') {
      do {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        uVar2 = local_5c;
        uVar9 = (ushort)local_5c;
        if (*(ushort *)(param_3 + 6) < uVar9) {
LAB_00887713:
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if ((*(char *)((int)ppppcVar6 + iVar10) == '\0') || ((short)local_78 == 0)) break;
          if (*(char *)(param_3 + 4) == '\0') {
            Peek();
          }
          if (*(short *)(param_3 + 6) != (short)local_78) break;
          FUN_00429630(1,0);
          iVar10 = iVar10 + 1;
        }
        else {
          if (*(char *)(param_3 + 4) == '\0') {
            Peek();
          }
          if ((uVar2 & 0xffff) + 9 < (uint)*(ushort *)(param_3 + 6)) goto LAB_00887713;
          local_4d = '\x01';
          if (local_64 < 0x24) {
            if (*(char *)(param_3 + 4) == '\0') {
              Peek();
            }
            if ((*(ushort *)(param_3 + 6) != uVar9) || (local_64 != 0)) {
              if (*(char *)(param_3 + 4) == '\0') {
                Peek();
              }
              local_64 = local_64 + 1;
              *local_54 = ((char)*(undefined2 *)(param_3 + 6) - (char)uVar2) + '0';
              local_54 = local_54 + 1;
            }
          }
          else {
            local_60 = local_60 + 1;
          }
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if (*(char *)((int)ppppcVar6 + iVar10) != '\x7f') {
            ppppcVar6 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar6 = local_30;
            }
            *(char *)((int)ppppcVar6 + iVar10) = *(char *)((int)ppppcVar6 + iVar10) + '\x01';
          }
        }
        Inc();
        cVar3 = equal(local_68);
      } while (cVar3 == '\0');
      if (iVar10 != 0) {
        ppppcVar6 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar6 = local_30;
        }
        if (*(char *)((int)ppppcVar6 + iVar10) < '\x01') {
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
        if ((iVar10 == 0) || (cVar3 = *(char *)local_4c[0], cVar3 == '\x7f')) goto LAB_008877d8;
        iVar10 = iVar10 + -1;
        if (iVar10 != 0) break;
LAB_008877b7:
        if (iVar10 == 0) {
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if (cVar3 < *(char *)ppppcVar6) goto LAB_008877d4;
        }
        if ('\0' < *(char *)((int)local_4c[0] + 1)) {
          local_4c[0] = (char ***)((int)local_4c[0] + 1);
        }
      }
      ppppcVar6 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar6 = local_30;
      }
      if (cVar3 == *(char *)((int)ppppcVar6 + iVar10)) goto LAB_008877b7;
LAB_008877d4:
      local_55 = '\x01';
    }
LAB_008877d8:
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00402f30(1,0);
LAB_00887894:
    if ((local_4d != '\0') && (local_64 == 0)) {
      *local_54 = '0';
      local_54 = local_54 + 1;
    }
  }
  uVar5 = local_68;
  cVar3 = equal(local_68);
  if (cVar3 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar4 = (**(code **)(*local_74 + 4))();
    if (sVar1 == sVar4) {
      plVar7 = _localeconv();
      *local_54 = *plVar7->decimal_point;
      local_54 = local_54 + 1;
      Inc();
    }
  }
  iVar10 = local_64;
  if (local_64 == 0) {
    while (cVar3 = equal(uVar5), cVar3 == '\0') {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      if (*(short *)(param_3 + 6) != (ushort)local_5c) break;
      local_60 = local_60 + -1;
      local_4d = '\x01';
      Inc();
    }
    if (local_60 < 0) {
      local_60 = local_60 + 1;
      *local_54 = '0';
      local_54 = local_54 + 1;
    }
  }
  while (cVar3 = equal(uVar5), cVar3 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if (*(ushort *)(param_3 + 6) < (ushort)local_5c) break;
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if ((local_5c & 0xffff) + 9 < (uint)*(ushort *)(param_3 + 6)) break;
    if (iVar10 < 0x24) {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      *local_54 = (*(char *)(param_3 + 6) - (char)local_5c) + '0';
      iVar10 = iVar10 + 1;
      local_54 = local_54 + 1;
    }
    local_4d = '\x01';
    Inc();
  }
  if ((local_4d != '\0') && (cVar3 = equal(uVar5), cVar3 == '\0')) {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar4 = FUN_004303a0(0x65,0,local_70);
    if (sVar1 != sVar4) {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar1 = *(short *)(param_3 + 6);
      sVar4 = FUN_004303a0(0x45,0,local_70);
      if (sVar1 != sVar4) goto LAB_00887b54;
    }
    *local_54 = 'e';
    local_54 = local_54 + 1;
    Inc();
    local_4d = '\0';
    iVar10 = 0;
    cVar3 = equal(local_68);
    if (cVar3 == '\0') {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar1 = *(short *)(param_3 + 6);
      sVar4 = FUN_004303a0(0x2b,0,local_70);
      if (sVar1 == sVar4) {
        *local_54 = '+';
      }
      else {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        sVar1 = *(short *)(param_3 + 6);
        sVar4 = FUN_004303a0(0x2d,0,local_70);
        if (sVar1 != sVar4) goto LAB_00887a97;
        *local_54 = '-';
      }
      local_54 = local_54 + 1;
      Inc();
    }
LAB_00887a97:
    uVar5 = local_68;
    cVar3 = equal(local_68);
    if (cVar3 == '\0') {
      do {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        if (*(short *)(param_3 + 6) != (ushort)local_5c) break;
        local_4d = '\x01';
        Inc();
        cVar3 = equal(uVar5);
      } while (cVar3 == '\0');
      if (local_4d != '\0') {
        *local_54 = '0';
        local_54 = local_54 + 1;
      }
    }
    while (cVar3 = equal(uVar5), cVar3 == '\0') {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      if (*(ushort *)(param_3 + 6) < (ushort)local_5c) break;
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      if ((local_5c & 0xffff) + 9 < (uint)*(ushort *)(param_3 + 6)) break;
      if (iVar10 < 8) {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        *local_54 = (*(char *)(param_3 + 6) - (char)local_5c) + '0';
        iVar10 = iVar10 + 1;
        local_54 = local_54 + 1;
      }
      local_4d = '\x01';
      Inc();
    }
  }
LAB_00887b54:
  pcVar8 = local_6c;
  if ((local_55 == '\0') && (local_4d != '\0')) {
    pcVar8 = local_54;
  }
  *pcVar8 = '\0';
  FUN_00402f30(1,0);
LAB_00887b7a:
  FUN_0089dbbc();
  return;
}

