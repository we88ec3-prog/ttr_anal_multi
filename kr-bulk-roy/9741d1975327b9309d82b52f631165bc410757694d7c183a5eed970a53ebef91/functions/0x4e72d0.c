
void FUN_004e72d0(void)

{
  uint uVar1;
  int *in_ECX;
  int in_EDX;
  uint uVar2;
  
  uVar1 = in_ECX[1] - *in_ECX >> 3;
  if (0x1fffffffU - in_EDX < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = uVar1 + in_EDX;
  uVar2 = in_ECX[2] - *in_ECX >> 3;
  if (uVar2 < uVar1) {
    if (0x1fffffff - (uVar2 >> 1) < uVar2) {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = uVar1;
      }
      FUN_004e7330(uVar2);
      return;
    }
    uVar2 = uVar2 + (uVar2 >> 1);
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
    FUN_004e7330(uVar2);
  }
  return;
}

