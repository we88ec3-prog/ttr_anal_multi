
/* WARNING: Removing unreachable block (ram,0x007f6013) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007f5540(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined **ppuVar9;
  char *pcVar10;
  int *piVar11;
  LPCSTR ****lpCaption;
  undefined **ppuVar12;
  int in_ECX;
  char *pcVar13;
  char *unaff_EBX;
  uint uVar14;
  int *piVar15;
  undefined ***pppuVar16;
  char *pcStack_234;
  undefined1 auStack_224 [4];
  int *local_220;
  undefined4 *local_21c;
  int local_218;
  int local_214;
  int *local_210;
  undefined4 uStack_20c;
  int local_204;
  int iStack_200;
  int iStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1e4;
  int iStack_1e0;
  int iStack_1dc;
  undefined4 uStack_1d8;
  undefined1 auStack_1d4 [4];
  char *local_1d0;
  char *local_1cc;
  undefined4 local_1c8;
  undefined **appuStack_1c4 [2];
  undefined1 auStack_1bc [4];
  undefined **appuStack_1b8 [2];
  undefined1 auStack_1b0 [4];
  int *piStack_1ac;
  LPCSTR ***appppCStack_190 [2];
  uint local_188;
  undefined4 uStack_180;
  uint uStack_17c;
  undefined4 local_178;
  uint local_174;
  uint local_16c;
  undefined4 uStack_164;
  uint uStack_160;
  undefined4 local_15c;
  undefined **local_158 [9];
  int *local_134;
  int *piStack_130;
  undefined4 uStack_12c;
  undefined4 local_124;
  uint local_120;
  uint local_fc;
  undefined4 local_ec;
  uint local_e8;
  char local_e0 [64];
  char local_a0 [112];
  undefined1 uStack_30;
  undefined1 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_0093751b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_224;
  pcStack_234 = (char *)(DAT_00d61f20 ^ (uint)&stack0xfffffdd0);
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x20) != 0) goto LAB_007f5901;
  local_218 = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_210 = DAT_00fb76a8;
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_c = 2;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
  }
  local_c = 0xffffffff;
  pcVar13 = (char *)(DAT_00fba838 + 4);
  if (0xf < *(uint *)(DAT_00fba838 + 0x18)) {
    pcVar13 = *(char **)pcVar13;
  }
  local_e8 = 0xf;
  local_ec = 0;
  local_fc = local_fc & 0xffffff00;
  do {
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70();
  local_1d0 = (char *)0x0;
  local_1cc = (char *)0x0;
  local_1c8 = 0;
  local_c._0_1_ = 4;
  local_c._1_3_ = 0;
  local_120 = 0xf;
  local_124 = 0;
  local_134 = (int *)((uint)local_134 & 0xffffff00);
  FUN_00402a70();
  local_c._0_1_ = 5;
  if (*(uint *)(local_218 + 0x18) < 0x10) {
    pcVar13 = (char *)(local_218 + 4);
  }
  else {
    pcVar13 = *(char **)(local_218 + 4);
  }
  local_158[0] = (undefined **)0xf;
  local_15c = 0;
  local_16c = local_16c & 0xffffff00;
  do {
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70();
  local_c = CONCAT31(local_c._1_3_,6);
  FUN_007da6b0();
  if ((undefined **)0xf < local_158[0]) {
    FUN_0089120c();
  }
  local_c._0_1_ = 4;
  local_158[0] = (undefined **)0xf;
  local_15c = 0;
  local_16c = local_16c & 0xffffff00;
  if (0xf < local_120) {
    FUN_0089120c();
  }
  pcVar13 = local_1d0;
  pcVar2 = local_1d0;
  if (0xf < *(uint *)(local_1d0 + 0x14)) {
    pcVar2 = *(char **)local_1d0;
  }
  __splitpath(pcVar2,(char *)0x0,local_a0,local_e0,(char *)0x0);
  local_21c = (undefined4 *)(uint)(1 < (uint)(((int)local_1cc - (int)pcVar13) / 0x1c));
  pcVar13 = local_e0;
  local_174 = 0xf;
  local_178 = 0;
  local_188 = local_188 & 0xffffff00;
  do {
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70();
  local_c._0_1_ = 7;
  FUN_00401fc0();
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_c._0_1_ = 8;
    FUN_00716be0();
    _atexit((_func_4879 *)&LAB_00bcf1a0);
    local_c._0_1_ = 7;
  }
  iVar3 = FUN_00716740();
  if (iVar3 == 0) {
    if (0xf < local_174) {
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188 = local_188 & 0xffffff00;
    FUN_00440a80();
LAB_007f58df:
    FUN_0089120c();
  }
  else {
    FUN_0079c590();
    local_c._0_1_ = 9;
    FUN_00798d70();
    local_220 = (int *)FUN_007d0920();
    local_c._0_1_ = 7;
    if ((undefined **)0xf < local_158[0]) {
      FUN_0089120c();
    }
    local_204 = iVar3 + 0x1c;
    local_158[0] = (undefined **)0xf;
    local_15c = 0;
    local_16c = local_16c & 0xffffff00;
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_c._0_1_ = 10;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_c._0_1_ = 7;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0();
      local_c._0_1_ = 0xb;
      FUN_007edcd0();
      local_c._0_1_ = 7;
      FUN_007ee080();
    }
    if (local_220 != (int *)0x0) {
      if ((local_220[0x37] - local_220[0x36] & 0xfffffffcU) == 0) {
        *(int **)(local_218 + 0x30) = local_220;
        iVar3 = local_218;
      }
      else {
        local_214 = FUN_00891268();
        local_c._0_1_ = 0xc;
        if (local_214 == 0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_0077ebb0();
        }
        iVar3 = local_218;
        local_c._0_1_ = 7;
        *(int **)(local_218 + 0x30) = piVar4;
        (**(code **)(*piVar4 + 0x40))();
      }
      FUN_007d45c0();
      local_c = CONCAT31(local_c._1_3_,0xd);
      FUN_007cbbd0("Particle View");
      local_220 = (int *)*piStack_130;
      if (piStack_130 != local_220) {
        do {
          piVar4 = local_220;
          iVar5 = (**(code **)(*(int *)local_220[3] + 4))();
          if (*(int *)(iVar5 + 4) == -0x5eed0000) {
            puVar7 = (undefined4 *)piVar4[3];
            if ((int *)puVar7[0x15] != (int *)0x0) {
              (**(code **)(*(int *)puVar7[0x15] + 0x5c))();
            }
            puVar7[0x15] = 0;
            puVar7[0x17] = 0;
            (**(code **)*puVar7)();
          }
          FUN_0079c460();
        } while (piStack_130 != local_220);
      }
      local_c._0_1_ = 0xe;
      FUN_004ca160();
      local_c._0_1_ = 7;
      FUN_0089120c();
      FUN_007d45c0();
      local_c._0_1_ = 0xf;
      FUN_007cbbd0(&DAT_00c50c50);
      FUN_007cc5a0(&DAT_00c50c54,3,*(undefined4 *)(iVar3 + 0x30),auStack_1b0);
      local_220 = (int *)*piStack_1ac;
      if (piStack_1ac != local_220) {
        do {
          piVar4 = local_220;
          iVar3 = (**(code **)(*(int *)local_220[3] + 4))();
          if (*(int *)(iVar3 + 4) == -0x5edc0000) {
            *(undefined4 *)(piVar4[3] + 0x70) = 1;
          }
          FUN_0079c460();
        } while (piStack_1ac != local_220);
      }
      if (local_21c != (undefined4 *)0x0) {
        puVar7 = *(undefined4 **)(local_218 + 0x30);
        local_134 = (int *)0x0;
        piStack_130 = (int *)0x0;
        uStack_12c = 0;
        local_c._0_1_ = 0x10;
        local_21c = puVar7;
        FUN_007c7dd0();
        uVar14 = 0;
        if ((int)piStack_130 - (int)local_134 >> 2 != 0) {
          do {
            iVar3 = FUN_00843ef0();
            *(undefined4 *)(iVar3 + 0x24) = 0;
            uVar14 = uVar14 + 1;
            puVar7 = local_21c;
          } while (uVar14 < (uint)((int)piStack_130 - (int)local_134 >> 2));
        }
        uVar6 = (**(code **)(**(int **)(local_218 + 0x30) + 0xc))();
        *(undefined4 *)(local_218 + 0x30) = uVar6;
        if (puVar7 != (undefined4 *)0x0) {
          (**(code **)*puVar7)();
        }
        piVar4 = local_134;
        if (local_134 != piStack_130) {
          FID_conflict__memcpy(local_134,piStack_130,0);
          piStack_130 = piVar4;
        }
        FUN_007c7dd0();
        local_220 = (int *)0x0;
        piVar4 = local_134;
        if ((int)piStack_130 - (int)local_134 >> 2 != 0) {
          do {
            iVar3 = piVar4[(int)local_220];
            iVar5 = 0;
            if (0 < *(int *)(iVar3 + 0x178)) {
              do {
                if ((DAT_00fb79e8 & 1) == 0) {
                  DAT_00fb79e8 = DAT_00fb79e8 | 1;
                  local_c._0_1_ = 0x11;
                  FUN_00798de0();
                  _atexit((_func_4879 *)&LAB_00bcd2e0);
                  local_c._0_1_ = 0x10;
                }
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
                if ((DAT_00fb79e8 & 1) == 0) {
                  DAT_00fb79e8 = DAT_00fb79e8 | 1;
                  local_c._0_1_ = 0x12;
                  FUN_00798de0();
                  _atexit((_func_4879 *)&LAB_00bcd2e0);
                  local_c._0_1_ = 0x10;
                }
                puVar7 = (undefined4 *)(**(code **)(*DAT_00fb76a8 + 0x54))();
                uVar6 = *puVar7;
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
                iVar8 = FUN_00843ef0();
                iVar5 = iVar5 + 1;
                *(undefined4 *)(iVar8 + 0xb8) = uVar6;
                piVar4 = local_134;
              } while (iVar5 < *(int *)(iVar3 + 0x178));
            }
            local_220 = (int *)((int)local_220 + 1);
          } while (local_220 < (int *)((int)piStack_130 - (int)piVar4 >> 2));
        }
        local_c._0_1_ = 0xf;
        if (piVar4 != (int *)0x0) {
          FUN_0089120c();
        }
      }
      piVar4 = local_210;
      pcVar13 = "gbdiffusemap";
      pppuVar16 = appuStack_1b8;
      (**(code **)(*local_210 + 0xa0))();
      (**(code **)(*piVar4 + 0xa0))(auStack_1bc);
      (**(code **)(*piVar4 + 0xa0))(&local_1d0,"1s_alphablend");
      (**(code **)(*piVar4 + 0xa0))(auStack_1d4,"2s_alphatest");
      iStack_200 = 0;
      iStack_1fc = 0;
      uStack_1f8 = 0;
      uStack_2c = 0x13;
      FUN_007c7dd0(*(undefined ***)((int)pcVar13 + 0x30),&iStack_200);
      uVar14 = 0;
      if (iStack_1fc - iStack_200 >> 2 != 0) {
        do {
          *(undefined4 *)(*(int *)(iStack_200 + uVar14 * 4) + 0x24) = 0;
          uVar14 = uVar14 + 1;
        } while (uVar14 < (uint)(iStack_1fc - iStack_200 >> 2));
      }
      ppuVar9 = (undefined **)(**(code **)(**(undefined ***)((int)pcVar13 + 0x30) + 0xc))();
      ppuVar12 = *(undefined ***)((int)pcVar13 + 0x30);
      *(undefined ***)((int)pcVar13 + 0x34) = ppuVar9;
      ppuVar9 = (undefined **)(**(code **)(*ppuVar12 + 0xc))();
      *(undefined ***)((int)pcVar13 + 0x30) = ppuVar9;
      (**(code **)*ppuVar12)(1);
      local_214 = 0;
      local_210 = (int *)0x0;
      uStack_20c = 0;
      uStack_30 = 0x14;
      FUN_007c7dd0(*(undefined ***)((int)pcVar13 + 0x34),&local_214);
      uVar14 = 0;
      if ((int)local_210 - local_214 >> 2 != 0) {
        do {
          iVar3 = *(int *)(local_214 + uVar14 * 4);
          if ((*(int *)(iVar3 + 0x164) == iStack_1e0) || (DAT_00fba84c != 0)) {
            uVar6 = uStack_1e4;
            if (*(int *)(iVar3 + 0x164) != iStack_1dc) {
              uVar6 = uStack_1d8;
            }
            *(undefined4 *)(iVar3 + 0x164) = uVar6;
            if ((float)*(undefined ***)((int)pcVar13 + 0x2c) <= 0.0) {
LAB_007f5fbb:
              ppuVar12 = (undefined **)0x0;
            }
            else if (1.0 <= (float)*(undefined ***)((int)pcVar13 + 0x2c)) {
              ppuVar12 = (undefined **)0x3f800000;
            }
            else {
              if ((float)*(undefined ***)((int)pcVar13 + 0x2c) <= 0.0) goto LAB_007f5fbb;
              ppuVar12 = *(undefined ***)((int)pcVar13 + 0x2c);
            }
            *(undefined ***)(iVar3 + 0x1cc) = ppuVar12;
          }
          uVar14 = uVar14 + 1;
        } while (uVar14 < (uint)((int)local_210 - local_214 >> 2));
      }
      FUN_007c5f40(*(undefined ***)((int)pcVar13 + 0x30),&stack0xfffffdd0);
      local_21c = (undefined4 *)0x0;
      *(undefined ***)((int)pcVar13 + 0x38) = (undefined **)0x0;
      piVar4 = (int *)FUN_00891268(0x2c);
      if (piVar4 == (int *)0x0) {
        std::exception::exception((exception *)local_158,(char **)&stack0xfffffdc8);
        local_158[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_158,&DAT_00c857a8);
      }
      *piVar4 = (int)piVar4;
      piVar4[1] = (int)piVar4;
      piVar4[2] = (int)piVar4;
      *(undefined1 *)(piVar4 + 10) = 1;
      *(undefined1 *)((int)piVar4 + 0x29) = 1;
      uStack_30 = 0x15;
      local_220 = piVar4;
      FUN_007c6ce0(pcStack_234,*(undefined ***)((int)pcVar13 + 0x30),auStack_224);
      piVar4 = (int *)*local_220;
      if (piVar4 != local_220) {
        do {
          if ((uint)piVar4[8] < 0x10) {
            piVar11 = piVar4 + 3;
          }
          else {
            piVar11 = (int *)piVar4[3];
          }
          piVar15 = piVar4;
          pcVar13 = (char *)pppuVar16;
          if ((DAT_00fe1df8 & 1) == 0) {
            DAT_00fe1df8 = DAT_00fe1df8 | 1;
            uStack_30 = 0x16;
            DAT_00fe1e04 = 0;
            iVar3 = FUN_00891268(0x30);
            if (iVar3 == 0) {
              std::exception::exception((exception *)appuStack_1c4,(char **)&stack0xfffffdc0);
              appuStack_1c4[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(appuStack_1c4,&DAT_00c857a8);
            }
            DAT_00fe1e00 = iVar3;
            *(int *)iVar3 = iVar3;
            *(int *)(DAT_00fe1e00 + 4) = DAT_00fe1e00;
            *(int *)(DAT_00fe1e00 + 8) = DAT_00fe1e00;
            *(undefined1 *)(DAT_00fe1e00 + 0x2c) = 1;
            *(undefined1 *)(DAT_00fe1e00 + 0x2d) = 1;
            _atexit((_func_4879 *)&LAB_00bcf1a0);
            uStack_30 = 0x15;
            pcVar13 = (char *)pppuVar16;
          }
          iVar3 = FUN_00716740(piVar11);
          if (iVar3 == 0) {
            pcVar2 = unaff_EBX;
            if (0xf < *(uint *)(unaff_EBX + 0x14)) {
              pcVar2 = *(char **)unaff_EBX;
            }
            uStack_17c = 0xf;
            uStack_180 = 0;
            appppCStack_190[0] = (LPCSTR ***)((uint)appppCStack_190[0] & 0xffffff00);
            pcVar10 = pcVar2;
            do {
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar2,(int)pcVar10 - (int)(pcVar2 + 1));
            uStack_30 = 0x17;
            FUN_00401fc0(&DAT_00c50c78,3);
            if ((uint)piVar4[8] < 0x10) {
              piVar4 = piVar4 + 3;
            }
            else {
              piVar4 = (int *)piVar4[3];
            }
            piVar11 = piVar4;
            do {
              iVar3 = *piVar11;
              piVar11 = (int *)((int)piVar11 + 1);
            } while ((char)iVar3 != '\0');
            FUN_00401fc0(piVar4,(int)piVar11 - (int)((int)piVar4 + 1));
            lpCaption = (LPCSTR ****)appppCStack_190[0];
            if (uStack_17c < 0x10) {
              lpCaption = appppCStack_190;
            }
            MessageBoxA((HWND)0x0,&DAT_00c50c7c,(LPCSTR)lpCaption,0);
            uStack_30 = 0x15;
joined_r0x007f63de:
            if (0xf < uStack_17c) {
              FUN_0089120c(appppCStack_190[0]);
            }
          }
          else {
            puVar7 = (undefined4 *)FUN_0079c590();
            uStack_30 = 0x18;
            if (0xf < (uint)puVar7[5]) {
              puVar7 = (undefined4 *)*puVar7;
            }
            piVar4 = piVar15 + 3;
            if (0xf < (uint)piVar15[8]) {
              piVar4 = (int *)*piVar4;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
            (*DAT_00fe1ae4)(piVar4,puVar7);
            SetEvent(DAT_00fe1b2c);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
            uStack_30 = 0x15;
            if (0xf < uStack_17c) {
              FUN_0089120c(appppCStack_190[0]);
            }
            if (*(uint *)(iVar3 + 0x30) < 0x10) {
              iVar3 = iVar3 + 0x1c;
            }
            else {
              iVar3 = *(int *)(iVar3 + 0x1c);
            }
            if ((DAT_00fe3314 & 1) == 0) {
              DAT_00fe3314 = DAT_00fe3314 | 1;
              DAT_00fe3318 = 0;
              DAT_00fe331c = 0;
              DAT_00fe3320 = 0;
              _DAT_00fe3324 = 0;
              uStack_30 = 0x1a;
              _DAT_00fe3334 = 0;
              iVar5 = FUN_00891268(0x30);
              if (iVar5 == 0) {
                pcStack_234 = (char *)0x0;
                std::exception::exception((exception *)appuStack_1b8,&pcStack_234);
                appuStack_1b8[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(appuStack_1b8,&DAT_00c857a8);
              }
              DAT_00fe3330 = iVar5;
              *(int *)iVar5 = iVar5;
              *(int *)(DAT_00fe3330 + 4) = DAT_00fe3330;
              *(int *)(DAT_00fe3330 + 8) = DAT_00fe3330;
              *(undefined1 *)(DAT_00fe3330 + 0x2c) = 1;
              *(undefined1 *)(DAT_00fe3330 + 0x2d) = 1;
              _atexit((_func_4879 *)&LAB_00bd0ae0);
              uStack_30 = 0x15;
            }
            if (DAT_00fe3318 != 0) {
              FUN_007ed8d0(appppCStack_190,iVar3);
              uStack_30 = 0x1b;
              FUN_007edcd0();
              uStack_30 = 0x15;
              if (0xf < uStack_160) {
                FUN_0089120c(local_174);
              }
              uStack_160 = 0xf;
              uStack_164 = 0;
              local_174 = local_174 & 0xffffff00;
              goto joined_r0x007f63de;
            }
          }
          if (*(char *)((int)piVar15 + 0x29) == '\0') {
            piVar4 = (int *)piVar15[2];
            if (*(char *)((int)piVar4 + 0x29) == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x29);
              piVar15 = piVar4;
              piVar4 = (int *)*piVar4;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar4 + 0x29);
                piVar15 = piVar4;
                piVar4 = (int *)*piVar4;
              }
            }
            else {
              cVar1 = *(char *)(piVar15[1] + 0x29);
              piVar11 = (int *)piVar15[1];
              piVar4 = piVar15;
              while ((piVar15 = piVar11, cVar1 == '\0' && (piVar4 == (int *)piVar15[2]))) {
                cVar1 = *(char *)(piVar15[1] + 0x29);
                piVar11 = (int *)piVar15[1];
                piVar4 = piVar15;
              }
            }
          }
          piVar4 = piVar15;
          pppuVar16 = (undefined ***)pcVar13;
        } while (piVar15 != local_220);
      }
      ppuVar12 = (undefined **)FUN_00891268(0x2c);
      uStack_30 = 0x1c;
      if (ppuVar12 == (undefined **)0x0) {
        ppuVar12 = (undefined **)0x0;
      }
      else {
        ppuVar12[5] = (undefined *)0xf;
        ppuVar12[4] = (undefined *)0x0;
        *(undefined1 *)ppuVar12 = 0;
        FUN_00403040((undefined ***)((int)pcVar13 + 4),0,0xffffffff);
        ppuVar12[7] = (undefined *)0x0;
        ppuVar12[8] = (undefined *)0x0;
        ppuVar12[9] = (undefined *)0x0;
      }
      uStack_30 = 0x15;
      *(undefined ***)((int)pcVar13 + 0x3c) = ppuVar12;
      FUN_007fd8c0(ppuVar12,*(undefined ***)((int)pcVar13 + 0x30));
      *(undefined ***)((int)pcVar13 + 0x20) = (undefined **)0x1;
      uStack_30 = 0x1d;
      FUN_004ad180(*local_220,local_220);
      FUN_0089120c(local_220);
      if (local_214 != 0) {
        FUN_0089120c(local_214);
      }
      local_214 = 0;
      local_210 = (int *)0x0;
      uStack_20c = 0;
      if (local_204 != 0) {
        FUN_0089120c(local_204);
      }
      local_204 = 0;
      iStack_200 = 0;
      iStack_1fc = 0;
      uStack_30 = 0x1e;
      FUN_004ca160(*(undefined4 *)local_1d0,local_1d0);
      FUN_0089120c(local_1d0);
      if (0xf < local_174) {
        FUN_0089120c();
      }
      pcVar2 = local_1cc;
      local_174 = 0xf;
      local_178 = 0;
      local_188 = local_188 & 0xffffff00;
      for (pcVar13 = local_1d0; pcVar13 != pcVar2; pcVar13 = pcVar13 + 0x1c) {
        if (0xf < *(uint *)(pcVar13 + 0x14)) {
          FUN_0089120c();
        }
        pcVar13[0x14] = '\x0f';
        pcVar13[0x15] = '\0';
        pcVar13[0x16] = '\0';
        pcVar13[0x17] = '\0';
        pcVar13[0x10] = '\0';
        pcVar13[0x11] = '\0';
        pcVar13[0x12] = '\0';
        pcVar13[0x13] = '\0';
        *pcVar13 = '\0';
      }
      goto LAB_007f58df;
    }
    if (0xf < local_174) {
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188 = local_188 & 0xffffff00;
    FUN_00573ea0();
  }
  if (0xf < local_e8) {
    FUN_0089120c();
  }
LAB_007f5901:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_224);
  return;
}

