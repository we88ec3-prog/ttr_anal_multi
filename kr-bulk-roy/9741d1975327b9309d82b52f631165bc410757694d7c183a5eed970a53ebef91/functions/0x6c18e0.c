
void FUN_006c18e0(int param_1)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  int local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942458;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_20 = DAT_00f9392c;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar3 = DAT_00f93930;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_24 = uVar3;
  FUN_008438c0(&local_24);
  if (local_28 == DAT_00fab14c) {
    local_2c = 0;
  }
  else {
    local_2c = *(int *)(local_28 + 0x10);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  local_24 = *(uint *)(param_1 + 0xb4);
  FUN_008438c0(&local_24);
  if (local_28 == DAT_00fab14c) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = *(int **)(local_28 + 0x10);
  }
  if (local_2c == 0) {
    ExceptionList = local_14;
    return;
  }
  switch(local_20) {
  case (int *)0x2:
  case (int *)0x4:
  case (int *)0x6:
  case (int *)0x9:
  case (int *)0xb:
    FUN_006c68c0();
    FUN_006c6af0();
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_1c = *(int **)(iVar4 + 0x5eac);
      piVar11 = local_1c;
      do {
        if (*(int *)(*piVar11 + 8) == iVar5) {
          iVar5 = local_1c[uVar7];
          goto LAB_006c2231;
        }
        uVar7 = uVar7 + 1;
        piVar11 = piVar11 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c2231:
    iVar4 = *(int *)(param_1 + 0xb4);
    local_20 = (int *)(uint)(iVar5 != 0);
    iVar5 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar5 + 0x5ec0) - *(int *)(iVar5 + 0x5ebc) >> 2;
    if (uVar3 != 0) {
      local_1c = *(int **)(iVar5 + 0x5ebc);
      piVar11 = local_1c;
      do {
        if (*(int *)(*piVar11 + 4) == iVar4) {
          iVar5 = local_1c[uVar7];
          goto LAB_006c2279;
        }
        uVar7 = uVar7 + 1;
        piVar11 = piVar11 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c2279:
    if (local_20 != (int *)0x0) {
      FUN_006c7760();
      ExceptionList = local_14;
      return;
    }
    if (iVar5 != 0) {
      FUN_006c7880();
      ExceptionList = local_14;
      return;
    }
    FUN_006c75e0(param_1);
    ExceptionList = local_14;
    return;
  case (int *)0x3:
  case (int *)0x8:
    FUN_006c68c0();
    uVar9 = CONCAT31(0xffffff,piVar11 != (int *)0x0);
    FUN_006c69c0(uVar9);
    FUN_006c6af0();
    FUN_006c6c10(uVar9);
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0044fd50();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar5) {
          local_28 = local_20[uVar7];
          goto LAB_006c1d5d;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    local_28 = 0;
LAB_006c1d5d:
    iVar5 = FUN_0044fd50();
    if (((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_28 == 0)) &&
         (iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0)) &&
        (iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0)) &&
       ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 4) != 0)))) {
      FUN_006c6da0();
    }
    if (piVar11 != (int *)0x0) {
      if (*(char *)(local_2c + 0x28) == '\0') {
        if ((*(short *)(local_2c + 0x14) == 0) && ((short)piVar11[5] == 0)) {
          FUN_006c7dc0(param_1);
        }
      }
      else if (*(short *)(local_2c + 0x14) == (short)piVar11[5]) {
        FUN_006c72e0();
      }
      else if ((short)piVar11[5] == 0) {
        FUN_006c7040();
      }
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 8) == iVar5) {
          iVar5 = local_20[uVar7];
          goto LAB_006c1e31;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c1e31:
    iVar4 = *(int *)(param_1 + 0xb4);
    local_24 = (uint)(iVar5 != 0);
    iVar5 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar5 + 0x5ec0) - *(int *)(iVar5 + 0x5ebc) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar5 + 0x5ebc);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar4) {
          iVar5 = local_20[uVar7];
          goto LAB_006c1e79;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c1e79:
    if (local_24 == 0) {
      if (iVar5 == 0) {
        FUN_006c75e0(param_1);
      }
      else {
        FUN_006c7880();
      }
    }
    else {
      FUN_006c7760();
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar6 = FUN_0048a3d0();
    iVar4 = *(int *)(iVar6 + 0x5ecc);
    if ((iVar4 == 0) || (*(int *)(iVar4 + 8) != iVar5)) {
      piVar10 = *(int **)(iVar6 + 0x5ed0);
      uVar3 = *(int *)(iVar6 + 0x5ed4) - (int)piVar10 >> 2;
      uVar7 = 0;
      piVar8 = piVar10;
      if (uVar3 != 0) {
        do {
          if (*(int *)(*piVar8 + 8) == iVar5) {
            iVar4 = piVar10[uVar7];
            goto LAB_006c1f02;
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (uVar7 < uVar3);
      }
LAB_006c1f06:
      FUN_006c79a0(param_1);
    }
    else {
LAB_006c1f02:
      if (iVar4 == 0) goto LAB_006c1f06;
    }
    iVar5 = FUN_0044fd50();
    iVar5 = *(int *)(iVar5 + 0x5ec0);
    goto joined_r0x006c21d5;
  case (int *)0x5:
    cVar1 = '\0';
    iVar5 = FUN_0041a4d0();
    if ((*(int *)(iVar5 + 0x5ed8) != 0) &&
       (iVar5 = FUN_00539aa0(*(undefined4 *)(param_1 + 0xb4)), iVar5 != 0)) {
      cVar1 = *(char *)(iVar5 + 7);
    }
    FUN_006c68c0();
    uVar9 = CONCAT31(0xffffff,piVar11 != (int *)0x0);
    FUN_006c69c0(uVar9);
    FUN_006c6af0();
    if (cVar1 == '\0') {
      FUN_006c6c10(uVar9);
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0044fd50();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar5) {
          local_24 = local_20[uVar7];
          goto LAB_006c200a;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    local_24 = 0;
LAB_006c200a:
    iVar5 = FUN_0044fd50();
    if ((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_24 == 0)) &&
        (iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0)) &&
       ((iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0 &&
        ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 4) != 0)))))) {
      FUN_006c6da0();
    }
    if (piVar11 != (int *)0x0) {
      if (*(char *)(local_2c + 0x28) == '\0') {
        if ((*(short *)(local_2c + 0x14) == 0) && ((short)piVar11[5] == 0)) {
          FUN_006c7dc0(param_1);
        }
      }
      else if (*(short *)(local_2c + 0x14) == (short)piVar11[5]) {
        FUN_006c72e0();
      }
      else if ((short)piVar11[5] == 0) {
        FUN_006c7040();
      }
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 8) == iVar5) {
          iVar5 = local_20[uVar7];
          goto LAB_006c20e1;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c20e1:
    iVar4 = *(int *)(param_1 + 0xb4);
    local_1c = (int *)(uint)(iVar5 != 0);
    iVar5 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar5 + 0x5ec0) - *(int *)(iVar5 + 0x5ebc) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar5 + 0x5ebc);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar4) {
          iVar5 = local_20[uVar7];
          goto LAB_006c2129;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c2129:
    if (local_1c == (int *)0x0) {
      if (iVar5 == 0) {
        FUN_006c75e0(param_1);
      }
      else {
        FUN_006c7880();
      }
    }
    else {
      FUN_006c7760();
    }
    if (cVar1 == '\0') {
      FUN_006c7c40(param_1);
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar6 = FUN_0048a3d0();
    iVar4 = *(int *)(iVar6 + 0x5ecc);
    if ((iVar4 == 0) || (*(int *)(iVar4 + 8) != iVar5)) {
      piVar10 = *(int **)(iVar6 + 0x5ed0);
      uVar3 = *(int *)(iVar6 + 0x5ed4) - (int)piVar10 >> 2;
      uVar7 = 0;
      piVar8 = piVar10;
      if (uVar3 != 0) {
        do {
          if (*(int *)(*piVar8 + 8) == iVar5) {
            iVar4 = piVar10[uVar7];
            goto LAB_006c21bf;
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (uVar7 < uVar3);
      }
LAB_006c21c3:
      FUN_006c79a0(param_1);
    }
    else {
LAB_006c21bf:
      if (iVar4 == 0) goto LAB_006c21c3;
    }
    iVar5 = FUN_0044fd50();
    iVar5 = *(int *)(iVar5 + 0x5ec0);
    local_28 = local_24;
joined_r0x006c21d5:
    if ((((iVar5 != 0) && (local_28 != 0)) && (*(char *)(local_28 + 0x12) == '\0')) &&
       (((iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0 &&
         (iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0)) &&
        ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 2) != 0)))))) {
      FUN_006c6ec0(param_1);
    }
    if (piVar11 == (int *)0x0) {
      ExceptionList = local_14;
      return;
    }
    if (*(char *)(local_2c + 0x28) == '\0') {
      ExceptionList = local_14;
      return;
    }
    break;
  case (int *)0x7:
  case (int *)0x17:
  case (int *)0x18:
    FUN_006c68c0();
    uVar9 = CONCAT31(0xffffff,piVar11 != (int *)0x0);
    FUN_006c69c0(uVar9);
    FUN_006c6af0();
    FUN_006c6c10(uVar9);
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0044fd50();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar5) {
          local_28 = local_20[uVar7];
          goto LAB_006c1ace;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    local_28 = 0;
LAB_006c1ace:
    iVar5 = FUN_0044fd50();
    if (((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_28 == 0)) &&
         (iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0)) &&
        (iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0)) &&
       ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 4) != 0)))) {
      FUN_006c6da0();
    }
    if (piVar11 != (int *)0x0) {
      if (*(char *)(local_2c + 0x28) == '\0') {
        if ((*(short *)(local_2c + 0x14) == 0) && ((short)piVar11[5] == 0)) {
          FUN_006c7dc0(param_1);
        }
      }
      else if (*(short *)(local_2c + 0x14) == (short)piVar11[5]) {
        FUN_006c72e0();
      }
      else if ((short)piVar11[5] == 0) {
        FUN_006c7040();
      }
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 8) == iVar5) {
          iVar5 = local_20[uVar7];
          goto LAB_006c1ba1;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c1ba1:
    iVar4 = *(int *)(param_1 + 0xb4);
    local_24 = (uint)(iVar5 != 0);
    iVar5 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar5 + 0x5ec0) - *(int *)(iVar5 + 0x5ebc) >> 2;
    if (uVar3 != 0) {
      local_20 = *(int **)(iVar5 + 0x5ebc);
      piVar10 = local_20;
      do {
        if (*(int *)(*piVar10 + 4) == iVar4) {
          iVar5 = local_20[uVar7];
          goto LAB_006c1be9;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c1be9:
    if (local_24 == 0) {
      if (iVar5 == 0) {
        FUN_006c75e0(param_1);
      }
      else {
        FUN_006c7880();
      }
    }
    else {
      FUN_006c7760();
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar6 = FUN_0048a3d0();
    iVar4 = *(int *)(iVar6 + 0x5ecc);
    if ((iVar4 == 0) || (*(int *)(iVar4 + 8) != iVar5)) {
      piVar10 = *(int **)(iVar6 + 0x5ed0);
      uVar3 = *(int *)(iVar6 + 0x5ed4) - (int)piVar10 >> 2;
      uVar7 = 0;
      piVar8 = piVar10;
      if (uVar3 != 0) {
        do {
          if (*(int *)(*piVar8 + 8) == iVar5) {
            iVar4 = piVar10[uVar7];
            goto LAB_006c1c72;
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (uVar7 < uVar3);
      }
LAB_006c1c76:
      FUN_006c79a0(param_1);
    }
    else {
LAB_006c1c72:
      if (iVar4 == 0) goto LAB_006c1c76;
    }
    iVar5 = FUN_0044fd50();
    if ((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_28 != 0)) &&
        (*(char *)(local_28 + 0x12) == '\0')) &&
       (((iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0 &&
         (iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0)) &&
        ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 2) != 0)))))) {
      FUN_006c6ec0(param_1);
    }
    if (piVar11 == (int *)0x0) {
      ExceptionList = local_14;
      return;
    }
