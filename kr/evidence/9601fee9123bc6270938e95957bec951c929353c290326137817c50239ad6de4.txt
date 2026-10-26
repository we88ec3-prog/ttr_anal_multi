
undefined4 FUN_004b2cd0(int param_1,uint param_2)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 *puStack_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940ae1;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_20 = DAT_00f94300 + 0x50dc;
  if (param_2 < 2) {
    local_30 = 0;
  }
  else {
    local_30 = (param_2 - 2) / 0x1f;
  }
  if (local_30 != 0) {
    puVar9 = (undefined4 *)(param_1 + 8);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_2c = (undefined4 *)(uint)*(ushort *)((int)puVar9 + -6);
      piVar5 = (int *)FUN_0082ef00(&local_2c);
      if (*piVar5 == DAT_00fab13c) {
        local_2c = (undefined4 *)FUN_00891268(0x140);
        local_c = 3;
        if (local_2c == (undefined4 *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_004cfd10(local_2c);
        }
        local_c = 0xffffffff;
        pcVar2 = *(code **)(*piVar5 + 0x3c);
        *(undefined2 *)(piVar5 + 1) = *(undefined2 *)((int)puVar9 + -6);
        (*pcVar2)(*(ushort *)(puVar9 + -1) | 0x3000000);
        (**(code **)(*piVar5 + 0x44))(puVar9,1);
        (**(code **)(*piVar5 + 0x58))(0x80);
        (**(code **)(*piVar5 + 0x30))();
        piVar5[0x47] = puVar9[5];
        FUN_004d0a10();
        piVar5[0x30] = puVar9[2];
        piVar5[0x31] = puVar9[3];
        piVar5[0x32] = 0x14;
        piVar5[0x35] = 1;
        FUN_004cfe90(*puVar9,puVar9[1]);
        uVar4 = DAT_00fab22c & 1;
        *(bool *)(piVar5 + 0x3d) = puVar9[4] != 0;
        if (uVar4 == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 4;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        FUN_004dff30(&DAT_00fab130);
      }
      else {
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 2;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_2c = (undefined4 *)(uint)*(ushort *)((int)puVar9 + -6);
        FUN_0082ef00(&local_2c);
        if (local_28 == DAT_00fab13c) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = *(int **)(local_28 + 0x10);
        }
        (**(code **)(*piVar5 + 0x44))(puVar9,1);
        (**(code **)(*piVar5 + 0x58))(0x80);
        piVar5[0x30] = puVar9[2];
        piVar5[0x31] = puVar9[3];
        piVar5[0x32] = 0x14;
        piVar5[0x35] = 1;
        FUN_004cfe90(*puVar9,puVar9[1]);
        *(bool *)(piVar5 + 0x3d) = puVar9[4] != 0;
      }
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 5;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      cVar1 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
      puVar6 = (undefined4 *)DAT_00f8d91c[1];
      local_2c = DAT_00f8d91c;
      while (puVar8 = puVar6, cVar1 == '\0') {
        if ((int)puVar8[3] < (int)puVar9[5]) {
          puVar6 = (undefined4 *)puVar8[2];
          puVar8 = local_2c;
        }
        else {
          puVar6 = (undefined4 *)*puVar8;
        }
        cVar1 = *(char *)((int)puVar6 + 0x15);
        local_2c = puVar8;
      }
      if ((local_2c == DAT_00f8d91c) || ((int)puVar9[5] < (int)local_2c[3])) {
        puStack_24 = DAT_00f8d91c;
        ppuVar7 = &puStack_24;
      }
      else {
        ppuVar7 = &local_2c;
      }
      if ((*ppuVar7 != DAT_00f8d91c) && (iVar3 = (*ppuVar7)[4], iVar3 != 0)) {
        FUN_0045f1b0(iVar3,*(undefined1 *)(puVar9 + 6));
      }
      puVar9 = (undefined4 *)((int)puVar9 + 0x1f);
      local_30 = local_30 - 1;
    } while (local_30 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

