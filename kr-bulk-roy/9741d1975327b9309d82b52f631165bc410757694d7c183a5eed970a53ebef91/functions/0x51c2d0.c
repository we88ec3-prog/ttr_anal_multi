
/* WARNING: Type propagation algorithm not settling */

void FUN_0051c2d0(int param_1)

{
  ushort uVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int *piVar4;
  char cVar5;
  short sVar6;
  undefined4 *******pppppppuVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  short *******pppppppsVar11;
  undefined4 *puVar12;
  uint *puVar13;
  int *piVar14;
  uint uVar15;
  int **ppiVar16;
  short *******pppppppsVar17;
  undefined1 uVar18;
  byte bVar19;
  uint uVar20;
  undefined2 uVar21;
  long lVar22;
  int iVar23;
  __time64_t _Var24;
  undefined1 local_240 [16];
  undefined **local_230 [3];
  int local_224;
  int *local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  int local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  int local_1e4;
  int local_1e0;
  undefined1 local_1dc [4];
  int *local_1d8;
  undefined4 local_1d4;
  int local_1cc;
  char *local_1c8;
  int local_1c4;
  int local_1c0;
  undefined1 local_1bc [8];
  int local_1b4;
  int local_1b0;
  int *local_1ac;
  int local_1a8;
  int *local_1a4;
  int local_1a0;
  int *local_19c;
  int *local_198;
  int *local_194;
  int *local_190;
  int local_188;
  undefined2 local_184;
  int local_180;
  int *local_17c [4];
  byte local_169;
  uint local_168;
  int *local_164;
  uint *local_160;
  tm local_15c;
  undefined4 local_138;
  undefined4 local_134;
  undefined1 local_70;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  short *******local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 *******local_34 [3];
  int local_28;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923b8e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_180 = param_1;
  local_138 = 0;
  local_134 = 0;
  FUN_0071bc20(local_18);
  local_70 = 0;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  local_8 = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (undefined4 *******)((uint)local_34[0] & 0xffffff00);
  FUN_00402a70("Table/Product.xml",0x11);
  local_8 = CONCAT31(local_8._1_3_,1);
  pppppppuVar7 = local_34[0];
  if (local_20 < 0x10) {
    pppppppuVar7 = local_34;
  }
  piVar8 = (int *)FUN_00714770(pppppppuVar7,&DAT_00bed1e0);
  if (piVar8 == (int *)0x0) {
    cVar5 = '\0';
  }
  else {
    (**(code **)(*piVar8 + 0x38))();
    uVar10 = (**(code **)(*piVar8 + 0x2c))();
    cVar5 = FUN_00499340(uVar10);
    (**(code **)(*piVar8 + 4))();
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (cVar5 == '\0') {
    local_8 = 0xffffffff;
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  else {
    local_17c[3] = (int *)local_138;
    local_17c[3] = (int *)FUN_0071ba40("PRODUCT_INFO");
    local_17c[3] = (int *)*local_17c[3];
    if (local_17c[3] != (int *)0x0) {
      local_1d4 = 0;
      local_1d8 = (int *)FUN_00891268(0x24);
      if (local_1d8 == (int *)0x0) {
        local_1c8 = (char *)0x0;
        std::exception::exception((exception *)local_230,&local_1c8);
        local_230[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_230,&DAT_00c857a8);
      }
      *local_1d8 = (int)local_1d8;
      local_1d8[1] = (int)local_1d8;
      local_1d8[2] = (int)local_1d8;
      *(undefined1 *)(local_1d8 + 8) = 1;
      *(undefined1 *)((int)local_1d8 + 0x21) = 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      local_1fc = FUN_004034e0();
      FUN_00719da0(&local_160);
      if (local_160 != (uint *)0x0) {
LAB_0051c4f3:
        iVar9 = FUN_00891268(0x6c);
        if (iVar9 == 0) {
          local_164 = (int *)0x0;
        }
        else {
          local_164 = (int *)FUN_0051be10();
        }
        piVar8 = local_164;
        lVar22 = 0;
        local_17c[0] = local_164;
        FUN_0071baa0("PRODUCT");
        if (local_204 != 0) {
          if (*(char **)(local_204 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_204 + 8),(char **)0x0,10);
          }
        }
        piVar8[7] = lVar22;
        local_3c = 7;
        local_40 = 0;
        local_50[0] = (short *******)((uint)local_50[0] & 0xffff0000);
        local_8._0_1_ = 3;
        uVar10 = FUN_00719f10(&local_160,&DAT_00bf2375);
        local_8._0_1_ = 4;
        FUN_00440130(uVar10);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        pppppppsVar17 = local_50[0];
        if (local_3c < 8) {
          pppppppsVar17 = (short *******)local_50;
        }
        pppppppsVar11 = pppppppsVar17;
        do {
          sVar6 = *(short *)pppppppsVar11;
          pppppppsVar11 = (short *******)((int)pppppppsVar11 + 2);
        } while (sVar6 != 0);
        FUN_00402160(pppppppsVar17,(int)pppppppsVar11 - (int)((int)pppppppsVar17 + 2) >> 1);
        lVar22 = 0;
        FUN_0071baa0(&DAT_00bf2330);
        if (local_1f4 != 0) {
          if (*(char **)(local_1f4 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1f4 + 8),(char **)0x0,10);
          }
        }
        piVar8[8] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("LEELOO");
        if (local_210 != 0) {
          if (*(char **)(local_210 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_210 + 8),(char **)0x0,10);
          }
        }
        piVar8[9] = lVar22;
        lVar22 = 0;
        FUN_0071baa0(&DAT_00c0e61c);
        if (local_1f0 != 0) {
          if (*(char **)(local_1f0 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1f0 + 8),(char **)0x0,10);
          }
        }
        piVar8[10] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("BATTLE_POINT");
        if (local_208 != 0) {
          if (*(char **)(local_208 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_208 + 8),(char **)0x0,10);
          }
        }
        piVar8[0xb] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("HOORU");
        if (local_1f8 != 0) {
          if (*(char **)(local_1f8 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1f8 + 8),(char **)0x0,10);
          }
        }
        piVar8[0xc] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("SELL_LEELOO");
        if (local_218 != 0) {
          if (*(char **)(local_218 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_218 + 8),(char **)0x0,10);
          }
        }
        piVar8[0xd] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("PRIVATE_TYPE");
        if (local_200 != 0) {
          if (*(char **)(local_200 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_200 + 8),(char **)0x0,10);
          }
        }
        piVar8[0xe] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("CAN_BE_DISMANTLED");
        if (local_1e4 != 0) {
          if (*(char **)(local_1e4 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1e4 + 8),(char **)0x0,10);
          }
        }
        piVar8[0xf] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("LEVELUP_DISABLED");
        if (local_1ec != 0) {
          if (*(char **)(local_1ec + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1ec + 8),(char **)0x0,10);
          }
        }
        iVar9 = local_1fc;
        piVar8[0x10] = lVar22;
        local_1b4 = piVar8[8];
        FUN_008438c0(&local_1b4);
        if (local_1e0 == *(int *)(iVar9 + 4)) {
          iVar9 = 0;
        }
        else {
          iVar9 = *(int *)(local_1e0 + 0x10);
        }
        piVar8[0x15] = iVar9;
        lVar22 = 0;
        FUN_0071baa0("START_DATETIME");
        if (local_20c != 0) {
          if (*(char **)(local_20c + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_20c + 8),(char **)0x0,10);
          }
        }
        piVar8[0x11] = lVar22;
        lVar22 = 0;
        FUN_0071baa0("END_DATETIME");
        if (local_214 != 0) {
          if (*(char **)(local_214 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_214 + 8),(char **)0x0,10);
          }
        }
        piVar8[0x12] = lVar22;
        uVar18 = 0;
        FUN_0071baa0("PRODUCT_RANK");
        if (local_21c != 0) {
          if (*(char **)(local_21c + 8) == (char *)0x0) {
            uVar18 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_21c + 8),(char **)0x0,10);
            uVar18 = (undefined1)lVar22;
          }
        }
        piVar8 = local_164;
        *(undefined1 *)(local_164 + 0x13) = uVar18;
        uVar18 = 0;
        FUN_0071baa0("OPENED_SLOT");
        if (local_1e8 != 0) {
          if (*(char **)(local_1e8 + 8) == (char *)0x0) {
            uVar18 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1e8 + 8),(char **)0x0,10);
            uVar18 = (undefined1)lVar22;
          }
        }
        *(undefined1 *)((int)piVar8 + 0x4d) = uVar18;
        lVar22 = 0;
        FUN_0071baa0("START_DATETIME");
        if (local_19c != (int *)0x0) {
          if ((char *)local_19c[2] == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol((char *)local_19c[2],(char **)0x0,10);
          }
        }
        local_1a0 = lVar22;
        if (lVar22 != 0) {
          __gmtime32_s(&local_15c,&local_1a0);
          _Var24 = __mktime64(&local_15c);
          local_1b4 = (int)((ulonglong)_Var24 >> 0x20);
          piVar8[0x11] = (int)_Var24;
        }
        lVar22 = 0;
        FUN_0071baa0("END_DATETIME");
        if (local_1b0 != 0) {
          if (*(char **)(local_1b0 + 8) == (char *)0x0) {
            lVar22 = 0;
          }
          else {
            lVar22 = _strtol(*(char **)(local_1b0 + 8),(char **)0x0,10);
          }
        }
        local_1a0 = lVar22;
        if (lVar22 != 0) {
          __gmtime32_s(&local_15c,&local_1a0);
          _Var24 = __mktime64(&local_15c);
          local_1b4 = (int)((ulonglong)_Var24 >> 0x20);
          piVar8[0x12] = (int)_Var24;
        }
        FUN_00719da0(&local_1c4);
        if (local_1c4 != 0) {
          puVar12 = (undefined4 *)FUN_00891268(0xc);
          if (puVar12 == (undefined4 *)0x0) {
            puVar12 = (undefined4 *)0x0;
          }
          else {
            lVar22 = 0;
            FUN_0071baa0("TARGET_PRODUCT");
            if (local_1ac != (int *)0x0) {
              if ((char *)local_1ac[2] == (char *)0x0) {
                lVar22 = 0;
              }
              else {
                lVar22 = _strtol((char *)local_1ac[2],(char **)0x0,10);
              }
            }
            puVar12[1] = 2;
            *puVar12 = ITEM::CMakingRecipe::vftable;
            puVar12[2] = lVar22;
          }
          local_164[puVar12[1] + 0x16] = (int)puVar12;
        }
        FUN_00719da0(&local_1cc);
        if (local_1cc != 0) {
          piVar8 = (int *)0x0;
          local_198 = (int *)0x0;
          local_194 = (int *)0x0;
          local_190 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,5);
          FUN_00719da0(&local_168);
          while (local_168 != 0) {
            local_1b4 = 0;
            FUN_0071baa0("PROVIDE_PRODUCT");
            if (local_1a4 != (int *)0x0) {
              if ((char *)local_1a4[2] == (char *)0x0) {
                local_1b4 = 0;
              }
              else {
                local_1b4 = _strtol((char *)local_1a4[2],(char **)0x0,10);
              }
            }
            uVar21 = 0;
            FUN_0071baa0(&DAT_00c0d848);
            if (local_1a8 != 0) {
              if (*(char **)(local_1a8 + 8) == (char *)0x0) {
                uVar21 = 0;
              }
              else {
                lVar22 = _strtol(*(char **)(local_1a8 + 8),(char **)0x0,10);
                uVar21 = (undefined2)lVar22;
              }
            }
            iVar9 = local_1b4;
            local_188 = local_1b4;
            local_184 = uVar21;
            if ((&local_188 < piVar8) && (local_198 <= &local_188)) {
              iVar9 = (int)&local_188 - (int)local_198 >> 3;
              if (piVar8 == local_190) {
                FUN_0051d890();
                piVar8 = local_194;
              }
              if (piVar8 != (int *)0x0) {
                *piVar8 = local_198[iVar9 * 2];
                *(short *)(piVar8 + 1) = (short)local_198[iVar9 * 2 + 1];
              }
            }
            else {
              if (piVar8 == local_190) {
                FUN_0051d890();
                piVar8 = local_194;
              }
              if (piVar8 != (int *)0x0) {
                *piVar8 = iVar9;
                *(undefined2 *)(piVar8 + 1) = uVar21;
              }
            }
            piVar8 = piVar8 + 2;
            local_194 = piVar8;
            puVar13 = (uint *)FUN_00719e00(local_1bc);
            local_168 = *puVar13;
          }
          FUN_0051ddc0();
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_004fcae0();
          FUN_004d3af0(local_1dc,local_240);
          if (local_28 != 0) {
            FUN_0089120c(local_28);
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          if (local_198 != (int *)0x0) {
            FUN_0089120c(local_198);
          }
          local_198 = (int *)0x0;
          local_194 = (int *)0x0;
          local_190 = (int *)0x0;
        }
        FUN_00719da0(local_17c + 3);
        if ((local_17c[3] != (int *)0x0) &&
           (FUN_00719da0(local_17c + 2), (uint *)local_17c[2] != (uint *)0x0)) {
LAB_0051cd10:
          puVar13 = (uint *)local_17c[2];
          uVar20 = 0;
          if ((uint *)local_17c[2] != (uint *)0x0) {
            for (uVar15 = local_17c[2][7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
              if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
                 (iVar9 = __stricmp("type",*(char **)(uVar15 + 4)), iVar9 == 0)) {
                if (*(char **)(uVar15 + 8) == (char *)0x0) {
                  uVar20 = 0;
                }
                else {
                  uVar20 = _strtol(*(char **)(uVar15 + 8),(char **)0x0,10);
                }
                break;
              }
            }
          }
          if ((uVar20 & 0xff) == 1) {
            puVar12 = (undefined4 *)FUN_00891268(0xc);
            if (puVar12 == (undefined4 *)0x0) {
              puVar12 = (undefined4 *)0x0;
            }
            else {
              uVar21 = 0;
              FUN_0071baa0("contract");
              if (local_17c[1] != (int *)0x0) {
                if ((char *)local_17c[1][2] == (char *)0x0) {
                  uVar21 = 0;
                }
                else {
                  lVar22 = _strtol((char *)local_17c[1][2],(char **)0x0,10);
                  uVar21 = (undefined2)lVar22;
                }
              }
              puVar12[1] = 4;
              *puVar12 = ITEM::CUsedContractLimit::vftable;
              *(undefined2 *)(puVar12 + 2) = uVar21;
            }
            local_164[puVar12[1] + 0x16] = (int)puVar12;
            puVar13 = (uint *)local_17c[2];
          }
          if (puVar13 != (uint *)0x0) {
            for (puVar13 = (uint *)puVar13[6]; puVar13 != (uint *)0x0; puVar13 = (uint *)puVar13[6])
            {
              if (((char *)puVar13[2] != (char *)0x0) &&
                 (iVar9 = __stricmp("PROPERTIES",(char *)puVar13[2]), iVar9 == 0))
              goto LAB_0051ce04;
            }
          }
          goto LAB_0051ce48;
        }
