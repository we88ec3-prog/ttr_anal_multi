
void FUN_007c6ce0(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int local_10;
  uint local_c;
  
  piVar3 = param_2;
  uVar5 = 0;
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 4))();
    iVar1 = *(int *)(iVar1 + 4);
    if (iVar1 < -0x5edbffff) {
      if (iVar1 == -0x5edc0000) {
        param_2 = (int *)0x0;
        if ((int *)piVar3[0x1d] != (int *)0x0) {
          (**(code **)(*(int *)piVar3[0x1d] + 0x38))();
          piVar3 = (int *)piVar3[0x1d];
          local_18 = piVar3;
          iVar1 = (**(code **)(*piVar3 + 4))();
          uVar2 = param_3;
          if ((*(int *)(iVar1 + 4) == -0x5ece0000) && (local_10 = 0, 0 < piVar3[0x5e])) {
            do {
              iVar1 = FUN_00843ef0();
              local_20 = *(uint *)(iVar1 + 0x3c);
              local_14 = iVar1;
              if (local_20 == 0) {
                local_24 = *(undefined4 *)(iVar1 + 0xb8);
                (**(code **)(*param_1 + 0x58))(&local_24,&param_2);
                uVar4 = FUN_007cd0d0(&param_2);
                FUN_004ad530(uVar2,local_40,uVar4);
              }
              else {
                local_c = 0;
                if (local_20 != 0) {
                  do {
                    uVar5 = local_c;
                    piVar3 = (int *)FUN_007800e0();
                    iVar7 = (**(code **)(*piVar3 + 4))();
                    iVar7 = *(int *)(iVar7 + 4);
                    if (iVar7 == -0x5dc00000) {
                      iVar7 = FUN_007800e0();
                      iVar8 = 0;
                      iVar1 = local_14;
                      if (0 < (int)(*(int *)(iVar7 + 0x34) - *(int *)(iVar7 + 0x30) & 0xfffffffcU))
                      {
                        do {
                          (**(code **)(*param_1 + 0x58))
                                    (*(int *)(*(int *)(iVar7 + 0x30) + iVar8 * 4) + 4,&param_2);
                          uVar4 = FUN_007cd0d0(&param_2);
                          FUN_004ad530(uVar2,local_30,uVar4);
                          iVar8 = iVar8 + 1;
                          iVar1 = local_14;
                        } while (iVar8 < *(int *)(iVar7 + 0x34) - *(int *)(iVar7 + 0x30) >> 2);
                      }
                    }
                    else if (iVar7 == -0x5de00000) {
                      local_1c = *(undefined4 *)(iVar1 + 0xb8);
                      (**(code **)(*param_1 + 0x58))(&local_1c,&param_2);
                      uVar4 = FUN_007cd0d0(&param_2);
                      FUN_004ad530(uVar2,local_38,uVar4);
                      local_c = uVar5;
                    }
                    else {
                      FID_conflict__wprintf("What\'s this?? : CLASSID - %x\n",iVar7);
                      local_c = uVar5;
                    }
                    local_c = local_c + 1;
                  } while (local_c < local_20);
                }
              }
              local_10 = local_10 + 1;
            } while (local_10 < local_18[0x5e]);
            return;
          }
        }
      }
      else if (iVar1 == -0x5eed0000) {
        iVar1 = piVar3[0x37] - piVar3[0x36] >> 2;
        if (0 < iVar1) {
          do {
            if (uVar5 < (uint)(piVar3[0x37] - piVar3[0x36] >> 2)) {
              uVar2 = *(undefined4 *)(piVar3[0x36] + uVar5 * 4);
            }
            else {
              uVar2 = 0;
            }
            FUN_007c6ce0(param_1,uVar2,param_3);
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 < iVar1);
        }
        iVar1 = (**(code **)(*piVar3 + 0x34))();
        iVar7 = 0;
        if (0 < iVar1) {
          do {
            uVar2 = (**(code **)(*piVar3 + 0x30))(iVar7,param_3);
            FUN_007c6ce0(param_1,uVar2);
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar1);
          return;
        }
      }
      else if (iVar1 == -0x5edf0000) {
        uVar6 = piVar3[0x1f] - piVar3[0x1e] >> 2;
        if (uVar6 != 0) {
          do {
            FUN_007c6ce0(param_1,*(undefined4 *)(piVar3[0x1e] + uVar5 * 4),param_3);
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar6);
        }
        uVar6 = 0;
        uVar5 = piVar3[0x23] - piVar3[0x22] >> 2;
        if (uVar5 != 0) {
          do {
            FUN_007c6ce0(param_1,*(undefined4 *)(piVar3[0x22] + uVar6 * 4),param_3);
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar5);
          return;
        }
      }
    }
    else if (iVar1 == -0x5ed70000) {
      piVar3 = (int *)piVar3[0x25];
      iVar1 = (**(code **)(*piVar3 + 4))();
      uVar2 = param_3;
      if ((*(int *)(iVar1 + 4) == -0x5ece0000) && (iVar1 = 0, 0 < piVar3[0x5e])) {
        do {
          iVar7 = FUN_00843ef0();
          param_2 = (int *)0x0;
          local_28 = *(undefined4 *)(iVar7 + 0xb8);
          (**(code **)(*param_1 + 0x58))(&local_28,&param_2);
          uVar4 = FUN_007cd0d0(&param_2);
          FUN_004ad530(uVar2,local_40,uVar4);
          iVar1 = iVar1 + 1;
        } while (iVar1 < piVar3[0x5e]);
      }
    }
  }
  return;
}

