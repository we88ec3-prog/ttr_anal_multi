
void FUN_0049ad90(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  pcVar2 = (char *)*unaff_EDI;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  *(undefined4 *)(unaff_ESI + 0x1c) = unaff_EDI[1];
  *(undefined4 *)(unaff_ESI + 0x20) = unaff_EDI[2];
  *(undefined4 *)(unaff_ESI + 0x24) = unaff_EDI[3];
  *(undefined4 *)(unaff_ESI + 0x28) = unaff_EDI[4];
  return;
}

