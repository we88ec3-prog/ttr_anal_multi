
char * FUN_008dc300(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x8c);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 == '/')) {
    pcVar1 = pcVar1 + 1;
  }
  return pcVar1;
}

