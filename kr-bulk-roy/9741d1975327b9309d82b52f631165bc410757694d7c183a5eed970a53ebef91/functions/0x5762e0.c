
void FUN_005762e0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *unaff_ESI;
  char *unaff_EDI;
  
  pcVar3 = unaff_EDI;
  if (0xf < *(uint *)(unaff_EDI + 0x14)) {
    pcVar3 = *(char **)unaff_EDI;
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar2 = pcVar3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0040b310(pcVar3);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x1c);
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_EDI + 0x20);
  return;
}

