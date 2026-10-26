
void FUN_00419600(void)

{
  int *in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = in_EAX[1] - *in_EAX >> 1;
  if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = uVar1 + 1;
  uVar2 = in_EAX[2] - *in_EAX >> 1;
  if (uVar2 < uVar1) {
    if (0x7fffffff - (uVar2 >> 1) < uVar2) {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = uVar1;
      }
      FUN_00419730(uVar2);
      return;
    }
    uVar2 = uVar2 + (uVar2 >> 1);
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
    FUN_00419730(uVar2);
  }
  return;
}

