
undefined4 FUN_00720100(void)

{
  char cVar1;
  undefined4 *in_EAX;
  
  switch(*(undefined1 *)*in_EAX) {
  case 99:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 3;
    }
    break;
  case 0x6e:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 2;
    }
    break;
  case 0x70:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 4;
    }
    break;
  case 0x74:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 5;
    }
  }
  return 0;
}

