
void FUN_0062c870(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  int **ppiVar9;
  int *piVar10;
  int *piVar11;
  int *local_1c;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00935dac;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20(uVar7);
    _atexit((_func_4879 *)&LAB_00bce3c0);
  }
  local_8 = 0xffffffff;
  FUN_006ccfc0();
  local_14 = *(undefined4 **)(param_1 + 0x120);
  puVar2 = (undefined4 *)*local_14;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 1;
    FUN_006ccd20(uVar7);
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  piVar8 = (int *)*DAT_00fc1800;
  piVar11 = DAT_00fc1800;
  if (piVar8 != DAT_00fc1800) {
    do {
      piVar8[5] = 0;
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar11 = (int *)piVar8[2];
        if (*(char *)((int)piVar11 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar11 + 0x19);
          piVar8 = piVar11;
          piVar11 = (int *)*piVar11;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar11 + 0x19);
            piVar8 = piVar11;
            piVar11 = (int *)*piVar11;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar10 = (int *)piVar8[1];
          piVar11 = piVar8;
          while ((piVar8 = piVar10, cVar1 == '\0' && (piVar11 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar10 = (int *)piVar8[1];
            piVar11 = piVar8;
          }
        }
      }
      piVar11 = DAT_00fc1800;
    } while (piVar8 != DAT_00fc1800);
  }
  while (puVar2 != local_14) {
    iVar3 = puVar2[3];
    uVar7 = 0;
    do {
      if (uVar7 < (uint)((int)(puVar2[0x11] - puVar2[0x10]) >> 2)) {
        iVar4 = *(int *)(puVar2[0x10] + uVar7 * 4);
        cVar1 = *(char *)(piVar11[1] + 0x19);
        piVar8 = (int *)piVar11[1];
        local_18 = piVar11;
        while (piVar10 = piVar8, cVar1 == '\0') {
          if (piVar10[3] < iVar4) {
            piVar8 = (int *)piVar10[2];
            piVar10 = local_18;
          }
          else {
            piVar8 = (int *)*piVar10;
          }
          cVar1 = *(char *)((int)piVar8 + 0x19);
          local_18 = piVar10;
        }
        if ((local_18 == piVar11) || (iVar4 < local_18[3])) {
          local_1c = piVar11;
          ppiVar9 = &local_1c;
        }
        else {
          ppiVar9 = &local_18;
        }
        if (*ppiVar9 != piVar11) {
          (*ppiVar9)[5] = iVar3;
          piVar11 = DAT_00fc1800;
        }
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 2);
    if (*(char *)((int)puVar2 + 0x89) == '\0') {
      puVar5 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar5 + 0x89) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x89);
        puVar2 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x89);
          puVar2 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x89);
        puVar6 = (undefined4 *)puVar2[1];
        puVar5 = puVar2;
        while ((puVar2 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x89);
          puVar6 = (undefined4 *)puVar2[1];
          puVar5 = puVar2;
        }
      }
    }
  }
  FUN_0062ccd0();
  ExceptionList = local_10;
  return;
}

