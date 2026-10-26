
int FUN_0075cd30(int param_1)

{
  undefined4 in_ECX;
  int iVar1;
  
  if (*(int *)(param_1 + 0x24c) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x24c) + 0xcc) != 0) {
      FUN_0042c8e0(in_ECX);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x24c) + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if (iVar1 != 0) {
      FUN_00405300(param_1 + 0xe8);
      *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(iVar1 + 0x154);
    }
    return iVar1;
  }
  return 0;
}

