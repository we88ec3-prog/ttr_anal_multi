
void FUN_004fb9c0(undefined4 param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_14c [4];
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  int iStack_138;
  int local_134;
  undefined4 local_130;
  char *pcStack_12c;
  int iStack_128;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined **appuStack_11c [5];
  undefined4 local_108;
  undefined4 local_104;
  int local_100;
  undefined4 local_fc;
  uint local_f8;
  undefined4 local_e8;
  uint local_e4;
  undefined4 *local_dc;
  undefined4 *local_d8;
  undefined4 *local_d4;
  uint local_cc;
  undefined4 local_bc;
  uint local_b8;
  undefined **local_b0 [17];
  char local_6c;
  uint local_64;
  undefined4 local_54;
  uint local_50;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009244f7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_14c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffea8;
  ExceptionList = &local_14;
  local_130 = param_1;
  FUN_0072ee30(local_b0);
  local_c = 0;
  FUN_0072f110(0);
  if (local_6c == '\0') {
    iVar4 = FUN_0072e2e0("SHOP_INFO");
    if (iVar4 == 0) {
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_134 = FUN_0072e360(uVar3);
      while (local_134 != 0) {
        local_e4 = 7;
        local_e8 = 0;
        local_f8 = local_f8 & 0xffff0000;
        local_dc = (undefined4 *)0x0;
        local_d8 = (undefined4 *)0x0;
        local_d4 = (undefined4 *)0x0;
        local_c._1_3_ = (undefined3)(local_c >> 8);
        local_c = CONCAT31(local_c._1_3_,1);
        iVar4 = FUN_007300a0(&DAT_00c0ce2c);
        if (iVar4 == 0) {
LAB_004fbb9d:
          local_108 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004fbb9d;
          local_108 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c067ec);
        if (iVar4 == 0) {
LAB_004fbbcb:
          local_104 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004fbbcb;
          local_104 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00bfb800);
        if (iVar4 == 0) {
LAB_004fbbf9:
          local_100 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004fbbf9;
          local_100 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c0d83c);
        if (iVar4 == 0) {
LAB_004fbc27:
          local_fc = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004fbc27;
          local_fc = FUN_008917b4(puVar5);
        }
        local_b8 = 0xf;
        local_bc = 0;
        local_cc = local_cc & 0xffffff00;
        FUN_00402a70(&DAT_00c0ce30,4);
        local_c._0_1_ = 2;
        uVar6 = FUN_0072ecf0(&DAT_00bf2375);
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_00440130(uVar6);
        if (0xf < local_24) {
          FUN_0089120c(local_38);
        }
        local_c = CONCAT31(local_c._1_3_,1);
        local_24 = 0xf;
        local_28 = 0;
        local_38 = local_38 & 0xffffff00;
        if (0xf < local_b8) {
          FUN_0089120c(local_cc);
        }
        local_b8 = 0xf;
        local_bc = 0;
        local_cc = local_cc & 0xffffff00;
        iVar4 = FUN_00526f60(DAT_00fe1bd0,local_fc);
        if (((iVar4 != 0) && (0 < local_100)) && (local_100 < 5)) {
          *(int *)(iVar4 + 0x20) = local_100 + 10;
        }
        iVar4 = FUN_0072e360();
        iStack_138 = iVar4;
        if (iVar4 != 0) {
          do {
            iVar1 = iVar4 + 0x44;
            iStack_138 = iVar4;
            for (iVar9 = *(int *)(iVar4 + 0x94); iVar9 != iVar1; iVar9 = *(int *)(iVar9 + 0x50)) {
              pcVar8 = (char *)(iVar9 + 0x14);
              if (0xf < *(uint *)(iVar9 + 0x28)) {
                pcVar8 = *(char **)pcVar8;
              }
              iVar7 = __stricmp(pcVar8,"NO");
              if (iVar7 == 0) {
                if (iVar9 != 0) {
                  puVar5 = (undefined4 *)(iVar9 + 0x30);
                  if (0xf < *(uint *)(iVar9 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uVar6 = FUN_008917b4(puVar5);
                    goto LAB_004fbd8f;
                  }
                }
                break;
              }
            }
            uVar6 = 0;
LAB_004fbd8f:
            uStack_144 = uVar6;
            uStack_140 = uVar6;
            for (iVar9 = *(int *)(iVar4 + 0x94); iVar9 != iVar1; iVar9 = *(int *)(iVar9 + 0x50)) {
              pcVar8 = (char *)(iVar9 + 0x14);
              if (0xf < *(uint *)(iVar9 + 0x28)) {
                pcVar8 = *(char **)pcVar8;
              }
              iVar7 = __stricmp(pcVar8,"QTY");
              if (iVar7 == 0) {
                if (iVar9 != 0) {
                  puVar5 = (undefined4 *)(iVar9 + 0x30);
                  if (0xf < *(uint *)(iVar9 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uStack_148 = FUN_008917b4(puVar5);
                    goto LAB_004fbdd0;
                  }
                }
                break;
              }
            }
            uStack_148 = 0;
LAB_004fbdd0:
            iVar9 = *(int *)(iVar4 + 0x94);
            uStack_13c = CONCAT31(uStack_13c._1_3_,(char)uStack_148);
            for (; iVar9 != iVar1; iVar9 = *(int *)(iVar9 + 0x50)) {
              pcVar8 = (char *)(iVar9 + 0x14);
              if (0xf < *(uint *)(iVar9 + 0x28)) {
                pcVar8 = *(char **)pcVar8;
              }
              iVar7 = __stricmp(pcVar8,"GUILD_LEVEL");
              if (iVar7 == 0) {
                if (iVar9 != 0) {
                  puVar5 = (undefined4 *)(iVar9 + 0x30);
                  if (0xf < *(uint *)(iVar9 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uVar2 = FUN_008917b4(puVar5);
                    goto LAB_004fbe0a;
                  }
                }
                break;
              }
            }
            uVar2 = 0;
LAB_004fbe0a:
            iVar4 = *(int *)(iVar4 + 0x94);
            uStack_13c._0_2_ = CONCAT11(uVar2,(undefined1)uStack_13c);
            for (; iVar4 != iVar1; iVar4 = *(int *)(iVar4 + 0x50)) {
              pcVar8 = (char *)(iVar4 + 0x14);
              if (0xf < *(uint *)(iVar4 + 0x28)) {
                pcVar8 = *(char **)pcVar8;
              }
              iVar9 = __stricmp(pcVar8,"TEAM_RANK");
              if (iVar9 == 0) {
                if (iVar4 != 0) {
                  puVar5 = (undefined4 *)(iVar4 + 0x30);
                  if (0xf < *(uint *)(iVar4 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uVar2 = FUN_008917b4(puVar5);
                    goto LAB_004fbe3f;
                  }
                }
                break;
              }
            }
            uVar2 = 0;
LAB_004fbe3f:
            uStack_13c._0_3_ = CONCAT12(uVar2,(undefined2)uStack_13c);
            if ((&uStack_140 < local_d8) && (local_dc <= &uStack_140)) {
              iVar4 = (int)&uStack_140 - (int)local_dc;
              if (local_d8 == local_d4) {
                uVar3 = (int)local_d8 - (int)local_dc >> 3;
                if (0x1ffffffe < uVar3) {
LAB_004fc21a:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar3 = uVar3 + 1;
                uVar10 = (int)local_d4 - (int)local_dc >> 3;
                if (uVar10 < uVar3) {
                  if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar3) {
                    uVar10 = uVar3;
                  }
                  FUN_004e7330(uVar10);
                }
              }
              if (local_d8 != (undefined4 *)0x0) {
                *local_d8 = local_dc[(iVar4 >> 3) * 2];
                local_d8[1] = (local_dc + (iVar4 >> 3) * 2)[1];
              }
            }
            else {
              if (local_d8 == local_d4) {
                uVar3 = (int)local_d8 - (int)local_dc >> 3;
                if (0x1ffffffe < uVar3) goto LAB_004fc21a;
                uVar3 = uVar3 + 1;
                uVar10 = (int)local_d4 - (int)local_dc >> 3;
                if (uVar10 < uVar3) {
                  if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar3) {
                    uVar10 = uVar3;
                  }
                  FUN_004e7330(uVar10);
                }
              }
              if (local_d8 != (undefined4 *)0x0) {
                *local_d8 = uVar6;
                local_d8[1] = uStack_13c;
              }
            }
            local_d8 = local_d8 + 2;
            if ((char)uStack_148 != '\0') {
              if ((DAT_00fe1da0 & 1) == 0) {
                DAT_00fe1da0 = DAT_00fe1da0 | 1;
                local_c._0_1_ = 4;
                DAT_00fe1dac = 0;
                iVar4 = FUN_00891268(0x18);
                if (iVar4 == 0) {
                  pcStack_12c = (char *)0x0;
                  std::exception::exception((exception *)appuStack_11c,&pcStack_12c);
                  appuStack_11c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  __CxxThrowException_8(appuStack_11c,&DAT_00c857a8);
                }
                DAT_00fe1da8 = iVar4;
                *(int *)iVar4 = iVar4;
                *(int *)(DAT_00fe1da8 + 4) = DAT_00fe1da8;
                *(int *)(DAT_00fe1da8 + 8) = DAT_00fe1da8;
                *(undefined1 *)(DAT_00fe1da8 + 0x14) = 1;
                *(undefined1 *)(DAT_00fe1da8 + 0x15) = 1;
                _atexit(FUN_00bcee30);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              uVar6 = uStack_144;
              FUN_0082ef00(&uStack_144);
              if (iStack_128 == DAT_00fe1da8) {
                puStack_120 = (undefined1 *)FUN_00891268(0xc);
                if (puStack_120 == (undefined1 *)0x0) {
                  puStack_120 = (undefined1 *)0x0;
                }
                else {
                  *puStack_120 = 0;
                  *(undefined4 *)(puStack_120 + 8) = 0;
                }
                *(undefined4 *)(puStack_120 + 8) = uVar6;
                uStack_124 = uVar6;
                *puStack_120 = (char)uStack_148;
                uVar6 = FUN_0057ef20();
                FUN_0082f200(&DAT_00fe1da4,uVar6);
              }
            }
            iVar4 = FUN_0072e3c0();
          } while (iVar4 != 0);
          iStack_138 = 0;
        }
        FUN_004fc680();
        local_c = local_c & 0xffffff00;
        if (local_dc != (undefined4 *)0x0) {
          FUN_0089120c(local_dc);
        }
        local_dc = (undefined4 *)0x0;
        local_d8 = (undefined4 *)0x0;
        local_d4 = (undefined4 *)0x0;
        if (7 < local_e4) {
          FUN_0089120c(local_f8);
        }
        local_f8 = local_f8 & 0xffff0000;
        local_e4 = 7;
        local_e8 = 0;
        local_134 = FUN_0072e3c0();
      }
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    local_c = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_14c);
  return;
}

