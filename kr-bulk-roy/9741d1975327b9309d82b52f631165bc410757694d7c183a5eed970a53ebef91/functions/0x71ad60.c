
void FUN_0071ad60(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *pcVar2;
  do {
    if (cVar1 == '\0') {
      if ((param_3 != '\0') && ((char)param_2 == '>')) {
        return;
      }
      *(char **)(in_ECX + 8) = pcVar2;
                    /* WARNING: Subroutine does not return */
      FID_conflict____longjmp_internal((int *)(in_ECX + 0xc),9);
    }
    if (cVar1 == '<') {
      if ((pcVar2[1] == '!') && (pcVar2[2] != '-')) {
        if (pcVar2[2] == '[') {
          pcVar2 = (char *)FUN_0071ad00(pcVar2);
        }
        else {
          pcVar2 = (char *)FUN_0071ad60(pcVar2,param_2,0);
        }
      }
      else {
LAB_0071adb7:
        pcVar2 = (char *)FUN_0071ac20();
      }
    }
    else {
      if ((cVar1 == '\"') || (cVar1 == '\'')) goto LAB_0071adb7;
      pcVar2 = pcVar2 + 1;
      if (cVar1 == '>') {
        return;
      }
    }
    cVar1 = *pcVar2;
  } while( true );
}

