
void FUN_0061e470(int param_1)

{
  int *in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x4e] + 0x20))) {
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}

