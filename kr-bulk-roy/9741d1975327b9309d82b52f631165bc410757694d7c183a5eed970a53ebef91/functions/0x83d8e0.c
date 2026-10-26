
void FUN_0083d8e0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e4d0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3b0) != *(int *)(in_ECX + 0x3b4)) {
    local_2c = 0;
    local_24 = 0;
    local_8 = 0;
    local_28 = in_ECX;
    FUN_00840310(&local_20,*(int *)(in_ECX + 0x3b0),*(undefined4 *)(in_ECX + 0x3b4),0);
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      if (local_18 != 0) {
        uVar3 = local_1c;
        uVar2 = FUN_0083eef0(local_1c);
        FUN_00863050(uVar2,uVar3);
      }
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
    local_8 = 0xffffffff;
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
  }
  if (*(int *)(in_ECX + 0x3c8) != 0) {
    local_2c = 0;
    local_24 = 0;
    local_8 = 1;
    local_28 = in_ECX;
    FUN_008403d0(&local_20,**(undefined4 **)(in_ECX + 0x3c4),*(undefined4 **)(in_ECX + 0x3c4),0);
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      if (local_18 != 0) {
        uVar3 = local_1c;
        uVar2 = FUN_0083eef0(local_1c);
        FUN_00863050(uVar2,uVar3);
      }
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
    local_8 = 0xffffffff;
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
  }
  if (*(int *)(in_ECX + 0x3d8) != 0) {
    local_2c = 0;
    local_24 = 0;
    local_8 = 2;
    local_28 = in_ECX;
    FUN_008403d0(&local_20,**(undefined4 **)(in_ECX + 0x3d4),*(undefined4 **)(in_ECX + 0x3d4),0);
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      if (local_18 != 0) {
        uVar3 = FUN_0083eef0(local_1c);
        FUN_00863050(uVar3,local_1c);
      }
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
    local_8 = 0xffffffff;
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
  }
  if (*(int *)(in_ECX + 1000) != 0) {
    local_20 = 0;
    local_18 = 0;
    local_8 = 3;
    FUN_008403d0(&local_2c,**(undefined4 **)(in_ECX + 0x3e4),*(undefined4 **)(in_ECX + 0x3e4),0);
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      if (local_24 != 0) {
        uVar3 = FUN_0083eef0(local_28,uVar1);
        FUN_00863050(uVar3,local_28);
      }
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
    local_8 = 0xffffffff;
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      FUN_0083f0d0(&DAT_00fbacc0,local_14,DAT_00fbacc0,DAT_00fbacc4);
    }
  }
  ExceptionList = local_10;
  return;
}

