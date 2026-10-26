
void FUN_00643300(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  int local_28;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00935d68;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar14 = 0;
  local_8 = 0;
  iVar15 = *(int *)(param_1 + 0x148);
  iVar13 = *(int *)(param_1 + 0x14c) - iVar15;
  iVar9 = iVar13 >> 0x1f;
  if (iVar13 / 0x1c + iVar9 != iVar9) {
    local_14 = 0;
    do {
      puVar8 = param_2;
      if (in_stack_0000001c < 8) {
        puVar8 = &param_2;
      }
      iVar9 = FUN_0044df20(0,puVar8,in_stack_00000018);
      if (iVar9 == 0) {
        iVar9 = *(int *)(param_1 + 0x14c);
        while (iVar15 = iVar15 + 0x1c, iVar15 != iVar9) {
          FUN_00402800(iVar15);
        }
        puVar6 = *(undefined4 **)(param_1 + 0x14c);
        for (puVar8 = puVar6 + -7; puVar8 != puVar6; puVar8 = puVar8 + 7) {
          if (7 < (uint)puVar8[5]) {
            FUN_0089120c(*puVar8);
          }
          puVar8[5] = 7;
          puVar8[4] = 0;
          *(undefined2 *)puVar8 = 0;
        }
        *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + -0x1c;
        iVar15 = *(int *)(*(int *)(*(int *)(param_1 + 0x134) + 0x24c) + 0xcc);
        if (iVar15 != 0) {
          FUN_006438f0(iVar15);
        }
        iVar9 = *(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148);
        iVar15 = iVar9 >> 0x1f;
        local_1c = 0;
        if (iVar9 / 0x1c + iVar15 == iVar15) break;
        local_28 = 0;
        do {
          iVar15 = *(int *)(param_1 + 0x148);
          iVar9 = *(int *)(param_1 + 0x134);
          iVar13 = *(int *)(iVar9 + 0x24c);
          if (iVar13 != 0) {
            piVar10 = *(int **)(iVar13 + 0xcc);
            if (piVar10 == (int *)0x0) {
              iVar13 = -1;
            }
            else {
              iVar13 = piVar10[0x39];
              if ((int *)piVar10[0x29] == (int *)0x0) {
                iVar13 = -1;
              }
              else {
                iVar12 = *(int *)piVar10[0x29];
                if (piVar10[0x2e] == piVar10[0x2f]) {
                  local_20 = (**(code **)(iVar12 + 0x28))();
                }
                else {
                  local_20 = *(int *)(piVar10[0x2f] + -4);
                  (**(code **)(iVar12 + 0x2c))(local_20);
                  if (piVar10[0x2e] != piVar10[0x2f]) {
                    piVar10[0x2f] = piVar10[0x2f] + -4;
                  }
                }
                *(int *)(local_20 + 0x20) = iVar13;
                local_14 = local_20;
                (**(code **)(*piVar10 + 0x70))(local_20);
                piVar5 = (int *)piVar10[0x2b];
                if (&local_14 < piVar5) {
                  piVar11 = (int *)piVar10[0x2a];
                  if (&local_14 < piVar11) goto LAB_00643553;
                  if (piVar5 == (int *)piVar10[0x2c]) {
                    FUN_004deab0();
                  }
                  if ((undefined4 *)piVar10[0x2b] != (undefined4 *)0x0) {
                    *(undefined4 *)piVar10[0x2b] =
                         *(undefined4 *)(piVar10[0x2a] + ((int)&local_14 - (int)piVar11 >> 2) * 4);
                  }
                }
                else {
LAB_00643553:
                  if (piVar5 == (int *)piVar10[0x2c]) {
                    FUN_004deab0();
                  }
                  if ((int *)piVar10[0x2b] != (int *)0x0) {
                    *(int *)piVar10[0x2b] = local_20;
                  }
                }
                piVar10[0x2b] = piVar10[0x2b] + 4;
                uVar14 = iVar13 + 1U;
                if (iVar13 + 1U <= (uint)piVar10[0x39]) {
                  uVar14 = piVar10[0x39];
                }
                piVar10[0x39] = uVar14;
              }
            }
            iVar9 = *(int *)(*(int *)(iVar9 + 0x24c) + 0xcc);
            if (iVar9 != 0) {
              for (piVar10 = *(int **)(iVar9 + 0xa8);
                  (piVar10 != *(int **)(iVar9 + 0xac) && (*(int *)(*piVar10 + 0x20) != iVar13));
                  piVar10 = piVar10 + 1) {
              }
            }
            FUN_00757800(iVar15 + local_28);
          }
          local_28 = local_28 + 0x1c;
          local_1c = local_1c + 1;
        } while (local_1c < (uint)((*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148)) / 0x1c));
        break;
      }
      local_14 = local_14 + 0x1c;
      uVar14 = uVar14 + 1;
      iVar15 = iVar15 + 0x1c;
    } while (uVar14 < (uint)((*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148)) / 0x1c));
  }
  iVar15 = *(int *)(param_1 + 0x134);
  iVar9 = *(int *)(iVar15 + 0x24c);
  uVar1 = *(undefined4 *)(iVar9 + 8);
  uVar2 = *(undefined4 *)(iVar9 + 0xc);
  uVar3 = *(undefined4 *)(iVar9 + 0x10);
  iVar13 = *(int *)(iVar9 + 0x14);
  if ((iVar9 == 0) || (*(int *)(iVar9 + 0xcc) == 0)) {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(*(int *)(iVar9 + 0xcc) + 0xd4);
  }
  if (*(int *)(iVar15 + 0x24c) != 0) {
    if (*(int *)(*(int *)(iVar15 + 0x24c) + 0xcc) != 0) {
      FUN_0042c8e0((*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148)) / 0x1c + -1);
    }
    iVar12 = *(int *)(*(int *)(iVar15 + 0x24c) + 0xcc);
    if (iVar12 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar12 + 0xdc);
    }
    local_14 = iVar12;
    if (iVar12 != 0) {
      FUN_004026e0(iVar12 + 0xe8,0,0xffffffff);
      piVar10 = (int *)(iVar15 + 0x104);
      if (piVar10 != (int *)(iVar12 + 0x104)) {
        puVar8 = *(undefined4 **)(iVar12 + 0x104);
        uVar4 = *puVar8;
        piVar5 = (int *)*piVar10;
        piVar11 = (int *)*piVar5;
        *piVar5 = (int)piVar5;
        *(int *)(*piVar10 + 4) = *piVar10;
        *(undefined4 *)(iVar15 + 0x108) = 0;
        local_18 = iVar15;
        if (piVar11 != (int *)*piVar10) {
          do {
            local_18 = *piVar11;
            FUN_0089120c(piVar11);
            piVar11 = (int *)local_18;
          } while (local_18 != *piVar10);
        }
        FUN_00405030(piVar10,*(undefined4 *)*piVar10,uVar4,puVar8,local_18);
      }
      iVar12 = local_14 + 0x110;
      if (iVar15 + 0x110 != iVar12) {
        FUN_006d7120(**(undefined4 **)(iVar15 + 0x114),*(undefined4 **)(iVar15 + 0x114));
        FUN_00405270(iVar12);
      }
      *(undefined4 *)(iVar15 + 0x154) = *(undefined4 *)(local_14 + 0x154);
    }
  }
  (**(code **)(**(int **)(*(int *)(param_1 + 0x134) + 0x24c) + 0xbc))
            (uVar1,uVar2,uVar3,iVar13 - iVar9,uVar7);
  piVar10 = *(int **)(*(int *)(param_1 + 0x134) + 0x24c);
  if (piVar10 != (int *)0x0) {
    puVar8 = (undefined4 *)piVar10[0x19];
    for (puVar6 = (undefined4 *)*puVar8; puVar6 != puVar8; puVar6 = (undefined4 *)*puVar6) {
      iVar15 = puVar6[2];
      if ((*(int *)(iVar15 + 0x60) != 0) && ((*(int **)(iVar15 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar15 + 0x1c) + 0x30))(iVar15);
      }
    }
    (**(code **)(*piVar10 + 0x128))();
  }
  (**(code **)(**(int **)(param_1 + 0x134) + 200))();
  iVar15 = *(int *)(*(int *)(param_1 + 0x134) + 0x24c);
  if (((iVar15 == 0) || (iVar15 = *(int *)(iVar15 + 0xcc), iVar15 == 0)) ||
     (*(int *)(iVar15 + 0xac) - *(int *)(iVar15 + 0xa8) >> 2 < 1)) {
    FUN_00642e60(0,0,1);
  }
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  return;
}

