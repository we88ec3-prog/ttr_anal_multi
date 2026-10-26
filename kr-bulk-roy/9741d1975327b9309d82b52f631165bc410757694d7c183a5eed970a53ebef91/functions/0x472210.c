
void FUN_00472210(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x44) == 0) ||
      (iVar2 = *(int *)(*(int *)(in_ECX + 0x44) + 0xd8), iVar2 == 0)) || (iVar2 != 1)) {
    iVar2 = (*(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa8) >> 2) * *(int *)(in_ECX + 0xd4);
    param_1[2] = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa8) >> 2;
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    FUN_0043c810(fVar1 / (float)*(int *)(in_ECX + 0xd8));
    iVar2 = FUN_008fed10();
    param_1[2] = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
    iVar2 = *(int *)(in_ECX + 0xd4) * iVar2;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = iVar2;
  return;
}

