
void FUN_0072f600(void)

{
  char cVar1;
  int *piVar2;
  int in_EAX;
  char *pcVar3;
  char *pcVar4;
  int unaff_EDI;
  
  if (*(uint *)(in_EAX + 0x34) < 0x10) {
    pcVar4 = (char *)(in_EAX + 0x20);
  }
  else {
    pcVar4 = *(char **)(in_EAX + 0x20);
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  *(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(in_EAX + 0xc);
  *(undefined1 *)(unaff_EDI + 0x44) = *(undefined1 *)(in_EAX + 0x44);
  if (*(uint *)(in_EAX + 0x60) < 0x10) {
    pcVar4 = (char *)(in_EAX + 0x4c);
  }
  else {
    pcVar4 = *(char **)(in_EAX + 0x4c);
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  for (piVar2 = *(int **)(in_EAX + 0x18); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
    (**(code **)(*piVar2 + 0x3c))();
    FUN_0072e0d0();
  }
  return;
}

