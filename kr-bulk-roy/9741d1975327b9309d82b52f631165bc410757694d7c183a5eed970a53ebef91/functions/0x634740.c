
void FUN_00634740(int param_1,short *param_2,char param_3)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined2 auStack_e8 [6];
  undefined4 uStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  int local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 auStack_8c [16];
  uint uStack_7c;
  uint uStack_78;
  uint local_70;
  undefined4 uStack_60;
  uint local_5c;
  undefined2 uStack_54;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 uStack_10;
  undefined3 uStack_f;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  uStack_10 = 0xc4;
  uStack_f = 0x948b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_bc;
  ExceptionList = &local_14;
  local_ac = param_1;
  if (param_3 == '\0') {
    FUN_00757710();
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 0;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_b4 = (undefined1 *)0x158;
    FUN_005740f0();
    if (local_b8 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00483f00();
    local_c = 1;
    FUN_00757800();
    if (7 < local_5c) {
      FUN_0089120c();
    }
  }
  local_94 = 7;
  local_98 = 0;
  local_a8 = (uint)local_a8._2_2_ << 0x10;
  local_c = 2;
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(short **)param_2;
  }
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  puStack_d8 = (undefined1 *)0x6348da;
  FUN_00402160();
  puStack_d8 = (undefined1 *)0x6348ea;
  FUN_00404300();
  uStack_40 = 7;
  uStack_44 = 0;
  uStack_54 = 0;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c._0_1_ = 4;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  iVar6 = local_b0;
  local_c._0_1_ = 3;
  local_b8 = *(undefined1 **)(local_b0 + 0x20);
  FUN_0050db00();
  if ((local_b4 != DAT_00fe17c4) && (local_b4 + 0x10 != (undefined1 *)0x0)) {
    local_b8 = (undefined1 *)auStack_e8;
    puStack_d8 = (undefined1 *)0x0;
    auStack_e8[0] = 0;
    FUN_004026e0(local_b4 + 0x10,0);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 6;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 5;
    local_b8 = (undefined1 *)0x16f;
    FUN_005740f0();
    if (local_b4 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    local_c._0_1_ = 3;
    psVar4 = (short *)FUN_00424c80();
    local_c._0_1_ = 7;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    puStack_d8 = (undefined1 *)0x634a5a;
    FUN_00404300();
    local_c._0_1_ = 3;
    if (7 < local_5c) {
      FUN_0089120c();
    }
    puStack_d8 = (undefined1 *)0x634a85;
    FUN_00404300();
    iVar6 = local_b0;
  }
  uStack_24 = 7;
  uStack_28 = 0;
  uStack_38 = 0;
  uVar2 = *(ushort *)(iVar6 + 0x28);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 9;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c._0_1_ = 8;
  local_b8 = (undefined1 *)(uVar2 | 0x6000000);
  iVar5 = FUN_004f7a70();
  if (*(uint *)(iVar5 + 0x30) < 8) {
    iVar5 = iVar5 + 0x1c;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x1c);
  }
  if (iVar5 != 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 10;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 8;
    }
    local_b8 = (undefined1 *)0x171;
    FUN_005740f0();
    if (local_b4 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar4 = (short *)FUN_004ed610();
    local_c._0_1_ = 0xb;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    puStack_d8 = (undefined1 *)0x634bc0;
    FUN_00404300();
    local_c._0_1_ = 8;
    if (7 < local_5c) {
      FUN_0089120c();
    }
    puStack_d8 = (undefined1 *)0x634bec;
    FUN_00404300();
  }
  uVar2 = *(ushort *)(iVar6 + 0x2c);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 0xc;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c._0_1_ = 8;
  }
  local_b8 = (undefined1 *)(uVar2 | 0x6000000);
  iVar6 = FUN_004f7a70();
  if (*(uint *)(iVar6 + 0x30) < 8) {
    iVar6 = iVar6 + 0x1c;
  }
  else {
    iVar6 = *(int *)(iVar6 + 0x1c);
  }
  if (iVar6 != 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0xd;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 8;
    }
    local_b8 = (undefined1 *)0x172;
    FUN_005740f0();
    if (local_b4 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar4 = (short *)FUN_004ed610();
    local_c._0_1_ = 0xe;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    puStack_d8 = (undefined1 *)0x634d01;
    FUN_00404300();
    local_c._0_1_ = 8;
    if (7 < local_5c) {
      FUN_0089120c();
    }
    puStack_d8 = (undefined1 *)0x634d2c;
    FUN_00404300();
  }
  local_5c = 7;
  uStack_60 = 0;
  local_70 = local_70 & 0xffff0000;
  local_c._0_1_ = 0xf;
  FUN_006343d0();
  puStack_d8 = auStack_8c;
  uStack_dc = 0x634d60;
  FUN_0044fa80();
  local_c._0_1_ = 0x10;
  FUN_00402800();
  local_c._0_1_ = 0xf;
  if (7 < uStack_78) {
    FUN_0089120c();
  }
  puStack_d8 = (undefined1 *)0x634daf;
  FUN_00765f70();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 0x11;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 0xf;
  }
  local_b8 = (undefined1 *)0x160;
  FUN_005740f0();
  if (local_b4 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_004068f0();
  iVar6 = local_ac;
  local_c._0_1_ = 0x12;
  FUN_00757800();
  local_c._0_1_ = 0xf;
  if (7 < uStack_78) {
    FUN_0089120c();
  }
  if (*(int *)(local_b0 + 0x88) == 0) {
    if (*(int *)(local_b0 + 0x80) != 0) {
      (**(code **)(**(int **)(iVar6 + 0x100) + 0x94))();
      FUN_00404ba0();
      FUN_008fed10();
      local_b8 = &stack0xffffff14;
      FUN_00412df0();
      uStack_10 = 0x17;
      puStack_bc = (undefined1 *)0x160;
      iVar5 = FUN_00585620();
      FUN_005740f0(&puStack_bc);
      if (local_b8 == *(undefined1 **)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      puVar7 = (undefined4 *)(local_b8 + 0x10);
      if (7 < *(uint *)(local_b8 + 0x24)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      uStack_10 = 0xf;
      FUN_00424c80(puVar7);
      uStack_10 = 0x18;
      FUN_00757710();
      uStack_10 = 0xf;
      if (7 < uStack_7c) {
        puStack_d8 = (undefined1 *)0x6350a7;
        FUN_0089120c();
      }
      (**(code **)(**(int **)(iVar6 + 0x100) + 200))();
    }
  }
  else {
    (**(code **)(**(int **)(iVar6 + 0x100) + 0x94))();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_10 = 0x13;
      FUN_004e1590();
      puStack_d8 = (undefined1 *)0x634eb6;
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_10 = 0xf;
    }
    FUN_008fed10();
    puStack_bc = &stack0xffffff14;
    FUN_00412df0();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_10 = 0x15;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    uStack_10 = 0x14;
    puStack_bc = (undefined1 *)0x15f;
    FUN_005740f0(&puStack_bc);
    if (local_b8 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar7 = (undefined4 *)(local_b8 + 0x10);
    if (7 < *(uint *)(local_b8 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    uStack_10 = 0xf;
    FUN_00424c80(puVar7);
    uStack_10 = 0x16;
    FUN_00757710();
    uStack_10 = 0xf;
    if (7 < uStack_7c) {
      puStack_d8 = (undefined1 *)0x634faf;
      FUN_0089120c();
    }
    (**(code **)(**(int **)(iVar6 + 0x100) + 200))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 0x19;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c._0_1_ = 0xf;
  }
  FUN_008fed10();
  local_b8 = (undefined1 *)auStack_e8;
  FUN_00412df0();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 0x1b;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c._0_1_ = 0x1a;
  local_b8 = (undefined1 *)0x163;
  FUN_005740f0();
  if (local_b4 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  local_c._0_1_ = 0xf;
  FUN_00424c80();
  local_c._0_1_ = 0x1c;
  FUN_00757710();
  local_c._0_1_ = 0xf;
  if (7 < uStack_78) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(iVar6 + 0x104) + 200))();
  local_b8 = (undefined1 *)auStack_e8;
  FUN_00412df0();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 0x1e;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c._0_1_ = 0x1d;
  local_b8 = (undefined1 *)0x164;
  FUN_005740f0();
  if (local_b4 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  local_c._0_1_ = 0xf;
  FUN_00424c80();
  local_c._0_1_ = 0x1f;
  FUN_00757710();
  local_c._0_1_ = 0xf;
  if (7 < uStack_78) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(iVar6 + 0x108) + 200))();
  local_b8 = (undefined1 *)auStack_e8;
  FUN_00412df0();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 0x21;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c._0_1_ = 0x20;
  local_b8 = &DAT_00000165;
  FUN_005740f0();
  if (local_b4 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  local_c._0_1_ = 0xf;
  FUN_00424c80();
  local_c._0_1_ = 0x22;
  FUN_00757800();
  local_c._0_1_ = 0xf;
  if (7 < uStack_78) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(iVar6 + 0x10c) + 200))();
  if (*(int *)(local_b0 + 0x90) != 0) {
    if ((DAT_00fd93f4 & 1) == 0) {
      DAT_00fd93f4 = DAT_00fd93f4 | 1;
      local_b8 = &stack0xffffff30;
      local_c._0_1_ = 0x23;
      FUN_00828c00();
      _atexit(FUN_00bcde40);
      local_c._0_1_ = 0xf;
    }
    puVar8 = (undefined2 *)FUN_00828ad0();
    if (puVar8 == (undefined2 *)0x0) goto LAB_0063547c;
    *(undefined2 *)(*(int *)(iVar6 + 0x110) + 0x158) = *puVar8;
    FUN_00759ac0();
  }
  (**(code **)(**(int **)(iVar6 + 0x110) + 0x94))();
LAB_0063547c:
  if (7 < local_5c) {
    FUN_0089120c();
  }
  if (7 < local_94) {
    FUN_0089120c();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_bc);
  return;
}

