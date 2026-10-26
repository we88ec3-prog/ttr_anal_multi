
void FUN_007c5f40(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_c [4];
  int local_8;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 4))();
    iVar1 = *(int *)(iVar1 + 4);
    if (iVar1 < -0x5ed6ffff) {
      if (iVar1 == -0x5ed70000) {
        if ((float)*(int *)(param_2 + 4) < (float)param_1[0x27] * 30.0) {
          uVar4 = FUN_008fed10();
          *(undefined4 *)(param_2 + 4) = uVar4;
          return;
        }
      }
      else if (iVar1 < -0x5edcffff) {
        if (iVar1 == -0x5edd0000) {
          iVar1 = param_1[0xf];
          iVar8 = 0;
          if (0 < iVar1) {
            do {
              piVar3 = (int *)FUN_007800e0();
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 0x1c))(local_c);
                if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
                  *(int *)(param_2 + 4) = local_8 / 0xa0;
                }
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < iVar1);
            return;
          }
        }
        else if (iVar1 == -0x5eed0000) {
          iVar1 = param_1[0xf];
          iVar8 = 0;
          if (0 < iVar1) {
            do {
              piVar3 = (int *)FUN_007800e0();
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 0x1c))(local_c);
                if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
                  *(int *)(param_2 + 4) = local_8 / 0xa0;
                }
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < iVar1);
          }
          uVar6 = 0;
          iVar1 = param_1[0x37] - param_1[0x36] >> 2;
          if (0 < iVar1) {
            do {
              if ((uVar6 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) &&
                 (iVar8 = *(int *)(param_1[0x36] + uVar6 * 4), iVar8 != 0)) {
                FUN_007c5f40(iVar8,param_2);
              }
              uVar6 = uVar6 + 1;
            } while ((int)uVar6 < iVar1);
          }
          iVar1 = (**(code **)(*param_1 + 0x34))();
          iVar8 = 0;
          if (0 < iVar1) {
            do {
              uVar4 = (**(code **)(*param_1 + 0x30))(iVar8,param_2);
              FUN_007c5f40(uVar4);
              iVar8 = iVar8 + 1;
            } while (iVar8 < iVar1);
            return;
          }
        }
        else if (iVar1 == -0x5edf0000) {
          uVar6 = 0;
          uVar7 = param_1[0x27] - param_1[0x26] >> 2;
          if (uVar7 != 0) {
            do {
              puVar2 = (undefined4 *)FUN_007cd290();
              FUN_007c5f40(*puVar2,param_2);
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar7);
          }
          uVar7 = 0;
          uVar6 = param_1[0x1f] - param_1[0x1e] >> 2;
          if (uVar6 != 0) {
            do {
              FUN_007c5f40(*(undefined4 *)(param_1[0x1e] + uVar7 * 4),param_2);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar6);
            return;
          }
        }
      }
      else if (iVar1 == -0x5edc0000) {
        iVar1 = param_1[0xf];
        iVar8 = 0;
        if (0 < iVar1) {
          do {
            piVar3 = (int *)FUN_007800e0();
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 0x1c))(local_c);
              if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
                *(int *)(param_2 + 4) = local_8 / 0xa0;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar1);
        }
        if ((int *)param_1[0x1d] == (int *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = (**(code **)(*(int *)param_1[0x1d] + 0x38))();
          if (iVar1 == 0) {
            iVar1 = 1;
          }
        }
        iVar8 = 0;
        if (0 < iVar1) {
          do {
            if ((int *)param_1[0x1d] != (int *)0x0) {
              iVar5 = (**(code **)(*(int *)param_1[0x1d] + 0x24))();
              if (iVar5 == 0) {
                if (iVar8 == 0) {
                  iVar5 = param_1[0x1d];
LAB_007c61cc:
                  if (iVar5 != 0) {
                    FUN_007c5f40(iVar5,param_2);
                  }
                }
              }
              else {
                iVar5 = (**(code **)(*(int *)param_1[0x1d] + 0x38))();
                if (iVar8 < iVar5) {
                  iVar5 = (**(code **)(*(int *)param_1[0x1d] + 0x28))(iVar8);
                  goto LAB_007c61cc;
                }
              }
            }
            iVar8 = iVar8 + 1;
            if (iVar1 <= iVar8) {
              return;
            }
          } while( true );
        }
      }
    }
    else if (iVar1 == -0x5ecf0000) {
      iVar1 = param_1[0xf];
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          piVar3 = (int *)FUN_007800e0();
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x1c))(local_c);
            if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
              *(int *)(param_2 + 4) = local_8 / 0xa0;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
      }
      iVar1 = (**(code **)(*param_1 + 0x38))();
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          uVar4 = (**(code **)(*param_1 + 0x28))(iVar8,param_2);
          FUN_007c5f40(uVar4);
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
        return;
      }
    }
    else if (iVar1 == -0x5ece0000) {
      iVar1 = param_1[0xf];
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          piVar3 = (int *)FUN_007800e0();
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x1c))(local_c);
            if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
              *(int *)(param_2 + 4) = local_8 / 0xa0;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
      }
      iVar1 = param_1[0x5e];
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          uVar4 = FUN_00843ef0(param_2);
          FUN_007c5f40(uVar4);
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
        return;
      }
    }
    else if (iVar1 == -0x5ec00000) {
      iVar1 = param_1[0xf];
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          piVar3 = (int *)FUN_007800e0();
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x1c))(local_c);
            if (*(int *)(param_2 + 4) < local_8 / 0xa0) {
              *(int *)(param_2 + 4) = local_8 / 0xa0;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
        return;
      }
    }
  }
  return;
}

