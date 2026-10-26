
char * FUN_0072a4a0(void)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int in_EDX;
  int unaff_ESI;
  
  pcVar1 = (char *)(*(int *)(unaff_ESI + 0x6c) + *(int *)(unaff_ESI + 0x38));
  pcVar4 = (char *)(*(int *)(unaff_ESI + 0x38) + in_EDX);
  if ((*pcVar4 == *pcVar1) && (pcVar4[1] == pcVar1[1])) {
    pcVar4 = pcVar4 + 2;
    pcVar2 = pcVar1 + 2;
    while (((((pcVar3 = pcVar2 + 1, pcVar2[1] == pcVar4[1] &&
              (pcVar3 = pcVar2 + 2, pcVar2[2] == pcVar4[2])) &&
             (pcVar3 = pcVar2 + 3, pcVar2[3] == pcVar4[3])) &&
            ((pcVar3 = pcVar2 + 4, pcVar2[4] == pcVar4[4] &&
             (pcVar3 = pcVar2 + 5, pcVar2[5] == pcVar4[5])))) &&
           ((pcVar3 = pcVar2 + 6, pcVar2[6] == pcVar4[6] &&
            (pcVar3 = pcVar2 + 7, pcVar2[7] == pcVar4[7]))))) {
      pcVar3 = pcVar2 + 8;
      pcVar4 = pcVar4 + 8;
      if ((pcVar2[8] != *pcVar4) || (pcVar2 = pcVar3, pcVar1 + 0x102 <= pcVar3)) break;
    }
    pcVar3 = pcVar3 + (0x102 - (int)(pcVar1 + 0x102));
    if (2 < (int)pcVar3) {
      *(int *)(unaff_ESI + 0x70) = in_EDX;
      if (pcVar3 <= *(char **)(unaff_ESI + 0x74)) {
        return pcVar3;
      }
      return *(char **)(unaff_ESI + 0x74);
    }
  }
  return (char *)0x2;
}

