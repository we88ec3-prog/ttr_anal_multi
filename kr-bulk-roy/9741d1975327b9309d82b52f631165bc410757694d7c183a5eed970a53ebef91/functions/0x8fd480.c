
void FUN_008fd480(int param_1)

{
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  *(undefined4 *)(param_1 + 0x18) = in_ECX;
  *(undefined4 *)(param_1 + 0x1c) = in_EDX;
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00571e00(in_EDX);
  }
  return;
}

