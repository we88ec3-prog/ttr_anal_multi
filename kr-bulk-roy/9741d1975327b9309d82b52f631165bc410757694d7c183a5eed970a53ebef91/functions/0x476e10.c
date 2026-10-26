
void FUN_00476e10(int param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float unaff_EBX;
  undefined4 *puVar6;
  float fVar7;
  int *piVar8;
  int *local_24;
  int *local_20;
  float local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009413e2;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_24 = (int *)(float)DAT_00f942c8;
  uVar2 = *(ushort *)(*(int *)(param_1 + 0xf4) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0xf8) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0xfc) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x100) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x104) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x108) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x10c) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x110) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x114) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x118) + 0x298);
  if (uVar2 != 0) {
    local_24 = (int *)((float)uVar2 + (float)local_24);
    local_1c[0] = (float)(uint)uVar2;
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 1;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_c = 0xffffffff;
  iVar3 = FUN_00822660((int)(float)local_24);
  fVar7 = (float)(iVar3 + 1);
  if (7 < (int)fVar7) {
    fVar7 = 1.12104e-44;
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 2;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
    local_c = 0xffffffff;
  }
  local_1c[0] = fVar7;
  FUN_0062db10(local_1c);
  if (local_20 == DAT_00fb9384) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(ushort *)(local_20 + 4);
  }
  local_1c[0] = (float)uVar2;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 3;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
    local_c = 0xffffffff;
  }
  puVar6 = (undefined4 *)(param_1 + 0x134);
  local_20 = (int *)0x8;
  local_1c[0] = (local_1c[0] / (float)DAT_00fb936c) *
                (float)(*(int *)(*(int *)(param_1 + 0x124) + 0x10) -
                       *(int *)(*(int *)(param_1 + 0x124) + 8)) -
                (float)((*(int *)(*(int *)(param_1 + 300) + 0x10) -
                        *(int *)(*(int *)(param_1 + 300) + 8)) / 2);
  do {
    (**(code **)(*(int *)*puVar6 + 0x94))(0);
    puVar6 = puVar6 + 1;
    local_20 = (int *)((int)local_20 + -1);
  } while (local_20 != (int *)0x0);
  iVar3 = *(int *)(param_1 + 300);
  iVar5 = (int)local_1c[0] - *(int *)(iVar3 + 8);
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar5;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar5;
  iVar5 = *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + -iVar5;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + -iVar5;
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x10);
  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
  if (*(int *)(iVar3 + 0x60) != 0) {
    iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x2c);
    *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar5;
    *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + iVar5;
    iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x30);
    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + iVar5;
    *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + iVar5;
  }
  local_20 = *(int **)(iVar3 + 100);
  piVar4 = (int *)*local_20;
  if (piVar4 != local_20) {
    do {
      FUN_00746f70();
      piVar4 = (int *)*piVar4;
    } while (piVar4 != local_20);
  }
  (**(code **)(**(int **)(param_1 + 0x130 + (int)fVar7 * 4) + 0x94))(1);
  iVar3 = *(int *)(param_1 + 0x130 + (int)fVar7 * 4);
  iVar5 = FUN_008fed10();
  iVar5 = iVar5 - *(int *)(iVar3 + 8);
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar5;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar5;
  iVar5 = 10 - *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar5;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5;
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x10);
  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
  if (*(int *)(iVar3 + 0x60) != 0) {
    iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x2c);
    *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar5;
    *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + iVar5;
    iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x30);
    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + iVar5;
    *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + iVar5;
  }
  puVar6 = *(undefined4 **)(iVar3 + 100);
  for (puVar1 = (undefined4 *)*puVar6; puVar1 != puVar6; puVar1 = (undefined4 *)*puVar1) {
    FUN_00746f70();
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  piVar4 = (int *)FUN_00822660((int)unaff_EBX);
  if (((int)piVar4 < 8) && (piVar4 != (int *)0x0)) {
    if ((DAT_00fb9368 & 1) == 0) {
      DAT_00fb9368 = DAT_00fb9368 | 1;
      puStack_10 = (undefined1 *)0x5;
      FUN_00822000();
      _atexit((_func_4879 *)&LAB_00bcd590);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    local_20 = piVar4;
    FUN_0062db10(&local_20);
    if (local_24 == DAT_00fb9384) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(ushort *)(local_24 + 4);
    }
    if ((DAT_00fb9368 & 1) == 0) {
      DAT_00fb9368 = DAT_00fb9368 | 1;
      puStack_10 = (undefined1 *)0x6;
      FUN_00822000();
      _atexit((_func_4879 *)&LAB_00bcd590);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    iVar3 = *(int *)(param_1 + 0x130);
    local_20 = (int *)(((float)uVar2 / (float)DAT_00fb936c) *
                       (float)(*(int *)(*(int *)(param_1 + 0x128) + 0x10) -
                              *(int *)(*(int *)(param_1 + 0x128) + 8)) -
                      (float)((*(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 8)) / 2));
    iVar5 = (int)(float)local_20 - *(int *)(iVar3 + 8);
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar5;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar5;
    iVar5 = *(int *)(iVar3 + 0xc);
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + -iVar5;
    *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + -iVar5;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
    if (*(int *)(iVar3 + 0x60) != 0) {
      iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x2c);
      *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar5;
      *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + iVar5;
      iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x30);
      *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + iVar5;
      *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + iVar5;
    }
    puVar6 = *(undefined4 **)(iVar3 + 100);
    for (puVar1 = (undefined4 *)*puVar6; puVar1 != puVar6; puVar1 = (undefined4 *)*puVar1) {
      FUN_00746f70();
    }
    (**(code **)(**(int **)(param_1 + 0x130) + 0x94))(1);
    (**(code **)(**(int **)(param_1 + 0x130 + (int)piVar4 * 4) + 0x94))(1);
    iVar3 = *(int *)(param_1 + 0x130 + (int)piVar4 * 4);
    iVar5 = FUN_008fed10();
    iVar5 = iVar5 - *(int *)(iVar3 + 8);
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar5;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar5;
    iVar5 = 10 - *(int *)(iVar3 + 0xc);
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar5;
    *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
    if (*(int *)(iVar3 + 0x60) != 0) {
      iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x2c);
      *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar5;
      *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + iVar5;
      iVar5 = *(int *)(*(int *)(iVar3 + 0x60) + 0x30);
      *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + iVar5;
      *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + iVar5;
    }
    piVar4 = *(int **)(iVar3 + 100);
    piVar8 = (int *)*piVar4;
    if (piVar8 != piVar4) {
      do {
        FUN_00746f70();
        piVar8 = (int *)*piVar8;
      } while (piVar8 != piVar4);
      ExceptionList = local_20;
      return;
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x130) + 0x94))(0);
  }
  ExceptionList = local_20;
  return;
}

