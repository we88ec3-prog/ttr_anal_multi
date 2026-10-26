
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fbbb0(void)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined1 uVar9;
  int iVar10;
  undefined1 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined1 auStack_10a4 [2];
  undefined1 local_10a2 [2];
  uint local_10a0;
  int local_109c;
  int *local_1098;
  int *local_1094;
  undefined1 local_108e [2];
  int *local_108c;
  undefined1 *local_1088;
  undefined1 *local_1084;
  undefined1 *local_1080;
  int local_1078;
  int *local_1074;
  int *local_1070;
  int *local_106c;
  int local_1064;
  int local_1060 [6];
  undefined1 local_1048;
  int local_103c;
  char *local_1038;
  undefined **local_1034 [3];
  undefined4 local_1028;
  int local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ec67;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_10a4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffef50;
  ExceptionList = &local_14;
  local_103c = in_ECX;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  DVar3 = timeGetTime();
  if (DVar3 - _DAT_00fb1310 < 0x1f5) goto LAB_005fc325;
  puVar11 = (undefined1 *)0x0;
  local_1088 = (undefined1 *)0x0;
  local_1084 = (undefined1 *)0x0;
  local_1080 = (undefined1 *)0x0;
  local_1074 = (int *)0x0;
  local_1070 = (int *)0x0;
  local_106c = (int *)0x0;
  local_c = 1;
  _DAT_00fb1310 = DVar3;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  if (*(int *)(in_ECX + 0x118) == 0) {
    local_1098 = (int *)(DAT_00f94300 + 0x16f8);
    if (local_1098 == (int *)0x0) goto LAB_005fbccd;
    local_10a0 = *(uint *)(DAT_00f94300 + 0x2398);
  }
  else {
    local_1098 = (int *)0x0;
LAB_005fbccd:
    local_10a0 = 0;
  }
  local_1060[0] = 0;
  local_1060[1] = 0;
  local_1060[2] = 0;
  local_1060[3] = 0;
  local_1060[4] = 0;
  local_1060[5] = 0;
  local_1048 = 0;
  FUN_005feb50();
  if (local_1070 != (int *)0x0) {
    piVar7 = local_1060;
    piVar12 = local_1070;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar12 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar12 = piVar12 + 1;
    }
  }
  local_10a0 = local_10a0 + 1;
  piVar7 = local_1070 + 8;
  local_109c = 1;
  if (1 < (int)local_10a0) {
    local_1098 = (int *)((int)local_1098 + 0x28);
    do {
      local_1070 = piVar7;
      if (local_109c - 1U < 100) {
        if ((local_1098[1] == 0) || (*local_1098 == 0)) goto LAB_005fbd6b;
        piVar12 = local_1098 + -2;
      }
      else {
        FUN_006edb60(&DAT_00c0ddc0);
LAB_005fbd6b:
        piVar12 = (int *)0x0;
      }
      if (piVar12 == (int *)0x0) {
        local_1060[0] = 0;
        local_1060[1] = 0;
        local_1060[2] = 0;
        local_1060[3] = 0;
        local_1060[4] = 0;
        local_1060[5] = 0;
        local_1048 = 0;
        piVar12 = local_1060;
      }
      if ((piVar12 < piVar7) && (local_1074 <= piVar12)) {
        uVar2 = (int)piVar12 - (int)local_1074;
        if (piVar7 == local_106c) {
          FUN_005feb50();
          piVar7 = local_1070;
        }
        piVar12 = (int *)((uVar2 & 0xffffffe0) + (int)local_1074);
      }
      else if (piVar7 == local_106c) {
        FUN_005feb50();
        piVar7 = local_1070;
      }
      piVar13 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar7 = local_1070;
        for (iVar6 = 8; piVar13 = local_1070, iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar7 = *piVar12;
          piVar12 = piVar12 + 1;
          piVar7 = piVar7 + 1;
        }
      }
      local_1098 = local_1098 + 8;
      local_109c = local_109c + 1;
      piVar7 = piVar13 + 8;
    } while (local_109c < (int)local_10a0);
  }
  local_1098 = (int *)((int)piVar7 - (int)local_1074 >> 5);
  local_1094 = (int *)0x1;
  local_1070 = piVar7;
  if (1 < (int)local_1098) {
    local_108c = local_1074 + 10;
    do {
      if (local_108c[1] != 0) {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_c._0_1_ = 3;
          DAT_00f8d9b4 = 0;
          iVar6 = FUN_00891268(0x18);
          if (iVar6 == 0) {
            local_1038 = (char *)0x0;
            std::exception::exception((exception *)local_1034,&local_1038);
            local_1034[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_1034,&DAT_00c857a8);
          }
          DAT_00f8d9b0 = iVar6;
          *(int *)iVar6 = iVar6;
          *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
          *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
          *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
          *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
          local_c._0_1_ = 4;
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_c = CONCAT31(local_c._1_3_,1);
        }
        local_10a0 = local_108c[-1];
        FUN_008438c0(&local_10a0);
        if ((local_1064 != DAT_00f8d9b0) &&
           (local_10a0 = *(uint *)(local_1064 + 0x10), local_10a0 != 0)) {
          iVar6 = *(int *)(local_10a0 + 0xc);
          iVar10 = *local_108c;
          if (iVar10 < iVar6) {
            iVar4 = (int)local_1094 + 1;
            local_1078 = 0;
            if (iVar4 < (int)local_1098) {
              piVar7 = local_108c + 6;
              do {
                if (piVar7[3] == local_108c[1]) goto LAB_005fbf4b;
                iVar4 = iVar4 + 1;
                piVar7 = piVar7 + 8;
              } while (iVar4 < (int)local_1098);
            }
            piVar7 = (int *)0x0;
            iVar4 = local_1078;
LAB_005fbf4b:
            local_1078 = iVar4;
            iVar4 = local_1078;
            local_109c = iVar10;
            if (iVar10 < iVar6) {
              do {
                if (piVar7 == (int *)0x0) break;
                iVar5 = piVar7[2] + local_109c;
                uVar9 = (undefined1)iVar4;
                iVar10 = iVar4;
                if (iVar6 < iVar5) {
                  local_1074[iVar4 * 8 + 2] =
                       local_1074[iVar4 * 8 + 2] + (local_109c - *(int *)(local_10a0 + 0xc));
                  *local_108c = *(int *)(local_10a0 + 0xc);
                  local_109c = *(int *)(local_10a0 + 0xc);
                  local_108e[1] = local_1094._0_1_;
                  local_108e[0] = uVar9;
                  if ((local_108e < puVar11) && (local_1088 <= local_108e)) {
                    iVar6 = (int)local_108e - (int)local_1088 >> 1;
                    if (puVar11 == local_1080) {
                      uVar2 = (int)puVar11 - (int)local_1088 >> 1;
                      if (0x7ffffffe < uVar2) goto LAB_005fc38b;
                      uVar2 = uVar2 + 1;
                      uVar8 = (int)local_1080 - (int)local_1088 >> 1;
                      if (uVar8 < uVar2) {
                        if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                          uVar8 = 0;
                        }
                        else {
                          uVar8 = uVar8 + (uVar8 >> 1);
                        }
                        if (uVar8 < uVar2) {
                          uVar8 = uVar2;
                        }
                        FUN_005235d0(uVar8);
                        iVar10 = local_1078;
                        puVar11 = local_1084;
                      }
                    }
                    if (puVar11 != (undefined1 *)0x0) {
                      *puVar11 = local_1088[iVar6 * 2];
                      uVar9 = local_1088[iVar6 * 2 + 1];
LAB_005fc1ad:
                      puVar11[1] = uVar9;
                    }
                  }
                  else {
                    if (puVar11 == local_1080) {
                      uVar2 = (int)puVar11 - (int)local_1088 >> 1;
                      if (0x7ffffffe < uVar2) goto LAB_005fc38b;
                      uVar2 = uVar2 + 1;
                      uVar8 = (int)local_1080 - (int)local_1088 >> 1;
                      if (uVar8 < uVar2) {
                        if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                          uVar8 = 0;
                        }
                        else {
                          uVar8 = uVar8 + (uVar8 >> 1);
                        }
                        if (uVar8 < uVar2) {
                          uVar8 = uVar2;
                        }
                        FUN_005235d0(uVar8);
                        iVar10 = local_1078;
                        puVar11 = local_1084;
                      }
                    }
                    if (puVar11 != (undefined1 *)0x0) {
                      *puVar11 = (char)iVar10;
                      puVar11[1] = local_1094._0_1_;
                    }
                  }
                }
                else {
                  *local_108c = iVar5;
                  local_1060[0] = 0;
                  local_1060[1] = 0;
                  local_1060[2] = 0;
                  local_1060[3] = 0;
                  local_1060[4] = 0;
                  local_1060[5] = 0;
                  local_1048 = 0;
                  piVar7 = local_1060;
                  piVar12 = local_1074 + iVar4 * 8;
                  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *piVar12 = *piVar7;
                    piVar7 = piVar7 + 1;
                    piVar12 = piVar12 + 1;
                  }
                  local_10a2[1] = local_1094._0_1_;
                  local_10a2[0] = uVar9;
                  local_109c = iVar5;
                  if ((local_10a2 < puVar11) && (local_1088 <= local_10a2)) {
                    iVar6 = (int)local_10a2 - (int)local_1088 >> 1;
                    if (puVar11 == local_1080) {
                      uVar2 = (int)puVar11 - (int)local_1088 >> 1;
                      if (0x7ffffffe < uVar2) goto LAB_005fc38b;
                      uVar2 = uVar2 + 1;
                      uVar8 = (int)local_1080 - (int)local_1088 >> 1;
                      if (uVar8 < uVar2) {
                        if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                          uVar8 = 0;
                        }
                        else {
                          uVar8 = uVar8 + (uVar8 >> 1);
                        }
                        if (uVar8 < uVar2) {
                          uVar8 = uVar2;
                        }
                        FUN_005235d0(uVar8);
                        iVar10 = local_1078;
                        puVar11 = local_1084;
                      }
                    }
                    if (puVar11 != (undefined1 *)0x0) {
                      *puVar11 = local_1088[iVar6 * 2];
                      puVar11[1] = local_1088[iVar6 * 2 + 1];
                    }
                  }
                  else {
                    if (puVar11 == local_1080) {
                      uVar2 = (int)puVar11 - (int)local_1088 >> 1;
                      if (0x7ffffffe < uVar2) goto LAB_005fc38b;
                      uVar2 = uVar2 + 1;
                      uVar8 = (int)local_1080 - (int)local_1088 >> 1;
                      if (uVar8 < uVar2) {
                        if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                          uVar8 = 0;
                        }
                        else {
                          uVar8 = uVar8 + (uVar8 >> 1);
                        }
                        if (uVar8 < uVar2) {
                          uVar8 = uVar2;
                        }
                        FUN_005235d0(uVar8);
                        iVar10 = local_1078;
                        puVar11 = local_1084;
                      }
                    }
                    if (puVar11 != (undefined1 *)0x0) {
                      *puVar11 = (char)iVar10;
                      uVar9 = local_1094._0_1_;
                      goto LAB_005fc1ad;
                    }
                  }
                }
                puVar11 = puVar11 + 2;
                iVar4 = iVar10 + 1;
                if (iVar4 < (int)local_1098) {
                  piVar7 = local_1074 + iVar4 * 8;
                  do {
                    iVar6 = iVar4;
                    if (piVar7[3] == local_108c[1]) goto LAB_005fc1e5;
                    iVar4 = iVar4 + 1;
                    piVar7 = piVar7 + 8;
                  } while (iVar4 < (int)local_1098);
                }
                piVar7 = (int *)0x0;
                iVar4 = iVar10;
                iVar6 = local_1078;
LAB_005fc1e5:
                local_1078 = iVar6;
                iVar6 = *(int *)(local_10a0 + 0xc);
                local_1084 = puVar11;
              } while (local_109c < iVar6);
            }
          }
        }
      }
      local_108c = local_108c + 8;
      local_1094 = (int *)((int)local_1094 + 1);
    } while ((int)local_1094 < (int)local_1098);
  }
  local_109c = 1;
  if (1 < (int)local_1098) {
    local_1094 = local_1074 + 8;
    do {
      if (local_1094[3] == 0) {
        if ((int)local_1098 <= local_109c + 1) break;
        piVar7 = local_1074 + (int)local_1098 * 8 + 3;
        local_1064 = (int)local_1098;
        while( true ) {
          local_1064 = local_1064 + -1;
          piVar7 = piVar7 + -8;
          if (*piVar7 != 0) break;
          if (local_1064 <= local_109c + 1) goto LAB_005fc268;
        }
        piVar7 = local_1074 + local_1064 * 8;
        piVar12 = local_1094;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar12 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar12 = piVar12 + 1;
        }
        local_1060[0] = 0;
        local_1060[1] = 0;
        local_1060[2] = 0;
        local_1060[3] = 0;
        local_1060[4] = 0;
        local_1060[5] = 0;
        local_1048 = 0;
        piVar7 = local_1060;
        piVar12 = local_1074 + local_1064 * 8;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar12 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar12 = piVar12 + 1;
        }
        local_10a2[1] = (undefined1)local_109c;
        local_10a2[0] = (undefined1)local_1064;
        if ((local_10a2 < puVar11) && (local_1088 <= local_10a2)) {
          iVar6 = (int)local_10a2 - (int)local_1088 >> 1;
          if (puVar11 == local_1080) {
            uVar2 = (int)puVar11 - (int)local_1088 >> 1;
            if (0x7ffffffe < uVar2) goto LAB_005fc38b;
            uVar2 = uVar2 + 1;
            uVar8 = (int)local_1080 - (int)local_1088 >> 1;
            if (uVar8 < uVar2) {
              if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                uVar8 = 0;
              }
              else {
                uVar8 = uVar8 + (uVar8 >> 1);
              }
              if (uVar8 < uVar2) {
                uVar8 = uVar2;
              }
              FUN_005235d0(uVar8);
              puVar11 = local_1084;
            }
          }
          if (puVar11 != (undefined1 *)0x0) {
            *puVar11 = local_1088[iVar6 * 2];
            puVar11[1] = local_1088[iVar6 * 2 + 1];
          }
        }
        else {
          if (puVar11 == local_1080) {
            uVar2 = (int)puVar11 - (int)local_1088 >> 1;
            if (0x7ffffffe < uVar2) {
LAB_005fc38b:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar2 = uVar2 + 1;
            uVar8 = (int)local_1080 - (int)local_1088 >> 1;
            if (uVar8 < uVar2) {
              if (0x7fffffff - (uVar8 >> 1) < uVar8) {
                uVar8 = 0;
              }
              else {
                uVar8 = uVar8 + (uVar8 >> 1);
              }
              if (uVar8 < uVar2) {
                uVar8 = uVar2;
              }
              FUN_005235d0(uVar8);
              puVar11 = local_1084;
            }
          }
          if (puVar11 != (undefined1 *)0x0) {
            *puVar11 = (char)local_1064;
            puVar11[1] = (undefined1)local_109c;
          }
        }
        puVar11 = puVar11 + 2;
        local_1084 = puVar11;
      }
      local_1094 = local_1094 + 8;
      local_109c = local_109c + 1;
    } while (local_109c < (int)local_1098);
  }
LAB_005fc268:
  puVar1 = local_1088;
  if (local_1088 != puVar11) {
    local_10a0 = 0xdc;
    iVar6 = 4;
    uVar2 = 0;
    uVar8 = (int)puVar11 - (int)local_1088 >> 1;
    local_28 = 4;
    local_1028 = CONCAT13(*(char *)(local_103c + 0x118) + '\x01',0xdc);
    if (uVar8 != 0) {
      do {
        local_10a0 = (uint)CONCAT12(local_1088[uVar2 * 2 + 1],(ushort)(byte)local_1088[uVar2 * 2]);
        if (iVar6 + 4U < 0x1001) {
          *(uint *)((int)&local_1028 + iVar6) = local_10a0;
          iVar6 = local_28 + 4;
          local_28 = iVar6;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar8);
    }
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1028,iVar6);
  }
  if (local_1074 != (int *)0x0) {
    FUN_0089120c(local_1074);
  }
  if (puVar1 != (undefined1 *)0x0) {
    FUN_0089120c(puVar1);
  }
LAB_005fc325:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_10a4);
  return;
}

