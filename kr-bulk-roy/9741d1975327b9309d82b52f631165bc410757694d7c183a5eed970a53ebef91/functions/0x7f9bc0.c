
void FUN_007f9bc0(void)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = in_ECX[0x33];
  if (uVar1 < (uint)in_ECX[0x34]) {
    in_ECX[0x33] = uVar1 + 1;
    (**(code **)(*in_ECX + 0x28))(uVar1 * 0x5c + in_ECX[0x32]);
  }
  return;
}

