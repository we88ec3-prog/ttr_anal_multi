
void FUN_004d8f50(undefined4 param_1)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char *_Str1;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int **ppiVar11;
  int iVar12;
  undefined1 local_1f4 [8];
  undefined1 local_1ec [8];
  undefined1 local_1e4 [8];
  undefined1 local_1dc [24];
  undefined **local_1c4 [4];
  char *local_1b4;
  undefined4 local_1b0 [2];
  int *local_1a8 [4];
  int **local_198;
  int **local_194;
  int **local_190;
  undefined4 *local_188;
  undefined4 *local_184;
  undefined4 *local_180;
  undefined1 local_178 [4];
  undefined4 *local_174;
  int local_170;
  int local_168;
  undefined1 local_161;
  uint local_160;
  int *local_15c;
  undefined2 local_158 [2];
  undefined4 local_154 [5];
  uint local_140;
  uint local_138;
  undefined4 local_128;
  uint local_124;
  undefined **local_110 [17];
  char local_cc;
  uint local_c4;
  undefined4 local_b4;
  uint local_b0;
  uint local_98;
  undefined4 local_88;
  uint local_84;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined2 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  int local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924c85;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1a8[2] = (int *)param_1;
  local_18 = uVar3;
  FUN_0072ed80(local_110);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_cc == '\0') {
    iVar4 = FUN_0072e2e0("CONTRACT_LIST");
    if (iVar4 != 0) {
      local_168 = FUN_0072e360(uVar3);
      if (local_168 != 0) {
        do {
          iVar4 = FUN_007300a0(&DAT_00c0ce2c);
          if (iVar4 == 0) {
LAB_004d9089:
            local_160 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_004d9089;
            local_160 = FUN_008917b4(puVar5);
          }
          local_1a8[3] = (int *)(local_160 & 0xffff);
          local_84 = 7;
          local_68 = 7;
          local_88 = 0;
          local_98 = local_98 & 0xffff0000;
          local_6c = 0;
          local_7c = local_7c & 0xffff0000;
          local_60 = 0;
          local_5c = 0;
          local_58 = 0;
          local_8._0_1_ = 1;
          local_34 = local_34 & 0xffffff00;
          local_20 = 0xf;
          local_24 = (undefined4 *)0x0;
          FUN_00402a70(&DAT_00c0ce30,4);
          local_8._0_1_ = 2;
          uVar6 = FUN_0072ecf0(&DAT_00bf2375);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00440130(uVar6);
          if (0xf < local_3c) {
            FUN_0089120c(local_50);
          }
          local_8._0_1_ = 1;
          local_3c = 0xf;
          local_40 = 0;
          local_50 = local_50 & 0xffffff00;
          if (0xf < local_20) {
            FUN_0089120c(local_34);
          }
          local_20 = 0xf;
          local_24 = (undefined4 *)0x0;
          local_34 = local_34 & 0xffffff00;
          FUN_00402a70("COMMENT",7);
          local_8._0_1_ = 4;
          uVar6 = FUN_0072ecf0(&DAT_00bf2375);
          local_8 = CONCAT31(local_8._1_3_,5);
          FUN_00440130(uVar6);
          if (0xf < local_3c) {
            FUN_0089120c(local_50);
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          local_3c = 0xf;
          local_40 = 0;
          local_50 = local_50 & 0xffffff00;
          if (0xf < local_20) {
            FUN_0089120c(local_34);
          }
          iVar4 = FUN_007300a0(&DAT_00bfb800);
          if (iVar4 == 0) {
LAB_004d91fd:
            uVar2 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_004d91fd;
            uVar2 = FUN_008917b4(puVar5);
          }
          local_60 = CONCAT11(local_60._1_1_,uVar2);
          iVar4 = FUN_007300a0("TARGET_CHAR");
          if (iVar4 == 0) {
LAB_004d922b:
            uVar2 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_004d922b;
            uVar2 = FUN_008917b4(puVar5);
          }
          local_60 = CONCAT11(uVar2,(undefined1)local_60);
          iVar4 = FUN_007300a0("TARGET_ITEM");
          if (iVar4 == 0) {
LAB_004d9259:
            local_5c = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_004d9259;
            local_5c = FUN_008917b4(puVar5);
          }
          iVar4 = FUN_007300a0("VALUE");
          if (iVar4 == 0) {
LAB_004d9289:
            local_58 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_004d9289;
            local_58 = FUN_008917b4(puVar5);
          }
          local_158[0] = (undefined2)local_160;
          FUN_004d9c80(local_154);
          piVar8 = local_1a8[2];
          local_8._0_1_ = 6;
          uVar6 = FUN_004dbfc0(local_158);
          FUN_004db840(piVar8,uVar6);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (7 < local_124) {
            FUN_0089120c(local_138);
          }
          local_124 = 7;
          local_128 = 0;
          local_138 = local_138 & 0xffff0000;
          if (7 < local_140) {
            FUN_0089120c(local_154[0]);
          }
          local_170 = 0;
          puVar5 = (undefined4 *)FUN_00891268(0x24);
          if (puVar5 == (undefined4 *)0x0) {
            local_1b4 = (char *)0x0;
            std::exception::exception((exception *)local_1c4,&local_1b4);
            local_1c4[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_1c4,&DAT_00c857a8);
          }
          *puVar5 = puVar5;
          puVar5[1] = puVar5;
          puVar5[2] = puVar5;
          *(undefined1 *)(puVar5 + 8) = 1;
          *(undefined1 *)((int)puVar5 + 0x21) = 1;
          local_8 = CONCAT31(local_8._1_3_,7);
          local_174 = puVar5;
          local_160 = FUN_0072e360();
          while (local_160 != 0) {
            iVar12 = local_160 + 0x44;
            for (iVar4 = *(int *)(local_160 + 0x94); iVar4 != iVar12; iVar4 = *(int *)(iVar4 + 0x50)
                ) {
              _Str1 = (char *)(iVar4 + 0x14);
              if (0xf < *(uint *)(iVar4 + 0x28)) {
                _Str1 = *(char **)_Str1;
              }
              iVar7 = __stricmp(_Str1,"LEVEL");
              if (iVar7 == 0) {
                if (iVar4 != 0) {
                  puVar5 = (undefined4 *)(iVar4 + 0x30);
                  if (0xf < *(uint *)(iVar4 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_161 = FUN_008917b4(puVar5);
                    goto LAB_004d93d1;
                  }
                }
                break;
              }
            }
            local_161 = 0;
LAB_004d93d1:
            ppiVar11 = (int **)0x0;
            local_198 = (int **)0x0;
            local_194 = (int **)0x0;
            local_190 = (int **)0x0;
            local_8._0_1_ = 8;
            piVar8 = (int *)FUN_0072e360();
            while (local_15c = piVar8, piVar8 != (int *)0x0) {
              for (piVar1 = (int *)piVar8[0x25]; piVar1 != piVar8 + 0x11;
                  piVar1 = (int *)piVar1[0x14]) {
                piVar9 = piVar1 + 5;
                if (0xf < (uint)piVar1[10]) {
                  piVar9 = (int *)*piVar9;
                }
                iVar4 = __stricmp((char *)piVar9,"ID");
                if (iVar4 == 0) {
                  if (piVar1 != (int *)0x0) {
                    piVar9 = piVar1 + 0xc;
                    if (0xf < (uint)piVar1[0x11]) {
                      piVar9 = (int *)*piVar9;
                    }
                    if (piVar9 != (int *)0x0) {
                      local_1a8[0] = (int *)FUN_008917b4(piVar9);
                      goto LAB_004d944d;
                    }
                  }
                  break;
                }
              }
              local_1a8[0] = (int *)0x0;
LAB_004d944d:
              for (piVar1 = (int *)piVar8[0x25]; piVar1 != piVar8 + 0x11;
                  piVar1 = (int *)piVar1[0x14]) {
                piVar9 = piVar1 + 5;
                if (0xf < (uint)piVar1[10]) {
                  piVar9 = (int *)*piVar9;
                }
                iVar4 = __stricmp((char *)piVar9,"VALUE");
                if (iVar4 == 0) {
                  if (piVar1 != (int *)0x0) {
                    piVar8 = piVar1 + 0xc;
                    if (0xf < (uint)piVar1[0x11]) {
                      piVar8 = (int *)*piVar8;
                    }
                    if (piVar8 != (int *)0x0) {
                      piVar8 = (int *)FUN_008917b4(piVar8);
                      goto LAB_004d948a;
                    }
                  }
                  break;
                }
              }
              piVar8 = (int *)0x0;
LAB_004d948a:
              local_1a8[1] = piVar8;
              if ((local_1a8 < ppiVar11) && (local_198 <= local_1a8)) {
                iVar4 = (int)local_1a8 - (int)local_198 >> 3;
                if (ppiVar11 == local_190) {
                  uVar3 = (int)ppiVar11 - (int)local_198 >> 3;
                  if (0x1ffffffe < uVar3) goto LAB_004d9b96;
                  uVar3 = uVar3 + 1;
                  uVar10 = (int)local_190 - (int)local_198 >> 3;
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
                    ppiVar11 = local_194;
                  }
                }
                if (ppiVar11 != (int **)0x0) {
                  *ppiVar11 = local_198[iVar4 * 2];
                  ppiVar11[1] = local_198[iVar4 * 2 + 1];
                }
              }
              else {
                if (ppiVar11 == local_190) {
                  uVar3 = (int)ppiVar11 - (int)local_198 >> 3;
                  if (0x1ffffffe < uVar3) goto LAB_004d9b96;
                  uVar3 = uVar3 + 1;
                  uVar10 = (int)local_190 - (int)local_198 >> 3;
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
                    ppiVar11 = local_194;
                  }
                }
                if (ppiVar11 != (int **)0x0) {
                  *ppiVar11 = local_1a8[0];
                  ppiVar11[1] = piVar8;
                }
              }
              ppiVar11 = ppiVar11 + 2;
              local_194 = ppiVar11;
              piVar8 = (int *)FUN_0072e3c0();
            }
            FUN_004db7d0();
            local_8 = CONCAT31(local_8._1_3_,9);
            FUN_004dc160();
            FUN_004dba00(local_178,local_1f4);
            if (local_28 != 0) {
              FUN_0089120c(local_28);
            }
            local_8 = CONCAT31(local_8._1_3_,7);
            if (local_198 != (int **)0x0) {
              FUN_0089120c(local_198);
            }
            local_198 = (int **)0x0;
            local_194 = (int **)0x0;
            local_190 = (int **)0x0;
            local_160 = FUN_0072e3c0();
          }
          if (local_170 != 0) {
            uVar6 = FUN_004db7f0();
            local_8._0_1_ = 10;
            uVar6 = FUN_004dc090(uVar6);
            FUN_004db900(local_1ec,uVar6);
            local_15c = &local_28;
            local_8._0_1_ = 0xb;
            FUN_0085e680(*local_24,local_24);
            local_8 = CONCAT31(local_8._1_3_,7);
            FUN_0089120c(local_24);
          }
          FUN_004d3610(local_174[1]);
          local_174[1] = local_174;
          *local_174 = local_174;
          puVar5 = (undefined4 *)0x0;
          local_174[2] = local_174;
          local_170 = 0;
          local_188 = (undefined4 *)0x0;
          local_184 = (undefined4 *)0x0;
          local_180 = (undefined4 *)0x0;
          local_8._0_1_ = 0xc;
          piVar8 = (int *)FUN_0072e360();
          while (piVar8 != (int *)0x0) {
            local_15c = piVar8;
            for (piVar1 = (int *)piVar8[0x25]; piVar1 != piVar8 + 0x11; piVar1 = (int *)piVar1[0x14]
                ) {
              piVar9 = piVar1 + 5;
              if (0xf < (uint)piVar1[10]) {
                piVar9 = (int *)*piVar9;
              }
              iVar4 = __stricmp((char *)piVar9,"ID");
              if (iVar4 == 0) {
                if (piVar1 != (int *)0x0) {
                  piVar9 = piVar1 + 0xc;
                  if (0xf < (uint)piVar1[0x11]) {
                    piVar9 = (int *)*piVar9;
                  }
                  if (piVar9 != (int *)0x0) {
                    local_1b0[0] = FUN_008917b4(piVar9);
                    goto LAB_004d97dd;
                  }
                }
                break;
              }
            }
            local_1b0[0] = 0;
LAB_004d97dd:
            for (piVar1 = (int *)piVar8[0x25]; piVar1 != piVar8 + 0x11; piVar1 = (int *)piVar1[0x14]
                ) {
              piVar9 = piVar1 + 5;
              if (0xf < (uint)piVar1[10]) {
                piVar9 = (int *)*piVar9;
              }
              iVar4 = __stricmp((char *)piVar9,"VALUE");
              if (iVar4 == 0) {
                if (piVar1 != (int *)0x0) {
                  piVar8 = piVar1 + 0xc;
                  if (0xf < (uint)piVar1[0x11]) {
                    piVar8 = (int *)*piVar8;
                  }
                  if (piVar8 != (int *)0x0) {
                    uVar6 = FUN_008917b4(piVar8);
                    goto LAB_004d981a;
                  }
                }
                break;
              }
            }
            uVar6 = 0;
LAB_004d981a:
            local_1b0[1] = uVar6;
            if ((local_1b0 < puVar5) && (local_188 <= local_1b0)) {
              iVar4 = (int)local_1b0 - (int)local_188 >> 3;
              if (puVar5 == local_180) {
                uVar3 = (int)puVar5 - (int)local_188 >> 3;
                if (0x1ffffffe < uVar3) goto LAB_004d9b96;
                uVar3 = uVar3 + 1;
                uVar10 = (int)local_180 - (int)local_188 >> 3;
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
                  puVar5 = local_184;
                }
              }
              if (puVar5 != (undefined4 *)0x0) {
                *puVar5 = local_188[iVar4 * 2];
                puVar5[1] = local_188[iVar4 * 2 + 1];
              }
            }
            else {
              if (puVar5 == local_180) {
                uVar3 = (int)puVar5 - (int)local_188 >> 3;
                if (0x1ffffffe < uVar3) {
LAB_004d9b96:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar3 = uVar3 + 1;
                uVar10 = (int)local_180 - (int)local_188 >> 3;
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
                  puVar5 = local_184;
                }
              }
              if (puVar5 != (undefined4 *)0x0) {
                *puVar5 = local_1b0[0];
                puVar5[1] = uVar6;
              }
            }
            puVar5 = puVar5 + 2;
            local_184 = puVar5;
            piVar8 = (int *)FUN_0072e3c0();
          }
          local_15c = (int *)0x0;
          if ((int)puVar5 - (int)local_188 >> 3 != 0) {
            local_15c = (int *)0x0;
            FUN_004db820();
            local_8._0_1_ = 0xd;
            FUN_004dc160();
            FUN_004dba00(local_178,local_1dc);
            local_8._0_1_ = 0xc;
            if (local_28 != 0) {
              FUN_0089120c(local_28);
            }
          }
          if (local_170 != 0) {
            uVar6 = FUN_004db7f0();
            local_8._0_1_ = 0xe;
            uVar6 = FUN_004dc090(uVar6);
            FUN_004db900(local_1e4,uVar6);
            local_1a8[3] = &local_28;
            local_8._0_1_ = 0xf;
            FUN_0085e680(*local_24,local_24);
            FUN_0089120c(local_24);
          }
          if (local_188 != (undefined4 *)0x0) {
            FUN_0089120c(local_188);
          }
          local_188 = (undefined4 *)0x0;
          local_184 = (undefined4 *)0x0;
          local_180 = (undefined4 *)0x0;
          local_8._0_1_ = 0x10;
          FUN_0085e680(*local_174,local_174);
          FUN_0089120c(local_174);
          local_8 = (uint)local_8._1_3_ << 8;
          if (7 < local_68) {
            FUN_0089120c(local_7c);
          }
          local_68 = 7;
          local_6c = 0;
          local_7c = local_7c & 0xffff0000;
          if (7 < local_84) {
            FUN_0089120c(local_98);
          }
          local_84 = 7;
          local_88 = 0;
          local_98 = local_98 & 0xffff0000;
          local_168 = FUN_0072e3c0();
        } while (local_168 != 0);
        local_168 = 0;
      }
      local_8 = 0xffffffff;
      local_110[0] = TiXmlDocument::vftable;
      if (0xf < local_b0) {
        FUN_0089120c(local_c4);
      }
      local_c4 = local_c4 & 0xffffff00;
      goto LAB_004d9b5d;
    }
    local_8 = 0xffffffff;
    local_110[0] = TiXmlDocument::vftable;
    if (0xf < local_b0) {
      FUN_0089120c(local_c4);
      local_c4 = local_c4 & 0xffffff00;
      goto LAB_004d9b5d;
    }
  }
  else {
    local_8 = 0xffffffff;
    local_110[0] = TiXmlDocument::vftable;
    if (0xf < local_b0) {
      FUN_0089120c(local_c4);
    }
  }
  local_c4 = local_c4 & 0xffffff00;
LAB_004d9b5d:
  local_b0 = 0xf;
  local_b4 = 0;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

