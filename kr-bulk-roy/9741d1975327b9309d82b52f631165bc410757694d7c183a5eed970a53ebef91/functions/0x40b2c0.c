
bool FUN_0040b2c0(void)

{
  undefined4 *in_EAX;
  uint unaff_ESI;
  
  if (unaff_ESI == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_EAX[5] < unaff_ESI) {
    FUN_0040b150();
    return unaff_ESI != 0;
  }
  if (unaff_ESI == 0) {
    in_EAX[4] = 0;
    if (0xf < (uint)in_EAX[5]) {
      in_EAX = (undefined4 *)*in_EAX;
    }
    *(undefined1 *)in_EAX = 0;
  }
  return unaff_ESI != 0;
}

