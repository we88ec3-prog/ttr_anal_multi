
undefined4 FUN_007fad30(void)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  (**(code **)(*in_EAX + 0x14))();
  iVar2 = FUN_007300a0(&DAT_00bfca9c);
  if (iVar2 == 0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  (**(code **)(*in_EAX + 0x14))();
  iVar2 = FUN_007300a0(&DAT_00bed1d4);
  if (iVar2 == 0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  return 1;
}

