
void FUN_00650660(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf440a) {
    if (uVar1 == 0xf4409) {
      FUN_00650d50();
      return;
    }
    if (uVar1 == 0x578) {
      FUN_00650820();
      return;
    }
    if (uVar1 == 0xf43d2) {
      FUN_00650ca0();
      return;
    }
  }
  else if (uVar1 == 0xf440a) {
    FUN_00650d00();
  }
  return;
}

