
void FUN_00402b70(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *in_ECX = 0;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}

