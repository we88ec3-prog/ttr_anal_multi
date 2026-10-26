
void FUN_00850dc0(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == param_4) {
    *param_2 = param_3;
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = param_3;
  for (; param_4 != iVar1; param_4 = param_4 + 0x14) {
    FUN_006dd790(param_4);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_4 + 0x10);
    iVar2 = iVar2 + 0x14;
  }
  FUN_008508b0(*(undefined4 *)(param_1 + 4));
  *(int *)(param_1 + 4) = iVar2;
  *param_2 = param_3;
  return;
}