LAB_0051ce5a:
        iVar9 = local_180;
        local_224 = local_164[7];
        local_220 = local_164;
        uVar10 = FUN_0057ef20();
        FUN_0057e850(iVar9,uVar10);
        ppiVar16 = *(int ***)(iVar9 + 0x14);
        puVar13 = (uint *)(iVar9 + 0x10);
        if (local_17c < ppiVar16) {
          ppiVar2 = (int **)*puVar13;
          if (local_17c < ppiVar2) goto LAB_0051cf05;
          if (ppiVar16 == *(int ***)(iVar9 + 0x18)) {
            uVar20 = (int)ppiVar16 - (int)ppiVar2 >> 2;
            if (0x3ffffffe < uVar20) goto LAB_0051d085;
            uVar20 = uVar20 + 1;
            uVar15 = (int)*(int ***)(iVar9 + 0x18) - (int)ppiVar2 >> 2;
            if (uVar15 < uVar20) {
              if (0x3fffffff - (uVar15 >> 1) < uVar15) {
                uVar15 = 0;
              }
              else {
                uVar15 = uVar15 + (uVar15 >> 1);
              }
              if (uVar15 < uVar20) {
                uVar15 = uVar20;
              }
              FUN_00797980(uVar15);
            }
          }
          if (*(undefined4 **)(iVar9 + 0x14) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar9 + 0x14) =
                 *(undefined4 *)(*puVar13 + ((int)local_17c - (int)ppiVar2 >> 2) * 4);
          }
        }
        else {
LAB_0051cf05:
          if (ppiVar16 == *(int ***)(iVar9 + 0x18)) {
            uVar20 = (int)((int)ppiVar16 - *puVar13) >> 2;
            if (0x3ffffffe < uVar20) {
LAB_0051d085:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar20 = uVar20 + 1;
            uVar15 = (int)((int)*(int ***)(iVar9 + 0x18) - *puVar13) >> 2;
            if (uVar15 < uVar20) {
              if (0x3fffffff - (uVar15 >> 1) < uVar15) {
                uVar15 = 0;
              }
              else {
                uVar15 = uVar15 + (uVar15 >> 1);
              }
              if (uVar15 < uVar20) {
                uVar15 = uVar20;
              }
              FUN_00797980(uVar15);
            }
          }
          if (*(int **)(iVar9 + 0x14) != (int *)0x0) {
            **(int **)(iVar9 + 0x14) = (int)local_164;
          }
        }
        *(int *)(iVar9 + 0x14) = *(int *)(iVar9 + 0x14) + 4;
        local_8 = CONCAT31(local_8._1_3_,2);
        if (7 < local_3c) {
          FUN_0089120c(local_50[0]);
        }
        if (local_160 != (uint *)0x0) {
          for (puVar13 = (uint *)local_160[6]; puVar13 != (uint *)0x0; puVar13 = (uint *)puVar13[6])
          {
            if (((char *)puVar13[2] != (char *)0x0) &&
               (iVar9 = __stricmp("PRODUCT",(char *)puVar13[2]), iVar9 == 0)) goto LAB_0051cfa6;
          }
        }
        goto LAB_0051cfe8;
      }
