
undefined1 FUN_006f1b90(byte param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x20) != 0) && (param_1 < 0x100)) {
    return *(undefined1 *)(param_1 + 0x160 + in_ECX);
  }
  return 0;
}

