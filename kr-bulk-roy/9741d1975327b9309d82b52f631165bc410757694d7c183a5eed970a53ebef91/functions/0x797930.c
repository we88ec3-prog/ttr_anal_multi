
void FUN_00797930(void)

{
  int *in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = in_EAX[1] - *in_EAX >> 2;
  if (0x3ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = uVar1 + 1;
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
    FUN_00797980(uVar2);
  }
  return;
}

