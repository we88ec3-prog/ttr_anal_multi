
undefined4 FUN_0073ff40(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int local_8;
  
  FUN_0082ef00(&param_1);
  if (local_8 == *(int *)(in_EAX + 0x20)) {
    uVar1 = FUN_0057ef20();
    FUN_0082f200(in_EAX + 0x1c,uVar1);
    return 1;
  }
  return 0;
}

