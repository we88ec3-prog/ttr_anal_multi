
int FUN_007779f0(void)

{
  undefined4 *in_EAX;
  uint in_ECX;
  
  if ((uint)in_EAX[4] <= in_ECX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  if (7 < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  return (int)in_EAX + in_ECX * 2;
}

