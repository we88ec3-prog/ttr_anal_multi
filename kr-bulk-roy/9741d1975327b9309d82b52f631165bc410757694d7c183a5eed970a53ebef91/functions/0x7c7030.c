
void FUN_007c7030(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint local_14;
  uint local_10;
  int *local_8;
  
  iVar1 = param_1[0x37] - param_1[0x36] >> 2;
  local_10 = 0;
  if (0 < iVar1) {
    do {
      if (local_10 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
        local_8 = *(int **)(param_1[0x36] + local_10 * 4);
      }
      else {
        local_8 = (int *)0x0;
      }
      iVar2 = (**(code **)(*local_8 + 4))();
      if (*(int *)(iVar2 + 4) == -0x5edf0000) {
        local_14 = 0;
        if (local_8[0x1f] - local_8[0x1e] >> 2 != 0) {
          do {
            if (param_2 == 1) {
              *(undefined4 *)(*(int *)(local_8[0x1e] + local_14 * 4) + 0x24) = 0;
            }
            else {
              iVar2 = *(int *)(local_8[0x1e] + local_14 * 4);
              uVar9 = 0;
              while (*(int **)(iVar2 + 0x74) != (int *)0x0) {
                uVar5 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x38))();
                if (uVar5 == 0) {
                  uVar5 = 1;
                }
                if (uVar5 <= uVar9) break;
                if (*(int **)(iVar2 + 0x74) == (int *)0x0) {
LAB_007c7133:
                  piVar6 = (int *)0x0;
                }
                else {
                  iVar4 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x24))();
                  if (iVar4 == 0) {
                    if (uVar9 != 0) goto LAB_007c7133;
                    piVar6 = *(int **)(iVar2 + 0x74);
                  }
                  else {
                    iVar4 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x38))();
                    if (iVar4 <= (int)uVar9) goto LAB_007c7133;
                    piVar6 = (int *)(**(code **)(**(int **)(iVar2 + 0x74) + 0x28))(uVar9);
                  }
                }
                iVar4 = (**(code **)(*piVar6 + 4))();
                if (*(int *)(iVar4 + 4) == -0x5ece0000) {
                  if (*(int **)(iVar2 + 0x74) == (int *)0x0) {
LAB_007c717f:
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x24))();
                    if (iVar4 == 0) {
                      if (uVar9 != 0) goto LAB_007c717f;
                      iVar4 = *(int *)(iVar2 + 0x74);
                    }
                    else {
                      iVar4 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x38))();
                      if (iVar4 <= (int)uVar9) goto LAB_007c717f;
                      iVar4 = (**(code **)(**(int **)(iVar2 + 0x74) + 0x28))(uVar9);
                    }
                  }
                  if (param_2 != 2) {
                    iVar7 = 0;
                    if (0 < *(int *)(iVar4 + 0x178)) {
                      do {
                        iVar3 = FUN_00843ef0();
                        iVar7 = iVar7 + 1;
                        *(undefined4 *)(iVar3 + 0x24) = 0;
                      } while (iVar7 < *(int *)(iVar4 + 0x178));
                    }
                    goto LAB_007c71bb;
                  }
                  *(undefined4 *)(iVar4 + 0x24) = 0;
                  uVar9 = uVar9 + 1;
                }
                else {
LAB_007c71bb:
                  uVar9 = uVar9 + 1;
                }
              }
            }
            local_14 = local_14 + 1;
          } while (local_14 < (uint)(local_8[0x1f] - local_8[0x1e] >> 2));
        }
        iVar2 = local_8[0x22];
        iVar4 = local_8[0x23] - iVar2 >> 2;
        uVar9 = 0;
        if (iVar4 != 0) {
          if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_0087db7d("invalid vector<T> subscript");
          }
          do {
            FUN_007c7030(*(undefined4 *)(iVar2 + uVar9 * 4),param_2);
            iVar2 = local_8[0x22];
            uVar9 = uVar9 + 1;
          } while (uVar9 < (uint)(local_8[0x23] - iVar2 >> 2));
        }
      }
      iVar2 = (**(code **)(*local_8 + 4))();
      if (*(int *)(iVar2 + 4) == -0x5edc0000) {
        if (param_2 == 1) {
          local_8[9] = 0;
        }
        else {
          uVar9 = 0;
          while ((int *)local_8[0x1d] != (int *)0x0) {
            uVar5 = (**(code **)(*(int *)local_8[0x1d] + 0x38))();
            if (uVar5 == 0) {
              uVar5 = 1;
            }
            if (uVar5 <= uVar9) break;
            if ((int *)local_8[0x1d] == (int *)0x0) {
LAB_007c72aa:
              piVar6 = (int *)0x0;
            }
            else {
              iVar2 = (**(code **)(*(int *)local_8[0x1d] + 0x24))();
              if (iVar2 == 0) {
                if (uVar9 != 0) goto LAB_007c72aa;
                piVar6 = (int *)local_8[0x1d];
              }
              else {
                iVar2 = (**(code **)(*(int *)local_8[0x1d] + 0x38))();
                if (iVar2 <= (int)uVar9) goto LAB_007c72aa;
                piVar6 = (int *)(**(code **)(*(int *)local_8[0x1d] + 0x28))(uVar9);
              }
            }
            iVar2 = (**(code **)(*piVar6 + 4))();
            if (*(int *)(iVar2 + 4) == -0x5ece0000) {
              if ((int *)local_8[0x1d] == (int *)0x0) {
LAB_007c72fa:
                iVar2 = 0;
              }
              else {
                iVar2 = (**(code **)(*(int *)local_8[0x1d] + 0x24))();
                if (iVar2 == 0) {
                  if (uVar9 != 0) goto LAB_007c72fa;
                  iVar2 = local_8[0x1d];
                }
                else {
                  iVar2 = (**(code **)(*(int *)local_8[0x1d] + 0x38))();
                  if (iVar2 <= (int)uVar9) goto LAB_007c72fa;
                  iVar2 = (**(code **)(*(int *)local_8[0x1d] + 0x28))(uVar9);
                }
              }
              if (param_2 != 2) {
                iVar4 = 0;
                if (0 < *(int *)(iVar2 + 0x178)) {
                  do {
                    iVar7 = FUN_00843ef0();
                    iVar4 = iVar4 + 1;
                    *(undefined4 *)(iVar7 + 0x24) = 0;
                  } while (iVar4 < *(int *)(iVar2 + 0x178));
                }
                goto LAB_007c733a;
              }
              *(undefined4 *)(iVar2 + 0x24) = 0;
              uVar9 = uVar9 + 1;
            }
            else {
LAB_007c733a:
              uVar9 = uVar9 + 1;
            }
          }
        }
      }
      local_10 = local_10 + 1;
    } while ((int)local_10 < iVar1);
  }
  iVar1 = (**(code **)(*param_1 + 0x34))();
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      uVar8 = (**(code **)(*param_1 + 0x30))(iVar2,param_2);
      FUN_007c7030(uVar8);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

