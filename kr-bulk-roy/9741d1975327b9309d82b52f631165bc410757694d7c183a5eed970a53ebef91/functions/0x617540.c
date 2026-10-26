
void FUN_00617540(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (0x58c < uVar1) {
    if ((uVar1 != 0x70a) && (uVar1 != 0x70c)) {
      return;
    }
    FUN_00617610();
    return;
  }
  if (uVar1 != 0x58c) {
    if (uVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
        FUN_005de120();
        FUN_00617a80(0);
        return;
      }
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
        return;
      }
      FUN_0041bb70();
      FUN_005de120();
      FUN_00617a80(1);
      return;
    }
    if (uVar1 != 0x57a) {
      return;
    }
  }
  if ((*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) &&
     (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xf0) + 0x20))) {
    return;
  }
  FUN_00617760(param_1);
  return;
}

