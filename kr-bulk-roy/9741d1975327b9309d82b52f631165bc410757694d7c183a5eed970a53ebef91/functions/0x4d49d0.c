
int FUN_004d49d0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_38;
  int local_34;
  int local_30 [4];
  undefined4 uStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092228c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((iVar1 != 0) && (iVar1 != 1)) {
    if (*(int *)(in_ECX + 0x44) != 0) {
      local_30[0] = 0x4079999a;
      local_30[1] = 0x3f800000;
      (**(code **)(**(int **)(in_ECX + 0x44) + 0x24))
                (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),0,local_30,1,0,
                 (uint)*(byte *)(in_ECX + 0x38) << 0x18 | 0xffffff,
                 DAT_00d61f20 ^ (uint)&stack0xffffffb8);
    }
    iVar4 = *(int *)(in_ECX + 0x6c) - *(int *)(in_ECX + 0x68);
    iVar1 = iVar4 * -0x6db6db6d;
    if (iVar4 / 0x1c + (iVar4 >> 0x1f) != iVar4 >> 0x1f) {
      local_38 = 0x28;
      local_34 = DAT_00e1951c;
      iVar1 = FUN_0043ffa0();
      FUN_00736180(&local_34);
      if ((local_30[0] != *(int *)(iVar1 + 0x10)) && (local_30[0] != -0x10)) {
        local_38 = *(int *)(local_30[0] + 0x54);
      }
      iVar1 = FUN_006dfc40();
      uStack_20 = *(undefined4 *)(iVar1 + 0x18);
      iVar1 = *(int *)(in_ECX + 0x10);
      uVar2 = (uint)(((*(int *)(in_ECX + 0x6c) - *(int *)(in_ECX + 0x68)) / 0x1c) * local_38) >> 1;
      local_30[3] = iVar1 - uVar2;
      iStack_1c = uVar2 + iVar1;
      local_30[2] = 0;
      iVar4 = DAT_00e1951c;
      FUN_0043ffa0(iVar1,DAT_00e1951c);
      FUN_007358b0(iVar4);
      iVar1 = *(int *)(in_ECX + 0x68);
      iVar5 = *(int *)(in_ECX + 0x6c) - iVar1;
      iVar4 = iVar5 >> 0x1f;
      uVar2 = 0;
      if (iVar5 / 0x1c + iVar4 != iVar4) {
        local_34 = 0;
        do {
          puVar6 = (undefined4 *)(iVar1 + local_34);
          if (7 < (uint)puVar6[5]) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if ((DAT_00fb7bc8 & 1) == 0) {
            DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
            uStack_c = 0;
            FUN_00734ef0();
            _atexit((_func_4879 *)&LAB_00bcd4f0);
            uStack_c = 0xffffffff;
          }
          uVar3 = (uint)*(byte *)(in_ECX + 0x38) << 0x18;
          FUN_00735c90(0,puVar6,*(uint *)(in_ECX + 0x78) & 0xffffff | uVar3,uVar3 | 0xffffff);
          local_30[3] = local_30[3] + local_38;
          iStack_1c = iStack_1c + local_38;
          iVar1 = *(int *)(in_ECX + 0x68);
          local_34 = local_34 + 0x1c;
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)((*(int *)(in_ECX + 0x6c) - iVar1) / 0x1c));
      }
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        uStack_c = 1;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
      }
      iVar4 = local_30[0];
      FUN_00736180(local_30);
      if ((local_34 == DAT_00fb7b80) || (iVar1 = local_34 + 0x10, local_34 = 0, iVar1 == 0)) {
        DAT_00fb7b90 = DAT_00fb7b8c;
        ExceptionList = local_14;
        return local_34;
      }
      DAT_00fb7b90 = iVar4;
    }
  }
  ExceptionList = local_14;
  return iVar1;
}

