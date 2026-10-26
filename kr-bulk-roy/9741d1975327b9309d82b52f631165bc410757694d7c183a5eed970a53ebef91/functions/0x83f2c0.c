
void FUN_0083f2c0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_00fbac90 - DAT_00fbac8c >> 3;
  if (0x1ffffffe < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar2 = uVar2 + 1;
  uVar1 = DAT_00fbac94 - DAT_00fbac8c >> 3;
  if (uVar1 < uVar2) {
    if (0x1fffffff - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 + (uVar1 >> 1);
    }
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_0083f6d0(uVar1);
  }
  return;
}

