
undefined4 FUN_006ae420(int param_1)

{
  int *in_ECX;
  
  if ((param_1 == 0xd) && ((*(uint *)(in_ECX[0x3f] + 0x28) >> 7 & 1) != 0)) {
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  return 0;
}

