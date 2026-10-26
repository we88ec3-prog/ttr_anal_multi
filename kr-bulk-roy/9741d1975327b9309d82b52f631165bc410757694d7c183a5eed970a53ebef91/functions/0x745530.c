
void FUN_00745530(void)

{
  int *in_ECX;
  
  FUN_00746780(in_ECX);
  (**(code **)(*in_ECX + 0x6c))();
  if ((int *)in_ECX[7] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[7] + 0x1c))(1);
    in_ECX[7] = 0;
  }
  if ((in_ECX[0xf] != 0) && ((in_ECX[10] & 0x40000U) == 0)) {
    FUN_00746c10();
    FUN_00746b80();
    if ((int *)in_ECX[0xf] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[0xf] + 0x1c))(1);
    }
    in_ECX[0xf] = 0;
  }
  return;
}

