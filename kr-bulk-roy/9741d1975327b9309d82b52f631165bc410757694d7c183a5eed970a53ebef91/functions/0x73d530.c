
undefined4 FUN_0073d530(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int local_10 [3];
  
  local_10[0] = FUN_0073e670(*(undefined4 *)(in_EAX + 0x1c),*(undefined4 *)(in_EAX + 0x20),
                             *(undefined4 *)(in_EAX + 0x38));
  if (local_10[0] != 0) {
    local_10[2] = 0;
    local_10[1] = 0;
    FUN_0073d2d0();
    FUN_008438c0(local_10);
    uVar1 = FUN_0073f770(param_1 + 0x2c);
    return uVar1;
  }
  return 0;
}

