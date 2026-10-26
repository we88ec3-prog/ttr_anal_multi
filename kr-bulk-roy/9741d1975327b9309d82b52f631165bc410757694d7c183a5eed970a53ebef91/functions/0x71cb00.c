
uint FUN_0071cb00(void)

{
  int *in_EAX;
  char *pcVar1;
  char cVar2;
  undefined1 *puVar3;
  int *unaff_EDI;
  
  if ((*in_EAX == 0) || (puVar3 = *(undefined1 **)(*in_EAX + 4), puVar3 == (undefined1 *)0x0)) {
    puVar3 = &DAT_00bf2375;
  }
  pcVar1 = "xmlns";
  cVar2 = 'x';
  do {
    if (pcVar1[(int)(puVar3 + -0xc44524)] != cVar2) {
      if (*pcVar1 != '\0') {
        return (uint)pcVar1 & 0xffffff00;
      }
      break;
    }
    cVar2 = pcVar1[1];
    pcVar1 = pcVar1 + 1;
  } while (cVar2 != '\0');
  if (*unaff_EDI == 0) {
    return (uint)(puVar3[5] == '\0');
  }
  if (puVar3[5] == ':') {
    cVar2 = FUN_0071a3a0();
    if (cVar2 != '\0') {
      return 1;
    }
  }
  return 0;
}

