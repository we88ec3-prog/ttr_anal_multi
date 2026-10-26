
void FUN_00757000(void)

{
  int in_ECX;
  
  FUN_00745930();
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) {
      return;
    }
    in_ECX = FUN_00745c20();
  }
  if (((in_ECX != 0) && ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) &&
     (*(int *)(in_ECX + 0x60) != 0)) {
    FUN_00749f40(in_ECX);
  }
  return;
}

