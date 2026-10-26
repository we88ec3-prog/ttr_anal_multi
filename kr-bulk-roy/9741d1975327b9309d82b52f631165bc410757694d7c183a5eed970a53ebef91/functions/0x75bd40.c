
void FUN_0075bd40(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x128);
  in_ECX[0x34] = param_1;
  (*pcVar1)();
  return;
}

