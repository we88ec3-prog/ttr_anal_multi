
void FUN_0072ecf0(char *param_1)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_ECX;
  undefined1 *unaff_ESI;
  
  iVar2 = FUN_00730050(in_ECX + 0x44,in_EAX);
  if ((iVar2 != 0) && (pcVar4 = (char *)(iVar2 + 0x30), pcVar4 != (char *)0x0)) {
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
    *(undefined4 *)(unaff_ESI + 0x10) = 0;
    *unaff_ESI = 0;
    pcVar3 = pcVar4;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar4 - (int)(param_1 + 1));
  return;
}

