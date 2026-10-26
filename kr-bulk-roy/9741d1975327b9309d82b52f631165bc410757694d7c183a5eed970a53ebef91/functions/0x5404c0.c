
void FUN_005404c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009220e8;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  iVar4 = *(int *)(in_ECX + 0x48) - *(int *)(in_ECX + 0x44);
  iVar3 = iVar4 >> 0x1f;
  if (iVar4 / 0x1c + iVar3 != iVar3) {
    local_34 = 0x28;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 0;
      FUN_00734ef0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_c = 0xffffffff;
    local_38 = DAT_00e44af4;
    FUN_00736180(&local_38);
    if ((local_30 != DAT_00fb7b80) && (local_30 != -0x10)) {
      local_34 = *(int *)(local_30 + 0x54);
    }
    iVar3 = FUN_006dfc40();
    local_1c = *(int *)(in_ECX + 0x10);
    local_20 = *(undefined4 *)(iVar3 + 0x18);
    uVar6 = 0;
    local_24 = local_1c + -0x20;
    local_28 = 0;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 1;
      FUN_00734ef0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    iVar3 = DAT_00e44af4;
    local_2c = DAT_00fb7b90;
    local_30 = DAT_00e44af4;
    FUN_00736180(&local_30);
    if ((local_38 == DAT_00fb7b80) || (local_38 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = iVar3;
    }
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar5 = *(int *)(in_ECX + 0x48) - iVar3;
    iVar4 = iVar5 >> 0x1f;
    if (iVar5 / 0x1c + iVar4 != iVar4) {
      local_38 = 0;
      do {
        puVar7 = (undefined4 *)(iVar3 + local_38);
        if (7 < (uint)puVar7[5]) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_c = 2;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_c = 0xffffffff;
        }
        FUN_00735c90(0,puVar7,(uint)*(byte *)(in_ECX + 0x38) << 0x18 |
                              *(uint *)(in_ECX + 0x54) & 0xffffff,0xff000000);
        local_24 = local_24 + local_34;
        local_1c = local_1c + local_34;
        iVar3 = *(int *)(in_ECX + 0x44);
        local_38 = local_38 + 0x1c;
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)((*(int *)(in_ECX + 0x48) - iVar3) / 0x1c));
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 3;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    uVar1 = local_2c;
    FUN_00736180(&local_2c);
    if ((local_30 == DAT_00fb7b80) || (local_30 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
      ExceptionList = local_14;
      return;
    }
    DAT_00fb7b90 = uVar1;
  }
  ExceptionList = local_14;
  return;
}

