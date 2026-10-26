
int FUN_004dade0(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  FUN_004daea0(&param_1);
  if (in_ECX != *(int *)(in_EAX + 0x24)) {
    FUN_00515a30();
    if (param_1 != *(int *)(in_ECX + 0x14)) {
      return param_1 + 0x10;
    }
  }
  return 0;
}

