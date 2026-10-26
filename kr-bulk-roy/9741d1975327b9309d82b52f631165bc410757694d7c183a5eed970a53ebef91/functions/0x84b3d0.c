
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0084b3d0(void)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = _DAT_00fba93c + *(float *)(in_ECX + 0xa0);
  *(float *)(in_ECX + 0xa0) = fVar1;
  if (*(float *)(in_ECX + 0x9c) < fVar1) {
    if (*(int *)(in_ECX + 0xa4) != 0) {
      *(undefined4 *)(in_ECX + 0xa0) = 0;
      return;
    }
    *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(in_ECX + 0x9c);
  }
  return;
}

