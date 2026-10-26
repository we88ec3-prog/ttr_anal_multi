
void FUN_006fb5a0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  if (*(char *)(iVar1 + 0x15) == '\x01') {
    FUN_006f9f70(iVar1,param_1);
    return;
  }
  *(byte *)(in_ECX + 5) = *(byte *)(iVar1 + 0x14) & 3 | *(byte *)(in_ECX + 5) & 0xf8;
  return;
}

