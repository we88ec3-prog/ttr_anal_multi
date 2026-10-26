
undefined4 FUN_00422a00(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x3e] + 0x28) >> 7 & 1) != 0) {
      FUN_00422be0(in_ECX);
    }
    return 1;
  }
  if (param_1 != 0xe) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

