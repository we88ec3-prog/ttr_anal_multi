
undefined4 FUN_00520e10(void)

{
  int in_EAX;
  
  switch(*(undefined4 *)(in_EAX + 8)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x1b:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    return 1;
  default:
    return 0;
  }
}

