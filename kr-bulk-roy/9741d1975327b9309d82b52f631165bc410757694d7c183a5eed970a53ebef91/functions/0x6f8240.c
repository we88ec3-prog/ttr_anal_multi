
bool FUN_006f8240(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX & 0x3f;
  if ((0x1b < uVar1) && ((uVar1 < 0x1f || (uVar1 == 0x22)))) {
    return (in_EAX & 0xff800000) == 0;
  }
  return false;
}

