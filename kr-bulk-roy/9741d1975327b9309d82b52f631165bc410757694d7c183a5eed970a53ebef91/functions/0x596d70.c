
void FUN_00596d70(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6,undefined4 param_7)

{
  int in_EAX;
  undefined4 uVar1;
  
  FUN_00848020(&param_2);
  if (param_1 == *(int *)(param_1 + 0xc4 + in_EAX * 0x10)) {
    uVar1 = FUN_0054f7d0();
    FUN_00597db0((in_EAX + 0xc) * 0x10 + param_1,uVar1);
  }
  return;
}

