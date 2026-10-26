
void FUN_0042dc60(int param_1)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  ushort *puVar10;
  int *piVar11;
  bool bVar12;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942c10;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = *(int *)(param_1 + 0xf8);
  local_34 = param_1;
  local_14 = uVar4;
  if (*(char *)(iVar6 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar4);
  }
  local_30 = (ushort *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  FUN_004026e0(iVar6 + 0x108,0,0xffffffff);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  puVar5 = local_30;
  if (local_1c < 8) {
    puVar5 = (ushort *)&local_30;
  }
  puVar10 = &DAT_00bed1fc;
  do {
    uVar1 = *puVar5;
    bVar12 = uVar1 < *puVar10;
    if (uVar1 != *puVar10) {
LAB_0042dd16:
      iVar6 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_0042dd1b;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar5[1];
    bVar12 = uVar1 < puVar10[1];
    if (uVar1 != puVar10[1]) goto LAB_0042dd16;
    puVar5 = puVar5 + 2;
    puVar10 = puVar10 + 2;
  } while (uVar1 != 0);
  iVar6 = 0;
LAB_0042dd1b:
  if (iVar6 == 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 0;
    local_38 = 0x196;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8._0_1_ = 0;
    }
    local_34 = 0x38;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (undefined4 *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8._0_1_ = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8._0_1_ = 0;
    }
    FUN_007532b0(&DAT_00f94810,puVar7,0,0);
    FUN_0042e340();
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    goto LAB_0042e04e;
  }
  if ((DAT_00fb75c0 & 1) == 0) {
    DAT_00fb75c0 = DAT_00fb75c0 | 1;
    local_8._0_1_ = 4;
    local_8._1_3_ = 0;
    FUN_0081e5f0();
    _atexit((_func_4879 *)&LAB_00bcd250);
  }
  local_8._0_1_ = 0;
  iVar6 = FUN_0081ec70(0x73);
  if (iVar6 == 0) {
    local_34 = 0x196;
    iVar6 = FUN_005854b0();
    FUN_005740f0(&local_34);
    if (local_38 == *(int *)(iVar6 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_38 + 0x24) < 8) {
      iVar6 = local_38 + 0x10;
    }
    else {
      iVar6 = *(int *)(local_38 + 0x10);
    }
    local_34 = 0x32;
    iVar8 = FUN_005854b0();
    FUN_005740f0(&local_34);
    if (local_38 == *(int *)(iVar8 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (undefined4 *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    FUN_00404b10(0xca,puVar7,iVar6,0,0);
    FUN_0042e340();
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    goto LAB_0042e04e;
  }
  iVar6 = *(int *)(param_1 + 0xf8);
  if (*(char *)(iVar6 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar4);
  }
  FUN_004026e0(iVar6 + 0x108,0,0xffffffff);
  iVar6 = *(int *)(param_1 + 0xfc);
  if (*(char *)(iVar6 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  uVar9 = FUN_00432b90(iVar6 + 0x108);
  *(undefined4 *)(param_1 + 0x154) = uVar9;
  iVar6 = *(int *)(*(int *)(param_1 + 0x100) + 0x24c);
  if (iVar6 == 0) {
LAB_0042dfd2:
    uVar3 = 0xff;
  }
  else {
    iVar6 = *(int *)(iVar6 + 0xcc);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
    }
    if (iVar6 == 0) goto LAB_0042dfd2;
    uVar3 = (undefined1)*(undefined4 *)(iVar6 + 0x20);
  }
  *(undefined1 *)(param_1 + 0x130) = uVar3;
  *(byte *)(param_1 + 0x158) = (byte)(*(uint *)(*(int *)(param_1 + 0x104) + 0x28) >> 9) & 1;
  iVar6 = 0;
  piVar11 = (int *)(param_1 + 0x11c);
  do {
    iVar8 = *piVar11;
    if (*(char *)(iVar8 + 0x141) != '\0') {
      FUN_006edb10("Not supported operation");
    }
    uVar3 = FUN_00432b90(iVar8 + 0x108);
    *(undefined1 *)(local_34 + 0x131 + iVar6) = uVar3;
    iVar6 = iVar6 + 1;
    piVar11 = piVar11 + 1;
  } while (iVar6 < 3);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
LAB_0042e04e:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

