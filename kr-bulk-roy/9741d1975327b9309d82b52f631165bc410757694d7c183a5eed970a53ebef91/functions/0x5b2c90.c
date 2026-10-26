
void FUN_005b2c90(int param_1)

{
  int *in_ECX;
  
  FUN_005b7be0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf434d) {
    (**(code **)(*in_ECX + 0x1a0))(0);
  }
  return;
}

