
int FUN_008e1f00(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_EDX;
  
  iVar1 = *(int *)(in_EDX + 0x188);
  if (iVar1 == in_EDX + 8) {
    FUN_008e0760();
    return 0;
  }
  piVar2 = (int *)(iVar1 + -8);
  *(int **)(in_EDX + 0x188) = piVar2;
  if (*(int *)(iVar1 + -4) == 1) {
    iVar1 = *piVar2;
    if (iVar1 < 0) {
      return -(0x2000 - iVar1 >> 0xe);
    }
    iVar3 = iVar1 + 0x2000 >> 0xe;
  }
  else {
    iVar3 = *piVar2;
    if (*(int *)(iVar1 + -4) == 2) {
      return iVar3 << 0x10;
    }
  }
  return iVar3;
}

