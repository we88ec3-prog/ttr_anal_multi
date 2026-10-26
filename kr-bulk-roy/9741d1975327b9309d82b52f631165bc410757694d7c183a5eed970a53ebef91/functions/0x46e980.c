
void FUN_0046e980(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *unaff_ESI;
  int unaff_EDI;
  
  FUN_00834f20(&stack0x00000004);
  iVar1 = *(int *)(unaff_EDI + 4);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  if (iVar1 == 0) {
    pcVar2 = (char *)0x0;
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    FUN_00402a70(0,pcVar3);
    return;
  }
  FUN_00403040(0x14,0,0xffffffff);
  return;
}

