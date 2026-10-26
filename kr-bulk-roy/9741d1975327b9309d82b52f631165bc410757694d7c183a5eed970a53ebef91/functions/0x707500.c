
void FUN_00707500(char *param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  FUN_006f55b0();
  FUN_006f55b0(param_2,1);
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  return;
}

