
void FUN_006f9810(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  if (*(undefined **)(in_EAX + 0x10) == &DAT_00c0bfa8) {
    FUN_006f9630(param_1,param_2,0);
    return;
  }
  FUN_006f9630(param_1,param_2,1 << (*(byte *)(in_EAX + 7) & 0x1f));
  return;
}

