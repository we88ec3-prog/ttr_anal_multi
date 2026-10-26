
void FUN_007460e0(byte param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0x28);
  if (((byte)(uVar1 >> 8) & 1) != param_1) {
    if (param_1 != 0) {
      *(uint *)(in_ECX + 0x28) = uVar1 | 0x100;
      FUN_00745b80();
      return;
    }
    if ((uVar1 & 0x100) != 0) {
      *(uint *)(in_ECX + 0x28) = uVar1 ^ 0x100;
    }
    FUN_00745b80();
  }
  return;
}

