
void FUN_005b2f20(void)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  
  FUN_005b87b0();
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
  }
  if ((*(int *)(in_ECX + 0x2fc) != 0) &&
     ((*(uint *)(*(int *)(in_ECX + 0x2fc) + 0x28) >> 8 & 1) != 0)) {
    FUN_0064d1a0();
  }
  iVar1 = *(int *)(in_ECX + 0x300);
  if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
    fVar2 = *(float *)(iVar1 + 0x10c) + 0.033333335;
    *(float *)(iVar1 + 0x10c) = fVar2;
    if (5.0 < fVar2) {
      FUN_00671bd0();
      *(undefined4 *)(iVar1 + 0x10c) = 0;
    }
  }
  if ((*(int *)(in_ECX + 0x308) != 0) &&
     ((*(uint *)(*(int *)(in_ECX + 0x308) + 0x28) >> 8 & 1) != 0)) {
    FUN_0069d480();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x308) + 0x28) >> 8 & 1) != 0) {
    FUN_0069d6a0();
  }
  return;
}

