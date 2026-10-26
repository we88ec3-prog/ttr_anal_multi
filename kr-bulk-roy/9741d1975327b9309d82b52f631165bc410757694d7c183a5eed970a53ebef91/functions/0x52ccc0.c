
undefined4 FUN_0052ccc0(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  FUN_008195e0(&param_1);
  if (in_ECX != *(int *)(in_EAX + 0x34)) {
    FUN_0052d110(&param_1);
    if (param_1 != *(int *)(in_ECX + 0x14)) {
      return *(undefined4 *)(param_1 + 0x20);
    }
  }
  return 0;
}

