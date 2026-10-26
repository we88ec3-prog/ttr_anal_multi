
void FUN_007cc6f0(int *param_1,undefined4 param_2,uint *param_3)

{
  undefined4 *puVar1;
  int **ppiVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int local_2c;
  int *local_28;
  int *local_24 [2];
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  
  if (param_1 != (int *)0x0) {
    local_1c = param_1[0x37] - param_1[0x36] >> 2;
    local_18 = 0;
    if (local_1c != 0) {
      do {
        if (param_1[0x37] - param_1[0x36] >> 2 == 0) {
          local_c = (int *)0x0;
        }
        else {
          local_c = *(int **)param_1[0x36];
        }
        piVar13 = local_c;
        iVar6 = (**(code **)(*local_c + 4))();
        if (*(int *)(iVar6 + 4) == -0x5edf0000) {
          uVar11 = piVar13[0x23] - piVar13[0x22] >> 2;
          local_14 = 0;
          if (uVar11 != 0) {
            local_24[1] = param_1;
            local_10 = uVar11;
            do {
              piVar13 = *(int **)(piVar13[0x22] + local_14 * 4);
              ppiVar2 = (int **)param_3[1];
              local_24[0] = piVar13;
              if ((local_24 < ppiVar2) && (ppiVar3 = (int **)*param_3, ppiVar3 <= local_24)) {
                if (ppiVar2 == (int **)param_3[2]) {
                  uVar7 = (int)ppiVar2 - (int)ppiVar3 >> 3;
                  if (0x1ffffffe < uVar7) goto LAB_007cca3f;
                  uVar7 = uVar7 + 1;
                  uVar10 = (int)param_3[2] - (int)ppiVar3 >> 3;
                  if (uVar10 < uVar7) {
                    if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                      uVar10 = 0;
                    }
                    else {
                      uVar10 = uVar10 + (uVar10 >> 1);
                    }
                    if (uVar10 < uVar7) {
                      uVar10 = uVar7;
                    }
                    FUN_004e7330(uVar10);
                    uVar11 = local_10;
                  }
                }
                puVar4 = (undefined4 *)param_3[1];
                puVar1 = (undefined4 *)(*param_3 + ((int)local_24 - (int)ppiVar3 >> 3) * 8);
                if (puVar4 != (undefined4 *)0x0) {
                  *puVar4 = *puVar1;
                  puVar4[1] = puVar1[1];
                }
              }
              else {
                if (ppiVar2 == (int **)param_3[2]) {
                  uVar7 = (int)((int)ppiVar2 - *param_3) >> 3;
                  if (0x1ffffffe < uVar7) goto LAB_007cca3f;
                  uVar7 = uVar7 + 1;
                  uVar10 = (int)((int)param_3[2] - *param_3) >> 3;
                  if (uVar10 < uVar7) {
                    if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                      uVar10 = 0;
                    }
                    else {
                      uVar10 = uVar10 + (uVar10 >> 1);
                    }
                    if (uVar10 < uVar7) {
                      uVar10 = uVar7;
                    }
                    FUN_004e7330(uVar10);
                    uVar11 = local_10;
                  }
                }
                puVar1 = (undefined4 *)param_3[1];
                if (puVar1 != (undefined4 *)0x0) {
                  *puVar1 = piVar13;
                  puVar1[1] = param_1;
                }
              }
              param_3[1] = param_3[1] + 8;
              local_14 = local_14 + 1;
              piVar13 = local_c;
            } while (local_14 < uVar11);
          }
          local_10 = 0;
          uVar11 = piVar13[0x27] - piVar13[0x26] >> 2;
          local_14 = uVar11;
          if (uVar11 != 0) {
            do {
              iVar6 = *(int *)(piVar13[0x26] + local_10 * 4);
              pcVar9 = (char *)(iVar6 + 8);
              if (0xf < *(uint *)(iVar6 + 0x1c)) {
                pcVar9 = *(char **)pcVar9;
              }
              pcVar9 = _strstr(pcVar9,"LP");
              if (pcVar9 != (char *)0x0) {
                piVar13 = (int *)param_3[1];
                local_28 = param_1;
                local_2c = iVar6;
                if (&local_2c < piVar13) {
                  piVar5 = (int *)*param_3;
                  if (&local_2c < piVar5) goto LAB_007cc9a2;
                  if (piVar13 == (int *)param_3[2]) {
                    uVar7 = (int)piVar13 - (int)piVar5 >> 3;
                    if (0x1ffffffe < uVar7) goto LAB_007cca3f;
                    uVar7 = uVar7 + 1;
                    uVar10 = (int)param_3[2] - (int)piVar5 >> 3;
                    if (uVar10 < uVar7) {
                      if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                        uVar10 = 0;
                      }
                      else {
                        uVar10 = uVar10 + (uVar10 >> 1);
                      }
                      if (uVar10 < uVar7) {
                        uVar10 = uVar7;
                      }
                      FUN_004e7330(uVar10);
                      uVar11 = local_14;
                    }
                  }
                  puVar4 = (undefined4 *)param_3[1];
                  puVar1 = (undefined4 *)(*param_3 + ((int)&local_2c - (int)piVar5 >> 3) * 8);
                  if (puVar4 != (undefined4 *)0x0) {
                    *puVar4 = *puVar1;
                    puVar4[1] = puVar1[1];
                  }
                }
                else {
LAB_007cc9a2:
                  if (piVar13 == (int *)param_3[2]) {
                    uVar7 = (int)((int)piVar13 - *param_3) >> 3;
                    if (0x1ffffffe < uVar7) {
LAB_007cca3f:
                    /* WARNING: Subroutine does not return */
                      FUN_0087db30("vector<T> too long");
                    }
                    uVar7 = uVar7 + 1;
                    uVar10 = (int)((int)param_3[2] - *param_3) >> 3;
                    if (uVar10 < uVar7) {
                      if (0x1fffffff - (uVar10 >> 1) < uVar10) {
                        uVar10 = 0;
                      }
                      else {
                        uVar10 = uVar10 + (uVar10 >> 1);
                      }
                      if (uVar10 < uVar7) {
                        uVar10 = uVar7;
                      }
                      FUN_004e7330(uVar10);
                      uVar11 = local_14;
                    }
                  }
                  piVar13 = (int *)param_3[1];
                  if (piVar13 != (int *)0x0) {
                    *piVar13 = iVar6;
                    piVar13[1] = (int)param_1;
                  }
                }
                param_3[1] = param_3[1] + 8;
              }
              local_10 = local_10 + 1;
              piVar13 = local_c;
            } while (local_10 < uVar11);
          }
        }
        else {
          iVar6 = (**(code **)(*piVar13 + 4))();
          if (*(int *)(iVar6 + 4) == -0x5ed90000) {
            FUN_007ccfa0();
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < local_1c);
    }
    iVar6 = (**(code **)(*param_1 + 0x34))();
    iVar12 = 0;
    if (0 < iVar6) {
      do {
        uVar8 = (**(code **)(*param_1 + 0x30))(iVar12,param_2,param_3);
        FUN_007cc6f0(uVar8);
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar6);
    }
  }
  return;
}

