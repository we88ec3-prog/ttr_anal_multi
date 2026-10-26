
undefined4 FUN_0081aea0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  uint in_ECX;
  
  if ((in_ECX < (uint)(*(int *)(in_EAX + 0x18) - *(int *)(in_EAX + 0x14) >> 2)) &&
     (puVar1 = *(undefined4 **)(*(int *)(in_EAX + 0x14) + in_ECX * 4), puVar1 != (undefined4 *)0x0))
  {
    return *puVar1;
  }
  return 0;
}

