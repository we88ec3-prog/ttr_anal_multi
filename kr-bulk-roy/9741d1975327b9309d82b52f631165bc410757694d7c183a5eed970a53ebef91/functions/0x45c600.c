
undefined4 FUN_0045c600(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x3f] + 0x28) >> 7 & 1) != 0) {
      FUN_0045c240();
    }
    return 1;
  }
  if (param_1 == 0x2af9) {
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  return 0;
}

