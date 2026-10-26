
void FUN_00749890(int param_1)

{
  int in_ECX;
  
  if (param_1 != 0) {
    if ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0) {
      FUN_007486f0(*(undefined4 *)(in_ECX + 0x24));
      if ((*(byte *)(in_ECX + 0x2a) & 1) != 0) {
        FUN_00746bd0();
      }
      if ((*(uint *)(in_ECX + 0x28) >> 0xf & 1) != 0) {
        FUN_00746b30();
      }
    }
    *(int *)(param_1 + 0x60) = in_ECX;
  }
  *(int *)(in_ECX + 0x3c) = param_1;
  return;
}

