
int FUN_00685cc0(int param_1)

{
  int in_EAX;
  
  FUN_00405370();
  *(undefined1 *)(param_1 + 0x158) = *(undefined1 *)(in_EAX + 0x158);
  FUN_00405420(in_EAX + 0x15c);
  FUN_004026e0(in_EAX + 0x248,0,0xffffffff);
  return param_1;
}

