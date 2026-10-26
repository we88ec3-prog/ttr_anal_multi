
undefined4 FUN_008726e0(uint param_1)

{
  int in_ECX;
  
  if (param_1 < (uint)(*(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2)) {
    return *(undefined4 *)(*(int *)(in_ECX + 0x184) + param_1 * 4);
  }
  return 0;
}

