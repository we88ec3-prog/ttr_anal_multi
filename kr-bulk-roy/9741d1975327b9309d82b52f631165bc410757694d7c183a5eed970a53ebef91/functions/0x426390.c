
void FUN_00426390(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int **ppiVar4;
  int **ppiVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 **ppuVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *local_24;
  undefined4 *local_20;
  int local_1c;
  int *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931d9e;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar11 = *(int *)(*(int *)(param_1 + 0x104) + 0xcc);
  if (iVar11 != 0) {
    FUN_006438f0(iVar11);
  }
  local_1c = 0;
  puVar15 = DAT_00fb732c;
  do {
    iVar11 = local_1c;
    bVar12 = (byte)local_1c;
    if ((*(byte *)(param_1 + 0x10c) & (byte)(1 << (bVar12 & 0x1f))) != 0) {
      if ((DAT_00fb7324 & 1) == 0) {
        DAT_00fb7324 = DAT_00fb7324 | 1;
        local_8 = 0;
        FUN_0081b920(uVar6);
        _atexit((_func_4879 *)&LAB_00bcd080);
        local_8 = 0xffffffff;
        puVar15 = DAT_00fb732c;
      }
      cVar1 = *(char *)((int)puVar15[1] + 0x41);
      puVar7 = (undefined4 *)puVar15[1];
      local_20 = puVar15;
      while (puVar13 = puVar7, cVar1 == '\0') {
        if (*(byte *)(puVar13 + 3) < bVar12) {
          puVar7 = (undefined4 *)puVar13[2];
          puVar13 = local_20;
        }
        else {
          puVar7 = (undefined4 *)*puVar13;
        }
        cVar1 = *(char *)((int)puVar7 + 0x41);
        local_20 = puVar13;
      }
      if ((local_20 == puVar15) || (bVar12 < *(byte *)(local_20 + 3))) {
        local_24 = puVar15;
        ppuVar8 = &local_24;
      }
      else {
        ppuVar8 = &local_20;
      }
      puVar7 = *ppuVar8;
      if (((puVar7 != puVar15) && (local_20 = puVar7 + 4, local_20 != (undefined4 *)0x0)) &&
         (piVar14 = *(int **)puVar7[0xd], iVar11 = local_1c, local_18[1] = piVar14,
         (int *)puVar7[0xd] != piVar14)) {
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x104) + 0xcc);
          iVar11 = piVar14[5];
          if ((piVar2 == (int *)0x0) || ((int *)piVar2[0x29] == (int *)0x0)) {
LAB_004265ba:
            piVar9 = (int *)0x0;
          }
          else {
            iVar3 = *(int *)piVar2[0x29];
            if (piVar2[0x2e] == piVar2[0x2f]) {
              piVar9 = (int *)(**(code **)(iVar3 + 0x28))();
            }
            else {
              piVar9 = *(int **)(piVar2[0x2f] + -4);
              (**(code **)(iVar3 + 0x2c))(piVar9);
              if (piVar2[0x2e] != piVar2[0x2f]) {
                piVar2[0x2f] = piVar2[0x2f] + -4;
              }
            }
            piVar9[8] = iVar11;
            local_18[0] = piVar9;
            (**(code **)(*piVar2 + 0x70))(piVar9);
            ppiVar4 = (int **)piVar2[0x2b];
            if (local_18 < ppiVar4) {
              ppiVar5 = (int **)piVar2[0x2a];
              if (local_18 < ppiVar5) goto LAB_00426550;
              if (ppiVar4 == (int **)piVar2[0x2c]) {
                FUN_004deab0();
              }
              if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
                *(undefined4 *)piVar2[0x2b] =
                     *(undefined4 *)(piVar2[0x2a] + ((int)local_18 - (int)ppiVar5 >> 2) * 4);
              }
            }
            else {
LAB_00426550:
              if (ppiVar4 == (int **)piVar2[0x2c]) {
                FUN_004deab0();
              }
              if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
                *(undefined4 *)piVar2[0x2b] = piVar9;
              }
            }
            piVar2[0x2b] = piVar2[0x2b] + 4;
            uVar10 = iVar11 + 1;
            if (uVar10 <= (uint)piVar2[0x39]) {
              uVar10 = piVar2[0x39];
            }
            piVar2[0x39] = uVar10;
            iVar11 = (**(code **)(*piVar9 + 4))();
            piVar14 = local_18[1];
            if (iVar11 != 0x12d) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              piVar14 = local_18[1];
              goto LAB_004265ba;
            }
          }
          FUN_00425920(piVar9,piVar14 + 4);
          (**(code **)(*(int *)piVar9[0x93] + 0x94))(0);
          (**(code **)(*(int *)piVar9[0x93] + 200))();
          (**(code **)(*piVar9 + 200))();
          if (*(char *)((int)piVar14 + 0x45) == '\0') {
            piVar2 = (int *)piVar14[2];
            if (*(char *)((int)piVar2 + 0x45) == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x45);
              piVar14 = piVar2;
              piVar2 = (int *)*piVar2;
              while (local_18[1] = piVar14, cVar1 == '\0') {
                cVar1 = *(char *)(*piVar2 + 0x45);
                piVar14 = piVar2;
                piVar2 = (int *)*piVar2;
              }
            }
            else {
              cVar1 = *(char *)(piVar14[1] + 0x45);
              piVar9 = (int *)piVar14[1];
              piVar2 = piVar14;
              while ((piVar14 = piVar9, local_18[1] = piVar14, cVar1 == '\0' &&
                     (piVar2 == (int *)piVar14[2]))) {
                cVar1 = *(char *)(piVar14[1] + 0x45);
                piVar9 = (int *)piVar14[1];
                piVar2 = piVar14;
              }
            }
          }
          iVar11 = local_1c;
          puVar15 = DAT_00fb732c;
        } while ((int *)local_20[9] != piVar14);
      }
    }
    local_1c = iVar11 + 1;
    if (7 < local_1c) {
      piVar14 = *(int **)(param_1 + 0x104);
      puVar15 = (undefined4 *)piVar14[0x19];
      for (puVar7 = (undefined4 *)*puVar15; puVar7 != puVar15; puVar7 = (undefined4 *)*puVar7) {
        iVar11 = puVar7[2];
        if ((*(int *)(iVar11 + 0x60) != 0) && ((*(int **)(iVar11 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar11 + 0x1c) + 0x30))(iVar11);
        }
      }
      (**(code **)(*piVar14 + 0x128))();
      (**(code **)(**(int **)(param_1 + 0x104) + 200))();
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

