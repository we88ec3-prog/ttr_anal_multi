
void FUN_00733450(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *******pppppppcVar3;
  int iVar4;
  int *in_ECX;
  char *******pppppppcVar5;
  byte *pbVar6;
  undefined **local_120;
  byte local_119;
  int *local_118;
  int *local_114;
  undefined **local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined1 local_fc;
  undefined4 local_ec;
  undefined4 local_e8;
  char ******local_e0 [4];
  undefined4 local_d0;
  uint local_cc;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined **local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  char ******local_8c [4];
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined **local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined4 local_44;
  undefined4 local_40;
  char ******local_38 [4];
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cd4e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_118 = in_ECX;
  pcVar2 = (char *)FUN_00731170(param_3,local_14);
  for (local_114 = in_ECX; local_114 != (int *)0x0; local_114 = (int *)local_114[4]) {
    iVar4 = (**(code **)(*local_114 + 0x10))();
    if (iVar4 != 0) {
      local_114 = (int *)(**(code **)(*local_114 + 0x10))();
      goto LAB_007334c0;
    }
  }
  local_114 = (int *)0x0;
LAB_007334c0:
  if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) ||
     (cVar1 = FUN_00731560(1,param_3), cVar1 == '\0')) {
    if ((local_114 != (int *)0x0) && ((char)local_114[0x11] == '\0')) {
      *(undefined1 *)(local_114 + 0x11) = 1;
      local_114[0x12] = 0xc;
      local_120 = (undefined **)(PTR_s_Error_parsing_Declaration__00d63cb8 + 1);
      pcVar2 = PTR_s_Error_parsing_Declaration__00d63cb8;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Error_parsing_Declaration__00d63cb8,(int)pcVar2 - (int)local_120);
      local_114[0x1c] = -1;
      local_114[0x1b] = -1;
      local_120 = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_120,0,0,param_3);
    }
  }
  else {
    if (param_2 != (int *)0x0) {
      FUN_00730f80(pcVar2,param_3);
      local_118[1] = *param_2;
      local_118[2] = param_2[1];
    }
    local_114 = local_118 + 0x11;
    pbVar6 = (byte *)(pcVar2 + 5);
    FUN_00402a70(&DAT_00bf2375,0);
    local_120 = (undefined **)(local_118 + 0x18);
    FUN_00402a70(&DAT_00bf2375,0);
    local_118 = local_118 + 0x1f;
    FUN_00402a70(&DAT_00bf2375,0);
    while (((pbVar6 != (byte *)0x0 && (*pbVar6 != 0)) && (*pbVar6 != 0x3e))) {
      pbVar6 = (byte *)FUN_00731170(param_3);
      cVar1 = FUN_00731560(1,param_3);
      if (cVar1 == '\0') {
        cVar1 = FUN_00731560(1,param_3);
        if (cVar1 != '\0') {
          local_b4 = 0xffffffff;
          local_b8 = 0xffffffff;
          local_b0 = 0;
          local_bc = TiXmlAttribute::vftable;
          local_94 = 0xf;
          local_98 = 0;
          local_a8 = 0;
          local_78 = 0xf;
          local_7c = 0;
          local_8c[0] = (char ******)((uint)local_8c[0] & 0xffffff00);
          local_ac = 0;
          local_6c = 0;
          local_70 = 0;
          local_8 = 1;
          pbVar6 = (byte *)FUN_00732fe0(pbVar6,param_2,param_3);
          pppppppcVar5 = (char *******)local_8c[0];
          if (local_78 < 0x10) {
            pppppppcVar5 = local_8c;
          }
          pppppppcVar3 = pppppppcVar5;
          do {
            cVar1 = *(char *)pppppppcVar3;
            pppppppcVar3 = (char *******)((int)pppppppcVar3 + 1);
          } while (cVar1 != '\0');
          FUN_00402a70(pppppppcVar5,(int)pppppppcVar3 - (int)((int)pppppppcVar5 + 1));
          goto LAB_00733656;
        }
        cVar1 = FUN_00731560(1,param_3);
        if (cVar1 != '\0') {
          local_60 = 0xffffffff;
          local_64 = 0xffffffff;
          local_5c = 0;
          local_68 = TiXmlAttribute::vftable;
          local_40 = 0xf;
          local_44 = 0;
          local_54 = 0;
          local_24 = 0xf;
          local_28 = 0;
          local_38[0] = (char ******)((uint)local_38[0] & 0xffffff00);
          local_58 = 0;
          local_18 = 0;
          local_1c = 0;
          local_8 = 2;
          pbVar6 = (byte *)FUN_00732fe0(pbVar6,param_2,param_3);
          pppppppcVar5 = (char *******)local_38[0];
          if (local_24 < 0x10) {
            pppppppcVar5 = local_38;
          }
          pppppppcVar3 = pppppppcVar5;
          do {
            cVar1 = *(char *)pppppppcVar3;
            pppppppcVar3 = (char *******)((int)pppppppcVar3 + 1);
          } while (cVar1 != '\0');
          FUN_00402a70(pppppppcVar5,(int)pppppppcVar3 - (int)((int)pppppppcVar5 + 1));
          goto LAB_00733656;
        }
        while( true ) {
          if (pbVar6 == (byte *)0x0) goto LAB_007338f3;
          local_119 = *pbVar6;
          if ((((local_119 == 0) || (local_119 == 0x3e)) ||
              (iVar4 = _isspace((uint)local_119), iVar4 != 0)) ||
             ((local_119 == 10 || (local_119 == 0xd)))) break;
          pbVar6 = pbVar6 + 1;
        }
      }
      else {
        local_108 = 0xffffffff;
        local_10c = 0xffffffff;
        local_104 = 0;
        local_110 = TiXmlAttribute::vftable;
        local_e8 = 0xf;
        local_ec = 0;
        local_fc = 0;
        local_cc = 0xf;
        local_d0 = 0;
        local_e0[0] = (char ******)((uint)local_e0[0] & 0xffffff00);
        local_100 = 0;
        local_c0 = 0;
        local_c4 = 0;
        local_8 = 0;
        pbVar6 = (byte *)FUN_00732fe0(pbVar6,param_2,param_3);
        pppppppcVar5 = (char *******)local_e0[0];
        if (local_cc < 0x10) {
          pppppppcVar5 = local_e0;
        }
        pppppppcVar3 = pppppppcVar5;
        do {
          cVar1 = *(char *)pppppppcVar3;
          pppppppcVar3 = (char *******)((int)pppppppcVar3 + 1);
        } while (cVar1 != '\0');
        FUN_00402a70(pppppppcVar5,(int)pppppppcVar3 - (int)((int)pppppppcVar5 + 1));
LAB_00733656:
        local_8 = 0xffffffff;
        FUN_0072dc10();
      }
    }
  }
LAB_007338f3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

