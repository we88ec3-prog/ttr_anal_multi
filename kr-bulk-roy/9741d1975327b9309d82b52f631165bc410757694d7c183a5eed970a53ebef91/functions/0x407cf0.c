
void FUN_00407cf0(void)

{
  int *in_EAX;
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar1 = in_EAX[1] - *in_EAX;
  if (-in_ECX - 1U < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = uVar1 + in_ECX;
  uVar2 = in_EAX[2] - *in_EAX;
  if (uVar2 < uVar1) {
    if (-(uVar2 >> 1) - 1 < uVar2) {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = uVar1;
      }
      FUN_00407d50(uVar2);
      return;
    }
    uVar2 = uVar2 + (uVar2 >> 1);
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
    FUN_00407d50(uVar2);
  }
  return;
}

