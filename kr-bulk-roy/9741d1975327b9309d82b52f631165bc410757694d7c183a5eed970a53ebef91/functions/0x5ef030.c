
undefined4 FUN_005ef030(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091642e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x184) + 0x4c);
  if (*(int *)(in_ECX + 0x188) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x188) + 0x30);
    local_14 = uVar3;
    if ((DAT_00fc1b00 & 1) == 0) {
      DAT_00fc1b00 = DAT_00fc1b00 | 1;
      local_8 = 0;
      FUN_00829b30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit(FUN_00bce3e0);
    }
    local_18 = *(undefined4 *)(*(int *)(in_ECX + 0x184) + 0x50);
    local_20 = uVar1;
    FUN_00835c70(&local_18);
    iVar2 = local_1c;
    if (local_1c != DAT_00fc1b08) {
      FUN_008438c0(&local_20);
      if (local_1c != *(int *)(iVar2 + 0x14)) {
        local_20 = *(undefined4 *)(local_1c + 0x10);
        uVar3 = FUN_008fed10();
        ExceptionList = local_10;
        return uVar3;
      }
      ExceptionList = local_10;
      return local_14;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

