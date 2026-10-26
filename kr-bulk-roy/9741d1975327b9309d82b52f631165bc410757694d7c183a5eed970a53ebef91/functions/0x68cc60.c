
undefined4 FUN_0068cc60(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    FUN_0068c790(in_ECX);
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  if ((param_1 != 0x2af9) && (param_1 != 0xe)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

