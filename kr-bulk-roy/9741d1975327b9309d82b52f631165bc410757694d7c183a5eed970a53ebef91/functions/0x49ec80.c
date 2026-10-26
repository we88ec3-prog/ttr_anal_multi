
void FUN_0049ec80(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *in_EDX;
  undefined1 *unaff_ESI;
  
  pcVar2 = in_EDX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_0049ecd0(in_EDX,(int)pcVar2 - (int)(in_EDX + 1));
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  FUN_00402bb0(uVar3);
  return;
}

