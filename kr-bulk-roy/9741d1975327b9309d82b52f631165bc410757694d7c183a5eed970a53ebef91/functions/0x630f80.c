
void FUN_00630f80(void)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  short *psVar6;
  undefined2 *puVar7;
  undefined1 *in_ECX;
  undefined1 *puVar8;
  undefined1 *unaff_EBX;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined1 auStack_160 [24];
  undefined4 uStack_148;
  undefined2 *puStack_144;
  undefined1 auStack_140 [24];
  undefined4 uStack_128;
  undefined4 *puStack_120;
  uint *puStack_11c;
  uint uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  uint local_ec;
  undefined1 *local_e8;
  undefined1 *local_e4;
  undefined1 *puStack_e0;
  undefined1 *local_dc;
  undefined1 *puStack_d8;
  int iStack_d4;
  undefined1 *puStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined4 uStack_a8;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  undefined4 uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  uint local_1c;
  undefined1 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009467db;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_ec;
  ExceptionList = &local_14;
  local_dc = in_ECX;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  iVar5 = DAT_00fb114c;
  local_c = 0xffffffff;
  local_ec = *(uint *)(in_ECX + 0xfc);
  FUN_00503d20();
  if ((local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) ||
     (local_e4 = (undefined1 *)((int)local_e8 + 0x10), local_e4 == (undefined1 *)0x0))
  goto LAB_0063225a;
  FUN_00757800();
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c = 1;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  uStack_5c = 7;
  uStack_60 = 0;
  uStack_70 = (short *)((uint)uStack_70._2_2_ << 0x10);
  local_c = 2;
  FUN_00632280();
  FUN_00632b10();
  FUN_00757200();
  local_c._0_1_ = 3;
  psVar6 = uStack_70;
  if (uStack_5c < 8) {
    psVar6 = (short *)&uStack_70;
  }
  uStack_a8 = (uint)uStack_a8._2_2_ << 0x10;
  uStack_94 = 7;
  uStack_98 = 0;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160();
  local_c._0_1_ = 4;
  FUN_007578f0();
  uStack_110 = 0x63115f;
  FUN_00759ed0();
  local_c._0_1_ = 3;
  if (7 < uStack_94) {
    FUN_0089120c();
  }
  FUN_00766030();
  (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
  uStack_c4 = (short *)((uint)uStack_c4._2_2_ << 0x10);
  uStack_b0 = 7;
  uStack_b4 = 0;
  FUN_00402160();
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c._0_1_ = 6;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_c._0_1_ = 5;
  local_ec = *(uint *)(local_e4 + 0x20);
  FUN_0050db00();
  if ((local_e8 != (undefined1 *)DAT_00fe17c4) && (local_e8 != (undefined1 *)0xfffffff0)) {
    puStack_e0 = (undefined1 *)&uStack_118;
    puStack_11c = (uint *)0xffffffff;
    puStack_120 = (undefined4 *)0x0;
    uStack_118 = uStack_118 & 0xffff0000;
    uStack_128 = 0x631256;
    FUN_004026e0();
    local_c._0_1_ = 7;
    local_ec = 0x16f;
    puStack_11c = (uint *)0x63126b;
    iVar5 = FUN_00585620();
    puStack_11c = &local_ec;
    puStack_120 = (undefined4 *)0x63127d;
    FUN_005740f0();
    if (local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puStack_11c = (uint *)((int)local_e8 + 0x10);
    if (7 < *(uint *)((int)local_e8 + 0x24)) {
      puStack_11c = (uint *)*puStack_11c;
    }
    local_c._0_1_ = 5;
    puStack_120 = (undefined4 *)0x6312b6;
    psVar6 = (short *)FUN_00424c80();
    local_c._0_1_ = 8;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    local_c._0_1_ = 5;
    if (7 < uStack_94) {
      FUN_0089120c();
    }
    FUN_00404300();
  }
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c._0_1_ = 9;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
    local_c._0_1_ = 5;
  }
  local_ec = *(uint *)(local_e4 + 0x24);
  FUN_005366c0();
  if ((local_e8 != (undefined1 *)DAT_00fe17e4) && (local_e8 != (undefined1 *)0xfffffff0)) {
    puStack_e0 = (undefined1 *)&uStack_118;
    puStack_11c = (uint *)0xffffffff;
    puStack_120 = (undefined4 *)0x0;
    uStack_118 = uStack_118 & 0xffff0000;
    uStack_128 = 0x6313a8;
    FUN_004026e0();
    local_c._0_1_ = 10;
    local_ec = 0x170;
    puStack_11c = (uint *)0x6313bd;
    iVar5 = FUN_00585620();
    puStack_11c = &local_ec;
    puStack_120 = (undefined4 *)0x6313cf;
    FUN_005740f0();
    if (local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puStack_11c = (uint *)((int)local_e8 + 0x10);
    if (7 < *(uint *)((int)local_e8 + 0x24)) {
      puStack_11c = (uint *)*puStack_11c;
    }
    local_c._0_1_ = 5;
    puStack_120 = (undefined4 *)0x631408;
    psVar6 = (short *)FUN_00424c80();
    local_c._0_1_ = 0xb;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    local_c._0_1_ = 5;
    if (7 < uStack_94) {
      FUN_0089120c();
    }
    FUN_00404300();
    local_ec = 0x173;
    iVar5 = FUN_00585620();
    FUN_005740f0();
    if (local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar6 = (short *)FUN_004ed610();
    local_c._0_1_ = 0xc;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    local_c._0_1_ = 5;
    if (7 < uStack_94) {
      FUN_0089120c();
    }
    FUN_00404300();
  }
  uVar2 = *(ushort *)(local_e4 + 0x28);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 0xd;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c._0_1_ = 5;
  }
  local_ec = uVar2 | 0x6000000;
  iVar5 = FUN_004f7a70();
  if (*(uint *)(iVar5 + 0x30) < 8) {
    iVar5 = iVar5 + 0x1c;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x1c);
  }
  if (iVar5 != 0) {
    local_ec = 0x171;
    iVar5 = FUN_00585620();
    FUN_005740f0();
    if (local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar6 = (short *)FUN_004ed610();
    local_c._0_1_ = 0xe;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    local_c._0_1_ = 5;
    if (7 < uStack_94) {
      FUN_0089120c();
    }
    FUN_00404300();
  }
  uVar2 = *(ushort *)(local_e4 + 0x2c);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 0xf;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c._0_1_ = 5;
  }
  local_ec = uVar2 | 0x6000000;
  iVar5 = FUN_004f7a70();
  if (*(uint *)(iVar5 + 0x30) < 8) {
    iVar5 = iVar5 + 0x1c;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x1c);
  }
  if (iVar5 != 0) {
    local_ec = 0x172;
    iVar5 = FUN_00585620();
    FUN_005740f0();
    if (local_e8 == (undefined1 *)*(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar6 = (short *)FUN_004ed610();
    local_c._0_1_ = 0x10;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300();
    local_c._0_1_ = 5;
    if (7 < uStack_94) {
      FUN_0089120c();
    }
    FUN_00404300();
  }
  FUN_00404300();
  iVar5 = DAT_00fe1bd0;
  local_ec = *(uint *)(local_e4 + 0x30);
  FUN_005274d0();
  puVar10 = local_e8;
  if (local_e8 != (undefined1 *)*(int *)(iVar5 + 0x1c)) {
    while (local_e8 = puVar10, puVar10 != (undefined1 *)0xfffffff0) {
      FUN_00633110();
      local_c._0_1_ = 0x11;
      FUN_00402800();
      local_c._0_1_ = 5;
      if (7 < uStack_94) {
        FUN_0089120c();
      }
      iVar5 = DAT_00fe1bd0;
      uStack_a8 = uStack_a8 & 0xffff0000;
      local_ec = *(uint *)((int)puVar10 + 0x30);
      uStack_94 = 7;
      uStack_98 = 0;
      if (((int)local_ec < 1) ||
         (FUN_005274d0(), puVar10 = local_e8, local_e8 == (undefined1 *)*(int *)(iVar5 + 0x1c)))
      break;
    }
  }
  local_ec = *(uint *)(local_e4 + 0x34);
  FUN_005274d0();
  puVar10 = local_e8;
  if (local_e8 != (undefined1 *)*(int *)(iVar5 + 0x1c)) {
    while (puVar10 != (undefined1 *)0xfffffff0) {
      local_e8 = puVar10;
      FUN_00633110();
      local_c._0_1_ = 0x12;
      FUN_00402800();
      local_c._0_1_ = 5;
      if (7 < uStack_94) {
        FUN_0089120c();
      }
      iVar5 = DAT_00fe1bd0;
      uStack_94 = 7;
      uStack_98 = 0;
      uStack_a8 = uStack_a8 & 0xffff0000;
      if (((int)*(uint *)((int)puVar10 + 0x30) < 1) ||
         (local_ec = *(uint *)((int)puVar10 + 0x30), FUN_005274d0(), puVar10 = local_e8,
         local_e8 == (undefined1 *)*(int *)(iVar5 + 0x1c))) break;
    }
  }
  psVar6 = uStack_c4;
  if (uStack_b0 < 8) {
    psVar6 = (short *)&uStack_c4;
  }
  uStack_94 = 7;
  uStack_98 = 0;
  uStack_a8 = uStack_a8 & 0xffff0000;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160();
  local_c._0_1_ = 0x13;
  FUN_007578f0();
  uStack_110 = 0x631976;
  FUN_00759ed0();
  local_c = CONCAT31(local_c._1_3_,5);
  if (7 < uStack_94) {
    FUN_0089120c();
  }
  puVar10 = local_dc;
  FUN_00766030();
  (**(code **)(**(int **)(puVar10 + 0x108) + 200))();
  if (*(int *)(local_e4 + 0x88) == 0) {
    pcVar3 = *(code **)(**(int **)(puVar10 + 0x10c) + 0x94);
    if (*(int *)(local_e4 + 0x80) != 0) {
      (*pcVar3)();
      local_dc = (undefined1 *)0x0;
      FUN_00404ba0();
      cVar4 = FUN_004d9d20();
      if (cVar4 == '\0') {
        FUN_00404ba0();
        FUN_008fed10();
        local_e4 = (undefined1 *)&puStack_11c;
        puStack_120 = (undefined4 *)0x631c33;
        FUN_00412df0();
        puStack_120 = (undefined4 *)0x160;
        puStack_10._0_1_ = 0x19;
        FUN_00585620();
        puStack_120 = (undefined4 *)FUN_00585330();
        puStack_10._0_1_ = 5;
        FUN_00424c80();
        puStack_10._0_1_ = 0x1a;
        FUN_00757710();
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,5);
        FUN_004fa440();
      }
      else {
        FUN_00757200();
        puStack_10._0_1_ = 0x16;
        FUN_00404ba0();
        FUN_008fed10();
        iVar5 = FUN_008fed10();
        puVar7 = &DAT_00c02bac;
        if (iVar5 < 0) {
          puVar7 = (undefined2 *)&DAT_00c1ad60;
        }
        unaff_EBX = &stack0xfffffedc;
        local_e4 = auStack_140;
        puStack_144 = (undefined2 *)0x631b64;
        FUN_00412df0();
        puStack_10._0_1_ = 0x17;
        uStack_148 = 0x631b72;
        puStack_144 = puVar7;
        FUN_00404ba0();
        uStack_148 = 0x631b87;
        FUN_008fed10();
        puStack_d0 = auStack_160;
        FUN_00412df0();
        uVar11 = 0x161;
        puStack_10._0_1_ = 0x18;
        FUN_00585620(0x161);
        uVar11 = FUN_00585330(uVar11);
        puStack_10._0_1_ = 0x16;
        FUN_006331f0(uVar11);
        uStack_128 = 0x631bd0;
        FUN_00759e60();
        FUN_00405300();
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,5);
        FUN_00757640();
        puVar10 = puStack_e0;
      }
      goto LAB_00631c99;
    }
    (*pcVar3)();
  }
  else {
    (**(code **)(**(int **)(puVar10 + 0x10c) + 0x94))();
    FUN_00404ba0();
    FUN_008fed10();
    local_e4 = (undefined1 *)&puStack_11c;
    puStack_120 = (undefined4 *)0x631a02;
    FUN_00412df0();
    puStack_10._0_1_ = 0x14;
    unaff_EBX = (undefined1 *)0x15f;
    puStack_120 = (undefined4 *)0x631a17;
    iVar5 = FUN_00585620();
    puStack_120 = (undefined4 *)&stack0xffffff10;
    FUN_005740f0();
    if (local_ec == *(uint *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puStack_120 = (undefined4 *)(local_ec + 0x10);
    if (7 < *(uint *)(local_ec + 0x24)) {
      puStack_120 = (undefined4 *)*puStack_120;
    }
    puStack_10._0_1_ = 5;
    FUN_00424c80();
    puStack_10._0_1_ = 0x15;
    FUN_00757710();
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,5);
    if (7 < uStack_98) {
      FUN_0089120c();
    }
LAB_00631c99:
    (**(code **)(**(int **)(puVar10 + 0x10c) + 200))();
  }
  (**(code **)(**(int **)(puVar10 + 0x110) + 0x94))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14._0_1_ = 0x1b;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)CONCAT31(local_14._1_3_,5);
  }
  FUN_008fed10();
  local_e8 = (undefined1 *)&puStack_120;
  FUN_00412df0();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_14._0_1_ = 0x1d;
    uStack_128 = 0x631d44;
    FUN_00584c40();
    uStack_128 = 0x631d4e;
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_14._0_1_ = 0x1c;
  uStack_128 = 0x631d74;
  FUN_005740f0();
  if (unaff_EBX == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  local_14._0_1_ = 5;
  uStack_128 = 0x631da4;
  FUN_00424c80();
  local_14._0_1_ = 0x1e;
  FUN_00757710();
  local_14 = (void *)CONCAT31(local_14._1_3_,5);
  if (7 < uStack_9c) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(puVar10 + 0x110) + 200))();
  (**(code **)(**(int **)(puVar10 + 0x114) + 0x94))();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_18 = 0x1f;
    uStack_110 = 0x631e28;
    FUN_00584c40();
    uStack_110 = 0x631e32;
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_18 = 5;
  }
  uStack_110 = 0x631e58;
  FUN_005740f0();
  if (DAT_00fe5ac8 == (undefined1 *)0x163) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_004068f0();
  uStack_18 = 0x20;
  FUN_00757710();
  uStack_18 = 5;
  if (7 < uStack_a0) {
    uStack_110 = 0x631ec3;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(puVar10 + 0x114) + 200))();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_18 = 0x21;
    uStack_110 = 0x631ef8;
    FUN_00584c40();
    uStack_110 = 0x631f02;
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_18 = 5;
  }
  uStack_110 = 0x631f28;
  FUN_005740f0();
  if (DAT_00fe5ac8 == (undefined1 *)0x163) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_004068f0();
  uStack_18 = 0x22;
  uStack_110 = 0x631f73;
  FUN_00757800();
  uStack_18 = 5;
  if (7 < uStack_a0) {
    uStack_110 = 0x631f8b;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(puVar10 + 0x118) + 200))();
  if (*(int *)(local_e4 + 0x90) == 0) {
LAB_00631ffb:
    (**(code **)(**(int **)(puVar10 + 0x11c) + 0x94))();
  }
  else {
    FUN_00489e00();
    puVar7 = (undefined2 *)FUN_00828ad0();
    if (puVar7 != (undefined2 *)0x0) {
      *(undefined2 *)(*(int *)(puVar10 + 0x11c) + 0x158) = *puVar7;
      FUN_00759ac0();
      goto LAB_00631ffb;
    }
  }
  local_ec = *(uint *)(local_e4 + 0x78);
  puVar8 = (undefined1 *)0x0;
  puStack_d0 = (undefined1 *)0x0;
  *(undefined4 *)(puVar10 + 0x140) = 0;
  local_e8 = (undefined1 *)0x0;
  if (0 < (int)local_ec) {
    iStack_d4 = 0;
    do {
      if (1 < (int)puVar8) break;
      puStack_d8 = (undefined1 *)0x0;
      puStack_e0 = (undefined1 *)
                   (((int *)(*(int *)(local_e4 + 0x94) + iStack_d4))[1] -
                    *(int *)(*(int *)(local_e4 + 0x94) + iStack_d4) >> 3);
      if (puStack_e0 != (undefined1 *)0x0) {
        puVar9 = (undefined4 *)(local_dc + (int)puVar8 * 4 + 0x128);
        do {
          if (1 < (int)puVar8) break;
          uVar11 = *(undefined4 *)
                    (*(int *)(iStack_d4 + *(int *)(local_e4 + 0x94)) + (int)puStack_d8 * 8);
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c._0_1_ = 0x23;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = CONCAT31(local_c._1_3_,5);
          }
          uStack_c8 = uVar11;
          FUN_008438c0();
          if ((iStack_cc == DAT_00f8d91c) || (*(int *)(iStack_cc + 0x10) == 0)) {
            uStack_110 = 0xffffffff;
            uStack_114 = 0x632121;
            (**(code **)(*(int *)*puVar9 + 0x1ac))();
            uStack_114 = 0;
          }
          else {
            uStack_110 = 0xffffffff;
            uStack_114 = 0x632107;
            (**(code **)(*(int *)*puVar9 + 0x1ac))();
            uStack_114 = 1;
          }
          uStack_118 = 0x63212f;
          (**(code **)(*(int *)*puVar9 + 0x90))();
          uStack_118 = 0x63213b;
          (**(code **)(*(int *)*puVar9 + 200))();
          *(int *)(local_dc + 0x140) = *(int *)(local_dc + 0x140) + 1;
          puVar8 = puStack_d0 + 1;
          puStack_d8 = puStack_d8 + 1;
          puVar9 = puVar9 + 1;
          puStack_d0 = puVar8;
        } while (puStack_d8 < puStack_e0);
      }
      iStack_d4 = iStack_d4 + 0x10;
      local_e8 = (undefined1 *)((int)local_e8 + 1);
    } while ((int)local_e8 < (int)local_ec);
  }
  puVar10 = local_dc;
  if ((int)puVar8 < 6) {
    puVar9 = (undefined4 *)(local_dc + (int)puVar8 * 4 + 0x128);
    iVar5 = 6 - (int)puVar8;
    do {
      uStack_110 = 0xffffffff;
      uStack_114 = 0x6321b6;
      (**(code **)(*(int *)*puVar9 + 0x1ac))();
      uStack_114 = 0;
      uStack_118 = 0x6321c4;
      (**(code **)(*(int *)*puVar9 + 0x90))();
      uStack_118 = 0x6321d0;
      (**(code **)(*(int *)*puVar9 + 200))();
      puVar9 = puVar9 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *(uint *)(puVar10 + 0x144) = (uint)((int)local_ec < 2);
  if (*(int *)(*(int *)(puVar10 + 0x124) + 0xcc) != 0) {
    FUN_0042c8e0();
  }
  if (7 < uStack_b0) {
    FUN_0089120c();
  }
  uStack_b0 = 7;
  uStack_b4 = 0;
  uStack_c4 = (short *)((uint)uStack_c4 & 0xffff0000);
  local_c = CONCAT31(local_c._1_3_,2);
  FUN_00757640();
  if (7 < uStack_5c) {
    FUN_0089120c();
  }
LAB_0063225a:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_ec);
  return;
}

