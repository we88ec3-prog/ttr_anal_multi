
bool FUN_00741a40(void)

{
  undefined4 *in_EAX;
  uint unaff_ESI;
  
  if (0x7ffffffe < unaff_ESI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_EAX[5] < unaff_ESI) {
    FUN_00741c60();
    return unaff_ESI != 0;
  }
  if (unaff_ESI == 0) {
    in_EAX[4] = 0;
    if (7 < (uint)in_EAX[5]) {
      in_EAX = (undefined4 *)*in_EAX;
    }
    *(undefined2 *)in_EAX = 0;
  }
  return unaff_ESI != 0;
}

