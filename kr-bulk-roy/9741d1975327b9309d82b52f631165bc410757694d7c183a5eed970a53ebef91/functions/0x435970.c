
void FUN_00435970(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf42d4) {
    if (uVar1 == 0xf42d3) {
      FUN_00436390();
      return;
    }
    if (uVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
        FUN_004362d0(in_ECX);
        return;
      }
    }
    else if (uVar1 == 0x70a) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
        FUN_00435c40();
        return;
      }
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
        FUN_00435c80();
        return;
      }
    }
  }
  else if (uVar1 == 0xf443b) {
    FUN_00435f10(in_ECX);
  }
  return;
}

