
void FUN_007b5010(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_00fbab58 - DAT_00fbab54 >> 2;
  if (0x3ffffffe < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar2 = uVar2 + 1;
  uVar1 = DAT_00fbab5c - DAT_00fbab54 >> 2;
  if (uVar1 < uVar2) {
    if (0x3fffffff - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 + (uVar1 >> 1);
    }
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
    FUN_007b5070(uVar1);
  }
  return;
}

