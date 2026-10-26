
void FUN_00468f50(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int **ppiVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined **local_5c [3];
  undefined **local_50 [3];
  undefined4 *local_44;
  int local_40;
  int *local_38;
  int local_34;
  char *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937194;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0;
  local_44 = (undefined4 *)FUN_00891268(0x74,uVar5);
  local_1c[1] = local_44;
  if (local_44 == (undefined4 *)0x0) {
    local_28 = (int *)0x0;
    std::exception::exception((exception *)local_5c,(char **)&local_28);
    local_5c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_5c,&DAT_00c857a8);
  }
  *local_44 = local_44;
  local_44[1] = local_44;
  local_8 = 0;
  local_34 = 0;
  piVar6 = (int *)FUN_00891268(0x74,uVar5);
  local_1c[2] = piVar6;
  if (piVar6 == (int *)0x0) {
    local_2c = (char *)0x0;
    std::exception::exception((exception *)local_50,&local_2c);
    local_50[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_50,&DAT_00c857a8);
  }
  *piVar6 = (int)piVar6;
  piVar6[1] = (int)piVar6;
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar9 = (int *)**(int **)((int)param_2 + 4);
  local_38 = piVar6;
  if (piVar9 != *(int **)((int)param_2 + 4)) {
    do {
      piVar11 = local_1c[1];
      if ((char)piVar9[0x1a] != '\0') {
        piVar11 = (undefined4 *)*local_1c[1];
      }
      iVar7 = FUN_0046ac30(piVar11,piVar11[1],piVar9 + 4);
      if (local_40 == 0x25ed096) goto LAB_0046908f;
      local_40 = local_40 + 1;
      piVar11[1] = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
      if (*(char *)((int)piVar9 + 0x7d) == '\0') {
        piVar11 = (int *)piVar9[2];
        if (*(char *)((int)piVar11 + 0x7d) == '\0') {
          cVar1 = *(char *)(*piVar11 + 0x7d);
          piVar9 = piVar11;
          piVar11 = (int *)*piVar11;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar11 + 0x7d);
            piVar9 = piVar11;
            piVar11 = (int *)*piVar11;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x7d);
          piVar14 = (int *)piVar9[1];
          piVar11 = piVar9;
          while ((piVar9 = piVar14, cVar1 == '\0' && (piVar11 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x7d);
            piVar14 = (int *)piVar9[1];
            piVar11 = piVar9;
          }
        }
      }
    } while (piVar9 != *(int **)((int)param_2 + 4));
  }
  puVar15 = (undefined4 *)*local_1c[1];
  if (puVar15 != local_1c[1]) {
    do {
      if (*(char *)((int)puVar15 + 0x61) == '\0') {
        iVar7 = FUN_0046ac30(piVar6,piVar6[1],puVar15 + 2);
        if (local_34 == 0x25ed096) {
LAB_0046908f:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        piVar6[1] = iVar7;
      }
      else {
        iVar2 = *piVar6;
        iVar7 = FUN_0046ac30(iVar2,*(undefined4 *)(iVar2 + 4),puVar15 + 2);
        if (local_34 == 0x25ed096) goto LAB_0046908f;
        *(int *)(iVar2 + 4) = iVar7;
      }
      local_34 = local_34 + 1;
      **(int **)(iVar7 + 4) = iVar7;
      puVar15 = (undefined4 *)*puVar15;
    } while (puVar15 != local_1c[1]);
  }
  local_20 = (int *)*piVar6;
  if (local_20 != piVar6) {
    do {
      iVar7 = FUN_0044df20(0,&DAT_00bffde4,3);
      if (iVar7 == 0) {
        piVar6 = *(int **)(*(int *)(param_1 + 0xfc) + 0xcc);
        if (piVar6 == (int *)0x0) goto LAB_004694f0;
        piVar9 = (int *)piVar6[0x39];
        local_28 = piVar9;
        if ((int *)piVar6[0x29] == (int *)0x0) goto LAB_004694c6;
        iVar7 = *(int *)piVar6[0x29];
        if (piVar6[0x2e] == piVar6[0x2f]) {
          param_2 = (int *)(**(code **)(iVar7 + 0x28))();
        }
        else {
          param_2 = *(int **)(piVar6[0x2f] + -4);
          (**(code **)(iVar7 + 0x2c))(param_2);
          if (piVar6[0x2e] != piVar6[0x2f]) {
            piVar6[0x2f] = piVar6[0x2f] + -4;
          }
        }
        param_2[8] = (int)piVar9;
        local_1c[0] = param_2;
        (**(code **)(*piVar6 + 0x70))(param_2);
        ppiVar8 = (int **)piVar6[0x2b];
        puVar13 = (uint *)(piVar6 + 0x2a);
        if ((local_1c < ppiVar8) && (ppiVar3 = (int **)*puVar13, ppiVar3 <= local_1c)) {
          local_24 = (int *)((int)local_1c - (int)ppiVar3 >> 2);
          if (ppiVar8 == (int **)piVar6[0x2c]) {
            uVar5 = (int)ppiVar8 - (int)ppiVar3 >> 2;
            if (0x3ffffffe < uVar5) goto LAB_00469647;
            uVar5 = uVar5 + 1;
            uVar10 = piVar6[0x2c] - (int)ppiVar3 >> 2;
            if (uVar10 < uVar5) {
              if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar5) {
                uVar10 = uVar5;
              }
              FUN_00797980(uVar10);
            }
          }
          piVar9 = local_28;
          if ((undefined4 *)piVar6[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar6[0x2b] = *(undefined4 *)(*puVar13 + (int)local_24 * 4);
          }
        }
        else {
          if (ppiVar8 == (int **)piVar6[0x2c]) {
            uVar5 = (int)((int)ppiVar8 - *puVar13) >> 2;
            if (0x3ffffffe < uVar5) goto LAB_00469647;
            uVar5 = uVar5 + 1;
            uVar10 = (int)(piVar6[0x2c] - *puVar13) >> 2;
            if (uVar10 < uVar5) {
              if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar5) {
                uVar10 = uVar5;
              }
              FUN_00797980(uVar10);
            }
          }
          piVar9 = local_28;
          if ((undefined4 *)piVar6[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar6[0x2b] = param_2;
          }
        }
LAB_004694aa:
        puVar13[1] = puVar13[1] + 4;
        uVar5 = (int)piVar9 + 1U;
        if ((int)piVar9 + 1U <= (uint)piVar6[0x39]) {
          uVar5 = piVar6[0x39];
        }
        piVar6[0x39] = uVar5;
LAB_004694c8:
        if (param_2 == (int *)0x0) goto LAB_004694f0;
        iVar7 = (**(code **)(*param_2 + 4))();
        if (iVar7 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_004694f0;
        }
      }
      else {
        iVar7 = FUN_0044df20(0,L"telecom",7);
        if (iVar7 == 0) {
          piVar6 = *(int **)(*(int *)(param_1 + 0x100) + 0xcc);
          if (piVar6 != (int *)0x0) {
            piVar9 = (int *)piVar6[0x29];
            piVar11 = (int *)piVar6[0x39];
            local_24 = piVar11;
            if (piVar9 != (int *)0x0) {
              if (piVar6[0x2e] == piVar6[0x2f]) {
                param_2 = (int *)(**(code **)(*piVar9 + 0x28))();
              }
              else {
                param_2 = *(int **)(piVar6[0x2f] + -4);
                (**(code **)(*piVar9 + 0x2c))(param_2);
                if (piVar6[0x2e] != piVar6[0x2f]) {
                  piVar6[0x2f] = piVar6[0x2f] + -4;
                }
              }
              param_2[8] = (int)piVar11;
              local_1c[0] = param_2;
              (**(code **)(*piVar6 + 0x70))(param_2);
              ppiVar8 = (int **)piVar6[0x2b];
              puVar13 = (uint *)(piVar6 + 0x2a);
              if ((ppiVar8 <= local_1c) || (ppiVar3 = (int **)*puVar13, local_1c < ppiVar3)) {
LAB_00469458:
                if (ppiVar8 == (int **)puVar13[2]) {
                  uVar5 = (int)((int)ppiVar8 - *puVar13) >> 2;
                  if (0x3ffffffe < uVar5) {
LAB_00469647:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar5 = uVar5 + 1;
                  uVar10 = (int)((int)puVar13[2] - *puVar13) >> 2;
                  if (uVar10 < uVar5) {
                    if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                      uVar10 = 0;
                    }
                    else {
                      uVar10 = uVar10 + (uVar10 >> 1);
                    }
                    if (uVar10 < uVar5) {
                      uVar10 = uVar5;
                    }
                    FUN_00797980(uVar10);
                  }
                }
                piVar9 = local_24;
                if ((undefined4 *)puVar13[1] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar13[1] = param_2;
                  piVar9 = local_24;
                }
                goto LAB_004694aa;
              }
              local_28 = (int *)((int)local_1c - (int)ppiVar3 >> 2);
              if (ppiVar8 == (int **)piVar6[0x2c]) {
                uVar5 = (int)ppiVar8 - (int)ppiVar3 >> 2;
                if (0x3ffffffe < uVar5) goto LAB_00469647;
                uVar5 = uVar5 + 1;
                uVar10 = piVar6[0x2c] - (int)ppiVar3 >> 2;
                if (uVar10 < uVar5) {
                  uVar12 = uVar10 >> 1;
                  if (0x3fffffff - uVar12 < uVar10) {
                    uVar10 = 0;
                  }
                  else {
LAB_00469433:
                    uVar10 = uVar10 + uVar12;
                  }
LAB_00469435:
                  if (uVar10 < uVar5) {
                    uVar10 = uVar5;
                  }
                  FUN_00797980(uVar10);
                }
              }
LAB_00469443:
              piVar9 = local_24;
              if ((undefined4 *)puVar13[1] != (undefined4 *)0x0) {
                *(undefined4 *)puVar13[1] = *(undefined4 *)(*puVar13 + (int)local_28 * 4);
                piVar9 = local_24;
              }
              goto LAB_004694aa;
            }
LAB_004694c6:
            param_2 = (int *)0x0;
            goto LAB_004694c8;
          }
        }
        else {
          piVar6 = *(int **)(*(int *)(param_1 + 0xf8) + 0xcc);
          if (piVar6 != (int *)0x0) {
            piVar9 = (int *)piVar6[0x29];
            piVar11 = (int *)piVar6[0x39];
            local_24 = piVar11;
            if (piVar9 != (int *)0x0) {
              if (piVar6[0x2e] == piVar6[0x2f]) {
                param_2 = (int *)(**(code **)(*piVar9 + 0x28))();
              }
              else {
                param_2 = *(int **)(piVar6[0x2f] + -4);
                (**(code **)(*piVar9 + 0x2c))(param_2);
                if (piVar6[0x2e] != piVar6[0x2f]) {
                  piVar6[0x2f] = piVar6[0x2f] + -4;
                }
              }
              param_2[8] = (int)piVar11;
              local_1c[0] = param_2;
              (**(code **)(*piVar6 + 0x70))(param_2);
              ppiVar8 = (int **)piVar6[0x2b];
              puVar13 = (uint *)(piVar6 + 0x2a);
              if ((ppiVar8 <= local_1c) || (ppiVar3 = (int **)*puVar13, local_1c < ppiVar3))
              goto LAB_00469458;
              local_28 = (int *)((int)local_1c - (int)ppiVar3 >> 2);
              if (ppiVar8 == (int **)piVar6[0x2c]) {
                uVar5 = (int)ppiVar8 - (int)ppiVar3 >> 2;
                if (0x3ffffffe < uVar5) goto LAB_00469647;
                uVar5 = uVar5 + 1;
                uVar10 = piVar6[0x2c] - (int)ppiVar3 >> 2;
                if (uVar10 < uVar5) {
                  uVar12 = uVar10 >> 1;
                  if (uVar10 <= 0x3fffffff - uVar12) goto LAB_00469433;
                  uVar10 = 0;
                  goto LAB_00469435;
                }
              }
              goto LAB_00469443;
            }
            goto LAB_004694c6;
          }
        }
LAB_004694f0:
        param_2 = (int *)0x0;
      }
      piVar6 = local_1c[2];
      piVar9 = local_20;
      FUN_00468650(param_2,local_20 + 2);
      FUN_00757800(piVar9 + 3);
      (**(code **)(*(int *)param_2[0x92] + 200))();
      local_20 = (int *)*local_20;
    } while (local_20 != piVar6);
  }
  param_2 = (int *)(param_1 + 0xf0);
  local_20 = (int *)0x5;
  do {
    piVar9 = (int *)*param_2;
    piVar11 = (int *)piVar9[0x19];
    piVar14 = (int *)*piVar11;
    local_28 = piVar11;
    if (piVar14 != piVar11) {
      do {
        iVar7 = piVar14[2];
        if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
          piVar11 = local_28;
        }
        piVar14 = (int *)*piVar14;
      } while (piVar14 != piVar11);
    }
    (**(code **)(*piVar9 + 0x128))();
    (**(code **)(*(int *)*param_2 + 200))();
    param_2 = param_2 + 1;
    local_20 = (int *)((int)local_20 + -1);
  } while (local_20 != (int *)0x0);
  FUN_004696c0(param_1);
  FUN_00469e80(param_1);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar9 = (int *)*piVar6;
  *piVar6 = (int)piVar6;
  piVar6[1] = (int)piVar6;
  local_34 = 0;
  while (piVar9 != piVar6) {
    piVar11 = (int *)*piVar9;
    FUN_004012f0(piVar9 + 2);
    FUN_0089120c(piVar9);
    piVar9 = piVar11;
  }
  FUN_0089120c(piVar6);
  piVar6 = local_1c[1];
  local_8 = 3;
  puVar15 = (undefined4 *)*local_1c[1];
  *local_1c[1] = (int)local_1c[1];
  local_1c[1][1] = (int)local_1c[1];
  local_40 = 0;
  while (puVar15 != piVar6) {
    puVar4 = (undefined4 *)*puVar15;
    FUN_004012f0(puVar15 + 2);
    FUN_0089120c(puVar15);
    puVar15 = puVar4;
  }
  FUN_0089120c(piVar6);
  ExceptionList = local_10;
  return;
}

