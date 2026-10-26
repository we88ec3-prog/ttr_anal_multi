
void FUN_0069c490(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x140) + 0x20)) {
      uVar2 = *(int *)(in_ECX + 0x144) + 1;
      if (uVar2 < *(uint *)(in_ECX + 0x148)) {
        *(uint *)(in_ECX + 0x144) = uVar2;
        FUN_0069c130(in_ECX);
        return;
      }
    }
    else if ((*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x13c) + 0x20)) &&
            (*(int *)(in_ECX + 0x144) != 0)) {
      *(int *)(in_ECX + 0x144) = *(int *)(in_ECX + 0x144) + -1;
      FUN_0069c130(in_ECX);
      return;
    }
  }
  else {
    if (iVar1 == 0x70b) {
      FUN_0069ca20();
      return;
    }
    if (iVar1 == 0x70a) {
      FUN_0069c550();
      return;
    }
    if (iVar1 == 0xf429f) {
      FUN_0069c130(in_ECX);
    }
  }
  return;
}

