
void FUN_0062cd40(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  uint *puVar12;
  int iVar13;
  int *local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093851c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce3c0);
    if ((DAT_00fc1724 & 1) == 0) {
      DAT_00fc1724 = DAT_00fc1724 | 1;
      local_8 = 1;
      FUN_006ccd20();
      _atexit((_func_4879 *)&LAB_00bce3c0);
    }
  }
  local_8 = 0xffffffff;
  FUN_006cdb80();
  iVar7 = FUN_006cda20();
  puVar2 = (undefined4 *)param_1[0x48];
  local_14 = (undefined4 *)*puVar2;
  do {
    if (local_14 == puVar2) {
      FUN_0062ccd0();
      ExceptionList = local_10;
      return;
    }
    iVar13 = 0;
    puVar11 = local_14 + 5;
    do {
      pvVar3 = (void *)puVar11[-1];
      if (pvVar3 != (void *)*puVar11) {
        FID_conflict__memcpy(pvVar3,(void *)*puVar11,0);
        *puVar11 = pvVar3;
      }
      (**(code **)(*param_1 + 0x1a0))(puVar11 + -1,local_14[3],iVar13);
      puVar6 = local_14;
      iVar13 = iVar13 + 1;
      puVar11 = puVar11 + 4;
    } while (iVar13 < 3);
    if (iVar7 != 0) {
      pvVar3 = (void *)local_14[0x10];
      puVar12 = local_14 + 0x10;
      if (pvVar3 != (void *)local_14[0x11]) {
        FID_conflict__memcpy(pvVar3,(void *)local_14[0x11],0);
        puVar6[0x11] = pvVar3;
      }
      piVar10 = (int *)**(int **)(iVar7 + 0x44);
      local_1c = piVar10;
      if (piVar10 != *(int **)(iVar7 + 0x44)) {
        do {
          if (piVar10[5] == local_14[3]) {
            local_18 = piVar10[4];
            piVar4 = (int *)puVar6[0x11];
            if ((&local_18 < piVar4) && (piVar5 = (int *)*puVar12, piVar5 <= &local_18)) {
              if (piVar4 == (int *)puVar6[0x12]) {
                uVar8 = (int)piVar4 - (int)piVar5 >> 2;
                if (0x3ffffffe < uVar8) {
LAB_0062d040:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar8 = uVar8 + 1;
                uVar9 = (int)puVar6[0x12] - (int)piVar5 >> 2;
                if (uVar9 < uVar8) {
                  if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = uVar9 + (uVar9 >> 1);
                  }
                  if (uVar9 < uVar8) {
                    uVar9 = uVar8;
                  }
                  FUN_00797980(uVar9);
                  piVar10 = local_1c;
                }
              }
              if ((undefined4 *)puVar6[0x11] != (undefined4 *)0x0) {
                *(undefined4 *)puVar6[0x11] =
                     *(undefined4 *)(*puVar12 + ((int)&local_18 - (int)piVar5 >> 2) * 4);
              }
            }
            else {
              if (piVar4 == (int *)puVar6[0x12]) {
                uVar8 = (int)((int)piVar4 - *puVar12) >> 2;
                if (0x3ffffffe < uVar8) goto LAB_0062d040;
                uVar8 = uVar8 + 1;
                uVar9 = (int)((int)puVar6[0x12] - *puVar12) >> 2;
                if (uVar9 < uVar8) {
                  if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = uVar9 + (uVar9 >> 1);
                  }
                  if (uVar9 < uVar8) {
                    uVar9 = uVar8;
                  }
                  FUN_00797980(uVar9);
                }
              }
              if ((int *)puVar6[0x11] != (int *)0x0) {
                *(int *)puVar6[0x11] = local_18;
              }
            }
            puVar6[0x11] = puVar6[0x11] + 4;
          }
          if (*(char *)((int)piVar10 + 0x19) == '\0') {
            piVar4 = (int *)piVar10[2];
            if (*(char *)((int)piVar4 + 0x19) == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x19);
              piVar10 = piVar4;
              piVar4 = (int *)*piVar4;
              while (local_1c = piVar10, cVar1 == '\0') {
                cVar1 = *(char *)(*piVar4 + 0x19);
                piVar10 = piVar4;
                piVar4 = (int *)*piVar4;
              }
            }
            else {
              cVar1 = *(char *)(piVar10[1] + 0x19);
              piVar5 = (int *)piVar10[1];
              piVar4 = piVar10;
              while ((piVar10 = piVar5, local_1c = piVar10, cVar1 == '\0' &&
                     (piVar4 == (int *)piVar10[2]))) {
                cVar1 = *(char *)(piVar10[1] + 0x19);
                piVar5 = (int *)piVar10[1];
                piVar4 = piVar10;
              }
            }
          }
        } while (piVar10 != *(int **)(iVar7 + 0x44));
      }
    }
    if (*(char *)((int)local_14 + 0x89) == '\0') {
      puVar11 = (undefined4 *)local_14[2];
      if (*(char *)((int)puVar11 + 0x89) == '\0') {
        cVar1 = *(char *)((int)*puVar11 + 0x89);
        local_14 = puVar11;
        puVar11 = (undefined4 *)*puVar11;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar11 + 0x89);
          local_14 = puVar11;
          puVar11 = (undefined4 *)*puVar11;
        }
      }
      else {
        cVar1 = *(char *)((int)local_14[1] + 0x89);
        puVar6 = (undefined4 *)local_14[1];
        puVar11 = local_14;
        while ((local_14 = puVar6, cVar1 == '\0' && (puVar11 == (undefined4 *)local_14[2]))) {
          cVar1 = *(char *)((int)local_14[1] + 0x89);
          puVar6 = (undefined4 *)local_14[1];
          puVar11 = local_14;
        }
      }
    }
  } while( true );
}

