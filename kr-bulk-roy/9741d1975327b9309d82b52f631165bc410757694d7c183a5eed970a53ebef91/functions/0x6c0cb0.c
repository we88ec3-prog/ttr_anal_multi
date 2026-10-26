
void FUN_006c0cb0(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    FUN_00413960();
    FUN_006c0e60();
    return;
  }
  return;
}

