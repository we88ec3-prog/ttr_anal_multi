
void FUN_0049f590(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_00fb72f0 - DAT_00fb72ec >> 6;
  if (0x3fffffe < uVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = DAT_00fb72f4 - DAT_00fb72ec >> 6;
  if (uVar1 < uVar2 + 1) {
    if (0x3ffffff - (uVar1 >> 1) < uVar1) {
      FUN_0049f5f0();
      return;
    }
    FUN_0049f5f0();
    return;
  }
  return;
}

