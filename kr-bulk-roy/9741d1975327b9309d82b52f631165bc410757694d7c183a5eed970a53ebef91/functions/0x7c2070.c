
void FUN_007c2070(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_94 [4];
  int *local_90;
  int *local_8c;
  undefined1 local_85;
  undefined1 auStack_84 [4];
  int *piStack_80;
  undefined4 local_7c;
  char *pcStack_74;
  undefined4 local_70;
  char *pcStack_6c;
  int *local_68;
  char *pcStack_64;
  undefined **appuStack_60 [3];
  undefined **appuStack_54 [4];
  undefined **appuStack_44 [3];
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00937e2c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  ExceptionList = &local_14;
  piVar3 = *(int **)(in_ECX + 4);
  local_68 = piVar3;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff60);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  local_c = 0xffffffff;
  piVar6 = (int *)**(int **)(in_ECX + 4);
  local_70 = DAT_00fb76a8;
  local_8c = piVar6;
  if (piVar6 != piVar3) {
    do {
      iVar4 = piVar6[10];
      if ((DAT_00fe321c & 1) == 0) {
        DAT_00fe321c = DAT_00fe321c | 1;
        local_c = 2;
        FUN_007d0fb0(&local_85);
        _atexit((_func_4879 *)&LAB_00bd09c0);
        local_c = 0xffffffff;
      }
      iVar2 = FUN_007d0920(0);
      *(int *)(iVar4 + 0x1c) = iVar2;
      if (iVar2 != 0) {
        if ((*(int *)(iVar2 + 0xdc) - *(int *)(iVar2 + 0xd8) & 0xfffffffcU) != 0) {
          local_90 = (int *)FUN_00891268(0xe8);
          local_c = 3;
          if (local_90 == (int *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = (int *)FUN_0077ebb0();
          }
          local_c = 0xffffffff;
          (**(code **)(*piVar3 + 0x40))(*(undefined4 *)(iVar4 + 0x1c));
          *(int **)(iVar4 + 0x1c) = piVar3;
        }
        local_7c = 0;
        piVar3 = (int *)FUN_00891268(0x2c);
        if (piVar3 == (int *)0x0) {
          pcStack_6c = (char *)0x0;
          std::exception::exception((exception *)appuStack_54,&pcStack_6c);
          appuStack_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(appuStack_54,&DAT_00c857a8);
        }
        *piVar3 = (int)piVar3;
        piVar3[1] = (int)piVar3;
        piVar3[2] = (int)piVar3;
        *(undefined1 *)(piVar3 + 10) = 1;
        *(undefined1 *)((int)piVar3 + 0x29) = 1;
        local_c._0_1_ = 4;
        local_c._1_3_ = 0;
        piStack_80 = piVar3;
        FUN_007c6ce0(local_70,*(undefined4 *)(iVar4 + 0x1c),auStack_84);
        piVar3 = (int *)*piStack_80;
        local_90 = piVar3;
        if (piVar3 != piStack_80) {
          do {
            piVar6 = piVar3 + 3;
            piVar7 = piVar6;
            if (0xf < (uint)piVar3[8]) {
              piVar7 = (int *)*piVar6;
            }
            if ((DAT_00fe1df8 & 1) == 0) {
              DAT_00fe1df8 = DAT_00fe1df8 | 1;
              local_c._0_1_ = 5;
              DAT_00fe1e04 = 0;
              iVar4 = FUN_00891268(0x30);
              if (iVar4 == 0) {
                pcStack_64 = (char *)0x0;
                std::exception::exception((exception *)appuStack_60,&pcStack_64);
                appuStack_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(appuStack_60,&DAT_00c857a8);
              }
              DAT_00fe1e00 = iVar4;
              *(int *)iVar4 = iVar4;
              *(int *)(DAT_00fe1e00 + 4) = DAT_00fe1e00;
              *(int *)(DAT_00fe1e00 + 8) = DAT_00fe1e00;
              *(undefined1 *)(DAT_00fe1e00 + 0x2c) = 1;
              *(undefined1 *)(DAT_00fe1e00 + 0x2d) = 1;
              _atexit((_func_4879 *)&LAB_00bcf1a0);
              local_c._0_1_ = 4;
            }
            iVar4 = FUN_00716740(piVar7);
            if (iVar4 == 0) {
              piVar7 = piVar6;
              if (0xf < (uint)piVar3[8]) {
                piVar7 = (int *)*piVar6;
              }
              if ((DAT_00fe1df8 & 1) == 0) {
                DAT_00fe1df8 = DAT_00fe1df8 | 1;
                local_c._0_1_ = 6;
                DAT_00fe1e04 = 0;
                iVar4 = FUN_00891268(0x30);
                if (iVar4 == 0) {
                  pcStack_74 = (char *)0x0;
                  std::exception::exception((exception *)appuStack_44,&pcStack_74);
                  appuStack_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  __CxxThrowException_8(appuStack_44,&DAT_00c857a8);
                }
                DAT_00fe1e00 = iVar4;
                *(int *)iVar4 = iVar4;
                *(int *)(DAT_00fe1e00 + 4) = DAT_00fe1e00;
                *(int *)(DAT_00fe1e00 + 8) = DAT_00fe1e00;
                *(undefined1 *)(DAT_00fe1e00 + 0x2c) = 1;
                *(undefined1 *)(DAT_00fe1e00 + 0x2d) = 1;
                _atexit((_func_4879 *)&LAB_00bcf1a0);
                local_c._0_1_ = 4;
              }
              iVar4 = FUN_00716740(piVar7);
              if (iVar4 != 0) goto LAB_007c23a2;
            }
            else {
LAB_007c23a2:
              puVar5 = (undefined4 *)FUN_0079c590();
              if (0xf < (uint)puVar5[5]) {
                puVar5 = (undefined4 *)*puVar5;
              }
              if (0xf < (uint)piVar3[8]) {
                piVar6 = (int *)*piVar6;
              }
              if ((DAT_00fe1ac0 & 1) == 0) {
                DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
                local_c._0_1_ = 8;
                FUN_007bb970();
                _atexit((_func_4879 *)&LAB_00bceac0);
              }
              local_c._0_1_ = 7;
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
              (*DAT_00fe1ae0)(piVar6,puVar5);
              SetEvent(DAT_00fe1b2c);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
              local_c._0_1_ = 4;
              piVar3 = local_90;
              if (0xf < uStack_24) {
                FUN_0089120c(uStack_38);
                piVar3 = local_90;
              }
            }
            if (*(char *)((int)piVar3 + 0x29) == '\0') {
              piVar6 = (int *)piVar3[2];
              if (*(char *)((int)piVar6 + 0x29) == '\0') {
                cVar1 = *(char *)(*piVar6 + 0x29);
                piVar3 = piVar6;
                piVar6 = (int *)*piVar6;
                while (local_90 = piVar3, cVar1 == '\0') {
                  cVar1 = *(char *)(*piVar6 + 0x29);
                  piVar3 = piVar6;
                  piVar6 = (int *)*piVar6;
                }
              }
              else {
                cVar1 = *(char *)(piVar3[1] + 0x29);
                piVar7 = (int *)piVar3[1];
                piVar6 = piVar3;
                while ((piVar3 = piVar7, local_90 = piVar3, cVar1 == '\0' &&
                       (piVar6 == (int *)piVar3[2]))) {
                  cVar1 = *(char *)(piVar3[1] + 0x29);
                  piVar7 = (int *)piVar3[1];
                  piVar6 = piVar3;
                }
              }
            }
            piVar6 = local_8c;
          } while (piVar3 != piStack_80);
        }
        local_c = 9;
        FUN_004ad180(*piStack_80,piStack_80);
        local_c = 0xffffffff;
        FUN_0089120c(piStack_80);
      }
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (local_8c = piVar6, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar7 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar7, local_8c = piVar6, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))
                ) {
            cVar1 = *(char *)(piVar6[1] + 0x2d);
            piVar7 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != local_68);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

