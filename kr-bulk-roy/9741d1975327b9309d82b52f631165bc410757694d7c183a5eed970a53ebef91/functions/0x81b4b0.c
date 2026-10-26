
undefined4 FUN_0081b4b0(int param_1)

{
  char *pcVar1;
  int in_ECX;
  
  if ((((*(int *)(param_1 + 0x10) != 0) &&
       (pcVar1 = *(char **)(*(int *)(param_1 + 0x10) + 8), *pcVar1 == *(char *)(in_ECX + 8))) &&
      ((*(byte *)(in_ECX + 9) == 0 || (*(byte *)(in_ECX + 9) <= (byte)pcVar1[1])))) &&
     ((*(byte *)(in_ECX + 10) == 0 || ((byte)pcVar1[1] <= *(byte *)(in_ECX + 10))))) {
    return 1;
  }
  return 0;
}

