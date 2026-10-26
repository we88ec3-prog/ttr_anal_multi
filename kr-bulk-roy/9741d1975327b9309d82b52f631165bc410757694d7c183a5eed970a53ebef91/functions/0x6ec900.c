
undefined4 FUN_006ec900(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x20:
    return 8;
  case 0x17:
  case 0x18:
  case 0x19:
    return 5;
  case 0x1a:
  case 0x1e:
    return 4;
  case 0x1b:
  case 0x1d:
    return 2;
  default:
    return 0;
  case 0x1f:
  case 0x23:
    return 10;
  case 0x24:
    return 0x10;
  }
}

