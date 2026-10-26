
char * FUN_0071ac20(void)

{
  char cVar1;
  char cVar2;
  char *in_EAX;
  char *pcVar3;
  int in_ECX;
  
  cVar1 = *in_EAX;
  if ((cVar1 == '\"') || (cVar1 == '\'')) {
    pcVar3 = in_EAX + 1;
    cVar2 = *pcVar3;
    do {
      if (cVar2 == '\0') {
LAB_0071ace5:
        *(char **)(in_ECX + 8) = pcVar3;
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(in_ECX + 0xc),9);
      }
      if (cVar2 == cVar1) {
        if (*pcVar3 != '\0') {
          return pcVar3 + 1;
        }
        goto LAB_0071ace5;
      }
      cVar2 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  if (cVar1 == '<') {
    if (in_EAX[1] == '?') {
      pcVar3 = in_EAX + 2;
      in_EAX = in_EAX + 2;
      cVar1 = *pcVar3;
      while (cVar1 != '\0') {
        if ((cVar1 == '?') && (in_EAX[1] == '>')) {
          if (*in_EAX != '\0') {
            return in_EAX + 2;
          }
          break;
        }
        pcVar3 = in_EAX + 1;
        in_EAX = in_EAX + 1;
        cVar1 = *pcVar3;
      }
    }
    else if (((in_EAX[1] == '!') && (in_EAX[2] == '-')) && (in_EAX[3] == '-')) {
      cVar1 = in_EAX[4];
      pcVar3 = in_EAX + 4;
      do {
        if (cVar1 == '\0') {
LAB_0071acb6:
          *(char **)(in_ECX + 8) = pcVar3;
                    /* WARNING: Subroutine does not return */
          FID_conflict____longjmp_internal((int *)(in_ECX + 0xc),9);
        }
        if (((cVar1 == '-') && (pcVar3[1] == '-')) && (pcVar3[2] == '>')) {
          if (*pcVar3 != '\0') {
            return pcVar3 + 4;
          }
          goto LAB_0071acb6;
        }
        cVar1 = pcVar3[1];
        pcVar3 = pcVar3 + 1;
      } while( true );
    }
  }
  *(char **)(in_ECX + 8) = in_EAX;
                    /* WARNING: Subroutine does not return */
  FID_conflict____longjmp_internal((int *)(in_ECX + 0xc),9);
}

