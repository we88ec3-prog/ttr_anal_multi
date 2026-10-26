
undefined4 FUN_008cc270(char param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  char cVar5;
  int in_EAX;
  
  iVar3 = *(int *)(in_EAX + 0x400);
  do {
    if (iVar3 < 0) {
      return 0;
    }
    *(int *)(in_EAX + 0x50) =
         (int)*(short *)(in_EAX + 0x3c2 + *(int *)(in_EAX + 0x400) * 4) * *(int *)(in_EAX + 4);
    *(int *)(in_EAX + 0x4c) =
         (int)*(short *)(in_EAX + 0x3c0 + *(int *)(in_EAX + 0x400) * 4) * *(int *)(in_EAX + 4);
    *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_EAX + 0x1c);
    *(undefined4 *)(in_EAX + 0x2c) = 0;
    cVar5 = FUN_008cb840((int)param_1);
    if (cVar5 == '\0') {
      if ((*(int *)(in_EAX + 0x5c) != 0) && (cVar5 = FUN_008cbf70(), cVar5 != '\0')) {
        return *(undefined4 *)(in_EAX + 0x2c);
      }
      *(int *)(in_EAX + 0x400) = *(int *)(in_EAX + 0x400) + -1;
    }
    else {
      if (*(int *)(in_EAX + 0x2c) != 0x62) {
        return 1;
      }
      iVar3 = *(int *)(in_EAX + 0x400);
      *(undefined4 *)(in_EAX + 0x2c) = 0;
      sVar1 = *(short *)(in_EAX + 0x3c0 + iVar3 * 4);
      sVar2 = *(short *)(in_EAX + 0x3c2 + iVar3 * 4);
      sVar4 = (short)(((int)sVar2 + (int)sVar1) / 2);
      if ((6 < iVar3) || (sVar4 < sVar1)) {
        *(undefined4 *)(in_EAX + 0x400) = 0;
        *(undefined4 *)(in_EAX + 0x2c) = 0x14;
        return 0x14;
      }
      *(short *)(in_EAX + 0x3c4 + iVar3 * 4) = sVar4;
      *(short *)(in_EAX + 0x3c6 + *(int *)(in_EAX + 0x400) * 4) = sVar2;
      *(short *)(in_EAX + 0x3c2 + *(int *)(in_EAX + 0x400) * 4) = sVar4 + -1;
      *(int *)(in_EAX + 0x400) = *(int *)(in_EAX + 0x400) + 1;
    }
    iVar3 = *(int *)(in_EAX + 0x400);
  } while( true );
}

