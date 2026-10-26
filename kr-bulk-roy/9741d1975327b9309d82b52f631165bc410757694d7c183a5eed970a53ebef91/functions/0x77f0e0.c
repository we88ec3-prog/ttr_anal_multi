
undefined4 FUN_0077f0e0(uint param_1)

{
  int in_ECX;
  
  if ((uint)(*(int *)(in_ECX + 0xcc) - *(int *)(in_ECX + 200) >> 2) <= param_1) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 200) + param_1 * 4);
}

