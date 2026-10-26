
void FUN_00707ca0(void)

{
  int iVar1;
  int in_EAX;
  
  FUN_006f5730();
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  if ((*(int *)(*(int *)(in_EAX + 8) + -8) == 6) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 8) + -0x10), *(char *)(iVar1 + 6) != '\0')) {
    (**(code **)(iVar1 + 0x10))();
    return;
  }
  (*(code *)0x0)();
  return;
}

