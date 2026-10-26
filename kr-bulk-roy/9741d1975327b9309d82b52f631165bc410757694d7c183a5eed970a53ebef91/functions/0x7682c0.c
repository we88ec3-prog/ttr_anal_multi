
void FUN_007682c0(int param_1)

{
  int *in_ECX;
  
  in_ECX[0x4d] = *(int *)(param_1 + 0xc4);
  (**(code **)(*in_ECX + 0x1b0))();
  return;
}

