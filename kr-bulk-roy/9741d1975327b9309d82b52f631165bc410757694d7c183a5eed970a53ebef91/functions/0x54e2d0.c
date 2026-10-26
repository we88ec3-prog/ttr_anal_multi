
void FUN_0054e2d0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) & 0xfffffffcU) != 0) {
    *(int *)(in_ECX + 0x44) = param_1;
    iVar2 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2;
    uVar1 = *(uint *)(*(int *)(*(int *)(in_ECX + 8) + -4 + iVar2 * 4) + 0x24);
    if ((int)uVar1 <= param_1) {
      *(uint *)(in_ECX + 0x44) = -(uint)(iVar2 != 0) & uVar1;
    }
  }
  return;
}

