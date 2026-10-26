
void FUN_00641e00(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int *piVar9;
  uint uVar10;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  int local_24 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092d1e8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar10 = 0;
  piVar9 = (int *)(in_ECX + 0x148);
  local_8 = 0;
  iVar8 = *(int *)(in_ECX + 0x14c) - *piVar9;
  iVar5 = iVar8 >> 0x1f;
  local_14 = in_ECX;
  if (iVar8 / 0x1c + iVar5 != iVar5) {
    do {
      puVar4 = param_1;
      if (in_stack_00000018 < 8) {
        puVar4 = &param_1;
      }
      iVar5 = FUN_0044df20(0,puVar4,in_stack_00000014);
      if (iVar5 == 0) goto LAB_006421bc;
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)((*(int *)(in_ECX + 0x14c) - *piVar9) / 0x1c));
  }
  iVar5 = local_14;
  FUN_0049c120(uVar3);
  uVar3 = (*(int *)(in_ECX + 0x14c) - *piVar9) / 0x1c;
  if (uVar3 < 10) {
    iVar5 = *(int *)(iVar5 + 0x134);
    iVar8 = *piVar9;
    iVar6 = *(int *)(iVar5 + 0x24c);
    if (iVar6 != 0) {
      iVar6 = *(int *)(iVar6 + 0xcc);
      if (iVar6 == 0) {
        iVar6 = -1;
      }
      else {
        iVar6 = FUN_0075d370(*(undefined4 *)(iVar6 + 0xe4));
      }
      iVar5 = *(int *)(*(int *)(iVar5 + 0x24c) + 0xcc);
      if (iVar5 != 0) {
        for (piVar9 = *(int **)(iVar5 + 0xa8);
            (piVar9 != *(int **)(iVar5 + 0xac) && (*(int *)(*piVar9 + 0x20) != iVar6));
            piVar9 = piVar9 + 1) {
        }
      }
      FUN_00757800(iVar8 + -0x1c + uVar3 * 0x1c);
    }
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x14c);
    iVar5 = *piVar9 + 0x1c;
    if (iVar5 != iVar8) {
      local_24[2] = *piVar9 - iVar5;
      do {
        FUN_00402800(iVar5);
        iVar5 = iVar5 + 0x1c;
      } while (iVar5 != iVar8);
    }
    puVar1 = *(undefined4 **)(in_ECX + 0x14c);
    for (puVar4 = puVar1 + -7; puVar4 != puVar1; puVar4 = puVar4 + 7) {
      if (7 < (uint)puVar4[5]) {
        FUN_0089120c(*puVar4);
      }
      puVar4[5] = 7;
      puVar4[4] = 0;
      *(undefined2 *)puVar4 = 0;
    }
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + -0x1c;
    iVar5 = *(int *)(*(int *)(local_14 + 0x134) + 0x24c);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0xcc), iVar5 != 0)) {
      FUN_006438f0(iVar5);
    }
    FUN_00757710();
    iVar8 = *(int *)(in_ECX + 0x14c) - *piVar9;
    iVar5 = iVar8 >> 0x1f;
    local_24[2] = 0;
    if (iVar8 / 0x1c + iVar5 != iVar5) {
      local_24[1] = 0;
      do {
        iVar6 = *piVar9 + local_24[1];
        iVar5 = *(int *)(local_14 + 0x134);
        iVar8 = *(int *)(iVar5 + 0x24c);
        if (iVar8 != 0) {
          piVar7 = *(int **)(iVar8 + 0xcc);
          if (piVar7 == (int *)0x0) {
            iVar8 = -1;
          }
          else {
            piVar2 = (int *)piVar7[0x29];
            iVar8 = piVar7[0x39];
            if (piVar2 == (int *)0x0) {
              iVar8 = -1;
            }
            else {
              if (piVar7[0x2e] == piVar7[0x2f]) {
                local_24[3] = (**(code **)(*piVar2 + 0x28))();
              }
              else {
                local_24[3] = *(int *)(piVar7[0x2f] + -4);
                (**(code **)(*piVar2 + 0x2c))(local_24[3]);
                if (piVar7[0x2e] != piVar7[0x2f]) {
                  piVar7[0x2f] = piVar7[0x2f] + -4;
                }
              }
              *(int *)(local_24[3] + 0x20) = iVar8;
              local_24[0] = local_24[3];
              (**(code **)(*piVar7 + 0x70))(local_24[3]);
              piVar2 = (int *)piVar7[0x2b];
              if (local_24 < piVar2) {
                if (local_24 < (int *)piVar7[0x2a]) goto LAB_00642079;
                local_24[3] = (int)local_24 - piVar7[0x2a] >> 2;
                if (piVar2 == (int *)piVar7[0x2c]) {
                  FUN_004deab0();
                }
                if ((undefined4 *)piVar7[0x2b] != (undefined4 *)0x0) {
                  *(undefined4 *)piVar7[0x2b] = *(undefined4 *)(piVar7[0x2a] + local_24[3] * 4);
                }
              }
              else {
LAB_00642079:
                if (piVar2 == (int *)piVar7[0x2c]) {
                  FUN_004deab0();
                }
                if ((int *)piVar7[0x2b] != (int *)0x0) {
                  *(int *)piVar7[0x2b] = local_24[3];
                }
              }
              piVar7[0x2b] = piVar7[0x2b] + 4;
              uVar3 = iVar8 + 1U;
              if (iVar8 + 1U <= (uint)piVar7[0x39]) {
                uVar3 = piVar7[0x39];
              }
              piVar7[0x39] = uVar3;
            }
          }
          iVar5 = *(int *)(*(int *)(iVar5 + 0x24c) + 0xcc);
          if (iVar5 != 0) {
            for (piVar7 = *(int **)(iVar5 + 0xa8);
                (piVar7 != *(int **)(iVar5 + 0xac) && (*(int *)(*piVar7 + 0x20) != iVar8));
                piVar7 = piVar7 + 1) {
            }
          }
          FUN_00757800(iVar6);
        }
        local_24[1] = local_24[1] + 0x1c;
        local_24[2] = local_24[2] + 1;
      } while ((uint)local_24[2] < (uint)((*(int *)(in_ECX + 0x14c) - *piVar9) / 0x1c));
    }
  }
