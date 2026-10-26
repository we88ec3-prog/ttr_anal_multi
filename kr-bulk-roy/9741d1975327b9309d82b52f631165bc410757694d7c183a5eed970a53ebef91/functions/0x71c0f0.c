
undefined4 FUN_0071c0f0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *unaff_ESI;
  
  if (*(char *)(unaff_ESI + 1) == '\0') {
    pcVar2 = (char *)*unaff_ESI;
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = FUN_0071bf40(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
    *unaff_ESI = uVar4;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return uVar4;
  }
  return *unaff_ESI;
}

