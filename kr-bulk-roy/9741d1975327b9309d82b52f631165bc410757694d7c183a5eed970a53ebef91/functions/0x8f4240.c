
undefined4 FUN_008f4240(void)

{
  uint in_EAX;
  undefined4 uVar1;
  uint in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar2 = in_ECX;
  if ((int)in_EAX < (int)in_ECX) {
    if ((int)in_EAX < (int)-in_ECX) {
      uVar4 = 0xfffffffe;
    }
    else {
      uVar4 = 1;
      uVar2 = in_EAX;
      in_EAX = in_ECX;
    }
  }
  else if ((int)in_EAX < (int)-in_ECX) {
    uVar4 = 0xffffffff;
    uVar2 = in_EAX;
    in_EAX = -in_ECX;
  }
  else {
    uVar4 = 2;
  }
  uVar3 = (int)(uVar2 * 0xe) >> 0x1f;
  uVar1 = 4;
  if ((int)((uVar2 * 0xe ^ uVar3) - uVar3) <
      (int)((in_EAX ^ (int)in_EAX >> 0x1f) - ((int)in_EAX >> 0x1f))) {
    uVar1 = uVar4;
  }
  return uVar1;
}

