
void FUN_00435a90(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int *local_20 [2];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  local_20[0] = (int *)0x1;
  do {
    piVar7 = local_20[0];
    iVar9 = *(int *)(param_1 + 0x148);
    piVar5 = (int *)FUN_004364c0(local_20);
    (**(code **)(**(int **)(param_1 + 0x104 + (int)piVar7 * 4) + 0x90))(*piVar5 != iVar9,uVar4);
    local_20[0] = (int *)((int)piVar7 + 1);
  } while ((int)local_20[0] < 10);
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  bVar3 = false;
  puVar8 = (undefined4 *)(param_1 + 300);
  iVar9 = 3;
  do {
    (**(code **)(*(int *)*puVar8 + 0x90))(0 < (int)puVar8[3]);
    if ((int)puVar8[3] < 1) {
      (**(code **)(*(int *)*puVar8 + 0x19c))();
      bVar3 = true;
    }
    else {
      (**(code **)(*(int *)*puVar8 + 0x198))(puVar8[3]);
    }
    puVar8 = puVar8 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    iStack_c = iVar9;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    iStack_c = 0xffffffff;
  }
  iVar9 = FUN_004d43d0();
  piVar7 = *(int **)(param_1 + 0xfc);
  puVar8 = (undefined4 *)piVar7[0x19];
  local_20[0] = piVar7;
  for (puVar1 = (undefined4 *)*puVar8; puVar1 != puVar8; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = puVar1[2];
    if ((*(int *)(iVar2 + 0x60) != 0) && ((*(int **)(iVar2 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x30))(iVar2);
      piVar7 = local_20[0];
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  if ((bVar3) || (iVar9 < 0x28)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  (**(code **)(**(int **)(param_1 + 0xf4) + 0x90))(uVar6);
  ExceptionList = pvStack_18;
  return;
}

