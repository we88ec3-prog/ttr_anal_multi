
char * FUN_0071ad00(int param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *pcVar2;
  do {
    if (cVar1 == '\0') {
      *(char **)(in_ECX + 8) = pcVar2;
                    /* WARNING: Subroutine does not return */
      FID_conflict____longjmp_internal((int *)(in_ECX + 0xc),9);
    }
    if (((cVar1 == '<') && (pcVar2[1] == '!')) && (pcVar2[2] == '[')) {
      pcVar2 = (char *)FUN_0071ad00(pcVar2);
    }
    else {
      if (((cVar1 == ']') && (pcVar2[1] == ']')) && (pcVar2[2] == '>')) {
        return pcVar2 + 3;
      }
      pcVar2 = pcVar2 + 1;
    }
    cVar1 = *pcVar2;
  } while( true );
}

