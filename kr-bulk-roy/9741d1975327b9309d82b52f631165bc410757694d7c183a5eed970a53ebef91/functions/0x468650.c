
void FUN_00468650(int param_1,int *param_2)

{
  uint *puVar1;
  char cVar2;
  int **ppiVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  undefined **local_5c [3];
  undefined **local_50 [3];
  int *local_44;
  int local_40;
  int *local_38;
  int local_34;
  char *local_2c;
  char *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934180;
  local_10 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(char *)(param_1 + 600) = (char)param_2[0x16];
  cVar2 = *(char *)((int)param_2 + 0x59);
  *(char *)(param_1 + 0x259) = cVar2;
  if ((*(char *)(param_1 + 600) == '\0') && (cVar2 == '\0')) {
    (**(code **)(**(int **)(param_1 + 0x250) + 0x94))(0);
    (**(code **)(**(int **)(param_1 + 0x254) + 0x94))(0);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x250) + 0x94))(1,uVar8);
    (**(code **)(**(int **)(param_1 + 0x254) + 0x94))(1);
    (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(*(char *)(param_1 + 600) != '\0');
    (**(code **)(**(int **)(param_1 + 0x254) + 0x90))(*(char *)(param_1 + 0x259) != '\0');
  }
  local_40 = 0;
  local_44 = (int *)FUN_00891268(0x34);
  local_18[1] = local_44;
  if (local_44 == (int *)0x0) {
    local_28 = (char *)0x0;
    std::exception::exception((exception *)local_5c,&local_28);
    local_5c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_5c,&DAT_00c857a8);
  }
  *local_44 = (int)local_44;
  local_44[1] = (int)local_44;
  local_8 = 0;
  local_34 = 0;
  piVar9 = (int *)FUN_00891268(0x34);
  local_20 = piVar9;
  if (piVar9 == (int *)0x0) {
    local_2c = (char *)0x0;
    std::exception::exception((exception *)local_50,&local_2c);
    local_50[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_50,&DAT_00c857a8);
  }
  *piVar9 = (int)piVar9;
  piVar9[1] = (int)piVar9;
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar15 = *(int **)param_2[0x18];
  local_38 = piVar9;
  if (piVar15 != (int *)param_2[0x18]) {
    do {
      piVar11 = local_18[1];
      if ((char)piVar15[0xc] == '\0') {
        iVar13 = FUN_0046ab30(local_18[1],local_18[1][1],piVar15 + 4);
        if (local_40 == 0x5d1745c) goto LAB_0046886d;
        piVar11[1] = iVar13;
        **(int **)(iVar13 + 4) = iVar13;
      }
      else {
        iVar13 = *local_18[1];
        iVar10 = FUN_0046ab30(iVar13,*(undefined4 *)(iVar13 + 4),piVar15 + 4);
        if (local_40 == 0x5d1745c) goto LAB_0046886d;
        *(int *)(iVar13 + 4) = iVar10;
        **(int **)(iVar10 + 4) = iVar10;
      }
      local_40 = local_40 + 1;
      if (*(char *)((int)piVar15 + 0x3d) == '\0') {
        piVar11 = (int *)piVar15[2];
        if (*(char *)((int)piVar11 + 0x3d) == '\0') {
          cVar2 = *(char *)(*piVar11 + 0x3d);
          piVar15 = piVar11;
          piVar11 = (int *)*piVar11;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar11 + 0x3d);
            piVar15 = piVar11;
            piVar11 = (int *)*piVar11;
          }
        }
        else {
          cVar2 = *(char *)(piVar15[1] + 0x3d);
          piVar7 = (int *)piVar15[1];
          piVar11 = piVar15;
          while ((piVar15 = piVar7, cVar2 == '\0' && (piVar11 == (int *)piVar15[2]))) {
            cVar2 = *(char *)(piVar15[1] + 0x3d);
            piVar7 = (int *)piVar15[1];
            piVar11 = piVar15;
          }
        }
      }
    } while (piVar15 != (int *)param_2[0x18]);
  }
  piVar15 = (int *)*local_18[1];
  if (piVar15 != local_18[1]) {
    do {
      if (*(char *)((int)piVar15 + 0x29) == '\0') {
        iVar13 = FUN_0046ab30(piVar9,piVar9[1],piVar15 + 2);
        if (local_34 == 0x5d1745c) {
LAB_0046886d:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        piVar9[1] = iVar13;
        **(int **)(iVar13 + 4) = iVar13;
      }
      else {
        iVar13 = *piVar9;
        iVar10 = FUN_0046ab30(iVar13,*(undefined4 *)(iVar13 + 4),piVar15 + 2);
        if (local_34 == 0x5d1745c) goto LAB_0046886d;
        *(int *)(iVar13 + 4) = iVar10;
        **(int **)(iVar10 + 4) = iVar10;
      }
      piVar15 = (int *)*piVar15;
      local_34 = local_34 + 1;
    } while (piVar15 != local_18[1]);
  }
  local_18[1] = (int *)*local_20;
  if (local_18[1] != local_20) {
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x24c) + 0xcc);
      if (piVar9 == (int *)0x0) {
LAB_00468a5c:
        piVar9 = (int *)0x0;
      }
      else {
        piVar15 = (int *)piVar9[0x29];
        pcVar12 = (char *)piVar9[0x39];
        local_28 = pcVar12;
        if (piVar15 == (int *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          if (piVar9[0x2e] == piVar9[0x2f]) {
            piVar11 = (int *)(**(code **)(*piVar15 + 0x28))();
            local_1c = piVar11;
          }
          else {
            piVar11 = *(int **)(piVar9[0x2f] + -4);
            local_1c = piVar11;
            (**(code **)(*piVar15 + 0x2c))(piVar11);
            if (piVar9[0x2e] != piVar9[0x2f]) {
              piVar9[0x2f] = piVar9[0x2f] + -4;
            }
          }
          piVar11[8] = (int)pcVar12;
          local_18[0] = piVar11;
          (**(code **)(*piVar9 + 0x70))(piVar11);
          ppiVar3 = (int **)piVar9[0x2b];
          puVar1 = (uint *)(piVar9 + 0x2a);
          if ((local_18 < ppiVar3) && (ppiVar4 = (int **)*puVar1, ppiVar4 <= local_18)) {
            local_24 = (int)local_18 - (int)ppiVar4 >> 2;
            if (ppiVar3 == (int **)piVar9[0x2c]) {
              uVar8 = (int)ppiVar3 - (int)ppiVar4 >> 2;
              if (0x3ffffffe < uVar8) {
LAB_00468b7d:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar8 = uVar8 + 1;
              uVar14 = piVar9[0x2c] - (int)ppiVar4 >> 2;
              if (uVar14 < uVar8) {
                if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar8) {
                  uVar14 = uVar8;
                }
                FUN_00797980(uVar14);
              }
            }
            if ((undefined4 *)piVar9[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar9[0x2b] = *(undefined4 *)(*puVar1 + local_24 * 4);
            }
          }
          else {
            if (ppiVar3 == (int **)piVar9[0x2c]) {
              uVar8 = (int)((int)ppiVar3 - *puVar1) >> 2;
              if (0x3ffffffe < uVar8) goto LAB_00468b7d;
              uVar8 = uVar8 + 1;
              uVar14 = (int)(piVar9[0x2c] - *puVar1) >> 2;
              if (uVar14 < uVar8) {
                if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar8) {
                  uVar14 = uVar8;
                }
                FUN_00797980(uVar14);
                piVar11 = local_1c;
              }
            }
            if ((undefined4 *)piVar9[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar9[0x2b] = piVar11;
            }
          }
          piVar9[0x2b] = piVar9[0x2b] + 4;
          pcVar12 = local_28 + 1;
          if (local_28 + 1 <= (char *)piVar9[0x39]) {
            pcVar12 = (char *)piVar9[0x39];
          }
          piVar9[0x39] = (int)pcVar12;
          piVar9 = local_1c;
        }
        if (piVar9 == (int *)0x0) goto LAB_00468a5c;
        iVar13 = (**(code **)(*piVar9 + 4))();
        if (iVar13 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_00468a5c;
        }
      }
      piVar15 = local_18[1];
      FUN_00757800(local_18[1] + 3);
      (**(code **)(*(int *)piVar9[0x94] + 200))();
      piVar9[0x96] = piVar15[2];
      piVar9[0x95] = *param_2;
      *(char *)(piVar9 + 0x97) = (char)piVar15[10];
      *(undefined1 *)((int)piVar9 + 0x25d) = *(undefined1 *)((int)piVar15 + 0x29);
      (**(code **)(*(int *)piVar9[0x92] + 0x94))((char)piVar9[0x97]);
      (**(code **)(*(int *)piVar9[0x93] + 0x94))(*(undefined1 *)((int)piVar9 + 0x25d));
      local_18[1] = (int *)*piVar15;
    } while (local_18[1] != local_20);
  }
  piVar9 = *(int **)(param_1 + 0x24c);
  puVar5 = (undefined4 *)piVar9[0x19];
  for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    iVar13 = puVar6[2];
    if ((*(int *)(iVar13 + 0x60) != 0) && ((*(int **)(iVar13 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar13 + 0x1c) + 0x30))(iVar13);
    }
  }
  (**(code **)(*piVar9 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  FUN_0046aad0(&local_38);
  FUN_0089120c(local_38);
  FUN_0046aad0(&local_44);
  FUN_0089120c(local_44);
  ExceptionList = local_10;
  return;
}

