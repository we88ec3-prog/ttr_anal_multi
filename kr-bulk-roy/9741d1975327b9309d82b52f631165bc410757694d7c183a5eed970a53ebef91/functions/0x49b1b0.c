
uint FUN_0049b1b0(void)

{
  int in_EAX;
  uint uVar1;
  int in_ECX;
  
  if (in_EAX - 0x30U < 10) {
    uVar1 = in_EAX - 0x30;
  }
  else if (in_EAX - 0x61U < 6) {
    uVar1 = in_EAX - 0x57;
  }
  else if (in_EAX - 0x41U < 6) {
    uVar1 = in_EAX - 0x37;
  }
  else {
    uVar1 = 0;
  }
  if (in_ECX - 0x30U < 10) {
    return (uVar1 & 0xf) << 4 | in_ECX - 0x30U & 0xf;
  }
  if (in_ECX - 0x61U < 6) {
    return (uVar1 & 0xf) << 4 | in_ECX - 0x57U & 0xf;
  }
  if (in_ECX - 0x41U < 6) {
    return (uVar1 & 0xf) << 4 | in_ECX - 0x37U & 0xf;
  }
  return (uVar1 & 0xf) << 4;
}