LAB_0051cff8:
      piVar8 = (int *)*local_1d8;
      local_19c = local_1d8;
      iVar9 = local_180;
      local_164 = piVar8;
      if (piVar8 != local_1d8) {
        do {
          local_17c[1] = (int *)piVar8[3];
          FUN_008438c0(local_17c + 1);
          if ((local_1a8 != *(int *)(iVar9 + 4)) &&
             (iVar23 = *(int *)(local_1a8 + 0x10), local_1b0 = iVar23, iVar23 != 0)) {
            local_17c[2] = (int *)FUN_00891268(0x18);
            if ((uint *)local_17c[2] == (uint *)0x0) {
              local_17c[2] = (int *)0x0;
            }
            else {
              local_17c[2][1] = 1;
              *local_17c[2] = (int)ITEM::CPackageProvideProducts::vftable;
              local_17c[2][2] = 0;
              local_17c[2][3] = 0;
              local_17c[2][4] = 0;
            }
            local_1ac = (int *)(piVar8[5] - piVar8[4] >> 3);
            local_17c[0] = (int *)0x0;
            if (local_1ac != (int *)0x0) {
              do {
                piVar4 = local_17c[2];
                uVar1 = *(ushort *)(piVar8[4] + 4 + (int)local_17c[0] * 8);
                local_168 = (uint)uVar1;
                local_17c[3] = (int *)(piVar8[4] + (int)local_17c[0] * 8);
                piVar8 = (int *)(*(int **)(local_180 + 4))[1];
                cVar5 = *(char *)((int)piVar8 + 0x15);
                local_17c[1] = *(int **)(local_180 + 4);
                while (cVar5 == '\0') {
                  if (piVar8[3] < *local_17c[3]) {
                    piVar14 = (int *)piVar8[2];
                    piVar8 = local_17c[1];
                  }
                  else {
                    piVar14 = (int *)*piVar8;
                  }
                  local_17c[1] = piVar8;
                  piVar8 = piVar14;
                  cVar5 = *(char *)((int)piVar14 + 0x15);
                }
                piVar8 = *(int **)(local_180 + 4);
                if ((local_17c[1] == piVar8) || (*local_17c[3] < local_17c[1][3])) {
                  local_1a4 = piVar8;
                  ppiVar16 = &local_1a4;
                }
                else {
                  ppiVar16 = local_17c + 1;
                }
                if ((*ppiVar16 != piVar8) && (iVar9 = (*ppiVar16)[4], iVar9 != 0)) {
                  bVar19 = *(byte *)(*(int *)(iVar9 + 0x54) + 0xc);
                  local_17c[1] = (int *)(uint)bVar19;
                  local_169 = bVar19;
                  if ((int)local_17c[1] < (int)(short)uVar1) {
                    do {
                      piVar8 = (int *)piVar4[3];
                      iVar9 = *local_17c[3];
                      local_188 = iVar9;
                      local_184 = CONCAT11(local_184._1_1_,bVar19);
                      if ((&local_188 < piVar8) &&
                         (piVar14 = (int *)piVar4[2], piVar14 <= &local_188)) {
                        if (piVar8 == (int *)piVar4[4]) {
                          uVar20 = (int)piVar8 - (int)piVar14 >> 3;
                          if (0x1ffffffe < uVar20) goto LAB_0051d085;
                          uVar20 = uVar20 + 1;
                          uVar15 = piVar4[4] - (int)piVar14 >> 3;
                          if (uVar15 < uVar20) {
                            if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                              uVar15 = 0;
                            }
                            else {
                              uVar15 = uVar15 + (uVar15 >> 1);
                            }
                            if (uVar15 < uVar20) {
                              uVar15 = uVar20;
                            }
                            FUN_0051df20(uVar15);
                            bVar19 = local_169;
                          }
                        }
                        puVar3 = (undefined4 *)piVar4[3];
                        puVar12 = (undefined4 *)
                                  (piVar4[2] + ((int)&local_188 - (int)piVar14 >> 3) * 8);
                        if (puVar3 != (undefined4 *)0x0) {
                          *puVar3 = *puVar12;
                          *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(puVar12 + 1);
                        }
                      }
                      else {
                        if (piVar8 == (int *)piVar4[4]) {
                          uVar20 = (int)piVar8 - piVar4[2] >> 3;
                          if (0x1ffffffe < uVar20) goto LAB_0051d085;
                          uVar20 = uVar20 + 1;
                          uVar15 = piVar4[4] - piVar4[2] >> 3;
                          if (uVar15 < uVar20) {
                            if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                              uVar15 = 0;
                            }
                            else {
                              uVar15 = uVar15 + (uVar15 >> 1);
                            }
                            if (uVar15 < uVar20) {
                              uVar15 = uVar20;
                            }
                            FUN_0051df20(uVar15);
                            bVar19 = local_169;
                          }
                        }
                        piVar8 = (int *)piVar4[3];
                        if (piVar8 != (int *)0x0) {
                          *piVar8 = iVar9;
                          *(byte *)(piVar8 + 1) = bVar19;
                        }
                      }
                      piVar4[3] = piVar4[3] + 8;
                      sVar6 = (short)local_168 - (ushort)bVar19;
                      local_168 = CONCAT22(local_168._2_2_,sVar6);
                    } while ((int)local_17c[1] < (int)sVar6);
                  }
                  piVar8 = local_17c[2];
                  if (0 < (short)local_168) {
                    iVar9 = *local_17c[3];
                    piVar4 = (int *)local_17c[2][3];
                    uVar18 = (undefined1)local_168;
                    local_1bc[0] = (undefined1)local_168;
                    local_1c0 = iVar9;
                    if (&local_1c0 < piVar4) {
                      piVar14 = (int *)local_17c[2][2];
                      if (&local_1c0 < piVar14) goto LAB_0051d2f7;
                      if (piVar4 == (int *)local_17c[2][4]) {
                        FUN_0051dff0();
                      }
                      puVar12 = (undefined4 *)
                                (piVar8[2] + ((int)&local_1c0 - (int)piVar14 >> 3) * 8);
                      puVar3 = (undefined4 *)piVar8[3];
                      if (puVar3 != (undefined4 *)0x0) {
                        *puVar3 = *puVar12;
                        *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(puVar12 + 1);
                      }
                    }
                    else {
LAB_0051d2f7:
                      if (piVar4 == (int *)local_17c[2][4]) {
                        FUN_0051dff0();
                      }
                      piVar4 = (int *)piVar8[3];
                      if (piVar4 != (int *)0x0) {
                        *piVar4 = iVar9;
                        *(undefined1 *)(piVar4 + 1) = uVar18;
                      }
                    }
                    piVar8[3] = piVar8[3] + 8;
                  }
                }
                local_17c[0] = (int *)((int)local_17c[0] + 1);
                piVar8 = local_164;
                iVar23 = local_1b0;
              } while (local_17c[0] < local_1ac);
            }
            *(int **)(iVar23 + 0x58 + local_17c[2][1] * 4) = local_17c[2];
            iVar9 = local_180;
          }
          if (*(char *)((int)piVar8 + 0x21) == '\0') {
            piVar4 = (int *)piVar8[2];
            if (*(char *)((int)piVar4 + 0x21) == '\0') {
              cVar5 = *(char *)(*piVar4 + 0x21);
              piVar8 = piVar4;
              piVar4 = (int *)*piVar4;
              while (local_164 = piVar8, cVar5 == '\0') {
                cVar5 = *(char *)(*piVar4 + 0x21);
                piVar8 = piVar4;
                piVar4 = (int *)*piVar4;
              }
            }
            else {
              cVar5 = *(char *)(piVar8[1] + 0x21);
              piVar14 = (int *)piVar8[1];
              piVar4 = piVar8;
              while ((piVar8 = piVar14, local_164 = piVar8, cVar5 == '\0' &&
                     (piVar4 == (int *)piVar8[2]))) {
                cVar5 = *(char *)(piVar8[1] + 0x21);
                piVar14 = (int *)piVar8[1];
                piVar4 = piVar8;
              }
            }
          }
        } while (piVar8 != local_19c);
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_0085e680(*local_1d8,local_1d8);
      FUN_0089120c(local_1d8);
      local_8 = 0xffffffff;
      if (0xf < local_58) {
        FUN_0089120c(local_6c);
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = local_6c & 0xffffff00;
      FUN_0071bc90(&local_138);
      goto LAB_0051c3ff;
    }
    FUN_006edb60("This Is Not a Product File.");
    local_8 = 0xffffffff;
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  local_5c = 0;
  local_58 = 0xf;
  local_6c = local_6c & 0xffffff00;
  FUN_0071bc90(&local_138);
