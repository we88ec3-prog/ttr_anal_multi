
uint FUN_008c8370(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    return param_1 + 0xa0;
  case 1:
    return param_1 + 0x104;
  case 2:
    return (uint)(param_1 + 0x16c) & (*(short *)(param_1 + 0x16c) == -1) - 1;
  case 3:
    return param_1 + 0xd8;
  case 4:
    if (*(char *)(param_1 + 0x124) != '\0') {
      return param_1 + 0x128;
    }
    break;
  case 5:
    return param_1 + 0x1d4;
  case 6:
    return -(uint)(*(int *)(param_1 + 0x224) != 0) & param_1 + 0x224U;
  }
  return 0;
}

