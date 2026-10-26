
void FUN_0081bd10(undefined4 param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  undefined4 **ppuVar11;
  undefined4 **ppuVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined1 local_1b8 [12];
  undefined **local_1ac [4];
  undefined4 local_19c;
  char *local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 **local_18c;
  undefined4 *local_188;
  int local_184;
  undefined **local_180 [19];
  uint local_134;
  undefined4 local_124;
  uint local_120;
  undefined4 local_fc;
  uint local_ec;
  uint local_e8;
  int local_e0;
  undefined4 local_dc;
  uint local_d8;
  uint local_d0;
  undefined4 local_c0;
  uint local_bc;
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
  undefined1 local_98;
  uint local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_78 [4];
  undefined4 *local_74;
  undefined4 local_70;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  undefined1 local_4c [4];
  undefined4 local_48;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092620f;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_19c = param_1;
  local_18 = uVar5;
  FUN_0072ee30(local_180);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_8 = 0xffffffff;
    local_180[0] = TiXmlDocument::vftable;
    if (0xf < local_120) {
      FUN_0089120c(local_134);
    }
  }
  else {
    iVar6 = FUN_0072e360(uVar5);
    if (iVar6 != 0) {
      local_184 = FUN_0072e360(uVar5);
      iVar6 = local_184;
      while (iVar6 != 0) {
        local_98 = 0;
        local_80 = 7;
        local_84 = 0;
        local_94 = local_94 & 0xffff0000;
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 1;
        local_70 = 0;
        puVar7 = (undefined4 *)FUN_00891268(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          local_198 = (char *)0x0;
          std::exception::exception((exception *)local_1ac,&local_198);
          local_1ac[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_1ac,&DAT_00c857a8);
        }
        *puVar7 = puVar7;
        puVar7[1] = puVar7;
        puVar7[2] = puVar7;
        *(undefined1 *)(puVar7 + 0x11) = 1;
        *(undefined1 *)((int)puVar7 + 0x45) = 1;
        local_8 = CONCAT31(local_8._1_3_,2);
        local_74 = puVar7;
        iVar6 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar6 == 0) {
LAB_0081bea9:
          local_98 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0081bea9;
          local_98 = FUN_008917b4(puVar7);
        }
        local_a0 = 0xf;
        local_a4 = 0;
        local_b4 = local_b4 & 0xffffff00;
        FUN_00402a70(&DAT_00c0ce30,4);
        local_8._0_1_ = 3;
        uVar8 = FUN_0072ecf0(&DAT_00bf2375);
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        local_8._0_1_ = 5;
        FUN_00403040(uVar8,0,0xffffffff);
        local_8._0_1_ = 6;
        uVar8 = FUN_00402a50();
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00402800(uVar8);
        if (7 < local_bc) {
          FUN_0089120c(local_d0);
        }
        local_bc = 7;
        local_c0 = 0;
        local_d0 = local_d0 & 0xffff0000;
        if (0xf < local_54) {
          FUN_0089120c(local_68);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        if (0xf < local_d8) {
          FUN_0089120c(local_ec);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        local_d8 = 0xf;
        local_dc = 0;
        local_ec = local_ec & 0xffffff00;
        if (0xf < local_a0) {
          FUN_0089120c(local_b4);
        }
        iVar6 = FUN_0072e360();
        local_188 = (undefined4 *)iVar6;
        while (iVar6 != 0) {
          local_4c[0] = 0;
          local_48 = 0;
          local_30 = 7;
          local_34 = 0;
          local_44 = local_44 & 0xffff0000;
          local_28 = (undefined4 *)0x0;
          local_24 = (undefined4 *)0x0;
          local_20 = (undefined4 *)0x0;
          local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
          local_8 = CONCAT31(local_8._1_3_,8);
          for (iVar1 = *(int *)(iVar6 + 0x94); iVar1 != iVar6 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar10 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar9 = __stricmp(pcVar10,"DIFFICULTY");
            if (iVar9 == 0) {
              if (iVar1 != 0) {
                puVar7 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  local_4c[0] = FUN_008917b4(puVar7);
                  goto LAB_0081c04a;
                }
              }
              break;
            }
          }
          local_4c[0] = 0;
LAB_0081c04a:
          for (iVar1 = *(int *)(iVar6 + 0x94); iVar1 != iVar6 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar10 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar9 = __stricmp(pcVar10,"STAGE");
            if (iVar9 == 0) {
              if (iVar1 != 0) {
                puVar7 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  local_48 = FUN_008917b4(puVar7);
                  goto LAB_0081c07e;
                }
              }
              break;
            }
          }
          local_48 = 0;
LAB_0081c07e:
          local_a0 = 0xf;
          local_a4 = 0;
          local_b4 = local_b4 & 0xffffff00;
          FUN_00402a70(&DAT_00c0dfbc,4);
          local_8._0_1_ = 9;
          uVar8 = FUN_0072ecf0(&DAT_00bf2375);
          local_54 = 0xf;
          local_58 = 0;
          local_68 = local_68 & 0xffffff00;
          local_8._0_1_ = 0xb;
          FUN_00403040(uVar8,0,0xffffffff);
          local_8._0_1_ = 0xc;
          uVar8 = FUN_00402a50();
          local_8 = CONCAT31(local_8._1_3_,0xd);
          FUN_00402800(uVar8);
          if (7 < local_d8) {
            FUN_0089120c(local_ec);
          }
          local_d8 = 7;
          local_dc = 0;
          local_ec = local_ec & 0xffff0000;
          if (0xf < local_54) {
            FUN_0089120c(local_68);
          }
          local_54 = 0xf;
          local_58 = 0;
          local_68 = local_68 & 0xffffff00;
          if (0xf < local_bc) {
            FUN_0089120c(local_d0);
          }
          local_8 = CONCAT31(local_8._1_3_,8);
          local_bc = 0xf;
          local_c0 = 0;
          local_d0 = local_d0 & 0xffffff00;
          if (0xf < local_a0) {
            FUN_0089120c(local_b4);
          }
          iVar6 = FUN_0072e360();
          if ((iVar6 != 0) &&
             (ppuVar11 = (undefined4 **)FUN_0072e360(), local_18c = ppuVar11,
             ppuVar11 != (undefined4 **)0x0)) {
            do {
              local_18c = ppuVar11;
              for (ppuVar2 = (undefined4 **)ppuVar11[0x25]; ppuVar2 != ppuVar11 + 0x11;
                  ppuVar2 = (undefined4 **)ppuVar2[0x14]) {
                ppuVar12 = ppuVar2 + 5;
                if ((undefined4 *)0xf < ppuVar2[10]) {
                  ppuVar12 = (undefined4 **)*ppuVar12;
                }
                iVar6 = __stricmp((char *)ppuVar12,"PRODUCT");
                if (iVar6 == 0) {
                  if (ppuVar2 != (undefined4 **)0x0) {
                    ppuVar12 = ppuVar2 + 0xc;
                    if ((undefined4 *)0xf < ppuVar2[0x11]) {
                      ppuVar12 = (undefined4 **)*ppuVar12;
                    }
                    if (ppuVar12 != (undefined4 **)0x0) {
                      uVar8 = FUN_008917b4(ppuVar12);
                      goto LAB_0081c261;
                    }
                  }
                  break;
                }
              }
              uVar8 = 0;
LAB_0081c261:
              local_194 = uVar8;
              for (ppuVar2 = (undefined4 **)ppuVar11[0x25]; ppuVar2 != ppuVar11 + 0x11;
                  ppuVar2 = (undefined4 **)ppuVar2[0x14]) {
                ppuVar12 = ppuVar2 + 5;
                if ((undefined4 *)0xf < ppuVar2[10]) {
                  ppuVar12 = (undefined4 **)*ppuVar12;
                }
                iVar6 = __stricmp((char *)ppuVar12,"QTY");
                if (iVar6 == 0) {
                  if (ppuVar2 != (undefined4 **)0x0) {
                    ppuVar11 = ppuVar2 + 0xc;
                    if ((undefined4 *)0xf < ppuVar2[0x11]) {
                      ppuVar11 = (undefined4 **)*ppuVar11;
                    }
                    if (ppuVar11 != (undefined4 **)0x0) {
                      uVar4 = FUN_008917b4(ppuVar11);
                      goto LAB_0081c29a;
                    }
                  }
                  break;
                }
              }
              uVar4 = 0;
LAB_0081c29a:
              local_190 = CONCAT31(local_190._1_3_,uVar4);
              if ((&local_194 < local_24) && (local_28 <= &local_194)) {
                iVar6 = (int)&local_194 - (int)local_28;
                if (local_24 == local_20) {
                  uVar5 = (int)local_24 - (int)local_28 >> 3;
                  if (0x1ffffffe < uVar5) {
LAB_0081c624:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar5 = uVar5 + 1;
                  uVar14 = (int)local_20 - (int)local_28 >> 3;
                  if (uVar14 < uVar5) {
                    if (0x1fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar5) {
                      uVar14 = uVar5;
                    }
                    FUN_004e7330(uVar14);
                  }
                }
                if (local_24 != (undefined4 *)0x0) {
                  *local_24 = local_28[(iVar6 >> 3) * 2];
                  local_24[1] = (local_28 + (iVar6 >> 3) * 2)[1];
                }
              }
              else {
                if (local_24 == local_20) {
                  uVar5 = (int)local_24 - (int)local_28 >> 3;
                  if (0x1ffffffe < uVar5) goto LAB_0081c624;
                  uVar5 = uVar5 + 1;
                  uVar14 = (int)local_20 - (int)local_28 >> 3;
                  if (uVar14 < uVar5) {
                    if (0x1fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar5) {
                      uVar14 = uVar5;
                    }
                    FUN_004e7330(uVar14);
                  }
                }
                if (local_24 != (undefined4 *)0x0) {
                  *local_24 = uVar8;
                  local_24[1] = local_190;
                }
              }
              local_24 = local_24 + 2;
              ppuVar11 = (undefined4 **)FUN_0072e3c0();
            } while (ppuVar11 != (undefined4 **)0x0);
            local_18c = (undefined4 **)0x0;
          }
          uVar8 = FUN_0081d8a0();
          local_8._0_1_ = 0xe;
          FUN_0081e040(uVar8);
          FUN_0081d950(local_78,local_1b8);
          local_8 = CONCAT31(local_8._1_3_,8);
          if (local_e0 != 0) {
            FUN_0089120c(local_e0);
          }
          local_e0 = 0;
          local_dc = 0;
          local_d8 = 0;
          if (7 < local_e8) {
            FUN_0089120c(local_fc);
          }
          iVar6 = FUN_0072e3c0();
          local_8 = CONCAT31(local_8._1_3_,2);
          local_188 = (undefined4 *)iVar6;
          if (local_28 != (undefined4 *)0x0) {
            FUN_0089120c(local_28);
          }
          local_28 = (undefined4 *)0x0;
          local_24 = (undefined4 *)0x0;
          local_20 = (undefined4 *)0x0;
          if (7 < local_30) {
            FUN_0089120c(local_44);
          }
        }
        uVar13 = FUN_0081d8c0(local_4c);
        uVar8 = local_19c;
        local_8._0_1_ = 0xf;
        uVar13 = FUN_0081e110(uVar13);
        FUN_0081da10(uVar8,uVar13);
        local_188 = &local_48;
        local_18c = &local_28;
        local_8._0_1_ = 0x11;
        FUN_0081cbb0(*local_24,local_24);
        FUN_0089120c(local_24);
        local_8._0_1_ = 2;
        if (7 < local_30) {
          FUN_0089120c(local_44);
        }
        iVar6 = FUN_0072e3c0();
        local_188 = (undefined4 *)local_78;
        local_8 = CONCAT31(local_8._1_3_,0x13);
        local_184 = iVar6;
        FUN_0081cbb0(*local_74,local_74);
        FUN_0089120c(local_74);
        if (7 < local_80) {
          FUN_0089120c(local_94);
        }
        local_80 = 7;
        local_84 = 0;
        local_94 = local_94 & 0xffff0000;
      }
      local_8 = 0xffffffff;
      local_180[0] = TiXmlDocument::vftable;
      if (0xf < local_120) {
        FUN_0089120c(local_134);
      }
      local_134 = local_134 & 0xffffff00;
      goto LAB_0081c5eb;
    }
    local_8 = 0xffffffff;
    local_180[0] = TiXmlDocument::vftable;
    if (0xf < local_120) {
      FUN_0089120c(local_134);
      local_134 = local_134 & 0xffffff00;
      goto LAB_0081c5eb;
    }
  }
  local_134 = local_134 & 0xffffff00;
LAB_0081c5eb:
  local_124 = 0;
  local_120 = 0xf;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

