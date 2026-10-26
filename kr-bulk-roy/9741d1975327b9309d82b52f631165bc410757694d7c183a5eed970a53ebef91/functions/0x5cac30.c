
undefined4 FUN_005cac30(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  
  FUN_0082ef00(&param_2);
  if ((in_EAX != 0) && (param_1 == *(int *)(param_1 + 0x4c))) {
    *(int *)(in_EAX + 4) = param_1;
    uVar1 = FUN_0057ef20();
    FUN_0082f200(param_1 + 0x48,uVar1);
    return 1;
  }
  return 0;
}

