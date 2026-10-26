
void FUN_007ee9a0(int *param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int in_ECX;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iStack_30;
  uint uStack_2c;
  int *apiStack_28 [4];
  int *piStack_18;
  int *piStack_14;
  
  iVar4 = (**(code **)(*param_1 + 4))();
  if (iVar4 != 0) {
    while (*(int *)(iVar4 + 4) != -0x5ef00000) {
      iVar4 = *(int *)(iVar4 + 0x28);
      if (iVar4 == 0) {
        return;
      }
    }
    for (iVar4 = (**(code **)(*param_1 + 4))(); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {
      if (*(int *)(iVar4 + 4) == -0x5eed0000) {
        uStack_2c = 0;
        if (0 < (int)(param_1[0x37] - param_1[0x36] & 0xfffffffcU)) {
          do {
            if (uStack_2c < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
              piVar7 = *(int **)(param_1[0x36] + uStack_2c * 4);
            }
            else {
              piVar7 = (int *)0x0;
            }
            if (piVar7[0x1c] == 0) {
              iVar4 = (**(code **)(*piVar7 + 4))();
              if (*(int *)(iVar4 + 4) == -0x5edf0000) {
                iStack_30 = 0;
                if (0 < (int)(piVar7[0x1f] - piVar7[0x1e] & 0xfffffffcU)) {
                  do {
                    apiStack_28[1] = *(int **)(piVar7[0x1e] + iStack_30 * 4);
                    ppiVar1 = *(int ***)(in_ECX + 8);
                    apiStack_28[0] = param_1;
                    if (apiStack_28 < ppiVar1) {
                      ppiVar2 = *(int ***)(in_ECX + 4);
                      if (apiStack_28 < ppiVar2) goto LAB_007eeaed;
                      if (ppiVar1 == *(int ***)(in_ECX + 0xc)) {
                        FUN_007eee80();
                      }
                      puVar3 = *(undefined4 **)(in_ECX + 8);
                      puVar8 = (undefined4 *)
                               (((int)apiStack_28 - (int)ppiVar2 & 0xfffffff0U) +
                               *(int *)(in_ECX + 4));
                      if (puVar3 != (undefined4 *)0x0) {
                        *puVar3 = *puVar8;
                        puVar3[1] = puVar8[1];
                        puVar3[2] = puVar8[2];
                        puVar3[3] = puVar8[3];
                      }
                    }
                    else {
LAB_007eeaed:
                      if (ppiVar1 == *(int ***)(in_ECX + 0xc)) {
                        FUN_007eee80();
                      }
                      puVar3 = *(undefined4 **)(in_ECX + 8);
                      if (puVar3 != (undefined4 *)0x0) {
                        *puVar3 = apiStack_28[0];
                        puVar3[1] = apiStack_28[1];
                        puVar3[2] = apiStack_28[2];
                        puVar3[3] = apiStack_28[3];
                      }
                    }
                    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
                    iStack_30 = iStack_30 + 1;
                  } while (iStack_30 < piVar7[0x1f] - piVar7[0x1e] >> 2);
                }
                iVar4 = piVar7[0x22];
                uVar9 = 0;
                if (piVar7[0x23] - iVar4 >> 2 != 0) {
                  do {
                    FUN_007ee9a0(*(undefined4 *)(iVar4 + uVar9 * 4));
                    iVar4 = piVar7[0x22];
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < (uint)(piVar7[0x23] - iVar4 >> 2));
                }
              }
              else {
                piStack_18 = param_1;
                piStack_14 = piVar7;
                FUN_007eee20();
              }
            }
            uStack_2c = uStack_2c + 1;
          } while ((int)uStack_2c < param_1[0x37] - param_1[0x36] >> 2);
        }
        break;
      }
    }
    uVar9 = 0;
    iVar4 = (**(code **)(*param_1 + 0x34))();
    if (iVar4 != 0) {
      do {
        uVar5 = (**(code **)(*param_1 + 0x30))(uVar9);
        FUN_007ee9a0(uVar5);
        uVar9 = uVar9 + 1;
        uVar6 = (**(code **)(*param_1 + 0x34))();
      } while (uVar9 < uVar6);
    }
  }
  return;
}

