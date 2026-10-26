
void FUN_0071cd80(char *param_1,char *param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  cVar1 = *in_EAX;
  pcVar4 = in_EAX;
  do {
    if (cVar1 == '\0') {
      *pcVar4 = '\0';
      return;
    }
    in_EAX = in_EAX + 1;
    pcVar3 = _strchr(param_1,(int)cVar1);
    if (pcVar3 == (char *)0x0) {
      *pcVar4 = cVar1;
LAB_0071cdcd:
      pcVar4 = pcVar4 + 1;
    }
    else if ((uint)((int)pcVar3 - (int)param_1) < (uint)((int)pcVar2 - (int)(param_2 + 1))) {
      *pcVar4 = param_2[(int)pcVar3 - (int)param_1];
      goto LAB_0071cdcd;
    }
    cVar1 = *in_EAX;
  } while( true );
}

