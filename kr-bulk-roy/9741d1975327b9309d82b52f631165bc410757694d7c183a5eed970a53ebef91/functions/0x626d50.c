
void FUN_00626d50(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf43ca) {
    if (uVar1 == 0xf43c9) {
      *(undefined4 *)(in_ECX + 0x11c) = 1;
      return;
    }
    if (uVar1 == 0x578) {
      FUN_00626f30(in_ECX);
      return;
    }
    if (uVar1 == 0x76c) {
      FUN_00626ed0();
      return;
    }
  }
  else if (uVar1 == 0xf43ca) {
    *(undefined4 *)(in_ECX + 0x11c) = 0;
  }
  else {
    if (uVar1 == 0xf43cc) {
      FUN_00627240(in_ECX);
      return;
    }
    if (uVar1 == 0xf43cd) {
      FUN_006273a0(in_ECX);
      return;
    }
  }
  return;
}

