
undefined4 FUN_0073d360(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = FUN_0073e260(param_1 + 4,*(undefined4 *)(in_EAX + 0x1c),*(undefined4 *)(in_EAX + 0x20),
                          *(undefined4 *)(in_EAX + 0x38));
  if (local_10 != 0) {
    local_8 = 0;
    local_c = 0;
    FUN_0073d2d0();
    FUN_008438c0(&local_10);
    if (local_14 == *(int *)(param_1 + 0x20)) {
      local_28 = 0;
    }
    else {
      local_28 = *(undefined4 *)(local_14 + 0x10);
    }
    local_1c = *(undefined4 *)(in_EAX + 0x34);
    local_20 = (undefined1)local_c;
    local_24 = local_8;
    local_18 = *(undefined4 *)(in_EAX + 0x38);
    uVar1 = FUN_0073f8e0(param_1 + 0x2c,&local_28);
    return uVar1;
  }
  return 0;
}

