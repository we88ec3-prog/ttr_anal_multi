
undefined4 FUN_00630660(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    FUN_0062ea30(in_ECX);
    return 1;
  }
  if ((param_1 != 0xe) && (param_1 != 0x2af9)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

