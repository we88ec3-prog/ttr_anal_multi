
void FUN_005b1c30(void)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  
  FUN_005c2c60();
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
  return;
}

