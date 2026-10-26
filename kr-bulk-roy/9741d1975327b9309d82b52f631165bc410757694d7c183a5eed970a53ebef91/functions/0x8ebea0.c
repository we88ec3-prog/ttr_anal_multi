
undefined4 FUN_008ebea0(undefined4 param_1)

{
  int in_EAX;
  int in_ECX;
  undefined4 in_EDX;
  
  *(undefined4 *)(in_ECX + 0x1b4 + in_EAX * 8) = in_EDX;
  *(undefined4 *)(in_ECX + 0x1b8 + in_EAX * 8) = param_1;
  return 0;
}

