
undefined1 FUN_008d81c0(void)

{
  undefined1 uVar1;
  int *in_ECX;
  
  uVar1 = 1;
  if ((((*in_ECX != 0x50465230) || (4 < (uint)in_ECX[1])) || ((uint)in_ECX[3] < 0x3a)) ||
     (in_ECX[2] != 0xd0a)) {
    uVar1 = 0;
  }
  return uVar1;
}

