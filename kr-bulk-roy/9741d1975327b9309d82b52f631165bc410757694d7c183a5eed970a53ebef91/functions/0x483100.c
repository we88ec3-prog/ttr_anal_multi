
void FUN_00483100(void)

{
  int in_ECX;
  
  FUN_007459c0();
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0048313b;
    in_ECX = FUN_00745c20();
  }
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x60) != 0)) &&
     ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) {
    FUN_0074a010(in_ECX);
  }
LAB_0048313b:
  FUN_00483730();
  return;
}

