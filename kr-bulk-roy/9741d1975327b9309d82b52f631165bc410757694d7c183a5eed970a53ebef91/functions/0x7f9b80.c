
void FUN_007f9b80(void)

{
  int *in_ECX;
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (in_ECX[0x33] != 0) {
    iVar1 = 0;
    do {
      (**(code **)(*in_ECX + 0x28))(in_ECX[0x32] + iVar1);
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x5c;
    } while (uVar2 < (uint)in_ECX[0x33]);
  }
  return;
}

