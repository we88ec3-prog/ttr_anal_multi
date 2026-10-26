
undefined4 FUN_008ebe70(undefined4 param_1)

{
  int in_EAX;
  int in_ECX;
  
  *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x1b4 + in_ECX * 8);
  *(undefined4 *)(in_EAX + 0x16c) = *(undefined4 *)(in_EAX + 0x1b8 + in_ECX * 8);
  *(undefined4 *)(in_EAX + 0x168) = param_1;
  *(int *)(in_EAX + 0x160) = in_ECX;
  return 0;
}

