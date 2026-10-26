
void FUN_00746350(byte param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = in_ECX[10];
  if (((byte)(uVar1 >> 10) & 1) != param_1) {
    if (param_1 != 0) {
      in_ECX[10] = uVar1 | 0x400;
      (**(code **)(*in_ECX + 0xcc))();
      return;
    }
    if ((uVar1 & 0x400) != 0) {
      in_ECX[10] = uVar1 ^ 0x400;
    }
    (**(code **)(*in_ECX + 0xcc))();
  }
  return;
}

