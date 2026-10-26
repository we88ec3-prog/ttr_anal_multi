
void FUN_008caeb0(int param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  int in_ECX;
  
  cVar1 = *(char *)(param_1 + 0x56);
  FUN_008cad20(param_2,-in_ECX,-in_EAX);
  if ((cVar1 != '\0') && (*(char *)(param_1 + 0x56) == '\0')) {
    *(int *)(*(int *)(param_1 + 0x58) + 0x14) = -*(int *)(*(int *)(param_1 + 0x58) + 0x14);
  }
  return;
}

