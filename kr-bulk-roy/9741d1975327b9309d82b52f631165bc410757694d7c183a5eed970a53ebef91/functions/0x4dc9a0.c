
int FUN_004dc9a0(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  int *piVar3;
  
  iVar1 = 0;
  iVar2 = *(int *)(in_EDX + 0x48) - *(int *)(in_EDX + 0x44) >> 3;
  if (iVar2 != 0) {
    piVar3 = (int *)(*(int *)(in_EDX + 0x44) + 4);
    do {
      if (*piVar3 != 0) {
        iVar1 = iVar1 + 1;
      }
      piVar3 = piVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}

