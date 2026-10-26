
void FUN_004429a0(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint unaff_EBX;
  int *piVar9;
  int iVar10;
  undefined4 unaff_ESI;
  uint uVar11;
  int unaff_EDI;
  undefined4 uStack_3c;
  char cVar12;
  int iStack_30;
  undefined4 *local_28;
  undefined4 *puStack_24;
  undefined4 *local_20;
  undefined4 *apuStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00941966;
  local_14 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (((uint)(*(int **)(unaff_EDI + 0x14c))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_EDI + 0x14c) + 0x19c))(0xffffffff,0xffffffff,0,0);
    (**(code **)(**(int **)(unaff_EDI + 0x14c) + 0x94))(0);
    (**(code **)(**(int **)(unaff_EDI + 0x14c) + 200))();
  }
  local_28 = (undefined4 *)0xffffffff;
  puVar4 = (undefined4 *)(unaff_EDI + 0x154);
  piVar9 = (int *)(unaff_EDI + 0x10c);
  local_20 = (undefined4 *)0x2;
  do {
    if ((piVar9[-1] < 0) || (*piVar9 < 0)) {
      (**(code **)(*(int *)puVar4[-5] + 0x19c))(0xffffffff,0xffffffff,0,0);
      (**(code **)(*(int *)*puVar4 + 0x94))(0);
      (**(code **)(*(int *)*puVar4 + 200))();
    }
    else {
      (**(code **)(*(int *)puVar4[-5] + 0x19c))(piVar9[-1],*piVar9,piVar9[1],piVar9[2]);
      (**(code **)(*(int *)*puVar4 + 0x94))(1);
      (**(code **)(*(int *)*puVar4 + 200))();
      uStack_3c = piVar9[3];
    }
    (**(code **)(*(int *)puVar4[-5] + 200))();
    puVar4 = puVar4 + 1;
    piVar9 = piVar9 + 8;
    local_20 = (undefined4 *)((int)local_20 - 1);
  } while (local_20 != (undefined4 *)0x0);
  if ((int)local_28 < 0) {
    piVar9 = *(int **)(unaff_EDI + 0x168);
    FUN_007598b0(1);
    FUN_007598b0(0);
    pcVar1 = *(code **)(*piVar9 + 200);
    piVar9[0x55] = -0x10000;
    (*pcVar1)();
    (**(code **)(**(int **)(unaff_EDI + 0x164) + 0x90))(0);
    (**(code **)(**(int **)(unaff_EDI + 0x164) + 200))();
    (**(code **)(**(int **)(unaff_EDI + 0x150) + 0x94))(0);
    (**(code **)(**(int **)(unaff_EDI + 0x150) + 200))();
    piVar9 = *(int **)(unaff_EDI + 0x16c);
    FUN_007598b0(1);
    FUN_007598b0(0);
    pcVar1 = *(code **)(*piVar9 + 200);
    piVar9[0x55] = -0x10000;
    (*pcVar1)();
  }
  else {
    if ((DAT_00fb7bcc & 1) == 0) {
      DAT_00fb7bcc = DAT_00fb7bcc | 1;
      uStack_c = 0;
      FUN_00820290();
      _atexit((_func_4879 *)&LAB_00bcd520);
      uStack_c = 0xffffffff;
    }
    uVar11 = 0;
    puStack_24 = (undefined4 *)0x0;
    iVar10 = DAT_00fb7bf0;
    if (DAT_00fb7bf4 - DAT_00fb7bf0 >> 2 != 0) {
      do {
        local_20 = (undefined4 *)(iVar10 + uVar11 * 4);
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          uStack_c = 1;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          uStack_c = 0xffffffff;
          iVar10 = DAT_00fb7bf0;
        }
        iVar3 = 0;
        if (DAT_00f94300 != -0x16f8) {
          iVar3 = FUN_005090e0();
        }
        puStack_24 = (undefined4 *)((int)puStack_24 + iVar3);
        uVar11 = uVar11 + 1;
      } while (uVar11 < (uint)(DAT_00fb7bf4 - iVar10 >> 2));
    }
    if ((DAT_00fb7bcc & 1) == 0) {
      DAT_00fb7bcc = DAT_00fb7bcc | 1;
      uStack_c = 2;
      FUN_00820290();
      _atexit((_func_4879 *)&LAB_00bcd520);
      uStack_c = 0xffffffff;
    }
    cVar12 = *(char *)((int)DAT_00fb7bd4[1] + 0x19);
    puVar4 = (undefined4 *)DAT_00fb7bd4[1];
    local_20 = DAT_00fb7bd4;
    while (puVar5 = puVar4, cVar12 == '\0') {
      if ((int)puVar5[3] < (int)local_28) {
        puVar4 = (undefined4 *)puVar5[2];
        puVar5 = local_20;
      }
      else {
        puVar4 = (undefined4 *)*puVar5;
      }
      cVar12 = *(char *)((int)puVar4 + 0x19);
      local_20 = puVar5;
    }
    if ((local_20 == DAT_00fb7bd4) || ((int)local_28 < (int)local_20[3])) {
      apuStack_1c[0] = DAT_00fb7bd4;
      ppuVar6 = apuStack_1c;
    }
    else {
      ppuVar6 = &local_20;
    }
    if (*ppuVar6 == DAT_00fb7bd4) {
      local_20 = (undefined4 *)0x0;
    }
    else {
      local_20 = (undefined4 *)(*ppuVar6)[4];
    }
    piVar9 = *(int **)(unaff_EDI + 0x168);
    if ((puStack_24 < local_20) || (bVar2 = false, local_20 == (undefined4 *)0x0)) {
      bVar2 = true;
    }
    FUN_007598b0(1);
    FUN_007598b0(0);
    pcVar1 = *(code **)(*piVar9 + 200);
    piVar9[0x55] = (-(uint)bVar2 & 0xfe0100) - 0xff0100;
    (*pcVar1)();
    bVar2 = !bVar2;
    apuStack_1c[0] = (undefined4 *)CONCAT31(apuStack_1c[0]._1_3_,bVar2);
    puVar4 = apuStack_1c[0];
    (**(code **)(**(int **)(unaff_EDI + 0x164) + 0x90))(apuStack_1c[0]);
    (**(code **)(**(int **)(unaff_EDI + 0x164) + 200))();
    (**(code **)(**(int **)(unaff_EDI + 0x150) + 0x94))(puVar4);
    (**(code **)(**(int **)(unaff_EDI + 0x150) + 200))();
    if (!bVar2) {
      unaff_EBX = (uint)CONCAT21((short)(unaff_EBX >> 0x10),bVar2) << 8;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_14 = (void *)0x3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_14 = (void *)0xffffffff;
    }
    puVar4 = DAT_00f94244;
    if ((DAT_00fb7bcc & 1) == 0) {
      DAT_00fb7bcc = DAT_00fb7bcc | 1;
      local_14 = (void *)0x4;
      FUN_00820290();
      _atexit((_func_4879 *)&LAB_00bcd520);
      local_14 = (void *)0xffffffff;
    }
    cVar12 = *(char *)((int)DAT_00fb7bd4[1] + 0x19);
    puVar5 = (undefined4 *)DAT_00fb7bd4[1];
    puStack_24 = DAT_00fb7bd4;
    while (puVar8 = puVar5, cVar12 == '\0') {
      if ((int)puVar8[3] < iStack_30) {
        puVar5 = (undefined4 *)puVar8[2];
        puVar8 = puStack_24;
      }
      else {
        puVar5 = (undefined4 *)*puVar8;
      }
      cVar12 = *(char *)((int)puVar5 + 0x19);
      puStack_24 = puVar8;
    }
    if ((puStack_24 == DAT_00fb7bd4) || (iStack_30 < (int)puStack_24[3])) {
      local_28 = DAT_00fb7bd4;
      ppuVar6 = &local_28;
    }
    else {
      ppuVar6 = &puStack_24;
    }
    if (*ppuVar6 == DAT_00fb7bd4) {
      local_28 = (undefined4 *)0x0;
    }
    else {
      local_28 = (undefined4 *)(*ppuVar6)[5];
    }
    piVar9 = *(int **)(unaff_EDI + 0x16c);
    if ((puVar4 < local_28) ||
       (unaff_EBX = CONCAT13((char)(unaff_EBX >> 0x18),(uint3)(ushort)unaff_EBX),
       local_28 == (undefined4 *)0x0)) {
      unaff_EBX = CONCAT13((char)(unaff_EBX >> 0x18),CONCAT12(1,(short)unaff_EBX));
    }
    FUN_007598b0(1);
    FUN_007598b0(0);
    cVar12 = (char)(unaff_EBX >> 0x10);
    pcVar1 = *(code **)(*piVar9 + 200);
    piVar9[0x55] = (-(uint)(cVar12 != '\0') & 0xfe0100) - 0xff0100;
    (*pcVar1)();
    if (cVar12 != '\0') {
      unaff_EBX = unaff_EBX & 0xffff0000;
    }
  }
  cVar12 = (char)(unaff_EBX >> 0x18);
  if ((cVar12 == '\0') || ((char)(unaff_EBX >> 8) == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x160) + 0x94))(uVar7);
  (**(code **)(**(int **)(unaff_EDI + 0x160) + 200))();
  if ((cVar12 == '\0') || ((char)((uint)unaff_ESI >> 8) == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x15c) + 0x94))(uVar7);
  (**(code **)(**(int **)(unaff_EDI + 0x15c) + 200))();
  if ((cVar12 == '\0') || (uStack_3c._1_1_ == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x174) + 0x90))(uVar7);
  (**(code **)(**(int **)(unaff_EDI + 0x174) + 200))();
  ExceptionList = local_28;
  return;
}

