
undefined4 FUN_008069a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_008438c0(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (*(int *)(in_ECX + 0x10) != 0)) {
    if (param_3 == 0) {
      return 1;
    }
    uVar1 = FUN_008060d0(param_2,param_3);
    return uVar1;
  }
  return 0;
}

