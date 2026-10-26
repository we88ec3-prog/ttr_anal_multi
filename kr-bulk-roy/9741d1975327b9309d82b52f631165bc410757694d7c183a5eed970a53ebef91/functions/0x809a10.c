
void FUN_00809a10(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *in_ECX;
  
  uVar2 = *in_ECX;
  if (((uVar2 & 0x1f8) == 0) && ((param_1 & 0x3f) == 0)) {
    uVar1 = uVar2 + param_1 * 8;
    if (uVar1 < uVar2) {
      in_ECX[1] = in_ECX[1] + 1;
    }
    in_ECX[1] = in_ECX[1] + (param_1 >> 0x1d);
    *in_ECX = uVar1;
    if (param_1 != 0) {
      do {
        FUN_00809ba0(in_ECX + 2);
        param_1 = param_1 - 0x40;
      } while (param_1 != 0);
      return;
    }
  }
  else {
    FUN_008098e0();
  }
  return;
}

