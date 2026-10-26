
int FUN_0047adc0(int param_1)

{
  int in_EAX;
  
  FUN_00405370();
  *(undefined1 *)(param_1 + 0x158) = *(undefined1 *)(in_EAX + 0x158);
  FUN_00405420(in_EAX + 0x15c);
  *(undefined4 *)(param_1 + 0x248) = *(undefined4 *)(in_EAX + 0x248);
  *(undefined4 *)(param_1 + 0x24c) = *(undefined4 *)(in_EAX + 0x24c);
  FUN_004026e0(in_EAX + 0x250,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x26c) = *(undefined1 *)(in_EAX + 0x26c);
  *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(in_EAX + 0x270);
  return param_1;
}

