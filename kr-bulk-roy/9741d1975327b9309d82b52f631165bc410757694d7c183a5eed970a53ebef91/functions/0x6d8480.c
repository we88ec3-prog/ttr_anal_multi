
void FUN_006d8480(undefined4 *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  int iVar8;
  undefined4 *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  ushort *puVar13;
  undefined4 *puVar14;
  ushort *puVar15;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00938a0e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  puVar11 = (ushort *)*param_1;
  local_28 = (ushort *)param_1[1];
  local_30 = puVar11;
  local_2c = puVar11;
  if (puVar11 != local_28) {
    do {
      puVar6 = (undefined4 *)DAT_00fab13c[1];
      cVar2 = *(char *)((int)puVar6 + 0x15);
      puVar9 = puVar6;
      local_24 = DAT_00fab13c;
      while (puVar14 = puVar9, cVar2 == '\0') {
        if ((uint)puVar14[3] < (uint)*local_30) {
          puVar9 = (undefined4 *)puVar14[2];
          puVar14 = local_24;
        }
        else {
          puVar9 = (undefined4 *)*puVar14;
        }
        cVar2 = *(char *)((int)puVar9 + 0x15);
        local_24 = puVar14;
      }
      if ((local_24 == DAT_00fab13c) || ((uint)*local_30 < (uint)local_24[3])) {
        local_20 = DAT_00fab13c;
        ppuVar7 = &local_20;
      }
      else {
        ppuVar7 = &local_24;
      }
      if (*ppuVar7 == DAT_00fab13c) {
        iVar12 = 0;
      }
      else {
        iVar12 = (*ppuVar7)[4];
      }
      cVar2 = *(char *)((int)puVar6 + 0x15);
      local_24 = DAT_00fab13c;
      while (puVar9 = puVar6, cVar2 == '\0') {
        if ((uint)puVar9[3] < (uint)puVar11[1]) {
          puVar6 = (undefined4 *)puVar9[2];
          puVar9 = local_24;
        }
        else {
          puVar6 = (undefined4 *)*puVar9;
        }
        cVar2 = *(char *)((int)puVar6 + 0x15);
        local_24 = puVar9;
      }
      if ((local_24 == DAT_00fab13c) || ((uint)puVar11[1] < (uint)local_24[3])) {
        local_1c[0] = DAT_00fab13c;
        ppuVar7 = local_1c;
      }
      else {
        ppuVar7 = &local_24;
      }
      if (*ppuVar7 == DAT_00fab13c) {
        iVar8 = 0;
      }
      else {
        iVar8 = (*ppuVar7)[4];
      }
      if ((iVar12 == 0) || (iVar8 == 0)) {
        puVar3 = (ushort *)param_1[1];
        puVar4 = puVar11;
        puVar5 = puVar11;
        while (puVar5 = puVar5 + 0xe, puVar5 != puVar3) {
          puVar10 = puVar4 + 0xe;
          puVar13 = puVar5;
          puVar15 = puVar4;
          for (iVar12 = 7; puVar4 = puVar10, puVar11 = local_2c, iVar12 != 0; iVar12 = iVar12 + -1)
          {
            *(undefined4 *)puVar15 = *(undefined4 *)puVar13;
            puVar13 = puVar13 + 2;
            puVar15 = puVar15 + 2;
          }
        }
        param_1[1] = param_1[1] + -0x1c;
        local_28 = (ushort *)param_1[1];
      }
      else {
        fVar1 = *(float *)(puVar11 + 0xc);
        *(float *)(puVar11 + 0xc) = fVar1 - param_2;
        if (0.0 < fVar1 - param_2) {
          local_30 = local_30 + 0xe;
          puVar11 = puVar11 + 0xe;
          local_2c = puVar11;
        }
        else {
          puVar3 = (ushort *)param_1[1];
          puVar4 = puVar11;
          puVar5 = puVar11;
          while (puVar5 = puVar5 + 0xe, puVar5 != puVar3) {
            puVar10 = puVar4 + 0xe;
            puVar13 = puVar5;
            puVar15 = puVar4;
            for (iVar12 = 7; puVar4 = puVar10, puVar11 = local_2c, iVar12 != 0; iVar12 = iVar12 + -1
                ) {
              *(undefined4 *)puVar15 = *(undefined4 *)puVar13;
              puVar13 = puVar13 + 2;
              puVar15 = puVar15 + 2;
            }
          }
          param_1[1] = param_1[1] + -0x1c;
          local_28 = (ushort *)param_1[1];
        }
      }
    } while (local_30 != local_28);
  }
  ExceptionList = local_14;
  return;
}

