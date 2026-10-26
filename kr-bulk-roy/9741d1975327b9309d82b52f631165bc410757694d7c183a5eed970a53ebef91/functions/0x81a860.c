
undefined4 FUN_0081a860(char param_1)

{
  char cVar1;
  char *in_EAX;
  uint uVar2;
  char in_DL;
  uint uVar3;
  
  uVar3 = 0;
  cVar1 = in_EAX[in_EAX[2] != '\0'];
  uVar2 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4);
  if (*(int *)(in_EAX + 8) != *(int *)(in_EAX + 4)) {
    do {
      if (*(char *)(*(int *)(in_EAX + 4) + uVar3) == param_1) {
        uVar3 = 0;
        do {
          if (*(char *)(*(int *)(in_EAX + 4) + uVar3) == in_DL) {
            *in_EAX = param_1;
            in_EAX[1] = in_DL;
            in_EAX[2] = '\0';
            if (cVar1 != param_1) {
              in_EAX[0x14] = '\x01';
              in_EAX[0x15] = '\0';
              in_EAX[0x16] = '\0';
              in_EAX[0x17] = '\0';
            }
            return 1;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}

