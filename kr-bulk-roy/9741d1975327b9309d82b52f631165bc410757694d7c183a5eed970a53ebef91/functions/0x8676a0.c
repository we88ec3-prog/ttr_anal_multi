
int FUN_008676a0(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  
  switch(*(undefined4 *)(in_ECX + 4)) {
  case 1:
    return 1;
  case 2:
  case 3:
  case 0xb:
  case 0xc:
  case 0xd:
    return 4;
  case 4:
    pcVar3 = *(char **)(in_ECX + 0xc);
    pcVar1 = pcVar3 + 1;
    break;
  case 5:
  case 10:
    return 8;
  case 6:
    return 0xc;
  case 7:
    return 0x10;
  case 8:
    return 0x30;
  case 9:
    return 0x40;
  default:
    return 0;
  }
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  return (int)pcVar3 - (int)pcVar1;
}

