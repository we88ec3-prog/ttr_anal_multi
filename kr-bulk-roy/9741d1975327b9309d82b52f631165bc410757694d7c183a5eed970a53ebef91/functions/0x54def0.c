
void FUN_0054def0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00fba80c == 0) {
    iVar1 = FUN_00891268(0x57c);
    if (iVar1 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x17e) == '\0')) {
    if ((DAT_00fbab40 & 8) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 8;
    }
  }
  else if ((DAT_00fbab40 & 8) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 8;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x180) == '\0')) {
    if ((DAT_00fbab40 & 0x10) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 0x10;
    }
  }
  else if ((DAT_00fbab40 & 0x10) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 0x10;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x171) == '\0')) {
    if ((DAT_00fbab40 & 2) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 2;
    }
  }
  else if ((DAT_00fbab40 & 2) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 2;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x17f) == '\0')) {
    if ((DAT_00fbab40 & 4) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 4;
    }
  }
  else if ((DAT_00fbab40 & 4) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 4;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x173) == '\0')) {
    if ((char)DAT_00fbab40 < '\0') {
      DAT_00fbab40 = DAT_00fbab40 ^ 0x80;
    }
  }
  else if (-1 < (char)DAT_00fbab40) {
    DAT_00fbab40 = DAT_00fbab40 | 0x80;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x181) == '\0')) {
    if ((DAT_00fbab40 & 0x100) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 0x100;
    }
  }
  else if ((DAT_00fbab40 & 0x100) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 0x100;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x170) == '\0')) {
    if ((DAT_00fbab40 & 0x20) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 0x20;
    }
  }
  else if ((DAT_00fbab40 & 0x20) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 0x20;
  }
  if ((*(int *)(DAT_00fba80c + 0x20) == 0) || (*(char *)(DAT_00fba80c + 0x172) == '\0')) {
    if ((DAT_00fbab40 & 0x40) != 0) {
      DAT_00fbab40 = DAT_00fbab40 ^ 0x40;
    }
  }
  else if ((DAT_00fbab40 & 0x40) == 0) {
    DAT_00fbab40 = DAT_00fbab40 | 0x40;
  }
  FUN_0054c930(param_1);
  return;
}

