
void FUN_00756630(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  int in_ECX;
  
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  *(int *)(in_ECX + 0xd8) = param_5 - param_3;
  *(int *)(in_ECX + 0xe0) = param_5 - param_3;
  *(int *)(in_ECX + 0xdc) = param_6 - param_4;
  *(int *)(in_ECX + 0xe4) = param_6 - param_4;
  return;
}

