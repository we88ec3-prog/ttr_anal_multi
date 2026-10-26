
void FUN_00535a40(void)

{
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  
  uVar2 = (in_ECX[1] - *in_ECX) / 0x1f;
  if (0x8421083 < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = (in_ECX[2] - *in_ECX) / 0x1f;
  uVar2 = uVar2 + 1;
  if (uVar1 < uVar2) {
    if (0x8421084 - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
      if (uVar2 != 0) {
        uVar1 = uVar2;
      }
      FUN_00535b60(uVar1);
      return;
    }
    uVar1 = uVar1 + (uVar1 >> 1);
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_00535b60(uVar1);
  }
  return;
}

