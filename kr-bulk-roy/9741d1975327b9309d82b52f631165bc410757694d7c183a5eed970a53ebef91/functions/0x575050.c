
void FUN_00575050(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *unaff_ESI;
  
  pcVar3 = param_1;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    pcVar3 = *(char **)param_1;
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
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  return;
}

