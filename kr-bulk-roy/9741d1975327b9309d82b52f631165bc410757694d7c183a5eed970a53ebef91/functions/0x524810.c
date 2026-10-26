
undefined4 FUN_00524810(void)

{
  int in_ECX;
  
  FUN_005276f0(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
  *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  FUN_00527e70(in_ECX + 4);
  return 1;
}

