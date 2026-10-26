
void FUN_00746280(byte param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = in_ECX[10];
  if (((byte)(uVar1 >> 9) & 1) != param_1) {
    if (param_1 != 0) {
      in_ECX[10] = uVar1 | 0x200;
      (**(code **)(*in_ECX + 0xcc))();
      return;
    }
    if ((uVar1 & 0x200) != 0) {
      in_ECX[10] = uVar1 ^ 0x200;
    }
    (**(code **)(*in_ECX + 0xcc))();
  }
  return;
}

