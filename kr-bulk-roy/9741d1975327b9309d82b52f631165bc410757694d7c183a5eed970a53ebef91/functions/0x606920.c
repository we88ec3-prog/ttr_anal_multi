
undefined4 FUN_00606920(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0xd) && (param_1 != 0x2af9)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

