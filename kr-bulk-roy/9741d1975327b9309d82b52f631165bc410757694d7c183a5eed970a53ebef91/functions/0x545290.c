
undefined4 FUN_00545290(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 3) {
    return *(undefined4 *)(in_ECX + (param_1 * 3 + 3) * 4);
  }
  return 0;
}

