
bool FUN_0054adc0(int param_1)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 1000);
  }
  return iVar1 == *(int *)(in_ECX + 4);
}