LAB_006421bc:
  piVar9 = *(int **)(*(int *)(local_14 + 0x134) + 0x24c);
  if (piVar9[0x33] == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(piVar9[0x33] + 0xd4);
  }
  if ((piVar9 == (int *)0x0) || (iVar8 = piVar9[0x33], iVar8 == 0)) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2;
  }
  (**(code **)(*piVar9 + 0xbc))(piVar9[2],piVar9[3],piVar9[4],iVar8 * iVar5 + piVar9[3]);
  puVar4 = (undefined4 *)piVar9[0x19];
  for (puVar1 = (undefined4 *)*puVar4; puVar1 != puVar4; puVar1 = (undefined4 *)*puVar1) {
    iVar5 = puVar1[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar9 + 0x128))();
  (**(code **)(*piVar9 + 200))();
  if (*(int *)(*(int *)(local_14 + 0x134) + 0x24c) != 0) {
    puVar4 = param_1;
    if (in_stack_00000018 < 8) {
      puVar4 = &param_1;
    }
    FUN_0075cc70(*(int *)(local_14 + 0x134),puVar4);
  }
  piVar9 = *(int **)(local_14 + 0x134);
  puVar4 = (undefined4 *)piVar9[0x19];
  for (puVar1 = (undefined4 *)*puVar4; puVar1 != puVar4; puVar1 = (undefined4 *)*puVar1) {
    iVar5 = puVar1[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar9 + 0x128))();
  (**(code **)(**(int **)(local_14 + 0x134) + 200))();
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

