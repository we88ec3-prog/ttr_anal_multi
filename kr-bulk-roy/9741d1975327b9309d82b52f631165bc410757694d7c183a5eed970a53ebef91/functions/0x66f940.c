
void FUN_0066f940(void)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int local_10;
  undefined4 *local_c;
  int *local_8;
  
  FUN_00755e50();
  FUN_00619bd0();
  FUN_00670100();
  FUN_00643ce0(21000);
  FUN_00643ce0(22000);
  FUN_00615fc0(30000);
  FUN_00615fc0(31000);
  FUN_00615fc0(32000);
  local_c = (undefined4 *)(in_ECX + 0x114);
  local_10 = 10;
  do {
    piVar1 = *(int **)(*(int *)(in_ECX + 0xf8) + 0xcc);
    if (piVar1 == (int *)0x0) {
LAB_0066fb08:
      piVar7 = (int *)0x0;
    }
    else {
      iVar9 = piVar1[0x39];
      if ((int *)piVar1[0x29] == (int *)0x0) goto LAB_0066fb08;
      iVar2 = *(int *)piVar1[0x29];
      if (piVar1[0x2e] == piVar1[0x2f]) {
        piVar7 = (int *)(**(code **)(iVar2 + 0x28))();
      }
      else {
        piVar7 = *(int **)(piVar1[0x2f] + -4);
        (**(code **)(iVar2 + 0x2c))(piVar7);
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
        if (&local_8 < ppiVar4) goto LAB_0066faa8;
        if (ppiVar3 == (int **)piVar1[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar1[0x2b] =
               *(undefined4 *)(piVar1[0x2a] + ((int)&local_8 - (int)ppiVar4 >> 2) * 4);
        }
      }
      else {
LAB_0066faa8:
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
        goto LAB_0066fb08;
      }
    }
    *local_c = piVar7;
    local_c = local_c + 1;
    local_10 = local_10 + -1;
    if (local_10 == 0) {
      piVar1 = *(int **)(in_ECX + 0xf8);
      puVar5 = (undefined4 *)piVar1[0x19];
      for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
        iVar9 = puVar6[2];
        if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
        }
      }
      (**(code **)(*piVar1 + 0x128))();
      return;
    }
  } while( true );
}

