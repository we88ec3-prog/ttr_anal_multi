
undefined4 FUN_006ec980(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x46:
  case 0x50:
    return 0x10;
  case 0x47:
  case 0x52:
    return 0x20;
  default:
    return 0;
  case 0x49:
    return 0xf;
  case 0x4b:
  case 0x4d:
  case 0x4f:
  case 0x53:
    return 0x18;
  }
}

