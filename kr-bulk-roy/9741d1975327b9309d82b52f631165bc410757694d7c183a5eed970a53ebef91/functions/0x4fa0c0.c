
void FUN_004fa0c0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (DAT_00fe1a94 - DAT_00fe1a90) / 0x14;
  if (0xccccccb < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((DAT_00fe1a98 - DAT_00fe1a90) / 0x14) < uVar1 + 1) {
    uVar2 = FUN_004fa230();
    FUN_004fa120(uVar2);
  }
  return;
}

