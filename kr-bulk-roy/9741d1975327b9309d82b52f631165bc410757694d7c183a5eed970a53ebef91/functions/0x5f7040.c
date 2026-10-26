
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f7040(void)

{
  undefined4 *puVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  DWORD DVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int in_ECX;
  int *piVar10;
  short *psVar11;
  uint uVar12;
  short sVar13;
  undefined4 *puVar14;
  int local_109c;
  undefined4 local_1098;
  int local_1094;
  undefined4 local_1090;
  int *local_108c;
  short *local_1088;
  short *local_1084;
  short *local_1080;
  int local_1078;
  int local_1074;
  uint local_1070;
  int local_106c;
  short local_1068 [2];
  int local_1064;
  undefined4 *local_1060;
  int local_105c;
  undefined4 local_1058;
  undefined **local_1050;
  undefined4 local_104c;
  undefined4 local_1048;
  undefined4 local_1044;
  undefined4 local_1040;
  undefined4 local_103c;
  char *local_1034;
  int local_1030;
  int local_102c;
  int local_1028 [1024];
  int local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093eec7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_109c;
  ExceptionList = &local_14;
  psVar11 = (short *)0x0;
  if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) == 0) ||
     (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) == 0)) {
    iVar4 = -1;
  }
  else {
    iVar4 = FUN_005f55a0(DAT_00d61f20 ^ (uint)&stack0xffffef58);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  DVar5 = timeGetTime();
  if (500 < DVar5 - _DAT_00fb1310) {
    local_1070 = iVar4 * 0x50;
    iVar4 = local_1070 + 0x50;
    local_1088 = (short *)0x0;
    local_1084 = (short *)0x0;
    local_1080 = (short *)0x0;
    local_1060 = (undefined4 *)0x0;
    local_105c = 0;
    local_1058 = 0;
    local_c = 1;
    _DAT_00fb1310 = DVar5;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    local_1090 = DAT_00f94300 + 0x23a0;
    if (local_1090 != 0) {
      local_109c = iVar4;
      if (*(int *)(DAT_00f94300 + 0x50b8) <= iVar4) {
        local_109c = *(int *)(DAT_00f94300 + 0x50b8);
      }
      local_1050 = (undefined **)0x0;
      local_104c = 0;
      local_1048 = 0;
      local_1044 = 0;
      local_1040 = 0;
      local_103c = 0;
      FUN_005f84f0();
      iVar4 = local_1070 + 1;
      if (iVar4 < local_109c + 1) {
        local_1098 = local_1070;
        local_109c = (local_109c + 1) - iVar4;
        piVar10 = (int *)(local_1090 + 8 + iVar4 * 0x18);
        do {
          if (local_1098 < 0x1e0) {
            if ((piVar10[1] == 0) || (*piVar10 == 0)) goto LAB_005f71f3;
            piVar6 = piVar10 + -2;
          }
          else {
            FUN_006edb60(&DAT_00c0ddc0);
LAB_005f71f3:
            piVar6 = (int *)0x0;
          }
          if (piVar6 == (int *)0x0) {
            local_1050 = (undefined **)0x0;
            local_104c = 0;
            local_1048 = 0;
            local_1044 = 0;
            local_1040 = 0;
            local_103c = 0;
          }
          FUN_005f84f0();
          local_1098 = local_1098 + 1;
          piVar10 = piVar10 + 6;
          local_109c = local_109c + -1;
        } while (local_109c != 0);
        local_109c = 0;
      }
      local_1078 = (local_105c - (int)local_1060) / 0x18;
      local_1090 = 1;
      if (1 < local_1078) {
        local_1074 = local_1070 + 1;
        local_108c = local_1060 + 8;
        local_109c = 1 - local_1070;
        do {
          if (local_108c[1] != 0) {
            if ((DAT_00f8d9a8 & 1) == 0) {
              DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
              local_c._0_1_ = 3;
              DAT_00f8d9b4 = 0;
              iVar4 = FUN_00891268(0x18);
              if (iVar4 == 0) {
                local_1034 = (char *)0x0;
                std::exception::exception((exception *)&local_1050,&local_1034);
                local_1050 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(&local_1050,&DAT_00c857a8);
              }
              DAT_00f8d9b0 = iVar4;
              *(int *)iVar4 = iVar4;
              *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
              *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
              *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
              *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
              local_c._0_1_ = 4;
              FUN_00521080(&DAT_00f8d9bc);
              _atexit((_func_4879 *)&LAB_00bccc50);
              local_c = CONCAT31(local_c._1_3_,1);
            }
            local_106c = local_108c[-1];
            FUN_008438c0(&local_106c);
            if ((local_102c != DAT_00f8d9b0) &&
               (local_1064 = *(int *)(local_102c + 0x10), local_1064 != 0)) {
              iVar4 = *(int *)(local_1064 + 0xc);
              iVar8 = *local_108c;
              local_106c = iVar4;
              if (iVar8 < iVar4) {
                local_1030 = local_108c[1];
                iVar7 = local_1074 + local_109c;
                if (iVar7 < local_1078) {
                  piVar10 = local_108c + 4;
                  do {
                    if (piVar10[3] == local_1030) goto LAB_005f73ab;
                    iVar7 = iVar7 + 1;
                    piVar10 = piVar10 + 6;
                  } while (iVar7 < local_1078);
                }
                piVar10 = (int *)0x0;
                iVar7 = 0;
LAB_005f73ab:
                local_1094 = iVar8;
                if (iVar8 < iVar4) {
                  do {
                    if (piVar10 == (int *)0x0) break;
                    iVar8 = piVar10[2] + local_1094;
                    sVar13 = (short)iVar7;
                    sVar2 = (short)local_1070;
                    if (iVar4 < iVar8) {
                      local_1060[iVar7 * 6 + 2] =
                           local_1060[iVar7 * 6 + 2] + (local_1094 - *(int *)(local_1064 + 0xc));
                      *local_108c = *(int *)(local_1064 + 0xc);
                      local_1094 = *(int *)(local_1064 + 0xc);
                      local_1068[0] = sVar13 + sVar2;
                      local_1068[1] = (short)local_1074;
                      if ((local_1068 < psVar11) && (local_1088 <= local_1068)) {
                        iVar4 = (int)local_1068 - (int)local_1088 >> 2;
                        if (psVar11 == local_1080) {
                          FUN_005f8d20();
                          psVar11 = local_1084;
                        }
                        if (psVar11 != (short *)0x0) {
                          *psVar11 = local_1088[iVar4 * 2];
                          psVar11[1] = local_1088[iVar4 * 2 + 1];
                        }
                      }
                      else {
LAB_005f74ef:
                        if (psVar11 == local_1080) {
                          FUN_005f8d20();
                          psVar11 = local_1084;
                        }
                        if (psVar11 != (short *)0x0) {
                          *psVar11 = sVar13 + sVar2;
                          psVar11[1] = (short)local_1074;
                        }
                      }
                    }
                    else {
                      *local_108c = iVar8;
                      puVar14 = local_1060 + iVar7 * 6;
                      *puVar14 = 0;
                      puVar14[1] = 0;
                      puVar14[2] = 0;
                      puVar14[3] = 0;
                      puVar14[4] = 0;
                      puVar14[5] = 0;
                      local_1098 = CONCAT22((short)local_1074,sVar13 + sVar2);
                      local_1094 = iVar8;
                      if ((psVar11 <= &local_1098) || (&local_1098 < local_1088)) goto LAB_005f74ef;
                      iVar4 = (int)&local_1098 - (int)local_1088 >> 2;
                      if (psVar11 == local_1080) {
                        FUN_005f8d20();
                        psVar11 = local_1084;
                      }
                      if (psVar11 != (short *)0x0) {
                        *psVar11 = local_1088[iVar4 * 2];
                        psVar11[1] = local_1088[iVar4 * 2 + 1];
                      }
                    }
                    psVar11 = psVar11 + 2;
                    iVar8 = iVar7 + 1;
                    if (iVar8 < local_1078) {
                      piVar10 = local_1060 + iVar8 * 6;
                      do {
                        if (piVar10[3] == local_108c[1]) goto LAB_005f754a;
                        iVar8 = iVar8 + 1;
                        piVar10 = piVar10 + 6;
                      } while (iVar8 < local_1078);
                    }
                    piVar10 = (int *)0x0;
                    iVar8 = iVar7;
LAB_005f754a:
                    iVar4 = *(int *)(local_1064 + 0xc);
                    iVar7 = iVar8;
                    local_1084 = psVar11;
                  } while (local_1094 < iVar4);
                }
              }
            }
          }
          local_108c = local_108c + 6;
          local_1074 = local_1074 + 1;
          local_1090 = local_1090 + 1;
        } while (local_1090 < local_1078);
      }
      local_1090 = 1;
      puVar14 = local_1060;
      if (1 < local_1078) {
        local_1094 = local_1070 + 1;
        local_109c = 1 - local_1070;
        iVar4 = local_1078;
        puVar1 = local_1060;
        do {
          if (puVar1[9] == 0) {
            if (iVar4 <= local_1094 + local_109c) break;
            piVar10 = puVar14 + iVar4 * 6 + 3;
            while( true ) {
              piVar10 = piVar10 + -6;
              iVar4 = iVar4 + -1;
              if (*piVar10 != 0) break;
              if (iVar4 <= local_1094 + local_109c) goto LAB_005f75d1;
            }
            puVar14 = puVar14 + iVar4 * 6;
            puVar1[6] = *puVar14;
            puVar1[7] = puVar14[1];
            puVar1[8] = puVar14[2];
            puVar1[9] = puVar14[3];
            puVar1[10] = puVar14[4];
            puVar1[0xb] = puVar14[5];
            *puVar14 = 0;
            puVar14[1] = 0;
            puVar14[2] = 0;
            puVar14[3] = 0;
            puVar14[4] = 0;
            puVar14[5] = 0;
            sVar13 = (short)iVar4 + (short)local_1070;
            local_1098 = CONCAT22((short)local_1094,sVar13);
            if ((&local_1098 < psVar11) && (local_1088 <= &local_1098)) {
              iVar4 = (int)&local_1098 - (int)local_1088 >> 2;
              if (psVar11 == local_1080) {
                uVar9 = (int)psVar11 - (int)local_1088 >> 2;
                if (0x3ffffffe < uVar9) {
LAB_005f783c:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar9 = uVar9 + 1;
                uVar12 = (int)local_1080 - (int)local_1088 >> 2;
                if (uVar12 < uVar9) {
                  if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = uVar12 + (uVar12 >> 1);
                  }
                  if (uVar12 < uVar9) {
                    uVar12 = uVar9;
                  }
                  FUN_005f8e00(uVar12);
                  psVar11 = local_1084;
                }
              }
              if (psVar11 != (short *)0x0) {
                *psVar11 = local_1088[iVar4 * 2];
                psVar11[1] = local_1088[iVar4 * 2 + 1];
              }
            }
            else {
              if (psVar11 == local_1080) {
                uVar9 = (int)psVar11 - (int)local_1088 >> 2;
                if (0x3ffffffe < uVar9) goto LAB_005f783c;
                uVar9 = uVar9 + 1;
                uVar12 = (int)local_1080 - (int)local_1088 >> 2;
                if (uVar12 < uVar9) {
                  if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = uVar12 + (uVar12 >> 1);
                  }
                  if (uVar12 < uVar9) {
                    uVar12 = uVar9;
                  }
                  FUN_005f8e00(uVar12);
                  psVar11 = local_1084;
                }
              }
              if (psVar11 != (short *)0x0) {
                *psVar11 = sVar13;
                psVar11[1] = (short)local_1094;
              }
            }
            psVar11 = psVar11 + 2;
            iVar4 = local_1078;
            puVar14 = local_1060;
            local_1084 = psVar11;
          }
          local_1094 = local_1094 + 1;
          local_1090 = local_1090 + 1;
          puVar1 = puVar1 + 6;
        } while (local_1090 < iVar4);
      }
LAB_005f75d1:
      psVar3 = local_1088;
      if (local_1088 != psVar11) {
        local_109c = 0x100dc;
        iVar4 = 4;
        uVar12 = (int)psVar11 - (int)local_1088 >> 2;
        uVar9 = 0;
        local_28 = 4;
        local_1028[0] = 0x100dc;
        if (uVar12 != 0) {
          do {
            local_1090 = CONCAT22(local_1088[uVar9 * 2 + 1],local_1088[uVar9 * 2]);
            if (iVar4 + 4U < 0x1001) {
              *(int *)((int)local_1028 + iVar4) = local_1090;
              iVar4 = local_28 + 4;
              local_28 = iVar4;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar12);
        }
        (**(code **)(*DAT_00fba854 + 0x10))(0,local_1028,iVar4);
      }
      if (puVar14 != (undefined4 *)0x0) {
        FUN_0089120c(puVar14);
      }
      if (psVar3 != (short *)0x0) {
        FUN_0089120c(psVar3);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_109c);
  return;
}

