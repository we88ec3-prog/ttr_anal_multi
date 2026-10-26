
undefined4 FUN_005e9e90(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  switch(in_EAX) {
  case 1:
    return *(undefined4 *)(in_ECX + 0x48);
  case 2:
    return *(undefined4 *)(in_ECX + 0x4c);
  case 3:
  case 4:
  case 0x1b:
    return *(undefined4 *)(in_ECX + 0x50);
  default:
    return 0;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x20:
  case 0x24:
  case 0x25:
    return *(undefined4 *)(in_ECX + 0x54);
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    return *(undefined4 *)(in_ECX + 0x58);
  }
}

