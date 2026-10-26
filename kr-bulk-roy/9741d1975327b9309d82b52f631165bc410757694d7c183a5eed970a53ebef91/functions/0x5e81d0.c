
void FUN_005e81d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091653a;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(in_ECX + 0x184);
  local_14 = *(undefined4 *)(iVar1 + 0x10);
  local_18 = *(undefined4 *)(iVar1 + 0x28);
  local_1c = *(undefined4 *)(iVar1 + 0x40);
  if (*(int *)(in_ECX + 0x188) != 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x188) + 0x30);
    local_20 = iVar1;
    if ((DAT_00fc1b00 & 1) == 0) {
      DAT_00fc1b00 = DAT_00fc1b00 | 1;
      local_8 = 0;
      FUN_00829b30(uVar4);
      _atexit(FUN_00bce3e0);
    }
    local_8 = 0xffffffff;
    iVar2 = *(int *)(in_ECX + 0x184);
    local_24 = *(int *)(iVar2 + 0x14);
    local_2c = iVar1;
    FUN_00835c70(&local_24);
    if (local_28 != DAT_00fc1b08) {
      local_28 = local_28 + 0x10;
      FUN_008438c0(&local_2c);
      if (local_24 != *(int *)(local_28 + 4)) {
        local_2c = *(int *)(iVar2 + 0x18) * iVar1;
        local_14 = FUN_008fed10();
      }
    }
    if ((DAT_00fc1b00 & 1) == 0) {
      DAT_00fc1b00 = DAT_00fc1b00 | 1;
      local_8 = 1;
      FUN_00829b30(uVar4);
      _atexit(FUN_00bce3e0);
      local_8 = 0xffffffff;
    }
    iVar2 = *(int *)(in_ECX + 0x184);
    local_2c = *(int *)(iVar2 + 0x2c);
    local_24 = iVar1;
    FUN_00835c70(&local_2c);
    if (local_28 != DAT_00fc1b08) {
      local_2c = local_28 + 0x10;
      FUN_008438c0(&local_24);
      if (local_28 != *(int *)(local_2c + 4)) {
        local_2c = *(int *)(iVar2 + 0x30) * iVar1;
        local_18 = FUN_008fed10();
      }
    }
    if ((DAT_00fc1b00 & 1) == 0) {
      DAT_00fc1b00 = DAT_00fc1b00 | 1;
      local_8 = 2;
      FUN_00829b30();
      _atexit(FUN_00bce3e0);
    }
    iVar2 = *(int *)(in_ECX + 0x184);
    local_2c = *(int *)(iVar2 + 0x44);
    local_24 = iVar1;
    FUN_00835c70(&local_2c);
    iVar3 = local_28;
    if (local_28 != DAT_00fc1b08) {
      FUN_008438c0(&local_24);
      if (local_2c != *(int *)(iVar3 + 0x14)) {
        local_2c = *(int *)(iVar2 + 0x48) * iVar1;
        local_1c = FUN_008fed10();
      }
    }
  }
  *param_1 = local_14;
  *param_2 = local_18;
  *param_3 = local_1c;
  ExceptionList = local_10;
  return;
}

