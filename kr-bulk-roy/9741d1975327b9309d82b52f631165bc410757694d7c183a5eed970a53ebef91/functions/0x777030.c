
void FUN_00777030(void)

{
  ushort uVar1;
  uint in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  if (in_EAX != 0) {
LAB_00777040:
    do {
      in_EAX = in_EAX - 1;
      if ((int)in_EAX < 1) {
        return;
      }
      if ((uint)unaff_ESI[4] <= in_EAX) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid string position");
      }
      puVar2 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        puVar2 = (undefined4 *)*unaff_ESI;
      }
      uVar1 = *(ushort *)((int)puVar2 + in_EAX * 2);
      if (0x5a < (ushort)(uVar1 - 0xe01)) {
        return;
      }
      if (uVar1 < 0xe2f) {
        return;
      }
      if ((ushort)(uVar1 - 0xe40) < 5) {
        return;
      }
      if ((((((uVar1 == 0xe3a) || ((ushort)(uVar1 - 0xe4d) < 3)) || (0xe59 < uVar1)) ||
           ((uVar1 == 0xe2f || (uVar1 == 0xe3f)))) ||
          (((ushort)(uVar1 - 0xe48) < 4 || ((ushort)(uVar1 - 0xe50) < 10)))) &&
         (3 < (ushort)(uVar1 - 0xe48))) {
        if (uVar1 == 0xe3a) goto LAB_00777040;
        if ((2 < (ushort)(uVar1 - 0xe4d)) && (uVar1 < 0xe5a)) {
          return;
        }
      }
    } while (uVar1 != 0xe32);
  }
  return;
}

