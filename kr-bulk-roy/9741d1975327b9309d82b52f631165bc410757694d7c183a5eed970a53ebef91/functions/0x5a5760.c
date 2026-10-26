
void FUN_005a5760(int param_1)

{
  int in_EAX;
  int iVar1;
  int in_EDX;
  int iVar2;
  
  if (*(int *)(param_1 + 0x158) == 1) {
    iVar1 = *(int *)(param_1 + 0x140);
  }
  else {
    if (*(int *)(param_1 + 0x158) != 2) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x148);
  }
  iVar2 = in_EDX - *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;
  iVar2 = in_EAX - *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar2;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar2;
  FUN_00746f70();
  return;
}

