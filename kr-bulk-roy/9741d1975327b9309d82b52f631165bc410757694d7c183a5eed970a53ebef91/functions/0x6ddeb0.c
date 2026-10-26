
void FUN_006ddeb0(void)

{
  int *in_EAX;
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar1 = in_EAX[1] - *in_EAX >> 2;
  if (0x3fffffffU - in_ECX < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = uVar1 + in_ECX;
  uVar2 = in_EAX[2] - *in_EAX >> 2;
  if (uVar2 < uVar1) {
    if (0x3fffffff - (uVar2 >> 1) < uVar2) {
      uVar2 = 0;
    }
    else {
      uVar2 = uVar2 + (uVar2 >> 1);
    }
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
    FUN_006ddf10(uVar2);
  }
  return;
}

