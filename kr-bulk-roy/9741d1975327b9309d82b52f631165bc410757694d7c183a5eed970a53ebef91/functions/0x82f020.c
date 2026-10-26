
void FUN_0082f020(void)

{
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  
  uVar2 = (in_ECX[1] - *in_ECX) / 0x38;
  if (0x4924923 < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = (in_ECX[2] - *in_ECX) / 0x38;
  uVar2 = uVar2 + 1;
  if (uVar1 < uVar2) {
    if (0x4924924 - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 + (uVar1 >> 1);
    }
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_0082f0a0(uVar1);
  }
  return;
}

