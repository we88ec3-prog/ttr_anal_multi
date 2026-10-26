
void FUN_0075d080(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x128))();
  if (param_1 == 0) {
    uVar1 = *(uint *)(in_ECX[0x93] + 0x28);
    if ((uVar1 & 0x100) != 0) {
      *(uint *)(in_ECX[0x93] + 0x28) = uVar1 ^ 0x100;
    }
  }
  else if ((param_1 == 1) || (param_1 == 2)) {
    *(uint *)(in_ECX[0x93] + 0x28) = *(uint *)(in_ECX[0x93] + 0x28) | 0x100;
    return;
  }
  return;
}

