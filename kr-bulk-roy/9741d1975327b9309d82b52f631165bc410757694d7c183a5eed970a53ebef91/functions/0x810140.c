
undefined4 FUN_00810140(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  alSourceStop(*(int *)(in_ECX + 0x10));
  FUN_00810080();
  FUN_0080ffb0(in_ECX);
  return 1;
}

