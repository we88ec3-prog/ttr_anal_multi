
void FUN_005e4b70(undefined4 param_1,uint param_2)

{
  short sVar1;
  code *pcVar2;
  undefined1 uVar3;
  uint uVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_EDX;
  short *psVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_6c [4];
  int iStack_68;
  int iStack_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093f026;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  iVar9 = 0;
  local_58 = param_1;
  iVar11 = 0;
  local_40 = 7;
  local_44 = 0;
  local_54[0] = local_54[0] & 0xffff0000;
  local_60 = in_EDX;
  FUN_00402160(&DAT_00bed1fc,0);
  local_c._1_3_ = 0;
  if (param_2 == 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c._0_1_ = 0;
    iVar9 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar9 == 0) {
      FUN_00404ba0();
      iVar11 = FUN_004d42e0();
      FUN_00404ba0();
      iVar9 = FUN_004d43d0();
    }
    else {
      iVar9 = *(int *)(iVar9 + 0x3d4);
      iVar11 = iVar9;
    }
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_004e1590(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c._0_1_ = 0;
    if (((param_2 < 10) && (iVar10 = param_2 * 0x210 + DAT_00f94304, *(int *)(iVar10 + 0x5c) != 0))
       && (iVar10 != 0)) {
      iVar9 = *(int *)(iVar10 + 8);
      iVar11 = iVar9;
    }
  }
  if (((local_5c == 0) || (local_5c <= iVar9)) && ((local_60 == 0 || (iVar11 <= local_60)))) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 0;
    }
    iStack_68 = 0x1c3;
    FUN_005740f0(&iStack_68);
    if (iStack_64 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(iStack_64 + 0x24) < 8) {
      psVar5 = (short *)(iStack_64 + 0x10);
      psVar8 = psVar5;
    }
    else {
      psVar5 = *(short **)(iStack_64 + 0x10);
      psVar8 = psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 4;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 0;
    }
    iStack_64 = 0x1c2;
    FUN_005740f0(&iStack_64);
    if (iStack_68 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(iStack_68 + 0x24) < 8) {
      psVar5 = (short *)(iStack_68 + 0x10);
      psVar8 = psVar5;
    }
    else {
      psVar5 = *(short **)(iStack_68 + 0x10);
      psVar8 = psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  FUN_00404300(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
  if (local_5c == 0) {
    if (local_60 == 0) {
      FUN_00402160(&DAT_00bed1fc,0);
      uVar3 = (undefined1)local_c;
    }
    else {
      iStack_68 = 0x1bb;
      iVar9 = FUN_00585620();
      FUN_005740f0(&iStack_68);
      if (iStack_64 == *(int *)(iVar9 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c._0_1_ = 8;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_c._0_1_ = 0;
      uVar3 = (undefined1)local_c;
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
        uVar3 = (undefined1)local_c;
      }
    }
  }
  else if (local_60 == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 0;
    }
    iStack_68 = 0x1ba;
    FUN_005740f0(&iStack_68);
    if (iStack_64 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar7 = FUN_004068f0();
    local_c._0_1_ = 7;
    FUN_004041f0(uVar7,0,0xffffffff);
    local_c._0_1_ = 0;
    uVar3 = (undefined1)local_c;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
      uVar3 = (undefined1)local_c;
    }
  }
  else {
    iStack_68 = 0x1b9;
    iVar9 = FUN_00585620();
    FUN_005740f0(&iStack_68);
    if (iStack_64 == *(int *)(iVar9 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar6 = (undefined4 *)(iStack_64 + 0x10);
    if (7 < *(uint *)(iStack_64 + 0x24)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    uVar7 = FUN_0040e460(puVar6);
    local_c._0_1_ = 5;
    FUN_004041f0(uVar7,0,0xffffffff);
    local_c._0_1_ = 0;
    uVar3 = (undefined1)local_c;
    local_c._0_1_ = 0;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
      uVar3 = (undefined1)local_c;
    }
  }
  local_c._0_1_ = uVar3;
  FUN_004041f0(local_54,0,0xffffffff);
  if (7 < local_40) {
    FUN_0089120c(local_54[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

