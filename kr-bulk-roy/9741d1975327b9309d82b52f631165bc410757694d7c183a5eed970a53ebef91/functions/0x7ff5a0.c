
void FUN_007ff5a0(float param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  FUN_007d89b0(*(int *)(in_ECX + 0x24),*(float *)(*(int *)(in_ECX + 0x24) + 0x74) * param_1);
  if (*(float *)(*(int *)(in_ECX + 0x24) + 0x70) < *(float *)(*(int *)(in_ECX + 0x24) + 0x6c)) {
    iVar1 = *(int *)(in_ECX + 0x24);
    uVar2 = 0;
    if (*(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x5c) >> 2 != 0) {
      do {
        *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x5c) + uVar2 * 4) + 0x7c) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)(*(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x5c) >> 2));
    }
    *(undefined4 *)(iVar1 + 0x6c) = 0;
  }
  return;
}

