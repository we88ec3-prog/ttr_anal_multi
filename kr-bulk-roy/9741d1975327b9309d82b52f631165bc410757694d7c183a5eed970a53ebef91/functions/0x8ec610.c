
void FUN_008ec610(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x180) + param_2 * 4);
  *piVar1 = *piVar1 + param_3;
  return;
}

