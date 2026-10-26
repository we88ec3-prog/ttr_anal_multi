
undefined4 FUN_0045dea0(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x41] + 0x28) >> 7 & 1) != 0) {
      FUN_0045d1a0();
    }
    return 1;
  }
  if ((param_1 != 0xe) && (param_1 != 0x2af9)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

