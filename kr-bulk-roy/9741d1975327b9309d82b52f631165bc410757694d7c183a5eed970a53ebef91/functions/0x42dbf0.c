
void FUN_0042dbf0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  (**(code **)(**(int **)(in_EAX + 0x10c) + 0x94))(param_1);
  if ((char)param_1 == '\0') {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_EAX + 300);
  }
  FUN_00749d00();
  iVar1 = *(int *)(*(int *)(in_EAX + 0x104) + 0x44);
  iVar2 = *(int *)(*(int *)(in_EAX + 0x10c) + 0xc);
  iVar4 = *(int *)(*(int *)(in_EAX + 0x10c) + 8) - *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar4;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar4;
  iVar3 = (iVar2 + iVar3) - *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar3;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar3;
  FUN_00746f70();
  return;
}

