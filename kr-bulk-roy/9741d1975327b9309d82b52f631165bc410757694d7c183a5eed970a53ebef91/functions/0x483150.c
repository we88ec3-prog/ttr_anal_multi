
undefined4 FUN_00483150(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x42] + 0x28) >> 7 & 1) != 0) {
      FUN_00483aa0();
      return 1;
    }
  }
  else if ((param_1 == 0xe) || (param_1 == 0x2af9)) {
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  return 0;
}

