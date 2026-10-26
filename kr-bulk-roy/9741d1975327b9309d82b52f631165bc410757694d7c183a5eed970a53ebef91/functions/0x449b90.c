
void FUN_00449b90(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined **local_30 [3];
  char *local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094522e;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = *(int *)(*(int *)(param_1 + 0xf4) + 0xcc);
  if (iVar6 != 0) {
    FUN_006438f0(iVar6);
  }
  local_18 = 0;
  if (*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x108) >> 2 != 0) {
    do {
      uVar8 = local_18;
      if ((DAT_00fb93b8 & 1) == 0) {
        DAT_00fb93b8 = DAT_00fb93b8 | 1;
        local_8 = 0;
        DAT_00fb93c4 = 0;
        iVar6 = FUN_00891268(0x18,uVar5);
        if (iVar6 == 0) {
          local_24 = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_24);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        DAT_00fb93c0 = iVar6;
        *(int *)iVar6 = iVar6;
        *(int *)(DAT_00fb93c0 + 4) = DAT_00fb93c0;
        *(int *)(DAT_00fb93c0 + 8) = DAT_00fb93c0;
        *(undefined1 *)(DAT_00fb93c0 + 0x14) = 1;
        *(undefined1 *)(DAT_00fb93c0 + 0x15) = 1;
        _atexit(FUN_00bcd5a0);
        local_8 = 0xffffffff;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0xf4) + 0xcc);
      local_1c = **(int **)(*(int *)(param_1 + 0x108) + uVar8 * 4);
      if ((piVar1 == (int *)0x0) || ((int *)piVar1[0x29] == (int *)0x0)) {
LAB_00449e00:
        piVar7 = (int *)0x0;
      }
      else {
        iVar6 = *(int *)piVar1[0x29];
        if (piVar1[0x2e] == piVar1[0x2f]) {
          piVar7 = (int *)(**(code **)(iVar6 + 0x28))();
        }
        else {
          piVar7 = *(int **)(piVar1[0x2f] + -4);
          (**(code **)(iVar6 + 0x2c))(piVar7);
          if (piVar1[0x2e] != piVar1[0x2f]) {
            piVar1[0x2f] = piVar1[0x2f] + -4;
          }
        }
        piVar7[8] = local_1c;
        local_14 = piVar7;
        (**(code **)(*piVar1 + 0x70))(piVar7);
        ppiVar4 = (int **)piVar1[0x2b];
        if (&local_14 < ppiVar4) {
          if (&local_14 < (int **)piVar1[0x2a]) goto LAB_00449d90;
          local_20 = (int)&local_14 - piVar1[0x2a] >> 2;
          if (ppiVar4 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] = *(undefined4 *)(piVar1[0x2a] + local_20 * 4);
          }
        }
        else {
LAB_00449d90:
          if (ppiVar4 == (int **)piVar1[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar1[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar1[0x2b] = piVar7;
          }
        }
        piVar1[0x2b] = piVar1[0x2b] + 4;
        uVar8 = local_1c + 1U;
        if (local_1c + 1U <= (uint)piVar1[0x39]) {
          uVar8 = piVar1[0x39];
        }
        piVar1[0x39] = uVar8;
        iVar6 = (**(code **)(*piVar7 + 4))();
        uVar8 = local_18;
        if (iVar6 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          uVar8 = local_18;
          goto LAB_00449e00;
        }
      }
      FUN_00448740(piVar7);
      (**(code **)(*(int *)piVar7[0x93] + 0x94))
                (*(char *)(*(int *)(*(int *)(param_1 + 0x108) + uVar8 * 4) + 9) != '\0');
      (**(code **)(*(int *)piVar7[0x93] + 200))();
      (**(code **)(*piVar7 + 200))();
      local_18 = uVar8 + 1;
    } while (local_18 < (uint)(*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x108) >> 2));
  }
  piVar1 = *(int **)(param_1 + 0xf4);
  puVar2 = (undefined4 *)piVar1[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar6 = puVar3[2];
    if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  ExceptionList = local_10;
  return;
}

