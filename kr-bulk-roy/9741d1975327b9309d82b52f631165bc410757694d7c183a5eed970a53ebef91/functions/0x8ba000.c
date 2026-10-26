
void FUN_008ba000(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = pcVar2 + (1 - (int)(param_2 + 1));
  }
  FUN_008b9fa0(param_1,param_2,pcVar2,param_3);
  return;
}

