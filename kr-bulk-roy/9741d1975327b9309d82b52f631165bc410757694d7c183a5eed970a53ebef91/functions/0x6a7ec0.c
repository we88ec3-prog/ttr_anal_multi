
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a7ec0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b70e;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar9 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar9 != 0) {
    FUN_006438f0(iVar9);
  }
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(uVar7);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  local_1c = (DAT_00fc0bfc - _DAT_00fc0bf8) / 0xc;
  if (local_1c != 0) {
    local_18 = 0;
    do {
      iVar9 = *(int *)(local_18 + _DAT_00fc0bf8);
      piVar1 = *(int **)(*(int *)(param_1 + 0xec) + 0xcc);
      if ((piVar1 == (int *)0x0) || (piVar2 = (int *)piVar1[0x29], piVar2 == (int *)0x0)) {
LAB_006a8090:
        piVar8 = (int *)0x0;
      }
      else {
        if (piVar1[0x2e] == piVar1[0x2f]) {
          piVar8 = (int *)(**(code **)(*piVar2 + 0x28))();
        }
        else {
          piVar8 = *(int **)(piVar1[0x2f] + -4);
          (**(code **)(*piVar2 + 0x2c))(piVar8);
          if (piVar1[0x2e] != piVar1[0x2f]) {
            piVar1[0x2f] = piVar1[0x2f] + -4;
          }
        }
        piVar8[8] = iVar9;
        local_14 = piVar8;
        (**(code **)(*piVar1 + 0x70))(piVar8);
        ppiVar3 = (int **)piVar1[0x2b];
        if ((&local_14 < ppiVar3) && (ppiVar4 = (int **)piVar1[0x2a], ppiVar4 <= &local_14)) {
          if (ppiVar3 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] =
                 *(undefined4 *)(piVar1[0x2a] + ((int)&local_14 - (int)ppiVar4 >> 2) * 4);
          }
        }
        else {
          if (ppiVar3 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] = piVar8;
          }
        }
        piVar1[0x2b] = piVar1[0x2b] + 4;
        uVar7 = iVar9 + 1;
        if (uVar7 <= (uint)piVar1[0x39]) {
          uVar7 = piVar1[0x39];
        }
        piVar1[0x39] = uVar7;
        iVar9 = (**(code **)(*piVar8 + 4))();
        if (iVar9 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_006a8090;
        }
      }
      FUN_006a7da0(piVar8);
      local_18 = local_18 + 0xc;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  piVar1 = *(int **)(param_1 + 0xec);
  puVar5 = (undefined4 *)piVar1[0x19];
  for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    iVar9 = puVar6[2];
    if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  ExceptionList = local_10;
  return;
}

