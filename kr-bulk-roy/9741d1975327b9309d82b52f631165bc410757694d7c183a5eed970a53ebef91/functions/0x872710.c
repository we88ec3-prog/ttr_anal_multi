
undefined4 FUN_00872710(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar2 - (int)(param_1 + 1));
  FUN_008608d0(*(undefined4 *)(in_ECX + 0x184),*(undefined4 *)(in_ECX + 0x188));
  if (param_1 != *(char **)(in_ECX + 0x188)) {
    *param_2 = *(undefined4 *)param_1;
    return 1;
  }
  *param_2 = 0;
  return 0;
}

