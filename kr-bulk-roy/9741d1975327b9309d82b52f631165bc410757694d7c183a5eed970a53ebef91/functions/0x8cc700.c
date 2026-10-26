
void FUN_008cc700(int param_1,int param_2,undefined4 *param_3)

{
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  if (*(int *)(param_2 + 0x48) == *(int *)(param_1 + 0x10)) {
    FUN_008b9440(param_2 + 0x6c,param_3);
  }
  return;
}

