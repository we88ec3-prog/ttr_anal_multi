
void FUN_008cb060(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  int in_EDX;
  
  iVar2 = *(int *)(param_1 + 0x34);
  *(int *)(iVar2 + 4) = -*(int *)(iVar2 + 4);
  *(int *)(iVar2 + 0xc) = -*(int *)(iVar2 + 0xc);
  *(int *)(iVar2 + 0x14) = -*(int *)(iVar2 + 0x14);
  if (2 < in_EAX) {
    *(int *)(iVar2 + 0x1c) = -*(int *)(iVar2 + 0x1c);
  }
  cVar1 = *(char *)(param_1 + 0x56);
  FUN_008caef0(param_2,-in_ECX,-in_EDX);
  if ((cVar1 != '\0') && (*(char *)(param_1 + 0x56) == '\0')) {
    *(int *)(*(int *)(param_1 + 0x58) + 0x14) = -*(int *)(*(int *)(param_1 + 0x58) + 0x14);
  }
  *(int *)(iVar2 + 4) = -*(int *)(iVar2 + 4);
  return;
}

