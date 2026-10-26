
void FUN_007815d0(uint param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int unaff_ESI;
  char *unaff_EDI;
  
  FUN_00730d00();
  *(undefined4 *)(unaff_ESI + 0x3c) = 0x20;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 2;
  if (unaff_EDI == (char *)0x0) {
    *(undefined4 *)(unaff_ESI + 0x48) = 6;
    if ((-1 < param_2) && ((0 < param_2 || (0x20 < param_1)))) {
      *(uint *)(unaff_ESI + 0x3c) = param_1;
      return;
    }
  }
  else {
    if ((param_2 < 1) && (param_2 < 0)) {
      param_1 = 0x7fffffff;
    }
    else if (param_1 == 0 && param_2 == 0) {
      pcVar2 = unaff_EDI;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      param_1 = (int)pcVar2 - (int)(unaff_EDI + 1);
    }
    *(char **)(unaff_ESI + 0x44) = unaff_EDI + param_1;
    **(undefined4 **)(unaff_ESI + 0x10) = unaff_EDI;
    **(undefined4 **)(unaff_ESI + 0x20) = unaff_EDI;
    **(uint **)(unaff_ESI + 0x30) = param_1;
  }
  return;
}

