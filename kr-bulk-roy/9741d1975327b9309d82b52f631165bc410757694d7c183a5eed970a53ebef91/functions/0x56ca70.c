
void FUN_0056ca70(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_EDI;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921e86;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = 0;
  if (unaff_EDI[10] != 0) {
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 0;
      FUN_00734ef0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_2c = DAT_00fb7b90;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 1;
      FUN_00734ef0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_8 = 0xffffffff;
    uVar1 = unaff_EDI[0x10];
    local_20 = uVar1;
    FUN_00736180(&local_20);
    if ((local_1c == DAT_00fb7b80) || (DAT_00fb7b90 = uVar1, local_1c == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    local_1c = unaff_EDI[0x12] + -0x400;
    local_18 = unaff_EDI[0x13] + -0x300;
    iVar6 = 0;
    local_14 = 0;
    if (unaff_EDI[8] == 0) {
      local_1c = local_1c / 2;
    }
    if (unaff_EDI[9] == 0) {
      local_18 = local_18 / 2;
    }
    if (0 < (int)unaff_EDI[0xd]) {
      do {
        puVar4 = unaff_EDI;
        if (7 < (uint)unaff_EDI[5]) {
          puVar4 = (undefined4 *)*unaff_EDI;
        }
        if (*(short *)((int)puVar4 + iVar5 * 2) == 10) {
          if ((DAT_00fb7bc8 & 1) == 0) {
            DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
            local_8 = 2;
            FUN_00734ef0(uVar3);
            _atexit((_func_4879 *)&LAB_00bcd4f0);
            local_8 = 0xffffffff;
          }
          local_24 = unaff_EDI[0x10];
          FUN_00736180(&local_24);
          if (local_28 == DAT_00fb7b80) {
            local_14 = local_14 + iRam00000044;
            iVar6 = 0;
          }
          else {
            local_14 = local_14 + *(int *)(local_28 + 0x54);
            iVar6 = 0;
          }
        }
        else {
          puVar4 = unaff_EDI;
          if (7 < (uint)unaff_EDI[5]) {
            puVar4 = (undefined4 *)*unaff_EDI;
          }
          local_20 = (uint)*(ushort *)((int)puVar4 + iVar5 * 2);
          if ((DAT_00fb7bc8 & 1) == 0) {
            DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
            local_8 = 3;
            FUN_00734ef0(uVar3);
            _atexit((_func_4879 *)&LAB_00bcd4f0);
            local_8 = 0xffffffff;
          }
          FUN_00735ba0(unaff_EDI[0xb] + local_1c + iVar6,unaff_EDI[0xc] + local_18 + local_14,0,
                       unaff_EDI[7],0);
          iVar6 = *(int *)(unaff_EDI[0x11] + iVar5 * 4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)unaff_EDI[0xd]);
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 4;
      FUN_00734ef0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    uVar2 = local_2c;
    FUN_00736180(&local_2c);
    if ((local_28 == DAT_00fb7b80) || (local_28 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
      ExceptionList = local_10;
      return;
    }
    DAT_00fb7b90 = uVar2;
  }
  ExceptionList = local_10;
  return;
}

