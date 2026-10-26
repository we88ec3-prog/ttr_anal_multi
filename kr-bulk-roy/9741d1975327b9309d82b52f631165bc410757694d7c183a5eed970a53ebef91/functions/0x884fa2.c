
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: int __cdecl std::num_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Getffldx(char *,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > &,class
   std::ios_base &,int *)const 
    private: int __cdecl std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Getffldx(char *,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::ios_base &,int *)const 
   
   Library: Visual Studio 2010 Release */

void Getffldx(int param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
             int *param_6)

{
  short sVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  char ****ppppcVar6;
  lconv *plVar7;
  char *pcVar8;
  undefined1 local_8c [4];
  uint local_88;
  uint local_84;
  uint local_80;
  int *local_7c;
  int local_78;
  char *local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64;
  undefined4 local_60;
  int local_5c;
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
  
  uStack_4 = 0x80;
  local_8 = 0x884fb1;
  local_74 = param_2;
  local_60 = param_4;
  local_78 = param_1;
  uVar4 = FUN_004318d0(local_8c);
  local_8 = 0;
  local_7c = (int *)FUN_00430690(uVar4);
  local_8 = 0xffffffff;
  FUN_004327c0();
  FUN_0042fd00(local_4c);
  param_1 = param_1 + 8;
  local_8 = 1;
  local_70 = param_1;
  local_64 = FUN_004303a0(0x30,0,param_1);
  local_64 = local_64 & 0xffff;
  local_84 = FUN_004303a0(0x61,0,param_1);
  local_84 = local_84 & 0xffff;
  local_80 = FUN_004303a0(0x41,0,param_1);
  local_80 = local_80 & 0xffff;
  local_54 = local_74;
  local_55 = '\0';
  cVar2 = equal(local_60);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar3 = FUN_004303a0(0x2b,0,local_70);
    if (sVar1 == sVar3) {
      *local_74 = '+';
    }
    else {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar1 = *(short *)(param_3 + 6);
      sVar3 = FUN_004303a0(0x2d,0,local_70);
      if (sVar1 != sVar3) goto LAB_008850bb;
      *local_74 = '-';
    }
    local_54 = local_74 + 1;
    Inc();
  }
LAB_008850bb:
  local_54[0] = '0';
  local_54[1] = 'x';
  local_54 = local_54 + 2;
  local_4d = '\0';
  local_5c = 0;
  local_6c = 0;
  cVar2 = equal(local_60);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if (*(short *)(param_3 + 6) == (ushort)local_64) {
      Inc();
      cVar2 = equal(local_60);
      if (cVar2 == '\0') {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        sVar1 = *(short *)(param_3 + 6);
        sVar3 = FUN_004303a0(0x78,0,local_70);
        if (sVar1 != sVar3) {
          if (*(char *)(param_3 + 4) == '\0') {
            Peek();
          }
          sVar1 = *(short *)(param_3 + 6);
          sVar3 = FUN_004303a0(0x58,0,local_70);
          if (sVar1 != sVar3) goto LAB_0088515a;
        }
        Inc();
      }
      else {
LAB_0088515a:
        local_4d = '\x01';
      }
    }
  }
  ppppcVar6 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar6 = local_4c;
  }
  if (*(char *)ppppcVar6 == '\x7f') {
LAB_008853b5:
    while (cVar2 = equal(local_60), cVar2 == '\0') {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      iVar5 = Hexdig(local_78,*(undefined2 *)(param_3 + 6),local_64,local_84,local_80);
      if (iVar5 < 0) break;
      if (local_5c < 0x24) {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        if ((*(short *)(param_3 + 6) != (ushort)local_64) || (local_5c != 0)) {
          local_5c = local_5c + 1;
          *local_54 = "0123456789abcdef"[iVar5];
          local_54 = local_54 + 1;
        }
      }
      else {
        local_6c = local_6c + 1;
      }
      local_4d = '\x01';
      Inc();
    }
  }
  else {
    ppppcVar6 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar6 = local_4c;
    }
    if (*(char *)ppppcVar6 < '\x01') goto LAB_008853b5;
    if (local_3c == 0) {
      local_88 = 0;
    }
    else {
      local_88 = (**(code **)(*local_7c + 8))();
      local_88 = local_88 & 0xffff;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    FUN_0046e1b0(1,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_68 = 0;
    cVar2 = equal(local_60);
    if (cVar2 == '\0') {
      do {
        if (*(char *)(param_3 + 4) == '\0') {
          Peek();
        }
        iVar5 = Hexdig(local_78,*(undefined2 *)(param_3 + 6),local_64,local_84,local_80);
        if (iVar5 < 0) {
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if ((*(char *)((int)ppppcVar6 + local_68) == '\0') || ((short)local_88 == 0)) break;
          if (*(char *)(param_3 + 4) == '\0') {
            Peek();
          }
          if (*(short *)(param_3 + 6) != (short)local_88) break;
          FUN_00429630(1,0);
          local_68 = local_68 + 1;
        }
        else {
          local_4d = '\x01';
          if (local_5c < 0x24) {
            if (*(char *)(param_3 + 4) == '\0') {
              Peek();
            }
            if ((*(short *)(param_3 + 6) != (ushort)local_64) || (local_5c != 0)) {
              local_5c = local_5c + 1;
              *local_54 = "0123456789abcdef"[iVar5];
              local_54 = local_54 + 1;
            }
          }
          else {
            local_6c = local_6c + 1;
          }
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if (*(char *)((int)ppppcVar6 + local_68) != '\x7f') {
            ppppcVar6 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar6 = local_30;
            }
            *(char *)((int)ppppcVar6 + local_68) = *(char *)((int)ppppcVar6 + local_68) + '\x01';
          }
        }
        Inc();
        cVar2 = equal(local_60);
      } while (cVar2 == '\0');
      if (local_68 != 0) {
        ppppcVar6 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar6 = local_30;
        }
        if (*(char *)((int)ppppcVar6 + local_68) < '\x01') {
          local_55 = '\x01';
        }
        else {
          local_68 = local_68 + 1;
        }
      }
    }
    if (local_38 < 0x10) {
      local_4c[0] = (char ***)local_4c;
    }
    iVar5 = local_68;
    if (local_55 == '\0') {
      while( true ) {
        if ((iVar5 == 0) || (cVar2 = *(char *)local_4c[0], cVar2 == '\x7f')) goto LAB_00885337;
        iVar5 = iVar5 + -1;
        if (iVar5 != 0) break;
LAB_00885317:
        if (iVar5 == 0) {
          ppppcVar6 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar6 = local_30;
          }
          if (cVar2 < *(char *)ppppcVar6) goto LAB_00885333;
        }
        if ('\0' < *(char *)((int)local_4c[0] + 1)) {
          local_4c[0] = (char ***)((int)local_4c[0] + 1);
        }
      }
      ppppcVar6 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar6 = local_30;
      }
      if (cVar2 == *(char *)((int)ppppcVar6 + iVar5)) goto LAB_00885317;
