
/* WARNING: Type propagation algorithm not settling */

void FUN_00827ec0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char *******pppppppcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int local_274 [8];
  int local_254 [35];
  undefined **local_1c8 [17];
  char local_184;
  uint local_17c;
  undefined4 local_16c;
  uint local_168;
  undefined2 local_150 [44];
  undefined4 local_f8;
  undefined4 local_f4;
  __time32_t local_f0;
  undefined4 local_ec;
  uint local_e4;
  undefined4 local_e0;
  int *local_dc;
  int *local_d8;
  int *local_d4;
  tm local_c8;
  uint local_a4;
  undefined4 local_94;
  uint local_90;
  uint local_88;
  undefined4 local_78;
  uint local_74;
  char *******local_6c [4];
  int local_5c;
  uint local_58;
  char *******local_50 [4];
  int local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925d72;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_0072ed80(local_1c8);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_184 == '\0') && (iVar2 = FUN_0072e2e0("TITLEINFO"), iVar2 != 0)) {
    local_274[7] = FUN_0072e360(uVar1);
    while (local_274[7] != 0) {
      FUN_00827d50(local_150);
      iVar2 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar2 == 0) {
LAB_00827ffc:
        local_150[0] = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00827ffc;
        local_150[0] = FUN_008917b4(puVar3);
      }
      local_90 = 7;
      local_94 = 0;
      local_a4 = local_a4 & 0xffff0000;
      local_74 = 7;
      local_78 = 0;
      local_88 = local_88 & 0xffff0000;
      local_8._0_1_ = 3;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 4;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00440130(uVar4);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_8._0_1_ = 3;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("EXPLAIN",7);
      local_8._0_1_ = 6;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_00440130(uVar4);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_8._0_1_ = 3;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("CONDITION",9);
      local_8._0_1_ = 8;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_00440130(uVar4);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_8._0_1_ = 3;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00bfb800,4);
      local_8._0_1_ = 10;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      FUN_00440130(uVar4);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_8._0_1_ = 3;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("VIEWTYPE",8);
      local_8._0_1_ = 0xc;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,0xd);
      FUN_00440130(uVar4);
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_8._0_1_ = 3;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70("COLOR",5);
      local_8._0_1_ = 0xe;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,0x10);
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      if (local_5c == 7) {
        pppppppcVar7 = local_6c[0];
        if (local_58 < 0x10) {
          pppppppcVar7 = (char *******)local_6c;
        }
        if (*(char *)pppppppcVar7 == '#') {
          uVar1 = FUN_0049b1b0();
          uVar5 = FUN_0049b1b0();
          uVar6 = FUN_0049b1b0();
          local_e4 = ((uVar1 | 0xffffff00) << 8 | uVar5 & 0xff) << 8 | uVar6 & 0xff;
        }
      }
      iVar2 = FUN_0044df20(0,L"UNLIMIT",7);
      if (iVar2 == 0) {
        local_ec = 0;
        local_f8 = 0;
        local_f4 = 0;
      }
      else {
        iVar2 = FUN_0044df20(0,L"PERIOD",6);
        if (iVar2 == 0) {
          local_ec = 1;
          iVar2 = FUN_0072e360();
          if (iVar2 == 0) {
            if (0xf < local_58) {
              FUN_0089120c(local_6c[0]);
            }
            local_58 = 0xf;
            local_5c = 0;
            local_6c[0] = (char *******)((uint)local_6c[0] & 0xffffff00);
            if (7 < local_74) {
              FUN_0089120c(local_88);
            }
            local_74 = 7;
            local_78 = 0;
            local_88 = local_88 & 0xffff0000;
            if (7 < local_90) {
              FUN_0089120c(local_a4);
            }
            local_90 = 7;
            local_94 = 0;
            local_a4 = local_a4 & 0xffff0000;
LAB_00828a63:
            FUN_00827e30();
            local_8 = 0xffffffff;
            FUN_00407fb0();
            goto LAB_008289cd;
          }
          iVar2 = FUN_007300a0("Period");
          if (iVar2 != 0) {
            puVar3 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            if (puVar3 != (undefined4 *)0x0) {
              local_f8 = FUN_008917b4(puVar3);
              local_f4 = 0;
              goto LAB_008285f7;
            }
          }
          local_f8 = 0;
          local_f4 = 0;
        }
        else {
          iVar2 = FUN_0044df20(0,L"TIME",4);
          if (iVar2 == 0) {
            local_ec = 2;
            iVar2 = FUN_0072e360();
            if (iVar2 == 0) {
              FUN_00402c50();
              FUN_004fa440();
              FUN_004fa440();
              goto LAB_00828a63;
            }
            FUN_00402b70(&DAT_00c52b98);
            local_8._0_1_ = 0x11;
            FUN_0072ecf0(&DAT_00bf2375);
            local_8 = CONCAT31(local_8._1_3_,0x10);
            FUN_00402c50();
            if (local_40 != 0) {
              local_254[0] = 0;
              local_274[3] = 0;
              local_274[4] = 0;
              local_274[2] = 0;
              local_274[6] = 0;
              local_274[5] = 0;
              pppppppcVar7 = local_50[0];
              if (local_3c < 0x10) {
                pppppppcVar7 = (char *******)local_50;
              }
              FID_conflict__sscanf
                        ((char *)pppppppcVar7,"%04d-%02d-%02dT%02d:%02d:%02d",local_254,
                         local_274 + 3,local_274 + 4,local_274 + 2,local_274 + 6,local_274 + 5);
              local_c8.tm_wday = 0;
              local_c8.tm_yday = 0;
              local_c8.tm_isdst = 0;
              local_c8.tm_year = local_254[0] + -0x76c;
              local_c8.tm_mon = local_274[3] + -1;
              local_c8.tm_hour = local_274[2];
              local_c8.tm_mday = local_274[4];
              local_c8.tm_min = local_274[6];
              local_c8.tm_sec = local_274[5];
              local_f0 = __mktime32(&local_c8);
              local_f4 = 0;
            }
            FUN_00402c50();
          }
        }
      }
