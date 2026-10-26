
undefined4 FUN_006532f0(void)

{
  int in_EAX;
  undefined4 in_ECX;
  
  switch(in_ECX) {
  case 0:
  case 1:
    *(undefined4 *)(in_EAX + 0xdc) = 1;
    return 1;
  case 2:
  case 3:
    *(undefined4 *)(in_EAX + 0xdc) = 2;
    return 1;
  case 4:
    *(undefined4 *)(in_EAX + 0xdc) = 4;
    return 1;
  case 5:
    *(undefined4 *)(in_EAX + 0xdc) = 6;
    return 1;
  case 6:
  case 7:
    *(undefined4 *)(in_EAX + 0xdc) = 8;
    return 1;
  case 8:
  case 9:
    *(undefined4 *)(in_EAX + 0xdc) = 10;
    return 1;
  case 10:
  case 0xb:
    *(undefined4 *)(in_EAX + 0xdc) = 0xc;
    return 1;
  case 0xc:
  case 0xd:
    *(undefined4 *)(in_EAX + 0xdc) = 0xe;
    return 1;
  case 0xe:
  case 0xf:
    *(undefined4 *)(in_EAX + 0xdc) = 0x10;
    return 1;
  default:
    return 0;
  }
}

