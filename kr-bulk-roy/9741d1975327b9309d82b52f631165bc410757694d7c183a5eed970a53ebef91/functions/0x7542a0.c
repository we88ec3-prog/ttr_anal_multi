
void FUN_007542a0(int param_1)

{
  int *in_ECX;
  
  in_ECX[0x31] = param_1;
  (**(code **)(*in_ECX + 0x128))();
  return;
}

