
int FUN_005306e0(int param_1)

{
  int iVar1;
  uint in_EAX;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(*(int *)(param_1 + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    FUN_008438c0(&param_1);
    if (in_ECX == *(int *)(param_1 + 4)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 0x10);
    }
    *(undefined4 *)(param_1 + 0x30) = uVar2;
  }
  iVar1 = *(int *)(param_1 + 0x30);
  if ((((iVar1 != 0) && (*(char *)(iVar1 + 0x24) == '\x01')) &&
      (in_EAX <= (uint)(*(int *)(iVar1 + 100) - *(int *)(iVar1 + 0x60) >> 4))) &&
     (iVar1 = *(int *)(iVar1 + 0x60) + -0x10 + in_EAX * 0x10, iVar1 != 0)) {
    return (int)*(short *)(iVar1 + 6);
  }
  return 0;
}

