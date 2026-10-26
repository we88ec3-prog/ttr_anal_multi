
undefined4 FUN_00520ee0(void)

{
  int in_EAX;
  
  switch(*(undefined4 *)(in_EAX + 8)) {
  case 1:
  case 2:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x2a:
  case 0x2b:
    return 1;
  default:
    return 0;
  }
}

