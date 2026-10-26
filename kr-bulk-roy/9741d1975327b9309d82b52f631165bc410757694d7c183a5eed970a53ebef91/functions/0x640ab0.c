
uint FUN_00640ab0(void)

{
  uint in_EAX;
  undefined4 in_ECX;
  
  switch(in_ECX) {
  case 0:
    return *(uint *)(*(int *)(in_EAX + 0xa8) + 0x28) >> 9 & 1;
  case 1:
    return *(uint *)(*(int *)(in_EAX + 0xac) + 0x28) >> 9 & 1;
  case 2:
    return *(uint *)(*(int *)(in_EAX + 0xb0) + 0x28) >> 9 & 1;
  case 3:
    return *(uint *)(*(int *)(in_EAX + 0xb4) + 0x28) >> 9 & 1;
  case 4:
    return *(uint *)(*(int *)(in_EAX + 0xb8) + 0x28) >> 9 & 1;
  case 5:
    return *(uint *)(*(int *)(in_EAX + 0xbc) + 0x28) >> 9 & 1;
  default:
    return in_EAX & 0xffffff00;
  }
}

