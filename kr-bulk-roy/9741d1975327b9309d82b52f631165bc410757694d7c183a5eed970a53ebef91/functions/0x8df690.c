
void FUN_008df690(void)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  char *in_EDX;
  char *pcVar5;
  char *pcVar6;
  char *local_8;
  
  local_8 = in_EDX;
  do {
    cVar1 = *local_8;
    local_8 = local_8 + 1;
  } while (cVar1 != '\0');
  pcVar4 = local_8 + (1 - (int)(in_EDX + 1));
  local_8 = local_8 + (-6 - (int)(in_EDX + 1));
  bVar2 = true;
  while( true ) {
    if (((int)pcVar4 < 7) || (in_EDX[6] != '+')) {
      return;
    }
    if ((*in_EDX < 'A') || ('Z' < *in_EDX)) {
      bVar2 = false;
    }
    if ((in_EDX[1] < 'A') || ('Z' < in_EDX[1])) {
      bVar2 = false;
    }
    if ((in_EDX[2] < 'A') || ('Z' < in_EDX[2])) {
      bVar2 = false;
    }
    if ((in_EDX[3] < 'A') || ('Z' < in_EDX[3])) {
      bVar2 = false;
    }
    if ((in_EDX[4] < 'A') || ('Z' < in_EDX[4])) {
      bVar2 = false;
    }
    if (in_EDX[5] < 'A') break;
    if ('Z' < in_EDX[5]) {
      return;
    }
    if (!bVar2) {
      return;
    }
    if (7 < (int)pcVar4) {
      pcVar5 = in_EDX + 7;
      pcVar6 = in_EDX;
      for (pcVar3 = local_8; pcVar3 != (char *)0x0; pcVar3 = pcVar3 + -1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
    }
    pcVar4 = pcVar4 + -7;
    local_8 = local_8 + -7;
  }
  return;
}

