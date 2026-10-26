
undefined4 FUN_00520e70(void)

{
  int in_EAX;
  
  switch(*(undefined4 *)(in_EAX + 8)) {
  case 1:
    return 3;
  case 2:
    return 2;
  default:
    return 0;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    return 1;
  }
}

