
/* WARNING: Removing unreachable block (ram,0x007b9f90) */
/* WARNING: Removing unreachable block (ram,0x007b9f97) */
/* WARNING: Removing unreachable block (ram,0x007b9fa0) */
/* WARNING: Removing unreachable block (ram,0x007b9fa2) */

void FUN_007b9ab0(uint param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar5 = param_1;
  puStack_c = &LAB_00938015;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  puVar7 = (undefined4 *)FUN_007b88a0();
  FUN_00823850();
  uVar10 = DAT_00fe3284 & 1;
  *puVar7 = 0;
  if (uVar10 == 0) {
    DAT_00fe3284 = DAT_00fe3284 | 1;
    local_8 = 1;
    FUN_007df1e0();
    _atexit((_func_4879 *)&LAB_00bd0ad0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fe328c != (undefined4 *)0x0) {
    (**(code **)*DAT_00fe328c)(1);
    DAT_00fe328c = (undefined4 *)0x0;
  }
  if (*(undefined4 **)(param_1 + 0x8c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x8c))(1);
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  FUN_007e0ba0();
  piVar11 = *(int **)(param_1 + 0x68);
  if ((piVar11 != (int *)0x0) && (*piVar11 == 2)) {
    *piVar11 = 1;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 0x24);
    piVar11 = *(int **)(iVar3 + 8);
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 8))(piVar11);
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_007e5c70(*(undefined4 *)(param_1 + 0x40));
  }
  FUN_007e0be0();
  piVar11 = (int *)(param_1 + 0xa8);
  piVar1 = (int *)(param_1 + 0xa4);
  param_1 = 0;
  if (*piVar11 - *piVar1 >> 2 != 0) {
    do {
      iVar3 = *(int *)(*(int *)(iVar5 + 0xa4) + param_1 * 4);
      iVar8 = *(int *)(iVar3 + 0x34);
      if (iVar8 != 0) {
        FUN_007d7300();
        FUN_0089120c(iVar8);
        *(undefined4 *)(iVar3 + 0x34) = 0;
      }
      if (*(int *)(*(int *)(iVar5 + 0xa4) + param_1 * 4) != 0) {
        iVar3 = *(int *)(*(int *)(iVar5 + 0xa4) + param_1 * 4);
        if (iVar3 != 0) {
          iVar8 = *(int *)(iVar3 + 0x34);
          if (iVar8 != 0) {
            FUN_007d7300();
            FUN_0089120c(iVar8);
            *(undefined4 *)(iVar3 + 0x34) = 0;
          }
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            FUN_0089120c(*(undefined4 *)(iVar3 + 0x14));
          }
          *(undefined4 *)(iVar3 + 0x28) = 0xf;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined1 *)(iVar3 + 0x14) = 0;
          FUN_0089120c(iVar3);
        }
        *(undefined4 *)(*(int *)(iVar5 + 0xa4) + param_1 * 4) = 0;
      }
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(iVar5 + 0xa8) - *(int *)(iVar5 + 0xa4) >> 2));
  }
  pvVar4 = *(void **)(iVar5 + 0xa4);
  if (pvVar4 != *(void **)(iVar5 + 0xa8)) {
    FID_conflict__memcpy(pvVar4,*(void **)(iVar5 + 0xa8),0);
    *(void **)(iVar5 + 0xa8) = pvVar4;
  }
  FUN_007e2fc0(iVar5 + 0x90);
  FUN_007e2d40(iVar5 + 0x90);
  uVar10 = 0;
  if (*(int *)(iVar5 + 0x80) - *(int *)(iVar5 + 0x7c) >> 2 != 0) {
    do {
      FUN_007e4260(*(undefined4 *)(*(int *)(iVar5 + 0x7c) + uVar10 * 4));
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(*(int *)(iVar5 + 0x80) - *(int *)(iVar5 + 0x7c) >> 2));
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x68) + 4) = 1;
  piVar11 = (int *)**(int **)(iVar5 + 0x70);
  if (piVar11 != *(int **)(iVar5 + 0x70)) {
    do {
      iVar3 = piVar11[10];
      if (iVar3 != 0) {
        FUN_007e32a0(iVar3);
        FUN_0089120c(iVar3);
        piVar11[10] = 0;
      }
      if (*(char *)((int)piVar11 + 0x2d) == '\0') {
        piVar1 = (int *)piVar11[2];
        if (*(char *)((int)piVar1 + 0x2d) == '\0') {
          cVar2 = *(char *)(*piVar1 + 0x2d);
          piVar11 = piVar1;
          piVar1 = (int *)*piVar1;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar1 + 0x2d);
            piVar11 = piVar1;
            piVar1 = (int *)*piVar1;
          }
        }
        else {
          cVar2 = *(char *)(piVar11[1] + 0x2d);
          piVar6 = (int *)piVar11[1];
          piVar1 = piVar11;
          while ((piVar11 = piVar6, cVar2 == '\0' && (piVar1 == (int *)piVar11[2]))) {
            cVar2 = *(char *)(piVar11[1] + 0x2d);
            piVar6 = (int *)piVar11[1];
            piVar1 = piVar11;
          }
        }
      }
    } while (piVar11 != *(int **)(iVar5 + 0x70));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(iVar5 + 0x70) + 4));
  *(int *)(*(int *)(iVar5 + 0x70) + 4) = *(int *)(iVar5 + 0x70);
  *(undefined4 *)*(undefined4 *)(iVar5 + 0x70) = *(undefined4 *)(iVar5 + 0x70);
  *(int *)(*(int *)(iVar5 + 0x70) + 8) = *(int *)(iVar5 + 0x70);
  *(undefined4 *)(iVar5 + 0x74) = 0;
  uVar10 = 0;
  if (*(int *)(iVar5 + 0xcc) - *(int *)(iVar5 + 200) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(iVar5 + 200) + uVar10 * 4) != 0) {
        piVar11 = *(int **)(*(int *)(iVar5 + 200) + uVar10 * 4);
        if (piVar11 != (int *)0x0) {
          (**(code **)(*piVar11 + 4))(1);
        }
        *(undefined4 *)(*(int *)(iVar5 + 200) + uVar10 * 4) = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(*(int *)(iVar5 + 0xcc) - *(int *)(iVar5 + 200) >> 2));
  }
  pvVar4 = *(void **)(iVar5 + 200);
  if (pvVar4 != *(void **)(iVar5 + 0xcc)) {
    FID_conflict__memcpy(pvVar4,*(void **)(iVar5 + 0xcc),0);
    *(void **)(iVar5 + 0xcc) = pvVar4;
  }
  if (*(int **)(iVar5 + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x40) + 4))(1);
    *(undefined4 *)(iVar5 + 0x40) = 0;
  }
  FUN_007e0c30(*(undefined4 *)(iVar5 + 0x54));
  iVar3 = *(int *)(iVar5 + 0x54);
  iVar8 = FUN_00891268(0x30);
  local_8 = 2;
  if (iVar8 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = FUN_007f3b20();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(iVar3 + 0xc) = uVar9;
  FUN_007b8f30();
  uVar10 = 0;
  if (*(int *)(iVar5 + 0x80) - *(int *)(iVar5 + 0x7c) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(iVar5 + 0x7c) + uVar10 * 4) != 0) {
        puVar7 = *(undefined4 **)(*(int *)(iVar5 + 0x7c) + uVar10 * 4);
        if (puVar7 != (undefined4 *)0x0) {
          if (puVar7[0x16] != 0) {
            FUN_0089120c(puVar7[0x16]);
          }
          puVar7[0x16] = 0;
          puVar7[0x17] = 0;
          puVar7[0x18] = 0;
          if (0xf < (uint)puVar7[5]) {
            FUN_0089120c(*puVar7);
          }
          puVar7[5] = 0xf;
          puVar7[4] = 0;
          *(undefined1 *)puVar7 = 0;
          FUN_0089120c(puVar7);
        }
        *(undefined4 *)(*(int *)(iVar5 + 0x7c) + uVar10 * 4) = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(*(int *)(iVar5 + 0x80) - *(int *)(iVar5 + 0x7c) >> 2));
  }
  pvVar4 = *(void **)(iVar5 + 0x7c);
  if (pvVar4 != *(void **)(iVar5 + 0x80)) {
    FID_conflict__memcpy(pvVar4,*(void **)(iVar5 + 0x80),0);
    *(void **)(iVar5 + 0x80) = pvVar4;
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if (DAT_00fb7974 != DAT_00fb7978) {
    DAT_00fb7978 = DAT_00fb7974;
  }
  *(undefined4 *)(iVar5 + 0x3c) = 0;
  ExceptionList = local_10;
  return;
}

