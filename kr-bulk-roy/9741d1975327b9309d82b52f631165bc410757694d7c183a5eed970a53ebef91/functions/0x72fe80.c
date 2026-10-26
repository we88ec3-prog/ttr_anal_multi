
void FUN_0072fe80(void)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  char *pcVar3;
  int unaff_ESI;
  
  pcVar3 = (char *)(in_EAX + 0x20);
  if (0xf < *(uint *)(in_EAX + 0x34)) {
    pcVar3 = *(char **)pcVar3;
  }
  pcVar2 = pcVar3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar3,(int)pcVar2 - (int)(pcVar3 + 1));
  *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(in_EAX + 0xc);
  FUN_00403040(in_EAX + 0x44,0,0xffffffff);
  FUN_00403040(in_EAX + 0x60,0,0xffffffff);
  FUN_00403040(in_EAX + 0x7c,0,0xffffffff);
  return;
}