LAB_008285f7:
      iVar2 = FUN_0044df20(0,L"ALWAYS",6);
      if (iVar2 == 0) {
        local_e0 = 0;
      }
      else {
        iVar2 = FUN_0044df20(0,L"HIDE_EXPLAIN",0xc);
        if (iVar2 == 0) {
          local_e0 = 1;
        }
        else {
          iVar2 = FUN_0044df20(0,L"HIDE_LIST_ITEM",0xe);
          if (iVar2 == 0) {
            local_e0 = 2;
          }
        }
      }
      iVar2 = FUN_0072e360();
      while (local_254[0] = iVar2, iVar2 != 0) {
        for (iVar9 = *(int *)(iVar2 + 0x94); iVar9 != iVar2 + 0x44; iVar9 = *(int *)(iVar9 + 0x50))
        {
          pcVar10 = (char *)(iVar9 + 0x14);
          if (0xf < *(uint *)(iVar9 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar8 = __stricmp(pcVar10,"ID");
          if (iVar8 == 0) {
            if (iVar9 != 0) {
              puVar3 = (undefined4 *)(iVar9 + 0x30);
              if (0xf < *(uint *)(iVar9 + 0x44)) {
                puVar3 = (undefined4 *)*puVar3;
              }
              if (puVar3 != (undefined4 *)0x0) {
                iVar9 = FUN_008917b4(puVar3);
                goto LAB_008286d1;
              }
            }
            break;
          }
        }
        iVar9 = 0;
LAB_008286d1:
        local_274[0] = iVar9;
        for (iVar8 = *(int *)(iVar2 + 0x94); iVar8 != iVar2 + 0x44; iVar8 = *(int *)(iVar8 + 0x50))
        {
          pcVar10 = (char *)(iVar8 + 0x14);
          if (0xf < *(uint *)(iVar8 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar11 = __stricmp(pcVar10,"VALUE");
          if (iVar11 == 0) {
            if (iVar8 != 0) {
              puVar3 = (undefined4 *)(iVar8 + 0x30);
              if (0xf < *(uint *)(iVar8 + 0x44)) {
                puVar3 = (undefined4 *)*puVar3;
              }
              if (puVar3 != (undefined4 *)0x0) {
                iVar2 = FUN_008917b4(puVar3);
                goto LAB_0082870a;
              }
            }
            break;
          }
        }
        iVar2 = 0;
LAB_0082870a:
        local_274[1] = iVar2;
        if ((local_274 < local_d8) && (local_dc <= local_274)) {
          iVar2 = (int)local_274 - (int)local_dc;
          if (local_d8 == local_d4) {
            uVar1 = (int)local_d8 - (int)local_dc >> 3;
            if (0x1ffffffe < uVar1) {
LAB_00828aa7:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar1 = uVar1 + 1;
            uVar5 = (int)local_d4 - (int)local_dc >> 3;
            if (uVar5 < uVar1) {
              if (0x1fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar1) {
                uVar5 = uVar1;
              }
              FUN_004e7330(uVar5);
            }
          }
          if (local_d8 != (int *)0x0) {
            *local_d8 = local_dc[(iVar2 >> 3) * 2];
            local_d8[1] = (local_dc + (iVar2 >> 3) * 2)[1];
          }
        }
        else {
          if (local_d8 == local_d4) {
            uVar1 = (int)local_d8 - (int)local_dc >> 3;
            if (0x1ffffffe < uVar1) goto LAB_00828aa7;
            uVar1 = uVar1 + 1;
            uVar5 = (int)local_d4 - (int)local_dc >> 3;
            if (uVar5 < uVar1) {
              if (0x1fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar1) {
                uVar5 = uVar1;
              }
              FUN_004e7330(uVar5);
            }
          }
          if (local_d8 != (int *)0x0) {
            *local_d8 = iVar9;
            local_d8[1] = iVar2;
          }
        }
        local_d8 = local_d8 + 2;
        iVar2 = FUN_0072e3c0();
      }
      uVar4 = FUN_00829110(local_150);
      local_8 = CONCAT31(local_8._1_3_,0x12);
      uVar4 = FUN_00829410(uVar4);
      FUN_00829140(param_1,uVar4);
      FUN_00827e30();
      if (0xf < local_58) {
        FUN_0089120c(local_6c[0]);
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = (char *******)((uint)local_6c[0] & 0xffffff00);
      if (7 < local_74) {
        FUN_0089120c(local_88);
      }
      local_74 = 7;
      local_78 = 0;
      local_88 = local_88 & 0xffff0000;
      if (7 < local_90) {
        FUN_0089120c(local_a4);
      }
      local_94 = 0;
      local_90 = 7;
      local_a4 = local_a4 & 0xffff0000;
      local_8 = local_8 & 0xffffff00;
      FUN_00827e30();
      local_274[7] = FUN_0072e3c0();
    }
    local_8 = 0xffffffff;
    local_1c8[0] = TiXmlDocument::vftable;
    if (0xf < local_168) {
      FUN_0089120c(local_17c);
    }
    local_168 = 0xf;
    local_16c = 0;
    local_17c = local_17c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_1c8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_168) {
      local_8 = 0xffffffff;
      local_1c8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_17c);
    }
    local_168 = 0xf;
    local_16c = 0;
    local_17c = local_17c & 0xffffff00;
    FUN_0072e040();
  }
LAB_008289cd:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

