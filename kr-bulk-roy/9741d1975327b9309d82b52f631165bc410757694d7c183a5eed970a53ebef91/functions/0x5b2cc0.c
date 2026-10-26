
void FUN_005b2cc0(int param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  FUN_005b7c50(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4249:
    if ((*(uint *)(*(int *)(in_ECX + 0x304) + 0x28) >> 8 & 1) != 0) {
      FUN_0066f750(*(int *)(in_ECX + 0x304));
      return;
    }
    break;
  case 0xf424a:
    if ((*(uint *)(*(int *)(in_ECX + 0x300) + 0x28) >> 8 & 1) != 0) {
      iVar2 = FUN_00404ba0();
      if (*(int *)(iVar2 + 0x5f4c) == 7) {
        FUN_00670670();
        return;
      }
      iVar2 = FUN_00404ba0();
      if ((*(int *)(iVar2 + 0x5f4c) == 0x17) ||
         (iVar2 = FUN_00404ba0(), *(int *)(iVar2 + 0x5f4c) == 0x18)) {
        FUN_006714b0();
        return;
      }
    }
    break;
  case 0xf4256:
    FUN_006a8850();
    return;
  case 0xf4284:
    if ((*(uint *)(*(int *)(in_ECX + 0x308) + 0x28) >> 8 & 1) != 0) {
      FUN_006a0b60();
      FUN_0069d480();
      return;
    }
    break;
  case 0xf4285:
    if ((*(uint *)(*(int *)(in_ECX + 0x308) + 0x28) >> 8 & 1) != 0) {
      FUN_0069e760(*(undefined4 *)(*(int *)(in_ECX + 0x308) + 0x100));
      FUN_0069d480();
      return;
    }
    break;
  case 0xf42b0:
    iVar2 = FUN_005a3810();
    cVar1 = *(char *)(iVar2 + 0x14);
    iVar2 = *(int *)(in_ECX + 0x308);
    (**(code **)(**(int **)(iVar2 + 0x108) + 0x90))(cVar1);
    *(bool *)(iVar2 + 0x114) = cVar1 != '\x01';
    return;
  case 0xf42d5:
    if ((*(uint *)(*(int *)(in_ECX + 0x30c) + 0x28) >> 8 & 1) != 0) {
      FUN_006a2340();
    }
  }
  return;
}

