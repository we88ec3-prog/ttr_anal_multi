
undefined4 FUN_0068d790(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    FUN_0068d4c0(in_ECX);
    (**(code **)(*in_ECX + 0xd4))();
  }
  else {
    if (param_1 == 0xe) {
      (**(code **)(*in_ECX + 0xd4))();
      return 0;
    }
    if (param_1 == 0x2af9) {
      (**(code **)(*in_ECX + 0xd4))();
      return 1;
    }
  }
  return 0;
}

