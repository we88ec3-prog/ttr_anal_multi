
int FUN_00530530(int param_1)

{
  short *psVar1;
  int iVar2;
  uint in_EAX;
  undefined4 uVar3;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(*(int *)(param_1 + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    FUN_008438c0(&param_1);
    if (in_ECX == *(int *)(param_1 + 4)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 0x10);
    }
    *(undefined4 *)(param_1 + 0x30) = uVar3;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if ((((iVar2 != 0) && (*(char *)(iVar2 + 0x24) == '\x01')) &&
      (in_EAX <= (uint)(*(int *)(iVar2 + 100) - *(int *)(iVar2 + 0x60) >> 4))) &&
     (psVar1 = (short *)(*(int *)(iVar2 + 0x60) + -0x10 + in_EAX * 0x10), psVar1 != (short *)0x0)) {
    return (int)*psVar1;
  }
  return 0;
}

