
void FUN_0049d0b0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 auStack_5c [4];
  undefined4 *local_58;
  int local_54;
  undefined4 *local_50;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_0092a098;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  local_54 = param_1;
  if (*(int *)(param_1 + 0x24) != 0) {
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 0;
      FUN_00734ef0(DAT_00d61f20 ^ (uint)&stack0xffffff98);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_c = 0xffffffff;
    puVar4 = *(undefined4 **)(param_1 + 0x28);
    local_50 = DAT_00fb7b90;
    local_58 = puVar4;
    FUN_00736180(&local_58);
    if ((local_4c == DAT_00fb7b80) || (DAT_00fb7b90 = puVar4, local_4c == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    iVar1 = FUN_006dfc40();
    uVar5 = *(uint *)(iVar1 + 0x18) >> 1;
    iVar1 = FUN_006dfc40();
    uVar3 = *(uint *)(iVar1 + 0x1c) >> 1;
    uVar2 = 0;
    (**(code **)(**(int **)(param_1 + 0x18) + 0x20))(uVar5 - 0xe8,uVar3 - 0x5c,0,0xffffffff);
    uStack_24 = 7;
    uStack_28 = 0;
    uStack_38 = (undefined4 *)((uint)uStack_38._2_2_ << 0x10);
    local_c._1_3_ = 0;
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if ((DAT_00fb8e98 - (int)DAT_00fb8e94 & 0xfffffffcU) != 0) {
      uVar2 = *DAT_00fb8e94;
    }
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_c._0_1_ = 3;
      FUN_00590760();
      _atexit((_func_4879 *)&LAB_00bce760);
    }
    local_c._0_1_ = 1;
    FUN_004026e0(&DAT_00fdfb1c + (uVar2 & 0xff) * 0x1c,0,0xffffffff);
    if (uStack_24 < 8) {
      local_58 = &uStack_38;
    }
    else {
      local_58 = uStack_38;
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c._0_1_ = 4;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c._0_1_ = 1;
    }
    iVar1 = uVar3 + 0x49;
    FUN_00735ba0(uVar5 - 199,iVar1,0,0xffffffff,0xff000000);
    iStack_48 = uVar5 + 0x6a;
    iStack_3c = uVar3 + 0x61;
    iStack_40 = uVar5 + 0xce;
    iStack_44 = iVar1;
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c._0_1_ = 5;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c._0_1_ = 1;
    }
    if ((DAT_00fb8e88 - (int)DAT_00fb8e84 & 0xfffffffcU) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *DAT_00fb8e84;
    }
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_c._0_1_ = 6;
      FUN_00590760();
      _atexit((_func_4879 *)&LAB_00bce760);
      local_c._0_1_ = 1;
    }
    FUN_004026e0(&DAT_00fdfb1c + (uVar2 & 0xff) * 0x1c,0,0xffffffff);
    puVar4 = uStack_38;
    if (uStack_24 < 8) {
      puVar4 = &uStack_38;
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c._0_1_ = 7;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c._0_1_ = 1;
    }
    FUN_00735c90(&iStack_48,puVar4,0xffffffff,0xff000000);
    FUN_00557620(local_54);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c._0_1_ = 8;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    puVar4 = local_50;
    FUN_00736180(&local_50);
    if ((local_54 == DAT_00fb7b80) || (local_54 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = puVar4;
    }
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

