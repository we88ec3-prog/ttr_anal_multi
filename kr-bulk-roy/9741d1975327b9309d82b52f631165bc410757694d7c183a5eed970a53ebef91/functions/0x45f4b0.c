
void FUN_0045f4b0(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  code *pcVar4;
  short *psVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 **ppuVar8;
  undefined4 *puVar9;
  int in_EDX;
  short *psVar10;
  int iVar11;
  undefined1 *puVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined2 auStack_cc [8];
  undefined4 local_bc;
  undefined4 local_b8;
  uint *puStack_b4;
  undefined4 uStack_b0;
  undefined4 **ppuStack_ac;
  undefined2 auStack_a8 [2];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined1 *puStack_98;
  short *psStack_94;
  undefined1 auStack_7c [4];
  int local_78;
  int local_74;
  undefined4 *local_70;
  undefined1 *local_6c;
  undefined4 *local_68;
  undefined4 *puStack_64;
  int *piStack_60;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined1 local_40 [20];
  uint local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009316fc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  local_78 = param_1;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120();
    psStack_94 = (short *)0x45f521;
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_74 = param_2;
  psStack_94 = (short *)0x45f549;
  FUN_008438c0();
  if ((local_68 == DAT_00f8d91c) || (psVar10 = (short *)local_68[4], psVar10 == (short *)0x0))
  goto LAB_0045f7d6;
  if (7 < *(uint *)(psVar10 + 10)) {
    psVar10 = *(short **)psVar10;
  }
  local_48 = 7;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffff0000;
  psVar5 = psVar10;
  do {
    sVar2 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar2 != 0);
  puStack_98 = (undefined1 *)0x45f5aa;
  psStack_94 = psVar10;
  FUN_00402160();
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  if (1 < in_EDX) {
    puStack_98 = (undefined1 *)FUN_004068f0();
    psStack_94 = (short *)0x0;
    local_c._0_1_ = 2;
    iStack_9c = 0x45f5e1;
    FUN_004041f0();
    local_c._0_1_ = 1;
    if (7 < local_2c) {
      psStack_94 = (short *)0x45f5fa;
      FUN_0089120c();
    }
  }
  if (local_70 == (undefined4 *)0x0) {
    if (param_3 != 0) {
      psStack_94 = (short *)&DAT_0000007b;
      local_6c = (undefined1 *)auStack_cc;
      local_b8 = 7;
      local_bc = 0;
      auStack_cc[0] = 0;
      FUN_004026e0(local_5c,0,0xffffffff);
      uVar14 = 0x7c;
      local_c._0_1_ = 6;
      FUN_00585620(0x7c);
      uVar14 = FUN_00585330(uVar14);
      local_c = CONCAT31(local_c._1_3_,1);
      FUN_00460780(uVar14);
      goto LAB_0045f79c;
    }
  }
  else if (param_3 == 0) {
    local_6c = (undefined1 *)auStack_a8;
    ppuStack_ac = (undefined4 **)0xffffffff;
    uStack_b0 = 0;
    puStack_b4 = local_5c;
    psStack_94 = (short *)0x7;
    puStack_98 = (undefined1 *)0x0;
    auStack_a8[0] = 0;
    local_b8 = 0x45f699;
    FUN_004026e0();
    local_c._0_1_ = 4;
    local_70 = (undefined4 *)&DAT_0000007b;
    ppuStack_ac = (undefined4 **)0x45f6ae;
    iVar6 = FUN_00585620();
    ppuStack_ac = &local_70;
    uStack_b0 = 0x45f6c0;
    FUN_005740f0();
    if (local_74 == *(int *)(iVar6 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    ppuStack_ac = (undefined4 **)(local_74 + 0x10);
    if (7 < *(uint *)(local_74 + 0x24)) {
      ppuStack_ac = (undefined4 **)*ppuStack_ac;
    }
    local_c._0_1_ = 1;
    uStack_b0 = 0x45f6f2;
    FUN_00460780();
    iVar6 = *(int *)(*(int *)(local_78 + 4) + 0x100);
    local_c = CONCAT31(local_c._1_3_,5);
    FUN_007578f0();
    psStack_94 = (short *)&DAT_0000007b;
    puStack_98 = local_40;
    uStack_a0 = 0x45f724;
    iStack_9c = iVar6 + 0xe8;
    FUN_00759ed0();
    if (7 < local_2c) {
      psStack_94 = (short *)0x45f739;
      FUN_0089120c();
    }
  }
  else {
    psStack_94 = (short *)&DAT_0000007b;
    local_70 = &uStack_b0;
    local_6c = (undefined1 *)auStack_cc;
    local_b8 = 7;
    local_bc = 0;
    auStack_cc[0] = 0;
    FUN_004026e0(local_5c,0,0xffffffff);
    uVar14 = 0x7a;
    local_c._0_1_ = 3;
    FUN_00585620(0x7a);
    uVar14 = FUN_00585330(uVar14);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_004606f0(uVar14);
LAB_0045f79c:
    puStack_b4 = (uint *)0x45f7b7;
    FUN_00759e60();
  }
  local_c = 0xffffffff;
  if (7 < local_48) {
    psStack_94 = (short *)0x45f7d3;
    FUN_0089120c();
  }
LAB_0045f7d6:
  iVar6 = *(int *)(local_78 + 4);
  psVar10 = *(short **)(*(int *)(iVar6 + 0xf8) + 0xcc);
  puVar12 = (undefined1 *)((*(int *)(iVar6 + 0x108) - *(int *)(iVar6 + 0x104)) / 0x18);
  local_6c = puVar12;
  if (psVar10 != (short *)0x0) {
    puStack_98 = (undefined1 *)0x45f817;
    psStack_94 = psVar10;
    FUN_00408920();
  }
  local_68 = (undefined4 *)0x0;
  if (puVar12 != (undefined1 *)0x0) {
    local_74 = 0;
    do {
      piVar13 = (int *)(*(int *)(*(int *)(local_78 + 4) + 0x104) + local_74);
      piStack_60 = piVar13;
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 7;
        FUN_0051c120();
        psStack_94 = (short *)0x45f86f;
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      cVar1 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
      puVar7 = (undefined4 *)DAT_00f8d91c[1];
      local_70 = DAT_00f8d91c;
      while (puVar9 = puVar7, cVar1 == '\0') {
        if ((int)puVar9[3] < piVar13[2]) {
          puVar7 = (undefined4 *)puVar9[2];
          puVar9 = local_70;
        }
        else {
          puVar7 = (undefined4 *)*puVar9;
        }
        cVar1 = *(char *)((int)puVar7 + 0x15);
        local_70 = puVar9;
      }
      if ((local_70 == DAT_00f8d91c) || (piVar13[2] < (int)local_70[3])) {
        puStack_64 = DAT_00f8d91c;
        ppuVar8 = &puStack_64;
      }
      else {
        ppuVar8 = &local_70;
      }
      if ((*ppuVar8 != DAT_00f8d91c) && (iVar6 = (*ppuVar8)[4], iVar6 != 0)) {
        iVar11 = *(int *)(*(int *)(*(int *)(local_78 + 4) + 0xf8) + 0xcc);
        if ((iVar11 == 0) ||
           (((int)local_68 < 0 ||
            (*(int *)(iVar11 + 0xac) - *(int *)(iVar11 + 0xa8) >> 2 <= (int)local_68)))) {
          iVar11 = 0;
        }
        else {
          iVar11 = *(int *)(*(int *)(iVar11 + 0xa8) + (int)local_68 * 4);
        }
        FUN_00757710();
        psStack_94 = (short *)piStack_60[1];
        puStack_98 = (undefined1 *)*piStack_60;
        iStack_9c = *(int *)(iVar6 + 0x1c);
        uStack_a0 = *(undefined4 *)(iVar6 + 0x20);
        uStack_a4 = 0x45f953;
        (**(code **)(**(int **)(iVar11 + 0x248) + 0x1ac))();
        puVar12 = local_6c;
      }
      local_74 = local_74 + 0x18;
      local_68 = (undefined4 *)((int)local_68 + 1);
    } while (local_68 < puVar12);
  }
  piVar13 = *(int **)(*(int *)(local_78 + 4) + 0xf8);
  puVar7 = (undefined4 *)piVar13[0x19];
  for (puVar9 = (undefined4 *)*puVar7; puVar9 != puVar7; puVar9 = (undefined4 *)*puVar9) {
    if ((*(int *)(puVar9[2] + 0x60) != 0) && (piVar3 = *(int **)(puVar9[2] + 0x1c), piVar3[2] != 6))
    {
      psStack_94 = (short *)0x45f99d;
      (**(code **)(*piVar3 + 0x30))();
    }
  }
  (**(code **)(*piVar13 + 0x128))();
  iVar6 = local_78;
  (**(code **)(**(int **)(*(int *)(local_78 + 4) + 0xf8) + 200))();
  (**(code **)(**(int **)(iVar6 + 4) + 0xd0))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

