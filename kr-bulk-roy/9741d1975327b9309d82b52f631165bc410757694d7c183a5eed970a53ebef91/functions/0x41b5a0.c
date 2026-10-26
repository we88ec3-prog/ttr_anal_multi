
void FUN_0041b5a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint local_c;
  int *local_8;
  
  iVar9 = *(int *)(*(int *)(param_1 + 0x100) + 0xcc);
  if (iVar9 != 0) {
    FUN_006438f0(iVar9);
  }
  local_c = 0;
  if (*(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x118) >> 2 != 0) {
    do {
      iVar9 = **(int **)(*(int *)(param_1 + 0x118) + local_c * 4);
      piVar1 = *(int **)(*(int *)(param_1 + 0x100) + 0xcc);
      if ((piVar1 == (int *)0x0) || (piVar2 = (int *)piVar1[0x29], piVar2 == (int *)0x0)) {
LAB_0041b723:
        piVar7 = (int *)0x0;
      }
      else {
        if (piVar1[0x2e] == piVar1[0x2f]) {
          piVar7 = (int *)(**(code **)(*piVar2 + 0x28))();
        }
        else {
          piVar7 = *(int **)(piVar1[0x2f] + -4);
          (**(code **)(*piVar2 + 0x2c))(piVar7);
          if (piVar1[0x2e] != piVar1[0x2f]) {
            piVar1[0x2f] = piVar1[0x2f] + -4;
          }
        }
        piVar7[8] = iVar9;
        local_8 = piVar7;
        (**(code **)(*piVar1 + 0x70))(piVar7);
        ppiVar3 = (int **)piVar1[0x2b];
        if (&local_8 < ppiVar3) {
          ppiVar4 = (int **)piVar1[0x2a];
          if (&local_8 < ppiVar4) goto LAB_0041b6b3;
          if (ppiVar3 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] =
                 *(undefined4 *)(piVar1[0x2a] + ((int)&local_8 - (int)ppiVar4 >> 2) * 4);
          }
        }
        else {
LAB_0041b6b3:
          if (ppiVar3 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] = piVar7;
          }
        }
        piVar1[0x2b] = piVar1[0x2b] + 4;
        uVar8 = iVar9 + 1;
        if (uVar8 <= (uint)piVar1[0x39]) {
          uVar8 = piVar1[0x39];
        }
        piVar1[0x39] = uVar8;
        iVar9 = (**(code **)(*piVar7 + 4))();
        if (iVar9 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_0041b723;
        }
      }
      FUN_0041b860(piVar7);
      (**(code **)(*piVar7 + 200))();
      local_c = local_c + 1;
    } while (local_c < (uint)(*(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x118) >> 2));
  }
  piVar1 = *(int **)(param_1 + 0x100);
  puVar5 = (undefined4 *)piVar1[0x19];
  for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    iVar9 = puVar6[2];
    if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  return;
}