LAB_006c1cce:
    if (*(char *)(local_2c + 0x28) == '\0') {
      ExceptionList = local_14;
      return;
    }
    if (*(short *)(local_2c + 0x14) != (short)piVar11[5]) {
      ExceptionList = local_14;
      return;
    }
    break;
  default:
    goto switchD_006c1a63_caseD_a;
  case (int *)0x15:
    FUN_006c68c0();
    uVar9 = CONCAT31(0xffffff,piVar11 != (int *)0x0);
    FUN_006c69c0(uVar9);
    FUN_006c6af0();
    FUN_006c6c10(uVar9);
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0044fd50();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_1c = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_1c;
      do {
        if (*(int *)(*piVar10 + 4) == iVar5) {
          local_24 = local_1c[uVar7];
          goto LAB_006c2357;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    local_24 = 0;
LAB_006c2357:
    iVar5 = FUN_0044fd50();
    if ((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_24 == 0)) &&
        (iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0)) &&
       ((iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0 &&
        ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 4) != 0)))))) {
      FUN_006c6da0();
    }
    if (piVar11 != (int *)0x0) {
      if (*(char *)(local_2c + 0x29) == '\0') {
        if (*(char *)(local_2c + 0x28) == '\0') {
          if ((short)piVar11[5] == 0) {
            FUN_006c7dc0(param_1);
          }
        }
        else {
          sVar2 = (short)piVar11[5];
          if (*(short *)(local_2c + 0x14) == sVar2) {
            FUN_006c72e0();
          }
          else if (sVar2 == 0) {
LAB_006c2448:
            FUN_006c7040();
          }
          else {
            if (((char)piVar11[10] == '\0') || (piVar11[4] != 0)) goto LAB_006c2443;
            FUN_006c8180();
          }
        }
      }
      else {
        sVar2 = (short)piVar11[5];
        if (*(short *)(local_2c + 0x14) == sVar2) {
          FUN_006c72e0();
        }
        else if (((sVar2 == 0) || ((char)piVar11[10] == '\0')) || (piVar11[4] != 0)) {
          if (*(char *)((int)piVar11 + 0x29) == '\0') {
            if (((char)piVar11[10] == '\0') || (*(int *)(local_2c + 0x10) != piVar11[4])) {
LAB_006c2443:
              if (sVar2 == 0) goto LAB_006c2448;
            }
            else {
              FUN_006c84e0();
            }
          }
          else {
            FUN_006c82a0();
          }
        }
        else {
          FUN_006c8060();
        }
      }
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar4 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar4 + 0x5eb0) - *(int *)(iVar4 + 0x5eac) >> 2;
    if (uVar3 != 0) {
      local_1c = *(int **)(iVar4 + 0x5eac);
      piVar10 = local_1c;
      do {
        if (*(int *)(*piVar10 + 8) == iVar5) {
          iVar5 = local_1c[uVar7];
          goto LAB_006c24a1;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c24a1:
    iVar4 = *(int *)(param_1 + 0xb4);
    local_20 = (int *)(uint)(iVar5 != 0);
    iVar5 = FUN_0048a3d0();
    uVar7 = 0;
    uVar3 = *(int *)(iVar5 + 0x5ec0) - *(int *)(iVar5 + 0x5ebc) >> 2;
    if (uVar3 != 0) {
      local_1c = *(int **)(iVar5 + 0x5ebc);
      piVar10 = local_1c;
      do {
        if (*(int *)(*piVar10 + 4) == iVar4) {
          iVar5 = local_1c[uVar7];
          goto LAB_006c24e9;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (uVar7 < uVar3);
    }
    iVar5 = 0;
LAB_006c24e9:
    if (local_20 == (int *)0x0) {
      if (iVar5 == 0) {
        FUN_006c75e0(param_1);
      }
      else {
        FUN_006c7880();
      }
    }
    else {
      FUN_006c7760();
    }
    iVar5 = *(int *)(param_1 + 0xb4);
    iVar6 = FUN_0048a3d0();
    iVar4 = *(int *)(iVar6 + 0x5ecc);
    if ((iVar4 == 0) || (*(int *)(iVar4 + 8) != iVar5)) {
      piVar10 = *(int **)(iVar6 + 0x5ed0);
      uVar3 = *(int *)(iVar6 + 0x5ed4) - (int)piVar10 >> 2;
      uVar7 = 0;
      piVar8 = piVar10;
      if (uVar3 != 0) {
        do {
          if (*(int *)(*piVar8 + 8) == iVar5) {
            iVar4 = piVar10[uVar7];
            goto LAB_006c2572;
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (uVar7 < uVar3);
      }
LAB_006c2576:
      FUN_006c79a0(param_1);
    }
    else {
LAB_006c2572:
      if (iVar4 == 0) goto LAB_006c2576;
    }
    if (((*(char *)(local_2c + 0x28) != '\0') && (piVar11 != (int *)0x0)) &&
       (iVar5 = *piVar11, iVar4 = FUN_00404ba0(), iVar5 == *(int *)(iVar4 + 0x5f50))) {
      FUN_006c8600();
    }
    iVar5 = FUN_0044fd50();
    if ((((*(int *)(iVar5 + 0x5ec0) != 0) && (local_24 != 0)) &&
        ((*(char *)(local_24 + 0x12) == '\0' &&
         ((iVar5 = FUN_0044fd50(), *(int *)(iVar5 + 0x5ec0) != 0 &&
          (iVar5 = *(int *)(iVar5 + 0x5ebc), iVar5 != 0)))))) &&
       ((*(char *)(iVar5 + 0x12) != '\0' || ((*(byte *)(iVar5 + 0x14) & 2) != 0)))) {
      FUN_006c6ec0(param_1);
    }
    if (piVar11 == (int *)0x0) {
      ExceptionList = local_14;
      return;
    }
    if (*(char *)(local_2c + 0x29) == '\0') goto LAB_006c1cce;
    if (*(short *)(local_2c + 0x14) != (short)piVar11[5]) {
      if ((char)piVar11[10] == '\0') {
        ExceptionList = local_14;
        return;
      }
      if (*(int *)(local_2c + 0x10) != piVar11[4]) {
        ExceptionList = local_14;
        return;
      }
      FUN_006c83c0();
      ExceptionList = local_14;
      return;
    }
  }
  FUN_006c7160(param_1);
switchD_006c1a63_caseD_a:
  ExceptionList = local_14;
  return;
}

