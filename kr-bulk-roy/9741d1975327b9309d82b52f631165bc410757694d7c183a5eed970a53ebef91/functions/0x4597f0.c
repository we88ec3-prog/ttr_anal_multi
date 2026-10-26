
void FUN_004597f0(int param_1)

{
  int *in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(in_ECX[0x3d] + 0x20) == *(int *)(param_1 + 8))) {
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}

