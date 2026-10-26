
undefined4 FUN_00636ed0(int param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (param_1 == 0xd) {
    FUN_00636b70();
    return 1;
  }
  if (param_1 != 0xe) {
    if (param_1 == 0x2af9) {
      (**(code **)(*in_ECX + 0xd4))();
      return 1;
    }
    return 0;
  }
  uVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x18))(0xe);
  return uVar1;
}

