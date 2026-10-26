
void FUN_00788400(void)

{
  int in_EAX;
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  
  uVar2 = (in_ECX[1] - *in_ECX) / 0x3c;
  if (0x4444444U - in_EAX < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar2 = uVar2 + in_EAX;
  uVar1 = (in_ECX[2] - *in_ECX) / 0x3c;
  if (uVar1 < uVar2) {
    if (0x4444444 - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 + (uVar1 >> 1);
    }
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_00788b10(uVar1);
  }
  return;
}