LAB_0051c3ff:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_0051ce04:
  do {
    if (puVar13 != (uint *)0x0) {
      if ((*puVar13 & 7) == 1) goto LAB_0051ce4a;
      for (puVar13 = (uint *)puVar13[6]; puVar13 != (uint *)0x0; puVar13 = (uint *)puVar13[6]) {
        if (((char *)puVar13[2] != (char *)0x0) &&
           (iVar9 = __stricmp("PROPERTIES",(char *)puVar13[2]), iVar9 == 0)) goto LAB_0051ce42;
      }
    }
    puVar13 = (uint *)0x0;
LAB_0051ce42:
  } while (puVar13 != (uint *)0x0);
LAB_0051ce48:
  puVar13 = (uint *)0x0;
LAB_0051ce4a:
  local_17c[2] = (int *)puVar13;
  if (puVar13 == (uint *)0x0) goto LAB_0051ce5a;
  goto LAB_0051cd10;
LAB_0051cfa6:
  do {
    if (puVar13 != (uint *)0x0) {
      if ((*puVar13 & 7) == 1) goto LAB_0051cfea;
      for (puVar13 = (uint *)puVar13[6]; puVar13 != (uint *)0x0; puVar13 = (uint *)puVar13[6]) {
        if (((char *)puVar13[2] != (char *)0x0) &&
           (iVar9 = __stricmp("PRODUCT",(char *)puVar13[2]), iVar9 == 0)) goto LAB_0051cfe2;
      }
    }
    puVar13 = (uint *)0x0;
LAB_0051cfe2:
  } while (puVar13 != (uint *)0x0);
LAB_0051cfe8:
  puVar13 = (uint *)0x0;
LAB_0051cfea:
  local_160 = puVar13;
  if (puVar13 == (uint *)0x0) goto LAB_0051cff8;
  goto LAB_0051c4f3;
}

