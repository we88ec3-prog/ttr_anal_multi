
undefined4 FUN_0058c9a0(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    (**(code **)(*in_ECX + 0x198))();
    return 1;
  }
  if (param_1 == 0xe) {
    (**(code **)(*in_ECX + 0x19c))();
    return 1;
  }
  return 0;
}

