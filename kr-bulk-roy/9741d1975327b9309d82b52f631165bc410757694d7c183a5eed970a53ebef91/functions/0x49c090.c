
void FUN_0049c090(void)

{
  int in_EAX;
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  
  uVar2 = (in_ECX[1] - *in_ECX) / 0x1c;
  if (0x9249249U - in_EAX < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar2 = uVar2 + in_EAX;
  uVar1 = (in_ECX[2] - *in_ECX) / 0x1c;
  if (uVar1 < uVar2) {
    if (0x9249249 - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
      if (uVar2 != 0) {
        uVar1 = uVar2;
      }
      FUN_0049bf70(uVar1);
      return;
    }
    uVar1 = uVar1 + (uVar1 >> 1);
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_0049bf70(uVar1);
  }
  return;
}

