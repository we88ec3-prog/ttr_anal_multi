
undefined4 FUN_0077f110(char *param_1)

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
  FUN_008608d0(*(undefined4 *)(in_ECX + 200),*(undefined4 *)(in_ECX + 0xcc));
  if (param_1 != *(char **)(in_ECX + 0xcc)) {
    return *(undefined4 *)param_1;
  }
  return 0;
}

