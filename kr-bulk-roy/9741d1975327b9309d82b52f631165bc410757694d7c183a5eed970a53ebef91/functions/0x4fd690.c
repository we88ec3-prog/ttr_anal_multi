
void FUN_004fd690(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (DAT_00fe1ab0 - DAT_00fe1aac) / 0x58;
  if (0x2e8ba2d < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((DAT_00fe1ab4 - DAT_00fe1aac) / 0x58) < uVar1 + 1) {
    uVar2 = FUN_004fd820();
    FUN_004fd6f0(uVar2);
  }
  return;
}

