
void FUN_006c0500(int param_1)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d8fc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar5 = (int *)(param_1 + 0xa4);
  iVar6 = 8;
  do {
    iVar8 = iVar6;
    if (*(int *)(*piVar5 + 0x60) != 0) {
      FUN_0074a010(*piVar5);
    }
    piVar5 = piVar5 + 1;
    iVar6 = iVar8 + -1;
  } while (iVar6 != 0);
  fVar2 = *(float *)(param_1 + 0xd8);
  if ((1.0 < fVar2) || (*(char *)(param_1 + 0xdc) != '\0')) {
    *(float *)(param_1 + 0xd8) = fVar2 - 0.033333335;
    if (fVar2 - 0.033333335 <= 0.5) {
      *(undefined1 *)(param_1 + 0xdc) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0x3f000000;
    }
  }
  else {
    *(float *)(param_1 + 0xd8) = fVar2 + 0.033333335;
    if (1.0 <= fVar2 + 0.033333335) {
      *(undefined1 *)(param_1 + 0xdc) = 1;
      *(undefined4 *)(param_1 + 0xd8) = 0x3f800000;
      puVar7 = (undefined4 *)(param_1 + 0xa4);
      iVar8 = iVar8 + 7;
      goto LAB_006c05f3;
    }
  }
  puVar7 = (undefined4 *)(param_1 + 0xa4);
  iVar8 = 8;
LAB_006c05f3:
  do {
    (**(code **)(*(int *)*puVar7 + 0xd8))(*(undefined4 *)(param_1 + 0xd8),uVar3);
    (**(code **)(*(int *)*puVar7 + 200))();
    puVar7 = puVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if ((*(uint *)(*(int *)(param_1 + 200) + 0x28) >> 9 & 1) == 0) {
    if ((*(uint *)(*(int *)(param_1 + 0xcc) + 0x28) >> 9 & 1) == 0) {
      ExceptionList = local_10;
      return;
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    iVar8 = DAT_00f947e8;
    iVar6 = *(int *)(param_1 + 0xd4);
    if ((((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
        (iVar4 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar4 == 0xbf6b)) &&
       (iVar6 = *(int *)(iVar6 + 0x94), *(int *)(iVar6 + 0x10) != iVar8)) {
      if (((iVar8 != 0) && (piVar5 = *(int **)(iVar8 + 8), piVar5 != (int *)0x0)) &&
         (piVar5[0x27] = piVar5[0x27] + 1, piVar5[0x27] == 1)) {
        (**(code **)(*piVar5 + 0x24))();
      }
      if ((*(int *)(iVar6 + 0x10) != 0) &&
         (piVar5 = *(int **)(*(int *)(iVar6 + 0x10) + 8), piVar5 != (int *)0x0)) {
        piVar1 = piVar5 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar5 + 0x28))();
        }
      }
      *(int *)(iVar6 + 0x10) = iVar8;
    }
    piVar5 = *(int **)(param_1 + 0xd4);
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = iVar8;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    iVar8 = DAT_00f947e4;
    iVar6 = *(int *)(param_1 + 0xd4);
    if ((((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
        (iVar4 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar4 == 0xbf6b)) &&
       (iVar6 = *(int *)(iVar6 + 0x94), *(int *)(iVar6 + 0x10) != iVar8)) {
      if (((iVar8 != 0) && (piVar5 = *(int **)(iVar8 + 8), piVar5 != (int *)0x0)) &&
         (piVar5[0x27] = piVar5[0x27] + 1, piVar5[0x27] == 1)) {
        (**(code **)(*piVar5 + 0x24))();
      }
      if ((*(int *)(iVar6 + 0x10) != 0) &&
         (piVar5 = *(int **)(*(int *)(iVar6 + 0x10) + 8), piVar5 != (int *)0x0)) {
        piVar1 = piVar5 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar5 + 0x28))();
        }
      }
      *(int *)(iVar6 + 0x10) = iVar8;
    }
    piVar5 = *(int **)(param_1 + 0xd4);
  }
  (**(code **)(*piVar5 + 200))();
  ExceptionList = local_10;
  return;
}

