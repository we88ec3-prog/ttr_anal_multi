
int FUN_00459bc0(int param_1)

{
  int in_EAX;
  
  FUN_00408e60(param_1);
  *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(in_EAX + 0x298);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(in_EAX + 0x2a0);
  *(undefined1 *)(param_1 + 0x2a4) = *(undefined1 *)(in_EAX + 0x2a4);
  *(undefined4 *)(param_1 + 0x2a8) = *(undefined4 *)(in_EAX + 0x2a8);
  FUN_0045d560();
  return param_1;
}

