
undefined4 FUN_008cdec0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if ((param_2 != *(int *)(param_1 + 200)) || (param_4 != *(int *)(param_1 + 0xcc))) {
    *(int *)(param_1 + 200) = param_2;
    *(int *)(param_1 + 0xcc) = param_4;
    FUN_008cd620();
  }
  if ((param_3 != *(int *)(param_1 + 0x194)) || (param_5 != *(int *)(param_1 + 0x198))) {
    *(int *)(param_1 + 0x194) = param_3;
    *(int *)(param_1 + 0x198) = param_5;
    FUN_008cd620();
    FUN_008cd950(param_1 + 0x19c,param_3);
  }
  return 0;
}

