
void FUN_008d67c0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_008ba070(*(int *)(*param_1 + 500) + 0x6c,param_1[0xb]);
  if (iVar1 != 0) {
    FUN_008ba690(param_1[0xb]);
    param_1[0xb] = 0;
  }
  return;
}

