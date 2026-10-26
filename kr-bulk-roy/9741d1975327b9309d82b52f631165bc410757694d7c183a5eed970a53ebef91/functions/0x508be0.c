
int FUN_00508be0(void)

{
  int in_EAX;
  undefined4 in_ECX;
  
  switch(in_ECX) {
  case 1:
    return in_EAX + 0x10;
  case 2:
    return in_EAX + 0x20;
  case 3:
    return in_EAX + 0x30;
  case 4:
    return in_EAX + 0x50;
  default:
    return 0;
  case 0x11:
    return in_EAX + 0x60;
  case 0x12:
    return in_EAX + 0x70;
  case 0x13:
    return in_EAX + 0x80;
  case 0x1b:
    return in_EAX + 0x40;
  case 0x20:
    return in_EAX + 0x90;
  case 0x24:
    return in_EAX + 0xa0;
  case 0x25:
    return in_EAX + 0xb0;
  case 0x28:
    return in_EAX + 0xc0;
  case 0x29:
    return in_EAX + 0xd0;
  case 0x2a:
    return in_EAX + 0xe0;
  case 0x2b:
    return in_EAX + 0xf0;
  }
}

