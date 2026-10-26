
void FUN_00700b00(char *param_1)

{
  char cVar1;
  int in_ECX;
  
  FUN_006f5510();
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  return;
}