LAB_00885333:
      local_55 = '\x01';
    }
LAB_00885337:
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00402f30(1,0);
  }
  if ((local_4d != '\0') && (local_5c == 0)) {
    *local_54 = '0';
    local_54 = local_54 + 1;
  }
  cVar2 = equal(local_60);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar3 = (**(code **)(*local_7c + 4))();
    if (sVar1 == sVar3) {
      plVar7 = _localeconv();
      *local_54 = *plVar7->decimal_point;
      local_54 = local_54 + 1;
      Inc();
    }
  }
  if (local_5c == 0) {
    while (cVar2 = equal(local_60), cVar2 == '\0') {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      if (*(short *)(param_3 + 6) != (ushort)local_64) break;
      local_6c = local_6c + -1;
      local_4d = '\x01';
      Inc();
    }
    if (local_6c < 0) {
      local_6c = local_6c + 1;
      *local_54 = '0';
      local_54 = local_54 + 1;
    }
  }
  while (cVar2 = equal(local_60), cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    iVar5 = Hexdig(local_78,*(undefined2 *)(param_3 + 6),local_64,local_84,local_80);
    if (iVar5 < 0) break;
    if (local_5c < 0x24) {
      local_5c = local_5c + 1;
      *local_54 = "0123456789abcdef"[iVar5];
      local_54 = local_54 + 1;
    }
    local_4d = '\x01';
    Inc();
  }
  if ((local_4d == '\0') || (cVar2 = equal(local_60), cVar2 != '\0')) goto LAB_00885666;
  if (*(char *)(param_3 + 4) == '\0') {
    Peek();
  }
  sVar1 = *(short *)(param_3 + 6);
  sVar3 = FUN_004303a0(0x70,0,local_70);
  if (sVar1 != sVar3) {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar3 = FUN_004303a0(0x50,0,local_70);
    if (sVar1 != sVar3) goto LAB_00885666;
  }
  *local_54 = 'p';
  local_54 = local_54 + 1;
  Inc();
  local_4d = '\0';
  local_5c = 0;
  cVar2 = equal(local_60);
  if (cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    sVar1 = *(short *)(param_3 + 6);
    sVar3 = FUN_004303a0(0x2b,0,local_70);
    if (sVar1 == sVar3) {
      *local_54 = '+';
    }
    else {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      sVar1 = *(short *)(param_3 + 6);
      sVar3 = FUN_004303a0(0x2d,0,local_70);
      if (sVar1 != sVar3) goto LAB_008855a9;
      *local_54 = '-';
    }
    local_54 = local_54 + 1;
    Inc();
  }
LAB_008855a9:
  uVar4 = local_60;
  cVar2 = equal(local_60);
  if (cVar2 == '\0') {
    do {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      if (*(short *)(param_3 + 6) != (ushort)local_64) break;
      local_4d = '\x01';
      Inc();
      cVar2 = equal(uVar4);
    } while (cVar2 == '\0');
    if (local_4d != '\0') {
      *local_54 = '0';
      local_54 = local_54 + 1;
    }
  }
  while (cVar2 = equal(uVar4), cVar2 == '\0') {
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if (*(ushort *)(param_3 + 6) < (ushort)local_64) break;
    if (*(char *)(param_3 + 4) == '\0') {
      Peek();
    }
    if ((local_64 & 0xffff) + 9 < (uint)*(ushort *)(param_3 + 6)) break;
    if (local_5c < 8) {
      if (*(char *)(param_3 + 4) == '\0') {
        Peek();
      }
      local_5c = local_5c + 1;
      *local_54 = (*(char *)(param_3 + 6) - (char)local_64) + '0';
      local_54 = local_54 + 1;
    }
    local_4d = '\x01';
    Inc();
  }
LAB_00885666:
  pcVar8 = local_74;
  if ((local_55 == '\0') && (local_4d != '\0')) {
    pcVar8 = local_54;
  }
  *pcVar8 = '\0';
  *param_6 = local_6c;
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

