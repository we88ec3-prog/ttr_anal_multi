
char * FUN_0070a1a0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *in_EAX;
  char *pcVar4;
  undefined4 uVar5;
  
  cVar1 = *in_EAX;
  while (cVar1 == ';') {
    in_EAX = in_EAX + 1;
    cVar1 = *in_EAX;
  }
  if (*in_EAX == '\0') {
    return (char *)0x0;
  }
  pcVar4 = _strchr(in_EAX,0x3b);
  pcVar3 = in_EAX;
  if (pcVar4 == (char *)0x0) {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
  }
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  uVar5 = FUN_006fec70(param_1,in_EAX,(int)pcVar4 - (int)in_EAX);
  *puVar2 = uVar5;
  puVar2[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return pcVar4;
}

