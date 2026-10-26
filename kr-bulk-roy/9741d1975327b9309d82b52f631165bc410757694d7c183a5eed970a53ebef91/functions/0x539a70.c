
int FUN_00539a70(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  int *piVar3;
  
  iVar1 = 0;
  iVar2 = *(int *)(in_EDX + 0x2c) - *(int *)(in_EDX + 0x28) >> 2;
  if (iVar2 != 0) {
    piVar3 = *(int **)(in_EDX + 0x28);
    do {
      if (*(char *)(*piVar3 + 10) != '\0') {
        iVar1 = iVar1 + 1;
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}

