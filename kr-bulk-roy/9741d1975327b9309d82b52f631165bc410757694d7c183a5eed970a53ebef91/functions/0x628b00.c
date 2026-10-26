
int FUN_00628b00(int param_1)

{
  int in_EAX;
  
  FUN_00405370();
  *(undefined1 *)(param_1 + 0x158) = *(undefined1 *)(in_EAX + 0x158);
  FUN_00405420(in_EAX + 0x15c);
  *(undefined4 *)(param_1 + 0x248) = *(undefined4 *)(in_EAX + 0x248);
  *(undefined4 *)(param_1 + 0x24c) = *(undefined4 *)(in_EAX + 0x24c);
  *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(in_EAX + 0x250);
  *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(in_EAX + 0x254);
  *(undefined1 *)(param_1 + 600) = *(undefined1 *)(in_EAX + 600);
  return param_1;
}

