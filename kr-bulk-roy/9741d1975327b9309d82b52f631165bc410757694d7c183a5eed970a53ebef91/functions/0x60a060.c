
undefined4 FUN_0060a060(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x40] + 0x28) >> 7 & 1) != 0) {
      FUN_00609550(in_ECX);
    }
    return 1;
  }
  if ((param_1 != 0xe) && (param_1 != 0x2af9)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

