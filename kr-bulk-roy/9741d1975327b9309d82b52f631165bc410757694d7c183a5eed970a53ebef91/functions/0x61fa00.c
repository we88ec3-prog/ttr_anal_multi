
void FUN_0061fa00(int param_1)

{
  uint uVar1;
  undefined4 in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf43c8) {
    if (uVar1 == 0xf43c7) {
      FUN_00621cd0(in_ECX);
      FUN_006241f0();
      return;
    }
    if (uVar1 == 0x578) {
      FUN_00621830();
      FUN_006241f0();
      return;
    }
    if (uVar1 == 0x5e6) {
      FUN_006220d0();
      FUN_006241f0();
      return;
    }
    if (uVar1 == 0x641) {
      FUN_00622190();
      FUN_006241f0();
      return;
    }
  }
  else if (uVar1 == 0xf43c8) {
    FUN_006200d0(in_ECX);
    FUN_006241f0();
  }
  else if (uVar1 == 0xf43d0) {
    FUN_00621ac0();
    FUN_006241f0();
    return;
  }
  return;
}

