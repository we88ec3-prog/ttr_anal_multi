
void FUN_004696c0(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int **ppiVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  int *local_18;
  int *local_14;
  int *local_10 [3];
  
  iVar7 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
  if ((iVar7 != 0) &&
     (local_10[2] = (int *)FUN_00412c70(*(undefined4 *)(iVar7 + 0xe4)), local_10[2] != (int *)0x0))
  {
    iVar7 = (**(code **)(*local_10[2] + 4))();
    if (iVar7 == 0x12d) goto LAB_0046971a;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_10[2] = (int *)0x0;
LAB_0046971a:
  iVar7 = 0;
  while( true ) {
    iVar9 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
    if (iVar9 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2;
    }
    if (iVar8 <= iVar7) break;
    if ((((iVar9 == 0) || (iVar7 < 0)) ||
        (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= iVar7)) ||
       (piVar13 = *(int **)(*(int *)(iVar9 + 0xa8) + iVar7 * 4), piVar13 == (int *)0x0)) {
LAB_0046979e:
      local_10[0] = (int *)0x0;
      piVar13 = local_10[0];
    }
    else {
      iVar9 = (**(code **)(*piVar13 + 4))();
      if (iVar9 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0046979e;
      }
    }
    local_10[0] = piVar13;
    iVar9 = 0;
    while( true ) {
      iVar8 = *(int *)(local_10[0][0x93] + 0xcc);
      if (iVar8 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = *(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2;
      }
      if (iVar10 <= iVar9) break;
      if (((iVar8 == 0) || (iVar9 < 0)) ||
         ((*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= iVar9 ||
          (piVar13 = *(int **)(*(int *)(iVar8 + 0xa8) + iVar9 * 4), piVar13 == (int *)0x0)))) {
LAB_00469827:
        piVar13 = (int *)0x0;
      }
      else {
        iVar8 = (**(code **)(*piVar13 + 4))();
        if (iVar8 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_00469827;
        }
      }
      if ((char)piVar13[0x97] != '\0') {
        piVar2 = *(int **)(local_10[2][0x93] + 0xcc);
        if (piVar2 == (int *)0x0) {
LAB_00469974:
          piVar14 = (int *)0x0;
        }
        else {
          iVar8 = piVar2[0x39];
          piVar14 = (int *)piVar2[0x29];
          if (piVar14 == (int *)0x0) goto LAB_00469974;
          if (piVar2[0x2e] == piVar2[0x2f]) {
            local_10[1] = (int *)(**(code **)(*piVar14 + 0x28))();
          }
          else {
            local_10[1] = *(int **)(piVar2[0x2f] + -4);
            (**(code **)(*piVar14 + 0x2c))(local_10[1]);
            if (piVar2[0x2e] != piVar2[0x2f]) {
              piVar2[0x2f] = piVar2[0x2f] + -4;
            }
          }
          local_10[1][8] = iVar8;
          local_14 = local_10[1];
          (**(code **)(*piVar2 + 0x70))(local_10[1]);
          ppiVar3 = (int **)piVar2[0x2b];
          if (&local_14 < ppiVar3) {
            ppiVar4 = (int **)piVar2[0x2a];
            if (&local_14 < ppiVar4) goto LAB_0046990e;
            if (ppiVar3 == (int **)piVar2[0x2c]) {
              FUN_004deab0();
            }
            if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar2[0x2b] =
                   *(undefined4 *)(piVar2[0x2a] + ((int)&local_14 - (int)ppiVar4 >> 2) * 4);
            }
          }
          else {
LAB_0046990e:
            if (ppiVar3 == (int **)piVar2[0x2c]) {
              FUN_004deab0();
            }
            if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar2[0x2b] = local_10[1];
            }
          }
          piVar14 = local_10[1];
          piVar2[0x2b] = piVar2[0x2b] + 4;
          uVar11 = iVar8 + 1;
          if (uVar11 <= (uint)piVar2[0x39]) {
            uVar11 = piVar2[0x39];
          }
          piVar2[0x39] = uVar11;
          iVar8 = (**(code **)(*local_10[1] + 4))();
          if (iVar8 != 0x12d) {
            MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
            goto LAB_00469974;
          }
        }
        FUN_00757800(piVar13[0x94] + 0xe8);
        (**(code **)(*(int *)piVar14[0x94] + 200))();
        piVar14[0x96] = piVar13[0x96];
        piVar14[0x95] = piVar13[0x95];
        iVar8 = piVar13[0x97];
        *(char *)(piVar14 + 0x97) = (char)iVar8;
        *(undefined1 *)((int)piVar14 + 0x25d) = *(undefined1 *)((int)piVar13 + 0x25d);
        (**(code **)(*(int *)piVar14[0x92] + 0x94))((char)iVar8);
        (**(code **)(*(int *)piVar14[0x93] + 0x94))(*(undefined1 *)((int)piVar14 + 0x25d));
        piVar13 = (int *)local_10[2][0x93];
        puVar5 = (undefined4 *)piVar13[0x19];
        for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
          iVar8 = puVar6[2];
          if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
            (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
          }
        }
        (**(code **)(*piVar13 + 0x128))();
        (**(code **)(*(int *)local_10[2][0x93] + 200))();
      }
      iVar9 = iVar9 + 1;
    }
    iVar7 = iVar7 + 1;
  }
  iVar7 = 0;
  do {
    iVar9 = *(int *)(*(int *)(param_1 + 0x100) + 0xcc);
    if (iVar9 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2;
    }
    if (iVar8 <= iVar7) {
      piVar13 = *(int **)(param_1 + 0xf0);
      puVar5 = (undefined4 *)piVar13[0x19];
      for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
        iVar7 = puVar6[2];
        if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
        }
      }
      (**(code **)(*piVar13 + 0x128))();
      (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
      return;
    }
    if ((((iVar9 == 0) || (iVar7 < 0)) ||
        (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= iVar7)) ||
       (piVar13 = *(int **)(*(int *)(iVar9 + 0xa8) + iVar7 * 4), piVar13 == (int *)0x0)) {
LAB_00469aec:
      local_14 = (int *)0x0;
      piVar13 = local_14;
    }
    else {
      iVar9 = (**(code **)(*piVar13 + 4))();
      if (iVar9 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00469aec;
      }
    }
    local_14 = piVar13;
    iVar9 = 0;
    while( true ) {
      iVar8 = *(int *)(local_14[0x93] + 0xcc);
      if (iVar8 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = *(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2;
      }
      if (iVar10 <= iVar9) break;
      if (((iVar8 == 0) || (iVar9 < 0)) ||
         ((*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= iVar9 ||
          (piVar13 = *(int **)(*(int *)(iVar8 + 0xa8) + iVar9 * 4), piVar13 == (int *)0x0)))) {
LAB_00469b75:
        piVar13 = (int *)0x0;
      }
      else {
        iVar8 = (**(code **)(*piVar13 + 4))();
        if (iVar8 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_00469b75;
        }
      }
      local_10[1] = piVar13;
      if ((char)piVar13[0x97] != '\0') {
        piVar13 = *(int **)(local_10[2][0x93] + 0xcc);
        if (piVar13 == (int *)0x0) {
LAB_00469d23:
          local_18 = (int *)0x0;
        }
        else {
          piVar2 = (int *)piVar13[0x29];
          iVar8 = piVar13[0x39];
          if (piVar2 == (int *)0x0) {
            local_18 = (int *)0x0;
          }
          else {
            if (piVar13[0x2e] == piVar13[0x2f]) {
              local_18 = (int *)(**(code **)(*piVar2 + 0x28))();
            }
            else {
              local_18 = *(int **)(piVar13[0x2f] + -4);
              (**(code **)(*piVar2 + 0x2c))(local_18);
              if (piVar13[0x2e] != piVar13[0x2f]) {
                piVar13[0x2f] = piVar13[0x2f] + -4;
              }
            }
            local_18[8] = iVar8;
            local_10[0] = local_18;
            (**(code **)(*piVar13 + 0x70))(local_18);
            ppiVar3 = (int **)piVar13[0x2b];
            puVar1 = (uint *)(piVar13 + 0x2a);
            if ((local_10 < ppiVar3) && (ppiVar4 = (int **)*puVar1, ppiVar4 <= local_10)) {
              if (ppiVar3 == (int **)piVar13[0x2c]) {
                uVar11 = (int)ppiVar3 - (int)ppiVar4 >> 2;
                if (0x3ffffffe < uVar11) {
LAB_00469e17:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar11 = uVar11 + 1;
                uVar12 = piVar13[0x2c] - (int)ppiVar4 >> 2;
                if (uVar12 < uVar11) {
                  if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = uVar12 + (uVar12 >> 1);
                  }
                  if (uVar12 < uVar11) {
                    uVar12 = uVar11;
                  }
                  FUN_00797980(uVar12);
                }
              }
              if ((undefined4 *)piVar13[0x2b] != (undefined4 *)0x0) {
                *(undefined4 *)piVar13[0x2b] =
                     *(undefined4 *)(*puVar1 + ((int)local_10 - (int)ppiVar4 >> 2) * 4);
              }
            }
            else {
              if (ppiVar3 == (int **)piVar13[0x2c]) {
                uVar11 = (int)((int)ppiVar3 - *puVar1) >> 2;
                if (0x3ffffffe < uVar11) goto LAB_00469e17;
                uVar11 = uVar11 + 1;
                uVar12 = (int)(piVar13[0x2c] - *puVar1) >> 2;
                if (uVar12 < uVar11) {
                  if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = uVar12 + (uVar12 >> 1);
                  }
                  if (uVar12 < uVar11) {
                    uVar12 = uVar11;
                  }
                  FUN_00797980(uVar12);
                }
              }
              if ((undefined4 *)piVar13[0x2b] != (undefined4 *)0x0) {
                *(undefined4 *)piVar13[0x2b] = local_18;
              }
            }
            piVar13[0x2b] = piVar13[0x2b] + 4;
            uVar11 = iVar8 + 1;
            if (uVar11 <= (uint)piVar13[0x39]) {
              uVar11 = piVar13[0x39];
            }
            piVar13[0x39] = uVar11;
          }
          if (local_18 == (int *)0x0) goto LAB_00469d23;
          iVar8 = (**(code **)(*local_18 + 4))();
          if (iVar8 != 0x12d) {
            MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
            goto LAB_00469d23;
          }
        }
        piVar13 = local_10[1];
        FUN_00757800(local_10[1][0x94] + 0xe8);
        (**(code **)(*(int *)local_18[0x94] + 200))();
        local_18[0x96] = piVar13[0x96];
        local_18[0x95] = piVar13[0x95];
        iVar8 = piVar13[0x97];
        *(char *)(local_18 + 0x97) = (char)iVar8;
        *(undefined1 *)((int)local_18 + 0x25d) = *(undefined1 *)((int)piVar13 + 0x25d);
        (**(code **)(*(int *)local_18[0x92] + 0x94))((char)iVar8);
        (**(code **)(*(int *)local_18[0x93] + 0x94))(*(undefined1 *)((int)local_18 + 0x25d));
        piVar13 = (int *)local_10[2][0x93];
        puVar5 = (undefined4 *)piVar13[0x19];
        for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
          iVar8 = puVar6[2];
          if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
            (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
          }
        }
        (**(code **)(*piVar13 + 0x128))();
        (**(code **)(*(int *)local_10[2][0x93] + 200))();
      }
      iVar9 = iVar9 + 1;
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

